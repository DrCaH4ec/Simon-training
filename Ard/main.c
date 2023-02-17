#define F_CPU 16000000UL

#include <util/delay.h>
#include <string.h>

#include <usart.h>

#define TEXT "!!!!!\n\r"

int main(void)
{
    usart_init(103,5);

    _delay_ms(1);

    usart_send_data(TEXT, strlen(TEXT));

    while (1);
    return 0;
}