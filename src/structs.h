#ifndef STRUCT_H
#define STRUCT_H

#include "include/SDL2/SDL.h"
#include <stdbool.h>

typedef struct{
    SDL_Renderer *renderer;
    SDL_Window *window;
    int w_X;
    int w_Y;
    int up;
    int down;
    int left;
    int right;
    int interacted;
    int jump;
} App;

typedef struct {
    int x;
    int y;
    int moveSpeed;
    int health;
    int framesCount;
    int currentFrame;
    char name;
    bool slowed;
    struct Entity *next;
    SDL_Texture *texture;
    SDL_Texture *frames[];
} Entity;

typedef struct {
    SDL_Texture *texture;
} UI_Entity;

extern App app;

#endif
