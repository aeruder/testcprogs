#include <stdio.h>

int main(void)
{
    char buffer[] = "1234\n";
    printf("sizeof '1234\\n\\0' = %d\n", (int)sizeof(buffer));
    return 0;
}
