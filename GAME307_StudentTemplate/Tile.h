#ifndef TILE_H
#define TILE_H

#include <SDL.h>
#include <SDL_image.h>

#include "Node.h"
#include "Scene.h"

enum TILE_STATE {
	WALKABLE = 0,
	PATH
};


class Tile {
private:
	Node* node;
	float width;
	float height;
	Uint8 r, g, b, a;
	TILE_STATE state;
	

	Scene* scene;

	void setRGBA(Uint8 r_, Uint8 g_, Uint8 b_, Uint8 a_) {
		r = r_;
		g = g_;
		b = b_;
		a = a_;
	}

public:

	Tile(Node* node_, float width_, float height_, Scene* scene_, TILE_STATE state_) {
		node = node_;
		width = width_;
		height = height_;
		r = 0;
		g = 255;
		b = 255;
		a = 255;
		scene = scene_;
		state = state_;
	}

	~Tile() {}
	void Render();
	Node* getNode() { return node; }

};

#endif // TILE_H //