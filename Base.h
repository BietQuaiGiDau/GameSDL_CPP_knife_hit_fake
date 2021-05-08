#ifndef BASE_H_INCLUDED
#define BASE_H_INCLUDED

//Using SDL, SDL_image, standard IO, math, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <vector>
#include <iostream>
#include <windows.foundation.h>

//Screen dimension constants
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 700;



const double Pi = 3.14159;

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

//Box collision detector
bool checkCollision( SDL_Rect a, SDL_Rect b );

void Rotate(SDL_Rect rectQuad,int originX, int originY,double angle);

void GameOver();

//Loads individual image
SDL_Surface* loadSurface( std::string path );

//The window we'll be rendering to
extern SDL_Window* gWindow ;

//The window renderer
extern SDL_Renderer* gRenderer ;

extern TTF_Font *gFont;

#endif // BASE_H_INCLUDED
