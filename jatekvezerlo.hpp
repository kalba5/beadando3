#ifndef JATEKVEZERLO_HPP
#define JATEKVEZERLO_HPP

//#include "graphics.hpp"
#include "graphics.hpp"
#include "application.hpp"
#include "palya.hpp"
#include "ferdehajitas.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include "pushbutton.hpp"
#include "legordulolista.hpp"
#include <iostream>
#include <vector>
#include <fstream>


class JatekVezerlo
{
    Palya* palya1;
    int soronJatekos;
    int sor_jatekos();;
public:
    JatekVezerlo();
    void run();
    void event_loop();
};

#endif // JATEKVEZERLO_HPP
