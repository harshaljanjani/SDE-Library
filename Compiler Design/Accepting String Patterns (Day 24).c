#include <stdio.h>
int matchPattern(const char *string, const char *pattern)
{
    // if (*pattern == '\0'):
    // This condition checks if the pattern string has reached its end.
    // If it has, it means we have successfully matched all characters in the pattern, so we check if the input string has also reached its end.
    // If the input string has also reached its end, we return 1 (indicating a match), otherwise, we return 0 (indicating a mismatch).
    if (*pattern == '\0')
    {
        return *string == '\0';
    }
    // if (*(pattern + 1) == '*'):
    // This condition checks if the next character in the pattern is an asterisk (*).
    // If it is, it means we have encountered a zero or more occurrences operator (*) after a character in the pattern.
    // We need to handle this special case, so we enter a loop that continues as long as the current character in the input string matches the character in the pattern (or the pattern character is a dot . indicating a wildcard).
    // Inside the loop, we make a recursive call to matchPattern with the updated input string and skipping the current character and the asterisk in the pattern (e.g., matchPattern(str, pattern + 2)).
    // After the loop, we make another recursive call to matchPattern with the updated input string and skipping the current character and the asterisk in the pattern (e.g., matchPattern(str, pattern + 2)).
    // We return the result of the recursive call, indicating if there was a match or not.
    if (*(pattern + 1) == '*')
    {
        while (*string != '\0' && (*string == *pattern) || *pattern == '.')
        {
            if (matchPattern(string, pattern + 2))
            {
                return 1;
            }
            string++;
        }
        return matchPattern(string, pattern + 2);
    }
    // if (*str != '\0' && (*str == *pattern || *pattern == '.'))
    // This condition checks if the input string is not empty and the current character in the input string matches the current character in the pattern or if the pattern character is a dot . (wildcard).
    // If the condition is true, we make a recursive call to matchPattern with the updated input string and pattern, moving to the next character in both strings (e.g., matchPattern(str + 1, pattern + 1)).
    // We return the result of the recursive call, indicating if there was a match or not.
    if (*string != '\0' && (*string == *pattern || *pattern == '.'))
    {
        return matchPattern(string + 1, pattern + 1);
    }
}

int main()
{
    const char *pattern1 = "a*";
    const char *pattern2 = "a*b+";
    const char *testString1 = "aaaa"; // Should match pattern1 and pattern2
    const char *testString2 = "abb";  // Should match pattern2
    const char *testString3 = "b";    // Should not match any pattern
    printf("Test String: %s\n", testString1);
    printf("Pattern '%s': %s\n", pattern1, matchPattern(testString1, pattern1) ? "Matches" : "Doesn't match");
    printf("Pattern '%s': %s\n", pattern2, matchPattern(testString1, pattern2) ? "Matches" : "Doesn't match");
    printf("\nTest String: %s\n", testString2);
    printf("Pattern '%s': %s\n", pattern1, matchPattern(testString2, pattern1) ? "Matches" : "Doesn't match");
    printf("Pattern '%s': %s\n", pattern2, matchPattern(testString2, pattern2) ? "Matches" : "Doesn't match");
    printf("\nTest String: %s\n", testString3);
    printf("Pattern '%s': %s\n", pattern1, matchPattern(testString3, pattern1) ? "Matches" : "Doesn't match");
    printf("Pattern '%s': %s\n", pattern2, matchPattern(testString3, pattern2) ? "Matches" : "Doesn't match");
    return 0;
}