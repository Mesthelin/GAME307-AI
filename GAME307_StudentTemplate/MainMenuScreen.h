#pragma once
#include "Scene.h"
#include "Button.h"

//#include <irrKlang.h>

class MainMenuScreen :
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

	Button* CreditsButton;
	Button* PlayButton;
	Button* QuitButton;
	SDL_Surface* MainMenuImage;
	SDL_Texture* MainMenuTexture;

public:
	MainMenuScreen(SDL_Window* sdlWindow, GameManager* game_);
	~MainMenuScreen();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
	float getxAxis() { return xAxis; }
	float getyAxis() { return yAxis; }
	SDL_Window* getWindow() { return window; }
	Matrix4 getProjectionMatrix() { return projectionMatrix; }
	Matrix4 getInverseMatrix() { return inverseProjection; }
	Vec3 GetPlayButtonMousePos();
	Vec3 GetCreditsButtonMousePos();
	Vec3 GetQuitButtonMousePos();
};

