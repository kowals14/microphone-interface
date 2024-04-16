#include <gui/eq_screen/EQView.hpp>
#include <gui/eq_screen/EQPresenter.hpp>

EQPresenter::EQPresenter(EQView& v)
    : view(v)
{

}

void EQPresenter::activate()
{
    curr_fx = model->getCurr();

    view.setBox(curr_fx);

    view.updateParameters(AUDIOFX_PKNG0);
    view.updateParameters(AUDIOFX_PKNG1);
    view.updateParameters(AUDIOFX_PKNG2);
    view.updateParameters(AUDIOFX_PKNG3);
    view.updateParameters(AUDIOFX_PKNG4);
}

void EQPresenter::deactivate()
{

}

void EQPresenter::update_fx(AUDIOFX_Type fx) {
    if(fx != curr_fx) {
        view.clearBox(curr_fx);
        curr_fx = fx;
        view.setBox(curr_fx);
    }

    view.updateParameters(curr_fx);
}

 void EQPresenter::update_curr(AUDIOFX_Type fx) {
    model->setCurr(fx);
 }