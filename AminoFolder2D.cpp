#include<iostream>
#include<string.h>
#include<time.h>

using namespace std;

void copyProtien(string* dest, string* src,int siz)
{
	int dim1 = 2 * siz;
	int dim2 = 2*siz+1;
	for(int inner = 0; inner < dim1; inner++)
	{
		for(int outer = 0; outer < dim2; outer++)
		{
			//cout << "!" << endl;
			dest[inner][outer] = src[inner][outer];
		}
	}
}

int findProtiens(string* grid, int loc1, int loc2, string protien, int size, int numH)
{
	//cout << numH << endl;
	grid[loc1][loc2] = protien[0];
	if(protien[0] == 'h')
	{
		if(grid[loc1][loc2-1] == 'h')
		{
			numH++;
		}
		if(grid[loc1][loc2+1] == 'h')
		{
			numH++;
		}
		if(grid[loc1-1][loc2] == 'h')
		{
			numH++;
		}
		if(grid[loc1+1][loc2] == 'h')
		{
			numH++;
		}
	}
	if(protien.size() == 1)
	{
		return numH;
	}
	//cout << numH << endl;

	string nextString = protien.substr(1,protien.size()-1);
	//cout << numH << endl;
	string* s1 = new string[size*2];
	string* s2 = new string[size*2];
	string* s3 = new string[size*2];
	string* s4 = new string[size*2];

	//cout << numH << endl;

	for(int inner = 0; inner < size * 2; inner++)
	{
		for(int outer = 0; outer < size * 2 + 1; outer++)//plus one for end condition in folding and checking for errors (don;t want to check something off the array!
		{
			s1[inner] += " ";
			s2[inner] += " ";
			s3[inner] += " ";
			s4[inner] += " ";
		}
	}

	//cout << numH << endl;

	copyProtien(s1,grid,size);//	hhh
	copyProtien(s2,grid,size);//	hhh
	copyProtien(s3,grid,size);
	copyProtien(s4,grid,size);
	int mostConnections[4] = {0,0,0,0};

	//cout << loc1 << "," << loc2 << endl;

	if(grid[loc1][loc2-1] == ' ')
	{
		mostConnections[0] = findProtiens(s1,loc1,loc2-1,nextString,size,numH);
	}
	if(grid[loc1][loc2+1] == ' ')
	{
		mostConnections[1] = findProtiens(s2,loc1,loc2+1,nextString,size,numH);
	}
	if(grid[loc1-1][loc2] == ' ')
	{
		mostConnections[2] = findProtiens(s3,loc1-1,loc2,nextString,size,numH);
	}
	if(grid[loc1+1][loc2] == ' ')
	{
		mostConnections[3] = findProtiens(s4,loc1+1,loc2,nextString,size,numH);
	}

	delete [] s1;
	delete [] s2;
	delete [] s3;
	delete [] s4;

	int bestH = 0;

	for(int inner = 0; inner < 4; inner++)
	{
		if(mostConnections[inner] > bestH)
		{
			bestH = mostConnections[inner];
		}
	}

	//cout << bestH;

	return bestH;
}

int main()
{
	clock_t startTime, endTime;
	startTime = clock();

	cout << "Input protien" << endl;

	char Cprotien[100];

	cin >> Cprotien;

	string protien(Cprotien);

	int size = protien.size();
	string* grid = new string[size * 2];

	for(int inner = 0; inner < size * 2; inner++)
	{
		for(int outer = 0; outer < size * 2 + 1; outer++)//plus one for end condition in folding and checking for errors (don;t want to check something off the array!
		{
			grid[inner] += " ";
		}
	}

	int bestConnections = 0;

	grid[size ][size - 1] = protien[0];

	bestConnections = findProtiens(grid, size, size, protien.substr(1,protien.size() - 1), size, 0);

	cout << "Best Number of Connections: " << bestConnections << endl;

	cout << "Finished!" << endl;
	//system("PAUSE");
	endTime = clock();
	cout << "Time: " << difftime(endTime, startTime) << " milliseconds" << endl;
}