
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char password[100];
    int upper = 0, lower = 0, digit = 0, special = 0;

    printf("Enter your password: ");
    scanf("%99s", password);

    int len = strlen(password);

    for (int i = 0; i < len; i++) {
        if (isupper((unsigned char)password[i]))
            upper = 1;
        else if (islower((unsigned char)password[i]))
            lower = 1;
        else if (isdigit((unsigned char)password[i]))
            digit = 1;
        else
            special = 1;
    }

    printf("\nPassword length: %d\n", len);

    if (len >= 8 && upper && lower && digit && special)
        printf("Strength: Strong\n");
    else {
        printf("Strength: Needs improvement\n");

        if (len < 8) printf("- Use at least 8 characters\n");
        if (!upper) printf("- Add an uppercase letter\n");
        if (!lower) printf("- Add a lowercase letter\n");
        if (!digit) printf("- Add a number\n");
        if (!special) printf("- Add a special character\n");
    }

    return 0;
}
