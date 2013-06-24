#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

const char* FILER = "Log.txt";
const int LOGINS = 3;

void accountFor(string,vector<string>&,int);

int main()
{
	string logins[LOGINS];
	ifstream reader;

	reader.open(FILER);

	for(int index = 0; index < LOGINS; index++)
	{
		reader >> logins[index];
		cout << logins[index] << endl;
	}

	vector<string> possibleLogins;
	possibleLogins.push_back(logins[0]);

	for(int index = 1; index < LOGINS; index++)
	{
		accountFor(logins[index], possibleLogins , 0);
	}

	long long best_Index = 0;
	int bestLength = 200;

	for(long long x = 0; x < possibleLogins.size(); x++)
	{
		if(possibleLogins[x].size() < bestLength)
		{
			best_Index = x;
			bestLength = possibleLogins[x].size();
			cout << "? " << possibleLogins[x] << endl; 
		}
	}

	cout << best_Index << " Solution: " << possibleLogins[best_Index] << endl;
}

//checks whether the login code is valid for the given possible logins
//edits the options array to include additional possible valid logins
void accountFor(string code, vector<string>& options, int start)
{
	if(code.size() == 0)
	{
		return;
	}
	cout << "size: " << options.size() << endl;
	cout << "Code: " << code << endl;
	int relevantNums = options.size();
	string nextString = code.substr(1);

	for(int inner = 0; inner < relevantNums; relevantNums--)
	{
		cout << "!!!" << options[0] << endl;
	
		int position = options[inner].find_first_of(code[0], start);
		if(position == -1)//if the character does not exist after the given index
		{
			for(unsigned int x = start; x <= options[inner].size();x++)
			{
				//system("PAUSE");
				vector<string> newPossibleLogins;
				options[inner].insert(x,&code[0],1);
				//string possibleLogin = options[inner];
				cout << options[inner] << "<--!" << endl;
				newPossibleLogins.push_back(options[inner]);
				options[inner].erase(x);
				accountFor(nextString,newPossibleLogins,x);

				for(int z = 0; z < newPossibleLogins.size(); z++)
				{
					cout << "z: " << z << endl;
					options.push_back(newPossibleLogins[z]);
				}
			}
		}
		else
		{
			vector<string> newPossibleLogins;
			newPossibleLogins.push_back(options[inner]);
			accountFor(nextString,newPossibleLogins,position);
			for(int x = 0; x < newPossibleLogins.size(); x++)
			{
				options.push_back(newPossibleLogins[x]);
			}
		}
		options.erase(options.begin());
	}
}