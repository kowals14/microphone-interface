#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <audioFX.h>
#include <Color.hpp>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void clearBox(AUDIOFX_Type FX);
    void setBox(AUDIOFX_Type FX);
    void updateParameters(AUDIOFX_Type FX);
protected:
};

#endif // SCREEN1VIEW_HPP