#include <iostream>
#include "Base.h"
#include "Logtexture.h"
#include "Knife.h"


using namespace std;



//Scene texture
LTexture gLogTexture;

//Background texture
LTexture gBackGround;

//Font texture
LTexture gMark;

//Knife texture
LKnife gKnife;

bool loadMedia()
{
	//Loading success flag
	bool success = true;

    //Load Log
	if( !gLogTexture.loadFromFile( "image/block.png" ) )
	{
		printf( "Failed to load Log texture!\n" );
		success = false;
	}

    //Load background
	if( !gBackGround.loadFromFile( "image/bg1.png" ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}

	//Load knife
	if( !gKnife.loadFromFile( "image/Knife2.png" ) )
	{
		printf( "Failed to load Knife texture!\n" );
		success = false;
	}


	return success;
}

void close()
{

	//Free loaded images
	gLogTexture.free();
    gBackGround.free();
    gKnife.free();
    gMark.free();

    //Free global font
	TTF_CloseFont( gFont );
	gFont = NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
int game();


int main( int argc, char* args[] )
{
    game();
	return 0;
}

int game()
{
    //Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
			//Main loop flag
			bool quit = false;
            int frame = 0;
            int tt = 1;
            int mark_val = 0;

			//Event handler
			SDL_Event e;

			SDL_RendererFlip flipType = SDL_FLIP_NONE;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
					gKnife.move( e );

				}

                //Clear screen
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
				SDL_RenderClear( gRenderer );

				//Render background
				gBackGround.render(0,0);

				std::string val_str_mark = std::to_string(mark_val*100);
                std::string strMark("YOUR'S SCORE: ");
                strMark += val_str_mark;


                std::vector < LKnife* > knife_list = gKnife.GetKnifeList();
				for (int i = 0; i < gKnife.GetKnifeList().size(); i++)
                 {

                     LKnife* p_knife = knife_list.at(i);


                    if ( p_knife != NULL )
                     {


                        p_knife->render( p_knife->getX(), p_knife->getY() );
                        if ( p_knife->get_is_move() )
                        {
                            bool check = checkCollision( p_knife->mCollider, gLogTexture.mCollider);
                                p_knife->HandleMove( check );
                                if( check )
                                {
                                   if ( mark_val <= ( i + 1) )
                                    {
                                        mark_val = i + 1;
                                    }
                                }


                                //SDL_SetRenderDrawColor( gRenderer, 0, 0xFF, 0xFF, 0xFF );
                                //SDL_RenderFillRect(gRenderer, &p_knife->mCollider);


                            if ( p_knife->getY() < -150 )
                            {
                                char buff[100];
                                sprintf_s(buff, "%s", strMark.c_str());
                                if (MessageBox(NULL, buff,"Game Over!!!", MB_OK | MB_ICONINFORMATION ) == IDOK)
                                {
                                    GameOver();
                                    return 0;
                                }

                            }


                        }
                        else if ( p_knife != NULL)
                        {
                            knife_list.erase( knife_list.begin() + i );
                            gKnife.setKnifeList(knife_list);
                            delete p_knife;
                            p_knife = NULL;

                        }


                     }


                 }



                gFont = TTF_OpenFont( "font.ttf", 28 );
                //Render text
                SDL_Color textColor = { 0, 0, 0 };
                if( !gMark.loadFromRenderedText( strMark, textColor ) )
                {
                        printf( "Failed to render text texture!\n" );

                }

                //Render mark
				gMark.render( ( SCREEN_WIDTH - gMark.getWidth() ) / 2, 10 );

                //Render Knife
                gKnife.render( gKnife.getX(), gKnife.getY() );
                gKnife.dichuyen( frame, tt );

				//Render Log
				gLogTexture.render( ( SCREEN_WIDTH - gLogTexture.getWidth() ) / 2, ( SCREEN_HEIGHT - gLogTexture.getHeight() ) / 2 - 200 );
                //SDL_SetRenderDrawColor( gRenderer, 0, 0xFF, 0xFF, 0xFF );
                //SDL_RenderFillRect(gRenderer, &gLogTexture.mCollider);

				//Update screen
				SDL_RenderPresent( gRenderer );

                frame++;


			}
		}
	}

	//Free resources and close SDL
	close();

    return 0;
}
