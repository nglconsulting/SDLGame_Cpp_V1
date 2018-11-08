#include "CVect2D.h"

float CVect2D::getVectX()const 
{
	return m_fltX;
}

float CVect2D::getVectY() const
{
	return m_fltY;
}


void CVect2D::setVectX(float fltX)
{
	m_fltX=fltX;
}

void CVect2D::setVectY(float fltY)
{
	m_fltY = fltY;
}

CVect2D::CVect2D()
{
	m_fltX = m_fltY = 0.0;

}

/*CVect2D::CVect2D(float fltX, float fltY) {

	m_fltX = fltX;
	m_fltY = fltY;


}*/

/*void CVect2D::initCVect2D(float fltX, float fltY)
{
	m_fltX = fltX;
	m_fltY = fltY;
}
*/

CVect2D::CVect2D(float fltX, float fltY):m_fltX(fltX),m_fltY(fltY)
{
	
}

CVect2D::CVect2D(CVect2D *vect)
{
	m_fltX = vect->m_fltX;
	m_fltY = vect->m_fltY;
}





//Destructeur

CVect2D::~CVect2D()
{


}


//Addition de vecteurs
void CVect2D::additionVect2D(CVect2D vect)
{
	this->m_fltX = this->m_fltX + vect.m_fltX;
	this->m_fltY= this->m_fltY + vect.m_fltY;

}

CVect2D CVect2D::addVect2D(CVect2D v) {

	CVect2D vect;
	vect.m_fltX = this->m_fltX + v.m_fltX;
	vect.m_fltY = this->m_fltY + v.m_fltY;
	return vect;

}

void CVect2D::soustractionVect2D(CVect2D vect)
{
	this->m_fltX = this->m_fltX - vect.m_fltX;
	this->m_fltY = this->m_fltY - vect.m_fltY;
}

void CVect2D::MultiVect2DScalaire(float fltR)
{
	this->m_fltX = this->m_fltX *fltR;
	this->m_fltY = this->m_fltY *fltR;
}

float CVect2D::ProduitScalVect2D(CVect2D vect)
{
	float fltR;
	fltR = this->m_fltX * vect.m_fltX + this->m_fltY * vect.m_fltY;
	return fltR;


}

void CVect2D::ProduitVectoriel(CVect2D vect)
{
	float fltTmpZ;
	this->m_fltX = (this->m_fltY * 0) - (0 * vect.m_fltY);
	this->m_fltY = (vect.m_fltX * 0) - (this->m_fltX * 0);
	fltTmpZ = this->m_fltX * vect.m_fltY - this->m_fltY - vect.m_fltX;
		
}



