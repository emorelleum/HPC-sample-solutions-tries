#include<iostream>
#include<string>
#include<fstream>

using namespace std;

void printArray(int* loc, int size)
{
	for(int x = 0; x < size; x++)
	{
		cout << loc[x] << "\t";
	}
	cout << endl;
}

void printArray(char* loc, int size)
{
	for(int x = 0; x < size; x++)
	{
		cout << loc[x] << "\t";
	}
	cout << endl;
}


int main()
{
	int freq[15][26];
	bool allowed[15][26];

	for(int x = 0; x < 15*26;x++)
	{
	//	cout << "la" << endl;
		freq[x/26][x%26] = 0;
		allowed[x/26][x%26] = true;
	}

	int totalCorrect = 0;

	string testCases[30];
	int testValues[30];
	int maxOccurance[15];

	for(int x = 0; x < 15; x++)
	{
		maxOccurance[x] = 0;
	}

	ifstream reader;
	reader.open("testSolutions.txt");

	int flicker = 0;

	while(!reader.eof())
	{
		int indexCase = flicker / 2;
		if(flicker % 2 == 0)
		{
			reader >> testCases[indexCase];
			for(int inner = 0; inner < 15; inner++)
			{
				char found = testCases[indexCase][inner];
				freq[inner][found - 'a']++;
				if(freq[inner][found - 'a'] > maxOccurance[inner])
				{
					maxOccurance[inner] = freq[inner][found - 'a'];
				}
			}
		}
		else
		{
			int tmep = 0;
			reader >> tmep;
			totalCorrect += tmep;
			testValues[indexCase] = tmep;
			if(tmep = 0)
			{
				for(int x = 0; x < 15; x++)
				{
					allowed[x][testCases[indexCase][x] - 'a'] = false;
				}
			}
		}
		//cout << flicker << endl;
		flicker++;
	}

	for(int x = 0; x < 15; x++)
	{
		cout << maxOccurance[x];
	}

	string bins[15][7];

	for(int outer = 0; outer < 15; outer++)
	{
		for(int inner = 0; inner < 7; inner++)
		{
			bins[outer][inner] = "";
		}
	}

	for(int outer = 0; outer < 15; outer++)
	{
		for(int inner = 0; inner < 26; inner++)
		{
			if(allowed[outer][inner + 'a'])
			{
				bins[outer][freq[outer][inner]] += (char)(inner + 'a');
			}
		}
	}

	for(int x = 0; x < 15; x++)
	{
		cout << x << ")\t";
		for(int inner = 0; inner < maxOccurance[x]; inner++)
		{
			cout << inner << ": " << bins[x][inner] << " ";
		}
		cout << endl;
	}

	string possibleSolutionPaths = "";

	//getPaths("",);


}

