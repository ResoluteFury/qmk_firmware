#include "lightcycle.h"
#include "i2cmaster.h"


bool i2c_initialized = 0;
uint8_t mcp23018_status = 0x20;

void matrix_init_kb(void) {
    init_lightcycle();
    matrix_init_user();
}


uint8_t init_lightcycle(void)
{
    debug_enable=true;
    init_teensy();
    return init_mcp23018();
}


uint8_t init_mcp23018(void)
{
    mcp23018_status = 0x20;

    // I2C subsystem

    if (i2c_initialized == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
        _delay_ms(1000);
    }

    // set pin direction
    // - unused  : input  : 1
    // - input   : input  : 1
    // - driving : output : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(IODIRA);            if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0xFF);              if (mcp23018_status) goto out;  // IODIRA
    mcp23018_status = i2c_write(0xE0);              if (mcp23018_status) goto out;  // IODIRB
    i2c_stop();

    // set pull-up
    // - unused  : on  : 1
    // - input   : on  : 1
    // - driving : off : 0
    mcp23018_status = i2c_start(I2C_ADDR_WRITE);    if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(GPPUA);             if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0xFF);              if (mcp23018_status) goto out;
    mcp23018_status = i2c_write(0xE0);              if (mcp23018_status) goto out;

out:
    i2c_stop();

    return mcp23018_status;
}

void init_teensy(void)
{
    /* Rows are outputs, Columns are inputs w/ pull-up resistor
        Rows: PF0..1, PF4..6
        Columns: PB0..3, PD2..3
        DDRx 0:input, 1: output
        PORTx for inputs(0: pull-up resistor disabled, 1: pull-up resistor enabled)
        PORTx for outputs(0: output LOW, 1: output HIGH)
    */
    DDRB  &= ~(1<<4);  // set B(4) as input
    PORTB &= ~(1<<4);  // set B(4) internal pull-up disabled

    // unused pins - C7, D4, D5, D7, E6
    // set as input with internal pull-up enabled
    DDRC  &= ~(1<<7);
    PORTC |=  (1<<7);
    DDRD  &= ~(1<<5 | 1<<4);
    PORTD |=  (1<<5 | 1<<4);
    DDRE  &= ~(1<<6);
    PORTE |=  (1<<6);

    // Rows
    // Output (DDRx 1)
    DDRF  |= (1<<0 | 1<<1 | 1<<4 | 1<<5 | 1<<6);

    // High (PORTx 1)
    PORTF |= (1<<0 | 1<<1 | 1<<4 | 1<<5 | 1<<6);
    //PORTF &= ~(1<<0 | 1<<1 | 1<<4 | 1<<5 | 1<<6);
    
    // Columns
    // Input (DDRx 0)
    DDRB  &= ~(1<<0 | 1<<1 | 1<<2 | 1<<3);
    DDRD  &= ~(1<<2 | 1<<3);

    // With Pull-Up Resistor (PORTx 1)
    PORTB |= (1<<0 | 1<<1 | 1<<2 | 1<<3);
    PORTD |= (1<<2 | 1<<3);
}