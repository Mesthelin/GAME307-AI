#include "Tile.h"


void Tile::Render() {
	SDL_Renderer* renderer = scene->game->getRenderer();
	SDL_Rect rect;

	Vec3 topLeftWorld;
	Vec3 bottomRightWorld;

	Vec3 topLeftScreenCoords;
	Vec3 bottomRightScreenCoords;


	// node position is at center of tile
	Vec3 pos = node->getPos();
	topLeftWorld = Vec3(pos.x - 0.5f * width, pos.y + 0.5f * height, 0.0f); // left and up
	bottomRightWorld = Vec3(pos.x + 0.5f * width, pos.y - 0.5f * height, 0.0f); // right and down

	topLeftScreenCoords = scene->getProjectionMatrix() * topLeftWorld;
	bottomRightScreenCoords = scene->getProjectionMatrix() * bottomRightWorld;

	rect.x = static_cast<int>(topLeftScreenCoords.x);
	rect.y = static_cast<int>(topLeftScreenCoords.y);
	rect.w = static_cast<int>(bottomRightScreenCoords.x - topLeftScreenCoords.x);
	rect.h = static_cast<int>(bottomRightScreenCoords.y - topLeftScreenCoords.y);

	// draw the tile fill - textures, images optional
	setRGBA(17, 138, 178, 255);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderFillRect(renderer, &rect);

	// draw border around the tile
	setRGBA(255, 255, 255, 255);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderDrawRect(renderer, &rect);
}
