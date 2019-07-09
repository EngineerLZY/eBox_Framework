/**
  ******************************************************************************
  * @file    G_LCD_interface.cpp
  * @author  cat_li
  * @brief   ͼ����ʾ���ӿ�
  ******************************************************************************
  * @attention
  *
  * No part of this software may be used for any commercial activities by any form
  * or means, without the prior written consent of shentq. This specification is
  * preliminary and is subject to change at any time without notice. shentq assumes
  * no responsibility for any errors contained herein.
  * <h2><center>&copy; Copyright 2015 shentq. All Rights Reserved.</center></h2>
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "G_LCD_interface.h"

void GAPI::draw_v_line(int16_t x, int16_t y, int16_t len, E_COLOR color)
{
    while(len--)
        draw_pixel(x, y++, color);
}
void GAPI::draw_h_line(int16_t x, int16_t y, int16_t len, E_COLOR color)
{
    while(len--)
        draw_pixel(x++, y, color);
}

void GAPI::fill_rect(int16_t x, int16_t y, int16_t width, int16_t height, E_COLOR color)
{
    for(uint16_t i=0; i <= width; i++)
    {
        for(uint16_t j = 0; j <= height; j++)
            draw_pixel(x+i, y+j, color);
    }
}

//void GAPI::draw_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, E_COLOR color)
//{
//    int dx,             // difference in x's
//        dy,             // difference in y's
//        dx2,            // dx,dy * 2
//        dy2,
//        x_inc,          // amount in pixel space to move during drawing
//        y_inc,          // amount in pixel space to move during drawing
//        error,          // the discriminant i.e. error i.e. decision variable
//        index;          // used for looping

//    //            set_xy(x0, y0);
//    dx = x1 - x0; //����x����
//    dy = y1 - y0; //����y����

//    if (dx >= 0)
//    {
//        x_inc = 1;
//    }
//    else
//    {
//        x_inc = -1;
//        dx    = -dx;
//    }

//    if (dy >= 0)
//    {
//        y_inc = 1;
//    }
//    else
//    {
//        y_inc = -1;
//        dy    = -dy;
//    }

//    dx2 = dx << 1;
//    dy2 = dy << 1;

//    if (dx > dy)//x�������y���룬��ôÿ��x����ֻ��һ���㣬ÿ��y���������ɸ���
//    {
//        //���ߵĵ�������x���룬��x���������
//        // initialize error term
//        error = dy2 - dx;

//        // draw the line
//        for (index = 0; index <= dx; index++) //Ҫ���ĵ������ᳬ��x����
//        {
//            //����
//            draw_pixel(x0, y0, color);

//            // test if error has overflowed
//            if (error >= 0) //�Ƿ���Ҫ����y����ֵ
//            {
//                error -= dx2;

//                // move to next line
//                y0 += y_inc; //����y����ֵ
//            } // end if error overflowed

//            // adjust the error term
//            error += dy2;

//            // move to the next pixel
//            x0 += x_inc; //x����ֵÿ�λ���󶼵���1
//        } // end for
//    } // end if |slope| <= 1
//    else//y�����x�ᣬ��ÿ��y����ֻ��һ���㣬x�����ɸ���
//    {
//        //��y��Ϊ��������
//        // initialize error term
//        error = dx2 - dy;

//        // draw the line
//        for (index = 0; index <= dy; index++)
//        {
//            // set the pixel
//            draw_pixel(x0, y0, color);

//            // test if error overflowed
//            if (error >= 0)
//            {
//                error -= dy2;

//                // move to next line
//                x0 += x_inc;
//            } // end if error overflowed

//            // adjust the error term
//            error += dx2;

//            // move to the next pixel
//            y0 += y_inc;
//        } // end for
//    } // end else |slope| > 1
//}



void GAPI::draw_circle(int16_t x, int16_t y, int16_t r, E_COLOR color)
{
    unsigned short  a, b;
    int c;
    a = 0;
    b = r;
    c = 3 - 2 * r;
    while (a < b)
    {
        draw_pixel(x + a, y + b, color); //        7
        draw_pixel(x - a, y + b, color); //        6
        draw_pixel(x + a, y - b, color); //        2
        draw_pixel(x - a, y - b, color); //        3
        draw_pixel(x + b, y + a, color); //        8
        draw_pixel(x - b, y + a, color); //        5
        draw_pixel(x + b, y - a, color); //        1
        draw_pixel(x - b, y - a, color); //        4

        if(c < 0) c = c + 4 * a + 6;
        else
        {
            c = c + 4 * (a - b) + 10;
            b -= 1;
        }
        a += 1;
    }
    if (a == b)
    {
        draw_pixel(x + a, y + b, color);
        draw_pixel(x + a, y + b, color);
        draw_pixel(x + a, y - b, color);
        draw_pixel(x - a, y - b, color);
        draw_pixel(x + b, y + a, color);
        draw_pixel(x - b, y + a, color);
        draw_pixel(x + b, y - a, color);
        draw_pixel(x - b, y - a, color);
    }
}

void GAPI::fill_screen(E_COLOR color)
{
	fill_rect(0,0,_width,_height,color);
}

void GAPI::flush()
{
}


