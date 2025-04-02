/* 
 * File:   newfile.h
 * Author: arunc
 *
 * Created on 30 December, 2024, 4:48 PM
 */

#ifndef NEWFILE_H
#define	NEWFILE_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef enum
{
    dashbord,
    menu
}State;
typedef enum
{
    m_view,
    m_clear,
    m_download,
    m_settime
}Menu;
#include <xc.h>
#include "ext_eeprom.h"
#include "ds1307.h"
#include "i2c.h"
#include "clcd.h"
#include "matrix_keypad.h" 
#include "eeprom.h"
#include "uart.h"

unsigned char key,add = 0x00;
unsigned char clock_reg[3];
unsigned char calender_reg[4];
unsigned char time[9];
unsigned char data1[11][18],data[18];

int j=0,star = 0,choice = 5,count1 = 0,toggle = 0,start = 0,k=0;
int count,speed = 0,flag = 0,temp,e_flag1 = 0,e_flag2 = 0;
unsigned char min = 0,h,sec = 0;
int s = 0;
unsigned long int wait = 0;
char *g[] = {"ON","GN","G1","G2","G3","G4","GR","C "};
//char [4][15] = {"                " ,"              ","                ","               "};
char *m[] = {" VIEW LOG         "," SET TIME      "," DOWNLOAD LOG   "," CLEAR LOG       "};
Menu mn;
void display_date(void);
void display_time(void);
//void init_config(void);
void get_time(void);
void get_date(void);
void init_adc();
unsigned short read_adc();
void das();
void men();
void store();
//void read(int pos);
void read();
void clear_mem();
void download();
void settime();
void writetime();


#ifdef	__cplusplus
}
#endif

#endif	/* NEWFILE_H */

