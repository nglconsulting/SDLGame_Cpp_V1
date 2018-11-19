#pragma once
#include "CVect2D.h"
#include "SDL.h"
#include <iostream>
#include "DefineState.h"




class CInputHandler {



private :
	

	
	
	//void onMouseButtonDown(SDL_Event &event);
	//void onMouseButtonUp(SDL_Event &event);

	//CVect2D *m_mousePosition = new CVect2D;

	CVect2D xy;
	SDL_Event event;

	gameState state=gameState::play;
	


public :

	void update();
	void clean();
	//bool isKeyDown();

	

	~CInputHandler() {

		clean();
	}

	CVect2D getXY() {
		return xy;
	}

	gameState getState() {
		return state;
	}
	


	//TODO get Mouse events
	//handle mouse events
	//void onMouseMove(SDL_Event &event);

	void onKeyDown(SDL_Event &event);

	/*CVect2D *getMousePosition() {
		//std::cout << m_mousePosition->getVectX() << std::endl;
		//std::cout << m_mousePosition->getVectY() << std::endl;
		return m_mousePosition;
	}*/
	




	


};