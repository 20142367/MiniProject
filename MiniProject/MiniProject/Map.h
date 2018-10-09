#pragma once
#include "Game.h"

class Map {

public :

	Map();
	~Map();

	void LoadMap(int arr[20][30]);
	void DrawMap();
	void handleEvents();

private:

	SDL_Rect src, dst;

	SDL_Texture* block;
	SDL_Texture* bomb;
	SDL_Texture* empty;

	SDL_Texture* sky;
	SDL_Texture* leaf;
	SDL_Texture* tree;
	SDL_Texture* cloud;

	int map[20][30];
};