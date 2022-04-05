#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

// Joseph Ekpo, CS50

/* Formula:::

index = 0.0588 * L - 0.296 * S - 15.8
L = Avg# of letters per 100 words
S = Avg# of sentences per 100 words

Avg per 100 calculation
(#oL * 100) / (#oW * 100)
(#oS * 100) / (#oW * 100)

*/
int countLetters(string input);
int countWords(string input);
int countSent(string input);

int main(void)
{

string text = get_string("Text: ");

int letterCount = countLetters(text);
int wordCount = countWords(text);
int sentCount = countSent(text);

printf("Total letter(s): %i\n", letterCount);
printf("Total word(s): %i\n", wordCount);
printf("Total sentence(s): %i\n", sentCount);

// Calculate reading level using Coleman-Liau index formula w/ values found for L & S
float L = ((float)letterCount / wordCount) * 100;
float S = ((float)sentCount / wordCount) * 100;
float index = (0.0588 * L - 0.296 * S - 15.8);

printf("Avg letters per 100 words: %.2f\n", L);
printf("Avg sentences per 100 words: %.2f\n", S);

printf("Index Calculation: %.2f\n", index);
int gradeLevel = round(index);

if(index < 1)
{
    printf("Before Grade 1\n");

}
else if(index > 16)
{
    printf("Grade 16+\n");

}
else
{
    printf("Grade: %i\n", gradeLevel);

}

// printf("Grade: %.0f\n", index);

}

int countLetters(string input)
{

    int totalLetters = 0;

    for(int i=0; i<strlen(input); i++)
    {
        // Use ASCII to identify letters A-z
        if(input[i] <= 122 && input[i] >= 65)
        {
            totalLetters++;
        }
    }

    return totalLetters;
}

int countWords(string input)
{
    int totalWords = 0;
    int spaces = 0;

    // Use ASCII indentify words seperated by a space
    for(int i=0; i<strlen(input); i++)
    {
        if((int)input[i] == 32)
        {
            spaces++;
        }

    }

    totalWords = spaces + 1;

    return totalWords;
}

int countSent(string input)
{
    int totalSent = 0;

    for(int i=0; i<strlen(input); i++)
    {
        // Using guidlines for sentences, identify a sentence by its ending with ".", "?", or "!"
        if(input[i] == 33 || input[i] == 46 || input[i] == 63)
        {
        totalSent++;
        }
    }

    return totalSent;
}