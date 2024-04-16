#ifndef DELAYPARAMS_HPP
#define DELAYPARAMS_HPP

#include <gui_generated/containers/DelayParamsBase.hpp>
#include <Color.hpp>


class DelayParams : public DelayParamsBase
{
public:
    DelayParams();
    virtual ~DelayParams() {}
    virtual void initialize();

    void setBox();
    void clearBox();
    void setBuffer(int param, float val);
protected:
};

#endif // DELAYPARAMS_HPP
