#include "include/raylib.h"
#include "forme.h"

int main(){
    InitWindow(1000, 750, "tests");
    Shape *shapes[12];
    shapes[0]=new U;
    shapes[1]=new P;
    shapes[2]=new I;
    SetTargetFPS(60);
    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        for (int i=0;i<3;i++){
            shapes[i]->rotate();
            shapes[i]->render();
            shapes[i]->move();
        }
        EndDrawing();
    }
}