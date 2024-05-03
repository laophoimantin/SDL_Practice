

//Be grateful for humble beginnings, because the next level will always require so much more of you
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>
#include "constants.h"
#include "Commons.h"
#include "Texture2D.h"

//Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
Texture2D* g_texture = nullptr;

float angle = 0.0f; // Picture angle

bool flipImage = false;

//Function prototypes
bool InitSDL();
void CloseSDL();
bool Update();
void Render();

int main(int argc, char* args[])
{

	//Check if sdl was setup correctly
	if (InitSDL()) {
		//SDL_Delay(5000);

		//Flag to check if we wish to finish
		bool quit = false;

		//Game loop
		while (!quit) {

			Render();
			quit = Update();
		}
	}

	CloseSDL();
	return 0;
}

bool InitSDL() {

	//Setup SDL
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL did not initialise. Error: " << SDL_GetError();
		return false;
	}
	else {
		//Setup passed so create window
		g_window = SDL_CreateWindow("Games Engine Creation",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			SDL_WINDOW_SHOWN);

		//Did the window get created?
		if (g_window == nullptr) {
			//Window failled
			std::cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}

		g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_renderer != nullptr) {
			//Init PNG loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags)) {
				std::cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
				return false;
			}
		}
		else {
			std::cout << "Renderer could not initialise. Error:" << SDL_GetError();
			return false;
		}

		//Load the background texture
		g_texture = new Texture2D(g_renderer); // heap memory allocation

		g_texture->LoadFromFile("Images/test.bmp");
		if (g_texture == nullptr) {
			std::cout << "Failed to load image from file\n";
			return false;
		}
	}
}

void CloseSDL() {

	//Release the window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	//release the texture
	delete g_texture;
	g_texture = nullptr;
}

bool Update() {
	//Event handler
	SDL_Event e;

	//Get events
	SDL_PollEvent(&e);

	//Handle the events
	switch (e.type) {
		//click the 'X' to quit
	case SDL_QUIT:
		return true;
		break;
	case SDL_KEYDOWN:

		//Chat GPT method, rotate to the left
		if (e.key.keysym.sym == SDLK_a || e.key.keysym.sym == SDLK_LEFT) {
			angle -= 15.0f;
		}
		//Rotate to the right
		switch (e.key.keysym.scancode) {
		case SDL_SCANCODE_D:
		case SDL_SCANCODE_RIGHT:
			angle += 15.0f;

		//Flip
		case SDL_SCANCODE_F:
			flipImage = !flipImage; //Change the current state != flipImage = true;
		}

		//Close with Q
		switch (e.key.keysym.sym) {
		case SDLK_q:
			return true;
			break;
		}


	case SDL_MOUSEBUTTONDOWN:

		//Close with right mouse button
		switch (e.button.button) {
		case SDL_BUTTON_RIGHT:
			return true;
			break;
		}
	}

	return false;
}


void Render() {

	//Clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	g_texture->Render(Vector2D(), SDL_FLIP_NONE);


	//Update the screen
	SDL_RenderPresent(g_renderer);

}