#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

char filename[] = "data";

int choiceScore( char mine ) {
   switch( mine ) {
      case 'A': // Rock
         return 1;
      case 'B': // Paper
         return 2;
      case 'C': // Scissors
         return 3;
      default:
         printf( "Somthing went wrong" );
         assert( 0 );
   }
}

int gameResult( char theirs, char mine ) {
   int score = 0;
   switch( mine ) {
      case 'X': // Lose
         score += 0;
         switch( theirs ) {
            case 'A': // Rock
               score += choiceScore( 'C' ); // Scissors
               return score;
            case 'B': // Paper
               score += choiceScore( 'A' ); // Rock
               return score;
            case 'C': // Scissors
               score += choiceScore( 'B' ); // Paper
               return score;
            default:
               printf( "Somthing went wrong" );
               assert( 0 );
         }
      case 'Y': // Draw
         score += 3;
         switch( theirs ) {
            case 'A': // Rock
               score += choiceScore( 'A' ); // Rock
               return score;
            case 'B': // Paper
               score += choiceScore( 'B' ); // Paper
               return score;
            case 'C': // Scissors
               score += choiceScore( 'C' ); // Scissors
               return score;
            default:
               printf( "Somthing went wrong" );
               assert( 0 );
         }
      case 'Z': // Win
         score += 6;
         switch( theirs ) {
            case 'A': // Rock
               score += choiceScore( 'B' ); // Paper
               return score;
            case 'B': // Paper
               score += choiceScore( 'C' ); // Scissors
               return score;
            case 'C': // Scissors
               score += choiceScore( 'A' ); // Rock
               return score;
            default:
               printf( "Somthing went wrong" );
               assert( 0 );
         }
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
   }
   
   fclose( f );

   printf( "My score is: %d", score );
}
