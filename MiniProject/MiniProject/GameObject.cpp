#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y, int w, int h) {
	
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;

	width = w;
	height = h;

}

void GameObject::update() {

	src.x = xpos;
	src.y = ypos;

	dst.x = xpos;
	dst.y = ypos;
	dst.w = src.w = width;
	dst.h = src.h = height;
}

void GameObject::render() {

	SDL_RenderCopy(Game::m_pRenderer, objTexture, &src, &dst);
}