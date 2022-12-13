#include "MainMenuScreen.h"

//irrklang::ISoundEngine * MainMenuEngine = irrklang::createIrrKlangDevice();
//irrklang::ISound* MainMenumusic = MainMenuEngine->play2D("./Assets/Game Sounds/Background Music/night_ambience_01.wav", true, false, true);

MainMenuScreen::MainMenuScreen(SDL_Window* sdlWindow, GameManager* game_)
{
	window = sdlWindow;
	game = game_;
	renderer = SDL_GetRenderer(window);
	xAxis = 25.0f;
	yAxis = 15.0f;
}

MainMenuScreen::~MainMenuScreen()
{
}

bool MainMenuScreen::OnCreate()
{
	int w, h;
	SDL_GetWindowSize(window, &w, &h);
	
	//Matrix4 ndc = MMath::viewportNDC(w, h);
	//Matrix4 ortho = MMath::orthographic(0.0f, xAxis, 0.0f, yAxis, 0.0f, 1.0f);
	//projectionMatrix = ndc * ortho;
	//inverseProjection = MMath::inverse(projectionMatrix);	
	
	IMG_Init(IMG_INIT_PNG);
	MainMenuImage = IMG_Load("./Assets/Menu UI Scenes/MainMenuBackground.png");
	MainMenuTexture = SDL_CreateTextureFromSurface(renderer, MainMenuImage);
   
	PlayButton = new Button("./Assets/Menu UI Buttons/Buttons/Play Button.png", this, Vec3(350.0f, 200.0f, 0.0f));
	if (!PlayButton->OnCreatePlayButton()) {
		return false;
	}

	CreditsButton = new Button("./Assets/Menu UI Buttons/Buttons/Options Button.png", this,Vec3(350.0f, 300.0f, 0.0f));
	if (!CreditsButton->OnCreateCreditsButton()) {
		return false;
	}

	QuitButton = new Button("./Assets/Menu UI Buttons/Buttons/Quit Button.png", this, Vec3(350.0f, 400.0f, 0.0f));
	if (!QuitButton->OnCreateQuitButton()) {
		return false;
	}
    return true;
} 

void MainMenuScreen::OnDestroy()
{
}

void MainMenuScreen::Update(const float time)
{
}

void MainMenuScreen::Render()
{
	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, MainMenuTexture, NULL, NULL);
	PlayButton->RenderPlayButton();
	CreditsButton->RenderCreditsButton();
	QuitButton->RenderQuitButton();
	SDL_RenderPresent(renderer);
}

void MainMenuScreen::HandleEvents(const SDL_Event& event)
{

	SDL_Event MainMenuButtonEvent;
	Vec3 PlayButtonMousePosition = GetPlayButtonMousePos();
	Vec3 CreditsButtonMousePosition = GetCreditsButtonMousePos();
	Vec3 QuitButtonMousePosition  =  GetQuitButtonMousePos();

					if (event.button.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
						if (PlayButton->ClickedPlayButton(PlayButtonMousePosition)) {
							//MainMenuEngine->play2D("./Assets/Game Sounds/Sound Effects/mixkit-arcade-game-jump-coin.wav"); // Using IrrKlang sound library.
							printf("Playing Scene1\n");
							SDL_memset(&MainMenuButtonEvent, 1, sizeof(MainMenuButtonEvent));
							MainMenuButtonEvent.type = game->getChangeScene();
							MainMenuButtonEvent.user.code = 3;
							MainMenuButtonEvent.user.data1 = nullptr;
							MainMenuButtonEvent.user.data2 = nullptr;
							SDL_PushEvent(&MainMenuButtonEvent);
					}	}

					if (event.button.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
						if (CreditsButton->ClickedCreditsButton(CreditsButtonMousePosition)) {
							//MainMenuEngine->play2D("./Assets/Sounds/Sound Effects/mixkit-arcade-game-jump-coin.wav"); // Using IrrKlang sound library.
							printf("Pressing Credits Menu\n");
							SDL_memset(&MainMenuButtonEvent, 1, sizeof(MainMenuButtonEvent));
							MainMenuButtonEvent.type = game->getChangeScene1();
							MainMenuButtonEvent.user.code = 2;
							MainMenuButtonEvent.user.data1 = nullptr;
							MainMenuButtonEvent.user.data2 = nullptr;
							SDL_PushEvent(&MainMenuButtonEvent);
						}
					}

					if (event.button.type == SDL_MOUSEBUTTONUP && event.button.button == SDL_BUTTON_LEFT) {
						if (QuitButton->ClickedQuitButton(QuitButtonMousePosition)) {
							//MainMenuEngine->play2D("./Assets/Sounds/Sound Effects/mixkit-arcade-game-jump-coin.wav"); // Using IrrKlang sound library.
							//SDL_Quit();
						}
					}
				
}
Vec3 MainMenuScreen::GetPlayButtonMousePos()
{
	Uint32 PlayButtonPos;
	int PlayButtonPosX, PlayButtonPosY;
	PlayButtonPos = SDL_GetMouseState(&PlayButtonPosX, &PlayButtonPosY);
	Vec3 PlayButtonMouseScreenCoords = Vec3(float(PlayButtonPosX), float(PlayButtonPosY), 0.0f);
	Vec3 PlayButtonMouseWorldCoords = inverseProjection * (PlayButtonMouseScreenCoords);
	return PlayButtonMouseWorldCoords;
}
Vec3 MainMenuScreen::GetCreditsButtonMousePos()
{
	Uint32 CreditsButtonPos;
	int CreditsButtonPosX, CreditsButtonPosY;
	CreditsButtonPos = SDL_GetMouseState(&CreditsButtonPosX, &CreditsButtonPosY);
	Vec3 CreditsButtonMouseScreenCoords = Vec3(float(CreditsButtonPosX), float(CreditsButtonPosY), 0.0f);
	//Vec3 CreditsButtonMouseWorldCoords = inverseProjection * (CreditsButtonMouseScreenCoords);
	Vec3 CreditsButtonMouseWorldCoords = CreditsButtonMouseScreenCoords;
	return CreditsButtonMouseWorldCoords;
}
Vec3 MainMenuScreen::GetQuitButtonMousePos()
{
	Uint32 QuitButtonPos;
	int QuitButtonPosX, QuitButtonPosY;
	QuitButtonPos = SDL_GetMouseState(&QuitButtonPosX, &QuitButtonPosY);
	Vec3 QuitButtonMouseScreenCoords = Vec3(float(QuitButtonPosX), float(QuitButtonPosY), 0.0f);
	Vec3 QuitButtonMouseWorldCoords = inverseProjection * (QuitButtonMouseScreenCoords);
	return QuitButtonMouseWorldCoords;
}
