#pragma once


#include<SDL.h>
#include<SDL_image.h>
#include <string>



class CSDLManager {


	public:

		void draw(int x, int y, int width, int height, SDL_Renderer * pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void drawFrame(int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * pRenderer,SDL_Texture * pTexture, SDL_RendererFlip flip = SDL_FLIP_NONE);
		SDL_Texture *load(std::string fileName, SDL_Renderer * pRenderer);
		int init(const char*, int, int, int, int, int);
		~CSDLManager();
		CSDLManager();

	
		SDL_Window *getWindow();
		SDL_Renderer *getRenderer();
		SDL_Texture *getTexture();


private :

		SDL_Window *g_pWindow;
		SDL_Renderer *g_pRenderer;
		SDL_Texture *pTexture;

};