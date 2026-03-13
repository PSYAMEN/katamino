#include "forme.h"

struct SavePlacement{
    Shape shape;
    int posX,posY;
    int indiceDansTab;
};

class Tableau{
private:
    Shape tab[5][12];
    int nbLigne;
    Shape availShape[12];
    int nextShape;
    SavePlacement placedShapes[12];
public:
    Tableau();
    Tableau(int nbL);
    bool canPlace(int indiceS,int x,int y);//on prend une forme et on verifie que elle ets pas sur une autre en fonctione de x et y(sa position)
    int nbOpti(int indiceS,int x,int y);//on renvoie le nombre de case sur laquel elle est a coter (diagonale compris normalement)
    void placeShape(int indiceS,int x,int y);//on pose la forme du tableau on invremente nextShape
    void removeShape(int i);//on enleve le ieme element de placed shape(generalement le darnier) et on desincrement le nextShape
    void algorythmeDePlacage();//on recupere le position optimale de chaque forme et le nombre de cas e elle on a coter puis on place la plus optimal(rotation inclus)(celle qui es a coter du plus grand nombre de cases) jusqua que l on puisse plus puis si le tableau pas rempli on nelve la derniere placer et on reregarde pour elle si elle peut etre placer differament et ainsi de suite
    void render();//affiche avec raylib
};