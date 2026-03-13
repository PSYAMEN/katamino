#include "tableau.h"

#include "include/raylib.h"
#include "time.h"
#include "math.h"

Tableau::Tableau(){
    availShape[0]=new U;
    availShape[1]=new P;
    availShape[2]=new I;
    availShape[3]=new L;
    availShape[4]=new T;
    availShape[5]=new V;
    availShape[6]=new W;
    availShape[7]=new X;
    availShape[8]=new F;
    availShape[9]=new Z;
    availShape[10]=new Y;
    availShape[11]=new N;

    nbLigne=12;
    nbPlacedShapes=0;

    for (int i=0;i<5;i++){//met tout a pas opti sauf les coter et met tout a "pas pris"
        for (int j=0;j<nbLigne;j++){
            tab[i][j].opti=false;
            tab[i][j].take=false;
            tab[i][j].color=WHITE;
            if(i==0 || i==4 || j==0 || j==nbLigne-1){
                tab[i][j].opti=true;
            }
        }
    }
}

Tableau::Tableau(int nbL){
    srand(time(NULL));
    availShape[0]=new U;
    availShape[1]=new P;
    availShape[2]=new I;
    availShape[3]=new L;
    availShape[4]=new T;
    availShape[5]=new V;
    availShape[6]=new W;
    availShape[7]=new X;
    availShape[8]=new F;
    availShape[9]=new Z;
    availShape[10]=new Y;
    availShape[11]=new N;
    for (int i=0;i<nbL;i++){//on fait un tableau de shape aleatoire 
        Shape* temp=availShape[i];
        int r=rand()%(12-i)+i;
        availShape[i]=availShape[r];
        availShape[r]=temp;
    }

    nbLigne=nbL;
    nbPlacedShapes=0;

    for (int i=0;i<5;i++){//met tout a pas opti sauf les coter et met tout a "pas pris"
        for (int j=0;j<nbLigne;j++){
            tab[i][j].opti=false;
            tab[i][j].take=false;
            tab[i][j].color=WHITE;
            if(i==0 || i==4 || j==0 ||j==nbLigne-1){
                tab[i][j].opti=true;
            }
        }
    }
}

Tableau::~Tableau(){
    for (int i=0;i<12;i++){
        delete availShape[i];
    }//on a pas besoin de faire la meme pour placedShapes car il pointeron vers les meme shape
}

void Tableau::render(){
    int cubeSize=75;
    int disFromSide=(1000-(900*nbLigne/12))/2;
    BeginDrawing();
    ClearBackground(RAYWHITE);
    for (int i=0;i<=nbLigne;i++){
        DrawLine( disFromSide+i*cubeSize,187,   disFromSide+i*cubeSize,562, BLACK);
    }
    for (int i=0;i<=5;i++){
        DrawLine(disFromSide,187+i*cubeSize, 1000-disFromSide,187+i*cubeSize, BLACK);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<nbLigne;j++){
            if(!tab[i][j].opti || tab[i][j].take) DrawRectangle(disFromSide+j*cubeSize, 187+i*cubeSize, cubeSize-1, cubeSize-1, tab[i][j].color);
            if(tab[i][j].opti && !tab[i][j].take) DrawRectangle(disFromSide+j*cubeSize, 187+i*cubeSize, cubeSize-1, cubeSize-1, GREEN);
        }
    }
    for (int i=0;i<nbLigne;i++){
        availShape[i]->render();
    }
    EndDrawing();
}

void Tableau::placeShape(int indiceS,int x,int y){
    for(int i=0;i<5;i++){
        tab[x+availShape[indiceS]->shape[i].posX][y+availShape[indiceS]->shape[i].posY]=availShape[indiceS]->shape[i];  
        for(int j=-1;j<2;j++){
            for(int k=-1;k<2;k++){
                if(x+availShape[indiceS]->shape[i].posX+j>=0 && x+availShape[indiceS]->shape[i].posX+j<5 && y+availShape[indiceS]->shape[i].posY+k>=0 &&y+availShape[indiceS]->shape[i].posY+k<nbLigne && j!=k){
                    tab[x+availShape[indiceS]->shape[i].posX+j][y+availShape[indiceS]->shape[i].posY+k].opti=true;
                }
            }
        }
    }
    placedShapes[nbPlacedShapes].posX=x;
    placedShapes[nbPlacedShapes].posY=y;
    placedShapes[nbPlacedShapes].indiceDansTab=indiceS;
    placedShapes[nbPlacedShapes].shape=*availShape[indiceS];
    nbPlacedShapes++;
    

}