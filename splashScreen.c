#include "src/include/SDL2/SDL.h"
#include "src/draw.h"
#include "src/defs.h"
#include "src/splash.h"
#include <stdio.h>

void throwSplash(){
    SDL_Texture *myTexture = loadTexture(SPLASH_SCREEN);

#if DEMO
    printf("\nThrowing the splash screen!! Press any key to continue");
#endif
    
    blit(myTexture, 0, 0);
}