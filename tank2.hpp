#ifndef TANK2_HPP
#define TANK2_HPP

#include "widget.hpp"
#include <vector>
#include <fstream>
using namespace std;

class Tank2: public Widget
{
    vector<vector<vector<int>>> kep;
    ifstream befajl;
    int magassag, szelesseg;
    int _csoX, _csoY;
    int _hp;
public:
    Tank2(Application* parent, int x, int y, int sx, int sy, string nev);
    bool talalat(int kx, int ky, int kr);
    void setCso(int csoX, int csoY);
    virtual void beolvas(ifstream& befajl);
    virtual void draw();
    virtual void handle(genv::event ev);

};

#endif // TANK_HPP
