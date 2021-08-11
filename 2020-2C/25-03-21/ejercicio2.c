/***
Escriba una rutina que dibuje un rombo azul del tamaño de la pantalla.
***/

#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <stdio.h>

#define WIDTH 640
#define HEIGHT 480

int main(){
  SDL_Window* window = SDL_CreateWindow("SDL2 GFX", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
  SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  SDL_Event e;
  int quit = 0;

  const short rhombus_x [] = {WIDTH / 2, WIDTH, WIDTH / 2, 0};
  const short rhombus_y [] = {0, HEIGHT / 2, HEIGHT, HEIGHT / 2};

  const int rhombus_n_points = 4;

  while (!quit){
    if (SDL_PollEvent(&e)){
      if (e.type == SDL_QUIT) quit = 1;
    }

  SDL_SetRenderDrawColor(renderer,0,0,0,0);
  SDL_RenderClear(renderer);

  polygonRGBA(renderer,rhombus_x,rhombus_y,rhombus_n_points,0x00,0x00,0xff,0xff);

  SDL_RenderPresent(renderer);
  SDL_Delay(10);
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
