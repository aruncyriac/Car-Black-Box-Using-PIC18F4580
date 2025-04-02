/*
 * File:   dashbord.c
 * Author: arunc
 *
 * Created on 30 December, 2024, 5:04 PM
 */

#include "main.h"
void das() {
    clcd_print("Time", LINE1(0));
    clcd_print("EV", LINE1(9));
    clcd_print("SP", LINE1(14));
    clcd_print(time, LINE2(0));
    clcd_print(g[count], LINE2(9));
      speed = (int) (read_adc() / (float) 10.32);
    clcd_putch(speed / 10 + '0', LINE2(14));
    clcd_putch(speed % 10 + '0', LINE2(15));

  
    temp = count;
    if (key == 2) {
        if (flag) {
            flag = 0;
            count = 1;
            
        } else {
            count++;
            
        }
    } else if (key == 3 && flag == 0 && count > 1) {
        count--;
        
    } else if (key == 1) {
        count = 7;
      
        flag = 1;
    }
   if (count > 6 && flag == 0) {
        count = 6;
    }
    if(temp != count)
    {
        store();
    }
}
