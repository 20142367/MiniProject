#include "Map.h"
#include "TextureManager.h"
#include "Game.h"

int lvl1[7][7] = {
	{ 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 1, 2, 2, 2, 2, 0 },
	{ 0, 2, 2, 2, 2, 1, 0 },
	{ 0, 2, 2, 2, 2, 2, 0 },
	{ 0, 2, 2, 1, 2, 2, 0 },
	{ 0, 2, 2, 1, 2, 1, 0 },
	{ 0, 0, 0, 0, 0, 0, 0 }
};

Map::Map() {

	block = TextureManager::LoadTexture("Assets/block.png");
	bomb = TextureManager::LoadTexture("Assets/bomb.png");
	empty = TextureManager::LoadTexture("Assets/empty.png");

	LoadMap(lvl1);

	src.x = src.y = 0;
	src.w = dst.w = 100;
	src.h = dst.h = 100;
}

void Map::LoadMap(int arr[7][7])	{
	
	for (int i = 0; i < 7; i++) {

		for (int k = 0; k < 7; k++) {

			map[i][k] = arr[i][k];
		}
	}
}

void Map::DrawMap()	{

	int type = 0;

	for (int i = 0; i < 7; i++) {

		for (int k = 0; k < 7; k++) {

			type = map[i][k];

			dst.x = k * 100;
			dst.y = i * 100;

			switch (type)
			{
			case 0:
				TextureManager::Draw(block, src, dst);
				break;

			case 1:
				TextureManager::Draw(bomb, src, dst);
				break;

			case 2:
				TextureManager::Draw(empty, src, dst);
				break;

			default:
				break;
			}
		}
	}
}

void Map::handleEvents() {

	SDL_Event event;
	if (SDL_PollEvent(&event)) {

		/*
		if (event.type == SDL_KEYDOWN)
		{
		switch (event.key.keysym.sym) {

		case SDLK_RIGHT:
		m_destinationRectangle.x += 15;
		break;
		case SDLK_LEFT:
		m_destinationRectangle.x-=15;
		m_pRendererFlip;
		break;
		case SDLK_UP:
		m_destinationRectangle.y--;
		break;
		case SDLK_DOWN:
		m_destinationRectangle.y++;
		break;

		case SDLK_ESCAPE:
		m_bRunning = false;
		break;
		}
		}*/

		
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_RIGHT)	dst.x += 15;
			if (event.key.keysym.sym == SDLK_LEFT)	dst.x -= 15;
			if (event.key.keysym.sym == SDLK_UP)	dst.y -= 15;
			if (event.key.keysym.sym == SDLK_DOWN)	dst.y += 15;
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				SDL_Quit();
				//m_bRunning = false;
			}
		}
		

		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.clicks) {
				SDL_SetRenderDrawColor(Game::m_pRenderer, 255, 0, 0, 255);
			}
		}
		switch (event.type) {


		case SDL_QUIT:
			//m_bRunning = false;
			break;

		default:
			break;
		}
	}
}