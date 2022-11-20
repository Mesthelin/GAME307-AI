#ifndef DECISION_H
#define DECISION_H

//#include "Character.h"
#include "DecisionTreeNode.h"


class Decision : public DecisionTreeNode {
protected:
	DecisionTreeNode* trueNode;
	DecisionTreeNode* falseNode;

public:
	virtual DecisionTreeNode* makeDecision();
	virtual DecisionTreeNode* getBranch();
	virtual bool testValue();
};

#endif // DECISION //