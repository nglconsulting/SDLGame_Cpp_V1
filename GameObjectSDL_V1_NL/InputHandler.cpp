#include "InputHandler.h"


void CInputHandler::update()
{
	
	
	if (SDL_PollEvent(&event)) {
		switch (event.type) {

		case SDL_QUIT:state = gameState::quit; break;
		case SDL_JOYAXISMOTION: break;
		case SDL_JOYBUTTONDOWN: break;
		case SDL_JOYBUTTONUP: break;
		case SDL_MOUSEMOTION: break;
		case SDL_MOUSEBUTTONDOWN: break;
		case SDL_MOUSEBUTTONUP: break;
		case SDL_KEYDOWN: onKeyDown(event); break;
		case SDL_KEYUP: break;
		default:break;

		}
	}
	
}

	


void CInputHandler::clean()
{

}




/*bool InputHandler::isKeyDown()
{
	/*if (m_keystates != 0) {
		if (m_keystates[key] == 1) {

			return true;
		}
		else {

			return false;
		}
	}
	return false;


	
}*/


/*void CInputHandler::onMouseMove(SDL_Event & event)
{
	//m_mousePosition->setVectX((float)event.motion.x);
	
	//std::cout << m_mousePosition->getVectX() << std::endl;
	//m_mousePosition->setVectY((float)event.motion.y);
	//std::cout << m_mousePosition->getVectY() << std::endl;
}*/


void CInputHandler::onKeyDown(SDL_Event & event)
{
		
	switch (event.key.keysym.sym)
	{
		case SDLK_ESCAPE:state = gameState::quit; break;
		case SDLK_LEFT:xy.setVectX(xy.getVectX() - 1); /*std::cout << xy->getVectX() << "\n";*/ break;
		case SDLK_RIGHT:xy.setVectX(xy.getVectX() + 1); /*std::cout << xy->getVectX() << "\n";*/ break;
		case SDLK_UP:xy.setVectY(xy.getVectY() - 1); /*std::cout << xy->getVectX() << "\n";*/ break;
		case SDLK_DOWN:xy.setVectY(xy.getVectY() + 1); /*std::cout << xy->getVectX() << "\n";*/ break;
	}
			
}
	

