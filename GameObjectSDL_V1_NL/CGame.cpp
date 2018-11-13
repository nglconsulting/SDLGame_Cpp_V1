#include "CGame.h"


CGame::CGame()
{
	//CSDLManager *SDL = new CSDLManager();
}

CGame::~CGame()
{
	//delete SDL;
	
}

int CGame::init(const char * title, int xpos, int ypos, int height, int width, int flag)
{


	if (SDL.init(title, xpos, ypos, height, width, flag)) {
		Obj.load(50, 50, 128, 55);
		return 1;
	}
	else {
		return 0;
	}
		

	
}


void CGame::update()
{

	Obj.update();

}

void CGame::render()
{
	

	SDL_RenderClear(SDL.getRenderer());

	
	Obj.draw(SDL.getRenderer(),SDL.getTexture());
	
	SDL_RenderPresent(SDL.getRenderer());

}
