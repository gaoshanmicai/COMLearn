#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include<time.h>

// int main(int argc, const char * argv[])

// {

// time_t t;

// time(&t);

// struct tm *tmp_time = localtime(&t);

// char s[100];

// strftime(s, sizeof(s), "%04Y%02m%02d %H:%M:%S", tmp_time);

// printf("%d: %s\n", (int)t, s);

// return 0;

// }


int main(int argc, const char * argv[])

{

    struct tm* tmp_time = (struct tm*)malloc(sizeof(struct tm));
    char t1[20] ="2016/08/13/06/12";

    strptime(t1,sizeof(t1)/sizeof(t1[0]),"%Y/%m/%d/%H/%M",tmp_time); 
    time_t t = mktime(tmp_time);//按当地时区解析tmp_time

    printf("%ld\n",t);

    free(tmp_time);

}


unsigned long ReadCount(void){ 
    unsigned long Count; 
    unsigned char i; 
    hx711_clk_l; 
    Count=0; 
    while(hx711_dout); 
    for (i=0;i<24;i++)
    { 
        hx711_clk_h;
        Count=Count<<1;
        hx711_clk_l; 
        if(hx711_dout) 
        Count++; 
    }
    hx711_clk_h;
    Count=Count^0x800000; 
    hx711_clk_l; 
    return(Count); 
 }