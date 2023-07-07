#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct ElectionData{
    char elect_name[100];
    char elect_date[100];
    char vote_time[100];
    char district[100];
    char constituency[100];
    struct ElectionData* next;
}ElectionData;

typedef struct candidate{
    // int candidate_id;
    char candidate_id[16];
    char candidate_name[50];
    char dob[11];  // Date of Birth (format: dd/mm/yyyy)
    char election_name[50];
    char party_name[50];
    char district[50];
    char constituency[50];
    char address[100];
    char phone_no[15];
    char email_id[50];
    char vote_count[50];
} candidate;

typedef struct user_struct{
    char status[200];
    char u_id[50];
    char first_name[50];
    char last_name[50];
    char dob[20];
    int age;
    char gender[50];
    char password[50];
    char address[50];
    char phoneno[50];
    char district[50];
    char consituency[50];
}user_struct;

void admin_func();
void elec_office();
void add_user();
void login_user();
void fetch_voters_req();
void voter_dash(char user_id[100]);
void voter_func();
void admin_approver();
void fetch_voters_app();
void generate_voter_id();
void extract_date(const char* date_string, int* month, int* day, int* year);
int sum_of_digits(int num);
void req_to_approval(char user_id[100]);
void view_voter_id(char user_id[100]);
void election_schedule();
ElectionData* create_node();
void insert_node(ElectionData **head, ElectionData *newnode);
void candidate_detail();
void cast_vote();
void show_candi(char user_id[100]);
void election_res();
void date_valid(char date[20],char valid_date[20]);
void clearInputBuffer();
void mobile_validation(char mobile[20],char valid_mobile[20]);
void elec_office_login();
int main();
void age_valid(int u_age,int valid_u_age);
void gender_validate(char gender_valid[20],char valid_gender[20]);