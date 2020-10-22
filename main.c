#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADTStack.h"

#define MAX_LENGTH 16
struct intl_passenger {
    char given_name[MAX_LENGTH];
    char surname[MAX_LENGTH];
    char passport_id[MAX_LENGTH];
    char country[MAX_LENGTH];
};

typedef struct intl_passenger *passenger;

void* cpy_elm(void *data) {
    passenger res = (passenger) malloc(sizeof(struct intl_passenger));
    passenger temp = (passenger) data;
    strcpy(res->passport_id, temp->passport_id);
    strcpy(res->given_name, temp->given_name);
    strcpy(res->surname, temp->surname);
    strcpy(res->country, temp->country);
    return res;
}

void free_elm(void* data){
        free(data);
}



char* label_elm(void* data){
    passenger temp = (passenger) data;
    char* res = malloc(16*4+10);
    strcpy(res, temp->given_name);
    strcat(res, " ");
    strcat(res, temp->surname);
    strcat(res, " ");
    strcat(res, temp->passport_id);
    strcat(res, "\n\0");
    return res;
}

void check(){
    struct intl_passenger temp;


    strcpy(temp.passport_id , "206233033");
    strcpy(temp.given_name , "TAL");
    strcpy(temp.surname , "SHAMIR");
    strcpy(temp.country , "ISRAEL");
    printf("%s", label_elm(&temp));
    passenger temp1 = cpy_elm(&temp);
    printf("%s", label_elm(temp1));
    free_elm(temp1);
}

void fill_stack(Stack stack, const char* path){
    FILE *fptr = fopen(path, "r");
    passenger temp = malloc(sizeof(struct intl_passenger));
    size_t len;
    while ((len = (size_t) fscanf(fptr, "%s %s %s %s", temp->given_name, temp->surname, temp->passport_id, temp->country)) != EOF) {
        push(stack, temp);
        }
    fclose(fptr);
    free(temp);
}


int main() {
    Stack new_stack = init(56, cpy_elm, free_elm, label_elm);
    fill_stack(new_stack, "international_passengers.dat"); 
    printf("-------STACK TEST FOR PASSENGERS DATA---------\n\n");
    print(new_stack);
    
    return 0;
}
