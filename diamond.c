#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Given a character from the alphabet, print a diamond of its 
output with that character being the midpoint of the diamond. */
int main() {
   
   /* declare vars */ 
   char ch;
   char *stringline; 
   char startchar;
   int topletteridx;
   int linelen;
 
   /* get input */ 
   printf("Enter a character: ");
   ch = getchar();
   
   /* convert to big caps  */ 
   ch = toupper(ch); 

   /* check if valid value */
   if (ch > 'Z' || ch < 'A')
   {
       printf("Not a valid letter, quitting program.");
       exit(1);
   }
   
   /* initialize vars and memory */ 
   topletteridx =  ch - 'A';
   linelen = (2*(topletteridx+1)-1);
   stringline = (char*) malloc(linelen*sizeof(char));
   if (!stringline)
   {
           printf("Error allocating space, quitting program."); 
           exit(1);
   }   
   printf("\n");  /*ensure it starts on new line as some compilers don't create it */ 
   
   /* create top half of diamond */ 
   for (int ctr = 0, startchar = 'A'; ctr <= topletteridx; ctr++)
   {
       memset(stringline, ' ', linelen);
       stringline[topletteridx-ctr] = startchar; 
       stringline[topletteridx+ctr] = startchar;
       printf("%s\n", stringline);
       
       startchar++;
   }

   /* create lower half of diamond */ 
   for (int ctr = topletteridx-1, startchar = ch-1; ctr >= 0; ctr--)
   {
       memset(stringline, ' ', linelen);
       stringline[topletteridx-ctr] = startchar; 
       stringline[topletteridx+ctr] = startchar;
       printf("%s\n", stringline);
       
       startchar--;
   }

    /* free up memory */ 
    if (stringline)
    {
        free(stringline);
    }
       
    return 0;
}