#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)	{
	
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::m_pRenderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dst) {

	SDL_RenderCopy(Game::m_pRenderer, tex, &src, &dst);
}