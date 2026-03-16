//#include "include/raylib.h"
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
    int calc=0;
    Tableau tab(12);
    InitWindow(750, 1000, "katamino");
    tab.algorythmeDePlacage();
    return 0;
}