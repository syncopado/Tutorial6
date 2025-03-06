#include "Node.h"

// Constructors & Destructor
Node::Node(Component* data): data(data), next(nullptr), prev(nullptr){
    
}

Node::~Node(){
    delete data;
}

// Getters
Node* Node::getNext() const{
    return next;
}

Node* Node::getPrev() const{
    return prev;
}

Component* Node::getData() const{
    return data;
}

// Setters
void Node::setNext(Node* next){
    this->next = next;
}

void Node::setPrev(Node* prev){
    this->prev = prev;
}
