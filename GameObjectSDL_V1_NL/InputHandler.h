#pragma once
#include "CVect2D.h"
#include "SDL.h"
#include <iostream>
#include "DefineState.h"




class CInputHandler {



private :
	

	
	
	

	CVect2D m_mousePosition;
	CVect2D xy;

	SDL_Event event;

	gameState state=gameState::play;
	


public :

	void update();
	void clean();
	

	~CInputHandler() {

		
	}

	CVect2D getXY() {
		return xy;
	}

	gameState getState() {
		return state;
	}
	
	//handle mouse events
	void onMouseMove(SDL_Event &event);

	void onKeyDown(SDL_Event &event);

	inline CVect2D getMousePosition() {
		//std::cout << m_mousePosition->getVectX() << std::endl;
		//std::cout << m_mousePosition->getVectY() << std::endl;
		return m_mousePosition;
	}
	




	


};