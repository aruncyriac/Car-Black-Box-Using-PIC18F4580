/* 
 * File:   eeprom.h
 * Author: arunc
 *
 * Created on 3 January, 2025, 2:08 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

void write_internal_eeprom(unsigned char address, unsigned char data);
unsigned char read_internal_eeprom(unsigned char address);

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

