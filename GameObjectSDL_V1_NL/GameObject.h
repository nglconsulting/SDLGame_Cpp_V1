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

		//std::cout << "draw game object" << std::endl;
		m_SDL.drawFrame((int)m_position.getVectX(),(int)m_position.getVectY(), nWidth, nHeight, nCurrentRow, nCurrentFrame, pRenderer,pTexture,SDL_FLIP_HORIZONTAL);
		
	}

	inline void update(CInputHandler *input) {
		std::cout << "update game object" << std::endl;
		handleInput(input);
		
		
		//std::cout << input->getXY()->getVectX() << "\n";
		//std::cout << m_velocity.getVectX() << "\n";
		m_position.setVectX(m_velocity.getVectX());
		m_position.setVectY(m_velocity.getVectY());
	 
		nCurrentFrame = (int)((SDL_GetTicks() / 100) % 5);
	}

	inline void clean() {
		std::cout << "clean game object" << std::endl;
	}

	void load(int x, int y, int width, int height);


	void handleInput(CInputHandler *input) {

		
		//TODO GetMousePosition()
		//CVect2D vec = input.getMousePosition();
		
		//m_velocity = (vec - m_position) / 100;
		//m_velocity = (vec.soustractionVect2D(m_position));
		//vec.soustractionVect2D(m_position);
		//m_velocity.setVectX(vec.getVectX() / 100);
		//m_velocity.setVectY(vec.getVectY() / 100);
		//m_velocity.setVectX(vec.getVectX());
		//m_velocity.setVectY(vec.getVectY());

	
		m_acceleration.setVectX(10);
		m_acceleration.setVectY(10);
		m_velocity.setVectX(input->getXY().getVectX());
		m_velocity.setVectY(input->getXY().getVectY());
		m_velocity.ProduitVectoriel(m_acceleration);




	}
};

