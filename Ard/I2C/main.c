#define F_CPU 16000000UL

#include <util/delay.h>
#include <usart.h>
#include <iic.h>
#include <stdint.h>

#define ADDRESS_OF_DS3231 0b1101000
#define ADDRESS_OF_MEMORY 0b1010111

#define ENTER "\n\r"
#define END "\n\r--------------------------------\n\r"
#define IIC_SLC_FREQ 200000
#define DELAY 1000
#define NUMS_OF_SHOW_TIME 120
#define PECKET_SIZE 8
#define USART_FREQ 9600


void decode_num(uint8_t num)
{
    usart_send_byte((num>>4) + 48);
    usart_send_byte((num & 0b00001111) + 48);
}

void show_time(uint8_t *byte_time)
{
    usart_send_data_str(ENTER);
    decode_num(byte_time[2]);
    usart_send_byte(':');
    decode_num(byte_time[1]);
    usart_send_byte(':');
    decode_num(byte_time[0]);

}

void take_com_time(uint8_t *time)
{
    char real_time[9];
    strcpy(real_time, __TIME__);

    time[0] = ((real_time[6] - 48)<<4) | (real_time[7] - 48);
    time[1] = ((real_time[3] - 48)<<4) | (real_time[4] - 48);
    time[2] = ((real_time[0] - 48)<<4) | (real_time[1] - 48);
}

int main(void)
{
    uint8_t byte_data[3];
    
    usart_init(USART_FREQ, PECKET_SIZE); //initializtion uart

    _delay_ms(1);

    take_com_time(byte_data); 

    /* Show time compile*/
    usart_send_data_str(ENTER);
    usart_send_data_str(__TIME__);
    usart_send_data_str(ENTER);
    /* Show time compile*/

    iic_set_SLC_freq(IIC_SLC_FREQ);

    iic_write_to_slave(ADDRESS_OF_DS3231, byte_data, 3, 0); //Send compile time to DS3231

    for (int i  = 0; i <NUMS_OF_SHOW_TIME; i++){
        _delay_ms(DELAY); //Wait 1 sec
        iic_read_from_slave(ADDRESS_OF_DS3231, byte_data, 3, 0); //Read data to buf
        show_time(byte_data); 
    }

    usart_send_data_str(END);

    while (1);
    return 0;
}