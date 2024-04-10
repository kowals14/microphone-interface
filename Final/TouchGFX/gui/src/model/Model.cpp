#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern AUDIOFX_Chain_HandleTypeDef hfxchn1;

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    if(hfxchn1.fx_change_flag) {
        modelListener->changeFX(&hfxchn1);
        hfxchn1.fx_change_flag = 0;
    }
    modelListener->updateParameters(&hfxchn1);
}