#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define TRUE 1
#define FALSE 0


int prepare_key2(char *key)
{
    register char *keyp;
    register char *dup;
    register int  character;

    if(*key =='\0')
        return FALSE;

    for(keyp = key;(character =*keyp)!='\0';keyp++){
        if(!islower(character)){
            if(!isupper(character)){
                    return FALSE;
            }
            *keyp = tolower(character);
        }
    }


    for(keyp = key; (character = *keyp)!='\0';){
        dup =++keyp;
        while((dup = strchr(dup,character))!=NULL)
            strcpy(dup,dup +1);
    }


    for(character = 'a';character <='z';character +=1){
        if(strchr(key,character)==NULL){
            *keyp++ = character;
            *keyp ='\0';
        }
    }

    return TRUE;
}


int prepare_key(const char *key,char *keymap)
{
    // Delete the duplicate words in key
    // change the work to upper letter
    int len ;
    char temp;
    int dublic =0;
    char *koptr,*knoptr;
    koptr = keymap;
    knoptr=koptr;
    len = strlen(key);
    printf("the key 's len = %d\n",len);
    for(int i =0; i < len ; i++)
    {
        temp=toupper(key[i]);
 
        *keymap++=temp;

        printf("keymap len =%d\n",strlen(keymap));
 
    }
    return 0;

}

int main()
{
    const char *mystr ="TRAILBLAZERS";
    char keymap[26] = {0};
    prepare_key(mystr,keymap);
    puts(keymap);

}