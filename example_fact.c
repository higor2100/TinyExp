#include "tinyexpr.h"
#include <stdio.h>


double fact(double n) {
  if (n >= 1) {
    return n * fact(n - 1);
  }
  return 1;
}


int main(int argc, char *argv[])
{
    const char *expression = "2 * fact(5) / 3";
    printf("Expressao:\n\t%s\n", expression);

    te_variable variaveis[] = {
        {"fatorial", fact, TE_FUNCTION1}
    };

    int err;
    te_expr *n = te_compile(expression, variaveis, 1, &err);


    if (n) {
        const double r = te_eval(n);
        printf("Resultado:\n\t%f\n", r);
        te_free(n);
    } else {
        printf("\t%*s^\nErro, posicao", err-1, "");
    }

    return 0;
}
