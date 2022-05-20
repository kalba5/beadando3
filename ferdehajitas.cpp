#include "ferdehajitas.hpp"


using namespace genv;

FerdeHajitas::FerdeHajitas(Application* parent, int x, int y, int sx, int sy, int category, int id, vector<Koord> koordVector):
                Widget(_parent, x,y,sx,sy), _category(category), _koordVector(koordVector), _id(id)
{

}


void FerdeHajitas::draw()
{
    if (_id == 1)
    {
        gout << move_to(90,546);
        for(size_t ii = 0; ii < _koordVector.size(); ii++)
        {
            gout << color(255,0,0) << line_to(_koordVector[ii]._ax +90, 546-4.59 - _koordVector[ii]._ay) << refresh;
        }
    }
    else if(_id == 2)
    {
        gout << move_to(910,546);
        for(size_t ii = 0; ii < _koordVector.size(); ii++)
        {
            gout << color(255,0,0) << line_to((_koordVector[ii]._ax +910)* -1, 546-4.59 - _koordVector[ii]._ay) << refresh;
        }
    }
}


void FerdeHajitas::handle(genv::event ev)
{

}
