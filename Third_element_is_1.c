#include <stdio.h>
#define SIZE 10
int main() {
    char str[SIZE], state = 'A';
    int i = 0;
    printf("Enter input containing 0 and 1 only: ");
    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] != '0' && str[i] != '1') {
            printf("\nIllegal characters.\n");
            return 0;
        } 
        switch(state) {
            case 'A':
                if (str[i] == '0')
                    state = 'A';
                else if (str[i] == '1')
                    state = 'B';
                break;
            case 'B':
                if (str[i] == '0')
                    state = 'G';
                else if (str[i] == '1')
                    state = 'C';
                break;
            case 'C':
                if (str[i] == '0')
                    state = 'E';
                else if (str[i] == '1')
                    state = 'D';
                break;
            case 'D':
                if (str[i] == '0')
                    state = 'E';
                else if (str[i] == '1')
                    state = 'D';
                break;
            case 'E':
                if (str[i] == '0')
                    state = 'H';
                else if (str[i] == '1')
                    state = 'F';
                break;
            case 'F':
                if (str[i] == '0')
                    state = 'G';
                else if (str[i] == '1')
                    state = 'C';
                break;
            case 'G':
                if (str[i] == '0')
                    state = 'H';
                else if (str[i] == '1')
                    state = 'F';
                break;
            case 'H':
                if (str[i] == '0')
                    state = 'A';
                else if (str[i] == '1')
                    state = 'B';
                break;
        }
    } 
    if (state == 'D' || state == 'E' || state == 'F' || state == 'H') 
        printf("\nInput accepted.\n");
    else
        printf("\nInput rejected.\n");
    return 0;
}
