#include<stdio.h>
#include"structure.h"
#include<string.h>
//make -f makefile.mk
int main(){
    int flip;
    // printf("Hello World");
    // elect_func();
    
    // int  valid_u_age=0;
    //char date[20]='\0';
    char valid_gender[20];
    printf("please select your role\n");
    printf("1. Admin\n");
    printf("2. Elector Officer\n");
    printf("3. User\n");
    printf("4");
    printf("~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("enter your choice\n");
    scanf("%d",&flip);

    switch(flip){
        case 1:
            admin_func();
            break;
        case 2:
            elec_office_login();
            break;
        case 3:
            voter_func();
            break;
        case 4:
            printf("hiii");
            gender_validate("aale",valid_gender);
            printf("%s",valid_gender);
            break;
    }

    return 0;
}


