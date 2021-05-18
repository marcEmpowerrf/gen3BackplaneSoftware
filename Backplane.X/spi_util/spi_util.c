#include <stdio.h>
#include <stdlib.h>
#include "../mcc_generated_files/mcc.h"
#include "spi_util.h"


void  SetSpiMode( SPI_MODE mode )
{
    SPI_DISABLE();
    
    switch(mode)
    {
        case SPI_MODE_0:
            SPI_CLK_MODE_0() ;
            break;
        case SPI_MODE_1:
            SPI_CLK_MODE_1() ;
            break;
        case SPI_MODE_2 :
            SPI_CLK_MODE_2();
            break;
        case SPI_MODE_3:
            SPI_CLK_MODE_3(); 
            break;
    }
    SPI_ENABLE();
        
}