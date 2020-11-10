//Jared Howie
//October 4 2018 


#include <iostream>		
#include <stdexcept>
#include <sstream>
#include "PlayingCard.h"
#include <ctime>


// Container class
class StandardDeck
{
	private:
		PlayingCard * myArray;  
		int mySize;	
		
	public:
		StandardDeck();
		void virtual Initialize();
		
		~StandardDeck() { delete [] myArray;} 
		StandardDeck(const StandardDeck &source); 
		StandardDeck& operator=(const StandardDeck &source); 
		int CardsRemaining(){ return mySize;};
		PlayingCard DrawRandomCard();
		PlayingCard DrawNextCard();
		void Shuffle();
		void DebugString() const;
};


int main()
{
	PlayingCard card;
	StandardDeck cards;
	cout << "As Initialized \n" 
		 << "--------------\n";
	cards.DebugString();
	
	cards.Shuffle();
		cout << "After Shuffle \n" 
		 	 << "--------------\n";
	cards.DebugString();
	
	card = cards.DrawNextCard();
	
	cout << "After DrawNextCard \n" 
		 << "--------------\n"
		 << "Card Taken Out :\n"
		 << (string) card << endl;
	cards.DebugString();

	card = cards.DrawRandomCard();
	
	cout << "After DrawRandomCard \n" 
		 << "--------------\n"
		 << "Card Taken Out :\n"
		 << (string) card << endl;
	cards.DebugString();

	cards.Shuffle();
		cout << "After Shuffle 2 \n" 
		 	 << "----------------\n";
	cards.DebugString();
	return 0;
}

StandardDeck::StandardDeck()
{
	
	myArray = 0;
	
	Initialize();
}


void StandardDeck::Initialize()
{
	int size = 52;
	int card = 0;
	if(myArray != 0)
	{
		delete [] myArray;
	}
		
	else
	{
		myArray = new PlayingCard [size]; 
		mySize = size; 
		
		for(int s = 0; s < 4; s++)
		{
			for(int r = 1; r <= 13; r++)
			{
				myArray[card].SetSuit(s); 
				myArray[card].SetRank(r,true); 
				card++;
			}
			
		}
	}	
	
}

StandardDeck::StandardDeck(const StandardDeck &source)
{
	mySize = source.mySize; 
	myArray = new PlayingCard [mySize]; 
	for(int i = 0; i < mySize; i++)
		myArray[i] = source.myArray[i];
}

StandardDeck& StandardDeck::operator=(const StandardDeck &source)
{
	delete [] myArray; 
	mySize = source.mySize; 
	myArray = new PlayingCard [mySize];
	
	for(int i = 0; i < mySize; i++)
		myArray[i] = source.myArray[i];
	
	return *this;
} 

void StandardDeck::DebugString() const
{
	stringstream debug;
	debug << "myArray: " << myArray << endl
		  << "mySize:  " << mySize << endl;
	for(int i = 0; i < mySize; i++)
	{
		debug << "[" << i << "]: " << (string) myArray[i] << endl;
	}

	debug << "\n===============================================" << endl;
	cout << debug.str();
}

PlayingCard StandardDeck::DrawNextCard()
{

	if(mySize <= 0)
		throw out_of_range("The deck is empty");

	PlayingCard card = myArray[0];
	

	for(int moveTo = 0; moveTo < mySize - 1; moveTo++)
	{
		myArray[moveTo] = myArray[moveTo + 1];
	}
	
	
	mySize = mySize - 1;

	return card;
}

PlayingCard StandardDeck::DrawRandomCard()
{

	if(mySize <= 0)
		throw out_of_range("The deck is empty");
	int ranCard = rand() % mySize;
	PlayingCard card = myArray[ranCard];
	

	for(int moveTo = ranCard; moveTo < mySize - 1; moveTo++)
	{
		myArray[moveTo] = myArray[moveTo + 1];
	}
	
	
	mySize = mySize - 1;

	return card;
}

void StandardDeck::Shuffle()
{
	srand(time(0));
	for (int z=0; z< mySize; z++) 
	{
	    int ranNum = rand() % mySize;
	    int setShuffle;
		myArray[setShuffle] = myArray[z]; myArray[z] = myArray[ranNum]; myArray[ranNum] = myArray[setShuffle];
	}
	
}
