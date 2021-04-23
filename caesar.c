#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, string argv[])
{
   if (argc != 2){printf("Insert valid key\n"); return 1;}
   for(int i = 0, n = strlen(argv[1]); i < n; i++)
   {
       if (isdigit(argv[1][i])){}
       else {printf("Usage: ./caesar key\n"); return 1; };
   };

   int key = atoi(argv[1]);
   //printf("%i\n", key);

    // get plain text
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");
    
    // convert to  ciphertext
    for (int i = 0, n = strlen(plain); i < n; i++){
        char c = (plain[i] + key) % 122;
        printf("%c", c);
        }
    
    printf("\n");
}