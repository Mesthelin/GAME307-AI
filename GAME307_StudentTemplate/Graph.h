#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map> // don't really need to but being shown stuff
#include <list>
#include <queue>
#include "Node.h"
using namespace std;


class Graph {
private:
	// a 2d matrix of the connection costs
	vector<vector< float >> cost;

	// list of nodes, stl vector maybe but map matches textbooks
	map<int, Node*> node;

public:
	Graph(); // (int numNodes);
	~Graph();

	bool OnCreate(vector<Node*> nodes_);
	int numNodes();

	Node* getNode(int label) { return node[label]; }

	void addWeightedConnection(int fromNode, int toNode, float weight);
	vector<int>neighbours(int fromNode);
	//vector<int>AStar(int startNode, int goalNode);
};

#endif // GRAPH //