#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v) : view(v)
{

}

void Screen1Presenter::activate()
{
}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::update_fx(AUDIOFX_Type fx) {
    if(fx != curr_fx) {
        view.clearBox(curr_fx);
        curr_fx = fx;
    }

    view.setBox(curr_fx);

    view.updateParameters(curr_fx);
}