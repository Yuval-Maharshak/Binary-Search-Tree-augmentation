#define MACRO(...) \
    printf(__VA_ARGS__);


#include <stdio.h>
int main() {
    int x = 0;
    char *lst[] = {"x","y","z"};
    MACRO("a");
}