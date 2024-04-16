#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern uint8_t change_fx_flag;
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

AUDIOFX_Type Model::getCurr() {
    return curr_fx;
}

void Model::setCurr(AUDIOFX_Type fx) {
    curr_fx = fx;
    change_fx_flag = 1;
}
