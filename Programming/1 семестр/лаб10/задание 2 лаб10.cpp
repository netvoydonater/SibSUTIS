//2.	Во введенном тексте найти количество  повторений каждого слова. Одинаковые слова дважды не выводить.
#include<stdio.h>
#include<stdlib.h>
#include <string.h>


bool func(char* offer, char* word, int j)
{
    int k, flag = 0;
    int count1 = 0;
    while (count1 < j)
    {
        char word1[256] = "";
        k = 0;
        while (offer[count1] != ' ')
        {
            word1[k] = offer[count1];
            count1++;
            k++;
        }
        if (strcmp(word, word1) == 0)
            flag++;
        count1 += 1;
    }
    if (flag == 0)
        return true;
    else
        return false;
}


int main()
{
    int j = 0, size = 0, size_consolt = 0, counten = 0;
    char offers[256], consolt[256] = "";
    char* offer;
    printf("Enter text: ");
    offer = gets_s(offers);
    while (offer[j] != '\0')
        j++;
    offer[j] = ',';
    while (size < j)
    {
        char word1[256] = "";
        int count = size, k = 0, flag = 0;
        while (offer[count] != ',')
        {
            word1[k] = offer[count];
            count++;
            k++;
        }
        int count1 = 0;
        while (count1 < j)
        {
            char word[256] = "";
            k = 0;
            while (offer[count1] != ',')
            {
                word[k] = offer[count1];
                count1++;
                k++;
            }
            if (strcmp(word, word1) == 0)
                flag++;
            count1 += 2;
        }
        if (flag == 1)
        {
            while (offer[size] != ',')
            {

                consolt[size_consolt] = offer[size];
                size_consolt++;
                size++;
                counten++;
            }
            consolt[size_consolt] = ' ';
            size_consolt += 1;
        }
        else if (func(consolt, word1, size_consolt)) {

            while (offer[size] != ',')
            {
                consolt[size_consolt] = offer[size];
                size_consolt++;
                size++;
                counten++;
            }
            consolt[size_consolt] = ' ';
            size_consolt += 1;
        }
        else
        {
            while (offer[size] != ',')
            {
                size++;
            }
            printf("WORD %s %d \n", word1, flag);
        }

        size += 2;
    }
    printf("%s", consolt);
    return 0;

}