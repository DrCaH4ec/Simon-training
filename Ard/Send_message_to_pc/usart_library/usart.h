#ifndef RESOURCES_USART
#define RESOURCES_USART


#define SBI(register, bit) (register |= (1<<bit))
//#define CBI(register, bit) (register &= !(1<<bit))
#define F_CPU_VAL 16000000
#define BITE_SIZE 8
#define CAL_UBRR_VAL_FOR_U2X0(bps) (uint16_t) (round(F_CPU_VAL / (16. * (float)bps)) - 1)

void usart_init(const unsigned int bps, const uint8_t packet_size);
void usart_send_data(const char *data, uint16_t size);
void usart_enable_transmitter(void);
void usart_enable_receiver(void);

#endif
