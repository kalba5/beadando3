#include <chrono>
#include <thread>


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
    ProgressBar* hp1;


    Szambeallit* ang2;
    Szambeallit* vel2;
    LegorduloLista* list2;
    PushButton* button2;
    ProgressBar* hp2;

    Tank* tank1;
    Tank2* tank2;



    Koord kk;
    vector<Koord> koordinatak;
    vector<string> lovedekek = {"kicsi", "kozepes", "nagy"};
    FerdeHajitas* fh1;
public:
    MyApp(int width, int height): Application(width, height)
    {
        ang1 = new Szambeallit(this, 40, 90, 60, 40, 0, 90, "Angle", [this](){csoXY(ang1, tank1);} );
        vel1 = new Szambeallit(this, 120, 90, 60, 40, 0, 100, "Velocity", [this](){});
        button1 = new PushButton(this, 200, 90, 60, 40, "fire", [this](){fire(ang1, vel1, 1);});
        list1 = new LegorduloLista(this, 40, 160, 200, 40, 3, lovedekek);
        hp1 = new ProgressBar(this, 40, 30, 200, 20, "Heal points:");

        ang2 = new Szambeallit(this, 740, 90, 60, 40, 0, 90, "Angle", [this](){csoXY2(ang2, tank2);});
        vel2 = new Szambeallit(this, 820, 90, 60, 40, 0, 100, "Velocity", [this](){});
        button2 = new PushButton(this, 900, 90, 60, 40, "fire", [this](){fire(ang2, vel2, 2);});
        list2 = new LegorduloLista(this, 740, 160, 200, 40, 3, lovedekek);
        hp2 = new ProgressBar(this, 740, 30, 200, 20, "Heal points:");

        tank1 = new Tank(this, 30,537,0,0, "tank_design3_bal.kep");
        tank2 = new Tank2(this, 850,537,0,0, "tank_design3_bal.kep");

        fh1 = new FerdeHajitas(this, 0,0,0,0, 0, 1, koordinatak);
    }

    int aktualisJatekos()
    {
        return *actualPlayer;
    }

    void fire(Szambeallit* _ang, Szambeallit* _vel, int id)
    {
        *actualPlayer = *actualPlayer * (-1);
        ferdeHajitas(_ang->getValue(), _vel->getValue(), id);
        /*if (id == 1)
        {
            fh1->draw();
        }*/
    }

    void ferdeHajitas(int _ang, int _vel, int id)
    {
        koordinatak.clear();
        double h = 4.59;
        double distance;
        double time;
        double partTime;
        double rad = (M_PI*_ang)/180;    //fokbol csinal radiant

        //kiszamolja a distance-ot
        distance = (_vel* cos(rad)* (_vel* sin(rad) + sqrt( _vel*_vel* sin(rad) * sin(rad) + 2 * 9.81 * h) )) / 9.81;
            //cout << "itt a distance: " << distance << endl;

        //kiszamolja h ezt mennyi ido alatt teszi meg
        time = distance / (_vel * cos(rad));
            //cout << "itt a time: " << time << endl;

        //felosztja 100 egyenlo reszre az idot
        partTime = time/100;

        //kiszamolja a 100 idopillanatban az aktualis x es y erteket es ezt beleteszi a koordinatak vectorba
        for (int i=0; i < 99; i++)
        {
            kk._ax = _vel* partTime*i * cos(rad) *12.2;
            kk._ay = (_vel* partTime*i * sin(rad) - (9.81/2) * partTime*partTime*i*i) *12.2;
            koordinatak.push_back(kk);
            cout << "parttime: " << partTime << endl;
            cout << "i: " << i << endl;
            cout << "x: " << kk._ax << " " << "y: " << kk._ay << endl;
        }

        ///kirajzol
        if (id == 1)
        {
            gout << move_to(90,546);
            for(size_t ii = 0; ii < koordinatak.size(); ii++)
            {
                gout << color(255,0,0) << line_to(koordinatak[ii]._ax +90, 546-h- koordinatak[ii]._ay) << refresh;

                this_thread::sleep_for(std::chrono::milliseconds(25));
            }
        }
        else if (id == 2)
        {
            gout << move_to(910,546);
            for(size_t ii = 0; ii < koordinatak.size(); ii++)
            {
                gout << color(255,0,0) << line_to(910 - koordinatak[ii]._ax, 546- h - koordinatak[ii]._ay) << refresh;

                this_thread::sleep_for(std::chrono::milliseconds(25));
            }
        }
    }


    void csoXY(Szambeallit* sz, Tank* tank)       //kiszamolja es beallitja a cso szoget
    {
        int x_, y_;
        x_ = cos(sz->getValue() * M_PI /180) * 75;
        y_ = sin(sz->getValue() * M_PI /180) * -75;

        tank->setCso(x_, y_);
    }

    void csoXY2(Szambeallit* sz, Tank2* tank)       //kiszamolja es beallitja a cso szoget
    {
        int x_, y_;
        x_ = cos(sz->getValue() * M_PI /180) * -75;
        y_ = sin(sz->getValue() * M_PI /180) * -75;

        tank->setCso(x_, y_);
    }
};

void JatekVezerlo::run()
{
    MyApp* app;
    app = new MyApp(1000,700);
    app->event_loop();
}
