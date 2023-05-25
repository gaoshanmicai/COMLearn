#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <time.h>
	
long long get_timestamp(void)//获取时间戳函数
{
    long long tmp;
    struct timeval tv;

    gettimeofday(&tv, NULL);
    tmp = tv.tv_sec;
    tmp = tmp * 1000;
    tmp = tmp + (tv.tv_usec / 1000);

    return tmp;
}

void get_format_time_string(char *str_time) //获取格式化时间
{
	time_t now;
    struct tm *tm_now;
    char datetime[128];
 
    time(&now);
    tm_now = localtime(&now);
    strftime(datetime, 128, "%Y-%m-%d %H:%M:%S", tm_now);
 
    printf("now datetime : %s\n", datetime);
	strcpy(str_time, datetime);
}

void get_format_time_ms(char *str_time) { 
    struct tm *tm_t;
    struct timeval time;
    
    if (sizeof(str_time) < 32) {
	printf("input buff len less than 32");	
	return;
	}
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

int main()
{
	char *format_time_string[128] = {0};
	long long curr_time = (long long)get_timestamp();
	get_format_time_string((char *)format_time_string);
	printf("timestamp:%lld, format time:%s",curr_time,format_time_string);
	return 0;
}