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

	//			0
	//			|
	//	  1 --- 2 --- 3
	//			|
	//			4

	int count = 5;
	nodes.resize(count); // private variable
	
	// create nodes
	for (int i = 0; i < count; i++) {

		nodes[i] = new Node(i); // new node with label 'i' from Node.h
	}

	// since nodes are created here, 
	// then Scene is responsible for deleting them later on

	// create Graph
	graph = new Graph(); // vector of node pointers
	if (!graph->OnCreate(nodes)) {
		return false;
	}


	// create connections from 0
	graph->addWeightedConnection(nodes[0]->getLabel(),
							   nodes[2]->getLabel(),
							   1.0f);

	// connections from 1
	graph->addWeightedConnection(nodes[1]->getLabel(),
							   nodes[2]->getLabel(),
							   1.0f);

	// connections from 2
	graph->addWeightedConnection(nodes[2]->getLabel(),
							   nodes[0]->getLabel(),
							   1.0f);

	graph->addWeightedConnection(nodes[2]->getLabel(),
							   nodes[1]->getLabel(),
							   1.0f);

	graph->addWeightedConnection(nodes[2]->getLabel(),
							   nodes[3]->getLabel(),
							   1.0f);

	graph->addWeightedConnection(nodes[2]->getLabel(),
							   nodes[4]->getLabel(),
							   1.0f);

	// connections from 3
	graph->addWeightedConnection(nodes[3]->getLabel(),
							   nodes[2]->getLabel(),
							   1.0f);

	// connections from 4
	graph->addWeightedConnection(nodes[4]->getLabel(),
							   nodes[2]->getLabel(),
							   1.0f);


	cout << "naighbours of 2:\n";
	for (int nodeLabel : graph->neighbours(2)) {

		cout << "Node " << nodeLabel << "\n";
	}

	return true;
}

void Scene2::OnDestroy() {

	delete graph;
}

void Scene2::Update(const float deltaTime) {}

void Scene2::Render() {}

void Scene2::HandleEvents(const SDL_Event& event) {}
