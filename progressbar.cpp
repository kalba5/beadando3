#include "progressbar.hpp"

using namespace genv;

ProgressBar::ProgressBar(Application* parent, int x, int y, int sx, int sy, std::string txt): Widget(parent, x, y, sx, sy), _text(txt)
{
    _percent = 100;
}


void ProgressBar::draw()
{
    gout << color(0,0,0) << move_to(_x, _y-10) << text(_text);
    gout << color(255,0,0) << move_to(_x, _y) << box(_size_x, _size_y)
         << color(0,0,255) << move_to(_x+2, _y+2) << box( (_size_x-4)*_percent /100, _size_y-4);
}

int ProgressBar::getPercent()
{
    return _percent;
}

void ProgressBar::setPercent(int pr)
{
    _percent = pr;
}

void ProgressBar::handle(genv::event ev)
{

}
