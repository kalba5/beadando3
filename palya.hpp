#ifndef PALYA_HPP
#define PALYA_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>
#include <fstream>

using namespace std;

class Palya
{
protected:
    string _nev;
    vector<int> palyaGorbe;
    vector<vector<vector<int>>> palyaSzin;
    ifstream be;
public:
    Palya(string nev);
    void gorbeSzamol();
    void beolvasas(ifstream &be);
    vector<int> getGorbe();

    void draw();
    void handle(genv::event ev);
};

#endif // PALYA_HPP
