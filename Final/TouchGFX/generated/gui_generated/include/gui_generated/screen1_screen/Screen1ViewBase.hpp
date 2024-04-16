/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SCREEN1VIEWBASE_HPP
#define SCREEN1VIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/BoxWithBorder.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>
#include <gui/containers/FilterParams.hpp>
#include <touchgfx/containers/buttons/Buttons.hpp>

class Screen1ViewBase : public touchgfx::View<Screen1Presenter>
{
public:
    Screen1ViewBase();
    virtual ~Screen1ViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::BoxWithBorder PKNG0_Box;
    touchgfx::BoxWithBorder Title_Box;
    touchgfx::BoxWithBorder PKNG4_Box;
    touchgfx::BoxWithBorder PKNG1_Box;
    touchgfx::BoxWithBorder PKNG2_Box;
    touchgfx::BoxWithBorder PKNG3_Box;
    touchgfx::TextArea Subtitle2_3;
    touchgfx::TextArea Subtitle2_3_1_1;
    touchgfx::TextArea Subtitle2_3_1_1_1;
    touchgfx::TextArea Subtitle2_3_1_1_1_1;
    touchgfx::TextArea Subtitle2;
    touchgfx::TextArea Subtitle2_2;
    touchgfx::TextAreaWithOneWildcard currentEffect;
    FilterParams peaking_filter_1;
    FilterParams peaking_filter_0;
    FilterParams peaking_filter_2;
    FilterParams peaking_filter_3;
    FilterParams peaking_filter_4;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  bandButton_1;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  bandButton_2;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  bandButton_3;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  bandButton_4;
    touchgfx::BoxWithBorderButtonStyle< touchgfx::ClickButtonTrigger >  bandButton_5;

    /*
     * Wildcard Buffers
     */
    static const uint16_t CURRENTEFFECT_SIZE = 32;
    touchgfx::Unicode::UnicodeChar currentEffectBuffer[CURRENTEFFECT_SIZE];

private:

};

#endif // SCREEN1VIEWBASE_HPP
