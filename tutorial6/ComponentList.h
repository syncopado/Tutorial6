#ifndef COMPONENT_LIST_H
#define COMPONENT_LIST_H

#include "Node.h"

class ComponentList {
    public:
    // Constructors
    ComponentList();
    // Destructor
    ~ComponentList();

    // Getters
    Component* get(int index) const;
    Component* get(const string& id) const;
    int getSize() const;

    // Setters

    // Methods
    bool add(Component* comp);  // Add to the back
    bool add(Component* comp, int index);
    Component* remove(int index);
    Component* remove(const string& id);

private:
    Node* head;
    Node* tail;
    int size;
};

#endif