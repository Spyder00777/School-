#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <stdio.h>
#include <string.h>
using namespace std;

void shuffle( int order[ ],int x )
{
// places the numbers from 1 to 20 in random order in the array order
	int position;
	int  i;
	for (i= 1; i <= x; i++ ) 
	{
		int count = 0;
		do 
		{	
			position = rand() % x;
			count++;
		} 
		while( order[position]!= 0 && count < 100 );
		order[position] = i;
   }
}
void playorder( const int order[ ], const char *songlist[], int numSongs) 
{
// prints out the songs in order given by order
	for ( int song = 1; song <= numSongs; song++ )
	{
		for ( int position = 0; position < numSongs; position++ )
		{
            if ( order[position] == song )
			{
               cout << song  << ". " << songlist[ position ] << "\n";
			}
	  }  
   }
	cout<< endl;
}

void Union(const char *friends[], const char *personal[], int numSongs)
{
	cout << "\nThe combined list is: \n" ;
	bool same = false;
	int counter = 1;
	for (int x = 0; x < numSongs; x ++)
	{
		cout << counter << ". " << personal[x] << "\n" ;
		counter++; 
	}
	for (int i = 0; i < numSongs; i++)
	{
		same = false;
		for (int j = 0; j < numSongs; j++)
		{
			if (strcmp (friends[i],personal[j]) == 0)
			{
				same = true;
			}
		}
		if (same != true)
		{
			cout << counter << ". " << friends[i] << "\n" ;
			counter++;
		}

	}
}

void intersection(const char *friends[], const char *personal[], int numSongs)
{
	cout << "\nThe intersection list is: \n" ;
	int counter = 1;
	for (int i = 0; i < numSongs; i++)
	{
		for (int j = 0; j < numSongs; j++)
		{
			if (strcmp (friends[i],personal[j]) == 0)
			{
				cout << counter << ". " << friends[i] << "\n" ;
				counter++;
			}

		}
	}
}

int main()  
{	int numSongs = 20;
	int songorder[numSongs] =  {0};
	const char *myfriendsmp3list[numSongs] = 
		{ "Don't","Same Old Love","Down in the DM","Hotline Bling",
			"7 Years","Here","Uptown Funk","Jumpman","I Took a Pill", "What Do You Mean",
			"Hide Away","The Hills","Adventure of A Lifetime","Like I'm Going to Lose You","Say it",
			"Summer Sixteen","Can't Feel My Face", "Ex's and Oh's","679","Die A Happy Man"};
			
	const char *mymp3list[ numSongs ] = 
        {"Work","Love Yourself","Stressed Out","Sorry","My House","Pillow Talk","Hello",
			"Me Myself and I","Roses","Cake By The Ocean","Hands to Myself","One Call Away","Stitches",
			"When We Were Young","In the Night","Don't","Same Old Love","Down in the DM",
			"Hotline Bling","7 Years"};
  
	cout << "Original Song Order:" << endl;
	for (int i= 1 ; i <= numSongs ; ++i)
         cout << i << ". " << mymp3list[i-1] << endl;
   
	cout << "Shuffled Order:" << endl;
	srand( time( 0 ));
	shuffle( songorder , numSongs); 
	for (int i = 0; i < numSongs ; ++i )
	{
		cout << i+1 << "->" << songorder[i] << "   " ;
	}
	cout << endl<< endl;
	playorder( songorder, mymp3list,numSongs);
	Union(myfriendsmp3list, mymp3list, numSongs);
	intersection(myfriendsmp3list, mymp3list, numSongs);
	return 0;
}