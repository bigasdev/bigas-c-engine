gcc main.c test.c spawn.c splashScreen.c input.c init.c draw.c hero.c -DDEMO=1 SDL2.dll SDL2_image.dll -o debug/heroesDebug
xcopy /s resources debug\resources