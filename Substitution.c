#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function prototypes
bool is_valid_key(char key[]);
char substitute(char letter, char key[]);

int main(int argc, char *argv[])
{
    // Check if there's exactly one command-line argument (the key)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Validate the key
    char *key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext from the user
    char plaintext[1000];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);  // Use fgets to get input with spaces

    // Encrypt the plaintext using the substitution cipher
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Encrypt each letter, leaving non-alphabetic characters unchanged
        printf("%c", substitute(plaintext[i], key));
    }
    printf("\n");

    return 0;
}

// Function to validate the key
bool is_valid_key(char key[])
{
    // Key must be 26 characters long
    if (strlen(key) != 26)
    {
        return false;
    }

    bool seen[26] = {false};

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))  // Check if each character is alphabetic
        {
            return false;
        }

        char letter = tolower(key[i]);

        // Check for duplicate letters
        if (seen[letter - 'a'])
        {
            return false;
        }
        seen[letter - 'a'] = true;
    }

    return true;
}

// Function to substitute a letter using the key
char substitute(char letter, char key[])
{
    if (isalpha(letter))
    {
        if (isupper(letter))
        {
            // Substitute uppercase letters
            return toupper(key[letter - 'A']);
        }
        else
        {
            // Substitute lowercase letters
            return tolower(key[letter - 'a']);
        }
    }
    else
    {
        // Non-alphabetic characters remain unchanged
        return letter;
    }
}
