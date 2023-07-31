#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random alphanumeric character
char generaterrandomchar()
{
    int randomchar = rand() % 16; // Random value from 0 to 15
    if (randomchar < 10)
        return '0' + randomchar;
    else
        return 'A' + (randomchar - 10);
}

// Function to generate a random alphanumeric string of random length between 3 and 10 characters
void generaterandomstr(char *randomstr)
{
	int i;
    int l = rand() % 8 + 3; // Random length between 3 and 10
    for (i = 0; i < l; i++) {
        randomstr[i] = generaterrandomchar();
    }
    randomstr[l] = '\0'; // Null-terminate the string
}

// Function to determine the highest base of the alphanumeric string
int base(char *randomstr)
{
    int b = 0;
    while (*randomstr != '\0')
	{
        int r;
        if (*randomstr >= '0' && *randomstr <= '9')
            r = *randomstr - '0';
        else if (*randomstr >= 'A' && *randomstr <= 'F')
            r = *randomstr - 'A' + 10;
        else
		{
            printf("Invalid character in the string: %c\n", *randomstr);
            exit(1);
        }

        if (r > b)
            b = r;

        randomstr++;
    }
    return b+1; // Adding 1 to get the highest base
}

int main()
{
    // Initialize random seed
    srand(time(0));

    char randomstr[11]; // Maximum length will be 10 + 1 (null-terminator)
    
    // generate a random alphanumeric string
    generaterandomstr(randomstr);
    
    //printf("Random Alphanumeric String: %s\n", rs);

    int B = base(randomstr);
    printf("The Highest Base of %s is %d\n", randomstr, B);

    return 0;
}
