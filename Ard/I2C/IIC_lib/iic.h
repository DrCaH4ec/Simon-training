#ifndef IIC 
#define IIC 

#include <avr/io.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>
//#include <usart.h>

//#define TEST_TWCR_CON //if you use it u must add usart.h
#define F_CPU 16000000UL
#define SIZE_OF_BYTE 128
#define WRITE_BIT_ON 0
#define WRITE_BIT_OFF 1
#define READ_BIT_ON WRITE_BIT_OFF
#define SBI(register, bit) (register |= (1<<bit))
#define CBI(register, bit) (register &= ~(1<<bit))
#define CAL_SETED_PV pow(4, (TWSR & (1<<TWPS0)) | (TWSR & (1<<TWPS1)))
#define CAL_PV(degree) (pow(4, degree))
#define CAL_TWBR_VAL(freq_SLC, presc_val) (F_CPU / freq_SLC - 16) / (2 * presc_val)
#define CAL_TWBR_

void iic_write_to_slave(uint8_t slave, uint8_t *array, uint8_t size, uint8_t address_memory);
void iic_read_from_slave(uint8_t slave, uint8_t *array, uint8_t size, uint8_t address_memory);
void iic_set_SLC_freq(uint32_t freq_SLC);
void iic_set_start_con(void);
void iic_set_stop_con(void);
void iic_send_SLA_Wbit(uint8_t data, bool write_bit);
void iic_send_data(uint8_t data);
uint8_t iic_read_data(void);
uint8_t iic_read_data_last(void);
uint8_t get_prescaler_val(void);
uint8_t get_TWBR_val(void);




#endif
