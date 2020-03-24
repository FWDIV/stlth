
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
         printf("perfect memcpy\n");
         memcpy(Dest,Source,(bits/8));
     }
     else
     {
         printf("rmndr %d\n",rmndr);
         memcpy(Dest,Source,(bits/8)+1) ;
         char f = *(Source + (bits/8));
         f=f >> 8-rmndr;
         f=f << 8-rmndr;

         *(Dest +bits/8)= f;

            }
 }

 void test(int t_number, char * expected_val,
             void * dst, void * src, unsigned int bit_size)
 {   printf("test :%d\n",t_number);
     bitcpy(dst,src,bit_size);
     char * v = (char *)dst ;
     char * t = expected_val ;
     printf("expected val= %s : test val = %s\n", t, v);
     assert(  strcmp(v,t) == 0 );
     printf("...Passed!\n");
     printf("\n");

  }

 void tests(){
     printf("loading tests...");
     char src[26] = "abcdefghijklmnopqrstuvwxyz"; //Source String
     char dst[26] = {0}; //dst buffer
     printf("string = %s\n", dst);

     test(1,"abb",dst,src,23);
     test(2,"abcdd",dst,src,39);
     test(3,"abcded",dst,src,46);
     test(4,"abcdefd",dst,src,54);
     test(5,"abcdefghh",dst,src,71);
 }
 /***
  * void test(int t_number,expected_val,dst,src,bit_size)
  * Ascii Table
  * :a	097	01100001	A	065	01000001
  * b	098	01100010	B	066	01000010
  * c	099	01100011	C	067	01000011
  * d	100	01100100	D	068	01000100
  * e	101	01100101	E	069	01000101
  * f	102	01100110	F	070	01000110
  * g	103	01100111	G	071	01000111
  * h	104	01101000	H	072	01001000
  * i	105	01101001	I	073	01001001
  * j	106	01101010	J	074	01001010
  * k	107	01101011	K	075	01001011
  * l	108	01101100	L	076	01001100
  * m	109	01101101	M	077	01001101
  * n	110	01101110	N	078	01001110
  * o	111	01101111	O	079	01001111
  * p	112	01110000	P	080	01010000
  * q	113	01110001	Q	081	01010001
  * r	114	01110010	R	082	01010010
  * s	115	01110011	S	083	01010011
  * t	116	01110100	T	084	01010100
  * u	117	01110101	U	085	01010101
  * v	118	01110110	V	086	01010110
  * w	119	01110111	W	087	01010111
  * x	120	01111000	X	088	01011000
  * y	121	01111001	Y	089	01011001
  * z	122	01111010	Z	090	01011010
  * */



 int main()
 {

     //copy source buffer int dst
     tests();
     return 0;
 }
