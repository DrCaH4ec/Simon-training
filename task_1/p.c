#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#define NUMBERS_OF_OPTIONS 3 
#define NUMBER_OF_LATER_IN_BIGEST_WORD (sizeof("scissors")/sizeof(char))
/*
Create a rock-paper-scissors console game
(rules https://en.wikipedia.org/wiki/Rock_paper_scissors)

The game should be simple, the goal is to create a git project with proper commit order and structure. E.g.:
```
> Please choose: rock (r) - paper (p) - scissors (s)
> r
> You choose rock, I choose paper
> I win: paper beats rock
```
Please add your sources into folder 'scissors'

Optional task: add printing md5 checksum of computer's choice before human's move.

*/
void get_choice_of_users_and_cheking_for_correct_input(char *choise_of_user)
{
    do
    {
        if((!(*choise_of_user == 'r' || *choise_of_user == 'p' || *choise_of_user == 's')) && *choise_of_user != '\n')
            printf("\nYou entered incorect object. Pls enter r,p,s.\n");
        *choise_of_user = getchar();        
    } while (!(*choise_of_user == 'r' || *choise_of_user == 'p' || *choise_of_user == 's'));// Take choise and check for right value of choise.
    printf("\n");
}

void get_random_choise_of_npc(char *choise_of_npc)
{
    srand(time(NULL));
    switch ((rand()% NUMBERS_OF_OPTIONS)+1)
    {
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

char *knowledge_search_be_char(char *abbrivia, char word[])
{
    switch (*abbrivia)
    {
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

void determination_winer(char * choice_of_users, char  *choise_of_npc)
{
    char word_bufer[NUMBER_OF_LATER_IN_BIGEST_WORD];
    if(*choice_of_users == *choise_of_npc)
    {
        printf("Dead head: : %s = %s\n", knowledge_search_be_char(choice_of_users, word_bufer),knowledge_search_be_char(choise_of_npc, word_bufer));
    }
    else
    {
        if(*choice_of_users == 'r')
        {
            if(*choise_of_npc == 's')
                printf("I loose. %s beats %s\n", knowledge_search_be_char(choice_of_users, word_bufer),knowledge_search_be_char(choise_of_npc, word_bufer));
            else 
                printf("I win. %s beats %s\n", knowledge_search_be_char(choise_of_npc, word_bufer),knowledge_search_be_char(choice_of_users, word_bufer));
        }
        if(*choice_of_users == 'p')
        {
            if(*choise_of_npc == 'r')
                printf("I loose. %s beats %s\n", knowledge_search_be_char(choice_of_users, word_bufer),knowledge_search_be_char(choise_of_npc, word_bufer));
            else 
                printf("I win. %s beats %s\n", knowledge_search_be_char(choise_of_npc, word_bufer),knowledge_search_be_char(choice_of_users, word_bufer));
        }
        if(*choice_of_users == 's')
        {
            if(*choise_of_npc == 'p')
                printf("I loose. %s beats %s\n", knowledge_search_be_char(choice_of_users, word_bufer),knowledge_search_be_char(choise_of_npc, word_bufer));
            else 
                printf("I win. %s beats %s\n", knowledge_search_be_char(choise_of_npc, word_bufer),knowledge_search_be_char(choice_of_users, word_bufer));
        }
        /*  
        Тут україньскою бо звернаюся до вчителя. Я десь чув шо те шо я зробив, а саме 3 однакові блоки з не великими змінами.
        Це мувітон у програмованні. Та не дотримування ідеалогії чистого коду. 
        Чи треба ломати тут голову над тим шоб чього уникнути?
        Чи це правило лайно собаки ?
        */
    }
}


int main()
{
    char choise_of_user; 
    char choise_of_npc;
    get_random_choise_of_npc(&choise_of_npc);// Set computer choise 
    printf ("\nComputer choise : %c", choise_of_npc);
    printf("\nPlease choose: rock (r) - paper (p) - scissors (s)\n");
    get_choice_of_users_and_cheking_for_correct_input(&choise_of_user);
    determination_winer(&choise_of_user, &choise_of_npc);

    
    
    return 0;
}
