//题目

/*A.Launch of Collider
time limit per test2 seconds
memory limit per test256 megabytes
input standard input
output standard output
There will be a launch of a new, powerful and unusual collider very soon, which located along a straight line.n particles will be launched inside it.All of them are located in a straight line and there can not be two or more particles located in the same point.The coordinates of the particles coincide with the distance in meters from the center of the collider, xi is the coordinate of the i-th particle and its position in the collider at the same time.All coordinates of particle positions are even integers.

You know the direction of each particle movement — it will move to the right or to the left after the collider's launch start. All particles begin to move simultaneously at the time of the collider's launch start.Each particle will move straight to the left or straight to the right with the constant speed of 1 meter per microsecond.The collider is big enough so particles can not leave it in the foreseeable time.

Write the program which finds the moment of the first collision of any two particles of the collider. In other words, find the number of microseconds before the first moment when any two particles are at the same point.


Input
The first line contains the positive integer n (1 ≤ n≤ 200 000) — the number of particles.

The second line contains n symbols "L" and "R". If the i-th symbol equals "L", then the i-th particle will move to the left, otherwise the i-th symbol equals "R" and the i-th particle will move to the right.

The third line contains the sequence of pairwise distinct even integers x1, x2,..., xn (0 ≤ xi≤ 109) — the coordinates of particles in the order from the left to the right.It is guaranteed that the coordinates of particles are given in the increasing order.

Output
In the first line print the only integer — the first moment (in microseconds) when two particles are at the same point and there will be an explosion.

Print the only integer -1, if the collision of particles doesn't happen.

Examples
input
4
RLRL
2 4 6 10
output
1
input
3
LLR
40 50 60
output
-1
Note
In the first sample case the first explosion will happen in 1 microsecond because the particles number 1 and 2 will simultaneously be at the same point with the coordinate 3.


In the second sample case there will be no explosion because there are no particles which will simultaneously be at the same point.
*/

#include<iostream>
using namespace std;

struct Particle
{
	char dir;
	int pos;
};
int main()
{
	int n, temp;
	cin >> n;
	temp = 0;
	Particle* paticles = new Particle[n];
	while (temp < n)
	{
		char c;
		cin >> c;
		paticles[temp].dir = c;
		temp++;
	}
	temp = 0;
	while (temp < n)
	{
		int pos;
		cin >> pos;
		paticles[temp].pos = pos;
		temp++;
	}
	int res = -1;
	for (int i = 0; i < n - 1; i++)
	{
		if (paticles[i].dir == 'R'&&paticles[i + 1].dir == 'L')
		{
			int time = (paticles[i + 1].pos - paticles[i].pos) / 2;
			if ((res > time) || (res == -1))
				res = time;
			i++;
		}
	}
	cout << res << endl;
	return 0;
}
