#ifndef DISTORTIONPARAMS_HPP
#define DISTORTIONPARAMS_HPP

#include <gui_generated/containers/DistortionParamsBase.hpp>

class DistortionParams : public DistortionParamsBase
{
public:
    DistortionParams();
    virtual ~DistortionParams() {}

    virtual void initialize();
protected:
};

#endif // DISTORTIONPARAMS_HPP
