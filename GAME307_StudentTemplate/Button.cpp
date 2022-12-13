#include "Button.h"
#include <MainMenuScreen.h>

Button::Button(const string& filename, Scene* owner_, Vec3 position_)
{
	scene = owner_;
	PlayButtonImage = IMG_Load(filename.c_str());
	CreditsButtonImage = IMG_Load(filename.c_str());
	QuitButtonImage = IMG_Load(filename.c_str());
	BackButtonImage = IMG_Load(filename.c_str());
	PlayButtonTexture = NULL;
	CreditsButtonTexture = NULL;
	QuitButtonTexture = NULL;
	BackButtonTexture = NULL;
	PlayButtonSquare = { 0,0,1,1 };
	CreditsButtonSquare = { 0,0,0,0 };
	QuitButtonSquare = { 0,0,0,0 };
	BackButtonSquare = { 0,0,0,0 };
	PlayButtonPosition = position_;
	CreditsButtonPosition = position_;
	QuitButtonPosition = position_;
	BackButtonPosition = position_;

}

Button::~Button()
{
}

bool Button::OnCreatePlayButton()
{

	Vec3 PlayButtonScreenCoords;
	int PlayButtonW, PlayButtonH;
	SDL_Window* PlayButtonWindow = scene->getWindow();

	PlayButtonRenderer = SDL_GetRenderer(PlayButtonWindow);
	PlayButtonTexture = SDL_CreateTextureFromSurface(PlayButtonRenderer, PlayButtonImage);
	if (PlayButtonImage == nullptr) {
		std::cerr << "Can't open Main Menu image" << std::endl;
	}

	//Vec3 PlayButtonPosition = Vec3(510.0f, 250.0f, 0.0f);
	float PlayButtonScale = 0.5f;
	SDL_QueryTexture(PlayButtonTexture, nullptr, nullptr, &PlayButtonW, &PlayButtonH);
	PlayButtonScreenCoords = scene->getProjectionMatrix() * PlayButtonPosition;

	PlayButtonW = static_cast<int>(PlayButtonImage->w * PlayButtonScale);
	PlayButtonH = static_cast<int>(PlayButtonImage->h * PlayButtonScale);

	//PlayButtonSquare.x = static_cast<int>(PlayButtonScreenCoords.x - 0.5f * PlayButtonW);
	//PlayButtonSquare.y = static_cast<int>(PlayButtonScreenCoords.y - 0.5f * PlayButtonH);
	PlayButtonSquare.x = static_cast<int>(PlayButtonScreenCoords.x);
	PlayButtonSquare.y = static_cast<int>(PlayButtonScreenCoords.y);
	PlayButtonSquare.w = PlayButtonW;
	PlayButtonSquare.h = PlayButtonH;

	PlayButtonTopLeft = PlayButtonPosition;
	PlayButtonBottomRight = scene->getInverseMatrix() * Vec3(static_cast<float>(PlayButtonSquare.x + PlayButtonW),
		static_cast<float>(PlayButtonSquare.y + PlayButtonH), 1.0f);

	return true;

 
}

bool Button::OnCreateCreditsButton()
{
	Vec3 CreditsButtonScreenCoords;
	int CreditsButtonW, CreditsButtonH;
	SDL_Window* CreditsButtonWindow = scene->getWindow();

	CreditsButtonRenderer = SDL_GetRenderer(CreditsButtonWindow);
	CreditsButtonTexture = SDL_CreateTextureFromSurface(CreditsButtonRenderer, CreditsButtonImage);
	if (CreditsButtonImage == nullptr) {
		std::cerr << "Can't open Main Menu image" << std::endl;
	}

	//Vec3 CreditsButtonPosition = Vec3(510.0f, 350.0f, 0.0f);
	float CreditsButtonScale = 0.5f;
	SDL_QueryTexture(PlayButtonTexture, nullptr, nullptr, &CreditsButtonW, &CreditsButtonH);
	CreditsButtonScreenCoords = scene->getProjectionMatrix() * CreditsButtonPosition;

	CreditsButtonW = static_cast<int>(CreditsButtonImage->w * CreditsButtonScale);
	CreditsButtonH = static_cast<int>(CreditsButtonImage->h * CreditsButtonScale);

	//CreditsButtonSquare.x = static_cast<int>(CreditsButtonScreenCoords.x - 0.5f * CreditsButtonW);
	//CreditsButtonSquare.y = static_cast<int>(CreditsButtonScreenCoords.y - 0.5f * CreditsButtonH);
	CreditsButtonSquare.x = static_cast<int>(CreditsButtonScreenCoords.x);
	CreditsButtonSquare.y = static_cast<int>(CreditsButtonScreenCoords.y);
	CreditsButtonSquare.w = CreditsButtonW;
	CreditsButtonSquare.h = CreditsButtonH;

	CreditsButtonTopLeft = CreditsButtonPosition;
	CreditsButtonBottomRight = scene->getInverseMatrix() * Vec3(static_cast<float>(CreditsButtonSquare.x + CreditsButtonW),
		static_cast<float>(CreditsButtonSquare.y + CreditsButtonH), 1.0f);

	return true;
}

bool Button::OnCreateQuitButton()
{
	Vec3 QuitButtonScreenCoords;
	int QuitButtonW, QuitButtonH;
	//SDL_Window* QuitButtonWindow = scene->getWindow();
	QuitButtonWindow = scene->getWindow();

	QuitButtonRenderer = SDL_GetRenderer(QuitButtonWindow);
	QuitButtonTexture = SDL_CreateTextureFromSurface(QuitButtonRenderer, QuitButtonImage);
	if (QuitButtonImage == nullptr) {
		std::cerr << "Can't open Main Menu image" << std::endl;
	}

	//Vec3 QuitButtonPosition = Vec3(510.0f, 450.0f, 0.0f);
	float QuitButtonScale = 0.5f;
	SDL_QueryTexture(QuitButtonTexture, nullptr, nullptr, &QuitButtonW, &QuitButtonH);
	QuitButtonScreenCoords = scene->getProjectionMatrix() * QuitButtonPosition;

	QuitButtonW = static_cast<int>(QuitButtonImage->w *QuitButtonScale);
	QuitButtonH = static_cast<int>(QuitButtonImage->h *QuitButtonScale);

	//QuitButtonSquare.x = static_cast<int>(QuitButtonScreenCoords.x - 0.5f * QuitButtonW);
	//QuitButtonSquare.y = static_cast<int>(QuitButtonScreenCoords.y - 0.5f * QuitButtonH);
	QuitButtonSquare.x = static_cast<int>(QuitButtonScreenCoords.x);
	QuitButtonSquare.y = static_cast<int>(QuitButtonScreenCoords.y);
	QuitButtonSquare.w = QuitButtonW;
	QuitButtonSquare.h = QuitButtonH;

	QuitButtonTopLeft = QuitButtonPosition;
	QuitButtonBottomRight = scene->getInverseMatrix() * Vec3(static_cast<float>(QuitButtonSquare.x + QuitButtonW),
		static_cast<float>(QuitButtonSquare.y + QuitButtonH), 1.0f);

	return true;
}

bool Button::OnCreateBackButton()
{
	Vec3 BackButtonScreenCoords;
	int BackButtonW, BackButtonH;
	//SDL_Window* BackButtonWindow = scene->getWindow();
	BackButtonWindow = scene->getWindow();

	BackButtonRenderer = SDL_GetRenderer(BackButtonWindow);
	BackButtonTexture = SDL_CreateTextureFromSurface(BackButtonRenderer, BackButtonImage);
	if (BackButtonImage == nullptr) {
		std::cerr << "Can't open Main Menu image" << std::endl;
	}

	//Vec3 BackButtonPosition = Vec3(500.0f, 500.0f, 0.0f);
	float BackButtonScale = 0.5f;
	SDL_QueryTexture(BackButtonTexture, nullptr, nullptr, &BackButtonW, &BackButtonH);
	BackButtonScreenCoords = scene->getProjectionMatrix() * BackButtonPosition;

	BackButtonW = static_cast<int>(BackButtonImage->w * BackButtonScale);
	BackButtonH = static_cast<int>(BackButtonImage->h * BackButtonScale);

	//BackButtonSquare.x = static_cast<int>(BackButtonScreenCoords.x - 0.5f * BackButtonW);
	//BackButtonSquare.y = static_cast<int>(BackButtonScreenCoords.y - 0.5f * BackButtonH);
	BackButtonSquare.x = static_cast<int>(BackButtonScreenCoords.x);
	BackButtonSquare.y = static_cast<int>(BackButtonScreenCoords.y);
	BackButtonSquare.w =BackButtonW;
	BackButtonSquare.h =BackButtonH;

	BackButtonTopLeft = BackButtonPosition;
	BackButtonBottomRight = scene->getInverseMatrix() * Vec3(static_cast<float>(BackButtonSquare.x + BackButtonW),
		static_cast<float>(BackButtonSquare.y + BackButtonH), 1.0f);

	return true;
}

void Button::RenderPlayButton()
{

	float PlayButtonOrientationDegrees = 0.0f;
	//SDL_RenderClear(PlayButtonRenderer);
	SDL_RenderCopyEx(PlayButtonRenderer, PlayButtonTexture, nullptr, &PlayButtonSquare,
		PlayButtonOrientationDegrees, nullptr, SDL_FLIP_NONE);
	//SDL_RenderPresent(PlayButtonRenderer);

}

void Button::RenderCreditsButton()
{
	float CreditsButtonOrientationDegrees = 0.0f;
	//SDL_RenderClear(CreditsButtonRenderer);
	SDL_RenderCopyEx(CreditsButtonRenderer, CreditsButtonTexture, nullptr, &CreditsButtonSquare,
		CreditsButtonOrientationDegrees, nullptr, SDL_FLIP_NONE);
	//SDL_RenderPresent(CreditsButtonRenderer);
}

void Button::RenderQuitButton()
{
	float QuitButtonOrientationDegrees = 0.0f;
	//SDL_RenderClear(QuitButtonRenderer);
	SDL_RenderCopyEx(QuitButtonRenderer, QuitButtonTexture, nullptr, &QuitButtonSquare,
		QuitButtonOrientationDegrees, nullptr, SDL_FLIP_NONE);
	//SDL_RenderPresent(QuitButtonRenderer);
}

void Button::RenderBackButton()
{

	float BackButtonOrientationDegrees = 0.0f;
	//SDL_RenderClear(BackButtonRenderer);
	SDL_RenderCopyEx(BackButtonRenderer, BackButtonTexture, nullptr, &BackButtonSquare,
		BackButtonOrientationDegrees, nullptr, SDL_FLIP_NONE);
	SDL_RenderPresent(BackButtonRenderer);
}

bool Button::ClickedPlayButton(Vec3 PlayButtonMousePos)
{
	//return true;
	return (PlayButtonTopLeft.x < PlayButtonMousePos.x && PlayButtonMousePos.y < PlayButtonBottomRight.y &&
		PlayButtonBottomRight.x < PlayButtonMousePos.x && PlayButtonMousePos.y < PlayButtonTopLeft.y);
}

bool Button::ClickedCreditsButton(Vec3 CreditsButtonMousePos)
{
	return true;
	return (CreditsButtonTopLeft.x < CreditsButtonMousePos.x && CreditsButtonMousePos.y < CreditsButtonBottomRight.y &&
		CreditsButtonBottomRight.x < CreditsButtonMousePos.x && CreditsButtonMousePos.y < CreditsButtonTopLeft.y);
}

bool Button::ClickedQuitButton(Vec3 QuitButtonMousePos)
{
	//return true;
	return (QuitButtonTopLeft.x < QuitButtonMousePos.x && QuitButtonMousePos.y < QuitButtonBottomRight.y &&
		QuitButtonBottomRight.x < QuitButtonMousePos.x && QuitButtonMousePos.y < QuitButtonTopLeft.y);
}

bool Button::ClickedBackButton(Vec3 ExitButtonMousePos)
{
	//return true;
	return (BackButtonTopLeft.x < ExitButtonMousePos.x && ExitButtonMousePos.y < BackButtonBottomRight.y &&
		BackButtonBottomRight.x < ExitButtonMousePos.x && ExitButtonMousePos.y < BackButtonTopLeft.y);
}

