#ifndef SZAMBEALLIT_HPP
#define SZAMBEALLIT_HPP

#include "widget.hpp"
#include <functional>

class Szambeallit : public Widget
{
    int _value;
    int upperLimit, lowerLimit;
    int rEgerFel, gEgerFel, bEgerFel;
    int rEgerLe, gEgerLe, bEgerLe;
    std::string _felirat;
    std::function<void()> _f;
public:
    Szambeallit(Application* parent, int x, int y, int sx, int sy, int lL, int uL, std::string felirat, std::function<void()>);
    int getValue();
    int gombFolott(int, int);
    void action();
    virtual void draw();
    virtual void handle(genv::event ev);

};

#endif // SZAMBEALLIT_HPP
