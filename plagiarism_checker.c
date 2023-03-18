#include <stdio.h>
#include <string.h>
int main(){
    char user_str[1000];
    char arr_raw[100][1000],arr_user[100][1000];
    int i,raw_row=0,user_row=0,col=0,k,ctrl;
    char raw_str[1000]="India, country that occupies the greater part of South Asia. Its capital is New Delhi, built in the 20th century just south of the historic hub of Old Delhi";
    scanf("%[^\n]",user_str);
    for(i=0;i<=(strlen(raw_str));i++)
    {
        if(raw_str[i]==' '||raw_str[i]=='\0')
        {
            arr_raw[raw_row][col]='\0';
            raw_row++;
            col=0;
        }
        else
        {
            arr_raw[raw_row][col++]=raw_str[i];
        }
    }
    col = 0;
    for(i=0;i<=(strlen(user_str));i++)
    {
        if(user_str[i]==' ' || user_str[i]=='\0')
        {
            arr_user[user_row][col]='\0';
            user_row++;
            col=0;
        }
        else
        {
            arr_user[user_row][col++]=user_str[i];
        }
    }

    int count = 0;
    for(int i = 0;i<raw_row;i++)
    {
        for(int j = 0;j<user_row;j++)
        {
            if(!strcmp(arr_user[i],arr_raw[j]))
            {
                count++;
                break;
            }
        }
    }
    //printf("Words in raw str = %d\n",raw_row);
    //printf("copied words in user str = %d\n",count);
    if(count > raw_row/2)
    {
        printf("\nPlagiarism Found! %d percent!\n",(int)(((float)count/(float)raw_row)*100));
    }
    else{
        printf("\nPaper ready for successful Publication!!!\n");
    }
    return 0;
}
