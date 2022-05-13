#include "palya.hpp"

Palya::Palya(string nev): _nev(nev)
{
    be.open(_nev);
}

void Palya::beolvasas(ifstream &be)
{
    cout << "be.good:" << be.good() << endl;
}




void Palya::handle(genv::event ev)
{

}
