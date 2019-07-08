/**
  ******************************************************************************
  * @file    TFT9325.h
  * @author  cat_li
  * @version V1.0
  * @date    2019/06/09
  * @brief	 ili9225 lcd ����,8080�ӿڣ����޸�֧��9325
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LCD_ILI9325_H
#define __LCD_ILI9325_H

#include "ebox_core.h"
#include "font.h"
#include "parallel_gpio.h"
#include "G_LCD_interface.h"


#define X_MAX_PIXEL	        176
#define Y_MAX_PIXEL	        220

#define ID					9225
#define degree			90

#define RED  	0xf800
#define GREEN	0x07e0
#define BLUE 	0x001f
#define WHITE	0xffff
#define BLACK	0x0000
#define YELLOW  0xFFE0
#define GRAY0   0xEF7D   	    //��ɫ0 3165 00110 001011 00101
#define GRAY1   0x8410      	//��ɫ1      00000 000000 00000
#define GRAY2   0x4208      	//��ɫ2  1111111111011111




class Lcd : public GAPI
{
public:
  Lcd(Gpio *cs,Gpio *rst, Gpio *rd, Gpio *rs, Gpio *wr, ParallelGpio *db,int16_t width,int16_t height):GAPI(width,height)
  {
    _cs = cs;
    _rst = rst;
    _rd = rd;
    _rs = rs;
    _wr = wr;
    _db = db;
  }
  void begin(void);
  void soft_reset(void);
  void clear(uint16_t Color);
  void on();
  void off();

  void set_xy(int16_t x, int16_t y);

  virtual void    draw_pixel(int16_t x, int16_t y, E_COLOR color);
	virtual void    draw_h_line(int16_t x, int16_t y, int16_t len, E_COLOR color);
  virtual void    draw_v_line(int16_t x, int16_t y, int16_t len, E_COLOR color);
  virtual void    fill_rect(int16_t x, int16_t y, int16_t width, int16_t height, E_COLOR color);
  virtual void    fill_screen(E_COLOR color);

private:
  Gpio *_cs;		// Ƭѡ
  Gpio *_rst;		// ��λ
  Gpio *_rd;		// ��
  Gpio *_rs;		// �Ĵ���
  Gpio *_wr;		// д

  ParallelGpio *_db;	// ������

  void _init(void);
  void _setRegion(int16_t Xpos, int16_t Ypos,int16_t Width, int16_t Height);

  void _setCommandMode();
  void _setDataMode();
  void _setWrite();
  void _writeCommand(uint16_t cmd,uint16_t dat);
  void _setIndexReg(uint16_t reg);
  void _writeDate(uint16_t dat);
  uint16_t _readReg(uint16_t reg);
};
#endif
