#include <stdio.h>

int main2() {
    const int UPPER_TO_LOWER_DIFF = 32;
    char input[50];
    char output[50];
    for (unsigned int i = 0; i<sizeof(input); i++){
        input[i]=output[i]=0;
    }
    scanf("%50[a-zA-Z0-9 ]", input);

    for (unsigned int i = 0; i < sizeof(input); i++) {
        int temp = (int)input[i];
        if (temp >=48 && temp <= 52){
            output[i] = '0';
        }
        else if(temp >= 52 && temp <= 57){
            output[i] = '8';
        }
        else if (temp >= 65 && temp <= 90) {
            output[i] = (char)(input[i] + UPPER_TO_LOWER_DIFF);
        } else if (temp >= 97 && temp <= 122) {
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