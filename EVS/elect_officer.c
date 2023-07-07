#include "structure.h"
#include<ctype.h>
#include<string.h>

void elec_office_login(){
    char off_id[20];
    char off_pass[20];
    printf("Enter User Id:");
    scanf("%s",off_id);
    printf("Enter password:");
    scanf("%s",off_pass);

    if((strcmp(off_id,"officer")==0) && (strcmp(off_pass,"1234")==0)){
        elec_office();
        return;
    }
    else{
        printf("\nPlease enter valid id and password\n");
        elec_office_login();
    }
}

void elec_office(){
    int flip;
    printf("*************************************\n");
    printf("press 1 to view votor request approved by admin\n");
    printf("press 2 to generate voter id\n");
    printf("*************************************\n");
    printf("Enter your choice");
    scanf("%d",&flip);

    switch(flip){
        case 1:
            fetch_voters_app();
            break;
        
        case 2:
            generate_voter_id();
    }
}


void fetch_voters_app(){
    user_struct user;
    FILE *file = fopen("user.csv","r");
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  user.status, user.u_id, user.first_name, user.last_name, user.dob, &user.age,
                  user.gender, user.password, user.address, user.phoneno, user.district,
                  user.consituency) == 12) {
                    
                    if(strcmp(user.status,"approved")==0){
                        printf("%s ,%s ,%s ,%s ,%s ,%d ,%s ,%s ,%s ,%s ,%s ,%s\n",user.status, user.u_id, user.first_name, user.last_name, user.dob, user.age,
                                user.gender, user.password, user.address, user.phoneno, user.district,
                                user.consituency);
                    }
    }
    elec_office();
}

void generate_voter_id(){
    user_struct user;
    char user_id[20];
    printf("Enter user id to genearte voter_id");
    scanf("%s",user_id);
    FILE *file = fopen("user.csv","r");
    FILE *tmp = fopen("temp.csv","w");
    
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  user.status, user.u_id, user.first_name, user.last_name, user.dob, &user.age,
                  user.gender, user.password, user.address, user.phoneno, user.district,
                  user.consituency) == 12) {
            if(strcmp(user.status,"approved")==0 && strcmp(user.u_id,user_id)==0){
                // random voter id generate karne ka code likhna hai 
                int first_len = strlen(user.first_name);
                int last_len = strlen(user.last_name);
                int month, day, year;
                char voter_id[20];
                extract_date(user.dob, &month, &day, &year);
                int sum_mon = sum_of_digits(month);
                int sum_day = sum_of_digits(day);
                int sum_year  =sum_of_digits(year);
                
                snprintf(voter_id,11,"%.1s%.2s%d%d%d%d%d",user.first_name,user.last_name,first_len,last_len,sum_mon,sum_day,sum_year);

                for(int i=0;i<voter_id[i];i++){
                    voter_id[i]=toupper(voter_id[i]);
                }

                strcpy(user.status,voter_id);
            }

            // printf("\n~~~%s\n",user.status);
            fprintf(tmp, "%s,%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%s\n",
                    user.status,user.u_id,user.first_name,user.last_name,user.dob,user.age,user.gender,user.password,
                    user.address,user.phoneno,user.district,user.consituency);
    }

    fclose(file);
    fclose(tmp);

    remove("user.csv");
    rename("temp.csv","user.csv");
    printf("VOTER ID GENERATED SUCCESSFULLY");
}



void extract_date(const char* date_string, int* month, int* day, int* year) {
    sscanf(date_string, "%d/%d/%d", month, day, year);
}

int sum_of_digits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}