#include <iostream>
#include <cstring>

using namespace std;

void sendData(char*);

int main()
{
	
	sendData("011111101111110");	//change arguments to play with the function

	return 0;
}

void sendData(char* str)
{

	const int dlSize = 9;

	char dl[dlSize] = "01111110";
	char* stuffedData = nullptr;
	char* framedData = nullptr;

	int insertions = 0,         //how many 0 insertions
		size = strlen(str),		//size of argument
		count = 0;				//count how many times 1 occurs 5 times consecutively

	//count insertions
	for (int i = 0; i < size; i++)
	{
		if (str[i] == '1')
		{
			count++;

			if (count == 5)
			{
				insertions++;
				count = 0;
			}
		}
	}

	//allocate memory for stuffedData
	size += insertions;
	stuffedData = new char[size + 1];	//+1 for null terminator
	
	int strPos = 0;
	count = 0;

	//create insertions
	for (int i = 0; i < size + 1; i++)
	{
		stuffedData[i] = str[strPos++];

		//count 1's
		if (str[i] == '1')
		{
			count++;

			//insert 0 at 5 consecutive 1's
			if (count == 5)
			{
				i++;
				stuffedData[i] = '0';
				count = 0;	//reset when inserted
			}
		}
		
		//reset if not consecutive 1
		if(stuffedData[i] == '0')
		{
			count = 0;
		}
	}


	//allocate memory for framed data
	size += dlSize * 2;
	framedData = new char[size + 1];	//+1 for null terminator

	strcpy(framedData, dl);
	strcat(framedData, stuffedData);
	strcat(framedData, dl);

	//create output

	cout << "Before stuffing: " << str << " -- " << strlen(str) << " characters" << endl;
	cout << "After stuffing: " << stuffedData << " -- " << strlen(stuffedData) << " characters" << endl;
	cout << "After framing: " << framedData << " -- " << strlen(framedData) << " characters" << endl;

	//deallocate memory
	delete[] stuffedData;
	delete[] framedData;
}