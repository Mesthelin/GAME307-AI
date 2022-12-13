#include "CreditsMenuScreen.h"

//irrklang::ISoundEngine* CreditsMenuEngine = irrklang::createIrrKlangDevice();
//irrklang::ISound* CreditsMenumusic = CreditsMenuEngine->play2D("./Assets/Game Sounds/Background Music/night_ambience_01.wav", true, false, true);

CreditsMenuScreen::CreditsMenuScreen(SDL_Window* sdlWindow, GameManager* game_)
{
	window = sdlWindow;
	game = game_;
	renderer = SDL_GetRenderer(window);
	xAxis = 25.0f;
	yAxis = 15.0f;
}

CreditsMenuScreen::~CreditsMenuScreen()
{

}

bool CreditsMenuScreen::OnCreate()
{

	//int w, h;
	//SDL_GetWindowSize(window, &w, &h);

	//Matrix4 ndc = MMath::viewportNDC(w, h);
	//Matrix4 ortho = MMath::orthographic(0.0f, xAxis, 0.0f, yAxis, 0.0f, 1.0f);
	//projectionMatrix = ndc * ortho;
	//inverseProjection = MMath::inverse(projectionMatrix);

	CreditsMenuImage = IMG_Load("./Assets/Menu UI Scenes/CreditsMenuBackground.png");
	CreditsMenuTexture = SDL_CreateTextureFromSurface(renderer, CreditsMenuImage);

	BackButton = new Button("./Assets/Menu UI Buttons/Buttons/Exit Button.png", this, Vec3(500.0f, 500.0f, 0.0f));
	if (!BackButton->OnCreateBackButton()) {
		return false;
	}
	return true;
}

void CreditsMenuScreen::OnDestroy()
{
}

void CreditsMenuScreen::Update(const float time)
{
	//int w, h;
	//SDL_GetWindowSize(window, &w, &h);
	//
	////Matrix4 ndc = MMath::viewportNDC(w, h);
	//
	//float left, right, botton, top;
	//left = 0.0f;
	//right = xAxis;
	//botton = 0.0f;
	//top = yAxis;
	//
	//Matrix4 ndc = MMath::viewportNDC(w, h);
	//Matrix4 ortho = MMath::orthographic(0.0f, right, 0.0f, left, 0.0f, 1.0f);
	//projectionMatrix = ndc * ortho;
}

void CreditsMenuScreen::Render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, CreditsMenuTexture, NULL, NULL);
	BackButton->RenderBackButton();
	SDL_RenderPresent(renderer);
}
Vec3 CreditsMenuScreen::GetBackButtonMousePos() {
	Uint32 BackButtonPos;
	int BackButtonPosX, BackButtonPosY;
	BackButtonPos = SDL_GetMouseState(&BackButtonPosX, &BackButtonPosY);
	Vec3 BackButtonMouseScreenCoords = Vec3(float(BackButtonPosX), float(BackButtonPosY), 0.0f);
	Vec3 BackButtonMouseWorldCoords = inverseProjection * (BackButtonMouseScreenCoords);
	return BackButtonMouseWorldCoords;
}

void CreditsMenuScreen::HandleEvents(const SDL_Event& event)
{
	SDL_Event CreditsMenuButtonEvent;
	Vec3 ExitButtonMousePosition = GetBackButtonMousePos();

	if (event.button.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
		if (BackButton->ClickedBackButton(ExitButtonMousePosition)) {
			//CreditsMenuEngine->play2D("./Assets/Game Sounds/Sound Effects/mixkit-arcade-game-jump-coin.wav"); // Using IrrKlang sound library.
			printf("Going back to Main Menu\n");
			SDL_memset(&CreditsMenuButtonEvent, 2, sizeof(CreditsMenuButtonEvent));
			CreditsMenuButtonEvent.type = game->getChangeScene2();
			CreditsMenuButtonEvent.user.code = 1;
			CreditsMenuButtonEvent.user.data1 = nullptr;
			CreditsMenuButtonEvent.user.data2 = nullptr;
			SDL_PushEvent(&CreditsMenuButtonEvent);
		}
	}
}
