/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/DistoritonLowpassBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DistoritonLowpassBase::DistoritonLowpassBase()
{
    setWidth(143);
    setHeight(55);
    param_box.setPosition(0, 0, 143, 55);
    param_box.setColor(touchgfx::Color::getColorFromRGB(31, 30, 30));
    param_box.setBorderColor(touchgfx::Color::getColorFromRGB(23, 20, 20));
    param_box.setBorderSize(5);
    add(param_box);

    f0.setPosition(13, 10, 76, 15);
    f0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    f0.setLinespacing(0);
    Unicode::snprintf(f0Buffer, F0_SIZE, "%s", touchgfx::TypedText(T_RESOURCEID1).getText());
    f0.setWildcard(f0Buffer);
    f0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_W6WV));
    add(f0);

    G.setPosition(13, 25, 76, 19);
    G.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    G.setLinespacing(0);
    Unicode::snprintf(GBuffer, G_SIZE, "%s", touchgfx::TypedText(T_RESOURCEID1).getText());
    G.setWildcard(GBuffer);
    G.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LBJU));
    add(G);

    param_button.setBoxWithBorderPosition(0, 0, 143, 55);
    param_button.setBorderSize(5);
    param_button.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    param_button.setAlpha(0);
    param_button.setPosition(0, 0, 143, 55);
    add(param_button);
}

DistoritonLowpassBase::~DistoritonLowpassBase()
{

}

void DistoritonLowpassBase::initialize()
{

}
