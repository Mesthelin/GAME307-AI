#ifndef BUTTON_H
#define BUTTON_H
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
//#include <string>
#include <Vector.h>
#include "MMath.h"
#include "Scene.h"

using namespace std;
using namespace MATH;


class Button
{
private:

	SDL_Surface* PlayButtonImage;
	SDL_Surface* CreditsButtonImage;
	SDL_Surface* QuitButtonImage;
	SDL_Surface* BackButtonImage;

	SDL_Texture* PlayButtonTexture;
	SDL_Texture* CreditsButtonTexture;
	SDL_Texture* QuitButtonTexture;
	SDL_Texture* BackButtonTexture;

	SDL_Rect PlayButtonSquare;
	SDL_Rect CreditsButtonSquare;
	SDL_Rect QuitButtonSquare;
	SDL_Rect BackButtonSquare;

	SDL_Renderer* PlayButtonRenderer;
	SDL_Renderer* CreditsButtonRenderer;
	SDL_Renderer* QuitButtonRenderer;
	SDL_Renderer* BackButtonRenderer;

	SDL_Window* BackButtonWindow;
	SDL_Window* QuitButtonWindow;

	Vec3 PlayButtonPosition;
	Vec3 CreditsButtonPosition;
	Vec3 QuitButtonPosition;
	Vec3 BackButtonPosition;

	Vec3 PlayButtonTopLeft;
	Vec3 CreditsButtonTopLeft;
	Vec3 QuitButtonTopLeft;
	Vec3 BackButtonTopLeft;

	Vec3 PlayButtonBottomRight;
	Vec3 CreditsButtonBottomRight;
	Vec3 QuitButtonBottomRight;
	Vec3 BackButtonBottomRight;

	Scene* scene;

	Matrix4 projectionMatrix;
	Matrix4 inverseProjection;

public:
	Button(const string &filename, Scene* owner_, Vec3 position_);
	~Button();
	bool OnCreatePlayButton();
	bool OnCreateCreditsButton();
	bool OnCreateQuitButton();
	bool OnCreateBackButton();
	void RenderPlayButton();
	void RenderCreditsButton();
	void RenderQuitButton();
	void RenderBackButton();

	bool ClickedPlayButton(Vec3 PlayButtonMousePos);
	bool ClickedCreditsButton(Vec3 CreditsButtonMousePos);
	bool ClickedQuitButton(Vec3 QuitButtonMousePos);
	bool ClickedBackButton(Vec3 ExitButtonMousePos);


};
#endif

