#ifndef DISTORTPARAMS_HPP
#define DISTORTPARAMS_HPP

#include <gui_generated/containers/DistortParamsBase.hpp>
#include <Color.hpp>

class DistortParams : public DistortParamsBase
{
public:
    DistortParams();
    virtual ~DistortParams() {}

    virtual void initialize();

    void setBox();
    void clearBox();
    void setBuffer(int param, float val);
protected:
};

#endif // DISTORTPARAMS_HPP
