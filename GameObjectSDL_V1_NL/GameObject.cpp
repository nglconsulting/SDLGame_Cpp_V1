#include "GameObject.h"



CGameObject::CGameObject()
{
	
}


CGameObject::~CGameObject()
{
}

void CGameObject::load(int x, int y, int width, int height)
{
	nCurrentFrame=1;
	nCurrentRow=1;

    nWidth=width;
	nHeight=height;

	m_position.setVectX((float)x);
	m_position.setVectY((float)y);

}
