#include "../srch/include/SDL2/SDL.h"
#include "../srch/draw.h"
#include "../srch/defs.h"
#include "../srch/structs.h"
#include "../srch/splash.h"
#include <stdio.h>

UI_Entity splash;
int splashState = 0;

void initSplash(){
    splash.texture = loadTexture(SPLASH_SCREEN);
#if DEMO
    printf("\nStarting the splash screen!! Press any key to continue");
#endif
}
void splashInput(){
    if(app.interacted){
        splashState = 1;
    }
}
