#include "graphics.hpp"
#include "jatekvezerlo.hpp"

using namespace std;
using namespace genv;


JatekVezerlo::JatekVezerlo()
{
    palya1 = new Palya("asd");
    soronJatekos = 1;
}

class Jatek: public Application
{
private:
    Szambeallit* ang1;
    Szambeallit* vel1;
    LegorduloLista* lista1;
    PushButton* loves1;
    vector<string> list1 = {"Baszogep", "pancelkuro" , "elkapmegbasz"};

    Szambeallit* ang2;
    Szambeallit* vel2;
    LegorduloLista* lista2;
    PushButton* loves2;
public:
    Jatek(int width, int height): Application(width, height)
    {
        ang1 = new Szambeallit(this, 40, 40, 50, 35, -10, 10);
        vel1 = new Szambeallit(this, 100, 40, 50, 35, -10, 10);
        lista1 = new LegorduloLista(this, 40, 150, 200, 40, 4, list1);
        loves1 = new PushButton(this, 160, 40, 50, 35, "fire", [this](){loves();});

        ang2 = new Szambeallit(this, 740, 40, 50, 35, -10, 10);
        vel2 = new Szambeallit(this, 800, 40, 50, 35, -10, 10);
        lista2 = new LegorduloLista(this, 740, 150, 200, 40, 4, list1);
        loves2 = new PushButton(this, 860, 40, 50, 35, "fire", [this](){loves();});
    }

    void action(string id)
    {
    }

    void loves()
    {
        //meghivja a ferdehajitas szamolot
        //valahogy kirajzolja a ferdehajitas animaciot
        //eldonti h volt-e talalat, ha igen akkor atallitja hp-t
        //soronJatekos *= -1;
    }

};


int JatekVezerlo::sor_jatekos()
{
    return soronJatekos;
}

void JatekVezerlo::run()
{

}



void JatekVezerlo::event_loop()
{
    //palya1->draw();
    Jatek _jatek(1000,700);

    _jatek.event_loop(soronJatekos);

    cout << "itt vagyok!!!!" << endl;
}

