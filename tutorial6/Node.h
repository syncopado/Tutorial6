#ifndef NODE_H
#define NODE_H

#include "Component.h"

class Node {
    public:
        // Constructor & Destructor
        Node(Component* data);
        ~Node();

        // Getters
        Node* getNext() const;
        Node* getPrev() const;
        Component* getData() const;

        // Setters
        void setNext(Node* next);
        void setPrev(Node* prev);

    private:
        Node* next;
        Node* prev;
        Component* data;

};

#endif