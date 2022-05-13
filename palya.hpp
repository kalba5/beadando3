/**#ifndef PALYA_HPP
#define PALYA_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include <vector>
#include <fstream>

using namespace std;

class Palya: public Widget
{
public:
    Palya(Application* parent, int,int,int,int);

    void draw();
    void handle(genv::event ev);
};

#endif // PALYA_HPP*/
