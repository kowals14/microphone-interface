#include <gui/containers/DelayParams.hpp>
#include "string.h"

DelayParams::DelayParams()
{

}

void DelayParams::initialize()
{
    DelayParamsBase::initialize();
}

void DelayParams::setBox() {       
    this->param_box.setBorderColor(Color::getColorFromRGB(54,143,93));
    this->invalidate();
}

void DelayParams::clearBox() {
    this->param_box.setBorderColor(Color::getColorFromRGB(23,20,20));
    this->invalidate();
}

void DelayParams::setBuffer(int param, float val) {
    switch (param)
    {
    case 0:
        memset(&MixBuffer, (val*100), sizeof(MixBuffer));
        Unicode::snprintfFloat(MixBuffer, sizeof(MixBuffer), "%.1f", (val*100));
        break;
    case 1:
        memset(&FeedbackBuffer, val, sizeof(FeedbackBuffer));
        Unicode::snprintfFloat(FeedbackBuffer, sizeof(FeedbackBuffer), "%.1f", val);
        break;
    case 2:
        memset(&TimeBuffer, val, sizeof(TimeBuffer));
        Unicode::snprintfFloat(TimeBuffer, sizeof(TimeBuffer), "%.1f", val);
        break;
    default:
        break;
    }
    this->invalidate();
}
