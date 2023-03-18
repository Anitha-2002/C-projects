#include<stdio.h>
#include<string.h>
void recharge(long int* bank_bal)
{
    long long int mob_num;
    int price;
    char sim_brand[1000];
    int data_pack=0;
    printf("***********Recharge Mobile Num************\n");
    printf("Enter the mobile number to recharge:\n");
    scanf("%lld",&mob_num);
    printf("Enter the service provider:\n");
    scanf("%s",sim_brand);

    if(!strcmp(sim_brand,"airtel"))
    {
        printf("Airtel:\n\nPacks provided:\n");
        printf("1. 2GB/day Data & Unlimited calls   | Validity: 56 days    | price : Rs.599\n");
        printf("2. 1.5GB/day Data & Unlimited Calls | Validity: 84 days    | price : Rs.999\n");
        printf("3. 2.5GB/day Data & Unlimited Calls | Validity: 84 days    | price : Rs.1099\n");
        scanf("%d",&data_pack);
        switch(data_pack)
        {
        case 1:
            price = 599;
            break;
        case 2:
            price = 999;
            break;
        case 3:
            price = 1099;
            break;
        }

    }
    if(!strcmp(sim_brand,"vodafone"))
    {
        printf("Vodafone:\n\nPacks provided:\n");
        printf("1. 2GB/day Data & Unlimited calls   | Validity: 56 days    | price : Rs.499\n");
        printf("2. 1.5GB/day Data & Unlimited Calls | Validity: 84 days    | price : Rs.899\n");
        printf("3. 2.5GB/day Data & Unlimited Calls | Validity: 84 days    | price : Rs.999\n");
        scanf("%d",&data_pack);
        switch(data_pack)
        {
        case 1:
            price = 499;
            break;
        case 2:
            price = 899;
            break;
        case 3:
            price = 999;
            break;
        }

    }
    if(!(!strcmp(sim_brand,"airtel")||!strcmp(sim_brand,"vodafone")))
    {
        printf("Service provider unavailable!\n");
    }
    if(price <= *bank_bal)
        {
            *bank_bal -= price;
        }
        else
            printf("Bank Balance is not sufficient!\n");

    printf("Recharge of Rs.%d for '%lld' is done successfully!\n",price,mob_num);
}
void signup(char* user_id,char* pwd,long int* upi_pin)
{
    printf("\n*********Sign Up**************\n");
    printf("Enter user id:\n");
    scanf("%s",user_id);
    printf("Enter password:\n");
    scanf("%s",pwd);
    printf("Enter UPI pin for funds transfer:\n");
    scanf("%ld",upi_pin);
    printf("upi pin entered : %ld\n",*upi_pin);
    printf("Signup Successfull!\n");
}
int login(char login_id[],char pass[])
{
    char user_id[1000],pwd[100];
    printf("\n**********Login***************\n");
    printf("Enter user id:\n");
    scanf("%s",user_id);
    printf("Enter password:\n");
    scanf("%s",pwd);
    int flag_login=0,flag_pwd=0;
    if(!strcmp(login_id,user_id) && !strcmp(pwd,pass))
        return 1;
    else
        return 0;

}
void get_bankacc(long long int* bank_acc, char* bank_name,long int* bank_bal)
{
    printf("*************Bank Details*****************\n");
    printf("Enter Bank Account Number:\n");
    scanf("%lld",bank_acc);
    bank_name = "IOB";
    //printf("Enter Bank Name:\n");
    //scanf("%s",bank_name);
    printf("%s\n",bank_name);
    printf("Bank details updated successfully!\n");
    *bank_bal = 20000;

}
void transfer_money(long long int* mob_num,long int* bank_bal,long int* upi_pin)
{
    int valid_mobnum = 0;
    printf("**********Transfer Funds******************\n");
    phnum:
    printf("Enter recepient mobile number: ");
    scanf("%lld",mob_num);

    long long int temp = *mob_num;
    int count = 0;
    while(temp>0)
    {
        temp /= 10;
        count++;
    }
    if(count == 10)
        valid_mobnum = 1;
    int amt;
    if(valid_mobnum)
    {
        amount:
        printf("Enter amount to transfer in INR: ");
        scanf("%d",&amt);
        if(amt <= *bank_bal)
        {
            long int pin=0;
            upipin:
            printf("Enter UPI pin to transfer funds:\n");
            scanf("%ld",&pin);
            //printf("upi:%ld\n",*upi_pin);
            if(pin == *upi_pin)
            {
                *bank_bal -= amt;
                printf("Rs.%d transfered to %lld successfully!\n",amt,*mob_num);
                return;
            }
            else
            {
                printf("Incorrect UPI pin entered!\n");
                goto upipin;
            }
        }
        else{
            printf("Bank balance low!\n");
            goto amount;
        }
    }
    else
    {
        printf("Invalid Mobile Number!\n");
        goto phnum;
    }
}
void view_bank_bal(long int bal)
{
    printf("Bank Balance:\nRs.%.2lf\n",(double)bal);
}
int main()
{
    char login_id[1000]="",pwd[100];
    char bank_name[1000];
    long long int bank_acc=0, mobileNum=0;
    long int bank_bal=0,upi_pin = 0;
    lbl:
    printf("****************Welcome to UPI App************\n");
    printf("If you are a new user enter 1 for signup else enter 2...\n");
    int login_signup;
    scanf("%d",&login_signup);
    //printf("login/signup = %d",login_signup);
    if(login_signup == 1)
    {
        signup(&login_id[0],&pwd[0],&upi_pin);
    }
    if(login(login_id,pwd))
    {
        int action=0;
        printf("Login successfull!\n");
        if(!bank_acc)
            get_bankacc(&bank_acc,bank_name,&bank_bal);

        while(action != 4)
        {
        printf("Choose action:\n1. Transfer money\n2.Mobile Recharge\n3.View Bank Balance\n4.Exit\n");
        scanf("%d",&action);
        //printf("upi_pin : %ld\n",upi_pin);
        switch(action)
        {
        case 1:
            transfer_money(&mobileNum,&bank_bal,&upi_pin);
            break;
        case 2:
            recharge(&bank_bal);
            break;
        case 3:
            view_bank_bal(bank_bal);
            break;
        case 4:
            return 0;
        }
        }

    }
    else{
        printf("Incorrect username or password!\n");
        goto lbl;
    }

}
