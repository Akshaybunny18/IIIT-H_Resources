#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    int id;
    char name[100];
    float avg;
};

int main() {
    FILE *file = fopen("students.txt", "r");
    if (!file) {
        printf("Error opening file\n");
        return 1;
    }

    char buffer[1000];
    int n = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        n++;
    }
    rewind(file);

    struct student students[n];

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d,", &students[i].id);

        int j = 0;
        char c;
        while ((c = fgetc(file)) != ',' && c != EOF) {
            students[i].name[j++] = c;
        }
        students[i].name[j] = '\0';

        float grade, sum = 0;
        int gradeCount = 0;

        while (fscanf(file, "%f", &grade) == 1) {
            sum += grade;
            gradeCount++;
            c = fgetc(file);
            if (c == '\n' || c == EOF) {
                break;
            }
        }
        students[i].avg = (gradeCount > 0) ? sum / gradeCount : 0;
    }
    fclose(file);

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                struct student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("Name:%s, Score: %.2f\n", students[i].name, students[i].avg);
    }
printf("\n");
    return 0;
}
