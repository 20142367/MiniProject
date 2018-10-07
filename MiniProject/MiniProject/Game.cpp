#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

GameObject* player;

Map* map;

SDL_Renderer* Game::m_pRenderer = nullptr;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {


	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {

		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, false);

		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}
		m_bRunning = true;

		SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
	}
	else
	{
		return false; 
	}

	player = new GameObject("Assets/animate-alpha.png", 0, 0);

	map = new Map();

	return true;
}

void Game::render() {


	// clear the renderer to the draw color
	SDL_RenderClear(m_pRenderer);	// draw color로 render 지우기

	player->render();
	map->DrawMap();

	SDL_RenderPresent(m_pRenderer);	// 화면 제시하기
}

void Game::update() {

	player->update();
}

void Game::clean() {

	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);

	SDL_Quit();
}

void Game::handleEvents() {

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

		/*
		if (event.type == SDL_KEYDOWN) {
			if (event.key.keysym.sym == SDLK_RIGHT)	m_destinationRectangle.x += 15;
			if (event.key.keysym.sym == SDLK_LEFT)	m_destinationRectangle.x -= 15;
			if (event.key.keysym.sym == SDLK_UP)	m_destinationRectangle.y -= 15;
			if (event.key.keysym.sym == SDLK_DOWN)	m_destinationRectangle.y += 15;
			if (event.key.keysym.sym == SDLK_ESCAPE) {
				SDL_Quit();
				m_bRunning = false;
			}
		}
		*/

		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.clicks) {
				SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);
			}
		}
		switch (event.type) {


		case SDL_QUIT:
			m_bRunning = false;
			break;

		default:
			break;
		}
	}
}
