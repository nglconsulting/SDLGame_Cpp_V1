#ifndef __GAME__
#define __GAME__
#pragma once
#include "CSDLManager.h"
#include "GameObject.h"
#include"InputHandler.h"


class CGame
{
public:
	CGame();
	~CGame();

	
	int init(const char * title, int xpos, int ypos, int height, int width, int flag);
	void update();
	void render();
	void handleEvents();
	inline bool running() { return m_bRunning; }
	void setRunning(bool run);
	void clean();
	void quit();


private:

	CSDLManager SDL;
	CGameObject Obj;
	CInputHandler input;

	

	bool m_bRunning;

	


	
	

};

#endif // !__GAME__