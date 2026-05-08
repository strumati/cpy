#include <stdio.h>
#include "../py/py.h"
#include <string.h>

int main(int argc, char* argv[]) {
    char json[100];

    scanf("%s",json);
    printf("%s",json);

    char line1[] = "x = 2";
    char line2[] = "print(x)";
    char *lines[] = {line1,line2,NULL};

    py_run_code(lines);
    return 0;
}
