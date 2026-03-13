#include "forme.h"
#include "include/raylib.h"

Shape::Shape(){
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


void Shape::operator =(Shape s2){
    shape[0].posX=s2.shape[0].posX;
    shape[1].posX=s2.shape[1].posX;
    shape[2].posX=s2.shape[2].posX;
    shape[3].posX=s2.shape[3].posX;
    shape[4].posX=s2.shape[4].posX;
    shape[0].posY=s2.shape[0].posY;
    shape[1].posY=s2.shape[1].posY;
    shape[2].posY=s2.shape[2].posY;
    shape[3].posY=s2.shape[3].posY;
    shape[4].posY=s2.shape[4].posY;
    rotateState=s2.rotateState ;
    x=s2.x;
    y=s2.y;
    cubeSize=s2.cubeSize;
}

U::U(){
    
    for (int i=0;i<5;i++){
        shape[i].color=YELLOW;
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
    
    for (int i=0;i<5;i++){
        shape[i].color=PINK;
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
    
    for (int i=0;i<5;i++){
        shape[i].color=SKYBLUE;
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
    
    for (int i=0;i<5;i++){
        shape[i].color=ORANGE;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=-1;
    shape[1].posX=0;    shape[1].posY=0;
    shape[2].posX=0;    shape[2].posY=1;
    shape[3].posX=0;    shape[3].posY=2;
    shape[4].posX=1;    shape[4].posY=2;

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
    
    for (int i=0;i<5;i++){
        shape[i].color=VIOLET;
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
    
    for (int i=0;i<5;i++){
        shape[i].color=GREEN;
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
    
    for (int i=0;i<5;i++){
        shape[i].color=BLUE;
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
    
    for (int i=0;i<5;i++){
        shape[i].color=MAROON;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=-1;   shape[1].posY=0;
    shape[2].posX=1;    shape[2].posY=0;
    shape[3].posX=0;    shape[3].posY=1;
    shape[4].posX=0;    shape[4].posY=-1;
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


//XX
// XX
// X
F::F(){
    
    for (int i=0;i<5;i++){
        shape[i].color=LIME;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=1;   shape[1].posY=0;
    shape[2].posX=0;    shape[2].posY=1;
    shape[3].posX=0;    shape[3].posY=-1;
    shape[4].posX=-1;    shape[4].posY=-1;
    rotateState=0;
    x=900;
    y=100;
};

void F::move(){
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


//XX
// X
// XX

Z::Z(){
    
    for (int i=0;i<5;i++){
        shape[i].color=BROWN;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=1;   shape[1].posY=1;
    shape[2].posX=0;    shape[2].posY=1;
    shape[3].posX=0;    shape[3].posY=-1;
    shape[4].posX=-1;    shape[4].posY=-1;
    rotateState=0;
    x=100;
    y=200;
};

void Z::move(){
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


//XXXX
// X

Y::Y(){
    
    for (int i=0;i<5;i++){
        shape[i].color=SKYBLUE;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=-1;   shape[1].posY=0;
    shape[2].posX=1;    shape[2].posY=0;
    shape[3].posX=2;    shape[3].posY=0;
    shape[4].posX=0;    shape[4].posY=1;
    rotateState=0;
    x=200;
    y=200;
};

void Y::move(){
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


//XX
// XXX

N::N(){
    
    for (int i=0;i<5;i++){
        shape[i].color=RED;
        shape[i].opti=false;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=-1;   shape[1].posY=-1;
    shape[2].posX=0;    shape[2].posY=-1;
    shape[3].posX=1;    shape[3].posY=0;
    shape[4].posX=2;    shape[4].posY=0;
    rotateState=0;
    x=300;
    y=200;
};

void N::move(){
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