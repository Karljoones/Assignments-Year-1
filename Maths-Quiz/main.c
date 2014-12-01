#include <stdio.h>
#include <conio.h>
#define SIZE 5
main()
{
    char menu_option = '0';
    int question_amount = 0;
    char confirmation = '0';
    float user_answers[SIZE] = { 0 };
    int i = 0;
    int correct_answers = 0;
    int incorrect_answers = 0;
    char menu_2 = '0';
    
    // Do ... while loop used so the menu always runs atleast once.
    do
    {
        printf("------------------------------------------------\n");
        printf("Please choose from the menu below:\n");
        printf("1. Choose the amount of questions in your quiz.\n");
        printf("2. Start the quiz.\n");
        printf("3. Show amount of correct and incorrect answers.\n");
        printf("4. End the program.\n");
        printf("------------------------------------------------\n");
        printf("Enter your selection here: ");
        scanf("%1s", &menu_option);
        clrscr();
        
        // Error checking on the menu_option input by the user.
        if ( menu_option < '1' || menu_option > '4' )
        {
            printf("Invalid input.\n\n");
            printf("Press enter to continue.");
            getchar();
            getchar();
            menu_option = '0';
            clrscr();
        }
        
        // While the user wants to choose the amount of questions in their quiz.
        while ( menu_option == '1' )
        {
            confirmation = '0';
            
            printf("Please chose how many questions you would like ( 5 max ): ");
            scanf("%d", &question_amount);
            clrscr();
            
            //Error checking to make sure the amount of questions selected is in the right range.
            if ( question_amount > 5 || question_amount < 1 )
            {
                printf("That is not a valid input, you can only have a maximum of 5 questions.\n");
                printf("Press enter to continue.");
                getchar();
                getchar();
                clrscr();
            }
            // If the amount is in the right range, check if they're sure.
            else if ( question_amount < 6 && question_amount > 0 )
            {
                printf("So you want %d questions in your quiz!\n\n", question_amount);
                printf("Is this correct? (Y)es or (N)o.\n");
                scanf("%1s", &confirmation);
                clrscr();
                
                if ( confirmation == 'y' || confirmation == 'Y' )
                {
                    menu_option = 0;
                    confirmation = '0';
                    printf("Would you like to start the quiz now? (Y)es or (N)o.\n");
                    scanf("%1s", &confirmation);
                    if ( confirmation == 'y' || confirmation == 'Y' )
                    {
                        menu_option = '2';
                        clrscr();
                    } // End if
                    else if ( confirmation == 'n' || confirmation == 'N' )
                    {
                        clrscr();
                        break;
                    } //End else if
                    
                } // End confirmation if statement.
                
                // Loops the program back around if it is not correct.
                else if ( confirmation == 'n' || confirmation == 'N' )
                {
                    printf("Try again.");
                    getchar();
                    getchar();
                    confirmation = '0';
                    clrscr();
                } // End else if statement.
                
            } // End else if
            
        } // End while ( menu_option == 1 )
        
        // If the user wants to start the quiz.
        if ( menu_option == '2' )
        {
            // If the user has not input the amount of questions they want in this quiz, it defaults to the maximum amount.
            if ( question_amount == 0 )
            {
                question_amount = SIZE;
            }
            
            //  Switch statement prints out the questions.
            switch ( question_amount )
            {
                case 1:
                {
                    correct_answers = 0;
                    incorrect_answers = 0;
                    
                    printf("1) 5 * 6 = ");
                    scanf("%f", &user_answers[i]);
                    printf("You entered %.2f -", user_answers[i]);
                    
                    // If the answer is correct, add one to the correct_answers counter ( same for rest of switch statement).
                    if ( user_answers[i] == 30 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }// End if
                    
                    // If the answer is wrong, add one to the incorrect_answers counter (same for rest of switch statement).
                    else
                    {
                        printf(" Wrong, the answer was 30!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    } // End else.
                    
                    // This brings the user to the second menu, starts on line 413.
                    menu_option = '5';
                    break;
                    
                } // End case 1
                
                case 2:
                {
                    correct_answers = 0;
                    incorrect_answers = 0;
                    
                    // Question one
                    printf("1) 5 * 6 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 30 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 30!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    // Question two
                    printf("2) 1 + 4 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 5 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 5!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    menu_option = '5';
                    break;
                    
                } // End case 2.
                
                case 3:
                {
                    correct_answers = 0;
                    incorrect_answers = 0;
                    
                    // Question one
                    printf("1) 5 * 6 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 30 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 30!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    // Question two
                    printf("2) 1 + 4 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 5 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 5!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    //Question three
                    printf("3) (5 / 2) * 2 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 5 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 5!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    menu_option = '5';
                    break;
                    
                } // End case 3.
                
                case 4:
                {
                    correct_answers = 0;
                    incorrect_answers = 0;
                    
                    // Question one
                    printf("1) 5 * 6 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 30 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 30!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    // Question two
                    printf("2) 1 + 4 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 5 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 5!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    //Question three
                    printf("3) (5 / 2) * 2 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 5 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 5!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    //Question 4
                    printf("4) 7 * 8 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers [i] == 56 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 56!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    menu_option = '5';
                    break;
                    
                } // End case 4
                
                case 5:
                {
                    correct_answers = 0;
                    incorrect_answers = 0;
                    
                    // Question one
                    printf("1) 5 * 6 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 30 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 30!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    // Question two
                    printf("2) 1 + 4 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 5 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 5!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    //Question three
                    printf("3) (5 / 2) * 2 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 5 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 5!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    //Question 4
                    printf("4) 7 * 8 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers [i] == 56 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 56!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    i++;
                    
                    // Question 5
                    printf("5) ( 7 * 10 ) * 2 = ");
                    scanf("%f", &user_answers[i]);
                    printf("\nYou entered %.2f -", user_answers[i]);
                    
                    if ( user_answers[i] == 140 )
                    {
                        printf(" Correct!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        correct_answers++;
                        clrscr();
                    }
                    else
                    {
                        printf(" Wrong, the answer was 140!\n\n");
                        printf("Press enter to continue.");
                        getchar();
                        getchar();
                        incorrect_answers++;
                        clrscr();
                    }
                    
                    menu_option = '5';
                    break;
                    
                } // End case 5
                
            } // End switch
            
        } // End if
        
        /* This is used to make sure the user doesnt select option 1 and 2
                The user cannot select this option in the main menu. */
        while ( menu_option == '5')
        {
            printf("------------------------------------------------\n");
            printf("3. Show amount of correct and incorrect answers.\n");
            printf("4. End the program.\n");
            printf("------------------------------------------------\n");
            printf("Enter your selection here: ");
            scanf("%1s", &menu_option);
            clrscr();
            
            // Does not allow the user to select 1 and 2
            if ( menu_option != '3' && menu_option != '4')
            {
                printf("Invalid option.\n\n");
                printf("Press enter to continue.");
                getchar();
                getchar();
                clrscr();
                menu_option = '5';
            } // End if
            
        } // End second menu while loop
        
        // While the menu_option is three, the user has a new menu.
        while ( menu_option == '3' )
        {
            menu_2 = '0';
            
            printf("-----------------------------\n");
            printf("1. Correct answers.\n");
            printf("2. Incorrect answers.\n");
            printf("3. Return to main menu.\n");
            printf("-----------------------------\n");
            printf("Enter your selection here: ");
            scanf("%1s", &menu_2);
            clrscr();
            
            //Shows the correct answers
            if ( menu_2 == '1')
            {
                printf("You got %d questions correct out of %d questions asked.\n\n", correct_answers, question_amount);
                menu_2 = '0';
            } // End if
            
            //Shows the incorrect answers
            else if ( menu_2 == '2' )
            {
                printf("You got %d questions incorrect out of %d questions asked.\n\n", incorrect_answers, question_amount);
                menu_2 = '0';
            } // End else if
            
            // Returns the user to the main menu
            else if ( menu_2 == '3' )
            {
                menu_2 = '0';
                break;
            } // End else if
            
            // Error checking.
            else if ( menu_2 != '3' || menu_2 != '2' || menu_2 != '1' )
            {
                printf("Invalid option.");
                menu_2 = '0';
            }
                    
        } // End while 3
        
        // When the user enters four, the confirmation to quit appears.
        while ( menu_option == '4' )
        {
            printf("Are you sure you want to quit the program? (Y)es or (N)o.\n");
            scanf("%1s", &confirmation);
            clrscr();
            
            // If the user enters 'y' then the program ends.
            if ( confirmation == 'y' || confirmation == 'Y' )
            {
                printf("Thanks for playing!");
                break;
            } // End if
            
            // If the user answers 'n', the program loops back to the main menu
            else if ( confirmation == 'n' || confirmation == 'N' )
            {
                printf("Then continue.");
                menu_option = 0;
                confirmation = '0';
                clrscr();
            } //  End if
            
            // Error checking of the user input, loops back around
            else
            {
                printf("Invalid input.\n");
                printf("Try again, (Y)es or (N)o: ");
                scanf("%1s", &confirmation);
                clrscr();
            } // End else
            
        } // End if to quit the program.
        
    } 
    while ( menu_option != '4' );
    // End while loop that loops the whole program.

    getchar();
    getchar();
    
} // End main.
