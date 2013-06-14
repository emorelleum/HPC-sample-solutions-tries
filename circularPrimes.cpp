

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<time.h>

using namespace std;

//sqrt((double)number)
bool checkPrime(int number)
{
	bool is_Prime = false;
	for(int index = (sqrt((double)number)); index > 1; index--)
	{
		if(number % index == 0)
		{
			is_Prime = false;
			return is_Prime;
		}
	}
	is_Prime = true;
	return is_Prime;


}

long long getNextRotation(long long num, int length)
{
	int onesDigit = num % 10;
	for(int x = 1; x < length; x++)
	{
		onesDigit *= 10;
	}

	return (num/10) + onesDigit;
	

}
int numDigits(int number)
{
	
	int answer = number;
	int digits = 0;
	while(answer != 0)
	{
		digits++;
		answer = answer/ 10;
	}
	return digits;

}

int main()
{

	clock_t startTime, endTime;
	startTime = clock();

	int digits;
	int accumulator = 0;
	bool all_Prime = true;
	long num;
	for(long index = 0; index < 1000000; index ++)
	{

		if(checkPrime(index))
		{
			all_Prime = true;
			digits = numDigits(index);
			num = index;
			for(int inner = 0; inner < digits; inner++)
			{
				num = getNextRotation(num,digits);
				if(!checkPrime(num))
				{
					all_Prime = false;
					break;
				}

			}
			if(all_Prime)
			{
				accumulator++;
				cout<<"All rotations of: "<<index<<" are Prime"<<"iteration: "<<accumulator<<endl;
				
			}

		}

	}

	endTime = clock();
	cout << "Time: " << difftime(endTime, startTime) << " milliseconds" << endl;

}