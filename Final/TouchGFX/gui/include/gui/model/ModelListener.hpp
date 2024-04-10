#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>
#include <../../../../AudioFX/audioFX.h>


class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }

    virtual void updateParameters(AUDIOFX_Chain_HandleTypeDef*) = 0;
    virtual void changeFX(AUDIOFX_Chain_HandleTypeDef*) = 0;
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
