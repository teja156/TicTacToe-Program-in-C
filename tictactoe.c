#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char arr[3][3] = {{'N','N','N'},{'N','N','N'},{'N','N','N'}};
int count=0;


int checkmatches()
{
    int i;
    int over=0;
    char ch;
    int j=0; //for rows
    int f=0;
    int g=0; //for columns
    int h =0;
    for(i=0;i<3;i++)
    {
        //check each row and column first
        //check row now
        if(arr[f][j]!='N')
        {
            if((arr[f][j]==arr[f][j+1]) && (arr[f][j]==arr[f][j+2]))
            {
                    
                    over = 1;
                    ch = arr[f][j];
                    break;

            }
        }
        //check column now
        if(arr[g][h]!='N')
        {
            if((arr[g][h]==arr[g+1][h]) && (arr[g][h] == arr[g+2][h]) && (arr[g][h]!='N'))
            {
                    
                    over = 1;
                    ch = arr[g][h];
                    break;
            }
        }
        f++;
        h++;
    }
    if(over==0)
    {
        //check diagonal now
        if((arr[0][0] == arr[1][1]) && (arr[0][0]!='N'))
        {
            
            if(arr[0][0]==arr[2][2])
            {
                over = 1;
                ch = arr[0][0];
            }
        }
        
        if((arr[0][2]==arr[1][1]) && (arr[0][2]!='N'))
        {
            if(arr[0][2] == arr[2][0])
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
        int i,j;
        int k=1;
        for(i=0;i<3;i++)
        {
            
            for(j=0;j<3;j++)
            {
                printf(" %d  |",k);
                k++;
                
            }
            printf("\n ------------------- \n");
            
        }
    }
    else
    {
        //choices are already made, display table with the choices made
        int i,j;
        int k=1;
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(arr[i][j]!='N')
                {
                    printf(" %c  |",arr[i][j]);
                    k++;
                }
                else
                {
                    printf("    |");
                    k++;
                }
            }
            printf("\n ------------------- \n");
        }
        
        //now check if there are any matches
        checkmatches();
    }
    
    return 0;
}



int insertx(int posx)
{
    switch(posx)
    {
        case 1:
            if(arr[0][0]!='Y'&&arr[0][0]!='X')
            {
                arr[0][0] = 'X'; 
                count++;
                return 1;
            }
            else
                return 0;
                
            
        case 2:
            if(arr[0][1]!='Y'&&arr[0][1]!='X')
            {
                arr[0][1] = 'X'; 
                count++;
                return 1;
            }
                
            else
                return 0;
            
            
        case 3:
            if(arr[0][2]!='Y'&&arr[0][2]!='X')
            {
                arr[0][2] = 'X'; 
                count++;
                return 1;
            }
            else 
                return 0;
            
        case 4:
            if(arr[1][0]!='Y'&&arr[1][0]!='X')
            {
                arr[1][0] = 'X';
                count++;
                return 1;
            }
            
            
        case 5:
            if(arr[1][1]!='Y'&&arr[1][1]!='X')
            {
                arr[1][1] = 'X';
                count++;
                return 1;
            }
            else
                return 0;
            
        case 6:
            if(arr[1][2]!='Y'&&arr[1][2]!='X')
            {
                arr[1][2] = 'X';
                count++;
                return 1;
            }
            else
                return 0;
            
        case 7:
            if(arr[2][0]!='Y'&&arr[2][0]!='X')
            {
                arr[2][0] = 'X';
                count++;
                return 1;
            }
            else
                return 0;
            
        case 8:
            if(arr[2][1]!='Y'&&arr[2][1]!='X')
            {
                arr[2][1] = 'X';
                count++;
                return 1;
            }
            else
                return 0;
            
        case 9:
            if(arr[2][2]!='Y'&&arr[2][2]!='X')
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
    
    //return 0;
}

int inserty()
{
    srand(time(NULL));
    //this value is automatically inserted by the computer at the best place possible
    //to generate random number use : num = (rand() % (upper – lower + 1)) + lower
    
    //when there are two Y's, or there are two X's in a row or column or diagonal, immediately put Y at the next position in order. This either makes the  
    //computer win or prevents the user from winning. Remember, our goal is not to let the user win.
    int inserted = 0;
    int i;
    int j=0;//for rows
    int f = 0;
    
    int g=0;//for columns
    int h=0;
    for(i=0;i<3;i++)
    {
        //check row - check if any two elements in the row is equal
        if(((arr[f][j]==arr[f][j+1] && arr[f][j]!='N') || (arr[f][j]==arr[f][j+2] && arr[f][j]!='N') || (arr[f][j+1]==arr[f][j+2] && arr[f][j+1]!='N')) && (inserted==0))
        {
            //inside this, check that the two equal characters are not N
            if((arr[f][j]=='N') && (inserted==0))
            {
                arr[f][j] = 'Y';
                count++;
                inserted = 1;
                //printf("inserted1");
            }
            else if((arr[f][j+1]=='N') && (inserted==0))
            {
                arr[f][j+1] = 'Y';
                count++;
                inserted = 1;
                //printf("inserted2");
            }
            else if((arr[f][j+2]=='N') && (inserted==0))
            {
                arr[f][j+2] = 'Y';
                count++;
                inserted = 1;
                //printf("inserted3");
            }
        }
        
        //check column - check if any two elements in the column are equal
        else if(((arr[g][h]==arr[g+1][h] && arr[g][h]!='N') || (arr[g][h]==arr[g+2][h] && arr[g][h]!='N') || (arr[g+1][h]==arr[g+2][h] && arr[g+1][h]!='N')) && (inserted==0))
        {
            if(arr[g][h]=='N')
            {
                arr[g][h] = 'Y';
                count++;
                inserted = 1;
                //printf("inserted4");
            }
            else if(arr[g+1][h]=='N')
            {
                arr[g+1][h] = 'Y';
                count++;
                inserted = 1;
                //printf("inserted5");
            }
            else if(arr[g+2][h]=='N')
            {
                
                arr[g+2][h] = 'Y';
                count++;
                inserted = 1;
                //printf("inserted6");
            }
        }
            
        f++;
        h++;
    }
    
    if(inserted==0)
    {
        //now check for diagonal - check if any two elements in the diagonal are equal
        if(((arr[0][0] == arr[1][1])&&arr[0][0]!='N') || ((arr[2][2]==arr[0][0]) && arr[2][2]!='N') || ((arr[1][1]==arr[2][2]) && arr[1][1]!='N'))
        {
            if(arr[0][0]=='N')
            {
                arr[0][0] = 'Y';
                count++;
                inserted = 1;
            }
            else if(arr[1][1]=='N')
            {
                arr[1][1] = 'Y';
                count++;
                inserted = 1;
            }
            else if(arr[2][2]=='N')
            {
                arr[2][2] = 'Y';
                count++;
                inserted = 1;
            }
        }

        else if(((arr[0][2] == arr[1][1]) && arr[0][2]!='N') || ((arr[2][0]==arr[0][2]) && arr[2][0]!='N') || ((arr[1][1]==arr[2][0]) && arr[1][1]!='N'))
        {
            if(arr[0][2]=='N')
            {
                arr[0][2] = 'Y';
                count++;
                inserted = 1;
            }
            else if(arr[1][1]=='N')
            {
                arr[1][1] = 'Y';
                count++;
                inserted = 1;
            }
            else if(arr[2][0]=='N')
            {
                arr[2][0] = 'Y';
                count++;
                inserted = 1;
            }
            
        }
        
        else
        {
            //at this point we can randomly insert Y at a position for now
            //int x,y;
            int upper = 3;
            int lower = 1;
            while(1)
            {
                //x = (rand() %(upper - lower + 1)) + lower;
                //y = (rand() %(upper - lower + 1)) + lower;
                
                //printf("\nRandom number 1 %d\n",((rand() %3) + 1)-1);
                //printf("\nRandom number 2 %d\n",((rand() %3) + 1)-1);
                
                int randpos1 = ((rand()%3) + 1)-1;
                int randpos2 = ((rand()%3) + 1)-1;
                if(arr[randpos1][randpos2]=='N')
                {
                    arr[randpos1][randpos2] = 'Y';
                    inserted=1;
                    count++;
                    printf("Random insertion done\n");
                    break;
                }
            }
            
            
        }
        /**
        
        if(inserted==0)
        {
            int i,j;
            for(i=0;i<3;i++)
                for(i=0;i<3;i++)
                {
                    if(arr[i][j]=='N')
                    {
                        arr[i][j]='Y';
                        count++;
                        inserted=1;
                    }
                }
        }
        */
        
        
    }
    
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
            printf("Game ended.");
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
                printf("Invalid choice enetered, please enter again : ");
        }
        
        printf("You made your choice : \n");
        showtable();
        printf("Now, its computer's turn : \n");
        printf("Enter 1 to let computer play : ");
        int an;
        
        while(1)
        {
            scanf("%d",&an);
            if(an==1)
            {
                inserty();
                break;
            }
                
        else
            printf("\nInvalid option selected, please enter again : ");
            
        }
        
        
        
    }
    
    return 0;
}
