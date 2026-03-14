#include "forme.h"

//ATENTION LE X ET Y A L AFFICHGE SONT INVERSER DONC LE X EST SUR LA VERTICALE ET LE Y SUR L HORISONTALE
//DANS LE CODE X EST L HORIZITAL ET Y LA VERTICALE (x entre 0 et 5 et y entre 0 et nbLigne) DONC C NORMAL
//
//
//
//

struct SavePlacement{ //pas un pointeur come on prend une copie parce que si c'est des pointeur on peu pas le comparer a ceux dans availShapes
    int posX=-1,posY=-1;
    int indiceDansTab=-1;
    char id='O';
};

struct saveState{
    int posX=-1,posY=-1;
    char id='O';
    int rota=0;
    int turn=0;
    bool flip=false;
};
class Tableau{
private:
    Cell tab[5][12];
    int nbLigne;//aussi utiliser pour availShape pour savoir combien de formes on a le droit d'utiliser
    Shape* shapes[12];
    Shape availShape[63];
    int nbPossibilities;
    SavePlacement placedShapes[12];//pas un pointeur come on prend une copie parce que si c'est des pointeur on peu pas le comparer a ceux dans availShapes
    int nbPlacedShapes;//le nombre de formes placer(fini le prog si )
    saveState notAllowed[12][63*12*5];
    int turn;
    int nbNotAllowed[12];//donne aussi en qq sorte la prochiane shape a placer
public:
    Tableau(int nbL=12);//shuffel et met de maniere aleatoir les shape dans availShapes pour pas toujour avoir les meme si le tableau est pas entier (comme chaque shape fait 5 case il y a nbL shape dans le tableau de disponible)
    ~Tableau();
    void render();//affiche avec raylib (en vert c'est les case opti en blac celle qui ne sont pas placer) ceux qui sont placer sont de leur couleur
    bool canPlace(int indiceS,int x,int y);//on prend une forme et on verifie que elle ets pas sur une autre en fonctione de x et y(sa position) faudra aussi faire gaffe a pas faire des check en dehors du tableau!!! sinon seg fault (tu fait just in if(x+shape.cell[i]>0 && x+shape.cell[i]<12))
    //bool isNotPlaced(int indiceS);
    int nbOpti(int indiceS,int x,int y);//on renvoie le nombre de case sur laquel elle est a coter (diagonale compris normalement)
    void placeShape(int indiceS,int x,int y);//on pose la forme du tableau on recolaps aussi le tableau de shape deriere (on utilisera toujour la shapes[0] comme prochain placement )
    bool solve();
    void removeShape();//on enleve le dernier element de placed shape et on desincrement le nbPlacedShape
    int algorythmeDePlacage();//on recupere le position optimale de chaque forme et le nombre de cas e elle on a coter puis on place la plus optimal(rotation inclus)(celle qui es a coter du plus grand nombre de cases) jusqua que l on puisse plus puis si le tableau pas rempli on nelve la derniere placer et on reregarde pour elle si elle peut etre placer differament et ainsi de suite en gros le main (il appel aussi render)
    //la condition de fin est qqch du genre nbPlacedShape!=nbLigne
};