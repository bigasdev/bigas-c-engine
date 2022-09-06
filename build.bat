gcc main.c test.c splashScreen.c input.c init.c draw.c hero.c -DSPLASH=1 SDL2.dll SDL2_image.dll --machine-windows -o dist/heroes
xcopy /s resources dist\resources