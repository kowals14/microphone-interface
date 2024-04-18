#include <gui/eq_screen/EQView.hpp>
#include <filters.h>
#include <delay.h>
#include <distort.h>
#include "string.h"

extern FILTERS_Params f_p0;
extern FILTERS_Params f_p1;
extern FILTERS_Params f_p2;
extern FILTERS_Params f_p3;
extern FILTERS_Params f_p4;

extern DELAY_Params dl_p;

extern DISTORT_Params ds_p;

EQView::EQView()
{

}

void EQView::setupScreen()
{
    EQViewBase::setupScreen();
}

void EQView::tearDownScreen()
{
    EQViewBase::tearDownScreen();
}

void EQView::clearBox(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_FILTER0:
        peaking_filter_0.clearBox();
        break;
    case AUDIOFX_FILTER1:
        peaking_filter_1.clearBox();
        break;
    case AUDIOFX_FILTER2:
        peaking_filter_2.clearBox();
        break;
    case AUDIOFX_FILTER3:
        peaking_filter_3.clearBox();
        break;
    case AUDIOFX_FILTER4:
        peaking_filter_4.clearBox();
        break;
    default:
        break;
    }
}

void EQView::setBox(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_FILTER0:
        peaking_filter_0.setBox();
        break;
    case AUDIOFX_FILTER1:
        peaking_filter_1.setBox();
        break;
    case AUDIOFX_FILTER2:
        peaking_filter_2.setBox();
        break;
    case AUDIOFX_FILTER3:
        peaking_filter_3.setBox();
        break;
    case AUDIOFX_FILTER4:
        peaking_filter_4.setBox();
        break;
    default:
        static_cast<FrontendApplication*>(Application::getInstance())->gotoDelayScreenSlideTransitionEast();
        break;
    }
}

void EQView::updateParameters(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_FILTER0:
        peaking_filter_0.setBuffer(0, f_p0.f0);
        peaking_filter_0.setBuffer(1, f_p0.G);
        peaking_filter_0.setBuffer(2, f_p0.BW);
        break;
    case AUDIOFX_FILTER1:
        peaking_filter_1.setBuffer(0, f_p1.f0);
        peaking_filter_1.setBuffer(1, f_p1.G);
        peaking_filter_1.setBuffer(2, f_p1.BW);
        break;
    case AUDIOFX_FILTER2:
        peaking_filter_2.setBuffer(0, f_p2.f0);
        peaking_filter_2.setBuffer(1, f_p2.G);
        peaking_filter_2.setBuffer(2, f_p2.BW);
        break;
    case AUDIOFX_FILTER3:
        peaking_filter_3.setBuffer(0, f_p3.f0);
        peaking_filter_3.setBuffer(1, f_p3.G);
        peaking_filter_3.setBuffer(2, f_p3.BW);
        break;
    case AUDIOFX_FILTER4:
        peaking_filter_4.setBuffer(0, f_p4.f0);
        peaking_filter_4.setBuffer(1, f_p4.G);
        peaking_filter_4.setBuffer(2, f_p4.BW);
        break;
    default:
        break;
    }
}

void EQView::UpdateCurFX(uint8_t fx) {
    presenter->update_curr(fx);
}
