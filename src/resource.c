#include <SDL3/SDL.h>

#include "./character.c"
#include "./ui.c"

struct Tree {
	SDL_FRect body;
	SDL_Texture *img;
};

// Please help with array size
const int TREE_COUNT = 1;

struct Environment {
	struct Tree *trees[1];
};

struct Resources {
	struct Character *character;
	struct Environment *environment;
};

struct Tree *init_trees(SDL_Renderer *renderer) {
	struct Tree *tree = malloc(sizeof(struct Tree));
	tree->body.x = 50;
	tree->body.y = 50;
	tree->body.h = 96;
	tree->body.w = 96;
	
	SDL_Surface* surface = SDL_ScaleSurface(SDL_LoadPNG("assets/tree.png"), tree->body.w, tree->body.y, SDL_SCALEMODE_PIXELART);
	tree->img = SDL_CreateTextureFromSurface(renderer, surface);

	return tree;
}

struct Resources* init_resources(SDL_Renderer *renderer) {
	struct Resources *resources = malloc(sizeof(struct Resources));
	struct Character *character = init_character(renderer);
	resources->character = character;

	struct Tree *tree = init_trees(renderer);
	struct Environment *environment = malloc(sizeof(struct Environment));
	environment->trees[0] = tree;
	resources->environment = environment;

	return resources;
}

void handle_resources(struct Resources* resources) {
	move_character(resources->character);
}

void draw_tree(SDL_Renderer *renderer, struct Tree *tree) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderTexture(renderer, tree->img, NULL, &tree->body);
}

void draw_environment(SDL_Renderer *renderer, struct Environment *environment) {
	for (int i = 0; i < TREE_COUNT; i++) {
		draw_tree(renderer, environment->trees[i]);
	}
}

void draw_resources(SDL_Renderer *renderer, struct Resources *resources) {
	draw_character(renderer, resources->character);
	draw_environment(renderer, resources->environment);
	draw_ui(renderer);
}
