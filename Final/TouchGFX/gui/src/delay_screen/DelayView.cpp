#include <gui/delay_screen/DelayView.hpp>
#include <filters.h>
#include <delay.h>
#include <distort.h>
#include "string.h"

extern DELAY_Params dl_p;
extern DISTORT_Params ds_p;

DelayView::DelayView()
{

}

void DelayView::setupScreen()
{
    DelayViewBase::setupScreen();
}

void DelayView::tearDownScreen()
{
    DelayViewBase::tearDownScreen();
}


void DelayView::clearBox(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_DELAY:
        delayParams1.clearBox();
        break;
    case AUDIOFX_DISTORTION:
        distortParams.clearBox();
        break;
    default:
        break;
    }
}

void DelayView::setBox(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_DELAY:
        delayParams1.setBox();
        break;
    case AUDIOFX_DISTORTION:
        distortParams.setBox();
        break;
    default:
        static_cast<FrontendApplication*>(Application::getInstance())->gotoEQScreenSlideTransitionWest();
        break;
    }
}

void DelayView::updateParameters(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_DELAY:
        delayParams1.setBuffer(0, dl_p.mix);
        delayParams1.setBuffer(1, dl_p.feedback);
        delayParams1.setBuffer(2, dl_p.time_ms);
        break;
    case AUDIOFX_DISTORTION:
        distortParams.setBuffer(0, ds_p.pre_amp);
        distortParams.setBuffer(1, ds_p.mix);
        distortParams.setBuffer(2, ds_p.gain);
        break;
    default:
        break;
    }
}

void DelayView::UpdateCurFX(uint8_t fx) {
    presenter->update_curr(fx);
}