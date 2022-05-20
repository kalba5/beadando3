#include "application.hpp"
#include "graphics.hpp"
#include "widget.hpp"
#include <iostream>

using namespace genv;

Application::Application(int width, int height)
{
    gout.open(width, height);
    actualPlayer = new int(-1);
    _gameover = false;
}
void Application::register_widget(Widget* widget)
{
    widgets.push_back(widget);
}

void Application::changePlayer()
{
    *actualPlayer = *actualPlayer *  (-1);

}


void Application::draw_background()
{
    gout << move_to(0,0) << color(0,255,255) << box(1000,600)
         << move_to(0, 600) << color(96,56,19) << box(1000, 100);
}

void Application::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev && ev.keycode != key_escape)
    {
        if(!_gameover)
        {
            //std::cout << "actualPlayer:" << *actualPlayer << std::endl;      ///deleteme
            if (ev.type == ev_mouse && ev.button == btn_left)
            {
                for (size_t i=0; i < widgets.size(); i++)
                {
                    if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                    {
                        if(*actualPlayer == -1 && i >= 0 && i <= 3)
                        {
                            focus = i;
                            widgets[i]->setColorSelected();

                        }
                        else if(*actualPlayer == 1 && i >= 4 && i <= 7)
                        {
                            focus = i;
                            widgets[i]->setColorSelected();

                        }
                    }
                }
            }


            if (focus != -1)
            {
                widgets[focus]->handle(ev);
            }


            if (ev.type == ev_mouse && ev.button == btn_left)       //hatterre balklikkre a focus visszaall -1 -re
            {
                int tmpFocus = -1;
                for (size_t i=0; i < widgets.size(); i++)
                {
                    if (widgets[i]->is_selected(ev.pos_x,ev.pos_y))
                    {
                        tmpFocus = 1;
                    }
                }

                if (ev.button == btn_left && tmpFocus == -1)
                {
                    focus = -1;
                }
            }


            for (size_t i=0; i<widgets.size(); i++)             //a nem kijelolt widgetek keretenek a szinet visszarakja basicre
            {
                if (i != focus)
                {
                    widgets[i]->setColorBasic();
                }
            }

            if(focus == 2)
            {
                focus = -1;
            }
            else if(focus == 7)
            {
                focus = -1;
            }

            draw_background();                                  //kirajzolja a hatteret

            for (Widget* w : widgets)                           //kirajzolja a widgeteket
            {
                w->draw();
            }

            if(*actualPlayer == 1)
            {
                gout << move_to(420,30) << color(255,0,0) << box(160,30);
                gout << move_to(428,50) << color(0,0,255) << text("Player two's turn!");
            }
            else if(*actualPlayer == -1)
            {
                gout << move_to(420,30) << color(0,0,255) << box(160,30);
                gout << move_to(428,50) << color(255,0,0) << text("Player one's turn!");
            }

            gout << refresh;
        }
        else //if(_gameover)
        {
            std::string gmover="Game over!";
            std::string winner_ = "The winner is: Player ";
            std::string quit="Press escape to quit";
            gout << color(255,255,255) << move_to(0,0) << box(999,699) << color(0,0,0)
                 << move_to(500- gout.twidth(gmover)/2, 100) << text(gmover)
                 << move_to(500-gout.twidth(winner_)/2, 150) << text(winner_) << text(gyoztes)
                 << move_to(500-gout.twidth(quit)/2, 200) << text(quit) << refresh;
            /*if(ev.keycode == key_enter)
            {

            }*/
        }
    }
}
