#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#define WIDTH 640
#define HEIGHT 480
// supongo que con el 1⁄4 seria a 1⁄4 de los extremos inferiores y superiores
int main(){
  SDL_Window* window = SDL_CreateWindow("rombo", 100,100, WIDTH,HEIGHT,SDL_WINDOW_OPENGL);
  SDL_Renderer* renderer =  SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED |SDL_RENDERER_PRESENTVSYNC);
  const short romboX [] = {WIDTH /2, WIDTH / 4 , WIDTH/2 , 3 * (WIDTH / 4)};
  const short romboY[] = {HEIGHT/ 4, HEIGHT / 2, 3 * (HEIGHT/4), HEIGHT / 2 };
  const short puntosRombo = 4;
  SDL_Event e;
  int quit = 0;
  while (!quit){
    if (SDL_PollEvent(&e)){
      if (e.type == SDL_QUIT) quit = 1;
    }
    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);
    polygonRGBA(renderer,romboX,romboY,puntosRombo,0xff,0x00,0x00,0xff);
    SDL_RenderPresent(renderer);
    SDL_Delay(10);
  }
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

return 0;
}
