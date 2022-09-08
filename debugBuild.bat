gcc src/main.c src/spawn.c src/splashScreen.c src/input.c src/init.c src/draw.c src/hero.c -DDEMO=1 SDL2.dll SDL2_image.dll -o debug/heroesDebug
xcopy /s resources debug\resources