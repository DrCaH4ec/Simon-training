#include <avr/io.h>

#include <stdint.h>
#include <usart.h>

void usart_boud_rate(const uint16_t b_rate_val)
{
    UBRR0H = (unsigned char) (b_rate_val>>BITE_SIZE);
    UBRR0L = (unsigned char) (b_rate_val);
}

void usart_enable_receiver(void)
{
    SET_BIT(UCSR0B, RXEN0);
}

void usart_enable_transmitter(void)
{
    SET_BIT(UCSR0B, TXEN0);
}

void usart_set_packet_size(const uint8_t packet_size)
{
    switch (packet_size){
    case 9:
        SET_BIT(UCSR0C, UCSZ00);
        SET_BIT(UCSR0C, UCSZ01);
        SET_BIT(UCSR0B, UCSZ02); // Set paket size 9 bit.
        break;
    case 7:
        KILL_BIT(UCSR0C, UCSZ00);
        SET_BIT(UCSR0C, UCSZ01);
        KILL_BIT(UCSR0B, UCSZ02); // Set paket size 7 bit.
        break;
    case 6:
        SET_BIT(UCSR0C, UCSZ00);
        KILL_BIT(UCSR0C, UCSZ01);
        KILL_BIT(UCSR0B, UCSZ02); // Set paket size 6 bit.
        break;
    case 5:
        KILL_BIT(UCSR0C, UCSZ00);
        KILL_BIT(UCSR0C, UCSZ01);
        KILL_BIT(UCSR0B, UCSZ02); // Set paket size 5 bit.
        break;
    default:
        SET_BIT(UCSR0C, UCSZ00);
        SET_BIT(UCSR0C, UCSZ01);
        KILL_BIT(UCSR0B, UCSZ02); // Set paket size 8 bit.
        break;
    } 
    // Set size of packet.
}

void usart_init(const uint16_t b_rate_val, const uint8_t packet_size) 
{
    usart_enable_transmitter();
    usart_set_packet_size(packet_size);
    usart_boud_rate(b_rate_val);
    // Set resources of uart.
}

void usart_send_byte(const char data)
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
