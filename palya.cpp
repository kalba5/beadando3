#include "palya.hpp"

Palya::Palya(Application* parent, int x, int y, int sx, int sy, string nev):Widget(parent, x, y, sx, sy), _nev(nev)
{
    be.open(_nev);
}

void Palya::beolvasas(ifstream &be)
{

}
