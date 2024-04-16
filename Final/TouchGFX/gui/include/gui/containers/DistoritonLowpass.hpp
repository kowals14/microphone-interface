#ifndef DISTORITONLOWPASS_HPP
#define DISTORITONLOWPASS_HPP

#include <gui_generated/containers/DistoritonLowpassBase.hpp>

class DistoritonLowpass : public DistoritonLowpassBase
{
public:
    DistoritonLowpass();
    virtual ~DistoritonLowpass() {}

    virtual void initialize();
protected:
};

#endif // DISTORITONLOWPASS_HPP
