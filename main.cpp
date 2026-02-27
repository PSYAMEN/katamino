#include "include/raylib.h"
#include "forme.h"

int main(){
    InitWindow(1000, 750, "tests");
    Shape *shapes[12];
    shapes[0]=new U;
    shapes[1]=new P;
    shapes[2]=new I;
    shapes[3]=new L;
    shapes[4]=new T;
    shapes[5]=new V;
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i=0;i<6;i++){
            shapes[i]->rotate();
            shapes[i]->render();
            shapes[i]->move();
        }
        EndDrawing();
    }
}