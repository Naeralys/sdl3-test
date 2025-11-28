#include "SDL3/SDL_keyboard.h"
#include <SDL3/SDL.h>
#include <stdlib.h>

struct Character_Velocity {
	float y;
	float x;
};
struct Character {
	float speed;
	SDL_FRect body;
	SDL_Texture *img;
	struct Character_Velocity vel;	
};

static int MAX_VELOCITY = 1;

unsigned int deltaTime;

struct Character* init_character(SDL_Renderer *renderer) {
	struct Character *character = malloc(sizeof(struct Character));
	character->speed = 2;

	character->body.x = 50;
	character->body.y = 450;
	character->body.w = 96;
	character->body.h = 96;

	SDL_Surface* surface = SDL_ScaleSurface(
		SDL_LoadPNG("assets/character.png"),
		character->body.w,
		character->body.h,
		SDL_SCALEMODE_PIXELART
	);

	character->img = SDL_CreateTextureFromSurface(renderer, surface);

	character->vel.y = 0;
	character->vel.x = 0;
	return character;
}

void draw_character(SDL_Renderer *renderer, struct Character *character) {	
	character->body.x = character->body.x + character->vel.x;
	character->body.y = character->body.y + character->vel.y;

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderTexture(renderer, character->img, NULL, &character->body);
}

void move_character(struct Character *character) {
	const bool * keyboardState = SDL_GetKeyboardState(NULL);
	
	bool characterMovedX = false;
	bool characterMovedY = false;

	if(keyboardState[SDL_SCANCODE_W]) {
		character->vel.y = -(character->speed);
		characterMovedY = true;
	}
	if(keyboardState[SDL_SCANCODE_S]) {
		character->vel.y = character->speed;
		characterMovedY = true;
	}
	if(keyboardState[SDL_SCANCODE_A]) {
		character->vel.x = -(character->speed);
		characterMovedX = true;
	}
	if(keyboardState[SDL_SCANCODE_D]) {
		character->vel.x = character->speed;
		characterMovedX = true;
	}	

	if(!characterMovedY) character->vel.y = 0;
	if(!characterMovedX) character->vel.x = 0;
}
