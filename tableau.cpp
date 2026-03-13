#include "tableau.h"

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
        availShape[i]=availShape[rand()%(12-i)+i];
        availShape[rand()%(12-i)+i]=temp;
    }

    nbLigne=nbL;
    nbPlacedShapes=0;
}

Tableau::~Tableau(){
    for (int i=0;i<12;i++){
        delete availShape[i];
    }//on a pas besoin de faire la meme pour plavedShapes car il pointeron vers les meme shape
}