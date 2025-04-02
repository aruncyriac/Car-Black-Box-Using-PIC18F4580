/*
 * File:   menu.c
 * Author: arunc
 *
 * Created on 2 January, 2025, 2:26 PM
 */


#include "main.h"

void men() {
    static int k = 0;
    if (e_flag2 == 0) {
        if (key == 2) {

            if (star == 0) {
                star = 1;
            } else {
                j++;
            }
            if (j > 2) {
                j = 2;
            }
        }
        if (key == 1) {

            if (star == 1) {
                star = 0;
            } else {
                j--;
            }
            if (j < 0) {
                j = 0;
            }
        }
        if (j < 3) {
            if (star) {
                clcd_putch('*', LINE2(0));
                clcd_putch(' ', LINE1(0));

            } else {
                clcd_putch(' ', LINE2(0));
                clcd_putch('*', LINE1(0));
            }
            clcd_print(m[j], LINE1(1));
            clcd_print(m[j + 1], LINE2(1));
        }
    }
    if (key == 11 && e_flag2 == 0) {
        e_flag2 = 1;
        //        h = (10 * (time[0] - 48)) + (time[1] - 48);
        //        min = (10 * (time[3] - 48)) + (time[4] - 48);
        //        sec = (10 * (time[6] - 48)) + (time[7] - 48);
        key = 0xff;
        if (star == 0 && j == 0) {
            choice = 0;
        }
        if (star == 1 && j == 2) {
            choice = 3;
        }
        if (star == 0 && j == 2) {
            choice = 2;
        }
        if (star == 1 && j == 1) {
            choice = 2;
        }
        if (star == 1 && j == 0) {
            choice = 1;
        }
        if (star == 0 && j == 1) {
            choice = 1;
        }
    }
    if (key == 12 && e_flag2 == 1) {
        //key = 0xff;
        h = (10 * (time[0] - 48)) + (time[1] - 48);
        min = (10 * (time[3] - 48)) + (time[4] - 48);
        sec = (10 * (time[6] - 48)) + (time[7] - 48);
        e_flag2 = 0;
    }

    /*  typedef enum
  {
      m_view,
      m_clear,
      m_download,
      m_settime
  }Menu;*/

}

void read() {
    // int k = 0;
    unsigned char temp = 0x00;
    if (start > 9) {
        temp = (start % 10)*10;
    } else {
        temp = 0;
    }
    for (int i = 0; i < 10; i++) {
        //        if (pos >=
        //                count1) {
        //            pos = 0;
        //        }
        data1[i][0] = i + '0';
        data1[i][1] = ' ';
        data1[i][2] = read_external_eeprom(temp++);
        data1[i][3] = read_external_eeprom(temp++);
        data1[i][4] = ':';
        data1[i][5] = read_external_eeprom(temp++);
        data1[i][6] = read_external_eeprom(temp++);
        data1[i][7] = ':';
        data1[i][8] = read_external_eeprom(temp++);
        data1[i][9] = read_external_eeprom(temp++);
        data1[i][10] = ' ';
        data1[i][11] = read_external_eeprom(temp++);
        data1[i][12] = read_external_eeprom(temp++);
        data1[i][13] = ' ';
        data1[i][14] = read_external_eeprom(temp++);
        data1[i][15] = read_external_eeprom(temp++);
        data1[i][16] = '\0';
        if (temp >= 0x64) {
            temp = 0x00;
        }
    }
}

void store() {
    data[0] = time[0];
    data[1] = time[1];
    data[2] = time[3];
    data[3] = time[4];
    data[4] = time[6];
    data[5] = time[7];
    data[6] = g[count][0];
    data[7] = g[count][1];
    data[8] = speed / 10 + '0';
    data[9] = speed % 10 + '0';
    data[10] = '\0';
    //    CLEAR_DISP_SCREEN;
    //    clcd_print(data,LINE1(0));
    //    for(unsigned long int k = 500000;k--;);
    //    CLEAR_DISP_SCREEN;
    for (int k = 0; k <= 9; k++) {
        write_external_eeprom(add++, data[k]);
        //        if(m_flag == 1)
        //        {
        //            pos++;
        //        }
    }
    count1++;
    start++;
    if (count1 > 10) {

        count1 = 10;
    }
    //    if (start > count1) {
    //        start = 0;
    //    }
    if (add >= 0x64) {

        add = 0x00;
        //        m_flag = 1;
    }
    //    if(pos >= 0x64)
    //    {
    //        pos = 0;
    //        m_flag = 0;
    //    }

    //    pos = start;
    //    if(start > count1)
    //    {
    //        pos = start - count1;
    //    }
    //    else
    //    {
    //        pos = count1 - start;
    //    }
}

void download() {
    if (count1 > 0) {
        puts("Logs are:\n\r");
        for (int k = 0; k < count1; k++) {
            puts(data1[k]);
            puts("\n\r");
        }
        //CLEAR_DISP_SCREEN;
        clcd_print("Downloading...  ", LINE1(0));
        clcd_print("Through UART... ", LINE2(0));
        for (unsigned long int t_wait = 500000; t_wait--;);
        CLEAR_DISP_SCREEN;
        e_flag2 = 0;
    } else {
        clcd_print("NO LOGS.        ", LINE1(0));
        clcd_print("   To Download:(", LINE2(0));
        puts("No Logs \n\r");
        for (unsigned long int t_wait = 500000; t_wait--;);
        CLEAR_DISP_SCREEN;
        e_flag2 = 0;
    }

    //e_flag1 = 0;

}

void writetime() {
    h = ((h / 10) << 4) | (h % 10);
    min = ((min / 10) << 4) | (min % 10);
    sec = ((sec / 10) << 4) | (sec % 10);
    write_ds1307(SEC_ADDR, sec);
    write_ds1307(MIN_ADDR, min);
    write_ds1307(HOUR_ADDR, h);
}

void settime() {
    clcd_print("HH:MM:SS       ", LINE1(0));
    if (key == 2) {
        s++;
        if (s == 3) {
            s = 0;
        }
    }
    if (s == 0) {


        if (toggle) {
            // CLEAR_DISP_SCREEN;
            clcd_putch(h / 10 + '0', LINE2(0));
            clcd_putch(h % 10 + '0', LINE2(1));
        } else {
            clcd_putch(' ', LINE2(0));
            clcd_putch(' ', LINE2(1));
        }
        if (key == 1) {
            h++;
            if (h > 23) {
                h = 0;
            }
        }
        clcd_putch(':', LINE2(2));
        clcd_putch(min / 10 + '0', LINE2(3));
        clcd_putch(min % 10 + '0', LINE2(4));
        clcd_putch(':', LINE2(5));
        clcd_putch(sec / 10 + '0', LINE2(6));
        clcd_putch(sec % 10 + '0', LINE2(7));
        clcd_print("         ", LINE2(8));
    } else if (s == 1) {
        if (toggle) {
            // CLEAR_DISP_SCREEN;
            clcd_putch(min / 10 + '0', LINE2(3));
            clcd_putch(min % 10 + '0', LINE2(4));
        } else {
            clcd_putch(' ', LINE2(3));
            clcd_putch(' ', LINE2(4));
        }
        if (key == 1) {
            min++;
            if (min > 59) {
                min = 0;
            }
        }
        clcd_putch(':', LINE2(2));
        clcd_putch(h / 10 + '0', LINE2(0));
        clcd_putch(h % 10 + '0', LINE2(1));
        clcd_putch(':', LINE2(5));
        clcd_putch(sec / 10 + '0', LINE2(6));
        clcd_putch(sec % 10 + '0', LINE2(7));
        clcd_print("         ", LINE2(8));
    } else if (s == 2) {
        if (toggle) {
            // CLEAR_DISP_SCREEN;
            clcd_putch(sec / 10 + '0', LINE2(6));
            clcd_putch(sec % 10 + '0', LINE2(7));
        } else {
            clcd_putch(' ', LINE2(6));
            clcd_putch(' ', LINE2(7));
        }
        if (key == 1) {
            sec++;
            if (sec > 59) {
                sec = 0;
            }
        }
        clcd_putch(':', LINE2(2));
        clcd_putch(h / 10 + '0', LINE2(0));
        clcd_putch(h % 10 + '0', LINE2(1));
        clcd_putch(':', LINE2(5));
        clcd_putch(min / 10 + '0', LINE2(3));
        clcd_putch(min % 10 + '0', LINE2(4));
        clcd_print("         ", LINE2(8));

    }
    if (key == 11) {
        CLEAR_DISP_SCREEN;
        writetime();
        e_flag1 = 0;
        e_flag2 = 0;
        min = 0;
        h = 0;
        sec = 0;
    } else if (key == 12) {
        h = (10 * (time[0] - 48)) + (time[1] - 48);
        min = (10 * (time[3] - 48)) + (time[4] - 48);
        sec = (10 * (time[6] - 48)) + (time[7] - 48);
        e_flag2 = 0;
    }


}

