#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char **argv)
{
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
      char* input = argv[i];
      // hexadecimal -> decimal
      long decimal = strtol(input, NULL, base);
      printf("%ld\n", decimal);
  }
  return 0;
}
