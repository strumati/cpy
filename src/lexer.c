//stand alone test lexer

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **lexer_str(char *code) {
    char **tokens = malloc(4 * sizeof(char *));
    tokens[0] = strdup("VAR:x");
    tokens[1] = strdup("OPERATOR:=");
    tokens[2] = strdup("INT:2");
    tokens[3] = NULL;
    return tokens;
}

char ***lexer(char **code) {
    int i = 0;
    
    while (code[i] != NULL) i++;
    
    char ***result = malloc((i + 1) * sizeof(char **));
    
    for (int j = 0; j < i; j++) {
        result[j] = lexer_str(code[j]);
    }
    result[i] = NULL;
    return result;
}

int main() {
    char line1[] = "x = 2";
    char line2[] = "print(x)";
    char *lines[] = {line1,line2,NULL};
    char ***result = lexer(lines);
    
    for (int i = 0; result[i] != NULL; i++) {
        printf("Group [%d]:\n", i);
        
        for (int j = 0; result[i][j] != NULL; j++) {
            printf("  Token [%d]: \"%s\"\n", j, result[i][j]);
        }
    }
    
    return 0;
}