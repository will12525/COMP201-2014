#include <iostream>
#include <string>
#include <vector>
using namespace std;

//this is an enumeration
//it defines a type, along with the possibilities
enum Suit {HEARTS, SPADES, CLUBS, DIAMONDS};
const string suitName[]={"Hearts","Spades","Clubs","Diamonds"};

enum Rank {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE};
const string rankName[]={"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};

//defines a type, called card
//it consists of a suit and a rank
typedef struct{ 
	//type variable
	Suit suit;
	//type variable
	Rank rank;
} Card;

void printCard(Card card)
{
	cout<<rankName[card.rank]<<" of " << suitName[card.suit]<<endl;
}
vector<Card> makeDeck()
{
	vector<Card>holder;
	
	for(int x=0;x<4;x++)
	{
		for(int y=0;y<13;y++)
		{
			Card card;
			card.suit=Suit(x);
			card.rank=Rank(y);
			holder.push_back(card);
		}
	}
	return holder;
}

int main()
{
	Card card;
	
	//card.suit = SPADES;
	//card.rank = ACE;
	vector<Card> deck = makeDeck();
	for(int i=0;i<deck.size();i++)
	{
		printCard(deck[i]);
		cout<<endl;
	}
	
	
	return 0;
}