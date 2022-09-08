#define SDL_MAIN_HANDLED

#include "src/include/SDL2/SDL.h"
#include "src/init.h"
#include "src/draw.h"
#include "src/spawn.h"
#include "src/defs.h"
#include "src/splash.h"
#include "src/input.h"
#include "src/structs.h"
#include "src/hero.h"
#include <stdio.h>
#include <string.h>
#include "test.h"

void cleanup(){

}

void start(){
	memset(&app, 0, sizeof(App));
    memset(&Hero, 0, sizeof(Entity));
#if SPLASH
	memset(&splash, 0, sizeof(UI_Entity));
	splashState = 0;
#endif

	initSDL();
	initSpawn();
	atexit(cleanup);

	createHero();

#if SPLASH
	initSplash();
#endif
}


int main(int argc, char *argv[]){
	start();

	//splash screen loop
#if SPLASH
	while(!splashState)
	{
		prepareScene();

		doInput();

		splashInput();

		blit(splash.texture, 2, 0, 0, 1);

		presentScene();

		SDL_Delay(32);
	}
#endif
	
	//main loop
	while (1)
	{
        
		prepareScene();

		doInput();

		playerInputs();

		animatePlayer();
        blitAtlas(Hero.texture, 20, 16, Hero.currentFrame, 0, 2, Hero.x, Hero.y, 0);
		readSpawn();

		presentScene();


		SDL_Delay(16);
	}

	return 0;
}
