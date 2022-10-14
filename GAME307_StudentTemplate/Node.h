#ifndef NODE_H
#define NODE_H


//class Node {
//public:
//    // member variables
//    int label;
//
//    // constructors
//    Node();
//    Node(int i_);
//
//    // useful functions
//    void print();
//};


 class Node {
 private:
 	int label;
 
 public:
 	Node(int label_) { label = label_; } // inline
 	~Node() {};
 	int getLabel() { return label; }
 };

#endif // NODE_H //