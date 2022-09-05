#define SDL_MAIN_HANDLED

#include "src/include/SDL2/SDL.h"
#include "src/init.h"
#include "src/draw.h"
#include "src/input.h"
#include "src/structs.h"
#include "src/hero.h"
#include <stdio.h>
#include <string.h>
#include "test.h"

void cleanup(){

}


int main(int argc, char *argv[]){
    Test();

    SDL_Delay(1600);

	memset(&app, 0, sizeof(App));
    memset(&Hero, 0, sizeof(Entity));

	initSDL();

	atexit(cleanup);

	createHero();

	while (1)
	{
        
		prepareScene();

		doInput();

		playerInputs();

		animatePlayer();
        blit(Hero.texture, Hero.x, Hero.y);

		presentScene();


		SDL_Delay(16);
	}

	return 0;
}
