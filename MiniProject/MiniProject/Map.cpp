#include "Map.h"
#include "TextureManager.h"
#include "Game.h"

int lvl1[20][30] = {
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's', 's' },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
};

Map::Map() {

	block = TextureManager::LoadTexture("Assets/block.png");
	bomb = TextureManager::LoadTexture("Assets/bomb.png");
	empty = TextureManager::LoadTexture("Assets/empty.png");


	sky = TextureManager::LoadTexture("Assets/sky.png");
	leaf = TextureManager::LoadTexture("Assets/leaf.png");
	tree = TextureManager::LoadTexture("Assets/tree.png");
	cloud = TextureManager::LoadTexture("Assets/cloud.png");

	LoadMap(lvl1);

	src.x = src.y = 0;
	src.w = dst.w = 25;
	src.h = dst.h = 25;
}

void Map::LoadMap(int arr[20][30])	{
	
	for (int i = 0; i < 20; i++) {

		for (int k = 0; k < 30; k++) {

			map[i][k] = arr[i][k];
		}
	}
}

void Map::DrawMap()	{

	/*
	int type = 0;

	for (int i = 0; i < 20; i++) {

		for (int k = 0; k < 30; k++) {

			type = map[i][k];

			dst.x = k * 25;
			dst.y = i * 25;

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

			case 's':
				TextureManager::Draw(sky, src, dst);
				break;

			case 'l':
				TextureManager::Draw(leaf, src, dst);
				break;

			case 't':
				TextureManager::Draw(tree, src, dst);
				break;

			case 'c':
				TextureManager::Draw(cloud, src, dst);
				break;

			default:
				break;
			}
		}
	}*/
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