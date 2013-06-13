

#include<iostream>
#include<stdio.h>
#include<random>
#include<stdlib.h>
#include<time.h>

using namespace std;


class square
{

private:

	bool has_Rock;
	bool has_Guy;
	bool has_Pedastel;

public:
	square()
	{
		has_Rock = false;
		has_Guy = false;
		has_Pedastel = false;
	}

	void addCondition(char what)
	{
		if(what == 'r')
		{
			has_Rock = true;
		}
		else if(what == 'g')
		{
			has_Guy = true;
		}
		else if(what == 'p')
		{
			has_Pedastel = true;
		}
		
	}

	void removeCondition(char what)
	{
		if(what == 'r')
		{
			has_Rock = false;
		}
		else if(what == 'g')
		{
			has_Guy = false;
		}
		else if(what == 'p')
		{
			has_Pedastel = false;
		}
	}

	bool hasRock()
	{
		if(has_Rock == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool hasGuy()
	{
		if(has_Guy == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool hasPedastel()
	{
		if(has_Pedastel == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


};

class map
{
private:

	int guy_Row;
	int guy_Column;
	int days;
	bool holding_Rock;
	square grid[3][3];
	bool completed;

public:

	map()
	{
		days = 0;
		holding_Rock = false;
		guy_Row = 1;
		guy_Column = 1;
		bool completed = false;
		for(int outer = 0; outer < 3; outer++)
		{
			for(int inner = 0; inner < 3; inner++)
			{
				if(outer == 0)
				{
					grid[outer][inner].addCondition('p');
				}
				if(outer == 1 && inner == 1)
				{
					grid[outer][inner].addCondition('g');
				}
				else if(outer == 2)
				{
					grid[outer][inner].addCondition('r');
				}
			}
		}
	}

	void move()
	{

		bool success = false;
		days++;

		while(success == false)
		{
		
			int move = rand() % 100;
			if(move < 25)
			{
				if(guy_Row + 1 < 3)
				{
					if(grid[guy_Row][guy_Column].hasRock() == true && holding_Rock == false)
					{
						grid[guy_Row][guy_Column].removeCondition('r');
						holding_Rock = true;
					}

					if(grid[guy_Row][guy_Column].hasPedastel() == true && holding_Rock == true)
					{
						holding_Rock = false;
						grid[guy_Row][guy_Column].removeCondition('p');
					}
					guy_Row++;
					success = true;

				}
			}
			else if(move < 50)
			{
				if(guy_Column - 1 > -1)
				{
					if(grid[guy_Row][guy_Column].hasRock() == true && holding_Rock == false)
					{
						grid[guy_Row][guy_Column].removeCondition('r');
						holding_Rock = true;
					}

					if(grid[guy_Row][guy_Column].hasPedastel() == true && holding_Rock == true)
					{
						holding_Rock = false;
						grid[guy_Row][guy_Column].removeCondition('p');
					}
					guy_Column--;
					success = true;

				}
			}
			else if(move < 75)
			{
				if(guy_Column + 1 < 3)
				{
					if(grid[guy_Row][guy_Column].hasRock() == true && holding_Rock == false)
					{
						grid[guy_Row][guy_Column].removeCondition('r');
						holding_Rock = true;
					}

					if(grid[guy_Row][guy_Column].hasPedastel() == true && holding_Rock == true)
					{
						holding_Rock = false;
						grid[guy_Row][guy_Column].removeCondition('p');
					}
					guy_Column++;
					success = true;

				}
			}
			else if(move < 100)
			{
				if(guy_Row - 1 > -1)
				{
					if(grid[guy_Row][guy_Column].hasRock() == true && holding_Rock == false)
					{
						grid[guy_Row][guy_Column].removeCondition('r');
						holding_Rock = true;
					}

					if(grid[guy_Row][guy_Column].hasPedastel() == true && holding_Rock == true)
					{
						holding_Rock = false;
						grid[guy_Row][guy_Column].removeCondition('p');
					}
					guy_Row--;
					success = true;

				}
			}

		}
		

	}

	bool checkWin()
	{
		bool has_Won = true;
		for(int outer = 0; outer < 3; outer++)
		{
			for(int inner = 0; inner < 3; inner++)
			{
				if(grid[outer][inner].hasPedastel() == true)
				{
					has_Won = false;
				}
			}
		}

		return has_Won;
	}

	int getDays()
	{
		return days;
	}



};


int main()
{
	srand(time(0));
	int sum = 0;

	for(int index = 0; index < 10000; index++)
	{
		map drunky;
		while(drunky.checkWin() == false)
		{
			drunky.move();
		}

		sum = sum + drunky.getDays();
	}

	double average = (double)sum / 10000;

	cout<<average<<endl;

}