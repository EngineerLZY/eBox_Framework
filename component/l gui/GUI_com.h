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

class GUI_COM 
{
 public:
 	virtual void 	update(void) = 0;
	virtual void 	selectWindow(GUI_COM *wnd)= 0;
  virtual void 	show();
  virtual void 	hide();
	
	void    setForeColor(E_COLOR c);
	void    setBackColor(E_COLOR c);
	E_COLOR getBackColor(){return _para.bc;};
	E_COLOR getForeColor(){return _para.fc;};
 
 	uint16_t		_state;    // ���״̬
protected:
  AREA_S      _para;     // �������
  void _paraInit(uint16_t w,uint16_t h);
};

class TXT_COM:public GUI_COM 
{
 public:
 	virtual void 	update(void) = 0;
	virtual void 	selectWindow(GUI_COM *wnd)= 0;
protected:
//  AREA_S      _para;     // �������
  TEXT_SS    	_lab;      // �ı�����
};

#endif
