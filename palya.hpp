#ifndef PALYA_HPP
#define PALYA_HPP

#include "widget.hpp"
#include <vector>
#include <fstream>

class Palya : public Widget
{
protected:
    std::string _nev;
    std::vector<int> palyaGorbe;
    std::vector<std::vector<std::vector<int>>> palyaSzin;
    std::ifstream beolvas;
public:
    Palya(std::string nev);
    void gorbeSzamol();
    void beolvasas(std::string beNev);

    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // PALYA_HPP
