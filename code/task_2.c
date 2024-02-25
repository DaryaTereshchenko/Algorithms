#include <stdio.h>
#include <string.h>

void rleCompression(char string[], int length) {
    char result[2 * length]; // Maximum length of result string

    int count = 1;
    int result_index = 0;

    for (int i = 1; i < length; i++) {
        if (string[i] == string[i - 1]) {
            count++;
        } else {
            result[result_index++] = count + '0'; // Convert count to char and store it
            result[result_index++] = string[i - 1]; // Store the character
            count = 1;
        }
    }

    // Add the last character and its count
    result[result_index++] = count + '0'; // Convert count to char and store it
    result[result_index++] = string[length - 1]; // Store the last character
    result[result_index] = '\0'; // Add null terminator to end the string

    printf("RLE-encoded string: %s\n", result);
}

int main() {
    char string[] = "AAABBAAAA";
    int length = strlen(string);
    rleCompression(string, length);
    return 0;
}
