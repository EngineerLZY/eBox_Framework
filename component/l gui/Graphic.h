/**
  ******************************************************************************
  * @file    Graphic.h
  * @author  cat_li
  * @brief   ����ͼ��
	*		2019.7.10		���ͼ��Ex�ӿڣ�Ex ͨ����ʼ����ͽ�������ȷ��λ�úʹ�С
	*								����Exͨ������ȷ��λ�ã�����ȷ����С								
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

#ifndef __GRAPHIC_H
#define __GRAPHIC_H

#include "G_LCD_interface.h"
#include "TEXT_interface.h"
#include "lgui_font.h"
#include "gui_com.h"


class GUI : public TEXTAPI
{
public: 
	GUI(GAPI *pG);
	
	void begin();
	void clear(){fillScreen(_g.bc);}
	void setDispMode(DispMode_e mode);
	
  /*  ���ͼ��	*/ 
  void fillScreen( E_COLOR c );
  void fillFrame( uint16_t x, uint16_t y, uint16_t width, uint16_t height, E_COLOR c );		// ������-����(x,y),�ߴ�(width,height),��ɫ(c)
	void fillFrameEx( uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, E_COLOR c );  		// ������-����(xs,ys,xe,ye),��ɫ(c)
  void fillRoundFrame( uint16_t x, uint16_t y, uint16_t width, uint16_t height,uint16_t r, E_COLOR c );	// ���Բ�Ǿ���-����(x,y),�ߴ�(width,height),Բ���뾶(r),��ɫ(c)	
	void fillRoundFrameEx( uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, uint16_t r, E_COLOR c );   // ���Բ�Ǿ���-����(xs,ys,xe,ye),��ɫ(c)
  void fillCircle( uint16_t x, uint16_t y, uint16_t r, E_COLOR c );			// ���Բ��-����(x,y),�뾶(r),��ɫ(c)
  
  /* 	��ͼ 	*/  
  void drawMesh(uint16_t x, uint16_t y, uint16_t width, uint16_t height,uint16_t gap, E_COLOR c );	// ������-����(x,y),�ߴ�(width,height),���(gap)��ɫ(c)
	void drawMeshEx(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye,uint16_t gap, E_COLOR c );			// ������-����(xs,ys,xe,ye),���(gap)��ɫ(c)
  void drawFrame(uint16_t x, uint16_t y, uint16_t width, uint16_t height, E_COLOR c );		// ������-����(x,y),�ߴ�(width,height),��ɫ(c)
  void drawFrameEx(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, E_COLOR c );  			// ������-����(xs,ys,xe,ye),��ɫ(c)
  void drawRoundFrame( uint16_t x, uint16_t y, uint16_t width, uint16_t height, uint16_t r, E_COLOR c );			// ��Բ�Ǿ���-����(x,y),�ߴ�(width,height),Բ���뾶(r),��ɫ(c)	
	void drawRoundFrameEx(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, uint16_t r, E_COLOR c );		// ��Բ�Ǿ���-����(xs,ys,xe,ye),Բ���뾶(r),��ɫ(c)  
  void drawPixel( uint16_t x0, uint16_t y0, E_COLOR c );														// ���-����(x,y),��ɫ(c)  
  void drawCircle( uint16_t x0, uint16_t y0, uint16_t r, E_COLOR c );								// ��Բ-����(x,y),�뾶(r),��ɫ(c)  
  void drawArc( uint16_t x0, uint16_t y0, uint16_t r, uint8_t s, E_COLOR c ); 			// ������ 
  void drawLine( uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, E_COLOR c );		// ����-���(xs,ys),�յ�(xe,ye)

	virtual void		drawBitmap(int16_t x, int16_t y,const uint8_t *bitmap, int16_t w, int16_t h, E_COLOR bcolor,E_COLOR fcolor);

	// ��ȡ����
	E_COLOR		getBColor(){return _g.bc;}
	E_COLOR  	getfColor(){return _g.fc;}
	int16_t		getWidth(){return  _g.w;}
	int16_t		getHeight(){return _g.h;}	
	
	
	void 	putText(TEXT_S *t,char *str,uint8_t align);
	void	ptxt(TEXT_SS *t);
	
	void 	loop();
	void 	setCurrentWND(GUI_COM *wnd){_wnd = wnd;}
private	:
	WINDOW_S 	_g;			// ��ʾ������Ϣ
	TEXT_S  	_t;			// ��ʾ�ı���Ϣ
	
	GUI_COM *_wnd;

	void _drawLine(uint16_t xs, uint16_t ys, uint16_t xe, uint16_t ye, E_COLOR c);		// ������Ƕ�ֱ��
	int16_t _getXend(int16_t xe){ return (xe>_g.w ? _g.w : xe);}											// ��ֹx���߽�
	int16_t _getYend(int16_t ye){ return (ye>_g.h ? _g.h : ye);}											// ��ֹy���߽�
	
	int16_t	_getYAdjust(uint8_t align,uint16_t h=1);
	int16_t	_getXAdjust(uint8_t align,uint16_t stringWidth);
};
#endif
