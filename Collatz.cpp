/*
#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

using namespace std;

int collatz(unsigned long long);
int collatzHelper(unsigned long long, int);

int main()
{
	clock_t startTime, endTime;
	startTime = clock();

	cout << sizeof(unsigned long long) << endl;
	
	long long answer = 0;
	int answer_Steps = 0;

# pragma omp parallel// num_threads(2)
	{

		long long greatestSteps = 0;
		long long greatestAnswer = 0;
		int id = omp_get_thread_num();
		long long start_Perm = 0;

		start_Perm = 5000000;
# pragma omp for
		for(long long steps = 0; steps < 5000000; steps++)
		{
			int tempSteps = collatz(start_Perm + steps);
			if(tempSteps > greatestSteps)
			{
				greatestSteps = tempSteps;
				greatestAnswer = start_Perm + steps;
			}
		}

#pragma omp critical
		{
			if(greatestSteps > answer_Steps)
			{
				answer_Steps = greatestSteps;
				answer = greatestAnswer;
			}
		}


	}

	cout << "longest collatz sequence: " << answer_Steps << " steps for num " << answer << endl;

	cout << "Finished!" << endl;
	//system("PAUSE");
	endTime = clock();
	cout << "Time: " << difftime(endTime, startTime) << " milliseconds" << endl;
}

int collatz(unsigned long long num)
{
	return collatzHelper(num, 0);
}

int collatzHelper(unsigned long long num, int steps)
{
	if(num == 1)
	{
		return steps;
	}
	else if(num % 2 == 0)
	{
		return collatzHelper(num/2,steps + 1);
	}
	else if(num % 2 == 1)
	{
		return collatzHelper(num* 3 + 1,steps + 1);
	}
	return -1;
}

*/

#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include<time.h>

using namespace std;

int collatz(unsigned long long);
int collatzHelper(unsigned long long, int);

int main()
{
	clock_t startTime, endTime;
	startTime = clock();

	cout << sizeof(unsigned long long) << endl;
	
	long long answer = 0;
	int answer_Steps = 0;

# pragma omp parallel num_threads(2)
	{

		long long greatestSteps = 0;
		long long greatestAnswer = 0;
		int id = omp_get_thread_num();
		long long start_Perm = 0;

		if(id == 0)
		{
			start_Perm = 5000000;
		}
		else
		{
			start_Perm = 7500000;
		}
		for(long long steps = 0; steps < 2500000; steps++)
		{
			int tempSteps = collatz(start_Perm + steps);
			if(tempSteps > greatestSteps)
			{
				greatestSteps = tempSteps;
				greatestAnswer = start_Perm + steps;
			}
		}

#pragma omp critical
		{
			if(greatestSteps > answer_Steps)
			{
				answer_Steps = greatestSteps;
				answer = greatestAnswer;
			}
		}


	}

	cout << "longest collatz sequence: " << answer_Steps << " steps for num " << answer << endl;

	cout << "Finished!" << endl;
	//system("PAUSE");
	endTime = clock();
	cout << "Time: " << difftime(endTime, startTime) << " milliseconds" << endl;
}

int collatz(unsigned long long num)
{
	return collatzHelper(num, 0);
}

int collatzHelper(unsigned long long num, int steps)
{
	if(num == 1)
	{
		return steps;
	}
	else if(num % 2 == 0)
	{
		return collatzHelper(num/2,steps + 1);
	}
	else if(num % 2 == 1)
	{
		return collatzHelper(num* 3 + 1,steps + 1);
	}
	return -1;
}