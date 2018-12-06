#pragma once
#include "CVect2D.h"
#include <iostream>
#include "CSDLManager.h"
#include "InputHandler.h"




class CGameObject
{

private  :
	
	

	CSDLManager m_SDL;
	CVect2D m_position;
	CVect2D m_velocity;
	CVect2D m_acceleration;

	int nCurrentFrame;
	int nCurrentRow;

	int nWidth;
	int nHeight;


public:


	CGameObject();
	~CGameObject();

	inline void draw(SDL_Renderer *pRenderer, SDL_Texture * pTexture) {

		std::cout << "draw game object" << std::endl;
		m_SDL.drawFrame((int)m_position.getVectX(),(int)m_position.getVectY(), nWidth, nHeight, nCurrentRow, nCurrentFrame, pRenderer,pTexture,SDL_FLIP_HORIZONTAL);
		
	}

	inline void update(CInputHandler *input) {
		std::cout << "update game object" << std::endl;
		handleInput(input);
		
		m_position.setVectX(m_velocity.getVectX());
		m_position.setVectY(m_velocity.getVectY());

	 
		nCurrentFrame = (int)((SDL_GetTicks() / 100) % 5);
	}

	inline void clean() {
		std::cout << "clean game object" << std::endl;
	}

	void load(int x, int y, int width, int height);


	inline void handleInput(CInputHandler *input) {

		const int frameDelay = 30;
		
		//Input type mouse motion	
		m_velocity.setVectX(input->getMousePosition().getVectX());
		m_velocity.setVectY(input->getMousePosition().getVectY());
		SDL_Delay(frameDelay);
		

		//Input type Key
		/*m_acceleration.setVectX(10);
		m_acceleration.setVectY(10);
		m_velocity.setVectX(input->getXY().getVectX());
		m_velocity.setVectY(input->getXY().getVectY());
		m_velocity.ProduitVectoriel(m_acceleration);*/




	}
};

