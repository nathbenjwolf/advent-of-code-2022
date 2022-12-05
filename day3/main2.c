#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char filename[] = "data";

int maxsize = 100;

int checkForChar( char letter, char * compartment ) {
   for( int i=0; compartment[i] != '\0'; ++i ) {
      if( compartment[i] == letter ) {
         return 1;
      }
   }
   return 0;
}

char * getCommonChars( char * list1, char * list2 ) {
   char * common = calloc( sizeof( char ), maxsize );
   int commonLen = 0;
   common[0] = '\0';
   for ( int i=0; list1[i] != '\0'; ++i ) {
      if( checkForChar( list1[i], list2 ) ) {
         common[ commonLen ] = list1[i];
         common[ ++commonLen ] = '\0';
      }
   }

   return common;
}

char * getCharSubset( char * rucksack ) {
   char * subset = calloc( sizeof( char ), maxsize );
   int subsetLen = 0;
   subset[0] = '\0';
   for ( int i=0; rucksack[i] != '\0'; ++i ) {
      if( !checkForChar( rucksack[i], subset ) ) {
         subset[ subsetLen ] = rucksack[i];
         subset[ ++subsetLen ] = '\0';
      }
   }

   return subset;
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

   char rucksack[maxsize];

   FILE *f;
   f = fopen( filename, "r" );

   int len = 0;
   int priority = 0;
   int elf = 0;

   char * tmpCommonChars = NULL;
   char * commonChars = NULL;
   char * subset = NULL;

   while ( fscanf( f, "%s\n", rucksack ) != -1 ) {
      len = strlen( rucksack );

      if( elf == 3 ) {
         assert( commonChars[1] == '\0' );
         //printf( "common char is: %c, value: %d\n", commonChars[0], getCharVal( commonChars[0] ) );
         priority += getCharVal( commonChars[0] );
         free( commonChars );
         elf = 0;

      }
      if( elf == 0 ) {
         commonChars = getCharSubset( rucksack );
      } else {
         subset = getCharSubset( rucksack );
         tmpCommonChars = getCommonChars( commonChars, subset );

         // Cleanup dynamic memory
         free( commonChars );
         free( subset );
         commonChars = tmpCommonChars;
         subset = NULL;
         tmpCommonChars = NULL;
      }
      ++elf;
   }

   assert( commonChars[1] == '\0' );
   printf( "common char is: %c, value: %d\n", commonChars[0], getCharVal( commonChars[0] ) );
   priority += getCharVal( commonChars[0] );
   free( commonChars );
   
   fclose( f );

   printf( "My priority is: %d\n", priority );
}
