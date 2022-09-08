#include "../srch/include/SDL2/SDL.h"
#include "../srch/include/SDL2/SDL_image.h"
#include "../srch/defs.h"
#include "../srch/structs.h"
#include "../srch/init.h"
#include <stdio.h>

App app;

void initSDL(void){
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

#if FULLSCREEN
    windowFlags = SDL_WINDOW_FULLSCREEN_DESKTOP;
#else
	windowFlags = 0;
#endif

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		exit(1);
    }
    
    app.window = SDL_CreateWindow("Hello world!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

    if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		exit(1);
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "0");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
	SDL_GetWindowSize(app.window, &app.w_X, &app.w_Y);

	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		exit(1);
	}
}