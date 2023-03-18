#include<stdio.h>
#include<string.h>
int main()
{
    char user_str[1000];
    scanf("%[^\n]",user_str);
    int user_len = sizeof(user_str)/sizeof(user_str[0]);

    char rawStr[100000];
    strcpy(rawStr,"India, country that occupies the greater part of South Asia. Its capital is New Delhi, built in the 20th century just south of the historic hub of Old Delhi to serve as India’s administrative centre. Its government is a constitutional republic that represents a highly diverse population consisting of thousands of ethnic groups and likely hundreds of languages. With roughly one-sixth of the world’s total population, India is the second most populous country, after China.It is known from archaeological evidence that a highly sophisticated urbanized culture—the Indus civilization—dominated the northwestern part of the subcontinent from about 2600 to 2000 BCE. From that period on, India functioned as a virtually self-contained.");    int len = strlen(rawStr);
    int raw_len = sizeof(rawStr)/sizeof(rawStr[0]);

    char arr_raw[100][10000];
    //char arr_user[100][10000];
    int r_r = 0;
    int r_c = 0;
    //int u_r = 0;
    //int u_c = 0;


    printf("Raw String:\n");
    for(int i = 0;rawStr[i]!='\0';i++)
    {

        if((rawStr[i]==' ') || (i==raw_len-1))
        {

          r_r++;
          r_c = 0;
        }
        else
        {
            arr_raw[r_r][r_c++] = rawStr[i];
        }
    }
    for(int i = 0;i<r_r;i++)
    {
        printf("r[%d]=%s\n",i,arr_raw[i]);
    }
    /*printf("User String:\n");


    for(int i = 0;user_str[i]!='\0';i++)
    {
        if((user_str[i]==' ') || (i==user_len-1))
        {
          u_r++;
          u_c = 0;
          continue;
        }
        else
        {
            arr_user[u_r][u_c++] = user_str[i];
        }
    }*/
    return 0;
}
