#ifndef MODEL_HPP
#define MODEL_HPP
#include <stdint.h>

#include <audioFX.h>

class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }
   
    void update_screen(AUDIOFX_Type);
    AUDIOFX_Type getCurr();
    void setCurr(AUDIOFX_Type);

    void tick();
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
