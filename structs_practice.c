#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

int const NAME_MAX_SIZE = 25;
int ARRAY_SIZE = 0;
const char FILENAME[] = "persons.dat";

struct User {
    int userID;
    char firstName[25];
    char lastName[25];
};

void write_users(const char *filename, struct User *users, int size);
struct User *read_users(const char *filename);
void printStructs(struct User *users);
void addUser(struct User *users);




int main()  
{   
    struct User *users;

    char answer[1000];
    while(1) {
        printf("Load with (l) and print with (p) add with (a) and save with (s)\n");
        scanf(" %s", answer);
        if (strcmp(answer, "l") == 0) {
            users = read_users(FILENAME);
        } else if (strcmp(answer, "p") == 0) {
            printStructs(users);
        } else if (strcmp(answer, "q") == 0) {
            printf("Quitting..");
            break;
        } else if (strcmp(answer, "a") == 0) {
            addUser(users);
        } else if (strcmp(answer, "s") == 0) {
            write_users(FILENAME, users, ARRAY_SIZE);
        }

    }
}

void write_users(const char *filename, struct User *users, int array_size) {
    FILE *outfile; 
    // open file for writing 
    outfile = fopen (filename, "w"); 
    if (outfile == NULL) 
    { 
        fprintf(stderr, "\nError in opening the file\n"); 
        exit (1); 
    }    
    for(int i=0; i <array_size; i++) {
        fwrite (&users[i], sizeof(struct User), 1, outfile); 
    }
    if(fwrite != 0)  
        printf("Contents to file written successfully !\n"); 
    else 
        printf("Error writing file!\n"); 
  
    // close file 
    fclose (outfile); 
}

struct User *read_users(const char *filename) {
    FILE *infile; 
    struct User input; 
      
    // Open person.dat for reading 
    infile = fopen (filename, "r"); 
    if (infile == NULL) 
    { 
        fprintf(stderr, "\nError opening file\n"); 
        exit (1); 
    } 
    struct User *users = (struct User *)malloc(1000);

    // read file contents till end of file 
    while(fread(&input, sizeof(struct User), 1, infile)) {
        users[input.userID].userID = input.userID;
        strncpy(users[input.userID].firstName, input.firstName, NAME_MAX_SIZE);
        strncpy(users[input.userID].lastName, input.lastName, NAME_MAX_SIZE);
        ARRAY_SIZE++;
    }
    // close file 
    fclose (infile); 
  
    return users; 
}


void printStructs(struct User *users) {
    for(int i=0; i < ARRAY_SIZE; i++) {
        puts("");
        printf("Id: %d\n", users[i].userID);
        printf("First name: %s\n", users[i].firstName);
        printf("last name: %s\n", users[i].lastName);
    }
    puts("");
}

void addUser(struct User *users) {
    char *firstName, *lastName;
    char c;
    while((c = getc(stdin)) != '\n' && c != EOF);
    printf("First name? (max %d characters)\n", NAME_MAX_SIZE);
    firstName = getStrInput(NAME_MAX_SIZE);
    printf("Last name? (max %d characters)\n", NAME_MAX_SIZE);
    lastName = getStrInput(NAME_MAX_SIZE);

    users[ARRAY_SIZE].userID = ARRAY_SIZE;
    strncpy(users[ARRAY_SIZE].firstName, firstName, NAME_MAX_SIZE);
    strncpy(users[ARRAY_SIZE].lastName, lastName, NAME_MAX_SIZE);
    ARRAY_SIZE++;
}
