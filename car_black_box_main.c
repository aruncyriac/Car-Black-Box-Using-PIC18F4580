/*
 * File:   car_black_box_main.c
 * Author: arunc
 *
 * Created on 30 December, 2024, 4:51 PM
 */


#include "main.h"

void init_config() {
    count = 0;
    speed = 0;
    flag = 0;
    init_clcd();
    init_matrix_keypad();
    init_adc();
    init_i2c();
    init_ds1307();
    init_uart();
    count1 = 0;
}

void main(void) {

    State state = dashbord;
    init_config();
    while (1) {
        if (++wait == 50) {
            wait = 0;
            toggle = !toggle;
        }
        get_time();
        key = read_switches(STATE_CHANGE);
        if (key == 11 && e_flag1 == 0) {
            CLEAR_DISP_SCREEN;
            e_flag1 = 1;
            key = 0xff;
            j = 0;
            star = 0;
            e_flag2 = 0;
            choice = 5;
            read();
            h = (10 * (time[0] - 48)) + (time[1] - 48);
            min = (10 * (time[3] - 48)) + (time[4] - 48);
            sec = (10 * (time[6] - 48)) + (time[7] - 48);
        }
        //        if (key == 11 && e_flag1 == 1 && e_flag2 == 0) {
        //            //CLEAR_DISP_SCREEN;
        //            e_flag2 = 1;
        //        }
        if (key == 12 && e_flag1 == 1 && e_flag2 == 0) {
            CLEAR_DISP_SCREEN;
            e_flag1 = 0;
        }
        //        if (key == 12 && e_flag1 == 1 && e_flag2 == 1) {
        //            //CLEAR_DISP_SCREEN;
        //            e_flag2 = 0;
        //        }
        if (e_flag1 == 1) {
            //e_flag1 = 1;
            //CLEAR_DISP_SCREEN;
            
            state = menu;

        } else {
            //CLEAR_DISP_SCREEN;
            state = dashbord;
        }
        switch (state) {
            case dashbord:
                das();

                k = 0;
                break;
            case menu:
                //pos = start - count1;
                men();
                break;

        }
        if (e_flag2 == 1) {
            switch (choice) {
                    CLEAR_DISP_SCREEN;
                case 0:


                    clcd_print("# Time     EV SP", LINE1(0));
                    if (count1 > 0) {
                        clcd_print(data1[k], LINE2(0));
                        if (key == 2) {
                            k++;
                        } else if (key == 1) {
                            k--;
                        }
                        if (k < 0) {
                            k = 0;
                        }
                        if (k > count1-1) {
                            k = count1-1;
                        }

                    } else {

                        clcd_print("N0 LOGS         ", LINE1(0));
                        clcd_print("  TO DISPLAY :( ",LINE2(0));
                        for(unsigned long int t_wait = 500000;t_wait--; );
                        e_flag2 = 0;
                    }

                    break;
                case 1:
                    settime();
                    break;
                case 2:

                    download();

                    break;
                case 3:
                    count1 = 0;
                    start = 0;
                    add = 0x00;
                    k = 0;
                    CLEAR_DISP_SCREEN;
                    clcd_print("CLEARING LOGS    ", LINE1(0));
                    clcd_print("JUST A MINUTE    ",LINE2(0));
                    for(unsigned long int t_wait = 500000;t_wait--; );
                    e_flag2 = 0;
                    break;
            }

        }
    }
    return;
}
