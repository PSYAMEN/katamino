#include "forme.h"
#include "include/raylib.h"

Shape::Shape(){
    for (int i=0;i<5;i++){
        shape[i].color=RED;
        shape[i].opti=0;
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
    fliped=false;
    x=500;
    y=375;
}

Shape::~Shape(){
    rotateState=0;
    fliped=false;
}

void Shape::render(){
    for (int i=0;i<5;i++){
        DrawRectangle(x+shape[i].posX*cubeSize, y+shape[i].posY*cubeSize, cubeSize, cubeSize, shape[i].color);
    }
}

void Shape::rotate(){
    int save;
    for (int i=0;i<5;i++){
        save=shape[i].posX;
        shape[i].posX=-shape[i].posY;
        shape[i].posY=save;
        //std::cout<<"posX: "<<shape[i].posX<<"  posY: "<<shape[i].posY<<std::endl;
    }
    rotateState=(rotateState+1)%4;
}


bool Shape::operator !=(Shape s2){
    for(int i=0;i<5;i++){
        if(shape[i].posX!=s2.shape[i].posX || shape[i].posY!=s2.shape[i].posY) return true;
    }
    return false;
}

void Shape::flip(){
    for(int i=0;i<5;i++){
        shape[i].posX=-shape[i].posX;
    }
    fliped=!fliped;
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

    shape[0].color=s2.shape[0].color;
    shape[1].color=s2.shape[1].color;
    shape[2].color=s2.shape[2].color;
    shape[3].color=s2.shape[3].color;
    shape[4].color=s2.shape[4].color;
    rotateState=s2.rotateState ;
    
    id=s2.id;

    x=s2.x;
    y=s2.y;
    rotateState=s2.rotateState;
    fliped=s2.fliped;
    cubeSize=s2.cubeSize;
}


int Shape::getRota(){
    return rotateState;
}

bool Shape::getFlip(){
    return fliped;
}

U::U(){
    id='U';
    for (int i=0;i<5;i++){
        shape[i].color=YELLOW;
        shape[i].opti=0;
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
    fliped=false;
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
    id ='P';
    for (int i=0;i<5;i++){
        shape[i].color=PINK;
        shape[i].opti=0;
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
    fliped=false;
    x=100;
    y=400;
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
    id='I';
    for (int i=0;i<5;i++){
        shape[i].color=SKYBLUE;
        shape[i].opti=0;
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
    fliped=false;
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
    id='L';
    for (int i=0;i<5;i++){
        shape[i].color=ORANGE;
        shape[i].opti=0;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=-1;
    shape[1].posX=0;    shape[1].posY=0;
    shape[2].posX=0;    shape[2].posY=1;
    shape[3].posX=0;    shape[3].posY=2;
    shape[4].posX=1;    shape[4].posY=2;

    rotateState=0;
    fliped=false;
    x=100;
    y=200;
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
    id='T';
    for (int i=0;i<5;i++){
        shape[i].color=VIOLET;
        shape[i].opti=0;
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
    fliped=false;
    x=200;
    y=220;
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
    id='V';
    for (int i=0;i<5;i++){
        shape[i].color=MAGENTA;
        shape[i].opti=0;
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
    fliped=false;
    x=100;
    y=300;
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
//X
//XX
// XX
W::W(){
    id='W';
    for (int i=0;i<5;i++){
        shape[i].color=BLUE;
        shape[i].opti=0;
        shape[i].take=true;
    }
    shape[0].posX=0;  shape[0].posY=0;
    shape[1].posX=-1; shape[1].posY=0;
    shape[2].posX=0;  shape[2].posY=1;
    shape[3].posX=1;  shape[3].posY=1;
    shape[4].posX=-1; shape[4].posY=-1;
    rotateState=0;
    fliped=false;
    x=200;
    y=400;
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
    id='X';
    for (int i=0;i<5;i++){
        shape[i].color=MAROON;
        shape[i].opti=0;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=-1;   shape[1].posY=0;
    shape[2].posX=1;    shape[2].posY=0;
    shape[3].posX=0;    shape[3].posY=1;
    shape[4].posX=0;    shape[4].posY=-1;
    rotateState=0;
    fliped=false;
    x=200;
    y=300;
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
    id='F';
    for (int i=0;i<5;i++){
        shape[i].color=LIME;
        shape[i].opti=0;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=1;   shape[1].posY=0;
    shape[2].posX=0;    shape[2].posY=1;
    shape[3].posX=0;    shape[3].posY=-1;
    shape[4].posX=-1;    shape[4].posY=-1;
    rotateState=0;
    fliped=false;
    x=100;
    y=500;
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
    id='Z';
    for (int i=0;i<5;i++){
        shape[i].color=BROWN;
        shape[i].opti=0;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=1;   shape[1].posY=1;
    shape[2].posX=0;    shape[2].posY=1;
    shape[3].posX=0;    shape[3].posY=-1;
    shape[4].posX=-1;    shape[4].posY=-1;
    rotateState=0;
    fliped=false;
    x=200;
    y=500;
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
    id='Y';
    for (int i=0;i<5;i++){
        shape[i].color=GREEN;
        shape[i].opti=0;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=-1;   shape[1].posY=0;
    shape[2].posX=1;    shape[2].posY=0;
    shape[3].posX=2;    shape[3].posY=0;
    shape[4].posX=0;    shape[4].posY=1;
    rotateState=0;
    fliped=false;
    x=100;
    y=600;
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
    id='N';
    for (int i=0;i<5;i++){
        shape[i].color=RED;
        shape[i].opti=0;
        shape[i].take=true;
    }
    shape[0].posX=0;    shape[0].posY=0;
    shape[1].posX=-1;   shape[1].posY=-1;
    shape[2].posX=0;    shape[2].posY=-1;
    shape[3].posX=1;    shape[3].posY=0;
    shape[4].posX=2;    shape[4].posY=0;
    rotateState=0;
    fliped=false;
    x=200;
    y=600;
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