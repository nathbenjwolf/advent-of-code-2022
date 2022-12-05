#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char filename[] = "data";

int gameResult( char theirs, char mine ) {
   switch( theirs ) {
      case 'A': // Rock
         switch( mine ) {
            case 'X': // Rock
               return 3;
            case 'Y': // Paper
               return 6;
            case 'Z': // Scissors
               return 0;
            default:
               printf( "Somthing went wrong" );
               assert( 0 );
         }
      case 'B': // Paper
         switch( mine ) {
            case 'X': // Rock
               return 0;
            case 'Y': // Paper
               return 3;
            case 'Z': // Scissors
               return 6;
            default:
               printf( "Somthing went wrong" );
               assert( 0 );
         }
      case 'C': // Scissors
         switch( mine ) {
            case 'X': // Rock
               return 6;
            case 'Y': // Paper
               return 0;
            case 'Z': // Scissors
               return 3;
            default:
               printf( "Somthing went wrong" );
               assert( 0 );
         }
      default:
         printf( "Somthing went wrong" );
         assert( 0 );
   }
}

int choiceScore( char mine ) {
   switch( mine ) {
      case 'X': // Rock
         return 1;
      case 'Y': // Paper
         return 2;
      case 'Z': // Scissors
         return 3;
      default:
         printf( "Somthing went wrong" );
         assert( 0 );
   }
}

int main( void ) {

   char theirChoice;
   char myChoice;

   FILE *f;
   f = fopen( filename, "r" );

   int score = 0;
   while ( fscanf( f, "%c %c\n", &theirChoice, &myChoice ) != -1 ) {
      score += gameResult( theirChoice, myChoice );
      score += choiceScore( myChoice );
   }
   
   fclose( f );

   printf( "My score is: %d", score );
}
