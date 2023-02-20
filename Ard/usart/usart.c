#include <avr/io.h>

#include <stdint.h>
#include <math.h>
#include <usart.h>

void usart_set_baud_rate(const unsigned int bps)
{
    uint16_t tem_UBRR_val = CAL_UBRR_VAL_FOR_U2X0(bps); 
    UBRR0H = (unsigned char) (tem_UBRR_val>>BITE_SIZE);
    UBRR0L = (unsigned char) (tem_UBRR_val);
}

void usart_enable_receiver(void)
{
    SBI(UCSR0B, RXEN0);
}

void usart_enable_transmitter(void)
{
    SBI(UCSR0B, TXEN0);
}

void usart_set_packet_size(const uint8_t packet_size)
{
    switch (packet_size){
    case 9:
        SBI(UCSR0C, UCSZ00);
        SBI(UCSR0C, UCSZ01);
        SBI(UCSR0B, UCSZ02); // Set paket size 9 bit.
        break;
    case 7:
        //CBI(UCSR0C, UCSZ00);
        SBI(UCSR0C, UCSZ01);
        //CBI(UCSR0B, UCSZ02); // Set paket size 7 bit.
        break;
    case 6:
        SBI(UCSR0C, UCSZ00);
        //CBI(UCSR0C, UCSZ01);
        //CBI(UCSR0B, UCSZ02); // Set paket size 6 bit.
        break;
    case 5:
        //CBI(UCSR0C, UCSZ00);
        //CBI(UCSR0C, UCSZ01);
        //CBI(UCSR0B, UCSZ02); // Set paket size 5 bit.
        break;
    case 8:
    default:
        SBI(UCSR0C, UCSZ00);
        SBI(UCSR0C, UCSZ01);
        //CBI(UCSR0B, UCSZ02); // Set paket size 8 bit.
        break;
    } 
    // Set size of packet.
}

void usart_init(const unsigned int bps, const uint8_t packet_size) 
{
    usart_enable_transmitter();
    usart_set_packet_size(packet_size);
    usart_set_baud_rate(bps);
    // Set resources of uart.
}

static void usart_send_byte(const char data)
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) );
    /* Put data into buffer, sends the data */
    UDR0 = data;
}

void usart_send_data(const char *data, uint16_t size)
{
    for (uint16_t i = 0; i < size; i++)
        usart_send_byte(data[i]);
}
