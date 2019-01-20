#include <stdio.h>
#include <stdlib.h>
#include <string.h>





char *getStrInput(int size){
    char *str = (char *)malloc(size + 2);
    char key[] = {'\n'};
    fgets(str, size + 2, stdin);
    if (strpbrk(str, key)) {
        if ((strlen(str) > 0) && (str[strlen (str) - 1] == '\n')) {
            str[strlen (str) - 1] = '\0';
        }
        return str;
    } else {
        char c;
        while((c = getc(stdin)) != '\n' && c != EOF);
        return NULL;
    }
}

int getNumber(){
    int number = 0;
    scanf(" %d", &number);
    return number;
}

void printWhile(int i, char *str) {
    do {
        printf("%d: %s\n", i, str);
        i--;
    } while (i > 0);
}

void printFor(int number, char *str){
    for (int i=1; i<=number; i++) {
        printf("%d: %s\n", i, str);
    }
}