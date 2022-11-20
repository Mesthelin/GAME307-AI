#ifndef DECISION_TREE_NODE_H
#define DECISION_TREE_NODE_H
// ABSTRACT CLASS ^^^ CANNOT CREATE INSTANCES OF THIS


class Character;
class DecisionTreeNode {
protected:
	Character* owner;

public:
	virtual DecisionTreeNode* makeDecision() = 0;

};

#endif // DECISION_TREE_NODE_H //