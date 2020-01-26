// *** Hardwarespecific defines ***
#define cbi(reg, bitmask) *reg &= ~bitmask
#define sbi(reg, bitmask) *reg |= bitmask

#define regtype volatile uint8_t
#define regsize uint8_t

#define FLASH_CS_PIN 45
