#ifndef JATEKVEZERLO_HPP
#define JATEKVEZERLO_HPP

//#include "graphics.hpp"
#include "graphics.hpp"
#include "palya.hpp"
#include "ferdehajitas.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include "pushbutton.hpp"
#include "legordulolista.hpp"
#include "tank.hpp"
#include <iostream>
#include <vector>
#include <fstream>


class JatekVezerlo
{
    int* esemeny;
public:
    JatekVezerlo();
    void run();
    void event_loop();
    int sor_jatekos();
};

#endif // JATEKVEZERLO_HPP
