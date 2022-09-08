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

void blit(SDL_Texture *texture, int size, int x, int y, int center)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	//resizing with the multiplier
	dest.w = (dest.w*size);
	dest.h = (dest.h*size);

	if(center){
		int w = app.w_X;
		int y = app.w_Y;

		dest.x = (w/2) - (dest.w/2);
		dest.y = (y/2) - (dest.h/2);

	}

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

//blit created to use an atlas
void blitAtlas(SDL_Texture *texture, int spr, int xx, int yy, int size, int x, int y, int center)
{
	SDL_Rect dest;
	SDL_Rect rect;

	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	rect.x = 0+(xx*size);
	rect.y = 0+(yy*size);
	rect.w = spr;
	rect.h = spr;

	dest.w = spr*size;
	dest.h = spr*size;

	/*printf("\n Checking the atlas for this texture: X%i Y%i", dest.w, dest.h);
	printf("\n Trying to grab: X%i Y%i", rect.x, rect.y);*/

	if(center){
		int w = app.w_X;
		int y = app.w_Y;

		dest.x = (w/2) - (dest.w/2);
		dest.y = (y/2) - (dest.h/2);

	}

	SDL_RenderCopy(app.renderer, texture, &rect, &dest);
}