#include "include/raylib.h"
#include "tableau.h"

//ATENTION LE X ET Y A L AFFICHGE SONT INVERSER DONC LE X EST SUR LA VERTICALE ET LE Y SUR L HORISONTALE
//DANS LE CODE X EST L HORIZITAL ET Y LA VERTICALE (x entre 0 et 5 et y entre 0 et nbLigne) DONC C NORMAL
//
//
//
//
//
int main(){
    InitWindow(750, 1000, "tests");
    SetTargetFPS(60);


    Shape *shapes[12];
    shapes[0]=new U;
    shapes[1]=new P;
    shapes[2]=new I;
    shapes[3]=new L;
    shapes[4]=new T;
    shapes[5]=new V;
    shapes[6]=new W;
    shapes[7]=new X;
    shapes[8]=new F;
    shapes[9]=new Z;
    shapes[10]=new Y;
    shapes[11]=new N;
    Tableau tab;
    if(tab.canPlace(0, 0, 0)){
        std::cout<<"problem\n";
    }
    std::cout<<"\n\n\n"<<tab.nbOpti(2, 2, 0)<<std::endl;
    tab.placeShape(2, 2, 0);

    if(tab.canPlace(0, 2, 2)){
        //std::cout<<"problem2\n";
    }
    while(!WindowShouldClose()){
        //BeginDrawing();
        //ClearBackground(RAYWHITE);
        //for (int i=0;i<12;i++){
        //    shapes[i]->rotate();
        //    shapes[i]->render();
        //    shapes[i]->move();
        //}
        //EndDrawing();
        tab.render();
    }
}