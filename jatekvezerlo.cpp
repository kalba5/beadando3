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
    Tank* tank1;
    Tank* tank2;


    vector<string> lovedekek = {"kicsi", "kozepes", "nagy"};
    //FerdeHajitas* ferdeha = new FerdeHajitas(this,1,1,1,1,1);
public:
    MyApp(int width, int height): Application(width, height)
    {
        ang1 = new Szambeallit(this, 40, 30, 60, 40, 0, 90, "Angle", [this](){});
        vel1 = new Szambeallit(this, 120, 30, 60, 40, 0, 100, "Velocity", [this](){});
        button1 = new PushButton(this, 200, 30, 60, 40, "fire", [this](){changePlayer();});
        list1 = new LegorduloLista(this, 40, 100, 200, 40, 3, lovedekek);

        ang1 = new Szambeallit(this, 740, 30, 60, 40, 0, 90, "Angle", [this](){});
        vel1 = new Szambeallit(this, 820, 30, 60, 40, 0, 100, "Velocity", [this](){});
        button1 = new PushButton(this, 900, 30, 60, 40, "fire", [this](){changePlayer();});
        list1 = new LegorduloLista(this, 740, 100, 200, 40, 3, lovedekek);

        tank1 = new Tank(this, 30,537,0,0, "tank_design3_bal.kep");
        //tank1 = new Tank(this, 850,537,0,0, "tank_design3_jobb.kep");
        //ferdeha = new FerdeHajitas(this,1,1,1,1,1);
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
