#include<iostream>
using namespace std;
 
bool MainMenu(char &input);
void ShowStory(int &difficulty, char &input);
void ResetGame(int &difficulty, int &lowerBound, int &upperBound, char &input, bool &userDone);
void GetInput(int &AI_Guess, int &lowerBound, int &upperBound, char &input, bool &userDone);
bool UpdateWorld(int &AI_Guess, int &lowerBound, int &upperBound, bool &userDone);
void DrawGraphics(int &AI_Guess);
bool GameOverScreen(int &difficulty, char &input, bool &userDone);
bool PlayGame(bool &userDone,int &AI_Guess, int &lowerBound, int &upperBound, char &input,int &difficulty);
 
int main() 
{
	int difficulty = 0;
	char input = 'n';
	bool userDone = true;
	int lowerBound = 1;
	int upperBound = difficulty + 1;
	int AI_Guess = (upperBound-lowerBound)/2; 
	while(MainMenu(input)) 
		{
			while(PlayGame(userDone, AI_Guess, lowerBound, upperBound, input, difficulty));
		}
	return 0;
}
 
bool PlayGame(bool &userDone,int &AI_Guess, int &lowerBound, int &upperBound, char &input,int &difficulty) {
  ResetGame(difficulty, lowerBound, upperBound, input, userDone);
  ShowStory(difficulty, input); 
  while(userDone) { // This is the main game loop
 
    UpdateWorld(AI_Guess, lowerBound, upperBound, userDone);
    DrawGraphics(AI_Guess);
    GetInput(AI_Guess, lowerBound, upperBound, input, userDone);
  }
 
  return GameOverScreen(difficulty, input, userDone);
}
 
bool MainMenu(char &input) {
  cout << "Welcome to the Game!" << endl;
  cout << "Would you like to play a game?" << endl;
  while(true) {
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << ">" << endl;
    cin >> input;
 
    if(input == '1') 
	{	
		cout << "Let's play!" << endl;
		return true; // This play the game
	}
    else if(input == '2') 
	{
		cout << "BOOOOOOOOOOOOOOO!" << endl;
		return false; // This will quit
	}
  }
}
 
// This function could show a little cutscene intro story.
// I've used it to display some instructions.
void ShowStory(int &difficulty, char &input)
{
  input = 'n'; // Make sure input is not 'y'
 
  cout << "Once upon a time in a galaxy far far away..." << endl;
  cout << "You thought of a number between 1 and " << difficulty << endl;
  cout << "I will attempt to guess the number." << endl;
  while(input != 'y') 
  {
		cout << "Have you got one (y/n)? ";
		cin >> input;
		if(input != 'y') cout << "Ok, I'll wait a bit..." << endl;
  }
 
  cout << endl;
}
 
void ResetGame(int &difficulty, int &lowerBound, int &upperBound, char &input, bool &userDone)
{
	difficulty += 10;
	lowerBound = 0;
	upperBound = difficulty + 1;
	input = 'n';
}
 
bool UpdateWorld(int &AI_Guess, int &lowerBound, int &upperBound, bool &userDone)
{	
    int Old_AI_Guess = AI_Guess;	
	AI_Guess = (lowerBound + upperBound) / 2; // Generate the next guess
	if(Old_AI_Guess == AI_Guess)
	{
	    cout<< "CHEATER !!! CHEATER!! PUMPKIN EATER!!" << endl;
		userDone = false;
	    return false;
	}
	return true;
}
 
void DrawGraphics(int &AI_Guess)
{	
	cout << "I think it's " << AI_Guess << "! Am I right?" << endl;
	cout << "l. Lower " << endl;
	cout << "h. Higher" << endl;
	cout << "y. Yes!" << endl;
}
 
void GetInput(int &AI_Guess, int &lowerBound, int &upperBound, char &input, bool &userDone)
{

	cin >> input; // Read something from the keyboard
 
  // Act on input:
	  switch(input) 
	  {
		case 'l': 
			upperBound = AI_Guess; 
			break;
		case 'h': 
			lowerBound = AI_Guess; 
			break;
		case 'y': 
			cout << "YaY!!!" << endl;
			cout << "I did it!!!"<< endl;
			cout << "I have tremendous joy!!!"<<endl;
			userDone = false;
			break;
		default:
			cout << "Please enter a 'l' 'h' or 'I'" << endl;
			GetInput(AI_Guess, lowerBound, upperBound, input, userDone);
		break;
	  }
	}

 
bool GameOverScreen(int &difficulty, char &input, bool &userDone)
{
	cout << endl;
	cout << "That was pretty good, play again (y/n)? " << endl;
	cin >> input;
	userDone = true;
 
  if(input != 'y')
  {
	  return false;
	  
  }
  else 
  {
	  cout << "would you like to change difficulty ? (y/n)" << endl;
	  cin >> input;
	  if (input == 'y')
	  {
		cout << "Enter a difficulty value (must be a posotive interger)" << endl;
		cin >> difficulty;
	  }
	  return true;
  }
}