#ifndef DELAYVIEW_HPP
#define DELAYVIEW_HPP

#include <gui_generated/delay_screen/DelayViewBase.hpp>
#include <gui/delay_screen/DelayPresenter.hpp>

class DelayView : public DelayViewBase
{
public:
    DelayView();
    virtual ~DelayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void clearBox(AUDIOFX_Type FX);
    void setBox(AUDIOFX_Type FX);
    void updateParameters(AUDIOFX_Type FX);
    void UpdateCurFX(uint8_t);
protected:
};

#endif // DELAYVIEW_HPP
