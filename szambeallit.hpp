#ifndef SZAMBEALLIT_HPP
#define SZAMBEALLIT_HPP

#include "widget.hpp"

class Szambeallit : public Widget
{
    int _value;
    int upperLimit, lowerLimit;
    int rEgerFel, gEgerFel, bEgerFel;
    int rEgerLe, gEgerLe, bEgerLe;
    std::string _felirat;
public:
    Szambeallit(Application* parent, int x, int y, int sx, int sy, int lL, int uL, std::string felirat);
    int getValue();
    int gombFolott(int, int);
    virtual void draw();
    virtual void handle(genv::event ev);

};

#endif // SZAMBEALLIT_HPP
