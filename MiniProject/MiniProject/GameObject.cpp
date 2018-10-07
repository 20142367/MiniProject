#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
	
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;

}

void GameObject::update() {

	src.x = xpos;
	src.y = ypos;

	dst.x = xpos;
	dst.y = ypos;
	dst.w = src.w * 2;
	dst.h = src.h * 2;
}

void GameObject::render() {

	SDL_RenderCopy(Game::m_pRenderer, objTexture, &src, &dst);
}