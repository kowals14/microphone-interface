#include <gui/screen1_screen/Screen1View.hpp>
#include <Color.hpp>

Screen1View::Screen1View()
{
}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::updateParameters(AUDIOFX_Type curFx, float* params) {
    switch (curFx)
    {
    case AUDIOFX_PKNG0:
    	peaking_filter_0.setBuffer(0, params[0]);
    	peaking_filter_0.setBuffer(1, params[1]);
    	peaking_filter_0.setBuffer(2, params[2]);
        break;
    case AUDIOFX_PKNG1:
        peaking_filter_1.setBuffer(0, params[0]);
        peaking_filter_1.setBuffer(1, params[1]);
        peaking_filter_1.setBuffer(2, params[2]);
        break;
    case AUDIOFX_PKNG2:
        peaking_filter_2.setBuffer(0, params[0]);
        peaking_filter_2.setBuffer(1, params[1]);
        peaking_filter_2.setBuffer(2, params[2]);
        break;
    case AUDIOFX_PKNG3:
        peaking_filter_3.setBuffer(0, params[0]);
        peaking_filter_3.setBuffer(1, params[1]);
        peaking_filter_3.setBuffer(2, params[2]);
        break;
    case AUDIOFX_PKNG4:
    	peaking_filter_4.setBuffer(0, params[0]);
    	peaking_filter_4.setBuffer(1, params[1]);
    	peaking_filter_4.setBuffer(2, params[2]);
        break;
    default:
        break;
    }
}

void Screen1View::changeFX(AUDIOFX_Type newFx, AUDIOFX_Type oldFx) {
    switch (oldFx)
    {
    case AUDIOFX_PKNG0:
    	PKNG0_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    case AUDIOFX_PKNG1:
        PKNG1_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    case AUDIOFX_PKNG2:
        PKNG2_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    case AUDIOFX_PKNG3:
        PKNG3_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    case AUDIOFX_PKNG4:
    	PKNG4_Box.setBorderColor(Color::getColorFromRGB(31,25,25));
        break;
    default:
        break;
    }

    switch (newFx)
    {
    case AUDIOFX_PKNG0:
    	PKNG0_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    case AUDIOFX_PKNG1:
        PKNG1_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    case AUDIOFX_PKNG2:
        PKNG2_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    case AUDIOFX_PKNG3:
        PKNG3_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    case AUDIOFX_PKNG4:
    	PKNG4_Box.setBorderColor(Color::getColorFromRGB(54,143,93));
        break;
    default:
        break;
    }
}
