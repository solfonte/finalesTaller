/*
**5) Escriba una rutina que dibuje las dos diagonales de la pantalla en color rojo..**
*/
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <assert.h>
#include <stdio.h>

#define WIDTH 640
#define HEIGHT 480
#define MIN (((HEIGHT) < (WIDTH))? HEIGHT : WIDTH)
#define N 7

int main(){
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Window* window = SDL_CreateWindow("SDL2 GFX", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
  SDL_Renderer* renderer = SDL_CreateRenderer(
  window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

  SDL_Event e;
  int begin = 1;
  int quit = 0;

  while (!quit){
    if (SDL_PollEvent(&e)){
      if (e.type == SDL_QUIT) quit = 1;
    }

  SDL_SetRenderDrawColor(renderer,0,0,0,0);
  SDL_RenderClear(renderer);

  lineRGBA(renderer, 0, 0, WIDTH, HEIGHT, 0xff, 0x00, 0x00, 0xff);
  lineRGBA(renderer, WIDTH, 0, 0, HEIGHT, 0xff, 0x00, 0x00, 0xff);//verde

  //lineRGBA(renderer, WIDTH, 0, 0, HEIGHT, 0x00, 0xff, 0x00, 0xff);//verde
//  lineRGBA(
//renderer, 0, HEIGHT / 2, WIDTH, HEIGHT / 2, 0x00, 0x00, 0xff, 0xff);//azul
  SDL_RenderPresent(renderer);
  SDL_Delay(10);
  begin = 0;
  }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
