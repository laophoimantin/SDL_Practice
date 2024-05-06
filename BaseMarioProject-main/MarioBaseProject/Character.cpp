#include "Character.h"
#include "Texture2D.h"
#include "constants.h"

Character::Character(SDL_Renderer* renderer, std::string imagePath, Vector2D start_position) {

	m_renderer = renderer;
	m_position = start_position;
	m_facing_direction = FACING_RIGHT;

	m_moving_left - false;
	m_moving_right = false;


	m_texture = new Texture2D(m_renderer);
	if (!m_texture->LoadFromFile(imagePath))
	{
		std::cout << "Failed to load character texture!" << std::endl;
	}


}

Character::~Character() {

	delete m_renderer;
	m_renderer = nullptr;

}

void Character::Render() {

	m_texture->Render(m_position, SDL_FLIP_NONE);
	if (m_facing_direction == FACING_RIGHT) {
		m_texture->Render(m_position, SDL_FLIP_NONE);
	}
	else {
		m_texture->Render(m_position, SDL_FLIP_HORIZONTAL);
	}

}

void Character::Update(float deltaTime, SDL_Event e) {

	//Deal with jumping
	if (m_jumping) {

		//adjust position
		m_position.y -= m_jump_force * deltaTime;

		//reduce jump force
		m_jump_force -= JUMP_FORCE_DECREMENT * deltaTime;

		//is jump force 0?
		if (m_jump_force <= 0.0f) {
			m_jumping = false;
		}
	}
	else {
		AddGravity(deltaTime);
	}

	if (m_moving_left) {
		MoveLeft(deltaTime);
	}
	else if (m_moving_right) {
		MoveRight(deltaTime);
	}

	SDL_PollEvent(&e);
	switch (e.type) {
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym) {
		case(SDLK_LEFT):
			m_moving_left = true;
			std::cout << "Left Down" << std::endl;
			break;
		case(SDLK_RIGHT):
			m_moving_right = true;
			std::cout << "Right Down" << std::endl;
			break;

			//Jumping
		case(SDLK_UP):
			if (m_can_jump) {
				Jump();
			}
			break;
		}
		break;

	case SDL_KEYUP:
		switch (e.key.keysym.sym) {
		case(SDLK_LEFT):
			m_moving_left = false;
			std::cout << "Left Up" << std::endl;
			break;
		case(SDLK_RIGHT):
			m_moving_right = false;
			std::cout << "Right Up" << std::endl;
			break;


		}
		break;
	}

	/*
	SDL_PollEvent(&e);
	switch (e.type) {
	case SDL_KEYDOWN:
		switch (e.key.keysym.sym) {
		case(SDLK_LEFT):
			m_position.x -= 1;
			std::cout << "Left" << std::endl;
			m_facing_direction = FACING_LEFT;
			break;
		case(SDLK_RIGHT):
			m_position.x += 1;
			std::cout << "Right" << std::endl;
			m_facing_direction = FACING_RIGHT;
			break;
		}
	}
	*/
}

void Character::MoveLeft(float deltaTime) {
	m_position.x -= deltaTime * MOVEMENTSPEED;
	m_facing_direction = FACING_LEFT;

}
void Character::MoveRight(float deltaTime) {
	m_position.x += deltaTime * MOVEMENTSPEED;
	m_facing_direction = FACING_RIGHT;
}

void Character::AddGravity(float deltaTime) {
	if (m_position.y + 64 <= SCREEN_HEIGHT) {
		m_position.y += deltaTime * GRAVITY;
	}
	else {
		m_can_jump = true;
	}
}

void Character::Jump() {
	m_jump_force = INITIAL_JUMP_FORCE;
	m_jumping = true;
	m_can_jump = false;
}

void Character::SetPosition(Vector2D newPosition) {

	m_position = newPosition;

}

Vector2D Character::GetPosition() {
	return m_position;
}

