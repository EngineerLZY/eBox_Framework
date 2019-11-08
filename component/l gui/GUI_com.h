/**
  ******************************************************************************
  * @file    gui_com.h
  * @author  cat_li
  * @brief   gui������������в������ɸ������չ
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

#ifndef __GUI_COMPONENT_H
#define __GUI_COMPONENT_H

#include "lgui_font.h"
#include "G_LCD_interface.h"
#include "TEXT_interface.h"
#include "list.h"

typedef enum{
	obj_State_Free 		= 0,
	obj_State_Valid		=	0x01,								// ��Ч
	obj_State_Busy		=	0x02,
	obj_State_Visible = 0x04,								// �ɼ�
	obj_State_Enable	= 0x08,
	obj_State_Update	= 0x10,								// ����
	obj_State_ReDraw	= 0x20,								// �ػ�
	obj_State_Init		= (obj_State_Free|obj_State_Valid)
}State_e;

typedef struct{
	int16_t xs;
	int16_t ys;
	int16_t xe;
	int16_t ye;
}AREA_S;

/* Window styles */
#define STYLE_2D                                  (0<<0)
#define STYLE_3D                                  (1<<0)


class GUI_COM 
{
 public:
 	virtual void 	update(void) = 0;
	virtual void 	selectWindow(GUI_COM *wnd)= 0;
	void 	show();
	void 	hide();
	// �����������
	void		setWidth(uint16_t	w)	{ _para.w = w; }
	void		setHeight(uint16_t	h){ _para.h = h; }
	void		setPost(uint16_t	x,uint16_t y);
	void    setForeColor(E_COLOR c);
	void    setBackColor(E_COLOR c);
	// ��ȡ�������
	void		getAvailiableArea(AREA_S *a);			//��ȡ��������
	E_COLOR getBackColor(){return _para.bc;};
	E_COLOR getForeColor(){return _para.fc;};
 
 	uint16_t		_state;    // ���״̬
	uint8_t			_style;		 // �����ʽ
protected:
  WINDOW_S    _para;     // �������
  void _paraInit(uint16_t w,uint16_t h);
};


class TXT_COM:public GUI_COM
{
public:
  virtual void 	update(void) = 0;
  virtual void 	selectWindow(GUI_COM *wnd)= 0;

  void setTxt(char * s);
  void setAlignMode(uint8_t align);
	void selectFont(const GUI_FONT *f){_pAFont = f;};
protected:
  const GUI_FONT *_pAFont;
  int16_t         _DX,_DY;
  uint8_t         _align;		// ����ģʽ
  char 		        *_str;
};

#endif
