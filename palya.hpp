#ifndef PALYA_HPP
#define PALYA_HPP

#include "widget.hpp"
#include <vector>
#include <fstream>

using namespace std;

class Palya : public Widget
{
protected:
    string _nev;
    vector<int> palyaGorbe;
    vector<vector<vector<int>>> palyaSzin;
    ifstream be;
public:
    Palya(Application* parent, int x, int y, int sx, int sy, string nev);
    void gorbeSzamol();
    void beolvasas(ifstream &be);
    vector<int> getGorbe();

    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // PALYA_HPP
