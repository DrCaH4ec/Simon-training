#ifndef RTC
#define RTC

#include <avr/io.h>
#include <stdint.h>
#include <string.h>
#include <iic.h>

#define ASCII_0 48
#define RTC_HOURS_MINUTES_SECOND 3
#define RTC_HMS RTC_HOURS_MINUTES_SECOND
#define SHIFT_TO_SET_TENS 4
#define SHIFT_TENS SHIFT_TO_SET_TENS
#define MEMORY_POS_HMS 0
#define UNITS_BIT_POS_HOURS_MINUTES_SECOND 0b00001111
#define UBP_HMS UNITS_BIT_POS_HOURS_MINUTES_SECOND

void rtc_set_time(const char *time, const uint8_t address_of_ds3231);
char *rtc_get_time(char *time_str, const uint8_t address_of_ds3231);

#endif
