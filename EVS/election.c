#include "structure.h"
#include<ctype.h>
#include<string.h>

ElectionData* create_node(){
    ElectionData *newnode = (ElectionData*)malloc(sizeof(ElectionData));
    if(newnode==NULL){
        printf("Memory is not allocated");
        exit(1);
    } 
    newnode->next = NULL;
    return newnode;
}

void insert_node(ElectionData **head, ElectionData *newnode){
    if(*head == NULL){
        *head = newnode;
    }
    else{
        ElectionData *temp = *head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

//void election_schedule(){
//     FILE *file = fopen("elect_data.csv","r");
//     if(file==NULL){
//         printf("failed to open file");
//         return;
//     }

//     ElectionData data;
    

//     while(fscanf(file,"%[^,],%[^,],%[^,],%[^,],%[^,]",data.elect_name,data.elect_date,data.vote_time,data.district,data.constituency)==5){
//         // insert_node(&head,newnode);
//         // //printf("hiiiiii");
//         // newnode = newnode->next;
//         // newnode=create_node();
//         printf("%s, %s, %s, %s, %s\n",data.elect_name,data.elect_date,data.vote_time,data.district,data.constituency);
//     }
    
//     // while(head != NULL){
//     //     printf("%s ***** %s %s %s %s-------\n",head->elect_name,head->elect_date,head->vote_time,head->district,head->constituency);
//     //     //ElectionData *temp = head->next;
//     //     head = head->next; // Move to the next node
//     //     //free(temp); // Free the current node

//     // }

//     fclose(file);
// }


void election_schedule() {
    FILE* file = fopen("elect_data.csv", "r");
    if (file == NULL) {
        printf("Failed to open file");
        return;
    }

    ElectionData* head = NULL;
    ElectionData* newnode = NULL;

    char line[1000];

    while (fgets(line, sizeof(line), file) != NULL) {
        newnode = create_node();

        // Parse the line into individual fields using sscanf
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^\n]", newnode->elect_name, newnode->elect_date, newnode->vote_time, newnode->district, newnode->constituency);

        insert_node(&head, newnode);
    }

    fclose(file);

    newnode = head; // Start from the head node
    
    while (newnode != NULL) {
        printf("%s %s %s %s %s\n", newnode->elect_name, newnode->elect_date, newnode->vote_time, newnode->district, newnode->constituency);
        ElectionData* temp = newnode; // Store the current node
        newnode = newnode->next; // Move to the next node
        free(temp); // Free the current node
    }
}