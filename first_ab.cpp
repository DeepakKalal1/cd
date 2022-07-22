#include <stdio.h>
#include <ctype.h>
#define MAX 10
void FIRST(char[], char);
void addToResultSet(char[], char);
int numOfProductions;
char productionSet[MAX][MAX];
char input[MAX];
int main()
{
    int i, j, inp;
    char choice;
    char c;
    char result[20];
    printf("Enter the number of production rules: ");
    scanf("%d", &numOfProductions);
    for (i = 0; i < numOfProductions; i++)
    {
        printf("\tEnter productions rule %d : ", i + 1);
        scanf("%s", productionSet[i]);
    }
    printf("\nEnter the number of symbols for which FIRST is required (maximum %d): ", MAX);
    scanf("%d", &inp);
    printf("\nEnter the symbols for which FIRST is required:\n");
    for (i = 0; i < inp; i++) 
    {
    	printf("\tEnter symbol %d: ", i+1); 
    	scanf("%s", &input[i]);
    }
    printf("Array of input symbols: [");
    for (i = 0; i < inp; i++)
    	printf(" %c ", input[i]);
    printf("]\n");
    printf("\nFIRST of the characters in the input array:\n");
    j = 0;
    do
    {
        FIRST(result, input[j]);
        printf("\tFIRST(%c) = {", input[j]);
        for (i = 0; result[i] != '\0'; i++)
            printf(" %c ", result[i]);
        printf("}\n");
        j++;
    } while (j < inp);
    return 0;
}

void FIRST(char *Result, char c)
{
    int i, j, k;
    char subResult[20];
    int foundEpsilon;
    subResult[0] = '\0';
    Result[0] = '\0';
    if (!(isupper(c)))
    {
        addToResultSet(Result, c);
        return;
    }
    for (i = 0; i < numOfProductions; i++)
    {
        if (productionSet[i][0] == c)
        {
            if (productionSet[i][3] == '$')
                addToResultSet(Result, '$');
            else
            {
                j = 3;
                while (productionSet[i][j] != '\0')
                {
                    foundEpsilon = 0;
                    FIRST(subResult, productionSet[i][j]);
                    for (k = 0; subResult[k] != '\0'; k++)
                        addToResultSet(Result, subResult[k]);
                    for (k = 0; subResult[k] != '\0'; k++)
                        if (subResult[k] == '$')
                        {
                            foundEpsilon = 1;
                            break;
                        }
                    if (!foundEpsilon)
                        break;
                    j++;
                }
            }
        }
    }
}

void addToResultSet(char Result[], char val)
{
    int k;
    for (k = 0; Result[k] != '\0'; k++)
        if (Result[k] == val)
            return;
    Result[k] = val;
    Result[k + 1] = '\0';
}
