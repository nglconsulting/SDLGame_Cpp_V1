#ifndef __GAME__
#define __GAME__
#pragma once

#include<SDL.h>
#include<SDL_image.h>
#include <string>


class CGame
{
public:
	CGame();
	~CGame();

	int init(const char*, int, int, int, int, int);
	
	void update();
	void render();

private:


	SDL_Window *g_pWindow;
	SDL_Renderer *g_pRenderer;

	SDL_Texture *pTexture;

	int m_currentFrame;


	void draw(int x, int y, int width, int height, SDL_Renderer * pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void drawFrame(int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	bool load(std::string fileName, SDL_Renderer * pRenderer);
	

};

#endif // !__GAME__