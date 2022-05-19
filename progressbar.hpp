#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include "widget.hpp"

class ProgressBar : public Widget
{
    int _value;
public:
    ProgressBar(Application* parent, int x, int y, int sx, int sy);

    int getValue();
    void setValue(int vl);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // PROGRESSBAR_HPP
