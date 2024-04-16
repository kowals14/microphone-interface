#include <gui/containers/DistortParams.hpp>
#include "string.h"

DistortParams::DistortParams()
{

}

void DistortParams::initialize()
{
    DistortParamsBase::initialize();
}

void DistortParams::setBox() {       
    this->param_box.setBorderColor(Color::getColorFromRGB(54,143,93));
    this->invalidate();
}

void DistortParams::clearBox() {
    this->param_box.setBorderColor(Color::getColorFromRGB(23,20,20));
    this->invalidate();
}

void DistortParams::setBuffer(int param, float val) {
    switch (param)
    {
    case 0:
        memset(&PreAmpBuffer, val, sizeof(PreAmpBuffer));
        Unicode::snprintfFloat(PreAmpBuffer, sizeof(PreAmpBuffer), "%.1f", val);
        break;
    case 1:
        memset(&MixBuffer, (val*100), sizeof(MixBuffer));
        Unicode::snprintfFloat(MixBuffer, sizeof(MixBuffer), "%.1f", (val*100));
        break;
    case 2:
        memset(&GainBuffer, val, sizeof(GainBuffer));
        Unicode::snprintfFloat(GainBuffer, sizeof(GainBuffer), "%.1f", val);
        break;
    default:
        break;
    }
    this->invalidate();
}
