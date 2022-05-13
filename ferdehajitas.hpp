#ifndef FERDEHAJITAS_HPP
#define FERDEHAJITAS_HPP

#include "widget.hpp"
#include <vector>

using namespace std;

class FerdeHajitas : Widget
{
protected:
    int _x, _y, _vel, _ang, _category;
    vector<vector<int>> lovedekGorbe;
    string _nev;

public:
    FerdeHajitas(Application* parent, int x, int y, int vel, int ang, int category);


    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // FERDEHAJITAS_HPP
