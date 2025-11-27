
#define SDL_MAIN_USE_CALLBACKS 1

#include <stdio.h>
#include <sys/time.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>

#include "./resource.c"

static int WIDTH = 800;
static int HEIGHT = 600;

static SDL_Window *window = NULL;
static SDL_Renderer *renderer = NULL;
static SDL_Texture *texture = NULL;

static struct Resources *resources = NULL;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{
	printf("Initialized app\n");
	SDL_CreateWindowAndRenderer("Adam testar", WIDTH, HEIGHT, false, &window, &renderer);

	struct Resources *_res = init_resources(renderer);
	resources = _res;

	return SDL_APP_CONTINUE;
}


SDL_AppResult SDL_AppIterate(void *appstate) {
	SDL_SetRenderDrawColor(renderer, 0, 0 , 0, 255);
	SDL_RenderClear(renderer);

	draw_resources(renderer, resources);

	SDL_RenderPresent(renderer);

	return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
	if (event->type == SDL_EVENT_QUIT) {
		return SDL_APP_SUCCESS;
	}

	handle_resources(event, resources); 

	return SDL_APP_CONTINUE;	
}

void SDL_AppQuit(void *appstate, SDL_AppResult result) {
	printf("AppQuit \n");
}

