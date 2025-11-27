#include <SDL3/SDL.h>

#include "./character.c"
#include "./ui.c"

struct Resources {
	struct Character *character;
};

struct Resources* init_resources(SDL_Renderer *renderer) {
	struct Resources *resources = malloc(sizeof(struct Resources));
	struct Character *character = init_character(renderer);
	resources->character = character;
	return resources;
}

void handle_resources(SDL_Event *event, struct Resources* resources) {
	move_character(event, resources->character);
}

void draw_resources(SDL_Renderer *renderer, struct Resources *resources) {
	draw_character(renderer, resources->character);
	draw_ui(renderer);
}
