#include "src/include/SDL2/SDL.h"
#include "src/draw.h"
#include "src/defs.h"
#include "src/structs.h"
#include "src/splash.h"
#include <stdio.h>

UI_Entity splash;
int pressed = 0;

void initSplash(){
    splash.texture = loadTexture(SPLASH_SCREEN);
#if DEMO
    printf("\nStarting the splash screen!! Press any key to continue");
#endif
}
void splashInput(){
    if(app.interacted){
        pressed = 1;
    }
}
