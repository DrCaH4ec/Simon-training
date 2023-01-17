#include<stdlib.h>
#include<stdio.h>
#include<time.h>

#define NUMBERS_OF_OPTIONS 3 
#define NUMBER_OF_LATER_IN_BIGEST_WORD (sizeof("scissors")/sizeof(char))

void get_choice_of_users_and_cheking_for_correct_input(char *choise_of_usr)
{
    do{
        if ((!(*choise_of_usr == 'r' ||
            *choise_of_usr == 'p' || 
            *choise_of_usr == 's')) &&
            *choise_of_usr != '\n')
            printf("\nYou entered incorect object. Pls enter r,p,s.\n");
        *choise_of_usr = getchar();        
    } while (!(*choise_of_usr == 'r' ||
            *choise_of_usr == 'p' ||
            *choise_of_usr == 's')); // Take choise and check for right value of choise.
    printf("\n");
}

void get_random_choise_of_npc(char *choise_of_npc)
{
    srand(time(NULL));
    switch ((rand()% NUMBERS_OF_OPTIONS)+1){
        case 1:
            *choise_of_npc = 'r';
            break;
        case 2:
            *choise_of_npc = 'p';
            break;
        case 3:
            *choise_of_npc = 's';
            break;
    }
}

char *find_word_by_char(char *abbrivia, char word[])
{
    switch (*abbrivia){
        case 'r':
            word = "rock";
            break;
        case 'p':
            word = "paper";
            break;
        case 's':
            word = "scissors";
            break;
    }
    return word;
}

void determination_winer(char * choice_of_usr, char  *choise_of_npc)
{
    char word_b[NUMBER_OF_LATER_IN_BIGEST_WORD];
    if (*choice_of_usr == *choise_of_npc)
        printf("Dead head: : %s = %s\n", find_word_by_char(choice_of_usr, word_b),
                                        find_word_by_char(choise_of_npc, word_b));
    else{
        if ((*choice_of_usr == 'r' && *choise_of_npc == 's')||
            (*choice_of_usr == 'p' && *choise_of_npc == 'r')||
            (*choice_of_usr == 's' && *choise_of_npc == 'p'))
            printf("I loose. %s beats %s\n", find_word_by_char(choice_of_usr, word_b),
                                            find_word_by_char(choise_of_npc, word_b));
        else
            printf("I win. %s beats %s\n", find_word_by_char(choise_of_npc, word_b),
                                            find_word_by_char(choice_of_usr, word_b));
    }
}


int main()
{
    char choise_of_usr; 
    char choise_of_npc;
    get_random_choise_of_npc(&choise_of_npc); // Set computer choise 
    printf("\nComputer choise : %c", choise_of_npc);
    printf("\nPlease choose: rock (r) - paper (p) - scissors (s)\n");
    get_choice_of_users_and_cheking_for_correct_input(&choise_of_usr);
    determination_winer(&choise_of_usr, &choise_of_npc);


    return 0;
}

