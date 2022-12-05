#include <stdio.h>
#include <stdlib.h>

char filename[] = "data";

int main( void ) {

	FILE *f;
	f = fopen( filename, "r" );
   if ( f == NULL ) {
      printf( "Failed to open file\n" );
      return -1;
   }
   
   ssize_t read;
   size_t len;
   char * line = NULL;

	int maxCals = 0;
   int maxCalElf = 0;
   int curElf = 0;
   int curCals = 0;

   while( ( read = getline(&line, &len, f) ) != -1 ) {
      if( line[0] == '\n' ) {
         if( curCals > maxCals ) {
            maxCals = curCals;
            maxCalElf = curElf;
         }
         curElf++;
         curCals = 0;
      } else {
         curCals += atoi( line );
      }
   }
	fclose( f );
   if( line ) {
      free( line );
   }

   printf( "Max calories are: %d, held by elf: %d", maxCals, maxCalElf );

	return 0;

}
