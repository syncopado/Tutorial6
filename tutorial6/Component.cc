#include "Component.h"

// Constructors
Component::Component(const Rectangle& properties, const string& id): properties(properties), id(id){

}

Component::Component(int x, int y, int width, int height, const string& id): properties(Rectangle(x, y, width, height)), id(id){

}

// Destructor
Component::~Component(){
    cout << "Component destructor called~" << endl;
}

// Getters
Rectangle Component::getProperties() const{
    return properties;
}

string Component::getId() const{
    return id;
}

// Methods
bool Component::overlaps(const Component& other) const{
    return properties.overlaps(other.properties);
}

// Print
void Component::print(){
    cout << "Component: " << id << endl;
}