/*
 *    Basado en https://github.com/wayoda/LedControl
 *    A library for controling Leds with a MAX7219/MAX7221
 *    Copyright (c) 2007 Eberhard Fahle
 * 
 *    Permission is hereby granted, free of charge, to any person
 *    obtaining a copy of this software and associated documentation
 *    files (the "Software"), to deal in the Software without
 *    restriction, including without limitation the rights to use,
 *    copy, modify, merge, publish, distribute, sublicense, and/or sell
 *    copies of the Software, and to permit persons to whom the
 *    Software is furnished to do so, subject to the following
 *    conditions:
 * 
 *    This permission notice shall be included in all copies or 
 *    substantial portions of the Software.
 * 
 *    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 *    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 *    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *    NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 *    HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 *    WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *    FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *    OTHER DEALINGS IN THE SOFTWARE.
 */

// https://xantorohara.github.io/led-matrix-editor/#0033333f33331e0c|003f66663e66663f|003c66030303663c|001f36666666361f|007f46161e16467f|000f06161e16467f|007c66730303663c|003333333f333333|001e0c0c0c0c0c1e|001e333330303078|006766361e366667|007f66460606060f|0063636b7f7f7763|006363737b6f6763|001c36636363361c|000f06063e66663f|00381e3b3333331e|006766363e66663f|001e33380e07331e|001e0c0c0c0c2d3f|003f333333333333|000c1e3333333333|0063777f6b636363|0063361c1c366363|001e0c0c1e333333|007f664c1831637f|0000000000000000|006e333e301e0000|003b66663e060607|001e3303331e0000|006e33333e303038|001e033f331e0000|000f06060f06361c|1f303e33336e0000|006766666e360607|001e0c0c0c0e000c|1e33333030300030|0067361e36660607|001e0c0c0c0c0c0e|00636b7f7f330000|00333333331f0000|001e3333331e0000|0f063e66663b0000|78303e33336e0000|000f06666e3b0000|001f301e033e0000|00182c0c0c3e0c08|006e333333330000|000c1e3333330000|00367f7f6b630000|0063361c36630000|1f303e3333330000|003f260c193f0000

#ifndef MatrizLed_h
#define MatrizLed_h

#include <avr/pgmspace.h>
#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

// rotar imagenes
// https://gist.github.com/danidask/f11126a3e5220f0a9f68be37008e6ef8

const static byte tablaCaracteresMayuscula [] PROGMEM  = {
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110,

  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01100110,
  B01100110,
  B01111100,

  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01100000,
  B01100110,
  B00111100,

  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01111100,

  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01111110,

  B00000000,
  B01111110,
  B01100000,
  B01100000,
  B01111100,
  B01100000,
  B01100000,
  B01100000,

  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100000,
  B01101110,
  B01100110,
  B00111100,

  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01111110,
  B01100110,
  B01100110,
  B01100110,

  B00000000,
  B00111100,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00111100,

  B00000000,
  B00011110,
  B00001100,
  B00001100,
  B00001100,
  B01101100,
  B01101100,
  B00111000,

  B00000000,
  B01100110,
  B01101100,
  B01111000,
  B01110000,
  B01111000,
  B01101100,
  B01100110,

  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01100000,
  B01111110,

  B00000000,
  B01100011,
  B01110111,
  B01111111,
  B01101011,
  B01100011,
  B01100011,
  B01100011,

  B00000000,
  B01100011,
  B01110011,
  B01111011,
  B01101111,
  B01100111,
  B01100011,
  B01100011,

  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100,

  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000,

  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01100110,
  B01101110,
  B00111100,
  B00000110,

  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01111000,
  B01101100,
  B01100110,

  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B00111100,
  B00000110,
  B01100110,
  B00111100,

  B00000000,
  B01111110,
  B01011010,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,

  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111110,

  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111100,
  B00011000,

  B00000000,
  B01100011,
  B01100011,
  B01100011,
  B01101011,
  B01111111,
  B01110111,
  B01100011,

  B00000000,
  B01100011,
  B01100011,
  B00110110,
  B00011100,
  B00110110,
  B01100011,
  B01100011,

  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B00111100,
  B00011000,
  B00011000,
  B00011000,

  B00000000,
  B01111110,
  B00000110,
  B00001100,
  B00011000,
  B00110000,
  B01100000,
  B01111110
};

const static byte tablaCaracteresMinuscula [] PROGMEM  = {
B00000000,
  B00000000,
  B00000000,
  B00111100,
  B00000110,
  B00111110,
  B01100110,
  B00111110,

  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,

  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01100110,
  B00111100,

  B00000000,
  B00000110,
  B00000110,
  B00000110,
  B00111110,
  B01100110,
  B01100110,
  B00111110,

  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B01100110,
  B01111110,
  B01100000,
  B00111100,

  B00000000,
  B00011100,
  B00110110,
  B00110000,
  B00110000,
  B01111100,
  B00110000,
  B00110000,

  B00000000,
  B00000000,
  B00111110,
  B01100110,
  B01100110,
  B00111110,
  B00000110,
  B00111100,

  B00000000,
  B01100000,
  B01100000,
  B01100000,
  B01111100,
  B01100110,
  B01100110,
  B01100110,

  B00000000,
  B00000000,
  B00011000,
  B00000000,
  B00011000,
  B00011000,
  B00011000,
  B00111100,

  B00000000,
  B00001100,
  B00000000,
  B00001100,
  B00001100,
  B01101100,
  B01101100,
  B00111000,

  B00000000,
  B01100000,
  B01100000,
  B01100110,
  B01101100,
  B01111000,
  B01101100,
  B01100110,

  B00000000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,
  B00011000,

  B00000000,
  B00000000,
  B00000000,
  B01100011,
  B01110111,
  B01111111,
  B01101011,
  B01101011,

  B00000000,
  B00000000,
  B00000000,
  B01111100,
  B01111110,
  B01100110,
  B01100110,
  B01100110,

  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B01100110,
  B00111100,

  B00000000,
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01111100,
  B01100000,
  B01100000,

  B00000000,
  B00000000,
  B00111100,
  B01101100,
  B01101100,
  B00111100,
  B00001101,
  B00001111,

  B00000000,
  B00000000,
  B00000000,
  B01111100,
  B01100110,
  B01100110,
  B01100000,
  B01100000,

  B00000000,
  B00000000,
  B00000000,
  B00111110,
  B01000000,
  B00111100,
  B00000010,
  B01111100,

  B00000000,
  B00000000,
  B00011000,
  B00011000,
  B01111110,
  B00011000,
  B00011000,
  B00011000,

  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B01100110,
  B01100110,
  B01100110,
  B00111110,

  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B01100110,
  B00111100,
  B00011000,

  B00000000,
  B00000000,
  B00000000,
  B01100011,
  B01101011,
  B01101011,
  B01101011,
  B00111110,

  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B00111100,
  B00011000,
  B00111100,
  B01100110,

  B00000000,
  B00000000,
  B00000000,
  B01100110,
  B01100110,
  B00111110,
  B00000110,
  B00111100,

  B00000000,
  B00000000,
  B00000000,
  B00111100,
  B00001100,
  B00011000,
  B00110000,
  B00111100
};

const static byte tablaNumeros [] PROGMEM  = {
  B00000000,
  B00111100,  
  B01100110,  
  B01101110,  
  B01110110,  
  B01100110,  
  B01100110,  
  B00111100,

  B00000000,  
  B00011000,  
  B00011000,  
  B00111000,  
  B00011000,  
  B00011000,  
  B00011000,  
  B01111110,  

  B00000000,  
  B00111100,  
  B01100110,  
  B00000110,  
  B00001100,  
  B00110000,  
  B01100000,  
  B01111110,  

  B00000000,  
  B00111100,  
  B01100110,  
  B00000110,  
  B00011100,  
  B00000110,  
  B01100110,  
  B00111100,
  
  B00000000,
  B00001100,
  B00011100,
  B00101100,
  B01001100,
  B01111110,
  B00001100,
  B00001100,

  B00000000,
  B01111110,
  B01100000,
  B01111100,
  B00000110,
  B00000110,
  B01100110,
  B00111100,

  B00000000,
  B00111100,
  B01100110,
  B01100000,
  B01111100,
  B01100110,
  B01100110,
  B00111100,

  B00000000,
  B01111110,
  B01100110,
  B00001100,
  B00001100,
  B00011000,
  B00011000,
  B00011000,

  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B00111100,
  B01100110,
  B01100110,
  B00111100,

  B00000000,
  B00111100,
  B01100110,
  B01100110,
  B00111110,
  B00000110,
  B01100110,
  B00111100
};


class MatrizLed {
    private :
        /* The array for shifting the data to the devices */
        byte spidata[16];
        /* Send out a single command to the device */
        void spiTransfer(int addr, byte opcode, byte data);
        /* We keep track of the led-status for all 8 devices in this array */
        byte status[64];
        /* Data is shifted out of this pin*/
        int SPI_MOSI;
        /* The clock is signaled on this pin */
        int SPI_CLK;
        /* This one is driven LOW for chip selectzion */
        int SPI_CS;
        /* The maximum number of devices we use */
        int maxDevices;
        int modelo = 0;
        void rotarCodigo(byte[8]);
        void rotar_horario_codigo(byte[8]);
        void rotar_antihorario_codigo(byte[8]);
        void espejo_codigo(byte[8]);

    public:
        /* 
         * Create a new controler 
         * Params :
         * dataPin		pin on the Arduino where data gets shifted out
         * clockPin		pin for the clock
         * csPin		pin for selecting the device 
         * numDevices	maximum number of devices that can be controled
         */
        MatrizLed();
        void begin(int dataPin, int clkPin, int csPin, int numDevices=1);
        void setRotacion(int);
        void setModelo(int);
        void escribirCaracter(char, int);
        void escribirFrase(const char*, int=0);
        void escribirFrase(const String, int=0);
        void escribirCifra(int, int=0);
        void escribirFraseScroll(const char*, unsigned long=0);
        void escribirFraseCompacta(const char*, int=0);
        void escribirFraseCompactaScroll(const char*, unsigned long=0);
        void borrar();
        void setIntensidad(int);
        void apagar();
        void encender();
        void escribirBits(const byte[8], int=0);
        void obtenerBitsCaracter(char, byte[8]);
        void obtenerSecuenciaTabla(byte[], int, byte[8]);

        /*
         * Gets the number of devices attached to this MatrizLed.
         * Returns :
         * int	the number of devices on this MatrizLed
         */
        int getDeviceCount();

        /* 
         * Set the shutdown (power saving) mode for the device
         * Params :
         * addr	The address of the display to control
         * status	If true the device goes into power-down mode. Set to false
         *		for normal operation.
         */
        void shutdown(int addr, bool status);

        /* 
         * Set the number of digits (or rows) to be displayed.
         * See datasheet for sideeffects of the scanlimit on the brightness
         * of the display.
         * Params :
         * addr	address of the display to control
         * limit	number of digits to be displayed (1..8)
         */
        void setScanLimit(int addr, int limit);

        /* 
         * Set the brightness of the display.
         * Params:
         * addr		the address of the display to control
         * intensity	the brightness of the display. (0..15)
         */
        void setIntensity(int addr, int intensity);

        /* 
         * Switch all Leds on the display off. 
         * Params:
         * addr	address of the display to control
         */
        void clearDisplay(int addr);

        /* 
         * Set the status of a single Led.
         * Params :
         * addr	address of the display 
         * row	the row of the Led (0..7)
         * col	the column of the Led (0..7)
         * state	If true the led is switched on, 
         *		if false it is switched off
         */
        void setLed(int addr, int row, int col, bool state=1);

        /* 
         * Set all 8 Led's in a row to a new state
         * Params:
         * addr	address of the display
         * row	row which is to be set (0..7)
         * value	each bit set to 1 will light up the
         *		corresponding Led.
         */
        void setRow(int addr, int row, byte value);

        /* 
         * Set all 8 Led's in a column to a new state
         * Params:
         * addr	address of the display
         * col	column which is to be set (0..7)
         * value	each bit set to 1 will light up the
         *		corresponding Led.
         */
        void setColumn(int addr, int col, byte value);

};

#endif	//MatrizLed.h
