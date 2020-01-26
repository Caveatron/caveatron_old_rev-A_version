// *** Hardwarespecific defines ***
#define cbi(reg, bitmask) *reg &= ~bitmask
#define sbi(reg, bitmask) *reg |= bitmask

#define regtype volatile uint32_t
#define regsize uint32_t

#define FLASH_CS_PIN 52
