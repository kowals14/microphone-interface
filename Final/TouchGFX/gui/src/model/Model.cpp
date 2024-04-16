#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>


extern AUDIOFX_Type curr_fx;


Model::Model() : modelListener(0)
{

}

void Model::tick()
{
    update_screen(curr_fx);
}

void Model::update_screen(AUDIOFX_Type curr_fx) {
    modelListener->update_fx(curr_fx);
}