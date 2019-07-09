/**
  ******************************************************************************
  * @file    TEXT_Interface.h
  * @author  cat_li
  * @brief   �ı�����ӿ�,������ָ���豸����ı�
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

#ifndef __TEXT_INTERFACE_H
#define __TEXT_INTERFACE_H

#include "lgui_font.h"
#include "G_LCD_interface.h"

// ��ʾ�������
typedef struct
{
		int16_t x;				// ����
		int16_t y;
		int16_t w;				// �ߴ�
		int16_t h;
		E_COLOR fc;				// ��ɫ
    E_COLOR bc;
		DispMode_e mode;	// ��ʾģʽ
}AREA_S;

typedef struct
{
    AREA_S   disp;
    const 	 GUI_FONT 	*pAFont;
		int16_t  DispPosX, DispPosY;
}TEXT_S;

typedef struct
{
    AREA_S    disp;
	  char 		  *str;
		uint8_t   align;		// ����ģʽ
    const 	  GUI_FONT 	  *pAFont;
		int16_t   DispPosX,   DispPosY;
}TEXT_SS;

class TEXTAPI
{
public: 
		TEXTAPI(GAPI *pG,TEXT_S *pT);
	
    void putChar(const char c);
		void putCharS(const char *s , uint16_t num);
		void putString(uint16_t x,uint16_t y,const char *str);
		// ��������
		void selectFont(const GUI_FONT *f){_pT->pAFont = f;}
		void setTextBackColor(E_COLOR c){_pT->disp.bc = c;}
		void setTextForeColor(E_COLOR c){_pT->disp.fc = c;}
		void setTextMode(DispMode_e mode){_pT->disp.mode = mode;}
		
//		void putText(TEXT_S *t,char 		  *str);
protected :
    TEXT_S *_pT;			// ָ���ı�����
		GAPI   *_pDev;		// ָ������豸

		void _dispChar(char c);
		virtual void 		_drawBitmap(int16_t x, int16_t y,const uint8_t *bitmap, int16_t w, int16_t h, E_COLOR color);
		virtual void 		_drawBitmap(int16_t x, int16_t y,const uint8_t *bitmap, int16_t w, int16_t h, E_COLOR bcolor,E_COLOR fcolor);
private	:

		void _dispCharP(char c);
		void _dispNextLine();
};

#endif
