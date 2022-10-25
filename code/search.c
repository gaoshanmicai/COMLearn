#include<string.h>
#include<stdio.h>

int main(void)
{
    char myData[]="cEDdjbiheagmrRwxszItVqABCyyy{}JPfT";
    char *ptr;
    unsigned char barcodeType[]=
    {0xA0,0xE0,0xFF,0xE1,0xB3,0xB1,0xB6,0xC1,0xB2,0xB7,0xB8,0xB4,0xC7,0xC8,0xD0,0xD2,0xD1,0xD3,0xC9,0xC6};
    int ch;
    int count=0;
    printf("please input a character:\n");
    scanf("%c",&ch);
    ptr =myData;
    
   ptr = strchr(myData,ch);
   count =ptr -myData;
    printf("mydata[%d]=%c,barcodeypte = 0x%x \n",count,myData[count],barcodeType[count]);
    return 0;

}