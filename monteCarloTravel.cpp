

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define runs 10000000

using namespace std;


int main()
{

	srand(time(0));

	double sum_One = 0;
	double sum_Two = 0;
	for(long long total = 0; total < runs; total++)
	{

		double option_One_Base = 3.6 / 35;
		double option_One_Time = option_One_Base;

		int temp;
		for(int index = 0; index < 8; index++)
		{
			temp = rand() % 100;
			if(temp < 50)
			{
				option_One_Time = option_One_Time + .0333;
			}
		}
		sum_One = option_One_Time + sum_One;
		option_One_Time = 0;

		double option_Two_Base = 2.9 / 25;
		double option_Two_Time = option_Two_Base;

	
		for(int second = 0; second < 7; second++)
		{
			temp = rand() % 100;
			if(temp < 35)
			{
				option_Two_Time = option_Two_Time + .05;
			}

		}
		sum_Two = option_Two_Time + sum_Two;
		option_Two_Time = 0;
	}

	double one_Average = sum_One/runs;
	double two_Average = sum_Two/runs;

	cout<<"Average time for option One in "<<runs<<": "<<one_Average<<endl;
	cout<<"Average time for option Two in "<<runs<<": "<<two_Average<<endl;
}