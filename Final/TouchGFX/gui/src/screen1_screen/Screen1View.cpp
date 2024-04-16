#include <gui/screen1_screen/Screen1View.hpp>
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

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();

    updateParameters(AUDIOFX_PKNG0);
    updateParameters(AUDIOFX_PKNG1);
    updateParameters(AUDIOFX_PKNG2);
    updateParameters(AUDIOFX_PKNG3);
    updateParameters(AUDIOFX_PKNG4);

}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}   

void Screen1View::clearBox(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_PKNG0:
        PKNG0_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    case AUDIOFX_PKNG1:
        PKNG1_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    case AUDIOFX_PKNG2:
        PKNG2_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    case AUDIOFX_PKNG3:
        PKNG3_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    case AUDIOFX_PKNG4:
        PKNG4_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    default:
        break;
    }
}

void Screen1View::setBox(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_PKNG0:
        PKNG0_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    case AUDIOFX_PKNG1:
        PKNG1_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    case AUDIOFX_PKNG2:
        PKNG2_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    case AUDIOFX_PKNG3:
        PKNG3_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    case AUDIOFX_PKNG4:
        PKNG4_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    default:
        break;
    }
}

void Screen1View::updateParameters(AUDIOFX_Type FX) {
    switch (FX)
    {
    case AUDIOFX_PKNG0:
        peaking_filter_0.setBuffer(0, f_p0.f0);
        peaking_filter_0.setBuffer(2, f_p0.G);
        peaking_filter_0.setBuffer(1, f_p0.BW);
        break;
    case AUDIOFX_PKNG1:
        peaking_filter_1.setBuffer(0, f_p1.f0);
        peaking_filter_1.setBuffer(2, f_p1.G);
        peaking_filter_1.setBuffer(1, f_p1.BW);
        break;
    case AUDIOFX_PKNG2:
        peaking_filter_2.setBuffer(0, f_p2.f0);
        peaking_filter_2.setBuffer(2, f_p2.G);
        peaking_filter_2.setBuffer(1, f_p2.BW);
        break;
    case AUDIOFX_PKNG3:
        peaking_filter_3.setBuffer(0, f_p3.f0);
        peaking_filter_3.setBuffer(2, f_p3.G);
        peaking_filter_3.setBuffer(1, f_p3.BW);
        break;
    case AUDIOFX_PKNG4:
        peaking_filter_4.setBuffer(0, f_p4.f0);
        peaking_filter_4.setBuffer(2, f_p4.G);
        peaking_filter_4.setBuffer(1, f_p4.BW);
        break;
    default:
        break;
    }
}

void Screen1View::showCurr(AUDIOFX_Type FX) {
    memset(&currentEffectBuffer, FX, sizeof(currentEffectBuffer));
    Unicode::snprintf(currentEffectBuffer, sizeof(currentEffectBuffer), "%d", FX);
}