#ifndef KNIFE_H_INCLUDED
#define KNIFE_H_INCLUDED

#include "Base.h"
const int KNIFE_WIDTH = 25;
const int KNIFE_HEIGHT = 99;


class LKnife
{
	public:
		//Initializes variables
		LKnife();

		//Deallocates memory
		~LKnife();

		//Loads image at specified path
		bool loadFromFile( std::string path );

		//Deallocates texture
		void free();

		//Renders texture at given point
		void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );

		bool get_is_move() const {return is_move_;}
		void set_is_move(bool is_move) { is_move_ = is_move; }

		void HandleMove( bool check);
		void HandleInputAction(SDL_Event e);

		void setKnifeList(std::vector < LKnife* > knife_list) { p_knife_list =  knife_list;}
        std::vector < LKnife* > GetKnifeList() const { return p_knife_list;}

        void move( SDL_Event& e );

        //The X and Y offsets of the Knife
		int getX();
		int getY();

		//Gets image dimensions
		int getWidth();
		int getHeight();

        SDL_Rect mCollider;

        //Moves the collision boxes relative to the Knife's offset
		void shiftColliders();

		void dichuyen( int tang_toc, int& tt);

	private:
		//The actual hardware texture
		SDL_Texture* mTexture;

		//Image dimensions
		int mWidth;
		int mHeight;

		//Axis
		int mKnifeX;
		int mKnifeY;

		bool is_move_;

        std::vector < LKnife* > p_knife_list;

		//The velocity of the Knife
		int mVelX;
		int mVelY;

};



#endif // KNIFE_H_INCLUDED
