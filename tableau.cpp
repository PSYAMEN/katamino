#include "tableau.h"

#include "include/raylib.h"
#include "time.h"
#include "math.h"

Tableau::Tableau(){
    availShape[0]=new U;
    availShape[1]=new I;
    availShape[2]=new L;
    availShape[3]=new T;
    availShape[4]=new V;
    availShape[5]=new X;
    availShape[6]=new P;
    availShape[7]=new W;
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
    availShape[1]=new I;
    availShape[2]=new L;
    availShape[3]=new T;
    availShape[4]=new V;
    availShape[5]=new X;
    availShape[6]=new P;
    availShape[7]=new W;
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
        DrawLine( 675,disFromSide+i*cubeSize,300,disFromSide+i*cubeSize,    BLACK);
    }
    for (int i=0;i<=5;i++){
        DrawLine( 300+i*cubeSize,1000-disFromSide,300+i*cubeSize, disFromSide,BLACK);
    }
    for(int i=0;i<5;i++){
        for(int j=0;j<nbLigne;j++){
            if(tab[i][j].take) DrawRectangle(300+i*cubeSize,disFromSide+j*cubeSize,  cubeSize-1, cubeSize-1, tab[i][j].color);//ceux qui sotn pris
            if(!tab[i][j].opti>0 && !tab[i][j].take) DrawRectangle(300+i*cubeSize,disFromSide+j*cubeSize,  cubeSize-1, cubeSize-1, WHITE);//ceux qui sont pas paris mais pas opti
            if(tab[i][j].opti && !tab[i][j].take) DrawRectangle(300+i*cubeSize,disFromSide+j*cubeSize,  cubeSize-1, cubeSize-1, GREEN);//ceux qui sotn pas pris et opti
        }
    }
    for (int i=nbPlacedShapes;i<nbLigne;i++){
        availShape[i]->render();
    }
    EndDrawing();
}

void Tableau::placeShape(int indiceS,int x,int y){
    for(int i=0;i<5;i++){
        tab[x+availShape[indiceS]->shape[i].posX][y+availShape[indiceS]->shape[i].posY]=availShape[indiceS]->shape[i];  
        tab[x+availShape[indiceS]->shape[i].posX][y+availShape[indiceS]->shape[i].posY].take=true;
        for(int j=-1;j<2;j++){
            for(int k=-1;k<2;k++){
                if(x+availShape[indiceS]->shape[i].posX+j>=0 && x+availShape[indiceS]->shape[i].posX+j<5 && y+availShape[indiceS]->shape[i].posY+k>=0 &&y+availShape[indiceS]->shape[i].posY+k<nbLigne && j*j!=k*k){
                    tab[x+availShape[indiceS]->shape[i].posX+j][y+availShape[indiceS]->shape[i].posY+k].opti++;
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

bool Tableau::canPlace(int indiceS,int x,int y){
    for(int i=0;i<5;i++){
        if(x+availShape[indiceS]->shape[i].posX<0 || x+availShape[indiceS]->shape[i].posX>5 || y+availShape[indiceS]->shape[i].posY<0 || y+availShape[indiceS]->shape[i].posY>nbLigne-1) return false;
        if(tab[x+availShape[indiceS]->shape[i].posX][y+availShape[indiceS]->shape[i].posY].take) return false;
    }
    return true;
}

int Tableau::nbOpti(int indiceS,int x,int y){
    int nbOpti=0;
    for(int i=0;i<5;i++){
        nbOpti+=tab[x+availShape[indiceS]->shape[i].posX][y+availShape[indiceS]->shape[i].posY].opti;
    }
    return nbOpti;
 }


void Tableau::removeShape(int i){//a faire

}

void Tableau::algorythmeDePlacage(){
    while(!WindowShouldClose()){
        while(!WindowShouldClose() && nbLigne!=nbPlacedShapes){
            //ecrire la fonctione ici


            //finir ici 
            render();
        }
        render();
    }
}