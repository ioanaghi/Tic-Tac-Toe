#include <iostream>
using namespace std;

//variables declaration
char game[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};//initialize the game a sa matrix
int row, column;
char token='X';
string p1;
string p2;
bool resulttie;
int cnt=0;

void first()
{
    

    //structure of the game
    cout<<"      |       |      \n";
    cout<<"  "<<game[0][0]<<"   |   " <<game[0][1]<<"   |   "<<game[0][2]<<"  \n";
    cout<<"      |       |      \n";
    cout<<"_____________________\n";
    cout<<"      |       |      \n";
    cout<<"  "<<game[1][0]<<"   |   " <<game[1][1]<<"   |   "<<game[1][2]<<"  \n";
    cout<<"      |       |      \n";
    cout<<"_____________________\n";
    cout<<"      |       |      \n";
    cout<<"  "<<game[2][0]<<"   |   " <<game[2][1]<<"   |   "<<game[2][2]<<"  \n";
    cout<<"      |       |      \n";

    cout<<endl<<endl<<endl;
   
}

void second()
{
    int digit;

    if(token=='X')
    {
        cout<<p1<<" what is your next move? (Write the digit of the place you want to fill)\n";
        cin>>digit;
    }

    if(token=='O')
    {
        cout<<p2<<" what is your next move? (Write the digit of the place you want to fill)\n";
        cin>>digit;
    }

    //each digit where is on the matrix
    if(digit==1)
    {
        row=0;
        column=0;
        cnt++;
    }
    if(digit==2)
    {
        row=0;
        column=1;
        cnt++;
    }
    if(digit==3)
    {
        row=0;
        column=2;
        cnt++;
    }
    if(digit==4)
    {
        row=1;
        column=0;
        cnt++;
    }
    if(digit==5)
    {
        row=1;
        column=1;
        cnt++;
    }
    if(digit==6)
    {
        row=1;
        column=2;
        cnt++;
    }
    if(digit==7)
    {
        row=2;
        column=0;
        cnt++;
    }
    if(digit==8)
    {
        row=2;
        column=1;
        cnt++;
    }
    if(digit==9)
    {
        row=2;
        column=2;
        cnt++;
    }
    if(digit<1||digit>9)
        {
            cout<<"Invalid input"<<endl;
        }


    //check if the cell is empty to input X
    if(token=='X'&& game[row][column]!='X'&&game[row][column]!='O')
        {
            game [row][column]='X';
            token='O';
        }
    else
    //check if the cell is empty for inpux O
    if(token=='O'&& game[row][column]!='X'&&game[row][column]!='O')
        {
            game[row][column]='O';
            token='X';
        }
    else
        {
            cout<<"This is not an empty space"<<endl;
            second();
        }
    first();
}

//winning the game
bool result()
{
    resulttie=false;
    //check on row and column
    for(int i=0;i<3;i++)
    {
        if((game[i][0]==game[i][1]&&game[i][0]==game[i][2])||(game[0][i]==game[1][i]&&game[2][i]==game[0][i]))
            return true;
    }
    //ceck on diagonal

    if((game[0][0]==game[1][1]&&game[0][0]==game[2][2])||(game[0][2]==game[1][1]&&game[0][2]==game[2][0]))
        return true;
    
    //check if the game is still ongoing
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            if(game[i][j]!='X'&&game[i][j]!='O')
                return false;
    }
    
    resulttie=true;
    if(cnt==9)
        return true;
    return false;
}

int main()
{
     //meeting the players
    cout<<"Please enter the name of the first player: \n";
    cin>>p1;
    cout<<"Please enter the name of the second player: \n";
    cin>>p2;
    cout<<"\n";

    
    cout<<"The first player is: "<<p1<<" and she/he will play first\n\n";
    cout<<"The second player is: "<<p2<<" and she/he will play second\n\n";


    //showcase the results
    while(!result())
    {
        first();
        second();
        result();
    }
    if(resulttie&&cnt==9)
        cout<<"It's a draw!"<<endl;
    if(token=='X')
        {
            cout <<p2<<" has won the game!"<<endl;
            return 0;
        }
    if(token=='O')
        {
            cout << p1 <<" has won the game!"<<endl;
            return 0;
        }
    return 0;
}
