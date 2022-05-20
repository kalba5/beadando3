#ifndef PROGRESSBAR_HPP
#define PROGRESSBAR_HPP

#include "widget.hpp"


class ProgressBar : public Widget
{
    int _percent;
    std::string _text;
public:
    ProgressBar(Application* parent, int x, int y, int sx, int sy, std::string txt);

    int getPercent();
    void setPercent(int vl);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // PROGRESSBAR_HPP
