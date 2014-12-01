/*
Lottery program
Karl Jones C13315991
Assignment 2 
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
// Windows.h used for the Sleep()
#include <windows.h>

#define LOTTO 6
#define MIN 1
#define MAX 42

//  Option 1: Getting the numbers into the system.
void number_input(int*, int*);
//  Option 1: Sorting the numbers.
void sorting(int*);
//  Option 2 : Displaying the digits.
void displayNumbers(int*);
//  Option 3: Check if the numbers played with are the winning numbers.
void compare_numbers(int*);
//  Option 4: Check the frequency of a number arising.
void checkFreq(int*);
//  Option 5: Exit the program.
void exit_fxn(void);
//  Function to make sure the user has done everything before moving onto the next section
int check_nums(int*);

main()
{
    char user_option = '0';
    int numbers_input[LOTTO] = { 0 };
    // This variable is used to hold the amount of times a number is input into the game in a single session.
    int frequency[MAX] = { 0 };
    // Variable that runs the check to make sure the user has put in some numbers.
    int ch = 0;
    

    //Do while loop is used here so that the menu of the program will ALWAYS display at least once when the program is ran.
    do
    {
        // This if statement shows the users current numbers over the main menu., but only does this if there are numbers input.
        if ( ch == LOTTO )
        {
            puts("              Your current numbers");
            
            for ( int i = 0 ; i < LOTTO ; i++ )
            {
                printf("%d\t", numbers_input[i]);
            }
            
            printf("\n------------------------------------------\n\n");
        }
        
        //Display the menu when the program is started or when the program loops it back around.
        puts("              MAIN MENU");
        puts("------------------------------------------");
        puts("1. Enter your numbers");
        puts("2. Display your numbers");
        puts("3. Check the winning numbers");
        puts("4. Check the frequency of the numbers used");
        puts("5. Exit");
        puts("-------------------------------------------");
        
        printf("Your selection: ");
        scanf("%1s", &user_option);
        
        switch(user_option)
        {
            case '1':
            {
                //  Option 1: Entering playing numbers
                number_input(numbers_input, frequency);
                break;
            }
            case '2':
            {
                ch = check_nums(numbers_input);
                if ( ch > 0 )
                {
                    clrscr();
                    printf("Please enter your numbers you want to play with first\n\n");
                    Sleep(1500);
                    number_input(numbers_input,frequency);
                }
                //  Option 2: Displaying the numbers entered IF they have been entered into option 1.
                displayNumbers(numbers_input);
                break;
            }
            case '3':
            {
                ch = check_nums(numbers_input);
                if ( ch > 0 )
                {
                    clrscr();
                    printf("Please enter your numbers you want to play with first.\n\n");
                    Sleep(1500);
                    number_input(numbers_input,frequency);
                }
                //  Option 3: Checking against the winning numbers IF there are numbers input from option 1.
                compare_numbers(numbers_input);
                break;
            }
            case '4':
            {
                ch = check_nums(numbers_input);
                if ( ch > 0 )
                {
                    clrscr();
                    printf("Please enter your numbers you want to play with first.\n\n");
                    Sleep(1500);
                    number_input(numbers_input, frequency);
                }
                //  Option 4: Checking the frequency os numbers used IF there are numbers input from option 1.
                checkFreq(frequency);
                break;
            }
            case '5':
            {
                user_option = '0';
                clrscr();
                // Option 5: Exiting the program.
                exit_fxn();
                break;
            }
            default:
            {
                puts("That is not a valid menu option");
                
                Sleep(1000);
                clrscr();
                user_option = '0'; //Looping the user back around
                break;
            }
            
        } // End switch statement.
        
    } while( user_option != '5');

} // End main() --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//  Option 1: Read in the numbers.
void number_input(int *numbers_input, int *Freq)
{
    char char_numbers_input[LOTTO] = "00000";
    int temp, i; 
    int counter = 0;
    
    clrscr();
    
    for ( i = 0 ; i < LOTTO ; i++ )
    {
        *(numbers_input + i ) = 0;
    }
    
    i = 0;
    
    do // Reading the numbers into the system
    {    
        clrscr();
        
        temp = i + 1;
        
        printf("Please enter number %d between %d and %d: ", temp, MIN, MAX);
        gets(char_numbers_input);
        
        *(numbers_input + i) = atoi(char_numbers_input); // Converting numbers from string to int
        
        temp = *(numbers_input + i);
        
        if ( *(numbers_input + i) < MIN || *(numbers_input + i) > MAX ) // Error checking: validation of numbers input.
        {
            printf("\n%d is not a valid number, please try another, between %d and %d\n", *(numbers_input + i), MIN, MAX );
            i--;
            // This is here to counteract a bug where it would always show an error on the first time going into this option.
            while ( counter != 1 )
            {
                counter = 1;
                clrscr();
            } 
            
            Sleep(1000);
            clrscr();
        } // End for
        
        for ( int j = 0 ; j < LOTTO ; j++ ) // Error checking: duplicates
        {
            if ( j == i )
            {
                j++;
            } // End if
            else if ( *(numbers_input + i) == *(numbers_input + j) )
            {
                puts("You have already used that number");
                Sleep(1000);
                i--;
                break;
            } // End else if
        } // End for
        
        i++;
        
    } while ( i < LOTTO );
    
    clrscr();
    
    printf("These are the %d numbers youre going to be playing with:\n", LOTTO);
    
    sorting(numbers_input); // Sorting the numbers before giving them back to the user
    
    for ( i = 0 ; i < LOTTO ; i++ )
    {
        printf("%d ", *(numbers_input + i) );
    } // End for loop.
    
    for ( i = 0 ; i < LOTTO ; i++ ) // Incrementing the frequency array
    {
        temp = *(numbers_input + i);
        temp--;
        *(Freq + temp) = *(Freq + temp) + 1;
    } //End for loop 
    
    Sleep(1500);
    clrscr();
    
} // End function number_input() -------------------------------------------------------------------------------------------------------------------------------------

// Sorting the numbers to go back into option 1. 
void sorting(int *numbers)
{
    int i, j, temp;
    
    for (i = 0; i < (LOTTO - 1); ++i)
    {
        for (j = 0; j < LOTTO - 1 - i; j++ )
        {
            if ( *( numbers + j ) > *(numbers + ( j + 1 ) ) )
            {
                temp = *( numbers + ( j + 1 ) );
                *( numbers + ( j + 1 ) ) = *( numbers + j );
                *( numbers + j ) = temp;
                
            } // End if statement
            
        } // End inner for
        
    } // End outer for
    
} //    End function sorting() ---------------------------------------------------------------------------------------------------------------------------------------------

//  Option 2: Display the numbers. 
void displayNumbers(int *numbers)
{
    clrscr();
    
    puts("Your numbers are as follows:");

    for ( int i = 0 ; i < LOTTO ; i++ )
    {
        printf("%d\t", *(numbers+i));
    }
    
    Sleep(1500);
    clrscr();
    
} // End function displayNumbers() ----------------------------------------------------------------------------------------------------------------------------------

//  Option 3: Check against the winning numbers and tell the user what they have won. 
void compare_numbers(int *numbers_input)
{
    int winning_numbers[] = { 1, 3, 5, 7, 9, 11 };
    int bonus_number = 42;
    int match = 0;
    int bonus = 0;
    
    clrscr();
    
    //  For loop to check the numbers through against the winning numbers.
    for ( int i = 0 ; i < LOTTO ; i++ )
    {
        for ( int j = 0 ; j < LOTTO ; j++ )
        {
            if ( *(numbers_input + j) == winning_numbers[i] )
            {
                
                match++;
                
            } // End if
            
        } // End inner for
        
    } // End outer for
    
    /* If statement to check if the bonus number has been gotten 
        only needed to run if the user has not matched six of the 
        numbers. */
    if ( match != 6 )
    {
        for ( int i = 0; i < LOTTO ; i++ )
        {
            if ( *(numbers_input + i) == bonus_number )
            {
                
                bonus++;
                
            } // End if
            
        }// End for
        
    }// End if
    
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"); // Telling the user what they won.
    if ( bonus == 1 )
    {
        printf("You matched %d numbers and got the bonus number!\n\n", match);
    }
    else
    {
        printf("You matched %d numbers!\n\n", match);
    }
    puts("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
    
    printf("You won ");
    
    if ( match == 6 && bonus == 0 )
    {
        clrscr();
        printf("\n       ####                   ####         ");
        printf("\n     #      #               #      #       ");
        printf("\n    #        #             #        #      ");
        printf("\n    #        #             #        #      ");
        printf("\n     #      #               #      #       ");
        printf("\n      #    #                 #    #        ");
        printf("\n       #  #                   #  #         ");
        printf("\n        ##                     ##          ");
        printf("\n         *                      *          ");   
        printf("\n        *                      *           ");
        printf("\n         *                      *          ");
        printf("\n        *                       *          ");
        printf("\n           YOU WON THE JACKPOT             ");
    }
    else if ( match == 5 && bonus == 1)
    {
        puts("a new car!");
    }
    else if ( match == 5 && bonus == 0 )
    {
        puts("a holiday!");
    }
    else if ( match == 4 && bonus == 1 )
    {
        puts("a weekend away!");
    }
    else if ( match == 4 && bonus == 0 )
    {
        puts("a night out!");
    }
    else if ( match == 3 && bonus == 1 )
    {
        puts("a cinema ticket!");
    }
    else
    {
        puts("nothing this time.");
    }
    
    Sleep(2500);
    clrscr();
    
} //  End function compare_numbers() -----------------------------------------------------------------------------------------------------------------------------

//  Option 4: Check the frequency. 
void checkFreq(int *Frequency)
{
    char user_choice = '0';
    int check, temp;
    
    clrscr();
    
    do
    {
        puts("What would you like to do?");
        puts("1. Check the freqency of a number");
        puts("2. Exit back to main menu");
        printf("Your selection: ");
        scanf("%1s", &user_choice);
        clrscr();
        
        if ( user_choice == '1' ) // If they select option 1 to check a numbers frequency.
        {
            puts("Enter the number you want to check:");
            scanf("%d", &check);
            
            if ( check < MIN || check > MAX ) // Error checking: range.
            {
                printf("That is not a valid selection.");
            }
            else
            {
                temp = check - 1;
                
                if ( *(Frequency + temp) == 1 )
                {
                    clrscr();
                    printf("%d has been used once.", check);
                }
                else
                {
                    clrscr();
                    printf("%d has been used %d times.\n", check, *(Frequency+temp));
                }
                
                Sleep(1000);
                clrscr();
                
            } //  End if statement
        } // End if
        
    } while ( user_choice != '2' ); // End do while loop
    
} // End function checkFreq() ----------------------------------------------------------------------------------------------------------------------------------------------------------

//  Option 5: Exit the game. 
void exit_fxn(void)
{
    char quit_option;
    
    puts("Are you sure you want to quit the game, (y)es or (n)o?");
    scanf("%1s", &quit_option);
    
    if ( quit_option == 'y' || quit_option == 'Y' ) // If user clicks Y.
    {
        printf("Thank you for playing!");
        Sleep(1000);
        exit(0);
    } // End if
    else if ( quit_option == 'n' || quit_option == 'N' ) // If user clicks N.
    {
        clrscr();
    } // End else if
    else // Error checking: Invalid option.
    {
        puts("ERROR: Invalid option selected, try again.");
        Sleep(1000);
        clrscr();
        
        exit_fxn(); // Calls exit_fxn() to loop the user back around.
    } // End else
    
} // End function exit() -----------------------------------------------------------------------------------------------------------------------------------------------------------------

/* This function will return a 1 if all the numbers are equal to zero,
    meaning that the user hasn't input any numbers since the user is not
    allowed to use zero in their number selection.*/
int check_nums(int *numbers)
{
    int check = 0;
    int checking[LOTTO] = { 0 };
    
    for ( int i = 0 ; i < LOTTO ; i++ )
    {
        
        if ( *(numbers+i) == checking[i])
        {
            check++;
        } 
        else
        {
            check--;
        }
    }
    
    return(check);
    
} //   End function check_nums()--------------------------------------------------------------------------------------------------------------------------------------------------------------
