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

#include "stdint.h"

/**********************************
*
*      Text styles
*
***********************************
*/

#define GUI_TS_NORMAL           (0)
#define GUI_TS_UNDERLINE        (1 << 0)
#define GUI_TS_STRIKETHRU       (1 << 1)
#define GUI_TS_OVERLINE         (1 << 2)

/*
      ****************************************
      *                                      *
      *      FONT structures (new in V1.10)  *
      *                                      *
      ****************************************
*/

/* Translation list. Translates a character code into up to 2
   indices of images to display on top of each other;
   '? -> index('a'), index('?) */
typedef struct {
  int16_t c0;
  int16_t c1;
} GUI_FONT_TRANSLIST;

typedef struct {
  uint16_t FirstChar;
  uint16_t LastChar;
  const GUI_FONT_TRANSLIST * pList;
} GUI_FONT_TRANSINFO;

// �ַ���Ϣ
typedef struct {
  uint8_t XSize;
  uint8_t XDist;
  uint8_t BytesPerLine;												// ÿ��byte�� 
  const unsigned char * pData;
} GUI_CHARINFO;

// ��������ṹ
typedef struct GUI_FONT_PROP {
  uint16_t First;                                             /* first character               */
  uint16_t Last;                                              /* last character                */
  const GUI_CHARINFO * paCharInfo;            /* ���ַ���ַ    */
  const struct GUI_FONT_PROP * pNext;         /* pointer to next */
} GUI_FONT_PROP;

// �ȿ�����
typedef struct {
  const unsigned char * pData;
  const uint8_t * pTransData;
  const GUI_FONT_TRANSINFO * pTrans;
  uint16_t FirstChar;
  uint16_t LastChar;
  uint8_t XSize;
  uint8_t XDist;
  uint8_t BytesPerLine;
} GUI_FONT_MONO;

// �ַ�����Ϣ
typedef struct GUI_FONT_INFO {
  uint16_t First;                        	/* first character               */
  uint16_t Last;                         	/* last character                */
  const GUI_CHARINFO* paCharInfo;    			/* address of first character    */
  const struct GUI_FONT_INFO* pNext; 			/* pointer to next */
} GUI_FONT_INFO;

// �����ַ���Ϣ
typedef struct {
  uint16_t Flags;
  uint8_t Baseline;
  uint8_t LHeight;     /* height of a small lower case character (a,x) */
  uint8_t CHeight;     /* height of a small upper case character (A,X) */
} GUI_FONTINFO;

// ��������
#define GUI_FONTINFO_FLAG_PROP (1<<0)    /* Is proportional ��������*/
#define GUI_FONTINFO_FLAG_MONO (1<<1)    /* Is monospaced 	�ȿ�����*/
#define GUI_FONTINFO_FLAG_AA   (1<<2)    /* Is an antialiased font */
#define GUI_FONTINFO_FLAG_AA2  (1<<3)    /* Is an antialiased font, 2bpp */
#define GUI_FONTINFO_FLAG_AA4  (1<<4)    /* Is an antialiased font, 4bpp */


/**********************************************************************
*
*         UNICODE Encoding
*
***********************************************************************
*/
typedef uint16_t  tGUI_GetCharCode(const char *s);
typedef int  tGUI_GetCharSize(const char *s);
typedef int  tGUI_CalcSizeOfChar(uint16_t Char);
typedef int  tGUI_Encode(char *s, uint16_t Char);

typedef struct {
  tGUI_GetCharCode*            pfGetCharCode;
  tGUI_GetCharSize*            pfGetCharSize;
  tGUI_CalcSizeOfChar*         pfCalcSizeOfChar;
  tGUI_Encode*                 pfEncode;
} GUI_UC_ENC_APILIST;

/**********************************************************************
*
*                 FONT Encoding
*
***********************************************************************
*/

typedef int  tGUI_GetLineDistX(const char *s, int Len);
typedef int  tGUI_GetLineLen(const char *s, int MaxLen);
typedef void tGL_DispLine(const char *s, int Len);

typedef struct {
  tGUI_GetLineDistX*          pfGetLineDistX;
  tGUI_GetLineLen*            pfGetLineLen;
  tGL_DispLine*               pfDispLine;
} tGUI_ENC_APIList;

extern const tGUI_ENC_APIList GUI_ENC_APIList_SJIS;

typedef struct GUI_FONT GUI_FONT;



/*
      ****************************************
      *                                      *
      *      FONT methods                    *
      *                                      *
      ****************************************
*/
typedef void GUI_DISPCHAR			(void);
typedef int  GUI_GETCHARDISTX	(const GUI_FONT * pFont,uint16_t c);
typedef uint16_t GUI_GETFONTINFO	(void);
typedef char GUI_ISINFONT   	(const GUI_FONT * pFont,uint16_t c);

#define DECLARE_FONT(Type)                                     \
void GUI##Type##_DispChar    (void);                         \
int  GUI##Type##_GetCharDistX(const GUI_FONT * pFont,uint16_t c);                         \
uint16_t GUI##Type##_GetFontInfo (void); \
char GUI##Type##_IsInFont    (const GUI_FONT * pFont, uint16_t c)

/* MONO: Monospaced fonts */    // �ȿ����� �߶ȿ�Ⱦ���ͬ
DECLARE_FONT(MONO);
#define GUI_FONTTYPE_MONO       \
  GUIMONO_DispChar,             \
	GUIMONO_GetCharDistX,         \
	GUIMONO_GetFontInfo,          \
	GUIMONO_IsInFont,             \
  (tGUI_ENC_APIList*)0

/* PROP: Proportional fonts */  // �������壬ÿ�����嶼�ж��ԵĿ�ȣ�������Ҫ����������������ÿ����
DECLARE_FONT(PROP);
#define GUI_FONTTYPE_PROP       \
  GUIPROP_DispChar,             \
	GUIPROP_GetCharDistX,         \
	GUIPROP_GetFontInfo,          \
	GUIPROP_IsInFont,             \
  (tGUI_ENC_APIList*)0

// �ַ��ṹ��
struct GUI_FONT {
  // ָ��ǰ����������غ���
  GUI_DISPCHAR*     pfDispChar; 
  GUI_GETCHARDISTX* pfGetCharDistX; 
  GUI_GETFONTINFO*  pfGetFontInfo; 
  GUI_ISINFONT*     pfIsInFont;
  const tGUI_ENC_APIList* pafEncode;
  // 
  uint8_t YSize;         // �߶�
  uint8_t YDist;         
  uint8_t XMag;
  uint8_t YMag;
	// ��������������ʹ֮����ָ��ͬ���͵�����
  union {
    const void          * pFontData;
    const GUI_FONT_MONO * pMono;
    const GUI_FONT_PROP * pProp;
  } p;
  uint8_t Baseline;
  uint8_t LHeight;     /* height of a small lower case character (a,x) */
  uint8_t CHeight;     /* height of a small upper case character (A,X) */
};


/*********************************************************************
*
*            Standard Fonts
*
**********************************************************************

Note: The external declarations for the fonts are now also included in
      this file.
*/

/* Proportional fonts */
extern const GUI_FONT GUI_Font8_ASCII,        GUI_Font8_1;
extern const GUI_FONT GUI_Font10S_ASCII,      GUI_Font10S_1;
extern const GUI_FONT GUI_Font10_ASCII,       GUI_Font10_1;
extern const GUI_FONT GUI_Font13_ASCII,       GUI_Font13_1;
extern const GUI_FONT GUI_Font13B_ASCII,      GUI_Font13B_1;
extern const GUI_FONT GUI_Font13H_ASCII,      GUI_Font13H_1;
extern const GUI_FONT GUI_Font13HB_ASCII,     GUI_Font13HB_1;
extern const GUI_FONT GUI_Font16_ASCII,       GUI_Font16_1,       GUI_Font16_HK,    GUI_Font16_1HK;
extern const GUI_FONT GUI_Font16B_ASCII,      GUI_Font16B_1;
extern const GUI_FONT GUI_Font24_ASCII,       GUI_Font24_1;
extern const GUI_FONT GUI_Font24B_ASCII,      GUI_Font24B_1;
extern const GUI_FONT GUI_Font32_ASCII,       GUI_Font32_1;
extern const GUI_FONT GUI_Font32B_ASCII,      GUI_Font32B_1;

/* Monospaced */
extern const GUI_FONT GUI_Font4x6;
extern const GUI_FONT GUI_Font6x8,            GUI_Font6x9;
extern const GUI_FONT GUI_Font8x8,            GUI_Font8x9;
extern const GUI_FONT GUI_Font8x10_ASCII;
extern const GUI_FONT GUI_Font8x12_ASCII;
extern const GUI_FONT GUI_Font8x13_ASCII,     GUI_Font8x13_1;
extern const GUI_FONT GUI_Font8x15B_ASCII,    GUI_Font8x15B_1;
extern const GUI_FONT GUI_Font8x16,           GUI_Font8x17,       GUI_Font8x18;
extern const GUI_FONT GUI_Font8x16x1x2,       GUI_Font8x16x2x2,   GUI_Font8x16x3x3;

/* Digits */
extern const GUI_FONT GUI_FontD24x32;
extern const GUI_FONT GUI_FontD32;
extern const GUI_FONT GUI_FontD36x48;
extern const GUI_FONT GUI_FontD48;
extern const GUI_FONT GUI_FontD48x64;
extern const GUI_FONT GUI_FontD64;
extern const GUI_FONT GUI_FontD60x80;
extern const GUI_FONT GUI_FontD80;

/* Comic fonts */
extern const GUI_FONT GUI_FontComic18B_ASCII, GUI_FontComic18B_1;
extern const GUI_FONT GUI_FontComic24B_ASCII, GUI_FontComic24B_1;


/*
      *********************************
      *                               *
      * Text and drawing mode defines *
      *                               *
      *********************************

These defines come in two flavors: the long version (.._DRAWMODE_..)
and the short ones (.._DM_..). They are identical, feel free to use
which ever one you like best.

*/
typedef enum{
		DRAWMODE_NORMAL = 0,
		DRAWMODE_XOR,
		DRAWMODE_TRANS,
		DRAWMODE_REV = 1<<2
}DrawMode_t;

#define LCD_DRAWMODE_NORMAL (0)						// �����������κ��Ѿ���ʾ�Ķ���
#define LCD_DRAWMODE_XOR    (1<<0)				// ���
#define LCD_DRAWMODE_TRANS  (1<<1)				// ͸��, ������ʾ������������
#define LCD_DRAWMODE_REV    (1<<2)				// ��ת��

#define GUI_DRAWMODE_NORMAL  LCD_DRAWMODE_NORMAL			// ����
#define GUI_DRAWMODE_XOR     LCD_DRAWMODE_XOR					// ���
#define GUI_DRAWMODE_TRANS   LCD_DRAWMODE_TRANS				// ͸��
#define GUI_DRAWMODE_REV     LCD_DRAWMODE_REV					// ��ת
#define GUI_DM_NORMAL        LCD_DRAWMODE_NORMAL
#define GUI_DM_XOR           LCD_DRAWMODE_XOR
#define GUI_DM_TRANS         LCD_DRAWMODE_TRANS
#define GUI_DM_REV           LCD_DRAWMODE_REV

#define GUI_TEXTMODE_NORMAL  LCD_DRAWMODE_NORMAL
#define GUI_TEXTMODE_XOR     LCD_DRAWMODE_XOR
#define GUI_TEXTMODE_TRANS   LCD_DRAWMODE_TRANS
#define GUI_TEXTMODE_REV     LCD_DRAWMODE_REV
#define GUI_TM_NORMAL        LCD_DRAWMODE_NORMAL
#define GUI_TM_XOR           LCD_DRAWMODE_XOR
#define GUI_TM_TRANS         LCD_DRAWMODE_TRANS
#define GUI_TM_REV           LCD_DRAWMODE_REV

/* Text alignment flags, horizontal */
#define GUI_TA_HORIZONTAL  (3<<0)
#define GUI_TA_LEFT        (0<<0)
#define GUI_TA_RIGHT	     (1<<0)
#define GUI_TA_CENTER	     (2<<0)
#define GUI_TA_HCENTER	   GUI_TA_CENTER  /* easier to remember :-)  */

/* Text alignment flags, vertical */
#define GUI_TA_VERTICAL   (3<<2)
#define GUI_TA_TOP	      (0<<2)
#define GUI_TA_BOTTOM	    (1<<2)
#define GUI_TA_BASELINE   (2<<2)
#define GUI_TA_VCENTER    (3<<2)


uint8_t        GUI_SetFillStyle (uint8_t Style);

/* Get/Set Character used as decimal point (usually '.' or ',') */
char      GUI_GetDecChar(void);
char      GUI_SetDecChar(char c);

/**************************************************************
*
*      Defines for constants
*
***************************************************************
*/

#define	________	0x0
#define	_______X	0x1
#define	______X_	0x2
#define	______XX	0x3
#define	_____X__	0x4
#define	_____X_X	0x5
#define	_____XX_	0x6
#define	_____XXX	0x7
#define	____X___	0x8
#define	____X__X	0x9
#define	____X_X_	0xa
#define	____X_XX	0xb
#define	____XX__	0xc
#define	____XX_X	0xd
#define	____XXX_	0xe
#define	____XXXX	0xf
#define	___X____	0x10
#define	___X___X	0x11
#define	___X__X_	0x12
#define	___X__XX	0x13
#define	___X_X__	0x14
#define	___X_X_X	0x15
#define	___X_XX_	0x16
#define	___X_XXX	0x17
#define	___XX___	0x18
#define	___XX__X	0x19
#define	___XX_X_	0x1a
#define	___XX_XX	0x1b
#define	___XXX__	0x1c
#define	___XXX_X	0x1d
#define	___XXXX_	0x1e
#define	___XXXXX	0x1f
#define	__X_____	0x20
#define	__X____X	0x21
#define	__X___X_	0x22
#define	__X___XX	0x23
#define	__X__X__	0x24
#define	__X__X_X	0x25
#define	__X__XX_	0x26
#define	__X__XXX	0x27
#define	__X_X___	0x28
#define	__X_X__X	0x29
#define	__X_X_X_	0x2a
#define	__X_X_XX	0x2b
#define	__X_XX__	0x2c
#define	__X_XX_X	0x2d
#define	__X_XXX_	0x2e
#define	__X_XXXX	0x2f
#define	__XX____	0x30
#define	__XX___X	0x31
#define	__XX__X_	0x32
#define	__XX__XX	0x33
#define	__XX_X__	0x34
#define	__XX_X_X	0x35
#define	__XX_XX_	0x36
#define	__XX_XXX	0x37
#define	__XXX___	0x38
#define	__XXX__X	0x39
#define	__XXX_X_	0x3a
#define	__XXX_XX	0x3b
#define	__XXXX__	0x3c
#define	__XXXX_X	0x3d
#define	__XXXXX_	0x3e
#define	__XXXXXX	0x3f
#define	_X______	0x40
#define	_X_____X	0x41
#define	_X____X_	0x42
#define	_X____XX	0x43
#define	_X___X__	0x44
#define	_X___X_X	0x45
#define	_X___XX_	0x46
#define	_X___XXX	0x47
#define	_X__X___	0x48
#define	_X__X__X	0x49
#define	_X__X_X_	0x4a
#define	_X__X_XX	0x4b
#define	_X__XX__	0x4c
#define	_X__XX_X	0x4d
#define	_X__XXX_	0x4e
#define	_X__XXXX	0x4f
#define	_X_X____	0x50
#define	_X_X___X	0x51
#define	_X_X__X_	0x52
#define	_X_X__XX	0x53
#define	_X_X_X__	0x54
#define	_X_X_X_X	0x55
#define	_X_X_XX_	0x56
#define	_X_X_XXX	0x57
#define	_X_XX___	0x58
#define	_X_XX__X	0x59
#define	_X_XX_X_	0x5a
#define	_X_XX_XX	0x5b
#define	_X_XXX__	0x5c
#define	_X_XXX_X	0x5d
#define	_X_XXXX_	0x5e
#define	_X_XXXXX	0x5f
#define	_XX_____	0x60
#define	_XX____X	0x61
#define	_XX___X_	0x62
#define	_XX___XX	0x63
#define	_XX__X__	0x64
#define	_XX__X_X	0x65
#define	_XX__XX_	0x66
#define	_XX__XXX	0x67
#define	_XX_X___	0x68
#define	_XX_X__X	0x69
#define	_XX_X_X_	0x6a
#define	_XX_X_XX	0x6b
#define	_XX_XX__	0x6c
#define	_XX_XX_X	0x6d
#define	_XX_XXX_	0x6e
#define	_XX_XXXX	0x6f
#define	_XXX____	0x70
#define	_XXX___X	0x71
#define	_XXX__X_	0x72
#define	_XXX__XX	0x73
#define	_XXX_X__	0x74
#define	_XXX_X_X	0x75
#define	_XXX_XX_	0x76
#define	_XXX_XXX	0x77
#define	_XXXX___	0x78
#define	_XXXX__X	0x79
#define	_XXXX_X_	0x7a
#define	_XXXX_XX	0x7b
#define	_XXXXX__	0x7c
#define	_XXXXX_X	0x7d
#define	_XXXXXX_	0x7e
#define	_XXXXXXX	0x7f
#define	X_______	0x80
#define	X______X	0x81
#define	X_____X_	0x82
#define	X_____XX	0x83
#define	X____X__	0x84
#define	X____X_X	0x85
#define	X____XX_	0x86
#define	X____XXX	0x87
#define	X___X___	0x88
#define	X___X__X	0x89
#define	X___X_X_	0x8a
#define	X___X_XX	0x8b
#define	X___XX__	0x8c
#define	X___XX_X	0x8d
#define	X___XXX_	0x8e
#define	X___XXXX	0x8f
#define	X__X____	0x90
#define	X__X___X	0x91
#define	X__X__X_	0x92
#define	X__X__XX	0x93
#define	X__X_X__	0x94
#define	X__X_X_X	0x95
#define	X__X_XX_	0x96
#define	X__X_XXX	0x97
#define	X__XX___	0x98
#define	X__XX__X	0x99
#define	X__XX_X_	0x9a
#define X__XX_XX	0x9b
#define X__XXX__	0x9c
#define X__XXX_X	0x9d
#define	X__XXXX_	0x9e
#define	X__XXXXX	0x9f
#define	X_X_____	0xa0
#define	X_X____X	0xa1
#define	X_X___X_	0xa2
#define	X_X___XX	0xa3
#define	X_X__X__	0xa4
#define	X_X__X_X	0xa5
#define	X_X__XX_	0xa6
#define	X_X__XXX	0xa7
#define	X_X_X___	0xa8
#define	X_X_X__X	0xa9
#define	X_X_X_X_	0xaa
#define	X_X_X_XX	0xab
#define	X_X_XX__	0xac
#define	X_X_XX_X	0xad
#define	X_X_XXX_	0xae
#define	X_X_XXXX	0xaf
#define	X_XX____	0xb0
#define X_XX___X	0xb1
#define	X_XX__X_	0xb2
#define	X_XX__XX	0xb3
#define	X_XX_X__	0xb4
#define	X_XX_X_X	0xb5
#define	X_XX_XX_	0xb6
#define	X_XX_XXX	0xb7
#define	X_XXX___	0xb8
#define	X_XXX__X	0xb9
#define	X_XXX_X_	0xba
#define	X_XXX_XX	0xbb
#define	X_XXXX__	0xbc
#define	X_XXXX_X	0xbd
#define	X_XXXXX_	0xbe
#define	X_XXXXXX	0xbf
#define	XX______	0xc0
#define	XX_____X	0xc1
#define	XX____X_	0xc2
#define	XX____XX	0xc3
#define	XX___X__	0xc4
#define	XX___X_X	0xc5
#define	XX___XX_	0xc6
#define	XX___XXX	0xc7
#define	XX__X___	0xc8
#define	XX__X__X	0xc9
#define	XX__X_X_	0xca
#define	XX__X_XX	0xcb
#define	XX__XX__	0xcc
#define	XX__XX_X	0xcd
#define	XX__XXX_	0xce
#define XX__XXXX	0xcf
#define	XX_X____	0xd0
#define	XX_X___X	0xd1
#define	XX_X__X_	0xd2
#define	XX_X__XX	0xd3
#define	XX_X_X__	0xd4
#define	XX_X_X_X	0xd5
#define	XX_X_XX_	0xd6
#define	XX_X_XXX	0xd7
#define	XX_XX___	0xd8
#define	XX_XX__X	0xd9
#define	XX_XX_X_	0xda
#define	XX_XX_XX	0xdb
#define	XX_XXX__	0xdc
#define	XX_XXX_X	0xdd
#define	XX_XXXX_	0xde
#define	XX_XXXXX	0xdf
#define	XXX_____	0xe0
#define	XXX____X	0xe1
#define	XXX___X_	0xe2
#define	XXX___XX	0xe3
#define	XXX__X__	0xe4
#define	XXX__X_X	0xe5
#define	XXX__XX_	0xe6
#define	XXX__XXX	0xe7
#define	XXX_X___	0xe8
#define	XXX_X__X	0xe9
#define	XXX_X_X_	0xea
#define	XXX_X_XX	0xeb
#define	XXX_XX__	0xec
#define	XXX_XX_X	0xed
#define	XXX_XXX_	0xee
#define	XXX_XXXX	0xef
#define	XXXX____	0xf0
#define	XXXX___X	0xf1
#define	XXXX__X_	0xf2
#define	XXXX__XX	0xf3
#define	XXXX_X__	0xf4
#define	XXXX_X_X	0xf5
#define	XXXX_XX_	0xf6
#define	XXXX_XXX	0xf7
#define	XXXXX___	0xf8
#define	XXXXX__X	0xf9
#define	XXXXX_X_	0xfa
#define	XXXXX_XX	0xfb
#define	XXXXXX__	0xfc
#define	XXXXXX_X	0xfd
#define	XXXXXXX_	0xfe
#define	XXXXXXXX	0xff

#if defined(__cplusplus)
}     /* Make sure we have C-declarations in C++ programs */
#endif

#endif   /* ifdef GUI_H */

/*************************** End of file ****************************/
