#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<unistd.h>
#include<windows.h>

using namespace std;

bool gameOver;
int x[3] ={ 0, 1, 2 };
int x1 = 0, x2 = 1, x3 = 2;
int SCORE;
const char jack[] = "J";
const char queen[] = "Q";
const char king[] = "K";
const int width = 13, length = 5;
enum eControls{ STOP = 0, FIRST, SECOND, THIRD, NEXT };
eControls contrls;

int irand(int a, int b);

void Input(){
	switch(_getch())
	{
	case '1':
		contrls = FIRST;
		break;
	case '2':
		contrls = SECOND;
		break;
	case '3':
		contrls = THIRD;
		break;
	case ' ':
		contrls = NEXT;
		break;
	case 'x':
		contrls = STOP;
		gameOver = true;
		break;
	}
}

void ProceedFunc(){
	cout << "Proceed?\n";
	while((contrls != NEXT) && (contrls != STOP)){
		Input();
		if(contrls == STOP)
			gameOver = true;
	}
}

void Setup(){
	gameOver = false;
	SCORE = 0;
	contrls = FIRST;
	cout << "GAME STARTED\nHere is 3 cards: Jack, Queen and King\n";
	cout << "We will shuffle it and then you should choose only 1 card which we asked for.\n";
}

void randPOS(){
	x1 = irand(0, 20) % 3;
	x2 = irand(0, 20) % 3;
	while(x2 == x1)
		x2 = irand(0, 20) % 3;
	x3 = irand(0, 20) % 3;
	while((x3 == x2) || (x3 == x1))
		x3 = irand(0, 20) % 3;
}

void Draw(){
	for(int j = 0; j < 3; j++){
		randPOS();
		for(int i = 0; i < width; i++)
			cout << "#";
		
		cout << endl;
		cout << "#   #   #   #\n";
		for(int jj = 0; jj < 3; jj++){
			if(x[jj] == x1)
				cout << "# " << jack << " ";	
			if(x[jj] == x2)
				cout << "# " << queen << " ";
			if(x[jj] == x3)
				cout << "# " << king << " ";
		}
		
		cout << "#" << endl;
		cout << "#   #   #   #\n";
		
		for(int i = 0; i < width; i++)
			cout << "#";
		
		cout << endl;
		sleep(1);
		system("cls");
	}
	for(int i = 0; i < width; i++)
			cout << "#";
		
		cout << endl;
		for(int k = 0; k < 3; k++)
			cout << "#   #   #   #\n";
		
		for(int i = 0; i < width; i++)
			cout << "#";
		cout << endl;
}


void Logic(){
	cout << "Which card is ";
	int question, True;
	question = irand(0, 20) % 3;
	switch(question)
		{
		case 0:
			cout << "jack?\n";	
			True = x1;
			break;
		case 1:
			cout << "queen?\n";
			True = x2;
			break;
		case 2:
			cout << "king?\n";
			True = x3;
			break;
		}
	
	while(contrls == STOP)
		Input();
	if(x[contrls-1] == True){				
		cout << "GOTCHA! You're right!\nYour score: ";
		SCORE += 10;
		cout << SCORE << endl;
	}
	else{
		cout << "NOPE! WRONG ANSWER!\nYour score: ";
		SCORE -= 5;
		cout << SCORE << endl;
	}
	ProceedFunc();
	contrls = STOP;
}


int main(void){											
	Setup();
	ProceedFunc();
	while(!gameOver){
		contrls = STOP;
		system("cls");
		Draw();
		Logic();
		if(SCORE == 100)
			break;
		if(SCORE == -15)
			break;
	}
	if(SCORE == 100)
		cout << "You win!\nHave a nice day!";
	if(SCORE == -15)
		cout << "Game is Over!\nYou loosed.";
	if((SCORE > -15) && (SCORE < 100))
		cout << "Game is Over!\n";
		
	return 0;
}

int irand(int a, int b)
{
	return a + rand() % (b - a + 1);
}









