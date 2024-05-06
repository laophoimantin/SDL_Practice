#pragma once
#ifndef _GAMESCREENLEVER1_H
#define _GAMESCREENLEVER1_H

#include "Commons.h"
#include "GameScreen.h"
<<<<<<< Updated upstream
=======
#include "Character.h"

class Character;
>>>>>>> Stashed changes

class Texture2D;

class GameScreenLevel1 : GameScreen {

public:

	GameScreenLevel1(SDL_Renderer* renderer);
	~GameScreenLevel1();

	void Render() override;
	void Update(float deltaTime, SDL_Event e) override;


protected:

private:
	Texture2D* m_background_texture;
	bool SetUpLevel();
<<<<<<< Updated upstream

};


=======
	Character* my_character;

};

>>>>>>> Stashed changes
#endif 