#include<stdio.h>
#include<string.h>

char contacts[][50] = {"ram","ragu","sam","anu","sita","john","jeeva","shyam","prabu","vijay"};
char playlist[][100] = {"harleys in hawai","dandellions","levitating","ranjithame ranjithame","unakkul naane","veesum velichathile"};
int playlst_len = sizeof(playlist)/sizeof(playlist[0]);
int cont_len = sizeof(contacts)/sizeof(contacts[0]);

int check_contact(char name[])
{

    for(int i = 0;i<cont_len;i++)
        {
            if(!strcmp(name,contacts[i]))
            {
                return 1;
            }
        }
        return 0;
}
int check_playlist(char song[])
{

    for(int i = 0;i<playlst_len;i++)
        {
            if(!strcmp(song,playlist[i]))
            {
                return 1;
            }
        }
        return 0;
}
const char* get_action(char str[],int* pos)
{
    int k = 0;
    char s[100];
    for(int i = 0;str[i]!='\0';i++)
    {

        if(str[i] == ' ')
        {
            *pos = i+1;
            break;
        }
        else{
        s[k++] = str[i];
        }
    }
    s[k]='\0';
    char *p = s;
    return p;
}
const char* get_name(int pos,char str[])
{
    char s[1000];
    char *p;
    int k = 0;
    for(int i = pos;str[i]!='\0';i++)
        s[k++] = str[i];
    s[k] = '\0';
    p = s;
    return p;
}
int main()
{

    char str[1000];
    scanf("%[^\n]s",str);

    char st[1000];
    int pos;
    char name[1000],message[1000];

    strcpy(st,get_action(str,&pos));

    //initiating greet
    if(!strcmp(str,"hi") || !strcmp(str,"hello") || !strcmp(str,"hey"))
        printf("Hello dude!\n");
    //had food??
    else if(!strcmp(str,"had lunch?") || !strcmp(str,"had dinner?") || !strcmp(str,"had breakfast?") || !strcmp(str,"had food?"))
        printf("I'm a machine which needs electricity\nI don't eat food like humans rather I charge myself...:)\n");
    else if(!strcmp(str,"Good Morning") || !strcmp(str,"Good afternoon") || !strcmp(str,"Good evening") || !strcmp(str,"Good night"))
        printf("%s!!!\n",str);
    //calling...
    else if(strcmp(st,"call")==0)
    {

        strcpy(name,get_name(pos,str));

        if(check_contact(name))
            printf("Calling '%s'...\n",name);
        else
            printf("Contact not found!\n");

    }
    // messaging
    else if(!strcmp(st,"message"))
    {
        strcpy(name,get_name(pos,str));
        if(check_contact(name))
        {
            char choice[100];
            printf("What message you would like to send?\n");
            scanf("%s",message);
            printf("Message:\n%s\nDo you want to edit or send the message?(type 'edit' for editing and 'send' to send the message)...\n",message);
            scanf("%s",choice);
            if(!strcmp(choice,"edit"))
            {
                printf("Enter the message: \n");
                scanf("%s",message);
            }
            printf("Sending message '%s' to %s...\n",message,name);

        }

        else
            printf("Contact not found!\n");
    }
    //play music
    else if(!strcmp(str,"play music"))
    {
            static int i = 0;
            lbl:
            printf("Playing song '%s'...\n",playlist[i]);
            char song_choice[100]="";
                while(strcmp(song_choice,"end")&&(i<playlst_len))
                {

                    scanf("%s",song_choice);
                    if(!strcmp(song_choice,"end"))
                        break;
                    if(!strcmp(song_choice,"previous_song"))
                    {
                        if(i==0)
                        {
                            goto lbl;
                        }
                        else
                        {
                            i = i-1;
                            goto lbl;
                        }
                    }
                    if(!strcmp(song_choice,"next_song"))
                    {
                        if(i == playlst_len-1)
                        {
                            printf("This is the last song\n");
                            goto lbl;
                        }
                        else
                        {
                            i++;
                            goto lbl;
                        }

                    }
                }


    }
    else if(!strcmp(str,"what are you doing"))
    {
        printf("I am clearing out the bugs behind and I'm always ready to help you!\n");
    }
    else if(!strcmp(str,"what's the time"))
    {
        printf("current time:\n%s\n",__TIME__);
    }
    else if(!strcmp(str,"what's today's date"))
        printf("%s\n",__DATE__);
    else if(!strcmp(str,"set alarm"))
    {
        char time[100];
        printf("At what time?: (eg : 8/pm)");
        scanf("%s",time);
        printf("Alarm set for %s\n",time);
    }
    else if(!strcmp(str,"I like you"))
        printf("%s too...\n",str);
    else
    {
        printf("Sorry! I couldn't get that!\n");
    }

}
