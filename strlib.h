#ifndef STRLIB_H
#define STRLIB_H

// This is all my JS string functions that will be implemented in C
int stringLength(const char *str);
char* stringConcat(const char *str1, const char *str2);
char* stringSlice(const char *str, int start, int end);
int stringIndexOf(const char *str, const char *substr);
char* stringReplace(const char *str, const char *old_substr, const char *new_substr);
char* stringToLowerCase(const char *str);
char* stringToUpperCase(const char *str);
char* stringTrim(const char *str);

#endif
