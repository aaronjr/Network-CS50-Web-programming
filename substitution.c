#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, string argv[])
{
    char key[26];
    // check 2 aruguments
   if (argc != 2){printf("Insert valid key\n"); return 1;}
   // check for 26 characters
   if(strlen(argv[1])!=26){printf("Insert 26 characters\n"); return 1;}
   // check for alphabeetical characters
   for(int i = 0, n = strlen(argv[1]); i < n; i++){
    if ( (argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z')){
          strncat(key, &argv[1][i], 1);
       }
   else {printf("Insert 26 alphabetical characters\n"); return 1;}
   }
   //string to key
   
   
   //test for key
   printf("The key is %s\n", key);

    // get plain text
    string plain = get_string("plaintext: ");
    printf("ciphertext: ");

    // to cipher
    for (int i = 0, n = strlen(plain); i < n; i++){
      if (plain[i] >= 'a' && plain[i] <= 'z'){
         char c = (((plain[i] - 'a') + key[plain[i] - 'a']) % 26) + 'a';
      printf("%c", c);}
      else if (plain[i] >= 'A' && plain[i] <= 'Z'){
         char c = (((plain[i] - 'A') + key[plain[i] - 'a']) % 26) + 'A';
      printf("%c", c);}
      else {printf("%c", plain[i]);}
     }


    //print new line
    printf("\n");
    //return 0
    return 0;
}


 
 