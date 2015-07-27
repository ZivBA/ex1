#include <stdio.h>

// constants for ASCII table
#define LESS_THAN_5_START 48
#define LESS_THAN_5_END 52
#define GEQ_5_START 53
#define GEQ_5_END 57
#define LOWER_CASE_START 97
#define UPPER_CASE_START 65
#define UPPER_CASE_END 90
#define LOWE_CASE_END 122
#define MAX_CHARS_TO_READ_FROM_USER_INPUT_DUDE 50

int main() {
    const int UPPER_TO_LOWER_DIFF = 32;
    char input[MAX_CHARS_TO_READ_FROM_USER_INPUT_DUDE];
    char output[MAX_CHARS_TO_READ_FROM_USER_INPUT_DUDE];

    for (unsigned int i = 0; i<sizeof(input); i++){
        input[i]=output[i]=0;
    }
    scanf("%50[^\n]", input);

    for (unsigned int i = 0; i < sizeof(input); i++) {
        int temp = (int)input[i];
        if (temp >=LESS_THAN_5_START && temp <= LESS_THAN_5_END){
            output[i] = '0';
        }
        else if(temp >= GEQ_5_START && temp <= GEQ_5_END){
            output[i] = '8';
        }
        else if (temp >= UPPER_CASE_START && UPPER_CASE_END <= 90) {
            output[i] = (char)(input[i] + UPPER_TO_LOWER_DIFF);
        } else if (temp >= LOWER_CASE_START && temp <= LOWE_CASE_END) {
            output[i] = (char)(input[i] - UPPER_TO_LOWER_DIFF);
        } else {
            output[i]=input[i];
        }

    }

    printf("\"");
    for (unsigned int j = 0; j < sizeof(input); ++j) {
        printf("%c",input[j]);
    }
    printf("\"");
    printf(" -> \"");

    for (unsigned int j = 0; j < sizeof(input); ++j) {
        printf("%c",output[j]);
    }

    printf("\"\n");
    return 0;
}