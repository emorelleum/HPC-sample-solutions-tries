

#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{

	int a;
	int b;

	for(a = 1; a < 1000; a++)
	{
		for(b = 1; b < 1000; b++)
		{
			int c = 1000 - a - b;
			if(a*a + b*b == c*c)
			{
				cout<<"A: "<<a<<" B: "<<b<<" C: "<<c<<endl;
				cout<<"A * B * C: "<<a*b*c<<endl;
			}
		}


	}



}