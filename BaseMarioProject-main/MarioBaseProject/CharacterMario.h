#pragma once
#ifndef _CHARACTERMARIO_H
#define _CHARACTERMARIO_H


#include "Character.h"
class CharacterMario : public Character
{
public:
    CharacterMario(SDL_Renderer* renderer, std::string imagePath, Vector2D start_posotion);
    ~CharacterMario();


protected:

private:



};

#endif