#include "include/raylib.h"
#include <iostream>

struct Cell{
    int posX,posY;
    bool take,opti;
    Color color;
};


class Shape{
protected:
    int rotateState;
    int cubeSize=20;
    int x,y;
public:
    Cell *shape;
    Shape();
    ~Shape();
    void render();
    void rotate();
    virtual void move();
};

class U: public Shape{//done
public:
    U();
    ~U();
    void move() override;
};

class P: public Shape{
public:
    P();
    ~P();
    void move() override;
};

class I: public Shape{
public:
    I();
    ~I();
    void move() override;
};

class L: public Shape{
public:
    L();
    void move() override;
};

class T: public Shape{
public:
    T();
    void move() override;
};

class V: public Shape{
public:
    V();
    void move() override;
};