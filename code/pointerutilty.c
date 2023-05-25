#include<stdio.h>

void cut(int intCut);
void copy(int intCopy);
void paste(int intPaste);
void delete(int intDelete);

int main(void)
{
    void (*funcPtr[4])(int) ={cut,copy,paste,delete};
    int intChoice;
    printf("\nEdit Menu: Enter your choice (0,1,2,or 3).\n");
    printf("Please do not enter any other number\
    except 0,1,2, or 3 to \n");
    printf("avoid abnormal termination of program.\n");
    printf("Enter 0 to activate menu-item Cut.\n");
    printf("Enter 1 to activate menu-item Copy.\n");
    printf("Enter 2 to activate menu-item Paste.\n");
    printf("Enter 3 to activate menu-item Delete.\n");
    scanf("%d",&intChoice);
    (funcPtr[intChoice])(intChoice);
    printf("Thanks you.\n");

    return 0;

}

void cut(int intCut)
{
    printf("You entered %d.\n",intCut);
    printf("Menu-item Cut is activated.\n");
}

void copy(int intCopy)
{
    printf("You entered %d.\n",intCopy);
    printf("Menu-item Copy is activated.\n");
}

void paste(int intPaste)
{
    printf("You entered %d.\n",intPaste);
    printf("Menu-tiem Paste is activated.\n");

}

void delete(int intDelete)
{
    printf("You entered %d.\n",intDelete);
    printf("Menu-tiem intDelete is activated.\n");
    
}