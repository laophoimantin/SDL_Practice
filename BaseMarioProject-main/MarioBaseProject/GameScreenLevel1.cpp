#include "GameScreenLevel1.h"
#include "Texture2D.h"
#include <iostream>

<<<<<<< Updated upstream
=======



>>>>>>> Stashed changes
GameScreenLevel1::GameScreenLevel1(SDL_Renderer* renderer) : GameScreen(renderer) {

	SetUpLevel();
}
GameScreenLevel1::~GameScreenLevel1() {
	delete m_background_texture;
	m_background_texture = nullptr;
<<<<<<< Updated upstream
=======
	delete my_character;
	my_character = nullptr;

>>>>>>> Stashed changes
}
void GameScreenLevel1::Render() {
	//draw the background
	m_background_texture->Render(Vector2D(), SDL_FLIP_NONE);
<<<<<<< Updated upstream

=======
	my_character->Render();
>>>>>>> Stashed changes

}
void GameScreenLevel1::Update(float deltaTime, SDL_Event e) {

<<<<<<< Updated upstream
}
bool GameScreenLevel1::SetUpLevel() {
=======
	//update character
	my_character->Update(deltaTime, e);

}
bool GameScreenLevel1::SetUpLevel() {
	//Set up player character
	my_character = new Character(m_renderer, "Images/Mario.png", Vector2D(64, 330));

>>>>>>> Stashed changes
	//load texture
	m_background_texture = new Texture2D(m_renderer);
	if (!m_background_texture->LoadFromFile("Images/test.bmp"))
	{
		std::cout << "Failed to load background texture!" << std::endl;
		return false;
	}
	else {
		return true;
	}
}
