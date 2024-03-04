#include "numerals.h"

#include <stdio.h>

uint8_t numeral_in[MAX_POS];
uint8_t numeral_out[MAX_POS];

void main(int argc, char **argv)
{   
    int8_t radix=0;
    if (argc<2){
        printf("USAGE: %s <ID>\n",argv[0]);
        return;
    }

    radix=id_string_to_numeral(argv[1],(uint8_t *)numeral_in);

    if (radix < 0)
    {
        printf("Invalid input!\n");
        return;
    }
    __uint128_t id = numeral_to_uint((uint8_t *)numeral_in,radix) + 1;
    
    printf("ID:%llu\n",id);
    printf("RADIX:%d NUMERALS:",radix);
    for (size_t i = 0; i < MAX_POS; i++)
    {
        printf("%d:%d ",i, numeral_in[i]);
    }
    printf("\n");

    printf("DEC: %llu\n",id);

    radix = uint_to_numeral(id,(uint8_t *)numeral_out);

    char ans[50]={0};

    numeral_to_id_string(ans,(uint8_t *)numeral_out,radix);

    printf("OUTPUT: %s\n",ans);
    return;
    
}