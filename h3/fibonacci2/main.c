/*
 * COMP.CS.120 Ohjelmoinnin Tekniikka C
 * H3 T5 Fibonaccin luvut #2
 *
 * Antti Hakkarainen / K79735
 * antti.i.hakkarainen@tuni.fi
 */

#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

int main(int argc, char *argv[])
{
  char *fibonacci = fib_jono_mj(atoi(argv[1]));
  printf("%s\n", fibonacci);
  free(fibonacci);
  return 0;
}
