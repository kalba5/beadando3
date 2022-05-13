#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP

#include "widget.hpp"
#include <functional>


class PushButton : public Widget
{
protected:
    bool _checked;
    std::string _text;
    std::function<void()> _f;

public:
    PushButton(Application*, int x, int y, int sx, int sy, std::string text, std::function<void()>);
    virtual void draw() override;
    virtual void handle(genv::event ev) override;
    virtual bool is_checked();
    void action();
};

#endif // PUSHBUTTON_HPP
