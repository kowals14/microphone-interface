/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/TitleBoxDistortBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

TitleBoxDistortBase::TitleBoxDistortBase()
{
    setWidth(143);
    setHeight(55);
    param_box.setPosition(0, 0, 143, 55);
    param_box.setColor(touchgfx::Color::getColorFromRGB(31, 30, 30));
    param_box.setBorderColor(touchgfx::Color::getColorFromRGB(23, 20, 20));
    param_box.setBorderSize(5);
    add(param_box);

    Title.setPosition(4, 18, 135, 19);
    Title.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Title.setLinespacing(0);
    Title.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0HWM));
    add(Title);
}

TitleBoxDistortBase::~TitleBoxDistortBase()
{

}

void TitleBoxDistortBase::initialize()
{

}
