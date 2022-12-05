#include <stdio.h>
#include <stdlib.h>

char filename[] = "data";

int cmpfunc( const void* a, const void* b ) {
   return ( *(int*) b - *(int*) a );
}

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

   int curElf = 0;
   int curCals = 0;
   int elfCals[10000];

   while( ( read = getline(&line, &len, f) ) != -1 ) {
      if( line[0] == '\n' ) {
         elfCals[ curElf ] = curCals;
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

   qsort( elfCals, curElf, sizeof( int ), cmpfunc );

   int topTotal = 0;
   for( int i=0; i < 3; ++i ) {
      topTotal += elfCals[ i ];
   }

   printf( "Total calories of top 3 elfs are: %d\n", topTotal );

	return 0;

}
