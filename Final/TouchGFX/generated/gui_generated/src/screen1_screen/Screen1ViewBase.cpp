/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen1ViewBase::Screen1ViewBase() :
    flexButtonCallback(this, &Screen1ViewBase::flexButtonCallbackHandler)
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    PKNG0_Box.setPosition(1, 120, 106, 120);
    PKNG0_Box.setColor(touchgfx::Color::getColorFromRGB(41, 34, 34));
    PKNG0_Box.setBorderColor(touchgfx::Color::getColorFromRGB(81, 209, 69));
    PKNG0_Box.setBorderSize(5);
    add(PKNG0_Box);

    Title_Box.setPosition(107, 120, 106, 120);
    Title_Box.setColor(touchgfx::Color::getColorFromRGB(41, 34, 34));
    Title_Box.setBorderColor(touchgfx::Color::getColorFromRGB(31, 25, 25));
    Title_Box.setBorderSize(5);
    add(Title_Box);

    PKNG4_Box.setPosition(213, 120, 106, 120);
    PKNG4_Box.setColor(touchgfx::Color::getColorFromRGB(41, 34, 34));
    PKNG4_Box.setBorderColor(touchgfx::Color::getColorFromRGB(31, 25, 25));
    PKNG4_Box.setBorderSize(5);
    add(PKNG4_Box);

    PKNG1_Box.setPosition(1, 0, 106, 120);
    PKNG1_Box.setColor(touchgfx::Color::getColorFromRGB(41, 34, 34));
    PKNG1_Box.setBorderColor(touchgfx::Color::getColorFromRGB(31, 25, 25));
    PKNG1_Box.setBorderSize(5);
    add(PKNG1_Box);

    PKNG2_Box.setPosition(107, 0, 106, 120);
    PKNG2_Box.setColor(touchgfx::Color::getColorFromRGB(41, 34, 34));
    PKNG2_Box.setBorderColor(touchgfx::Color::getColorFromRGB(31, 25, 25));
    PKNG2_Box.setBorderSize(5);
    add(PKNG2_Box);

    PKNG3_Box.setPosition(213, 0, 106, 120);
    PKNG3_Box.setColor(touchgfx::Color::getColorFromRGB(41, 34, 34));
    PKNG3_Box.setBorderColor(touchgfx::Color::getColorFromRGB(31, 25, 25));
    PKNG3_Box.setBorderSize(5);
    add(PKNG3_Box);

    Subtitle2_3.setPosition(36, 6, 39, 15);
    Subtitle2_3.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Subtitle2_3.setLinespacing(0);
    Subtitle2_3.setTypedText(touchgfx::TypedText(T___SINGLEUSE_2VZQ));
    add(Subtitle2_3);

    Subtitle2_3_1_1.setPosition(248, 127, 39, 15);
    Subtitle2_3_1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Subtitle2_3_1_1.setLinespacing(0);
    Subtitle2_3_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UCK5));
    add(Subtitle2_3_1_1);

    Subtitle2_3_1_1_1.setPosition(248, 6, 39, 15);
    Subtitle2_3_1_1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Subtitle2_3_1_1_1.setLinespacing(0);
    Subtitle2_3_1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AZKU));
    add(Subtitle2_3_1_1_1);

    Subtitle2_3_1_1_1_1.setPosition(141, 6, 39, 15);
    Subtitle2_3_1_1_1_1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Subtitle2_3_1_1_1_1.setLinespacing(0);
    Subtitle2_3_1_1_1_1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S08W));
    add(Subtitle2_3_1_1_1_1);

    Subtitle2.setPosition(36, 127, 39, 15);
    Subtitle2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Subtitle2.setLinespacing(0);
    Subtitle2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_G3P0));
    add(Subtitle2);

    Subtitle2_2.setPosition(122, 173, 76, 15);
    Subtitle2_2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    Subtitle2_2.setLinespacing(0);
    Subtitle2_2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_OG3J));
    add(Subtitle2_2);

    peaking_filter_1.setXY(7, 38);
    add(peaking_filter_1);

    peaking_filter_0.setXY(7, 158);
    add(peaking_filter_0);

    peaking_filter_2.setXY(113, 38);
    add(peaking_filter_2);

    peaking_filter_3.setXY(219, 38);
    add(peaking_filter_3);

    peaking_filter_4.setXY(219, 158);
    add(peaking_filter_4);

    bandButton_1.setBoxWithBorderPosition(0, 0, 90, 106);
    bandButton_1.setBorderSize(5);
    bandButton_1.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    bandButton_1.setAlpha(0);
    bandButton_1.setAction(flexButtonCallback);
    bandButton_1.setPosition(7, 127, 90, 106);
    add(bandButton_1);

    bandButton_2.setBoxWithBorderPosition(0, 0, 90, 106);
    bandButton_2.setBorderSize(5);
    bandButton_2.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    bandButton_2.setAlpha(0);
    bandButton_2.setAction(flexButtonCallback);
    bandButton_2.setPosition(7, 7, 90, 106);
    add(bandButton_2);

    bandButton_3.setBoxWithBorderPosition(0, 0, 90, 106);
    bandButton_3.setBorderSize(5);
    bandButton_3.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    bandButton_3.setAlpha(0);
    bandButton_3.setAction(flexButtonCallback);
    bandButton_3.setPosition(115, 7, 90, 106);
    add(bandButton_3);

    bandButton_4.setBoxWithBorderPosition(0, 0, 90, 106);
    bandButton_4.setBorderSize(5);
    bandButton_4.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    bandButton_4.setAlpha(0);
    bandButton_4.setAction(flexButtonCallback);
    bandButton_4.setPosition(222, 7, 90, 106);
    add(bandButton_4);

    bandButton_5.setBoxWithBorderPosition(0, 0, 90, 106);
    bandButton_5.setBorderSize(5);
    bandButton_5.setBoxWithBorderColors(touchgfx::Color::getColorFromRGB(0, 102, 153), touchgfx::Color::getColorFromRGB(0, 153, 204), touchgfx::Color::getColorFromRGB(0, 51, 102), touchgfx::Color::getColorFromRGB(51, 102, 153));
    bandButton_5.setAlpha(0);
    bandButton_5.setAction(flexButtonCallback);
    bandButton_5.setPosition(221, 127, 90, 106);
    add(bandButton_5);
}

Screen1ViewBase::~Screen1ViewBase()
{

}

void Screen1ViewBase::setupScreen()
{
    peaking_filter_1.initialize();
    peaking_filter_0.initialize();
    peaking_filter_2.initialize();
    peaking_filter_3.initialize();
    peaking_filter_4.initialize();
}

void Screen1ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &bandButton_1)
    {
        //Band1Click
        //When bandButton_1 clicked change border color of PKNG0_Box
        //Set RGB border color R:81, G:209, B:69 on PKNG0_Box
        PKNG0_Box.setBorderColor(touchgfx::Color::getColorFromRGB(81, 209, 69));
        PKNG0_Box.invalidate();
    
        //ClearBox1
        //When Band1Click completed call virtual function
        //Call clearCurrentBox
        clearCurrentBox();
    }
    if (&src == &bandButton_2)
    {
        //Band2Click
        //When bandButton_2 clicked change border color of PKNG1_Box
        //Set RGB border color R:81, G:209, B:69 on PKNG1_Box
        PKNG1_Box.setBorderColor(touchgfx::Color::getColorFromRGB(81, 209, 69));
        PKNG1_Box.invalidate();
    
        //ClearBox2
        //When Band2Click completed call virtual function
        //Call clearCurrentBox
        clearCurrentBox();
    }
    if (&src == &bandButton_3)
    {
        //Band3Click
        //When bandButton_3 clicked change border color of PKNG2_Box
        //Set RGB border color R:81, G:209, B:69 on PKNG2_Box
        PKNG2_Box.setBorderColor(touchgfx::Color::getColorFromRGB(81, 209, 69));
        PKNG2_Box.invalidate();
    
        //ClearBox3
        //When Band3Click completed call virtual function
        //Call clearCurrentBox
        clearCurrentBox();
    }
    if (&src == &bandButton_4)
    {
        //Band4Click
        //When bandButton_4 clicked change border color of PKNG3_Box
        //Set RGB border color R:81, G:209, B:69 on PKNG3_Box
        PKNG3_Box.setBorderColor(touchgfx::Color::getColorFromRGB(81, 209, 69));
        PKNG3_Box.invalidate();
    
        //ClearBox4
        //When Band4Click completed call virtual function
        //Call clearCurrentBox
        clearCurrentBox();
    }
    if (&src == &bandButton_5)
    {
        //Band5Click
        //When bandButton_5 clicked change border color of PKNG4_Box
        //Set RGB border color R:81, G:209, B:69 on PKNG4_Box
        PKNG4_Box.setBorderColor(touchgfx::Color::getColorFromRGB(81, 209, 69));
        PKNG4_Box.invalidate();
    
        //ClearBox5
        //When Band5Click completed call virtual function
        //Call clearCurrentBox
        clearCurrentBox();
    }
}
