#include "graphics.hpp"
#include "jatekvezerlo.hpp"

using namespace std;
using namespace genv;



JatekVezerlo::JatekVezerlo()
{
}

class MyApp: public Application
{
private:
    Szambeallit* ang1;
    Szambeallit* vel1;
    LegorduloLista* list1;
    PushButton* button1;


    vector<string> cars = {"audi", "bmw", "mercedes", "porsche", "ferrari"};
public:
    MyApp(int width, int height): Application(width, height)
    {
        ang1 = new Szambeallit(this, 40, 30, 60, 40, 0, 100);
        vel1 = new Szambeallit(this, 120, 30, 60, 40, 0, 100);
        button1 = new PushButton(this, 200, 30, 60, 40, "fire", [this](){changePlayer();});
        list1 = new LegorduloLista(this, 40, 100, 200, 40, 3, cars);

        ang1 = new Szambeallit(this, 740, 30, 60, 40, 0, 100);
        vel1 = new Szambeallit(this, 820, 30, 60, 40, 0, 100);
        button1 = new PushButton(this, 900, 30, 60, 40, "fire", [this](){changePlayer();});
        list1 = new LegorduloLista(this, 740, 100, 200, 40, 3, cars);
    }

    int aktualisJatekos()
    {
        return *actualPlayer;
    }

    void changePlayer()
    {
        *actualPlayer = *actualPlayer * (-1);
    }
};

void JatekVezerlo::run()
{
    MyApp* app;
    app = new MyApp(1000,700);
    app->event_loop();
}
