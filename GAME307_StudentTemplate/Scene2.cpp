#include "Scene2.h"


Scene2::Scene2(SDL_Window* sdlWindow_, GameManager* game_){
	window = sdlWindow_;
    game = game_;
	renderer = SDL_GetRenderer(window);
	xAxis = 25.0f;
	yAxis = 15.0f;
}

Scene2::~Scene2() {}

bool Scene2::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, xAxis, 0.0f, yAxis, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;
	inverseProjection = MMath::inverse(projectionMatrix);

	// turn on SDL imaging
	IMG_Init(IMG_INIT_PNG);

	// create tile with node
	int rows = ceil(yAxis / tileHeight);
	int cols = ceil(xAxis / tileWidth);
	// create tiles and populate nodes list
	createTiles(rows, cols);

	// create Graph
	graph = new Graph(); // vector of node pointers
	if (!graph->OnCreate(nodes)) {
		cout << "Failed!\n";
		return false;
	}

	calculateConnectionWeights();

	return true;
}

void Scene2::createTiles(int rows, int cols) {
	tiles.resize(rows);
	for (int i = 0; i < rows; i++) {
		tiles[i].resize(cols);
	}

	Node* n;
	Tile* t;
	int i, j, label;
	i = 0; // along y(rows)
	j = 0; // along x(columns)
	label = 0;

	for (float y = 0.5f * tileHeight; y < yAxis; y += tileHeight) {
		// do stuff for row, where y stays constant
		for (float x = 0.5f * tileWidth; x < xAxis; x += tileWidth) {

			n = new Node(label, Vec3(x, y, 0.0f));
			t = new Tile(n, tileWidth, tileHeight, this);
			n->setTile(t);
			nodes.push_back(n);
			tiles[i][j] = t;

			label++;
			j++;
		}
		j = 0;
		i++;
	}
}

void Scene2::calculateConnectionWeights() {
	int rows = tiles.size();
	int cols = tiles[0].size();

	for (int i = 0; i < rows; i++) {

		for (int j = 0; j < cols; j++) {

			//				i+1, j
			//	i, j-1		  i, j		i, j+1
			//				i-1, j

			int from = tiles[i][j]->getNode()->getLabel();

			// left is i, j-1
			if (j > 0) {
				int to = tiles[i][j - 1]->getNode()->getLabel();
				graph->addWeightedConnection(from, to, tileWidth);
			}
			// right is i, j+1
			if (j < cols - 1) {
				int to = tiles[i][j + 1]->getNode()->getLabel();
				graph->addWeightedConnection(from, to, tileWidth);
			}
			// above is i+1, j
			if (i < rows - 1) {
				int to = tiles[i + 1][j]->getNode()->getLabel();
				graph->addWeightedConnection(from, to, tileWidth);
			}
			// below is i-1, j
			if (i > 0) {
				int to = tiles[i - 1][j]->getNode()->getLabel();
				graph->addWeightedConnection(from, to, tileWidth);
			}
		}
	}
}

void Scene2::OnDestroy() {

	delete graph;
}

void Scene2::Update(const float deltaTime) {}

void Scene2::Render() {
	//clear frame
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0); // GOOD
	SDL_RenderClear(renderer);

	// render all tiles
	for (int i = 0; i < tiles.size(); i++) {

		for (int j = 0; j < tiles[i].size(); j++) {
			tiles[i][j]->Render();
		}
	}

	// Render it all
	SDL_RenderPresent(renderer);
}

void Scene2::HandleEvents(const SDL_Event& event) {}
