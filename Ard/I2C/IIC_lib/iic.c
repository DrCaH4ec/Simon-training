#include <iic.h>

#ifdef TEST_TWCR_CON
#define T "\n\r"
#define G "\n\r--------------------------------\n\r"
void show_TWSR_con()
{
    switch (TWSR)
    {
    case 0x08:
        usart_send_data(T, strlen(T));
        usart_send_data("0x08", strlen("0x08"));
        break;
    case 0x10:
        usart_send_data(T, strlen(T));
        usart_send_data("0x10", strlen("0x10"));
        break;
    case 0x18:
        usart_send_data(T, strlen(T));
        usart_send_data("0x18", strlen("0x18"));
        break;
    case 0x20:
        usart_send_data(T, strlen(T));
        usart_send_data("0x20", strlen("0x20"));
        break;
    case 0x28:
        usart_send_data(T, strlen(T));
        usart_send_data("0x28", strlen("0x28"));
        break;
    case 0x30:
        usart_send_data(T, strlen(T));
        usart_send_data("0x30", strlen("0x30"));
        break;
    case 0x38:
        usart_send_data(T, strlen(T));
        usart_send_data("0x38", strlen("0x38"));
        break;
    case 0x40:
        usart_send_data(T, strlen(T));
        usart_send_data("0x40", strlen("0x40"));
        break;
    case 0x48:
        usart_send_data(T, strlen(T));
        usart_send_data("0x48", strlen("0x48"));
    case 0x50:
        usart_send_data(T, strlen(T));
        usart_send_data("0x50", strlen("0x50"));
        break;
    case 0x58:
        usart_send_data(T, strlen(T));
        usart_send_data("0x58", strlen("0x58"));
        break;
    case 0x68:
        usart_send_data(T, strlen(T));
        usart_send_data("0x68", strlen("0x68"));
        break;
    case 0x78:
        usart_send_data(T, strlen(T));
        usart_send_data("0x78", strlen("0x78"));
        break;
    case 0xF8:
        usart_send_data(T, strlen(T));
        usart_send_data("0xF8", strlen("0xF8"));
        break;
    case 1:
    default :
        usart_send_data(T, strlen(T));
        usart_send_byte(TWSR);
        break;
    }
}
#endif 

static void set_prescaler_val(uint8_t presc_val)
{
    switch (presc_val)
    {
    case 1:
        CBI(TWSR, TWPS0); 
        CBI(TWSR, TWPS1);
        break;
    case 4:
        SBI(TWSR, TWPS0); 
        CBI(TWSR, TWPS1);
        break;
    case 16:
        CBI(TWSR, TWPS0); 
        SBI(TWSR, TWPS1);
        break;
    case 64:
    default:
        SBI(TWSR, TWPS0); 
        SBI(TWSR, TWPS1);
        break;
    }
}

uint8_t get_prescaler_val(void)
{
    return CAL_SETED_PV;
}

uint8_t get_TWBR_val(void)
{
    return TWBR;
}

void iic_set_SLC_freq(uint32_t freq_SLC) //const unsigned long SLC_freq
{
    uint32_t tem = 0;
    set_prescaler_val(1);
    for (uint8_t i = 0; i < 4; i++){
        tem = CAL_TWBR_VAL(freq_SLC, get_prescaler_val());
        if (tem < 128){
            TWBR = tem;
            break;
        }
        set_prescaler_val(CAL_PV(i));
    }
}

void iic_set_start_con(void)
{
    SBI(TWCR, TWINT);
    CBI(TWCR, TWEA);
    SBI(TWCR, TWSTA);
    CBI(TWCR, TWSTO);
    CBI(TWCR, TWWC);
    SBI(TWCR, TWEN);
    CBI(TWCR, TWIE);
    //Configuration to START
    while (!(TWCR & (1<<TWINT))); //Wait to set con
}

void static iic_MTM_set_write_con(void)
{
    SBI(TWCR, TWINT); //status bit 
    CBI(TWCR, TWEA);
    CBI(TWCR, TWSTA); //status bit
    CBI(TWCR, TWSTO); //status bit
    CBI(TWCR, TWWC);
    SBI(TWCR, TWEN); //status bit 
    CBI(TWCR, TWIE); 
    while (!(TWCR & (1<<TWINT)));//wait to set con
}

uint8_t iic_read_data(void)
{
    SBI(TWCR, TWINT);
    SBI(TWCR, TWEA);
    CBI(TWCR, TWSTA);
    CBI(TWCR, TWSTO);
    CBI(TWCR, TWWC);
    SBI(TWCR, TWEN); 
    CBI(TWCR, TWIE);
    //configuration to read current data
    while (!(TWCR & (1<<TWINT)));
    return TWDR;
}

uint8_t iic_read_data_last(void)
{
    SBI(TWCR, TWINT);  
    CBI(TWCR, TWEA);
    CBI(TWCR, TWSTA); 
    CBI(TWCR, TWSTO);
    CBI(TWCR, TWWC);
    SBI(TWCR, TWEN); 
    CBI(TWCR, TWIE);
    //configuration to read last data
    while (!(TWCR & (1<<TWINT)));
    return TWDR;
}

void iic_set_stop_con(void)
{
    SBI(TWCR, TWINT);
    CBI(TWCR, TWEA);
    CBI(TWCR, TWSTA);
    SBI(TWCR, TWSTO);
    CBI(TWCR, TWWC);
    SBI(TWCR, TWEN); 
    CBI(TWCR, TWIE); 
    //Configuration to STOP
    while (!(TWCR & (1<<TWINT))); //Wait to set con
}

void iic_send_SLA_Wbit(uint8_t data, bool write_bit)
{
    TWDR = data; // Save data in the memory
    TWDR = write_bit ? ((TWDR<<1) | 0b1): TWDR<<1;//Set Write bit
    iic_MTM_set_write_con();
}

void iic_send_data(uint8_t data)
{
    TWDR = data; // save data in the memory
    iic_MTM_set_write_con();

}

void iic_write_to_slave(uint8_t slave, uint8_t *array, uint8_t size, uint8_t address_memory)
{
    #ifndef TEST_TWCR_CON
    iic_set_start_con(); 
    
    iic_send_SLA_Wbit(slave, WRITE_BIT_ON); //Send SLA+W

    iic_send_data(address_memory); //Send slave memory address 

    for (uint16_t i = 0; i < size; i++)
        iic_send_data(array[i]); //Send data IIC 

    iic_set_stop_con();
    #endif

    #ifdef TEST_TWCR_CON
    iic_set_start_con(); //IIC set startn con
    show_TWSR_con();
    
    iic_send_SLA_Wbit(slave, WRITE_BIT_ON); //Send address of slave IIC
    show_TWSR_con(); //Checkout condition 
    
    iic_send_data(0); //Send memory address 
    show_TWSR_con(); //Checkout condition 

    for (uint16_t i = 0; i < size; i++){
        iic_send_data(array[i]); // send data 
        show_TWSR_con(); //Checkout condition 
    }

    iic_set_stop_con(); //IIC set stop con
    show_TWSR_con(); //Checkout condition 
    #endif
}

void iic_read_from_slave(uint8_t slave, uint8_t *array, uint8_t size, uint8_t address_memory)
{
    #ifndef TEST_TWCR_CON
    iic_set_start_con(); 

    iic_send_SLA_Wbit(slave, WRITE_BIT_ON); //Send SLA+W
    
    iic_send_data(address_memory); //Send slave memory address 

    iic_set_stop_con();
    ///////////////////////////////////

    iic_set_start_con();

    iic_send_SLA_Wbit(slave, READ_BIT_ON); //Send SLA+R 

    for (uint8_t i = 0; i < size - 1; i++)
        array[i] = iic_read_data(); //Read data from memory

    array[size - 1] = iic_read_data_last();

    iic_set_stop_con();
    #endif

    #ifdef TEST_TWCR_CON
    iic_set_start_con();
    show_TWSR_con(); //Checkout condition 

    iic_send_SLA_Wbit(slave, WRITE_BIT_ON); //Send address of slave IIC
    show_TWSR_con(); //Checkout condition 
    
    iic_send_data(address_memory); //Send memory address 
    show_TWSR_con(); //Checkout condition 

    iic_set_stop_con(); //IIC set stop con
    show_TWSR_con(); //Checkout condition 

    usart_send_data(G,strlen(G));

    iic_set_start_con(); //IIC set startn con
    show_TWSR_con(); //Checkout condition 

    iic_send_SLA_Wbit(slave, READ_BIT_ON); // send SLA+W
    show_TWSR_con(); //Checkout condition 

    for (uint8_t i = 0; i < size - 1; i++){
        array[i] = iic_read_data();
        show_TWSR_con(); //Checkout condition 
    }

    array[size - 1] = iic_read_data_last();
    show_TWSR_con(); //Checkout condition 

    iic_set_stop_con(); //IIC set stop con
    show_TWSR_con(); //Checkout condition 
    #endif

}
