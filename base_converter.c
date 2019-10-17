#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int is_power_of_two(double *exp, double n) {
    *exp = log2(n);
    return ceilf(*exp) == *exp;
}

int str_to_binary(char* str, char bin[], int input_base) {
    double exp;
    if (is_power_of_two(&exp, input_base) == 0) {
        fprintf(stderr,
                "Can't convert to binary for base that's not a power of 2: %d\n",
                input_base);
        return 1;
    }
    int i;
    if ((str[0] == '0') && (str[1] == 'x'))
        i = 2;
    else 
        i = 0;
    // TODO: Clean up so any abritrary base-encoding can be done (not just hex)
    // Copy pasted from: https://codeforwin.org/2015/08/c-program-to-convert-hexadecimal-to-binary-number-system.html
    for(; str[i]!='\0'; i++)
    {
        switch(str[i])
        {
            case '0':
                strcat(bin, "0000");
                break;
            case '1':
                strcat(bin, "0001");
                break;
            case '2':
                strcat(bin, "0010");
                break;
            case '3':
                strcat(bin, "0011");
                break;
            case '4':
                strcat(bin, "0100");
                break;
            case '5':
                strcat(bin, "0101");
                break;
            case '6':
                strcat(bin, "0110");
                break;
            case '7':
                strcat(bin, "0111");
                break;
            case '8':
                strcat(bin, "1000");
                break;
            case '9':
                strcat(bin, "1001");
                break;
            case 'a':
            case 'A':
                strcat(bin, "1010");
                break;
            case 'b':
            case 'B':
                strcat(bin, "1011");
                break;
            case 'c':
            case 'C':
                strcat(bin, "1100");
                break;
            case 'd':
            case 'D':
                strcat(bin, "1101");
                break;
            case 'e':
            case 'E':
                strcat(bin, "1110");
                break;
            case 'f':
            case 'F':
                strcat(bin, "1111");
                break;
            default:
                fprintf(stderr, "Warning: '%c' Not a valid hexidecimal char. Ignored.\n", str[i]);
        }
    }
    return 0;
}

int main (int argc, char *argv[]) {
  int base = 16;
  int c;

  while ((c = getopt (argc, argv, "b:v")) != -1)
    switch (c)
      {
      case 'b':
        base = atol(optarg);
        break;
      default:
        fprintf (stderr, "Bad option.\n");
        return 1;
      }
  for (int i = optind; i < argc; i++) {
      char* arg = argv[i];
      // <base> -> decimal
      long decimal = strtol(arg, NULL, base);
      printf("%ld\n", decimal);
      // <base> -> binary
      char binary [32];
      if (str_to_binary(arg, binary, base) == 0) {
          printf("%s\n", binary);
      }
  }
  return 0;
}
