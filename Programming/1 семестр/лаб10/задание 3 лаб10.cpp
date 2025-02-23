//3.	Список фамилий вводится через запятую в виде строки. Упорядочить   фамилии по алфавиту.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{

    printf("Lastnames: ");
    char offer[256], list[256] = "";
    char word[256][256]{};
    int size = 0, j = 0, l = 0;
    gets_s(offer);
    while (offer[size] != '\0')
        size++;
    offer[size] = ',';
    while (j < size)
    {
        char word1[256] = "";
        int count = j, k = 0, flag = 0;
        while (offer[count] != ',')
        {
            word1[k] = offer[count];
            count++;
            k++;
            j++;
        }
        j += 2;
        strcpy_s(word[l], word1);
        l++;
    }


    char word1[256];
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < l - i; j++)
        {
            if (strcmp(word[j], word[j + 1]) > 0)
            {
                strcpy_s(word1, word[j]);
                strcpy_s(word[j], word[j + 1]);
                strcpy_s(word[j + 1], word1);
            }
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%s\n", word[i]);
    }
    return 0;
}