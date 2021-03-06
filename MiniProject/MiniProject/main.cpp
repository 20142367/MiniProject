#include "Game.h"

Game* g_game = 0;	// our Game object

int main(int argc, char* argv[]) {

	g_game = new Game();
	g_game->init("MiniProject", 100, 100, 1280, 640, false);

	while (g_game->running()) {

		g_game->handleEvents();
		g_game->update();
		g_game->render();
	}

	g_game->clean();

	return 0;
}