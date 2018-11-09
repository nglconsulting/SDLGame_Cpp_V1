#include <iostream>
#include "CVect2D.h"
#include "CGame.h"



#define SCREEN_WIDTH 640	
#define SCREEN_HEIGHT 480


int main(int argc, char *argv[]) {

	/*CVect2D vect(1.2f,3.9f);
	CVect2D vect2(10.9f, 8.9f);
	CVect2D vect3(&vect);
	float fltScal=0.0;
	CVect2D vectTmp;
	


	vect.additionVect2D(vect2);
	vect.soustractionVect2D(vect2);
	vect.MultiVect2DScalaire(8.9);
	fltScal=vect.ProduitScalVect2D(vect2);
	vectTmp=vect.addVect2D(vect2);
	vect.ProduitVectoriel(vect2);*/

	const char* sProgName="SDL Game";


	std::cout << "Sdl Game" << std::endl;

	CGame myGame;
	bool blnRunning;

	if (myGame.init(sProgName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN)) {

		blnRunning = true;


	}
	else {

		return false;//something's wrong

	}
	
	while (blnRunning) {


		myGame.render();
		myGame.update();

	}


	return 0;
}