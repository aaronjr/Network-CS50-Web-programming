#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    char key[26] = "";

    // check 2 aruguments
    if (argc != 2)
    {
        printf("Insert valid key\n"); 
        return 1;
    }
    // check for 26 characters
    if (strlen(argv[1]) != 26)
    {
        printf("Insert 26 characters\n");
        return 1;
    }
    //check for duplicates - HERE!    
    for (int o = 0, m = strlen(argv[1]); o < m; o++)
    {
        for (int p = o + 1; p < m; p++)
        {
            if (argv[1][o] == argv[1][p])
            {
                return 1; 
                printf("No duplicate characters\n");
            }
        }
    }
    // check for alphabeetical characters
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
        {
            strncat(key, &argv[1][i], 1);
        }
        else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            char q = (argv[1][i] + 32);
            strncat(key, &q, 1);
        }
        else
        {
            printf("Insert 26 alphabetical characters\n"); 
            return 1;
        }
    }

    // get plain text
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    // to cipher 
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (plain[i] >= 'a' && plain[i] <= 'z')
        {
            printf("%c", key[plain[i] - 'a']);
        }
        else if (plain[i] >= 'A' && plain[i] <= 'Z')
        {
            printf("%c", key[plain[i] - 'A'] - 32);
        }
        else
        { 
            printf("%c", plain[i]);
        }
    }
    
    //print new line
    printf("\n");
    //return 0
    return 0;
}



