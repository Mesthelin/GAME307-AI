#include "Scene1.h"
#include "VMath.h"


Scene1::Scene1(SDL_Window* sdlWindow_, GameManager* game_){
	window = sdlWindow_;
    game = game_;
	renderer = SDL_GetRenderer(window);
	xAxis = 25.0f;
	yAxis = 15.0f;

	// create a NPC
	blinky = nullptr;
	spyGuy = NULL;
	blackHat = NULL;
}

Scene1::~Scene1(){
	if (blinky) 
	{
		blinky->OnDestroy();
		delete blinky;
	}
}

bool Scene1::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, xAxis, 0.0f, yAxis, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;
	
	/// Turn on the SDL imaging subsystem
	IMG_Init(IMG_INIT_PNG);

	// Set player image to PacMan
	SDL_Surface* image;
	SDL_Texture* texture;

	image = IMG_Load("pacman.png");
	texture = SDL_CreateTextureFromSurface(renderer, image);
	game->getPlayer()->setImage(image);
	game->getPlayer()->setTexture(texture);

	// Set up characters, choose good values for the constructor
	// or use the defaults, like this
	blinky = new Character();
	if (!blinky->OnCreate(this))
	{
		return false;
	}

	image = IMG_Load("Blinky.png");
	texture = SDL_CreateTextureFromSurface(renderer, image);
	if (image == nullptr) {
		std::cerr << "Can't open the image\n";
		return false;
	}
	else {
		blinky->setTexture(texture);
		SDL_FreeSurface(image);
	}
	//blinky->readDecisionTreeXML("playerinrange.xml");
	blinky->readStateMachineXML("some.xml");

	////////////////////////////////////////////////////////////////////
	Vec3 position = Vec3(15.0f, 8.0f, 0.0f);
	float orientation = 0.0f;
	float maxAcceleration = 3.5f;
	float maxSpeed = 3.5f;
	float maxRotation = 0.0f;
	spyGuy = new StaticBody(position, orientation, maxSpeed, maxRotation);

	image = IMG_Load("Clyde.png");
	texture = SDL_CreateTextureFromSurface(renderer, image);
	if (image == nullptr) {
		std::cerr << "Can't open the image\n";
		return false;
	}
	else {
		spyGuy->setTexture(texture);
		SDL_FreeSurface(image);
	}
	////////////////////////////////////////////////////////////////////
	{
		Vec3 position = Vec3(8.0f, 4.0f, 0.0f);
		float orientation = 0.0f;
		float maxAcceleration = 3.5f;
		float maxSpeed = 3.5f;
		float maxRotation = 0.0f;
		blackHat = new StaticBody(position, orientation, maxSpeed, maxRotation);

		image = IMG_Load("blackHat.png");
		texture = SDL_CreateTextureFromSurface(renderer, image);
		if (image == nullptr) {
			std::cerr << "Can't open the image\n";
			return false;
		}
		else {
			blackHat->setTexture(texture);
			SDL_FreeSurface(image);
		}
	}
	////////////////////////////////////////////////////////////////////
	// end of character set ups

	return true;
}

void Scene1::OnDestroy() {}

void Scene1::Update(const float deltaTime) {
	// Calculate and apply any steering for npc's
	blinky->Update(deltaTime);

	// Create our target
	Body* player = game->getPlayer(); // player = target

	// spyGuy
	KinematicSeek* steeringAlgorithm;
	steeringAlgorithm = new KinematicSeek(spyGuy, player);
	KinematicSteeringOutput* steering;
	steering = steeringAlgorithm->getSteering();

	// blackHat
	KinematicArrive* steeringAlgorithm2;
	steeringAlgorithm2 = new KinematicArrive(blackHat, player);
	KinematicSteeringOutput* steering2;
	steering2 = steeringAlgorithm2->getSteering();

	spyGuy->Update(deltaTime, steering);
	blackHat->Update(deltaTime, steering2);

	// Update player
	game->getPlayer()->Update(deltaTime);
}

void Scene1::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	// render any npc's
	blinky->Render(0.15f);

	////////////////////////////////////////////////////////////////////
	SDL_Rect square;
	Vec3 screenCoords;
	int w, h;
	float scale = 0.15f;

	SDL_QueryTexture(spyGuy->getTexture(), nullptr, nullptr, &w, &h);
	w = static_cast<int>(w * scale);
	h = static_cast<int>(h * scale);

	screenCoords = projectionMatrix * spyGuy->getPos();
	square.x = static_cast<int>(screenCoords.x - 0.5f * w);
	square.y = static_cast<int>(screenCoords.y - 0.5f * h);
	square.w = w;
	square.h = h;
	
	float orientation = spyGuy->getOrientation() * 180.0f / M_PI;
	//SDL_RenderCopyEx(renderer, spyGuy->getTexture(), nullptr, &square,
		//			 orientation, nullptr, SDL_FLIP_NONE);
	////////////////////////////////////////////////////////////////////
	{
		float scale = 0.5f;
		SDL_QueryTexture(blackHat->getTexture(), nullptr, nullptr, &w, &h);
		w = static_cast<int>(w * scale);
		h = static_cast<int>(h * scale);

		screenCoords = projectionMatrix * blackHat->getPos();
		square.x = static_cast<int>(screenCoords.x - 0.5f * w);
		square.y = static_cast<int>(screenCoords.y - 0.5f * h);
		square.w = w;
		square.h = h;
		
		float orientation = blackHat->getOrientation() * 180.0f / M_PI;
		//SDL_RenderCopyEx(renderer, blackHat->getTexture(), nullptr, &square,
			//			 orientation, nullptr, SDL_FLIP_NONE);
	}
	////////////////////////////////////////////////////////////////////

	// render the player
	game->RenderPlayer(0.10f);

	SDL_RenderPresent(renderer);
}

void Scene1::HandleEvents(const SDL_Event& event)
{
	// send events to npc's as needed

	// send events to player as needed
	game->getPlayer()->HandleEvents(event);
}
