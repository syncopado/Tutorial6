#ifndef DEFS_H
#define DEFS_H
#define MAX_COMPONENTS 256

#include <iostream>
#include <string>
#include <vector>
#include <X11/Xlib.h>


#define CuColour unsigned long

// X11 does not run on Gradescope, so we need to mock the X11 functions
#define XOpenDisplay(display) ((void*)0) //mocking XOpenDisplay
#define XCreateSimpleWindow(display, root, x, y, width, height, border_width, border, background) ((void*)0) //mocking XCreateSimpleWindow
#define XStoreName(display, win, name) ((void)0) //mocking XStoreName
#define XCreateGC(display, win, valuemask, values) ((void*)0) //mocking XCreateGC
#define XMapWindow(display, win) ((void)0) //mocking XMapWindow
#define XFlush(display) ((void)0) //mocking XFlush
#define XSetForeground(display, gc, foreground) ((void)0) //mocking XSetForeground
#define XDrawRectangle(display, win, gc, x, y, width, height) ((void)0) //mocking XDrawRectangle
#define XDrawString(display, win, gc, x, y, str, len) ((void)0) //mocking XDrawString
#define XDrawLine(display, win, gc, x1, y1, x2, y2) ((void)0) //mocking XDrawLine
#define XDrawArc(display, win, gc, x, y, width, height, angle1, angle2) ((void)0) //mocking XDrawArc
#define XFillRectangle(display, win, gc, x, y, width, height) ((void)0) //mocking XFillRectangle
#define XFillArc(display, win, gc, x, y, width, height, angle1, angle2) ((void)0) //mocking XFillArc

struct Rectangle{
    int x;
    int y;
    int width;
    int height;
    Rectangle(): x(0), y(0), width(0), height(0){}
    Rectangle(int x, int y, int width, int height): x(x), y(y), width(width), height(height){}
    Rectangle(const Rectangle& rect): x(rect.x), y(rect.y), width(rect.width), height(rect.height){}
    bool overlaps(const Rectangle& rect) const{
        if (x < rect.x + rect.width && x + width > rect.x && y < rect.y + rect.height && y + height > rect.y){
            return true;
        }
        if (rect.x < x + width && rect.x + rect.width > x && rect.y < y + height && rect.y + rect.height > y){
            return true;
        }
        return false;
    }

    bool contains(int x, int y) const{
        return x >= this->x && x <= this->x + width && y >= this->y && y <= this->y + height;
    }
};



#endif