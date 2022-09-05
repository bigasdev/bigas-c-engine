#ifndef STRUCT_H
#define STRUCT_H

#include "include/SDL2/SDL.h"
#include <stdbool.h>

typedef struct{
    SDL_Renderer *renderer;
    SDL_Window *window;
    int up;
    int down;
    int left;
    int right;
} App;

typedef struct {
    int x;
    int y;
    int moveSpeed;
    int health;
    int framesCount;
    char name;
    bool slowed;
    SDL_Texture *texture;
    SDL_Texture *frames[4];
} Entity;

extern App app;

#endif
