#include "CGame.h"
#include <assert.h>
#include <iostream>

CGame::CGame()
{
	g_pRenderer = NULL;
	g_pWindow = NULL;
	pTexture = NULL;
}

CGame::~CGame()
{

	//assert(g_pRenderer != NULL);
	SDL_DestroyRenderer(g_pRenderer);

	//assert(g_pWindow != NULL);
	SDL_DestroyWindow(g_pWindow);

	SDL_DestroyTexture(pTexture);
}

int CGame::init(const char * title, int xpos, int ypos, int height, int width, int flags)
{
	//initialize SDL

	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		//if succeeded create our window
		g_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		//if succeeded create window, create our render
		if (g_pWindow != NULL) {
			g_pRenderer = SDL_CreateRenderer(g_pWindow, -1, SDL_RENDERER_ACCELERATED);
			SDL_SetRenderDrawColor(g_pRenderer, 0, 0, 0, 255);
			SDL_RenderClear(g_pRenderer);

			int flags = IMG_INIT_JPG | IMG_INIT_PNG;
			int initted = IMG_Init(flags);
			if ((initted&flags) != flags) {

				std::cerr << "IMG_Init: Failed to init required jpg and png support!\n";
				std::cerr << "IMG_Init:" << IMG_GetError();

				// handle error
			}


		}


	}
	else {


		return 0;
	}

	load("assets/helicopter.png", g_pRenderer);





	return 1;
}

void CGame::draw(int x, int y, int width, int height, SDL_Renderer * pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect rectangleDest;
	SDL_Rect rectangleSource;

	rectangleSource.x = 0;
	rectangleSource.y = 0;
	rectangleSource.w = rectangleDest.w = width;
	rectangleSource.h = rectangleDest.h = height;



	//Définition du rectangle dest pour dessiner le png

	rectangleDest.x = x; //Largeur
	rectangleDest.y = y; //Hauteur


	SDL_RenderCopyEx(pRenderer,pTexture, &rectangleSource, &rectangleDest, 0, 0, flip);


}

void CGame::drawFrame(int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer * pRenderer, SDL_RendererFlip flip)
{


	SDL_Rect rectangleDest;
	SDL_Rect rectangleSource;

	rectangleSource.x = width * currentFrame;
	rectangleSource.y = height * (currentRow - 1);
	rectangleSource.w = rectangleDest.w = width;
	rectangleSource.h = rectangleDest.h = height;



	//Définition du rectangle dest pour dessiner le png

	rectangleDest.x = x; //Largeur
	rectangleDest.y = y; //Hauteur


	SDL_RenderCopyEx(pRenderer, pTexture, &rectangleSource, &rectangleDest, 0, 0, flip);



}

bool CGame::load(std::string fileName, SDL_Renderer * pRenderer)
{
	SDL_Surface *pTempSurface = NULL; //Création d'un tmp surface

	pTempSurface = IMG_Load(fileName.c_str()); //Charge le fichier image dans la surface

	if (pTempSurface == NULL) {
		return false;
	}

	

	//Création de la texture depuis la surface
	pTexture = SDL_CreateTextureFromSurface(pRenderer, pTempSurface);

	//libère la surface
	SDL_FreeSurface(pTempSurface);


	

	return true;
}

void CGame::update()
{
	m_currentFrame = (int)((SDL_GetTicks() / 100) % 5);

}

void CGame::render()
{
	

	SDL_RenderClear(g_pRenderer);
	
	//draw(320,240, 128, 55, g_pRenderer);
	drawFrame(100, 100, 128, 55, 1, m_currentFrame, g_pRenderer);

	SDL_RenderPresent(g_pRenderer);

}
