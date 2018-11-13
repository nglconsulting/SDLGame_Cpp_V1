#ifndef __GAME__
#define __GAME__
#pragma once
#include "CSDLManager.h"
#include "GameObject.h"


class CGame
{
public:
	CGame();
	~CGame();

	
	int init(const char * title, int xpos, int ypos, int height, int width, int flag);
	void update();
	void render();

private:


	CSDLManager SDL;
	CGameObject Obj;
	

	

	


	
	

};

#endif // !__GAME__