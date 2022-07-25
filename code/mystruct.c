
#include<stdio.h>
#include<string.h>



#define MAX_READER_COUNT 128

#define INV_POS (unsigned long)-1

struct disruptor
{
    unsigned long write_pos;
    unsigned long slowest_read_pos;
    unsigned long max_readable_pos;
    unsigned long read_pos[MAX_READER_COUNT];
    unsigned int reader_cnt;

    char* data_buf;
    unsigned int data_item_size;

    /* data_item_count must be a power of 2 */
    unsigned long data_item_count;
    unsigned long mask;
};


int main(void)
{
    struct disruptor *dis;

    printf("the size of unsigned long %d\n",sizeof(unsigned long));

    printf(" the size of dis = %d\n",sizeof(struct disruptor));

    
    
    return 0;

}