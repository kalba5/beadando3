#include "graphics.hpp"
#include "application.hpp"
#include "widget.hpp"
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
using namespace genv;

class App: public Application
{
private:
    ///LegorduloLista* ll1;
    ///vector<string> vll1 = {"Ford mustang (1967)", "Audi rs7", "Pagani Zonda", "Tesla model x", "Porsche 911", "Bugatti Chiron", "LaFerrari"};
public:
    App(int width, int height): Application(width, height)
    {
        ///ll1 = new LegorduloLista(this, 40, 250, 250, 35, 5, vll1);
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
