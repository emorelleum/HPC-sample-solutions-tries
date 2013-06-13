#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>

using namespace std;

int main()
{
	ifstream reader;

	reader.open("CIPHER.txt");

	string encrypted = "";

	int extractor = 0;

	reader >> extractor;
	encrypted += (char)extractor;
	char dummy = ',';

	while(!reader.eof())
	{
		reader >> dummy;
		reader >> extractor;
		encrypted += (char)extractor;
	}

	cout << encrypted.size() << ": " << encrypted.c_str() << endl;

	char key[3] = {'a','a','a'};

	for(key[0] = 'a'; key[0] <= 'z'; key[0]++)
	{
		for(key[1] = 'a'; key[1] <= 'z'; key[1]++)
		{
				for(key[2] = 'a'; key[2] <= 'z'; key[2]++)
				{
					string decrypted = "";
					int flicker = 0;
					for(int index = 0; index < encrypted.size();index++)
					{
						decrypted += (char)(encrypted[index] ^ key[flicker %3]);
						flicker++;
					}
					int numSpaces = count(decrypted.begin(),decrypted.end(),' ');
					int size = encrypted.size();

					//cout << numSpaces << endl;

					if(numSpaces < size / 3 &&  numSpaces > size / 7)
					{
						cout << key[0] << key[1] << key[2] << ": " << decrypted.c_str() << endl;
					}

				}
		}

	}


}