#include<stdio.h>
#include<string.h>
char keywords[5][10] = {"int","float","char","double","long"};

void check_char(char str[],int* j,int len)
{
    char st[1000]="";
    int k = 0;
    int keyword = 0;
    int i = *j;
    if((str[i]>='a' && str[i]<='z')||(str[i]>='A' && str[i]<='Z'))
        {

            for(;(i<len)&&((str[i]>='a' && str[i]<='z' && str[i] !=' ')||(str[i]>='A' && str[i]<='Z' && str[i]!=' ')|| str[i]=='_' || (str[i] >= '0' && str[i] <= '9'));i++)
            {
                st[k++] = str[i];
            }
            st[k]='\0';
            for(int s = 0;s<5;s++)
            {
                if(!strcmp(keywords[s],st))
                {
                    keyword = 1;
                }
            }
            if(keyword)
                printf("%s -> Keyword\n");
            else
            {
            if(k > 1)
                printf("%s -> Identifier(String)\n",st);
            if(k == 1)
                printf("%c -> Identifier(Char)\n",str[i-1]);
            }
            st[1000] = "";
        }
        *j = i;
}
void check_num(char str[],int* j,int len)
{
    int i = *j;
    if(str[i] >= '0' && str[i] <= '9')
    {
        int number=0,mantissa=0;
        int float_state = 0;
        for(;(i<len) && ((str[i] >= '0' && str[i]<='9')|| str[i]=='.');i++)
        {
            if(str[i] == '.')
            {
                float_state = 1;
                for(i = i+1;(str[i] >= '0' && str[i]<='9')|| str[i]=='.';i++)
                    mantissa = mantissa * 10 + (int)str[i]-48;
                break;
            }

            number = number*10 + (int)str[i]-48;

         }
         if(float_state)
         {
            printf("%d",number);
            printf(".");
            printf("%d -> Float\n",mantissa);
         }

         else
            printf("%d -> Integer\n",number);
            if(str[i]==')')
                i--;
     }
     *j = i;
}
int check_paranthesis(char str[],int i)
{
    if(str[i]=='(' || str[i]==')')
        return 1;
    return 0;
}

int main()
{
    char str[1000];

    printf("*********LEXICAL ANALYZER**********\n");
    printf("\nEnter the expression:\n");
    scanf("%[^\n]",str);
    printf("\nExpression:\n%s\n",str);
    printf("\n");

    int len;
    for(len = 1;str[len]!='\0';len++);

    for(int i = 0;str[i]!='\0';i++)
    {

            if((str[i]=='+' || str[i]=='-' || str[i]=='*' || str[i]=='/') && (str[i+1] == '='))
            {
                printf("%c%c -> Special Operator\n",str[i],str[i+1]);
                i+= 2;
            }
            switch(str[i])
            {
            case '=':
                printf("%c -> Assignment operator\n",str[i]);
                break;
            case '+':
                printf("%c -> Addition operator\n",str[i]);
                break;
            case '-':
                printf("%c -> Subtraction operator\n",str[i]);
                break;
            case '*':
                printf("%c -> Multiplication operator\n",str[i]);
                break;
            case '/':
                printf("%c -> Division operator\n",str[i]);
                break;
            default:
                check_char(str,&i,len);

                check_num(str,&i,len);

                if(check_paranthesis(str,i))
                    printf("%c -> Parenthesis\n",str[i]);
            }
        }

}
