#pragma once
#include "Game.h"

class GameObject {

public :
	
	GameObject(const char* texturesheet, int x, int y, int w, int h);
	~GameObject();

	void update();
	void render();

private :

	int xpos;
	int ypos;

	int width;
	int height;

	SDL_Texture* objTexture;
	SDL_Rect src, dst;
};