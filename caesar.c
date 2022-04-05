#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>

// Joseph Ekpo
// HarvardX CS50
// Professor Malan

// PSET 2.2 Caesar Text Encryption
// c(i) = (p(i) + k) % 26

//Method Declaration
string cipherText(string input, int key);
char shift(char x, int key);


int main(int argc, char* argv[])
{
    bool keyExists = (argv[1] != NULL) ? (1) : (0) ;
    int charCount = 0;

    if(keyExists)
    {
    string keyAsString = argv[1];

    for(int i=0; i<strlen(argv[1]); i++)
    {
        if(isalpha(keyAsString[i]))
        {
            charCount++;
        }
    }

    }


    if(!keyExists || charCount > 0)
    {
        printf("Usage: ./caesar\n");
        return 1;
    }


    // Get key from command-line & validate
    int key;
    int valueCheck;
    string zero = "0";

    //key = atoi(argv[1]);

    bool keyNotZero = strcmp(argv[1], zero);
    int keyCheck = strcmp(argv[1], zero);
    valueCheck = atoi(argv[1]);

    bool isNonNumeric = (valueCheck == 0 && (keyCheck != 0)) ? (1) : (0);


    if(!keyNotZero)
    {
        key = 0;
    }
    else if(valueCheck < 0 || isNonNumeric || argc > 2)
    {
        printf("Usage: ./caesar\n");
        return 1;
    }
    else
    {
        key = valueCheck;
    }



	// Get user text
	string userText = get_string("Text: ");




	// Display ciphered text based on key value or valueless key (0)

	if(key == 0)
	{
		printf("%s\n", userText);
	}
	//else if(isBadKey)
	//{
	//    printf("Usage: ./caesar key");
//	}
	else
	{
	    printf("ciphertext: %s\n", cipherText(userText, key));
	}

//	printf("\nCommand-line argument: %d\n", pre_key);

}

// Take user text and convert to cipher
string cipherText(string input, int key)
{
	string cipherText = input;
	// char newText[strlen(input)];

	// Convert users input to cipher text

	for(int i=0; i<strlen(input); i++)
	{
		cipherText[i] = shift(input[i], key);
	}



	return cipherText;
}

// Ciphers text based on key then returns ciphered character with matching case
char shift(char x, int key)
{
    // Lower --> 97(a)-122(z)
	// Upper --> 65(A)-90(Z)

char letter;
int charASCII;
int resultASCII;
int alphabetRange = 26;
int zTarget = 0;
int yTarget = 0;
// Subtract 1 from original ASCII values to account for cycling
int a = 96, A = 64;

letter = x;

charASCII = (int)letter;
bool isUpper = (charASCII >= 65 && charASCII <= 90) ? (1) : (0);
bool isLower = (charASCII >= 97 && charASCII <= 122) ? (1) : (0);
bool hasPunc = (charASCII >= 32 && charASCII <= 127) ? (1) : (0);
bool needsReset = false;

resultASCII = charASCII + key;

/*
printf("\nCharacter: %c\n", letter);
printf("Key: %d\n\n", key);

printf("ASCII index: %d\n", resultASCII);
*/

//Normal Conditions
if(isUpper)
{
    // If the key shifts the value past Z
    if(resultASCII > 90)
    {
        for(int i=charASCII; i<=resultASCII; i++)
        {

            if(i>90)
            {
            yTarget++;
                if(yTarget > 26)
                {
                    yTarget = 1;
                }
                else
                {
                    /*Do nothing*/;

                }
            }



        }

        return((char)(A + yTarget));

    }
    else
    {
       return((char)resultASCII);
    }

}
else if(isLower)
{
    // If the key shifts the value past z
     if(resultASCII > 122)
    {
        for(int i=charASCII; i<=resultASCII; i++)
        {

            if(i>122)
            {
            yTarget++;
                if(yTarget > 26)
                {
                    yTarget = 1;
                }
                else
                {
                    /* do nothing*/;

                }
            }

        }

        return((char)(a + yTarget));

    }
    else
    {
        return((char)resultASCII);
    }


}
else if(hasPunc)
{
    return(x);
}
else
{
    printf("N/A\n");
    return 0;
}


}