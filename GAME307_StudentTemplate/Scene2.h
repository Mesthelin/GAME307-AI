#ifndef SCENE2_H
#define SCENE2_H

#include "Scene.h"
#include "Graph.h"
#include "Tile.h"


class Scene2 : public Scene {
private:
	SDL_Window *window;
	float xAxis = 25.0f;
	float yAxis = 15.0f;
	SDL_Renderer* renderer;
	Matrix4 projectionMatrix;
    Matrix4 inverseProjection;

	Graph* graph;
	vector<Node*> nodes;

	// TILES
	vector<vector < Tile* >> tiles;
	float tileWidth = 2.5f;
	float tileHeight = 2.5f;

	void createTiles(int rows, int cols);
	void calculateConnectionWeights();

public:
	Scene2(SDL_Window* sdlWindow, GameManager* game_);
	~Scene2();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
    void HandleEvents(const SDL_Event &event);
	float getxAxis() { return xAxis; }
	float getyAxis() { return yAxis; }
	SDL_Window* getWindow() { return window; }
    Matrix4 getProjectionMatrix() { return projectionMatrix; }
	Matrix4 getInverseMatrix() { return inverseProjection; }
};

#endif
