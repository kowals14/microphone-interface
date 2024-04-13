#ifndef DELAYPARAMS_HPP
#define DELAYPARAMS_HPP

#include <gui_generated/containers/DelayParamsBase.hpp>

class DelayParams : public DelayParamsBase
{
public:
    DelayParams();
    virtual ~DelayParams() {}

    virtual void initialize();
protected:
};

#endif // DELAYPARAMS_HPP
