//#include "include/raylib.h"
#include "include/raylib.h"
#include "tableau.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        cout << "Usage: ./program k" << endl;
        return 1;
    }

    int k = stoi(argv[1]);

    vector<char> tab = {'U','P','I','L','T','V','W','X','Z','F','Y','N'};

    InitWindow(750, 1000, "katamino");

    int n = tab.size();

    for (int mask = 0; mask < (1 << n); mask++) {

        if (__builtin_popcount(mask) == k) {

            vector<char> allowed;

            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    allowed.push_back(tab[i]);
                }
            }

            // DEBUG print
            for (char c : allowed)
                cout << c;
            cout << endl;

            Tableau t(k);
            char good[12];
            for (int i=0;i<k;i++){
                good[i]=allowed[i];
            }
            std::cout << "done in : "
                      << t.algorythmeDePlacageOpti(good)
                      << " iterations\n";
        }
    }

    return 0;
}