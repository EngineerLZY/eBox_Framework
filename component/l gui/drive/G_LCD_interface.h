/**
  ******************************************************************************
  * @file    G_LCD_interface.h
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

#ifndef __G_LCD_INTERFACE_H
#define __G_LCD_INTERFACE_H

#include "ebox_type.h"
#include "enum.h"
#include "color_table.h"
#include "lgui_font.h"

typedef uint16_t    E_COLOR ; 

uint16_t bgr2rgb(uint16_t c);
uint16_t rgb24_2_rgb565(uint32_t color);   //Ӧ�û���ʧ��������

typedef struct {
		uint16_t x;						// ����x
		uint16_t y;						// ����y
    uint16_t width;    		// ��Ļ���
    uint16_t height;    	// ��Ļ�߶�
		DispMode_e mode;			// ��ʾģʽ
    E_COLOR fColor;
    E_COLOR bColor;
}display_t;



class GAPI
{
public:
		GAPI(int16_t width,int16_t height){_width = width;_height = height;}
		// ��㣨x,y��������ʵ�ָýӿ�
    virtual void    draw_pixel(int16_t x, int16_t y, E_COLOR color)=0;
		// ˮƽ�ߣ�x,y,len��������ײ�ʵ�ָýӿڣ��Ż�Ч��
    virtual void    draw_h_line(int16_t x, int16_t y, int16_t len, E_COLOR color);
		// ��ֱ�ߣ�x,y,len��������ײ�ʵ�ָýӿڣ��Ż�Ч��
    virtual void    draw_v_line(int16_t x, int16_t y, int16_t len, E_COLOR color);
		// �����Σ�x,y,width,high������ײ�ʵ�ָýӿڣ��Ż�Ч��
    virtual void    fill_rect(int16_t x, int16_t y, int16_t width, int16_t height, E_COLOR color);
		// ǿ�����������Ӳ�����Ծ����Ƿ�ʵ��
		virtual void    flush();
		
		
    void    draw_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, E_COLOR color);
    void    draw_circle(int16_t x, int16_t y, int16_t r, E_COLOR color);
    void    fill_screen(E_COLOR color);

//		void 		drawBitmap(int16_t x, int16_t y,const uint8_t *bitmap, int16_t w, int16_t h, E_COLOR color);
//		void 		drawBitmap(int16_t x, int16_t y,const uint8_t *bitmap, int16_t w, int16_t h, E_COLOR bcolor,E_COLOR fcolor);

		uint16_t		getWidth(){return _width;}
		uint16_t		getHeight(){return _height;}
protected :
    int16_t	_width;
		int16_t  _height;
};
#endif
