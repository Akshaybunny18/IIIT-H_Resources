/* 
MidSem Lab exam, Problem 1
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAMES 10     // Maximum number of names
#define NAME_LENGTH 30   // Maximum length of each name

int main() {
    char *names[MAX_NAMES]; // Array to hold pointers to names
    int count = 0;          // Current number of names
    int op;                 // Operation code

    while (1) {
        scanf("%d", &op);
        
        if (op == 0) {
            break; 
        } else if (op == 1) {
            // 1. TODO: Add a name, use malloc()
            //
            //
            //
            //
            names[count]=(char*)malloc(NAME_LENGTH * sizeof(char));
            if (names[count] == NULL) {
                printf("Memory allocation failed!\n");
                return 1; 
            }
            if(count>=MAX_NAMES){
            	printf("Cannot add more names. Maximum limit reached.");
            	continue ;
            }
            scanf("%s", names[count]);
            count++;
        } else if (op == 2) {
        	//if()
            // 1. TODO: Display names
            //
            printf("Names:\n");
            for(int i=0;i<count;i++){
            	printf("%s\n",names[i]);
            }
        } else {
            printf("Invalid operation. Try again.\n");
        }
    }

    // 3. TODO: Free allocated memory
    for(int i=0;i<count;i++){
        free(names[i]);
    }
    return 0; 
}
