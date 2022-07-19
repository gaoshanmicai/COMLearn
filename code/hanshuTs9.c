#include<stdio.h>
#include<string.h>
#include<ctype.h>


typedef enum bool{
    False=0,
    True
}BOOL;

int count_chars(char const *str,char const *chars)
{
    register char *current;
    register char  *last ;
    int count =0;
    if(str == NULL ||chars== NULL)
        return -1;
   
    if(*chars !='\0')
    {
        current = strstr(str,chars);
        while(current!=NULL)
        {
            last = current;
            current = strstr(last+1,chars);
            count++;
        }
    }


    return count;


}
// 检查一个字符串是否是回文数
// 1 检查字符串从左到右读与从右到左读是一致的 
// 2 忽略掉所有非字母字符 
// 3 正在比较的字符忽略大小写 
// abcddcba  另外一种是 abcdedcbA
BOOL palindrom(char *string)
{
    int len =0;
    char *p;
    int count =0;
    len = strlen(string);//len 不能以这个长度为主 ，因为可能包含，。等不可打印的字符
    
    
    p =(char*)malloc(sizeof(char)*len);

    for(int j =0; j < len;j++){
        if(isalpha(string[j]))
          {
              p[count] = string[j];
              count++;
          }
       
    }
    p[count] ='\0';
    puts(p);
    
    int dlen = strlen(p);

    for(int i =0; i<dlen/2;i++)
    {
        if(toupper(p[i])==toupper(p[dlen -1-i]))
            continue;
        else
            return False;
    }

    free(p);
    p=NULL;
    return True;      

}

int main(void)
{
    BOOL ret=True;
    char *mesg = " the bee is in the tree, the flower is in the grass,my the data\n";
    char *serch = "the";
    char *theDesstr=    "kkmadam,I'm AdamKK";
    int theSerCount =0;
    theSerCount = count_chars(mesg,serch);
#if 0
    printf(" the search word 'the' in the mesg is %d time\n",theSerCount);
    if(ret)
    {
        printf("this is true\n");

    }
    else{
        printf("this is false\n");
    }
#endif

    if( palindrom(theDesstr))
        printf("Yes it is\n");
    else
        printf("NO it isn't\n");

    return 0;
}