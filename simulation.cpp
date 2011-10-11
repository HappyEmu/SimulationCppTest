#include <iostream>
#include <cstdlib> 
using namespace std;

const int GENERATION_COUNT = 66;
const int GENERATION_SIZE = 100000;


class Person
{
	public:
		int descendants;
		Person();
};

Person::Person()
{
	this->descendants = 0;
}

Person population[GENERATION_COUNT][GENERATION_SIZE];
int results[GENERATION_SIZE];

int main()
{
	cout << "Setting up relationships..." << endl;
	srand(time(NULL));
	for (int i = GENERATION_COUNT - 1; i > 0; i--)
	{
		for (int j = 0; j < GENERATION_SIZE; j++)
		{
			int randIdxA = (int)(((float)rand() / RAND_MAX) * GENERATION_SIZE);
			int randIdxB = (int)(((float)rand() / RAND_MAX) * GENERATION_SIZE);
			
			while(randIdxB == randIdxA)
				randIdxB = (int)(((float)rand() / RAND_MAX) * GENERATION_SIZE);
				
			//cout << randIdxA << " " << randIdxB << endl;
			
			population[i-1][randIdxA].descendants = 1 + population[i][j].descendants;
			population[i-1][randIdxB].descendants = 1 + population[i][j].descendants;
		}
	} 
	
	cout << "Evaluating..." << endl;
	for (int i = 0; i < GENERATION_SIZE; i++)
	{
		int currentDescendants = population[0][i].descendants;
		if (!(currentDescendants > GENERATION_SIZE))
			results[currentDescendants]++;
	}
	cout << "Total descendants: " << results[0] << endl;
}

