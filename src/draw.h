#include "include/SDL2/SDL.h"

extern void prepareScene(void);
extern void presentScene(void);
extern void resetScene(void);
extern SDL_Texture *loadTexture(char *file);
void blit(SDL_Texture *texture, int x, int y);