#ifndef LOGTEXTURE_H_INCLUDED
#define LOGTEXTURE_H_INCLUDED

#include "Base.h"
const int LOG_WIDTH = 150;
const int LOG_HEIGHT = 150;

//Texture wrapper class
class LTexture
{
	public:
		//Initializes variables
		LTexture();

		//Deallocates memory
		~LTexture();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Creates image from font string
		bool loadFromRenderedText( std::string textureText, SDL_Color textColor );

		//Deallocates texture
		void free();

		//Set color modulation
		void setColor( Uint8 red, Uint8 green, Uint8 blue );

		//Set blending
		void setBlendMode( SDL_BlendMode blending );

		//Set alpha modulation
		void setAlpha( Uint8 alpha );

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		//Gets image dimensions
		int getWidth();
		int getHeight();

		//Gets image axis
		int getX();
		int getY();

		//Moves the collision boxes relative to the Knife's offset
		void shiftColliders();

        SDL_Rect mCollider;

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;

		int mLogX;
		int mLogY;
};


#endif // LOGTEXTURE_H_INCLUDED
