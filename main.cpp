#include "graphics.hpp"
#include "application.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include "pushbutton.hpp"
#include "palya.hpp"
#include "legordulolista.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include "jatekvezerlo.hpp"
using namespace std;
using namespace genv;

class Jatek: public JatekVezerlo
{

};


int main()
{

    Jatek a;
    a.run();
    return 0;
}
