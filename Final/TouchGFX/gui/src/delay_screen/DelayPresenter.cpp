#include <gui/delay_screen/DelayView.hpp>
#include <gui/delay_screen/DelayPresenter.hpp>

DelayPresenter::DelayPresenter(DelayView& v)
    : view(v)
{

}

void DelayPresenter::activate()
{
    curr_fx = model->getCurr();

    view.setBox(curr_fx);

    view.updateParameters(AUDIOFX_DELAY);
    view.updateParameters(AUDIOFX_DISTORTION);
}

void DelayPresenter::deactivate()
{

}

void DelayPresenter::update_fx(AUDIOFX_Type fx) {
    if(fx != curr_fx) {
        view.clearBox(curr_fx);
        curr_fx = fx;
        view.setBox(curr_fx);
    }

    view.updateParameters(curr_fx);
}

void DelayPresenter::update_curr(AUDIOFX_Type fx) {
    model->setCurr(fx);
}