#pragma once
#include "Scene.h"
#include "Button.h"

//#include <irrKlang.h>

class CreditsMenuScreen :
    public Scene
{
private:
	SDL_Window* window;
	float xAxis = 25.0f;
	float yAxis = 15.0f;
	SDL_Renderer* renderer;
	Matrix4 projectionMatrix;
	Matrix4 inverseProjection;
private:

	Button* BackButton;
	SDL_Surface* CreditsMenuImage;
	SDL_Texture* CreditsMenuTexture;

public:
	CreditsMenuScreen(SDL_Window* sdlWindow, GameManager* game_);
	~CreditsMenuScreen();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	Vec3 GetBackButtonMousePos();
	void HandleEvents(const SDL_Event& event);
	float getxAxis() { return xAxis; }
	float getyAxis() { return yAxis; }
	SDL_Window* getWindow() { return window; }
	Matrix4 getProjectionMatrix() { return projectionMatrix; }
	Matrix4 getInverseMatrix() { return inverseProjection; }
};

