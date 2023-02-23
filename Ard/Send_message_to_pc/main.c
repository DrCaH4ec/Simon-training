#define F_CPU 16000000UL

#include <util/delay.h>
#include <string.h>

#include <usart.h>

#define TEXT "->Hellow WORLD!!<-\n\r"

int main(void)
{
    usart_init(9600,8);

    _delay_ms(1);

    usart_send_data(TEXT, strlen(TEXT));

    while (1);
    return 0;
}
