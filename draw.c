#include "src/include/SDL2/SDL.h"
#include "src/include/SDL2/SDL_image.h"
#include "src/structs.h"
#include "src/draw.h"
#include <stdio.h>


void prepareScene(void)
{
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}

void resetScene(void){
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.renderer);
	SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadTexture(char *file){
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", file);

	texture = IMG_LoadTexture(app.renderer, file);

	return texture;
}

void blit(SDL_Texture *texture, int x, int y, int center)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	if(center){
		SDL_GetWindowSize(app.window, &app.w_X, &app.w_Y);
		int w = app.w_X;
		int y = app.w_Y;
		dest.x = (w/2) - (dest.w/2);
		dest.y = (y/2) - (dest.h/2);
	}

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}