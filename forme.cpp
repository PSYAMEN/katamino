#include "forme.h"
#include "include/raylib.h"

Shape::Shape(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=RED;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=-1;
    shape[1].posX=-1;
    shape[2].posX=0;
    shape[3].posX=0;
    shape[4].posX=1;
    shape[0].posY=0;
    shape[1].posY=-1;
    shape[2].posY=0;
    shape[3].posY=-1;
    shape[4].posY=0;
    rotateState=0;
    x=500;
    y=375;
}

Shape::~Shape(){
    delete [] shape;
    rotateState=0;
}

void Shape::render(){
    for (int i=0;i<5;i++){
        DrawRectangle(x+shape[i].posX*cubeSize, y+shape[i].posY*cubeSize, cubeSize, cubeSize, shape[i].color);
    }
}

void Shape::rotate(){
    if(!IsKeyPressed(KEY_ENTER)) return;
    int save;
    bool mouse=false;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x) && (GetMouseY()>=shape[i].posY*cubeSize+y && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y)) mouse=true; 
        //std::cout<<"Shape "<<i<<" X:"<<shape[i].posX*cubeSize+x<<"  Shape "<<i<<" Y: "<<shape[i].posY*cubeSize+y<<std::endl;
    }
    std::cout<<"mouseX: "<<GetMouseX()<<"   mouseY: "<<GetMouseY()<<std::endl;
    
    if (mouse){
        for (int i=0;i<5;i++){
            save=shape[i].posX;
            shape[i].posX=-shape[i].posY;
            shape[i].posY=save;
            std::cout<<"posX: "<<shape[i].posX<<"  posY: "<<shape[i].posY<<std::endl;
        }
        rotateState=(rotateState+1)%4;
    }
}

void Shape::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX();
            y=GetMouseY();
            break;
        case 1:
            x=GetMouseX()-cubeSize;
            y=GetMouseY();
            break;
        case 2:
            x=GetMouseX()-cubeSize;
            y=GetMouseY()-cubeSize;
            break;
        case 3:
            x=GetMouseX();
            y=GetMouseY()-cubeSize;
            break;
        }
    }
}

U::U(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=DARKGREEN;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;
    shape[1].posX=-1;
    shape[2].posX=1;
    shape[3].posX=-1;
    shape[4].posX=1;
    shape[0].posY=0;
    shape[1].posY=0;
    shape[2].posY=0;
    shape[3].posY=-1;
    shape[4].posY=-1;
    rotateState=0;
    x=100;
    y=100;
}

U::~U(){
    delete [] shape;
    rotateState=0;
}

void U::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 1:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 2:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 3:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        }
    }
}

P::P(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=GREEN;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=-1;
    shape[1].posX=-1;
    shape[2].posX=0;
    shape[3].posX=0;
    shape[4].posX=1;
    shape[0].posY=0;
    shape[1].posY=-1;
    shape[2].posY=0;
    shape[3].posY=-1;
    shape[4].posY=0;
    rotateState=0;
    x=700;
    y=100;
}

P::~P(){
    delete [] shape;
    rotateState=0;
}

void P::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX();
            y=GetMouseY();
            break;
        case 1:
            x=GetMouseX()-cubeSize;
            y=GetMouseY();
            break;
        case 2:
            x=GetMouseX()-cubeSize;
            y=GetMouseY()-cubeSize;
            break;
        case 3:
            x=GetMouseX();
            y=GetMouseY()-cubeSize;
            break;
        }
    }
}

I::I(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=PINK;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;
    shape[1].posX=-1;
    shape[2].posX=1;
    shape[3].posX=-2;
    shape[4].posX=2;
    shape[0].posY=0;
    shape[1].posY=0;
    shape[2].posY=0;
    shape[3].posY=0;
    shape[4].posY=0;
    rotateState=0;
    x=200;
    y=100;
}

I::~I(){
    delete [] shape;
    rotateState=0;
}

void I::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 1:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 2:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 3:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        }
    }
}

L::L(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=BLUE;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;
    shape[1].posX=0;
    shape[2].posX=0;
    shape[3].posX=0;
    shape[4].posX=1;
    shape[0].posY=-1;
    shape[1].posY=0;
    shape[2].posY=1;
    shape[3].posY=2;
    shape[4].posY=2;
    rotateState=0;
    x=300;
    y=100;
}

void L::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize;
            break;
        case 1:
            x=GetMouseX();
            y=GetMouseY()-cubeSize/2;
            break;
        case 2:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()+cubeSize/2;
            break;
        case 3:
            x=GetMouseX()-cubeSize;
            y=GetMouseY()-cubeSize/2;
            break;
        }
    }
}

T::T(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=ORANGE;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;
    shape[1].posX=0;
    shape[2].posX=0;
    shape[3].posX=-1;
    shape[4].posX=-2;
    shape[0].posY=-1;
    shape[1].posY=0;
    shape[2].posY=1;
    shape[3].posY=0;
    shape[4].posY=0;
    rotateState=0;
    x=400;
    y=100;
}

void T::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX();
            y=GetMouseY()-cubeSize/2;
            break;
        case 1:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY();
            break;
        case 2:
            x=GetMouseX()-cubeSize;
            y=GetMouseY()-cubeSize/2;
            break;
        case 3:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize;
            break;
        }
    }
}

V::V(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=DARKPURPLE;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=-1;
    shape[1].posX=-1;
    shape[2].posX=-1;
    shape[3].posX=0;
    shape[4].posX=1;
    shape[0].posY=-1;
    shape[1].posY=0;
    shape[2].posY=1;
    shape[3].posY=1;
    shape[4].posY=1;
    rotateState=0;
    x=500;
    y=100;
}

void V::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX()+cubeSize/2;
            y=GetMouseY()-cubeSize-cubeSize/2;
            break;
        case 1:
            x=GetMouseX()+cubeSize/2;
            y=GetMouseY()+cubeSize/2;
            break;
        case 2:
            x=GetMouseX()-cubeSize-cubeSize/2;
            y=GetMouseY()+cubeSize/2;
            break;
        case 3:
            x=GetMouseX()-cubeSize-cubeSize/2;
            y=GetMouseY()-cubeSize-cubeSize/2;
            break;
        }
    }
}

W::W(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=GREEN;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;
    shape[1].posX=-1;
    shape[2].posX=0;
    shape[3].posX=1;
    shape[4].posX=-1;
    shape[0].posY=0;
    shape[1].posY=0;
    shape[2].posY=1;
    shape[3].posY=1;
    shape[4].posY=-1;
    rotateState=0;
    x=800;
    y=100;
}

void W::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 1:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 2:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 3:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        }
    }
}

// X
//XXX
// X
X::X(){
    shape=new Cell[5];
    for (int i=0;i<5;i++){
        shape[i].color=PURPLE;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;
    shape[1].posX=-1;
    shape[2].posX=1;
    shape[3].posX=0;
    shape[4].posX=0;
    shape[0].posY=0;
    shape[1].posY=0;
    shape[2].posY=0;
    shape[3].posY=1;
    shape[4].posY=-1;
    rotateState=0;
    x=600;
    y=100;
};


void X::move(){
    bool move=false;
    if(!IsMouseButtonDown(MOUSE_LEFT_BUTTON)) return;
    for (int i=0;i<5;i++){
        if ((GetMouseX()>=shape[i].posX*cubeSize+x-5 && GetMouseX()<shape[i].posX*cubeSize+cubeSize+x+5) && (GetMouseY()>=shape[i].posY*cubeSize+y-5 && GetMouseY()<shape[i].posY*cubeSize+cubeSize+y+5)) move=true; 
    }
    if (move){
        switch(rotateState){
        case 0:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 1:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 2:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        case 3:
            x=GetMouseX()-cubeSize/2;
            y=GetMouseY()-cubeSize/2;
            break;
        }
    }
}