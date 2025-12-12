#include <iostream>
#include <cstring>

int main() {
    char str[1000000], temp;
    int i = 0, z = 0;
    std::cin >> str;
    int n = std::strlen(str);
    for (int i = 0; i < (n / 2); i++) {
        for (int j = i + 1; j < n - i - 1; j++) {
            if (str[i] == str[j]) {
                temp = str[j];
                str[j] = str[n - 1 - i];
                str[n - 1 - i] = temp;
                z += 1;
                break;
            }
        }
    }
    char hmm[n];
    std::strcpy(hmm, str);
    for (int i = 0; i < n / 2; i++) {
        temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
    if (std::strcmp(hmm, str) == 0) {
        std::cout << hmm;
    }
    else {
        std::cout << "NO SOLUTION";
    }
    return 0;
}
