#include<stdio.h>
#include<string.h>
void store(char* arr,int len,char str[])
{
    int a = 0;
    int k = 0;
    char st[1000];
    for(int i = 0;str[i]!='\0';i++)
    {
        if((str[i]==' ') || (i==len-1))
        {
          st[k] = '\0';
          k = 0;
          strcpy(arr[a++],st);
          printf("a[%d] = %s\n",a-1,st);
          continue;
        }
        else
        {
            st[k++] = arr[i];
        }
    }
}

int main()
{
    char user_str[1000];
    scanf("%[^\n]",user_str);
    int userstr_len = sizeof(user_str)/sizeof(user_str[0]);
    char rawStr[100000];
    strcpy(rawStr,"India, country that occupies the greater part of South Asia. Its capital is New Delhi, built in the 20th century just south of the historic hub of Old Delhi to serve as India’s administrative centre. Its government is a constitutional republic that represents a highly diverse population consisting of thousands of ethnic groups and likely hundreds of languages. With roughly one-sixth of the world’s total population, India is the second most populous country, after China.It is known from archaeological evidence that a highly sophisticated urbanized culture—the Indus civilization—dominated the northwestern part of the subcontinent from about 2600 to 2000 BCE. From that period on, India functioned as a virtually self-contained.");    int len = strlen(rawStr);
    char st[1000];
    int k = 0;
    char arr_raw[100][10000];
    int a = 0;
    int raw_len = sizeof(rawStr)/sizeof(rawStr[0]);
    store(arr_raw,raw_len,rawStr);
    store(user_str,userstr_len,user_str);

    //int arr_len = sizeof(arr)/sizeof(arr[0]);
    //for(int j = 0;j<arr_len;j++)
    //{
        //printf("arr[%d] = %s\n",j,arr[j]);
    //}
}
