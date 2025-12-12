#include <stdio.h>
#include <stdlib.h>

void writeToFile(const char *filename);
void readFromFile(const char *filename);
void appendToFile(const char *filename, const char *response);

int main() {
    const char *filename = "info.txt";
    char response;

    // Step 1: Write to file (if needed, you can comment this out if file already exists)
    writeToFile(filename);

    // Step 2: Read the content of the file
    readFromFile(filename);

    // Step 3: Ask the user if the statement is true or false
    printf("\nIs the above statement true? (y/n): ");
    scanf(" %c", &response);

    // Step 4: Append the user's response to the file
    if (response == 'y' || response == 'Y') {
        appendToFile(filename, "True");
        printf("You said it is true.\n");
    } else if (response == 'n' || response == 'N') {
        appendToFile(filename, "False");
        printf("You said it is false.\n");
    } else {
        appendToFile(filename, "Invalid input");
        printf("Invalid input.\n");
    }

    return 0;
}

// Function to write content to a file
void writeToFile(const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open the file for writing.\n");
        exit(1);
    }

    // Writing the initial content to the file
    fprintf(file, "Harshvardhan is the TA for the tut today and now he is facing issue with handling UG1 and struggling to make them understand.\n");

    // Close the file after writing
    fclose(file);
}

// Function to read the content from a file
void readFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open the file for reading.\n");
        exit(1);
    }

    char buffer[256];  // Buffer to store the content read from the file
    printf("Reading from file:\n");

    // Read and display the file content
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    // Close the file after reading
    fclose(file);
}

// Function to append content to a file
void appendToFile(const char *filename, const char *response) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Could not open the file for appending.\n");
        exit(1);
    }

    // Appending the response to the file
    fprintf(file, "Response: %s\n", response);

    // Close the file after appending
    fclose(file);
}
