#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct hangman
{
    char qs[25];
    char clue[100];
    int len;
} ;

struct hangman game[] ={{"ABDULKALAM","11TH PRESIDENT OF INDIA",10},
                         {"MAP","HAVE RIVERS,LAKES WITH NO WATER",3},
                         {"BLACKBOARD","DIRTY WHEN IT IS WHITE",10},
                         {"GOSSIP","SPREADS FAST BUT ERRONEOUS",6},
                         {"BROCOLLI","VEGETABLE",8},
                         {"FOOTSTEPS","MORE WE TAKE,MORE WE LEAVE BEHIND",9},
                         {"MONALISA","INCOMPLE PORTRAIT ACCORDTING TO AN ARTIST",8},
                         {"JAZZ","TYPE OF DANCE",4},
                         {"CORONA","MOST FAMOUS MEXICAN BEER",6},
                         {"BEES","CAN DETECT BOMBS",4},
                         {"BIGBEN","MOST FAMOUS LANDMARK IN UK",6},
                         {"CALEDONIA","WHAT ROMANS CALL SCOTTLAND",9}};


int cartoon(int incrt);
void hint();
void samelvl(int lvl);
void print(int lvl,char ans[]);

int main()
{
	int i,j;
    int lvl = 0,view = 0,h,count;
    do
    {
        int crt = 0,incrt = 0,temp = 0,flag = 0;
        char ch;
        char ans[]={'_','_','_','_','_','_','_','_','_','_'};
        printf("\n");
        system("cls");
        printf(" \n LEVEL = %d \n",(lvl+1));
        for(j=0;j<game[lvl].len;j++)
        {
            printf("%c ",ans[j]);
        }
        while(1)
        {
            fflush(stdin);
            printf("\n\n CLUE:%s",game[lvl].clue);
            printf("\n PRESS 6 TO VIEW THE HINT ELSE 0:");
            scanf("%d",&h);
            if(h==6)
            {
                system("cls");
                view++;

                for(i=65;i<=90;i++)
                {
                    count = 0;
                    for(j=0;j<game[lvl].len;j++)
                    {
                        if(game[lvl].qs[j]==i)
                        {
                            if(i != ans[j])
                            {
                                printf("\n %c",game[lvl].qs[j]);
                                ans[j] = game[lvl].qs[j];
                                print(lvl,ans);
                                count = 1;
                            }
                        }
                    }
                    if(count==1)
                        break;
                }
            }

              else
              {printf("\n\n enter a character:");
                fflush(stdin);
                scanf("%c",&ch);
                ch = toupper(ch);
                system("cls");

                for(j=0;j<game[lvl].len;j++)
                {
                    if(ch == game[lvl].qs[j] && ans[j] == '_')
                    {
                          ans[j] = ch;
                          crt++;
                          temp++;
                    }
                }
              }
                for(j=0;j<game[lvl].len;j++)
                {
                    printf("%c ",ans[j]);
                }


                if(crt == game[lvl].len)
                    break;

                if(temp == 0)
                {
                        incrt++;
                        flag = cartoon(incrt);
                }

                temp = 0;

                if(flag == 5)
                    break;

                for(j=0;j<game[lvl].len;j++)
                {
                    printf("%c ",ans[j]);
                }

            }


            if(flag != 5)
                lvl++;


    }while(lvl<12);


    return 0;
}

void hint(char ans[],int lvl)
{
	int i,j;
    for(i=0;i<game[lvl].len;i++)
    {
        for(j=0;j<game[lvl].len;j++)
        {
            if(game[lvl].qs[i]!= ans[j])
            {
                printf("\n %c",game[lvl].qs[i]);
                ans[j] = game[lvl].qs[i];
                print(lvl,ans);
                break;
            }
        }
    }

}

void print(int lvl,char ans[])
{
	int j;
    for(j=0;j<game[lvl].len;j++)
    {
        printf("%c ",ans[j]);
    }
}

int cartoon(int incrt)
{
    int var = 0;
    switch(incrt)
    {
    case 1:
        {
            printf("   _____ \n"
                 "  |     | \n"
                 "  |      \n"
                 "  |      \n"
                 "  |      \n"
                 "  |      \n"
                 "  |      \n"
                 "__|__\n");
            break;
        }
    case 2:
        {
            printf("   _____ \n"
                  "  |     | \n"
                  "  |    ( )\n"
                  "  |      \n"
                  "  |      \n"
                  "  |      \n"
                  "  |      \n"
                  "__|__\n");
                  break;
        }
    case 3:
        {
            printf("   _____ \n"
                  "  |     | \n"
                  "  |    ( )\n"
                  "  |     | \n"
                  "  |     | \n"
                  "  |     | \n"
                  "  |      \n"
                  "__|__\n");
                  break;
        }
    case 4:
        {
            printf("   _____ \n"
                  "  |     | \n"
                  "  |    ( )\n"
                  "  |     |   \n"
                  "  |    /|\\"
                "\n  |     |   \n"
                  "  |      \n"
                  "__|__\n");
                  break;
        }
    case 5:
        {
            printf("   _____ \n"
                  "  |     | \n"
                  "  |    ( )\n"
                  "  |     | \n"
                  "  |    /|\\  \n"
                  "  |     |   \n"
                  "  |    / \\   \n"
                  "__|__\n");
            //var = 25;
            printf("\n YOU FAILED !!!");
            printf("\n PRESS 5 TO CONTINUE");
            scanf("%d",&var);
            break;
        }
      }

      return var;
}
