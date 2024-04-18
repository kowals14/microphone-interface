#include <gui/containers/FilterParams.hpp>
#include "string.h"

FilterParams::FilterParams()
{

}

void FilterParams::initialize()
{
    FilterParamsBase::initialize();
}

void FilterParams::switchFX() {
}

void FilterParams::setBox() {       
    this->param_box.setBorderColor(Color::getColorFromRGB(54,143,93));
    this->invalidate();
}

void FilterParams::clearBox() {
    this->param_box.setBorderColor(Color::getColorFromRGB(23,20,20));
    this->invalidate();
}

void FilterParams::setBuffer(int param, float val) {
    switch (param)
    {
    case 0:
        memset(&f0Buffer, (val*1.0), sizeof(f0Buffer));
        Unicode::snprintfFloat(f0Buffer, sizeof(f0Buffer), "%.1f", (val*1.0));
        break;
    case 1:
        memset(&GBuffer, val, sizeof(GBuffer));
        Unicode::snprintfFloat(GBuffer, sizeof(GBuffer), "%.1f", val);
        break;
    case 2:
        memset(&BWBuffer, val, sizeof(BWBuffer));
        Unicode::snprintfFloat(BWBuffer, sizeof(BWBuffer), "%.1f", val);
        break;
    default:
        break;
    }
    this->invalidate();
}
