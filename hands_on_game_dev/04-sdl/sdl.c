#include <SDLs/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <emscripten.h>
#include <stdio.h>

#define MESSAGE "OLA SDL" // constante string
#define FONT_SIZE 16
#define FONT_FILE "font/Roboto-Black.ttf"

int main(){
    SDL_Window *window; // janela da aplicação
    SDL_Renderer *renderer; // renderizador

    SDL_Rect dest = {.x=160, .y=100, .w=0, .h=0}; // poderia ser {160, 100, 0, 0};

    TTF_Font *font;
    SDL_Texture *texture;

    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init(); // inicializa o sistema de fonte do SDL

    SDL_CreateWindowAndRenderer(320,200,0,&window,&renderer);

    SDL_SetRenderDrawColor(renderer,0,0,0,255);
    SDL_RenderClear(renderer);

    
    font = TTF_OpenFont(FONT_FILE,FONT_SIZE); // carrega a fonte a partir do arquivo

    SDL_Color font_color = {255,255,255,255}; // cor branca
    // criar um surface de pixels com o texto
    SDL_Surface *temp_surface = TTF_RenderText_Blended(font, MESSAGE, font_color);

    // cria a imagem renderiźavel do texto a partir do seu surface
    texture = SDL_CreateTextureFromSurface(renderer, temp_surface);

    SDL_FreeSurface(temp_surface);
    // armazena em dest.w e dest.h a largura e altura da imagem
    SDL_QueryTexture(texture,NULL,NULL,&dest.w,&dest.h);

    // uma vez descoberta as dimensões, pode-se centralizar a imagem
    dest.x -= dest.w/2;
    dest.y -= dest.h/2;

    // transfere a textura p/ o buffer de renderização
    SDL_RenderCopy(renderer, texture, NULL, &dest);
    // renderiza tudo na tela
    SDL_RenderPresent(renderer);

    return EXIT_SUCCESS;
}
