#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

uint16 prasedate(uint8 *data,uint16 len ,char *destArr);

uint16 stringToHexArr(char *str,uint16 len, uint8 *HexArr);

int main(void)
{

    FILE *fp;
    FILE *fp2;
    char buf[64];
    int readlen=0;
    int row =1;
    char desArr[64];
    uint8 deslen;
    uint8 HexResArr[64];
    uint16 datlen;

    fp = fopen("./HelTec.hex","r");
    if(fp==NULL)
    {
        perror("error open");
        return -1;

    } 
    fp2= fopen("./HelTec.bin","wb");
    if(fp2==NULL)
    { 
        perror("error open");
        return -1;
    }
    /* read a line */

    while(fgets(buf,64,fp)!=NULL){    // switch the line ASCII to HEX data 

        //printf("the len of the buf is %d\n",strlen( buf));
        deslen=prasedate(buf,strlen(buf),desArr);
        datlen=stringToHexArr(desArr,deslen,HexResArr);
        for(int j=0;j<datlen;j++)
        {
            printf("%02x ",HexResArr[j]);
        }
       
        printf("\n");
        if(datlen ==16)
        fwrite(HexResArr,sizeof(char),datlen,fp2);
        // printf("%d:%s\n",deslen,desArr);
        // puts(buf);
    }
    // uint8 mydata[]={0x02,0x00,0x00,0x04,0x08,0x00};
    // uint8 checksum=0 ;
    // int i=0;

    // for( i=0;i<sizeof(mydata);i++)
    // {
    //     checksum +=mydata[i];

    // }

    // printf("%s>befor checksum = 0x%x\n",__TIME__,checksum);


    // checksum = 0x100 - checksum;


    // printf("%s>after buma the check sum = 0x%x\n",__TIME__,checksum);

    fclose(fp);
    fclose(fp2);

    return 0;
}


uint16 prasedate(uint8 *data,uint16 len,char *destArr)
{

    if(data ==NULL||len ==0)
        return 0;
    if(*data ==':')
    {
       memcpy(destArr,data+9,len-12);
    } 
    destArr[len-11]='\0';
   return strlen(destArr);

}

uint8 charToByte(char c)
{
    if('0'<= c && c <='9')
        return c -'0';
    if( ('a'<=c && c <='f') || ('A'<=c && c <='F'))
        return toupper(c)-'A'+0x0a;
}
//每次传入数组为2的字符串，然后拼接成 一个十六进制数。
uint8 GetHex(uint8 *Asc)
{
    uint8 Hex;
    Hex =(Asc[0]&0x0f)<<4;
    if(Asc[0]>='A') Hex+=0x90;
        Hex |=(Asc[1]&0x0f);
    if(Asc[1]>='A') Hex+=0x90;
        
    return Hex;

}


uint16 stringToHexArr(char *str,uint16 len, uint8 *HexArr)
{
    if(str==NULL|| len ==0|| HexArr==NULL)
        return 0;
    
    for(int i=0; i < len/2; i++)
    {
        HexArr[i] = (charToByte(*str++))<<4;
        HexArr[i] += charToByte(*str++);
    }
    
    return len /2;

}