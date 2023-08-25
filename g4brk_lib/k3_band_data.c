// This is firmware for the Hermes Lite 2 IO board designed by Jim Ahlstrom, N2ADR. It is
//   Copyright (c) 2022-2023 James C. Ahlstrom <jahlstr@gmail.com>.
//   It is licensed under the MIT license. See MIT.txt.
// This function for K3-compatible band data output by Neil Whiting, G4BRK

// Output data on connector J4 pin 8 according to the band.
// Pin details and wiring:
// K3 signal  HL2 GPIO      HL2IO    HL2 ACC
// band0 out  GPIO16_Out1   J4  1    1
// band1 out  GPIO19_Out2   J4  2    2
// band2 out  GPIO20_Out3   J4  3    3
// band3 out  GPIO11_Out4   J4  4    4
// digout0    GPIO10_Out5   J6  5    5
// Keyout-lp  GPIO22_Out6   J6  6    6
// 
// 

#include "../hl2ioboard.h"

void k3_band_data(uint8_t fcode)	// 
// Band    160     80     60     40     30     20     17     15     12     10      6      4      2   70cm   23cm   13cm    9cm    6cm    3cm
// BandData  1      2      0      3      4      5      6      7      8      9      1      2      3      4      5      6      7      8      9
// Digout0   0      0      0      0      0      0      0      0      0      0      1      1      1      1      1      1      1      1      1
{

	static uint8_t banddata = 0;
	static uint8_t digout0  = 0;
	
	switch (fcode) {
	    case BAND_160:     banddata =  1; digout0  = 0; break;
	    case BAND_80:      banddata =  2; digout0  = 0; break;        
	    case BAND_60:      banddata =  0; digout0  = 0; break;
	    case BAND_40:      banddata =  3; digout0  = 0; break;        
	    case BAND_30:      banddata =  4; digout0  = 0; break;        
	    case BAND_20:      banddata =  5; digout0  = 0; break;        
	    case BAND_17:      banddata =  6; digout0  = 0; break;        
	    case BAND_15:      banddata =  7; digout0  = 0; break;        
	    case BAND_12:      banddata =  8; digout0  = 0; break;        
	    case BAND_10:      banddata =  9; digout0  = 0; break;        
	    case BAND_6:       banddata =  1; digout0  = 1; break;        
	    case BAND_4:       banddata =  2; digout0  = 1; break;        
	    case BAND_2:       banddata =  3; digout0  = 1; break;        
	    case BAND_70cm:    banddata =  4; digout0  = 1; break;
	    case BAND_23cm:    banddata =  5; digout0  = 1; break;
	    case BAND_13cm:    banddata =  6; digout0  = 1; break;
	    case BAND_9cm:     banddata =  7; digout0  = 1; break;
	    case BAND_5cm:     banddata =  8; digout0  = 1; break;
	    case BAND_3cm:     banddata =  9; digout0  = 1; break;
	    default:           banddata = 11; digout0  = 0; break;
	}
	gpio_put(GPIO10_Out5, digout0  & 0x01);
	gpio_put(GPIO16_Out1, banddata & 0x01);
	gpio_put(GPIO19_Out2, banddata & 0x02);
	gpio_put(GPIO20_Out3, banddata & 0x04);
	gpio_put(GPIO11_Out4, banddata & 0x08);
}

