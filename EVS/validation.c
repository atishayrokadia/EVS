#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"structure.h"
void date_valid(char date[20],char valid_date[20]){
    // char valid_date[20];

    int day, month, year;
    // printf("Hi");
    sscanf(date, "%d/%d/%d", &day, &month, &year);
    // printf("Hii");
    if ((1 <= day) && (day <= 31) && (1 <= month) && (month <= 12) && (1940 < year) && (year < 2025)) {
        snprintf(valid_date, 20, "%d/%d/%d", day, month, year);
    } else {
        printf("Please enter a valid date: ");
        char new_date[20];
        scanf("%19s", new_date);
        date_valid(new_date,valid_date);
        return;
    }
    //printf("%s",valid_date);
}


void mobile_validation(char mobile[20],char valid_mobile[20]){
    // printf("%lu\n",strlen(mobile));
    // printf("%u",isnum(mobile));
    int flag=0;
    for(int i=0;mobile[i]!='\0';i++){
        if (mobile[i]<'0' || mobile[i]>'9'){
            flag=1;
        }
    }

    if ((strlen(mobile)==10) && (flag==0)){
        strcpy(valid_mobile,mobile);
    }
    else{
       printf("please enter valid mobile no\n");
       char mobile_no[20];
       scanf("%s",mobile_no);
       mobile_validation(mobile_no,valid_mobile);
       return;
    }

    //printf("%s",valid_mobile);
}

void age_valid(int u_age,int valid_u_age){
    int age;
    //printf("%d\n",u_age);
    if ((u_age>18) && (u_age<99)){
        valid_u_age = u_age;
        printf("valid age is %d",valid_u_age);
        return;
    }
    else if(u_age<18){
        printf("You are minor you are not eligible for vote");
        voter_func();
        return;
    }
    else if (u_age>99){
        printf("please enter valid age\n");
        scanf("%d",&age);
        age_valid(age,valid_u_age);
        return;
    }
}


void gender_validate(char gender_valid[20],char valid_gender[20]){
    if((strcmp(gender_valid,"male")==0) || (strcmp(gender_valid,"female")==0)){
        strcpy(valid_gender,gender_valid);
    }
    else{
        printf("please enter valid gender");
        char gender[20];
        scanf("%s",gender);
        gender_validate(gender,valid_gender);
    }
}