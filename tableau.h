#include "forme.h"

struct SavePlacement{
    Shape shape;
    int posX,posY;
    int indiceDansTab;
    int nbOpti;//on verifiera ca quand in decrement pour etre sur de ne pas reprendre le meme 2 fois d'affiler et eviter de refaire idefiniment la meme operaton
};

class Tableau{
private:
    Cell tab[5][12];
    int nbLigne;//aussi utiliser pour availShape pour savoir combien de formes on a le droit d'utiliser
    Shape *availShape[12];
    SavePlacement placedShapes[12];
    int nbPlacedShapes;//le nombre de formes placer(fini le prog si )
public:
    Tableau();//tableau de 5x12 avec toute les forme de disponible
    Tableau(int nbL);//shuffel et met de maniere aleatoir les shape dans availShapes pour pas toujour avoir les meme si le tableau est pas entier (comme chaque shape fait 5 case il y a nbL shape dans le tableau de disponible)
    void render();//affiche avec raylib
    bool canPlace(int indiceS,int x,int y);//on prend une forme et on verifie que elle ets pas sur une autre en fonctione de x et y(sa position)
    int nbOpti(int indiceS,int x,int y);//on renvoie le nombre de case sur laquel elle est a coter (diagonale compris normalement)
    void placeShape(int indiceS,int x,int y);//on pose la forme du tableau on recolaps aussi le tableau de shape deriere (on utilisera toujour la shapes[0] comme prochain placement )
    void removeShape(int i);//on enleve le ieme element de placed shape(generalement le darnier) et on desincrement le nextShape
    void algorythmeDePlacage();//on recupere le position optimale de chaque forme et le nombre de cas e elle on a coter puis on place la plus optimal(rotation inclus)(celle qui es a coter du plus grand nombre de cases) jusqua que l on puisse plus puis si le tableau pas rempli on nelve la derniere placer et on reregarde pour elle si elle peut etre placer differament et ainsi de suite en gros le main (il appel aussi render)

};