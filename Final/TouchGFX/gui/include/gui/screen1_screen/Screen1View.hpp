#ifndef SCREEN1VIEW_HPP
#define SCREEN1VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <../../../../AudioFX/audioFX.h>

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void updateParameters(AUDIOFX_Type, float*);
    void changeFX(AUDIOFX_Type,AUDIOFX_Type);
protected:
};

#endif // SCREEN1VIEW_HPP