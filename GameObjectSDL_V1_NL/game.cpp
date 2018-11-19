#include <iostream>
#include "CGame.h"




#define SCREEN_WIDTH 640	
#define SCREEN_HEIGHT 480

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;


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


	//std::cout << "Sdl Game" << std::endl;

	CGame myGame;
	int frameStart=0, frameTime = 0;
	
	if (myGame.init(sProgName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_HEIGHT, SCREEN_WIDTH, SDL_WINDOW_SHOWN)) {

		myGame.setRunning(true);


	}
	else {

		return false;//something's wrong

	}
	
	while (myGame.running()) {
		
		frameStart = SDL_GetTicks();

		
		myGame.handleEvents();
		myGame.update();
		myGame.render();
		

		frameTime = SDL_GetTicks() - frameStart;

		if (frameTime < DELAY_TIME) {
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}

	}


	return 0;
}