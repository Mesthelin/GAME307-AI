#include "Graph.h"
using namespace std;


Graph::Graph() {

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

vector<int> Graph::AStar(int startNode, int goalNode) {
	// helper variables
	float new_cost;
	int current;

	// declare current NodeAndPriority
	A_Star_Node_Priority* currentNodeAndPriority;
	currentNodeAndPriority = new A_Star_Node_Priority(startNode, 0.0f);

	// setup priority queue for frontie of nodes
	priority_queue<A_Star_Node_Priority, deque<A_Star_Node_Priority>, ComparePriority> frontier; // copy from gitHub
	frontier.push(*currentNodeAndPriority);

	// track solution path
	vector<int> came_from;
	came_from.resize(numNodes());

	// store cost so far to reach node
	map<int, float> cost_so_far;  // easier to look up a spot in map rather than vector
	cost_so_far[startNode] = 0.0f;

	//// TODO Algorithm

	//// start looping through the frontier
	while (!frontier.empty()) {
		// get the node from the top of the frontier, put it in "current"
		current = frontier.top().node;
		// pop it off
		frontier.pop();
		// if its the goal, then break out of loop
		if (current == goalNode) {
			break;
		}

		// for the neighbours of current node
		for (auto next : neighbours(current)) {
			// calculate new_cost
			new_cost = cost_so_far[current] + cost[current][next];
			// if neighbour is not in cost_so_far OR new_cost is lower
			if (!cost_so_far.count(next) || new_cost < cost_so_far[next]) {

				cost_so_far[next] = new_cost;
				float priority = new_cost;
				currentNodeAndPriority = new A_Star_Node_Priority(next, priority);
				frontier.push(*currentNodeAndPriority);
				came_from[next] = current;
			}
			// found a better path so update structure(pseudo code)		
		}

		return came_from;
	}
}
