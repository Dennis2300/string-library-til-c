#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strlib.h"

int main()
{
    // test string that will be used for testing
    const char *test_string = "Hello, World!";

    // stringLength test
    printf("stringLength:: %d\n", stringLength(test_string));

    // stringConcat test
    char *concatenated_string = stringConcat("Hello, ", "World!");
    printf("stringConcat:: %s\n", concatenated_string);
    free(concatenated_string); // free the memory which means delloacte the memory

    // stringSlice test
    char *sliced_string = stringSlice(test_string, 0, 5);
    printf("stringSlice:: %s\n", sliced_string);
    free(sliced_string); // free the memory which means delloacte the memory

    // stringIndexOf test
    int indexOfResult = stringIndexOf(test_string, "World");
    printf("string_index_of:: %d\n", indexOfResult);

    // stringReplace test
    char *replaced_string = stringReplace(test_string, "World", "Coders");
    printf("string_replace:: %s\n", replaced_string);
    free(replaced_string); // free the memory which means delloacte the memory

    // stringToLowerCase test
    char *lowercase_string = stringToLowerCase(test_string);
    printf("string_to_lower_case:: %s\n", lowercase_string);
    free(lowercase_string); // free the memory which means delloacte the memory

    // stringToUpperCase test
    char *uppercase_string = stringToUpperCase(test_string);
    printf("string_to_upper_case:: %s\n", uppercase_string);
    free(uppercase_string); // free the memory which means delloacte the memory

    // stringTrim test
    char *trimmed_string = stringTrim("   Hello, World!   ");
    printf("string_trim:: %s\n", trimmed_string);
    free(trimmed_string); // free the memory which means delloacte the memory

    return 0;
}
