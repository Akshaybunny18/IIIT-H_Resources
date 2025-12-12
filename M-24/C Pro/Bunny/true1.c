#include <stdio.h>
#include <stdlib.h>

// Function to simulate the game
void p1(int* arr, int x, int a, int b, int m, int i, int j) {
    // Base case: all elements have been taken
    if (m == x) {
        // Player 1 wins if their score is greater than or equal to Player 2's score
        if (a >= b) {
            printf("true\n");
            exit(0); // Exit the program after printing the result
        }
        return ;
    }

    // If it's Player 1's turn, they can choose either the leftmost or rightmost element
    if (m % 2 == 0) {
        if (j >= 0) { // Take from the right
            p1(arr, x, a + arr[j], b, m + 1, i, j - 1);
        }
        if (i < x) { // Take from the left
            p1(arr, x, a + arr[i], b, m + 1, i + 1, j);
        }
    } 
    // If it's Player 2's turn, they can also choose either the leftmost or rightmost element
    else {
        if (j >= 0) { // Take from the right
            p1(arr, x, a, b + arr[j], m + 1, i, j - 1);
        }
        if (i < x) { // Take from the left
            p1(arr, x, a, b + arr[i], m + 1, i + 1, j);
        }
    }
}

int main() {
    int x;
    scanf("%d", &x);
    int arr[x];
    for (int i = 0; i < x; i++) {
        scanf("%d", &arr[i]);
    }

    // Start the recursive simulation
    p1(arr, x, 0, 0, 0, 0, x - 1);

    // If no result is printed in the recursion, output false
    printf("false\n");
    return 0;
}

