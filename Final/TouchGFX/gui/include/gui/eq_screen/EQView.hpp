#ifndef EQVIEW_HPP
#define EQVIEW_HPP

#include <gui_generated/eq_screen/EQViewBase.hpp>
#include <gui/eq_screen/EQPresenter.hpp>

class EQView : public EQViewBase
{
public:
    EQView();
    virtual ~EQView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void clearBox(AUDIOFX_Type FX);
    void setBox(AUDIOFX_Type FX);
    void updateParameters(AUDIOFX_Type FX);
    void UpdateCurFX(uint8_t fx);
protected:
};

#endif // EQVIEW_HPP
