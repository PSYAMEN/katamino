#include "include/raylib.h"
#include <iostream>

struct Cell{
    int posX,posY;
    bool take;
    int opti;
    Color color;
};


class Shape{
protected:
    int rotateState;
    int cubeSize=20;
    int x,y;
    bool fliped;
public:
    char id;
    Cell shape[5];//on y a acces deja pour les constructeur masi aussi 
    Shape();
    ~Shape();
    int getRota();
    void render();
    void rotate();
    virtual void move();
    void flip();
    bool getFlip();
    void operator =(Shape s2);
    bool operator !=(Shape s2);
};

//X X
//XXX
class U: public Shape{//done    
public:                        
    U();
    ~U();
    void move() override;
};

//XXX
//XX
class P: public Shape{//fini
public:
    P();
    ~P();
    void move() override;
};

//XXXXX
class I: public Shape{//fini
public:
    I();
    ~I();
    void move() override;
};

//XXXX
//X
class L: public Shape{//fini
public:
    L();
    void move() override;
};

//XXX
// X
// X
class T: public Shape{//fini
public:
    T();
    void move() override;
};

//X
//X
//XXX
class V: public Shape{//fini
public:
    V();
    void move() override;
};


//X
//XX
// XX
class W: public Shape{//a fair
public:
    W();
    void move() override;
};

// X
//XXX
// X
class X: public Shape{//a fair
public:
    X();
    void move() override;
};

//XX
// XX
// X
class F: public Shape{//a fair
public:
    F();
    void move() override;
}; 

//XX
// X
// XX
class Z: public Shape{//a fair
public:
    Z();
    void move() override;
};


//XXXX
// X
class Y: public Shape{//a fair
public:
    Y();
    void move() override;
};

//XX
// XXX
class N: public Shape{//a fair
public:
    N();
    void move() override;
};