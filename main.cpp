#include "include/raylib.h"
#include "tableau.h"

int main(){
    InitWindow(1000, 750, "tests");
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
    tab.placeShape(0, 1,1);
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