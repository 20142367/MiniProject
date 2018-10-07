#pragma once
#include "Game.h"

class Map {

public :

	Map();
	~Map();

	void LoadMap(int arr[7][7]);
	void DrawMap();
	void handleEvents();

private:

	SDL_Rect src, dst;

	SDL_Texture* block;
	SDL_Texture* bomb;
	SDL_Texture* empty;

	int map[6][6];
};