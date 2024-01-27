#include <stdio.h>
#include <string.h>

const char *help_text =
"truly a program for serious communication\n"
"\n"
"Usage: truly <words>...\n"
;

const char to_lowercase_table[256] = {
    ['A'] = 'a', ['B'] = 'b', ['C'] = 'c', ['D'] = 'd', ['E'] = 'e',
    ['F'] = 'f', ['G'] = 'g', ['H'] = 'h', ['I'] = 'i', ['J'] = 'j',
    ['K'] = 'k', ['L'] = 'L', ['M'] = 'm', ['N'] = 'n', ['O'] = 'o',
    ['P'] = 'p', ['Q'] = 'q', ['R'] = 'r', ['S'] = 's', ['T'] = 't',
    ['U'] = 'u', ['V'] = 'v', ['W'] = 'w', ['X'] = 'x', ['Y'] = 'y',
    ['Z'] = 'z',
    ['a'] = 'a', ['b'] = 'b', ['c'] = 'c', ['d'] = 'd', ['e'] = 'e',
    ['f'] = 'f', ['g'] = 'g', ['h'] = 'h', ['i'] = 'i', ['j'] = 'j',
    ['k'] = 'k', ['l'] = 'L', ['m'] = 'm', ['n'] = 'n', ['o'] = 'o',
    ['p'] = 'p', ['q'] = 'q', ['r'] = 'r', ['s'] = 's', ['t'] = 't',
    ['u'] = 'u', ['v'] = 'v', ['w'] = 'w', ['x'] = 'x', ['y'] = 'y',
    ['z'] = 'z',
};

const char to_uppercase_table[256] = {
    ['A'] = 'A', ['B'] = 'B', ['C'] = 'C', ['D'] = 'D', ['E'] = 'E',
    ['F'] = 'F', ['G'] = 'G', ['H'] = 'H', ['I'] = 'i', ['J'] = 'J',
    ['K'] = 'K', ['L'] = 'L', ['M'] = 'M', ['N'] = 'N', ['O'] = 'O',
    ['P'] = 'P', ['Q'] = 'Q', ['R'] = 'R', ['S'] = 'S', ['T'] = 'T',
    ['U'] = 'U', ['V'] = 'V', ['W'] = 'W', ['X'] = 'X', ['Y'] = 'Y',
    ['Z'] = 'Z',
    ['a'] = 'A', ['b'] = 'B', ['c'] = 'C', ['d'] = 'D', ['e'] = 'E',
    ['f'] = 'F', ['g'] = 'G', ['h'] = 'H', ['i'] = 'i', ['j'] = 'J',
    ['k'] = 'K', ['l'] = 'L', ['m'] = 'M', ['n'] = 'N', ['o'] = 'O',
    ['p'] = 'P', ['q'] = 'Q', ['r'] = 'R', ['s'] = 'S', ['t'] = 'T',
    ['u'] = 'U', ['v'] = 'V', ['w'] = 'W', ['x'] = 'X', ['y'] = 'Y',
    ['z'] = 'Z',
};

typedef enum { lowercase = 0, uppercase = 1 } Charcase;
static Charcase lastcase = uppercase;

static char to_lowercase(char c) {
    if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) return c;
    char result = to_lowercase_table[(int)c];
    if (result >= 'a' && result <= 'z') lastcase = lowercase;
    return result;
}

static char to_uppercase(char c) {
    if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z')) return c;
    char result = to_uppercase_table[(int)c];
    if (result >= 'A' && result <= 'Z') lastcase = uppercase;
    return result;
}

int main(int argc, char **argv) {
    if (argc == 1) {
        printf("%s", help_text);
        return 1;
    }

    for (int i = 1; i < argc; i += 1) {
        char *arg = argv[i];
        size_t arg_len = strlen(arg);
        for (size_t j = 0; j < arg_len; j += 1) {
            if (lastcase == uppercase) arg[j] = to_lowercase(arg[j]);
            else arg[j] = to_uppercase(arg[j]);
            putchar(arg[j]);
        }
        putchar(' ');
    }

    putchar('\n');
    return 0;
}
