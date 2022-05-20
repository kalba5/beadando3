#include "tank.hpp"
#include "graphics.hpp"

using namespace genv;
Tank::Tank(Application* parent, int x, int y, int sx, int sy, string nev): Widget(parent, x,y,sx,sy)
{
    befajl.open(nev);
    kep=vector<vector<vector<int>>>(magassag,vector<vector<int>> (szelesseg,vector<int>(3)));
    beolvas(befajl);
    _hp=100;
    _csoX = 75;
    _csoY = 0;
}


void Tank::beolvas(ifstream &be)
{
    be >> szelesseg >> magassag;
    kep=vector<vector<vector<int>>>(magassag,vector<vector<int>> (szelesseg,vector<int>(3)));
    for(int i=0; i<magassag; i++)
    {
        for(int j=0; j<szelesseg; j++)
        {
            be >> kep[i][j][0] >>kep[i][j][1] >> kep[i][j][2];
        }
    }
}

void Tank::draw()
{
    canvas c_tank;
    c_tank.open(116,64);
    c_tank.transparent(true);
    for (size_t i=0; i< kep.size(); i++)
    {
        for(int j=0; j<szelesseg; j++)
        {
            c_tank << color(kep[i][j][0],kep[i][j][1],kep[i][j][2]) <<
                    move_to(j+ 0, i+ 0) << dot;
        }
    }

    gout << stamp(c_tank, _x, _y);
    //cout << "cso_x:" << _csoX << "    cso_y:" << _csoY << endl;


    for (int i=0; i<15; i++)
    {
        gout << color(115, 112, 92) << move_to(85+i, 546) << line(_csoX, _csoY);
    }
    /*int tmpY = _csoY-10;
    for (int i=0; i<15; i++)
    {
        gout << color(255,0,0) << move_to(90, 541+i) << line(_csoX, _csoY+i);
    }*/
}


bool Tank::talalat(int kx, int ky, int kr)
{
    if(kx-kr <= _x+szelesseg && ky+kr >= _y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Tank::setCso(int csoX, int csoY)
{
    _csoX = csoX;
    _csoY = csoY;
}


void Tank::handle(genv::event ev)
{
}
