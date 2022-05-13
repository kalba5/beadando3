#include "graphics.hpp"
#include "application.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include "pushbutton.hpp"
#include "legordulolista.hpp"
#include <iostream>
#include <vector>
#include <fstream>
#include "jatekvezerlo.hpp"
using namespace std;
using namespace genv;

class App: public JatekVezerlo
{
};


int main()
{
    App a;
    a.event_loop();
    return 0;
}
