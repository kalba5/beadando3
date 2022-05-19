#include "progressbar.hpp"

using namespace genv;

ProgressBar::ProgressBar(Application* parent, int x, int y, int sx, int sy): Widget(parent, x, y, sx, sy)
{
    _value = 75;
}


void ProgressBar::draw()
{
    gout << color(255,0,0) << move_to(_x, _y) << box(_size_x, _size_y)
         << color(0,0,255) << move_to(_x+2, _y+2) << box( (_size_x-4)*_value /100, _size_y-4);
}
void ProgressBar::handle(genv::event ev)
{

}
