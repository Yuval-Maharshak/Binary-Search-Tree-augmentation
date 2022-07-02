#include <stdio.h>
#define insert(funcs, ...) \
    char *fields[] = {__VA_ARGS__};                       \
    printf("%d", node.fields[0]);

int main() {
    insert(1, "size");
};