A. Cards
time limit per test1 second
memory limit per test256 megabytes
inputstandard input
outputstandard output
There are n cards (n is even) in the deck. Each card has a positive integer written on it. n?/?2 people will play new card game. At the beginning of the game each player gets two cards, each card is given to exactly one player.

Find the way to distribute cards such that the sum of values written of the cards will be equal for each player. It is guaranteed that it is always possible.

Input
The first line of the input contains integer n (2?≤?n?≤?100) — the number of cards in the deck. It is guaranteed that n is even.

The second line contains the sequence of n positive integers a1,?a2,?...,?an (1?≤?ai?≤?100), where ai is equal to the number written on the i-th card.

Output
Print n?/?2 pairs of integers, the i-th pair denote the cards that should be given to the i-th player. Each card should be given to exactly one player. Cards are numbered in the order they appear in the input.

It is guaranteed that solution exists. If there are several correct answers, you are allowed to print any of them.

Examples
input
6
1 5 7 4 4 3
output
1 3
6 2
4 5
input
4
10 10 10 10
output
1 2
3 4
Note
In the first sample, cards are distributed in such a way that each player has the sum of numbers written on his cards equal to 8.

In the second sample, all values ai are equal. Thus, any distribution is acceptable.




#include<iostream>
using namespace std;
struct Card
{
	int number;
	bool owned=false;
};
void main()
{
	int n,players,i,sum,j;
	cin >> n;
	players = n / 2;
	i = 0;
	sum = 0;
	Card* numbers = new Card[n];
	while (i<n)
	{
		cin >> numbers[i].number;
		sum += numbers[i].number;
		i++;
	}
	int avg = sum / players;
	for (i = 0; i < n; i++)
	{
		if (numbers[i].owned == false)
		{
			cout << i+1<<' ';
			numbers[i].owned = true;
			for (int j = 0; j < n; j++)
			{
				if ((numbers[j].owned==false)&&((numbers[i].number + numbers[j].number == avg)))
				{
					cout << j+1 << endl;
					numbers[j].owned = true;
					break;
				}
			}
		}
	}
	delete numbers;

}
