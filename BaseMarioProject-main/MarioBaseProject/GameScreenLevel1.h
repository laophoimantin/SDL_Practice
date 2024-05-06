#pragma once
#ifndef _GAMESCREENLEVER1_H
#define _GAMESCREENLEVER1_H

#include "Commons.h"
#include "GameScreen.h"

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

};


#endif 