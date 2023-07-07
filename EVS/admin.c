#include"structure.h"
#include<string.h>
void admin_func(){
    char admin[20];
    char pass[20];
    printf("Please enter user name");
    scanf("%s",admin);
    printf("Please enter password");
    scanf("%s",pass);
    if((strcmp(admin,"admin")==0) && (strcmp(pass,"1234")==0)){
        int flip;
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("press 1 to view voter id request\n");
        printf("press 2 to approve voter id request\n");
        printf("press 3 to view candidate detail\n");
        printf("press 4 for main menu");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Enter value");
        scanf("%d",&flip);

        switch(flip){
            case 1:
                fetch_voters_req();
                break;

            case 2:
                admin_approver();
                break;
            case 3:
                candidate_detail();
            
            case 4:
                main();
                break;
        }
    }
    else{
        printf("please enter valid credentials");
        admin_func();
    }
}

void fetch_voters_req(){
    user_struct user;
    FILE *file = fopen("user.csv","r");
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  user.status, user.u_id, user.first_name, user.last_name, user.dob, &user.age,
                  user.gender, user.password, user.address, user.phoneno, user.district,
                  user.consituency) == 12) {
            if (strcmp(user.status,"req_to_approval")==0){
                printf("%s ,%s ,%s ,%s ,%s ,%d ,%s ,%s ,%s ,%s ,%s ,%s\n",user.status, user.u_id, user.first_name, user.last_name, user.dob, user.age,
                    user.gender, user.password, user.address, user.phoneno, user.district,
                    user.consituency);
            }
    
    }
}

void admin_approver(){
    user_struct user;
    char user_id[20];
    printf("Enter user id you want to approve");
    scanf("%s",user_id);
    FILE *file = fopen("user.csv","r");
    FILE *tmp = fopen("temp.csv","w");
    while (fscanf(file, "%[^,],%[^,],%[^,],%[^,],%[^,],%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  user.status, user.u_id, user.first_name, user.last_name, user.dob, &user.age,
                  user.gender, user.password, user.address, user.phoneno, user.district,
                  user.consituency) == 12) {
            if(strcmp(user_id,user.u_id)==0){
                strcpy(user.status, "approved");
            }
            fprintf(tmp, "%s,%s,%s,%s,%s,%d,%s,%s,%s,%s,%s,%s\n",
                    user.status,user.u_id,user.first_name,user.last_name,user.dob,user.age,user.gender,user.password,
                    user.address,user.phoneno,user.district,user.consituency);
            
    }
    fclose(file);
    fclose(tmp);

    remove("user.csv");
    rename("temp.csv","user.csv");

}


 void candidate_detail(){
    candidate cad;
    FILE *file = fopen("candidate.csv","r");
    char line[1000];

     while (fgets(line, sizeof(line), file) != NULL) {
    

        // Parse the line into individual fields using sscanf
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]",
                  cad.candidate_id, cad.candidate_name, cad.dob, cad.election_name, cad.party_name,
                   cad.district, cad.constituency, cad.address, cad.phone_no, cad.email_id,
                   cad.vote_count);

        printf("%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s",cad.candidate_id,cad.candidate_name,cad.dob,cad.election_name,cad.party_name,cad.district,cad.constituency,cad.address,
            cad.phone_no,cad.email_id,cad.vote_count);   
    }
}