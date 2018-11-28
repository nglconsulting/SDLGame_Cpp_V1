#pragma once


class CVect2D {

	//Donnees membres
private :
	float m_fltX;
	float m_fltY;
	
	
	

	//fonctions membres
public :
	float getVectX()const;
	float getVectY()const;
	void setVectX(float fltX);
	void setVectY(float fltY);


	//constructeur sans et avec parametres
	CVect2D();
	CVect2D(float fltX, float fltY=0.0);
	CVect2D(CVect2D *vect);

	//Destructeur
	~CVect2D();

	void additionVect2D(CVect2D vect); 
	void soustractionVect2D(CVect2D vect);
	void MultiVect2DScalaire(float fltR);
	float ProduitScalVect2D(CVect2D vect);
	void ProduitVectoriel(CVect2D vect);


	CVect2D addVect2D(CVect2D v);


};
