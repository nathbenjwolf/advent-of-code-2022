#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char filename[] = "data";

int checkForChar( char letter, char * compartment ) {
   for( int i=0; compartment[i] != '\0'; ++i ) {
      if( compartment[i] == letter ) {
         return 1;
      }
   }
   return 0;
}

int getCharVal( char letter ) {
   if( letter <= 'Z' ) {
      return letter - 'A' + 27;
   } else {
      return letter - 'a' + 1;
   }
}
int main( void ) {

   char theirChoice;
   char myChoice;

   char rucksack[100];

   FILE *f;
   f = fopen( filename, "r" );

   int len = 0;
   int priority = 0;
   while ( fscanf( f, "%s\n", rucksack ) != -1 ) {
      len = strlen( rucksack );
      assert( len % 2 == 0 );

      for( int i = 0; i < len/2; ++i ) {
         if( checkForChar( rucksack[i], &rucksack[len/2] ) ) {
            int value = getCharVal( rucksack[i] );
            priority += value;
            break;
         }
      }
   }
   
   fclose( f );

   printf( "My priority is: %d\n", priority );
}
