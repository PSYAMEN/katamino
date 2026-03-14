#include "tableau.h"

#include "include/raylib.h"
#include "time.h"
#include "math.h"
//#include <cmath>

Tableau::Tableau(int nbL){
    srand(time(NULL));
    shapes[0]=new U;
    shapes[1]=new I;
    shapes[2]=new L;
    shapes[3]=new T;
    shapes[4]=new V;
    shapes[5]=new X;
    shapes[6]=new P;
    shapes[7]=new W;
    shapes[8]=new F;
    shapes[9]=new Z;
    shapes[10]=new Y;
    shapes[11]=new N;
    for (int i=0;i<12;i++){//on fait un tableau de shape aleatoire 
        Shape* temp=shapes[i];
        int r=rand()%(12-i)+i;
        shapes[i]=shapes[r];
        shapes[r]=temp;
    }
    nbLigne=nbL;
    nbPossibilities=0;

    for(int s=0;s<12;s++){
        switch (shapes[s]->id){
            case 'X':{
                availShape[nbPossibilities]=*shapes[s];
                nbPossibilities++;
                break;
            }


            case 'I':{
                for(int i=0;i<2;i++){
                    shapes[s]->rotate();
                    availShape[nbPossibilities+i]=*shapes[s];
                }
                nbPossibilities+=2;
                break;
            }


            case 'Z':{
                for(int i=0;i<4;i++){
                    shapes[s]->rotate();
                    availShape[nbPossibilities+i]=*shapes[s];
                }
                nbPossibilities+=4;
                break;
            }
            case 'T':{
                for(int i=0;i<4;i++){
                    shapes[s]->rotate();
                    availShape[nbPossibilities+i]=*shapes[s];
                }
                nbPossibilities+=4;
                break;
            }
            case 'U':{
                for(int i=0;i<4;i++){
                    shapes[s]->rotate();
                    availShape[nbPossibilities+i]=*shapes[s];
                }
                nbPossibilities+=4;
                break;
            }
            case 'V':{
                for(int i=0;i<4;i++){
                    shapes[s]->rotate();
                    availShape[nbPossibilities+i]=*shapes[s];
                }
                nbPossibilities+=4;
                break;
            }            
            case 'W':{
                for(int i=0;i<4;i++){
                    shapes[s]->rotate();
                    availShape[nbPossibilities+i]=*shapes[s];
                }
                nbPossibilities+=4;
                break;
            }


            case 'F':{
                for(int j=0;j<2;j++){
                    shapes[s]->flip();
                    for(int i=0;i<4;i++){
                        shapes[s]->rotate();
                        availShape[nbPossibilities+i]=*shapes[s];
                    }
                    nbPossibilities+=4;
                }
                break;
            }
            case 'L':{
                for(int j=0;j<2;j++){
                    shapes[s]->flip();
                    for(int i=0;i<4;i++){
                        shapes[s]->rotate();
                        availShape[nbPossibilities+i]=*shapes[s];
                    }
                    nbPossibilities+=4;
                }
                break;
            }
            case 'P':{
                for(int j=0;j<2;j++){
                    shapes[s]->flip();
                    for(int i=0;i<4;i++){
                        shapes[s]->rotate();
                        availShape[nbPossibilities+i]=*shapes[s];
                    }
                    nbPossibilities+=4;
                }
                break;
            }
            case 'N':{
                for(int j=0;j<2;j++){
                    shapes[s]->flip();
                    for(int i=0;i<4;i++){
                        shapes[s]->rotate();
                        availShape[nbPossibilities+i]=*shapes[s];
                    }
                    nbPossibilities+=4;
                }
                break;
            }
            case 'Y':{
                for(int j=0;j<2;j++){
                    shapes[s]->flip();
                    for(int i=0;i<4;i++){
                        shapes[s]->rotate();
                        availShape[nbPossibilities+i]=*shapes[s];
                    }
                    nbPossibilities+=4;
                }
                break;
            }
        }
    }

    for(int i=0;i<12;i++){
        nbNotAllowed[i]=0;
    }

    nbPlacedShapes=0;

    for (int i=0;i<5;i++){//met tout a pas opti sauf les coter et met tout a "pas pris"
        for (int j=0;j<nbLigne;j++){
            tab[i][j].opti=0;
            tab[i][j].take=false;
            tab[i][j].color=WHITE;
            if(i==0 || i==4 || j==0 ||j==nbLigne-1){
                tab[i][j].opti=1;
            }
        }
    }
    turn=0;
    for (int i=0;i<nbPossibilities;i++){
        std::cout<<"id : "<<availShape[i].id<<" rotateState : "<<availShape[i].getRota()<<" flipped : "<<availShape[i].getFlip()<<std::endl;
    }
    std::cout<<"nbMade : "<<nbPossibilities<<std::endl;
}

Tableau::~Tableau(){
    for (int i=0;i<12;i++){
        delete shapes[i];
    }//on a pas besoin de faire la meme pour placedShapes car il pointeron vers les meme shape
}

void Tableau::render(){
    int cubeSize=75;
    int disFromSide=(1000-(900*nbLigne/12))/2;
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (int i=0;i<=nbLigne;i++){
        DrawLine( 675,disFromSide+i*cubeSize,300,disFromSide+i*cubeSize,    BLACK);
    }
    for (int i=0;i<=5;i++){
        DrawLine( 300+i*cubeSize,1000-disFromSide,300+i*cubeSize, disFromSide,BLACK);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<nbLigne;j++){
            if(tab[i][j].take) DrawRectangle(300+i*cubeSize,disFromSide+j*cubeSize,  cubeSize-1, cubeSize-1, tab[i][j].color);//ceux qui sotn pris
            if(tab[i][j].opti==0 && !tab[i][j].take) DrawRectangle(300+i*cubeSize,disFromSide+j*cubeSize,  cubeSize-1, cubeSize-1, WHITE);//ceux qui sont pas paris mais pas opti
            if(tab[i][j].opti>0 && !tab[i][j].take) DrawRectangle(300+i*cubeSize,disFromSide+j*cubeSize,  cubeSize-1, cubeSize-1, GRAY);//ceux qui sotn pas pris et opti
            char nbNear[1];
            nbNear[0]=tab[i][j].opti+'0';
            DrawText(nbNear, 300+i*cubeSize+10,disFromSide+j*cubeSize+10,20 , BLACK);
        }
    }
    bool placed=false;
    for (int i=0;i<12;i++){
        placed=false;
        for(int j=0;j<nbPlacedShapes;j++){
            if(shapes[i]->id==placedShapes[j].id) placed =true;
        }
        if(!placed)shapes[i]->render();
    }
    EndDrawing();
}

void Tableau::placeShape(int indiceS,int x,int y){
    for(int i=0;i<5;i++){
        int posX=x+availShape[indiceS].shape[i].posX;
        int posY=y+availShape[indiceS].shape[i].posY;
        tab[posX][posY].color=availShape[indiceS].shape[i].color; 
        tab[posX][posY].take=true;
        for(int j=-1;j<2;j++){
            for(int k=-1;k<2;k++){
                if(j*j!=k*k && posX+j>=0 && posX+j<5 && posY+k>=0 && posY+k<nbLigne){
                    tab[posX+j][posY+k].opti++;
                }
            }
        }
    }
    placedShapes[nbPlacedShapes].posX=x;
    placedShapes[nbPlacedShapes].posY=y;
    placedShapes[nbPlacedShapes].id=availShape[indiceS].id;
    placedShapes[nbPlacedShapes].indiceDansTab=indiceS;
    nbPlacedShapes++;


    notAllowed[turn][nbNotAllowed[turn]].flip=availShape[indiceS].getFlip();
    notAllowed[turn][nbNotAllowed[turn]].rota=availShape[indiceS].getRota();
    notAllowed[turn][nbNotAllowed[turn]].id=availShape[indiceS].id;
    notAllowed[turn][nbNotAllowed[turn]].posX=x;
    notAllowed[turn][nbNotAllowed[turn]].posY=y;
    //std::cout<<"banned Shape "<<indiceS<<" at "<<x<<' '<<y<<" on turn : "<<turn<<std::endl;
    
    nbNotAllowed[turn]++;

    turn++;
    //on pose une forme donc on reset la prochaine
}

bool Tableau::canPlace(int indiceS,int x,int y){
    int posX,posY;
    for(int i=0;i<5;i++){
        posX=x+availShape[indiceS].shape[i].posX;
        posY=y+availShape[indiceS].shape[i].posY;
        if(posX<0 || posX>4 || posY<0 || posY>nbLigne-1) return false;
        if(tab[posX][posY].take) {
            return false;
        }
        //std::cout<<"all good "<< i<<std::endl;
    }
    for(int i=0;i<nbPlacedShapes;i++){
        if (placedShapes[i].id==availShape[indiceS].id) return false;
        if (placedShapes[i].indiceDansTab==indiceS) return false;
    }
    //std::cout<<"test for "<<availShape[indiceS].id<<" at : "<<x<<' '<<y<<std::endl;
    for(int j=0;j<nbNotAllowed[turn];j++){
        //std::cout<<notAllowed[turn][j].id<<" at : "<<notAllowed[turn][j].posX<<' '<<notAllowed[turn][j].posY<<" is not allowed on turn : "<<turn<<std::endl;
        if(notAllowed[turn][j].rota==availShape[indiceS].getRota() && notAllowed[turn][j].id==availShape[indiceS].id && notAllowed[turn][j].flip==availShape[indiceS].getFlip() && notAllowed[turn][j].posX==x &&  notAllowed[turn][j].posY==y){return false;}
    }
    return true;
}

int Tableau::nbOpti(int indiceS,int x,int y){
    int nbOpti=0;
    for(int i=0;i<5;i++){
        nbOpti+=tab[x+availShape[indiceS].shape[i].posX][y+availShape[indiceS].shape[i].posY].opti;
    }
    return nbOpti;
 }


void Tableau::removeShape() {
    
}

int Tableau::algorythmeDePlacage(){
    while(!WindowShouldClose()){
        render();
    }return 0;
}