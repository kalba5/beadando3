#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Koord
{
    int _ax, _ay;
};

class Widget;                                   //jelezzuk, hogy majd kesobb lesz egy class Widget
class Application
{
protected:
    std::vector<Widget*> widgets;               //egy Widget* tipusu vector amiben eltaroljuk a hasznalt widgeteket
    std::ofstream kifajl;                       //menteshez kellett
    void draw_background();
    int* actualPlayer;
    void changePlayer();
    bool _gameover;
    std::string gyoztes;
public:
    Application(int, int);                      //konstruktor a hatter mereteinek
    void register_widget(Widget*);              //bele pusholja a widgeteket a widget vektorba
    void event_loop();
    //virtual void action(std::string) = 0;


};

#endif // APPLICATION_HPP
