#ifndef FERDEHAJITAS_HPP
#define FERDEHAJITAS_HPP

#include "widget.hpp"
#include <vector>

using namespace std;

class FerdeHajitas : Widget
{
protected:
    int _category, _id;

    Koord kk;
    vector<Koord> _koordVector;

public:
    FerdeHajitas(Application* parent, int x, int y, int sx, int sy, int category, int id, vector<Koord> koordVector);


    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // FERDEHAJITAS_HPP
