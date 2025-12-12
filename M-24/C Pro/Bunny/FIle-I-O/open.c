#include <stdlib.h>
#include <stdio.h>

int main() {
    /* File pointer to hold reference to our file */
    FILE *fPtr;

    // Open file in write mode. The path "data/file1.txt" is a relative path.
    fPtr = fopen("file1.txt", "r");

    /* fopen() returns NULL if the operation was unsuccessful */
    if (fPtr == NULL) {
        /* File not created, hence exit */
        printf("Unable to create file.\n");
        exit(0);
    }
        printf("File created successfully.\n");

printf("ptr add = %p\n",fPtr);
char ch;
while(ch != EOF)
{
    /* Read single character from file */
    ch = fgetc(fPtr);
    /* Print character read on console */
    putchar(ch);

}
printf("\n");
while(ch != EOF)
{
	    /* Read single character from file */
  ch = fgetc(fPtr);
     /* Print character read on console */
	printf("%c",ch);	     
}


  /* Repeat this 
if last read character is not EOF */

    /* Done with this file, close file to release resources */
    fclose(fPtr);

    return 0;
}

