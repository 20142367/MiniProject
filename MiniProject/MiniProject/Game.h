#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

using namespace std;



class Game
{
public:
	Game() {}
	~Game() {}

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);

	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	static SDL_Renderer* m_pRenderer;

private:
	SDL_Window * m_pWindow;
	SDL_RendererFlip* m_pRendererFlip;

	string state = "";

	bool m_bRunning;
};

//
