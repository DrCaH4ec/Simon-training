#define F_CPU 16000000UL

#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include <usart.h>
#include <rtc.h>
#include <iic.h>

#define ADDRESS_OF_DS3231 0b1101000
#define ADDRESS_OF_MEMORY 0b1010111
#define IIC_SLC_FREQ 200000 //Hrz
#define DELAY 1000 //ms
#define NUMS_OF_SHOW_TIME 120 //times
#define PECKET_SIZE 8 // byte
#define USART_FREQ 9600 //Bps
#define ENTER "\n\r"
#define END "\n\r--------------------------------\n\r"
#define FORMAT_0b "0b"
#define RTC_CUR_TIME "<- RTC"
#define TIME_AT_COM "<- Time at compile time"

void show_addresses(uint8_t *slave_adresses)
{
    uint8_t j = 0;

    while (slave_adresses[j] != 0b11111111 && j < 128)
        usart_send_data_by_nums(slave_adresses[j++]);
}

int main(void)
{   
    char time_str[9]; //buf for time_str
    uint8_t *slave_addresses;

    usart_init(USART_FREQ, PECKET_SIZE); //initializtion uart

    iic_init(IIC_SLC_FREQ); //initializtion I2C

    _delay_ms(1);

    show_addresses(iic_find_all_devices(slave_addresses));
    free(slave_addresses);
    usart_send_data_str(END);

    /* Show time compile*/
    usart_send_data_str(ENTER);
    usart_send_data_str(__TIME__);
    usart_send_data_str(TIME_AT_COM);
    usart_send_data_str(ENTER);
    usart_send_data_str(ENTER);
    /* Show time compile*/

    rtc_set_time(__TIME__, ADDRESS_OF_DS3231); //DS3231 set time.

    for (int i  = 0; i <NUMS_OF_SHOW_TIME; i++){
        _delay_ms(DELAY); //Wait 1 sec
        rtc_get_time(time_str, ADDRESS_OF_DS3231);
        usart_send_data_str(time_str);
        usart_send_data_str(RTC_CUR_TIME);
        usart_send_data_str(ENTER); 
    }

    usart_send_data_str(END);

    while (1);
    return 0;
}