#ifndef JATEKVEZERLO_HPP
#define JATEKVEZERLO_HPP

#include "graphics.hpp"
#include "palya.hpp"
#include "ferdehajitas.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include "pushbutton.hpp"
#include "tank.hpp"
#include "tank2.hpp"
#include "progressbar.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include <math.h>



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
