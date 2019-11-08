/*
*********************************************************************************************************
*                                                uC/GUI
*                        Universal graphic software for embedded applications
*
*                       (c) Copyright 2002, Micrium Inc., Weston, FL
*                       (c) Copyright 2002, SEGGER Microcontroller Systeme GmbH
*
*              �C/GUI is protected by international copyright laws. Knowledge of the
*              source code may not be used to write a similar product. This file may
*              only be used in accordance with a license and should not be redistributed
*              in any way. We appreciate your understanding and fairness.
*
----------------------------------------------------------------------
File        : GUI.h
Purpose     : GUI API include file
---------------------------END-OF-HEADER------------------------------

Attention : Do not modify this file ! If you do, you will not
            be able do update to a later GUI version !

*/
#ifndef  _FONT_H
#define  _FONT_H

#if defined(__cplusplus)
extern "C" {     /* Make sure we have C-declarations in C++ programs */
#endif

#include "fontType.h"
/*********************************************************************
*
*            Standard Fonts
*
**********************************************************************

Note: The external declarations for the fonts are now also included in
      this file.
*/

/* Proportional fonts */
extern const GUI_FONT GUI_FontGUI_Font8_1;
extern const GUI_FONT GUI_Font8_ASCII,        GUI_Font8_1;
extern const GUI_FONT GUI_FontGUI_Fontnewsong;


typedef enum{
		DispMode_Normal = 0,									// 0,�����������κ��Ѿ���ʾ�Ķ���
		DispMode_XOR,													// 1,���
		DispMode_Trans,												// 2,͸��, ������ʾ������������
		DispMode_Rev = 1<<2										// 4,��ת��
}DispMode_e;

typedef enum{
		AlignFlag_Horizontal	= 3,			// ˮƽ�����־ 0011
		AlignMode_Left = 0,							// �����				0000
		AlignMode_Right,								// �Ҷ���				0001
		AlignMode_Center,								// ˮƽ����			0010
		AlignFlag_Vertical		= 3<<2,		// ��ֱ�����־ 1100
		AlignMode_Top  		= 0,					// ��������			0000
		AlignMode_Bottom 	= 1<<2,				// �ײ�����			0100
		AlignMode_Vcenter = 2<<2				// ��ֱ����     1000
}AlignMode_e;

#if defined(__cplusplus)
}     /* Make sure we have C-declarations in C++ programs */
#endif

#endif   /* ifdef GUI_H */

/*************************** End of file ****************************/
