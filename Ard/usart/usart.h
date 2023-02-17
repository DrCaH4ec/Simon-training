#ifndef RESOURCES_USART
#define RESOURCES_USART


#define SET_BIT(register, bit) (register |= (1<<bit))
#define KILL_BIT(register, bit) (register |= (0<<bit))
#define BITE_SIZE 8

void usart_init(const uint16_t b_rate_val, const uint8_t packet_size);
void usart_send_data(const char *data, uint16_t size);

#endif
