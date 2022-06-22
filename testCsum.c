#include<stdio.h>
#include<string.h>
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

uint16 prasedate(uint8 *data,uint16 len ,char *destArr);

uint16 stringToHexArr(char *str,uint16 len, uint8 *HexArr);

int main(void)
{

    FILE *fp;
    char buf[64];
    int readlen=0;
    int row =1;
    char desArr[64];
    uint8 deslen;

    fp = fopen("./HelTec.hex","r");
    if(fp==NULL)
        perror("error open");
    /* read a line */

    while(fgets(buf,64,fp)!=NULL){    // switch the line ASCII to HEX data 

        //printf("the len of the buf is %d\n",strlen( buf));
        deslen=prasedate(buf,strlen(buf),desArr);
        printf("%d:%s\n",deslen,desArr);
        // puts(buf);
    }
    uint8 mydata[]={0x02,0x00,0x00,0x04,0x08,0x00};
    uint8 checksum=0 ;
    int i=0;

    for( i=0;i<sizeof(mydata);i++)
    {
        checksum +=mydata[i];

    }

    printf("%s>befor checksum = 0x%x\n",__TIME__,checksum);


    checksum = 0x100 - checksum;


    printf("%s>after buma the check sum = 0x%x\n",__TIME__,checksum);

    fclose(fp);

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


uint16 stringToHexArr(char *str,uint16 len, uint8 *HexArr)
{


}