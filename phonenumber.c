#include<stdio.h>
#include<string.h>
int digit_return(char st[])
{
    if(!strcmp(st,"one"))
        return 1;
    if(!strcmp(st,"two"))
        return 2;
    if(!strcmp(st,"three"))
        return 3;
    if(!strcmp(st,"four"))
        return 4;
    if(!strcmp(st,"five"))
        return 5;
    if(!strcmp(st,"six"))
        return 6;
    if(!strcmp(st,"seven"))
        return 7;
    if(!strcmp(st,"eight"))
        return 8;
    if(!strcmp(st,"nine"))
        return 9;

}
void calc(int count,char str[],int* num)
{

    for(int i = 0;i<count;i++)
        *num = (*num)*10 + digit_return(str);
    printf("inside func %ld\n",*num);

}
int main()
{
    long int num = 0;
    char s[10][1000],str[1000];
    int l = 0,k=0,n=2;
    scanf("%[^\n]",str);
    char st[1000];
    int len;
    for(len = 0;str[len]!='\0';len++);
    for(int i = 0;i<=len;i++)
    {
        if(str[i]==' ' || str[i]== '\0')
        {
            st[k] = '\0';
            k=0;
            strcpy(s[l++],st);
            if(str[i] == '\0')
                break;
        }
        else
        {
            st[k++] = str[i];
        }
    }
    for(int i = 0;i<l;i++)
        printf("s[%d] = %s\n",i,s[i]);

    int count = 1;
    for(int i = 0;i<l;i++)
    {
        if(!strcmp(s[i],"double"))
        {
            count = 2;
            i++;
        }
        if(!strcmp(s[i],"triple"))
        {
            count = 3;
            i++;
        }
        else
            count = 1;
        calc(count,s[i],&num);
    }
    printf("%ld",num);

}
