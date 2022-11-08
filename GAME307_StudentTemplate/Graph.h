#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map> // don't really need to but being shown stuff
#include <list>
#include <queue>
#include "Node.h"
#include "A_Star_Node_Priority.h"
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

	void addWeightedConnection(int fromNode, int toNode, float weight);
	
	Node* getNode(int label) { return node[label]; }
	vector<int>neighbours(int fromNode);
	vector<int>AStar(int startNode, int goalNode);

	// create struct with one operation, for use in the comparisons needed by the priority queue
	// (might be better to have in a separate file and included?)
	struct ComparePriority {
		bool operator()(A_Star_Node_Priority const& lhs, A_Star_Node_Priority const& rhs) {
			// make it a min queue
			return lhs.priority > rhs.priority;
		}
	};
};

#endif // GRAPH //