#include <stdio.h>
#include <time.h>
#include <sys/time.h>

void get_format_time_st(time_t t, char *pcTime)
{
  struct tm *tm_t;
  tm_t = localtime(&t);
  strftime(pcTime,128,"%FT%T+0800",tm_t);
}

void get_format_time_ms(char *str_time) { 
    struct tm *tm_t;
    struct timeval time;
    
    gettimeofday(&time,NULL);
    tm_t = localtime(&time.tv_sec);
    if(NULL != tm_t) {
        sprintf(str_time,"%04d-%02d-%02d %02d:%02d:%02d.%03ld",
            tm_t->tm_year+1900,
            tm_t->tm_mon+1, 
            tm_t->tm_mday,
            tm_t->tm_hour, 
            tm_t->tm_min, 
            tm_t->tm_sec,
            time.tv_usec/1000);
    }
    
    return;
}

int main(void) { 
    // unsigned long long curr_time = 1610617450;
    char time_str[256] = {0};
    // time_t time = (time_t)curr_time;

    get_format_time_ms(time_str);
   // get_format_time_st(time, (char *)time_str);
	printf("%s",time_str);
	return 0;
}