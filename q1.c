
/***
 *  Author Frederick Driver
 *  Date-time: March 24th 1pm
 **/

#include <stdio.h>
#include <string.h>
#include <assert.h> 

void * bitcpy(void * dst, void * src, unsigned int bits)
/***
 *  bitcpy - copies bits from a source address to a destination address
 *          parameters: destination, source, number of bits to copy
 *          in situations in which bits is not divisible by 8, the 
 *          remaining bits are filled with 0's
 **/
{
    char *Dest = (char *)dst;
    const char *Source =( const char*)src;

    unsigned int bytes = 0;
    int rmndr = bits%8;
    if (rmndr == 0) {
        memcpy(Dest,Source,(bits/8));
    }
    else
    {
        memcpy(Dest,Source,(bits/8)+1) ; 
        char f = *(Source + (bits/8));
        f=f >> 1;
        f=f <<1;

        *(Dest +bits/8)= f;

           }
}

void test(){
    printf("loading tests...");
    char src[26] = "abcdefghijklmnopqrstuvwxyz"; //Source String
    char dst[26] = {0}; //dst buffer
    printf("string = %s\n", dst);


    printf("test1\n");
    printf("expected val= abb : test val = %s\n", dst);


    bitcpy(dst,src,23);
    char * v = (dst) ;
    char * t = "abb" ;
    assert(  strcmp(v,t) == 0 );
    
    printf("test2, more tests incoming\n");

}



int main()
{

    //copy source buffer int dst
    test();
    return 0;
}