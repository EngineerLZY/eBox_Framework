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

#define EBOX_COLOR  uint16_t  

uint16_t bgr2rgb(uint16_t c);
uint16_t rgb24_2_rgb565(uint32_t color);   //Ӧ�û���ʧ��������

typedef struct {
		uint16_t x;						// ����x
		uint16_t y;						// ����y
    uint16_t width;    		// ��Ļ���
    uint16_t height;    	// ��Ļ�߶�
		DrawMode_t mode;			// ��ʾģʽ
    EBOX_COLOR fColor;
    EBOX_COLOR bColor;
}display_t;



class GAPI
{
public: 
		// ��㣨x,y��������ʵ�ָýӿ�
    virtual void    draw_pixel(int16_t x, int16_t y, uint32_t color)=0;
		// ˮƽ�ߣ�x,y,len��������ײ�ʵ�ָýӿڣ��Ż�Ч��
    virtual void    draw_h_line(int16_t x, int16_t y, int16_t len, uint32_t color);
		// ��ֱ�ߣ�x,y,len��������ײ�ʵ�ָýӿڣ��Ż�Ч��
    virtual void    draw_v_line(int16_t x, int16_t y, int16_t len, uint32_t color);
		// �����Σ�x,y,width,high������ײ�ʵ�ָýӿڣ��Ż�Ч��
    virtual void    fill_rect(int16_t x, int16_t y, int16_t width, int16_t height, uint32_t color);
		// ǿ�����������Ӳ�����Ծ����Ƿ�ʵ��
		virtual void    flush();
		
		
    void    draw_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint32_t color);
    void    draw_circle(int16_t x, int16_t y, int16_t r, uint32_t color);
    void    fill_screen(uint32_t color);

		void 		drawBitmap(int16_t x, int16_t y,const uint8_t *bitmap, int16_t w, int16_t h, uint32_t color);
		void 		drawBitmap(int16_t x, int16_t y,const uint8_t *bitmap, int16_t w, int16_t h, uint32_t bcolor,uint32_t fcolor);
protected :
    uint16_t	_width;
		uint16_t  _height;
};
#endif
