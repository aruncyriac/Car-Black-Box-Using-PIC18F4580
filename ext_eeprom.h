/* 
 * File:   ext_eeprom.h
 * Author: arunc
 *
 * Created on 15 January, 2025, 2:39 PM
 */

#ifndef EXT_EEPROM_H
#define	EXT_EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif
#define SLAVE_READ_E		0xA1
#define SLAVE_WRITE_E		0xA0
void write_external_eeprom(unsigned char address1,  unsigned char data);
unsigned char read_external_eeprom(unsigned char address1);


#ifdef	__cplusplus
}
#endif

#endif	/* EXT_EEPROM_H */

