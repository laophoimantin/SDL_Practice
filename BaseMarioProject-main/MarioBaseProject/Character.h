#pragma once
#ifndef _CHARACTER_H
#define _CHARACTER_H

#include <iostream>
#include <SDL.h>
#include "Commons.h"

class Texture2D;

class Character
{
public:

	Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_posotion);
	~Character();

	virtual void Render();
	virtual void Update(float deltaTime, SDL_Event e);
	void SetPosition(Vector2D new_position);
	Vector2D GetPosition();


protected:

	SDL_Renderer* m_renderer;
	Vector2D m_position;
	Texture2D* m_texture;

	bool m_moving_left;
	bool m_moving_right;

	bool m_jumping;
	bool m_can_jump;
	float m_jump_force;

	virtual void MoveLeft(float deltaTime);
	virtual void MoveRight(float deltaTime);
	virtual void AddGravity(float deltaTime);
	virtual void Jump();

private:

	FACING m_facing_direction;


};

#endif