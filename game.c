//Game created 19/12/2020
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int scorep,scoreb,tmp;

void menu();
void bowl();

void final()
{
    system("cls");
    
    for(int i=0;i<35;i++)
        printf("*");
    printf("Result");
    for(int i=0;i<39;i++)
        printf("*");
    printf("\n");
    
    printf("Your Final scores: %d\nOpponent's Final score: %d\n\n",scorep,scoreb);
    
    if(scorep>scoreb)
        printf("Congratulations, You Won the Game.\nPress any key to continue...");
    else if(scorep<scoreb)
        printf("Lol, You Lose the Game.\nPress any key to continue...");
    else
    {
        printf("It's a tie.\nPress any key to continue...");
    }
        getch();
    menu();
}

void bat()
{
    int score=0;
    
    srand(time(0));
    
    for(int i=0;i<6;i++)
    {
        system("cls");
        
        int shot;
    
        for(int i=0;i<32;i++)
        printf("*");
        printf("Batting");
        for(int i=0;i<33;i++)
        printf("*");
        printf("Score:%d",score);
        printf("\n");
        
        printf("Enter your shot: ");
        scanf("%d",&shot);
        
        int random=rand()%7;
        
        printf("Opponet chose: %d",random);
        
        if(random==shot)
        {
            printf("\nYou're Out.\nPress any key to continue",score);
            getch();
            break;
        }
        
        else
        {
            score=score+shot;
            printf("\nPress any key to continue...");
            getch();
        }
    }
        
        scorep=score;
        
        if(tmp==2)
            final();
        else
        {
            system("cls");
            printf("Your Final Score: %d\nNow your turn to bowl.\nPress any key to continue...",score);
            getch();
            tmp=1;
            bowl();
        }
    
}

void bowl()
{
    int score=0;
    
    srand(time(0));
    
    for(int i=0;i<6;i++)
    {
        system("cls");
        
        int choice;
    
        for(int i=0;i<32;i++)
        printf("*");
        printf("Bowling");
        for(int i=0;i<33;i++)
        printf("*");
        printf("Score:%d",score);
        printf("\n");
        
        printf("Enter your choice: ");
        scanf("%d",&choice);
        
        int shot=rand()%7;
        
        printf("Opponent make shot: %d",shot);
        
        if(choice==shot)
        {
            printf("\nWow,It's a Bold.\nPress any key to continue",score);
            getch();
            break;
        }
        
        else
        {
            score=score+shot;
            printf("\nPress any key to continue...");
            getch();
        }
        
    }
        
        scoreb=score;
        
        if(tmp==1)
            final();
        else
        {
            system("cls");
            printf("Opponent's Final Score: %d\nNow your turn to bat.\nPress any key to continue...",score);
            getch();
            tmp=2;
            bat();
        }
    
}

void newgame()
{
    
    srand(time(0));
    
    system("cls");
    
    for(int i=0;i<36;i++)
        printf("*");
    printf("GAME");
    for(int i=0;i<40;i++)
        printf("*");
    printf("\n");
    
    char toss[5];
    int choice,random;
    
    printf("Please choose Head or Tail: ");
        scanf("%s",toss);
    
    system("cls");
    
    for(int i=0;i<36;i++)
        printf("*");
    printf("GAME");
    for(int i=0;i<40;i++)
        printf("*");
    printf("\n");
    
    if(toss[0]=='h'||toss[0]=='H')
        choice=1;
    else if(toss[0]=='t'||toss[0]=='T')
        choice=0;
    
    random=rand()%2;
    
    if(random==choice&&choice==1)
    {
        int choice;
        printf("You chose for head and won the toss.");
        
        printf("\n\nWhat you want to choose:\n1. Bat\n2. Bowl");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);    
        
        choice==1?bat():bowl();    
    }
    
    else if(random==choice&&choice==0)
    {
        int choice;
        printf("You chose for tail and won the toss.");
        
        printf("\n\nWhat you want to choose:\n1. Bat\n2. Bowl");
        printf("\n\nEnter your choice: ");
        scanf("%d",&choice);    
        
        choice==1?bat():bowl();
    }
    
    else if(random!=choice&&choice==1)
    {
        printf("You chose for head and loss the toss.");
        int random=rand()%2;
        
        if(random==1)
        {
            printf("\nOpponent chose to bat\nPress any key to continue...");
            getch();
            bowl();
        }
        
        else
        {
            printf("\nOpponent chose to bowl\nPress any key to continue...");
            getch();
            bat();
        }    
    }
    
    else if(random!=choice&&choice==0)
    {
        printf("You chose for tail and loss the toss.");    
        int random=rand()%2;
        
        if(random==1)
        {
            printf("\nOpponent chose to bat\nPress any key to continue...");
            getch();
            bowl();
        }
        
        else
        {
            printf("\nOpponent chose to bowl\nPress any key to continue...");
            getch();
            bat();
        }
    }
    
}

void Exit()
{
    system("cls");
    exit(0);
}

void menu()
{
    
    scorep=0,scoreb=0,tmp=0;
    
    system("cls");
    
    for(int i=0;i<36;i++)
        printf("*");
    printf("MENU");
    for(int i=0;i<40;i++)
        printf("*");
    printf("\n");
    
    int choice;
    
    printf("1. Start New Game\n2. Exit");
    printf("\n\nEnter your choice: ");
    scanf("%d",&choice);
    
    choice==1?newgame():Exit();
    
}

int main()
{
    
    system("cls");
    
    for(int i=0;i<80;i++)
    printf("*");
    printf("\n");
    
    printf("Welcome to Hand Cricket\nPress any key to continue...");
    getch();
    
    menu();
    
}
