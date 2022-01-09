/**************************************
 Student Name: Luciana Castillo 
Date: October 29th 2021
I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
*********************************************************/


#include <stdio.h>
#include <string.h>

#define MAX 100
#define MAXD 10

    void readInput (char str [MAX]);
    void findStats (char str [MAX], int * countSpecialChars, int * countUpperCase, int * countLowerCase, int * countNumbers);
    int findTotalChancesGiven (char str [MAX]);
    int extractDigits (char str[MAX], int digitsInInputString [MAX]);
    int checkPlayerMove (int playersGuess, int digitsInInputString [MAX], int totalDigits);     //Function prototypes
    void updateDigits (int playersGuess, int remainingDigits [MAXD]);
    void displayDigits (int remainingDigits [MAXD]);
    void displayXs(char exes[MAX], int totalDigits);
    int countXs (char exes [MAX], int totalDigits);

int main(){
}


    void readInput(char str[MAX])           //Function definition
    {
    fgets(str, MAX, stdin);
    }

    void findStats (char str [MAX], int * countSpecialChars, int * countUpperCase, int * countLowerCase, int * countNumbers)    //Function definition
    {

    int specialChars = 0, upperCase = 0, lowerCase = 0, numbers = 0;

    for(int i =0; i < strlen(str); ++i)
        {

        if ((str[i] >= 97) && (str[i] <= 122))        //checks if input string contains lowercase letters using ASCII table values
            {
        lowerCase++;

            }

        else if((str[i] >= 65) && (str[i] <= 90))   //checks if input string contains upercase letters using ASCII table values
            {
        upperCase++;
            }

       else if((str[i] >= 48) && (str[i] <= 57))  //checks if input string contains numbers using ASCII table values
            {
        numbers++;
            }

        else if ((str[i] == ',') || (str[i] == ' '))         //checks if input string contains special chars
            {
        specialChars++;

            }
    }



    *countUpperCase = upperCase;
    *countLowerCase = lowerCase;
    *countSpecialChars = specialChars;
    *countNumbers = numbers;


    }



    int findTotalChancesGiven (char str [MAX])      //Function definition
        {
        int chances = 0;

        for (int i = 0; i < strlen(str); ++i)     //loop through str for length of str
            {

          if((str[i] >= 48) && (str[i] <= 57))             //check if str element is a digit
               {
                   if((str[i]!= str[i+1]) && (str[i] != str[i+2]) && (str[i] != str[i+3]))
                    {

                  chances++;
                    }
               }

        else
        {

            chances = chances;      //otherwise chances does not change
        }

            }

              return chances;


        }

    int extractDigits (char str[MAX], int digitsInInputString [MAX])
        {

    int j = 0;
    int digitCount = 0;

        for (int i= 0; i < strlen(str);++i)          //loop through str length of str times
            {
             if((str[i] >= 48) && (str[i] <= 57))       //check if element is a integer using ASCII values
            {

        digitsInInputString[j] = str[i];            //store element in digitsInInputString
        j = j + 1;                                  // add one to j everytime
        digitCount++;                               //add one to digitCount
        }


            }


    return digitCount;
        }

     int checkPlayerMove (int playersGuess, int digitsInInputString [MAX], int totalDigits)
     {


        for (int i = 0; i < totalDigits; ++i){                              //loop through totalDigits times

                if  (playersGuess == digitsInInputString[i])
                    {
                                                        //if playersGuess is equal to an element in digitsInInputString return 1
                return 1;
                    }

        else {


            return 0;                                             //if guess is wrong return 0

        }


      }
     }




  void updateDigits (int playersGuess, int remainingDigits [MAXD])
   {


       for (int i = 0; i < MAXD; ++i)
       {

        if (playersGuess == remainingDigits[i])
          {                                          //if playersGuess is equal to element in currentDigits then replace element with -1
            remainingDigits[i] = -1;
          }


       }

   }

    void displayDigits (int remainingDigits [MAXD])
    {

    for (int i = 0; i < MAXD; ++i)
          {

            if (remainingDigits[i] != -1)
            {                               //if element in remaining digits is not equal to -1 then print integer

                    printf("%d ", remainingDigits[i]);

            }

            else
            {

                printf(" ");
            }


          }
    }

    void displayXs(char exes[MAX], int totalDigits)
    {

        for (int i = 0; i < totalDigits; i++)
        {

            exes[i] = 'X';
            printf("%c ", exes[i]);                //loop through totalDigits and set every element in exes[i] equal to X
        }



    }

     int countXs (char exes [MAX], int totalDigits)
     {
         int numberExes = 0;


     for (int i=0; i < totalDigits; ++i)
     {                                     //loop through totalDigits and for every element equal to X add one to numberExes

        if (exes[i] == 'X')
        {
            numberExes++;

        }
     }

        return numberExes;              //return numberExes
