#include <gui/containers/FilterParams.hpp>
#include "string.h"

FilterParams::FilterParams()
{

}

void FilterParams::initialize()
{
    FilterParamsBase::initialize();
}

void FilterParams::setBuffer(int param, float val) {
    switch (param)
    {
    case 0:
        memset(&f0Buffer, val, sizeof(f0Buffer));
        Unicode::snprintfFloat(f0Buffer, sizeof(f0Buffer), "%.1f", val);
        break;
    case 1:
        memset(&dbGainBuffer, val, sizeof(dbGainBuffer));
        Unicode::snprintfFloat(dbGainBuffer, sizeof(dbGainBuffer), "%.1f", val);
        break;
    case 2:
        memset(&QBuffer, val, sizeof(QBuffer));
        Unicode::snprintfFloat(QBuffer, sizeof(QBuffer), "%.1f", val);
        break;
    default:
        break;
    }

    this->invalidate();
}