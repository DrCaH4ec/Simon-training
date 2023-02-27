#include <rtc.h>

static char *decode_to_srt(char *time_str, const uint8_t *time_rtc)
{
    /* time_str must be appearance "00:00:00\0"*/ 
    for (uint8_t i = 0; i < RTC_HMS; i++){
        time_str[i * 3] = (time_rtc[RTC_HMS - 1 - i]>>SHIFT_TENS) + ASCII_0;
        time_str[i * 3 + 1] = (time_rtc[RTC_HMS - 1 - i] & UBP_HMS) + ASCII_0;
        if (i != RTC_HMS - 1)
            time_str[i * 3 + 2] = ':';
        else
            time_str[i * 3 + 2] = '\0';
    }

    return time_str;
}

char *rtc_get_time(char *time_str, const uint8_t address_of_ds3231)
{
    uint8_t time_rtc[RTC_HMS];

    iic_read_from_slave(address_of_ds3231, time_rtc, RTC_HMS, 0);

    return decode_to_srt(time_str, time_rtc);
}

void rtc_set_time(const char *time_str, const uint8_t address_of_ds3231)
{
    uint8_t time_rtc[RTC_HMS];

    time_rtc[0] = ((time_str[6] - ASCII_0)<<SHIFT_TENS) | (time_str[7] - ASCII_0);
    time_rtc[1] = ((time_str[3] - ASCII_0)<<SHIFT_TENS) | (time_str[4] - ASCII_0);
    time_rtc[2] = ((time_str[0] - ASCII_0)<<SHIFT_TENS) | (time_str[1] - ASCII_0);

    iic_write_to_slave(address_of_ds3231, time_rtc, RTC_HMS, MEMORY_POS_HMS);
}
