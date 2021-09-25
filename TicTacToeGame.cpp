#include<iostream>
#include<cstdlib>
#include<time.h>
#include<windows.h>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char position;
int currentuser; 
void timer()
{
	cout<<"Clock ";
	for(int i=0; i<5; i++)
	{
		Sleep(1000);
		cout<<i+1<<" ";
	}
	cout<<endl;
}
void drawboard()
{
	system("color 02");
	cout<<" "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<endl;
	cout<<"........."<<endl;
	cout<<" "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<endl;
	cout<<"........."<<endl;
	cout<<" "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<endl;
}
bool placeMarker(int slot)
{
	int col, row=slot%3;
	if(slot%3==0)
	{
		row=(slot/3)-1;
		col=2;
	}
	else
	{
		row=(slot/3);
		col=(slot%3)-1;
	}
//	cout<<row<<", "<<col<<endl;
	if (board[row][col]!='x'&&board[row][col]!='o')
	{
		timer();
		board[row][col]=position;
		return true;
	}
	else return false;

}

int winner()
{
	int i;
	for(i=0; i<3; i++)
	{
		//rows
		if(board[i][0]== board[i][1]&&board[i][1]==board[i][2])
		return currentuser;
		//coloums
		if(board[0][i]==board[1][i]&&board[1][i]==board[2][i])
		return currentuser;
	}
	//diagonals
	
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])
		return currentuser;
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])
		return currentuser;	
	  
	return 0;
}

void interchange()
{
	if (position=='x')
	{
		position='o';
	}
	else
	{
		position='x';
	}
	if (currentuser==1)
	{
		currentuser=2;
	}
	else
	{
		currentuser=1;
	}
}

void game()
{
	char player_won;
	cout<<" Player 1, Please choose your marker :"<<endl;
	char marker_p1;
	cin>> marker_p1;
	currentuser=1;
	position= marker_p1;
	drawboard();
	for(int i=0; i<9; i++)
	{

	//	else
	//	{
		cout<<"Its player "<<currentuser<<" turn, Enter ur slot: "<<endl;
		int slot;
		cin>>slot;
	//	}

		if(slot<1||slot>9)
		{
			cout<<"Invalid slot! try another "<<endl;
			i--;
			continue;
		}
		if(!placeMarker(slot))
		{
			cout<<"the slot is occupied! try another "<<endl;
			i--;
			continue;
		}
		
		drawboard();
		player_won=winner();
		if(player_won== 1)
		{
			cout<<"Player 1 won!!!\nConratulations "<<endl;
			break;
		}
		if(player_won== 2)
		{
			cout<<"Player 2 won!!!\nConratulations "<<endl;
			break;
		}
		//system("CLS");
		interchange();
				//drawboard();
				
	}
		/*if (player_won==0)
		{
			cout<<"Its a tie Game "<<endl;
			
		}*/
		
}
	
int main()
{
	char x;
	do
	{
		system("color E");
		game();
		cout<<"Do you want to play again??(y/n)"<<endl;
		cin>>x;
	}
	while(x=='y');
	
	return 0;
}
