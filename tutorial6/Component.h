#ifndef COMPONENT_H
#define COMPONENT_H

#include "defs.h"

using namespace std;

class Component {
    public:
        // Constructors & Destructor
        Component(const Rectangle& properties, const string& id);
        Component(int x, int y, int width, int height, const string& id);
        virtual ~Component();

        // Getters
        Rectangle getProperties() const;
        string getId() const;

        // Methods
        bool overlaps(const Component& other) const;
        // virtual void draw(Display* display, Window& window, GC& gc, Rectangle& position) const = 0;

        // Print
        virtual void print();

    private:
        Rectangle properties;
        string id;

};

#endif