#include "graphics.hpp"
#include "application.hpp"
#include "widget.hpp"
#include "szambeallit.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;

class App: public Application
{
private:
    Szambeallit* sz1;
public:
    App(int width, int height): Application(width, height)
    {
        sz1 = new Szambeallit(this, 40, 40, 200, 35, -10, 10);
    }

    void action(string id)
    {
    }
};


int main()
{
    App appl(800,600);
    ofstream kifajl("mentes.txt");
    ///gout << refresh;
    appl.event_loop();
    return 0;
}
