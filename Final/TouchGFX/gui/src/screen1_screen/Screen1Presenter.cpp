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

void Screen1Presenter::updateParameters(AUDIOFX_Chain_HandleTypeDef* hfxchn) {
    AUDIOFX_UserParams* hfx = hfxchn->curr_fx;
    view.updateParameters(hfx->type, hfx->params);
}

void Screen1Presenter::changeFX(AUDIOFX_Chain_HandleTypeDef* hfxchn) {
    AUDIOFX_UserParams* hfx = hfxchn->curr_fx;
    AUDIOFX_Type curFX = hfx->type - 1;

    if(curFX == -1) {
        curFX = AUDIOFX_MAX_CHAIN - 1;
    }
    else if (curFX == AUDIOFX_MAX_CHAIN) {
        curFX = 0;
    }

    AUDIOFX_Type newFX = hfx->type;

    view.changeFX(newFX, curFX);
}