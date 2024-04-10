#ifndef FILTERPARAMS_HPP
#define FILTERPARAMS_HPP

#include <gui_generated/containers/FilterParamsBase.hpp>

class FilterParams : public FilterParamsBase
{
public:
    FilterParams();
    virtual ~FilterParams() {}

    virtual void initialize();

    void setBuffer(int, float);
protected:
};

#endif // FILTERPARAMS_HPP
