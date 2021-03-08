#include <stdio.h>

/*int check_vowel(char);

int main()
{
  char s[100], t[100];
  int c, d = 0;

  printf("Enter a string to delete vowels\n");
  gets(s);

  for (c = 0; s[c] != '\0'; c++) {
    if (check_vowel(s[c]) == 0) {     // If not a vowel
      t[d] = s[c];
      d++;
   }
  }

  t[d] = '\0';

  strcpy(s, t);  // We are changing initial string. This is optional.

  printf("String after deleting vowels: %s\n", s);

  return 0;
}

int check_vowel(char t)
{
  if (t == 'a' || t == 'A' || t == 'e' || t == 'E' || t == 'i' || t == 'I' || t =='o' || t=='O' || t == 'u' || t == 'U')
    return 1;

  return 0;
}
*/
int main()
{
   char s[1000], r[1000];
   int begin, end, count = 0;

   printf("Input a string\n");
   gets(s);

   // Calculating string length

   while (s[count] != '\0')
      count++;

   end = count - 1;

   for (begin = 0; begin < count; begin++) {
      r[begin] = s[end];
      end--;
   }

   r[begin] = '\0';

   printf("%s\n", r);

   return 0;
}