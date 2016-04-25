#include "Node.h"

//Key : symbol - Value : word

string Node::getWord() { return word; }
long Node::getSymbol() { return symbol; }

//Add to the Node children list the Node n
//If there is already a symbol s in the children list, it just update his linked word
Node* Node::addNode(string w, long s) {
	for (vector<Node *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (((*it)->symbol == s)) {
			if( w != "" ) (*it)->word = w;
			return (*it);
		}
	}
	Node * n = new Node(w, s);
	children.push_back(n);
	return n;

}

//Remove the first child with the symbol s from Node children list. Return true if the remove was sucessfull, otherwise false
bool Node::removeNode(long s) { //True if removed, else false
	for (vector<Node *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (((*it)->symbol == s)) {
			children.erase(it);
			return true;
		}
	}
	return false;
}

//Return true if symbol s is present at least one time in the Node children list. Else return false
bool Node::isPresent(long s) {
	for (vector<Node *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (((*it)->symbol == s)) {
			return true;
		}
	}
	return false;
}

//Return the child of this node with the symbol s. Otherwise return NULL
Node* Node::getChild(long s) {
	int score = 1000;
	int tempScore = 1000;
	Node* tempNode = NULL;
	for (vector<Node *>::iterator it = children.begin(); it != children.end(); ++it)
	{
		if (((*it)->symbol == s)) { //Optimisation because we already found the exact symbol
			return (*it);
		}
		tempScore = Scoring::calculateScore(s, (*it)->symbol);
		if (tempScore < score) {
			score = tempScore;
			tempNode = (*it);
		}
	}
	if (score < SEUIL) 	return tempNode;
	
	else return NULL;
}

//Retun all children of the current Node
vector <Node*> Node::getChildren() {
	return children;
}

//Return true if the current nod has at least one child. Otherwise, return false
bool Node::hasChild() {
	return children.size() != 0;
}

//Constructor of Node. w is the word linked to the symbol s
Node::Node(string w, long s)
{
	word = w;
	symbol = s;
}


Node::~Node()
{
}
