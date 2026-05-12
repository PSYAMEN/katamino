//#include "include/raylib.h"
#include "include/raylib.h"
#include "tableau.h"
#include <iostream>
#include <fstream>

//ATENTION LE X ET Y A L AFFICHGE SONT INVERSER DONC LE X EST SUR LA VERTICALE ET LE Y SUR L HORISONTALE
//DANS LE CODE X EST L HORIZITAL ET Y LA VERTICALE (x entre 0 et 5 et y entre 0 et nbLigne) DONC C NORMAL
//
//
//
//
//
int main(int argc, char* argv[]){
    srand(time(NULL));
    InitWindow(750, 1000, "katamino");
    int nb=12;
    if(argc==2){
        nb = std::stoi(argv[1]);
    }
    long long int iterMoy=0;
    for(int i=0;i<100;i++){
        Tableau tab(nb);
        iterMoy+=tab.algorythmeDePlacageOpti();
        WaitTime(1);
    }
    std::cout<<"iteration moyen : "<<iterMoy/100<<std::endl;
    return 0;
}