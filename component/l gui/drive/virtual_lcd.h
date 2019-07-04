#ifndef __virtual_lcd_h
#define __virtual_lcd_h

#include "ebox_core.h"
#include "print.h"
#include "G_LCD_interface.h"

// ���ô���ģ����Ļ

class VLcd : public GAPI
{
private:
    typedef struct
    {
        uint8_t 		*pixel;		//�Դ�����ָ��
        uint8_t     width; 		//��ʾ�����
        uint8_t     height;		//��ʾ���߶�
        uint32_t    mem_size;	//�Դ��С
    } Lcd_t;

public:
    VLcd(Print *p);
    ~VLcd();
    void    begin(uint16_t lcd_w, uint16_t lcd_h);
    void    set_xy(int16_t x, int16_t y);
    void    clear(uint32_t color);

    //����Vhmi�Ľӿ�
    virtual void    draw_pixel(int16_t x, int16_t y, uint32_t color);
    virtual void    fill_screen(uint32_t color);
		virtual void    flush();

private:
    Lcd_t   _lcd;
		Print		*_p;		//����豸

    uint32_t _getPosition(int16_t x, int16_t y);		// ������Ļλ�÷����������ڴ�λ��		
};

#endif

