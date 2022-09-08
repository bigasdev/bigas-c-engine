#include "include/SDL2/SDL.h"

extern void prepareScene(void);
extern void presentScene(void);
extern void resetScene(void);
extern SDL_Texture *loadTexture(char *file);
void blit(SDL_Texture *texture, int size, int x, int y, int center);
void blitAtlas(SDL_Texture *texture, int sprX, int sprY, int xx, int yy, int size, int x, int y, int center);