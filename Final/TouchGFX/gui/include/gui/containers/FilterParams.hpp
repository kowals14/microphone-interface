#ifndef FILTERPARAMS_HPP
#define FILTERPARAMS_HPP

#include <gui_generated/containers/FilterParamsBase.hpp>
#include <Color.hpp>

class FilterParams : public FilterParamsBase
{
public:
    FilterParams();
    virtual ~FilterParams() {}

    virtual void initialize();

    void switchFX();

    void setBuffer(int, float);
    void setBox();
    void clearBox();

protected:
};

#endif // FILTERPARAMS_HPP
