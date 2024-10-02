#include "strlib.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// This will return the length of the string
int stringLength(const char *str)
{
    return strlen(str);
}

// This will concatenate two strings
// which means it will combine two strings into one
char *stringConcat(const char *str1, const char *str2)
{                               // It will take two strings as input
    size_t len1 = strlen(str1); // It will get the length of the first string
    size_t len2 = strlen(str2); // It will get the length of the second string
    // malloc is used to allocate memory so that we can store the concatenated string
    // because we don't know the length of the concatenated string so we will allocate memory dynamically
    char *result = malloc(len1 + len2 + 1); // it will put the concatenated string in the result variable
    if (result)
    {                         // if the result is not NULL
        strcpy(result, str1); // it will copy the first string into the result
        strcat(result, str2); // it will concatenate the second string into the result
    }
    return result; // it will return the concatenated string
}

// This will slice the string
// which means it will return the part of the string
char *stringSlice(const char *str, int start, int end)
{ // it will take the string, start index and end index as input
    if (start < 0)
        start = 0; // if the start index is less than 0 then it will be 0
    if (end > strlen(str))
        end = strlen(str); // if the end index is greater than the length of the string then it will be the length of the string
    if (start > end)
        return NULL; // if the start index is greater than the end index then it will return NULL

    // malloc is used to allocate memory so that we can store the sliced string
    char *result = malloc(end - start + 1); // it will put the sliced string in the result variable
    if (result)
    {
        strncpy(result, str + start, end - start); // it will copy the sliced string into the result
        result[end - start] = '\0'; // it will put the null character at the end of the result
    }
    return result;
}

// This will return the index of the substring
// which means it will return the position of the substring in the string
int stringIndexOf(const char *str, const char *substr) // it will take the string and the substring as input
{
    char *pos = strstr(str, substr); // strstr is used to find the substring in the string
    if (pos) // if the substring is found
    {
        return pos - str; // it will return the position of the substring
    }
    return -1;
}

// This will replace the substring with the new substring
// It will take the string you want to replace and replace it with your new string
char *stringReplace(const char *str, const char *old_substr, const char *new_substr) 
{
    // strstr is used to find the substring in the string
    char *pos = strstr(str, old_substr); // it will find the old substring in the string
    if (!pos) // if the substring is not found
        return strdup(str); // it will return the string as it is

    // size_t is unsigned data type in C
    // it is used to store the size of the string
    size_t len_before = pos - str; // it will get the length before the substring
    size_t len_old = strlen(old_substr); // it will get the length of the old substring
    size_t len_new = strlen(new_substr); // it will get the length of the new substring

    // malloc is used to allocate memory so that we can store the replaced string
    char *result = malloc(len_before + len_new + strlen(pos + len_old) + 1); // it will put the replaced string in the result variable
    if (result) // if the result is not NULL
    {
        // we put the substrings together to form the new string
        strncpy(result, str, len_before); // it will copy the string before the substring into the result
        strcpy(result + len_before, new_substr); // it will copy the new substring into the result
        strcpy(result + len_before + len_new, pos + len_old); // it will copy the string after the substring into the result
    }
    return result;
}

// This will convert the string to lowercase
char *stringToLowerCase(const char *str) // Receives a string as input
{
    char *result = strdup(str); // strdup is used to copy the string
    if (result) // if the result is not null
    {
        // This will loop through the string
        for (char *str = result; *str; ++str)
        {
            // tolower is used to convert the character to lowercase
            *str = tolower(*str);
        }
    }
    return result;
}

// This will convert the string to uppercase
char *stringToUpperCase(const char *str) // Receives a string as ipnut
{
    char *result = strdup(str); // strdup is used to copy the string
    if (result) // if the result is not null
    {
        // This will loop through the string
        for (char *str = result; *str; ++str)
        {  
            // toupper is used to convert the character to uppercase
            *str = toupper(*str);
        }
    }
    return result;
}

// This will remove the leading and trailing whitespaces
// which means it will remove the spaces from the start and end of the string if there are any
char *stringTrim(const char *str) // Takes a string as input
{
    const char *start = str; // it will get the start of the string
    while (isspace(*start)) // it will check if there are any spaces at the start of the string
        ++start; // if there are spaces then it will move to the next character

    const char *end = str + strlen(str) - 1; // it will get the end of the string
    while (end > start && isspace(*end)) // it will check if there are any spaces at the end of the string
        --end; // if there are spaces then it will move to the previous character

    // size_t is unsigned data type in C
    // It is used to store the unknown size of the string
    size_t len = end - start + 1; // it will get the length of the string after removing the spaces
    char *result = malloc(len + 1); // malloc is used to allocate memory so that we can store the trimmed string
    if (result)
    {
        strncpy(result, start, len); // it will copy the trimmed string into the result
        result[len] = '\0'; // it will put the null character at the end of the result
    }
    return result;
}
