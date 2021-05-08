#include "Knife.h"

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;




LKnife::LKnife()
{
	//Initialize
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
    mKnifeX = ( SCREEN_WIDTH - KNIFE_WIDTH ) / 2;
    mKnifeY = ( SCREEN_HEIGHT - KNIFE_HEIGHT ) / 2 + 240;
    mVelX = 2;
    mVelY = 0;
    is_move_ = 0;

    //Set collision box dimension
	mCollider.w = KNIFE_WIDTH  ;
	mCollider.h = KNIFE_HEIGHT /2 ;
}

LKnife::~LKnife()
{
	//Deallocate
	free();
}

bool LKnife::loadFromFile( std::string path )
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key image
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( gRenderer, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void LKnife::free()
{
	//Free texture if it exists
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		mWidth = 0;
		mHeight = 0;
		mKnifeX = 0;
		mKnifeY = 0;
	}
}

void LKnife::HandleMove(bool check)
{
    if (! check )
    {
        mKnifeY -= 20;
        shiftColliders();
    }
}

void LKnife::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Set rendering space and render to screen
	SDL_Rect renderQuad = { x, y, mWidth, mHeight };

	//Set clip rendering dimensions
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx( gRenderer, mTexture, clip, &renderQuad, angle, center, flip );
}

int LKnife::getWidth()
{
	return mWidth;
}

int LKnife::getHeight()
{
	return mHeight;
}

int LKnife::getX()
{
    return mKnifeX ;
}
int LKnife::getY()
{
    return mKnifeY ;
}

void LKnife::move( SDL_Event& e )
{
    LKnife* p_knife = new LKnife();

    if( !p_knife->loadFromFile( "image/knife2.png" ) )
            {
                printf( "Failed to load Knife texture!\n" );

            }


    //If mouse event happened
	if( e.type == SDL_MOUSEBUTTONDOWN )
    {

        if (e.button.button == SDL_BUTTON_LEFT )
        {

            p_knife->mKnifeX = mKnifeX;
            p_knife->set_is_move(true);
        }
        p_knife_list.push_back(p_knife);
    }



    else if ( e.type == SDL_MOUSEBUTTONUP )
    {

    }

}

void LKnife::shiftColliders()
{
	//Align collider to center of dot
	mCollider.x = mKnifeX;
	mCollider.y = mKnifeY;
}

void LKnife::dichuyen( int tang_toc,int& tt )
{

    if ( (tang_toc %300) == 0)
    {
      tt++;
    }
    if ( mKnifeX < 50)
    {
        mVelX = 2 ;
    }
    if( mKnifeX >=450 - mWidth )
    {
        mVelX = -2 ;
    }

     mKnifeX += mVelX*tt;
}
