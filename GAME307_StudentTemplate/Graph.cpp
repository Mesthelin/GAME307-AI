#include "Graph.h"
using namespace std;


Graph::Graph() { // (int numNodes) {
	//	// initialize matrix of cost to have correct number of nodes
	//	// and to have 0.0 weights, i.e. "no connections"
	//	cost.resize(numNodes);
	//	for (unsigned int i = 0; i = numNodes; i++) {
	//		cost[i].resize(numNodes);
	//
	//		for (unsigned int j = o; j < numNodes; j++) {
	//			cost[i][j] = 0.0;	
	//		}
	//	}
}

bool Graph::OnCreate(vector<Node*> nodes_) {


	// ASSUMPTION: nodes_ vector has the node with label "i" in the [i] position of the vector


	// given list of nodes, initialize a matrix of costs with 0.0 weights
	int numNodes = nodes_.size();

	// free up space when out of scope
	cost.resize(numNodes); 

	for (int i = 0; i < numNodes; i++) {
		if (i != nodes_[i]->getLabel()) {
			return false;
		}
		
		// add the nodes to the internal list(map)
		node[i] = nodes_[i];

		// setup connections
		cost[i].resize(numNodes);
		for (int j = 0; j < numNodes; j++) {
			// intialize connection to other nodes
			cost[i][j] = 0.0f;
		}
	}
	return true;
}

Graph::~Graph() {}


int Graph::numNodes() {
	return node.size();
	// return cost.size();
}

void Graph::addWeightedConnection(int fromNode, int toNode, float weight) {
	cost[fromNode][toNode] = weight;
}

vector<int> Graph::neighbours(int fromNode) {
	vector<int> result = {}; // empty list
	for (int j = 0; j < numNodes(); j++) {

		if (cost[fromNode][j] > 0.0f) {
			result.push_back(j);
		}
	}
	return result;
}

vector<int> Graph::Dijkstra(int startNode, int goalNode) {
	// helper variables
	float new_cost;
	int current;

	// // declare current NodeAndPriority
	// NodeAndPriority* currentNodeAndPriority;
	// currentNodeAndPriority = new NodeAndPriority(startNode, 0.0f);
	// 
	// // setup priority queue for frontie of nodes
	// priority_queue<NodeAndPriority, deque<NodeAndPriority>, ComparePriority> frontier; // copy from gitHub
	// frontier.push(*currentNodeAndPriority);

	// track solution path
	vector<int> came_from;
	came_from.resize(numNodes());

	// store cost so far to reach node
	map<int, float> cost_so_far;  // easier to look up a spot in map rather than vector
	cost_so_far[startNode] = 0.0f;

	// TODO Algorithm

	// start looping through the frontier
	{
		// get the node from the top of the frontier, put it in "current"
		// pop it off
		

		// if its the goal, then break out of loop
		// for the neighbours of current node
		{
			// calculate new_cost
			// if neighbour is not in cost_so_far OR new_cost is lower
			{
				// found a better path so update structure(pseudo code)
			}
		}
	}




	return came_from;
}
