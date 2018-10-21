#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

char arr[3][3] = {{'N','N','N'},{'N','N','N'},{'N','N','N'}};
int count=0;

int checkmatches()
{
    int i;
    int over=0;
    char ch;
    for(i=0;i<3;i++)
    {
        //check each row and column first
        //check row now
        if(arr[i][0]!='N')
        {
            if((arr[i][0]==arr[i][1]) && (arr[i][1]==arr[i][2]))
            {
                    over = 1;
                    ch = arr[i][0];
                    break;

            }
        }
        //check column now
        if(arr[0][i]!='N')
        {
            if((arr[0][i]==arr[1][i]) && (arr[1][i] == arr[2][i]))
            {
                    over = 1;
                    ch = arr[0][i];
                    break;
            }
        }
    }
    if(over==0)
    {
        //check diagonal now
        if(arr[1][1]!='N')
        {
            //check left to right
            if((arr[0][0] == arr[1][1]) && arr[0][0]==arr[2][2])
            {
                over = 1;
                ch = arr[0][0];
            }
            //check right to left
            else if((arr[0][2]==arr[1][1]) && arr[0][2] == arr[2][0])
            {
                over = 1;
                ch = arr[0][2];
            }
        }

    }
    if(over==1)
    {
        printf("That's a match!\n");
        if(ch=='X')
            printf("Congratulations, you won :)\n");
        else if(ch=='Y')
            printf("oops, computer wins! better luck next time baby\n");
        exit(0);
    }
    return 0;
}

int showtable()
{
    if(count==0)
    {
        //no choices are yet made, display default table with positions of each cell
        int i;
        for(i=1;i<=9;i++)
        {
            printf(" %d  |",i);
            if(i%3==0)
                printf("\n ------------------- \n");
        }
    }
    else
    {
        //choices are already made, display table with the choices made
        int i,j;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]!='N')
                    printf(" %c  |",arr[i][j]);
                else
                    printf("    |");
            }
            printf("\n ------------------- \n");
        }
        //check if there are any matches but cant win before 5 turns so no need to check before that
        if(count>=5)
            checkmatches();
    }
    return 0;
}

int insertx(int posx)
{
    switch(posx)
    {
        case 1:
            if(arr[0][0]=='N')
            {
                arr[0][0] = 'X';
                count++;
                return 1;
            }
            else
                return 0;
        case 2:
            if(arr[0][1]=='N')
            {
                arr[0][1] = 'X';
                count++;
                return 1;
            }

            else
                return 0;


        case 3:
            if(arr[0][2]=='N')
            {
                arr[0][2] = 'X';
                count++;
                return 1;
            }
            else
                return 0;

        case 4:
            if(arr[1][0]=='N')
            {
                arr[1][0] = 'X';
                count++;
                return 1;
            }


        case 5:
            if(arr[1][1]=='N')
            {
                arr[1][1] = 'X';
                count++;
                return 1;
            }
            else
                return 0;

        case 6:
            if(arr[1][2]=='N')
            {
                arr[1][2] = 'X';
                count++;
                return 1;
            }
            else
                return 0;

        case 7:
            if(arr[2][0]=='N')
            {
                arr[2][0] = 'X';
                count++;
                return 1;
            }
            else
                return 0;

        case 8:
            if(arr[2][1]=='N')
            {
                arr[2][1] = 'X';
                count++;
                return 1;
            }
            else
                return 0;

        case 9:
            if(arr[2][2]=='N')
            {
                arr[2][2] = 'X';
                count++;
                return 1;
            }
            else
                return 0;

        default:
            return 0;

    }
}
int inserty()
{
    //this value is automatically inserted by the computer at the best place possible
    //to generate random number use : num = (rand() % (upper – lower + 1)) + lower

    //when there are two Y's, or there are two X's in a row or column or diagonal, immediately put Y at the next position in order. This either makes the
    //computer win or prevents the user from winning. Remember, our goal is not to let the user win.
    int inserted = 0;
    int i;
    for(i=0;i<3;i++)
    {
        //If inserted no need to check again
        if(inserted==1)
            break;
        //check row - check if any two elements in the row is equal
        if((arr[i][0]==arr[i][1] && arr[i][0]!='N') || (arr[i][0]==arr[i][2] && arr[i][0]!='N') || (arr[i][1]==arr[i][2] && arr[i][1]!='N'))
        {
            //inside this, check that the two equal characters are not N
            if(arr[i][0]=='N')
            {
                arr[i][0] = 'Y';
                inserted = 1;
            }
            else if(arr[i][1]=='N')
            {
                arr[i][1] = 'Y';
                inserted = 1;
            }
            else if(arr[i][2]=='N')
            {
                arr[i][2] = 'Y';
                inserted = 1;
            }
        }
        //check column - check if any two elements in the column are equal
        if(((arr[0][i]==arr[1][i] && arr[0][i]!='N') || (arr[0][i]==arr[2][i] && arr[0][i]!='N') || (arr[1][i]==arr[2][i] && arr[1][i]!='N')) && (inserted==0))
        {
            if(arr[0][i]=='N')
            {
                arr[0][i] = 'Y';
                inserted = 1;
            }
            else if(arr[1][i]=='N')
            {
                arr[1][i] = 'Y';
                inserted = 1;
            }
            else if(arr[2][i]=='N')
            {
                arr[2][i] = 'Y';
                inserted = 1;
            }
        }
    }
    if(inserted==0)
    {
        //now check for left to right diagonal - check if any two elements in the diagonal are equal
        if(((arr[0][0] == arr[1][1])&&arr[0][0]!='N') || ((arr[2][2]==arr[0][0]) && arr[2][2]!='N') || ((arr[1][1]==arr[2][2]) && arr[1][1]!='N'))
        {
            if(arr[0][0]=='N')
            {
                arr[0][0] = 'Y';
                inserted = 1;
            }
            else if(arr[1][1]=='N')
            {
                arr[1][1] = 'Y';
                inserted = 1;
            }
            else if(arr[2][2]=='N')
            {
                arr[2][2] = 'Y';
                inserted = 1;
            }
        }
        //check for right to left diagonal
        if((((arr[0][2] == arr[1][1]) && arr[0][2]!='N') || ((arr[2][0]==arr[0][2]) && arr[2][0]!='N') || ((arr[1][1]==arr[2][0]) && arr[1][1]!='N'))&& inserted==0)
        {
            if(arr[0][2]=='N')
            {
                arr[0][2] = 'Y';
                inserted = 1;
            }
            else if(arr[1][1]=='N')
            {
                arr[1][1] = 'Y';
                inserted = 1;
            }
            else if(arr[2][0]=='N')
            {
                arr[2][0] = 'Y';
                inserted = 1;
            }
        }
    }
    if(inserted==0)
    {
        //at this point we can randomly insert Y at a position for now
        int temp;
        for(i=0;i<100;++i)
        {
            srand(time(NULL));
            temp=rand();
            if(arr[temp%3][temp%3]=='N')
            {
                arr[temp%3][temp%3] = 'Y';
                inserted=1;
                break;
            }
        }
        //If Still Cant find random empty place (protection from infinite loop) then add in first empty place
        if(inserted==0)
        {
            for(i=0;i<3;++i)
            {
                for(int j=0;j<3;++j)
                {
                    //Select First Empty place
                    if(arr[i][j]=='N')
                    {
                        arr[i][j]='Y';
                        inserted=1;
                        break;
                    }
                }
                if(inserted==1)
                    break;
            }
        }
    }
    count++;
    return 0;
}

int main()
{
    printf("You play for 'X', computer plays for 'O'\n");
    while(1)
    {
        showtable();
        if(count==9)
        {
            printf("\nGame ended. Its a Draw");
            getch();
            exit(0);
        }
        printf("Where do you want to insert X? (1,2,3,4,5,6,7,8,9) : ");
        int posx;
        while(1)
        {
            scanf("%d",&posx);

            int a = insertx(posx);
            if(a==1)
                break;
            else
                printf("Invalid choice entered, please enter again : ");
        }
        printf("You made your choice !!\n");
        showtable();
        if(count==9)
        {
            printf("\nGame ended. Its a Draw");
            getch();
            exit(0);
        }
        printf("Now, its computer's turn : \n");
        printf("Press Enter to let computer play...");
        getch();
        printf("\n");
        inserty();
    }
    return 0;
}
