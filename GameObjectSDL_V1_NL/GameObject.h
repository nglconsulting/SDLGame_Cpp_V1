#pragma once
#include "CVect2D.h"
#include <iostream>
#include "CSDLManager.h"


class CGameObject
{

private  :
	CVect2D  vect;
	CSDLManager SDL;

	int nCurrentFrame;
	int nCurrentRow;

	int nWidth;
	int nHeight;




public:
	CGameObject();
	~CGameObject();

	inline void draw(SDL_Renderer *pRenderer, SDL_Texture * pTexture) {

		std::cout << "draw game object" << std::endl;
		SDL.drawFrame((int)vect.getVectX(),(int)vect.getVectY(), nWidth, nHeight, nCurrentRow, nCurrentFrame, pRenderer,pTexture);
		std::cout << nCurrentFrame;
	}

	inline void update() {
		std::cout << "update game object" << std::endl;

		nCurrentFrame = (int)((SDL_GetTicks() / 100) % 5);
	}

	inline void clean() {
		std::cout << "clean game object" << std::endl;
	}

	void load(int x, int y, int width, int height);
};

