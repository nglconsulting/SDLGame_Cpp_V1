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

	vect.setVectX((float)x);
	vect.setVectY((float)y);

}
