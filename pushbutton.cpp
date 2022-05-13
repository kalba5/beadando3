#include "pushbutton.hpp"

using namespace genv;
using namespace std;

PushButton::PushButton(Application* parent, int x, int y, int sx, int sy, std::string text, function<void()> f)
    : Widget(parent, x,y,sx,sy), _text(text), _f(f)
{
    _checked = 0;
}

void PushButton::draw()
{
    gout.load_font("LiberationSans-Regular", 16);
    gout << color(rFrame, gFrame, bFrame) << move_to(_x, _y) << box(_size_x, _size_y);
    gout << color(255,255,255) << move_to(_x+2, _y+2) << box(_size_x-4, _size_y-4) << color(0,0,0);
    gout << color(0,0,0) << move_to(_x +(_size_x - gout.twidth(_text))/2, _y+(_size_y - gout.cascent() - gout.cdescent()) / 2)
         << text(_text);

}

bool PushButton::is_checked()
{
    return _checked;
}


void PushButton::action()
{
    _f();
}

void PushButton::handle(genv::event ev)
{
    if(ev.type == ev_mouse && ev.button == btn_left && is_selected(ev.pos_x, ev.pos_y))
    {
        action();
    }

}
