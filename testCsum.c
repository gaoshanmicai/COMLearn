#include<stdio.h>
#include<string.h>
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;


int main(void)
{

    FILE *fp;
    char buf[64];
    int readlen=0;

    fp = fopen("./HelTec.hex","r");
    if(fp==NULL)
        perror("error open");
    /* read a line */

    fgets(buf,64,fp);
    // switch the line ASCII to HEX data 

    



    printf("the len of the buf is %d\n",strlen( buf));
    puts(buf);
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

    return 0;
}