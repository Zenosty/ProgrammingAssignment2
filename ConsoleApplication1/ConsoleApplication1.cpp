/*=========================================================*
 |			                                               |
 | PROJECT ASSIGNMENT FOR LIT.                             |
 |                                                         |
 | STEPHEN HICKEY(K00231578) & MARK HESTER(K00233238)      |
 |                                                         |
 *=========================================================*/

#include "stdafx.h"

using namespace std;

/*
* Prototype functions.
*/
int GetTotalValue(void);
int GetLargestValue(void);
int GetSmallestValue(void);
int GetOccurrences(int);
void ZeroBase(void);
void ReverseDisplay(void);
void MenuSwitch(int);
void ScaleValues(int);
void DisplayCollectionToScreen(void);
double GetAverageValue(void);

// Write the output file only if required.
bool writeFile = false;

// Store the contents of the file for function use.
vector<int> collection;

// hold value from user keyboard input.
int input;

/*
 * Entry point of the application
 */
int main()
{
	// hold each line as its read.
	int line;

	//hold the user menu selection.
	int menuSelection;

	// Construct file classes.
	ifstream inputFile("Input.dat");
	ofstream outputFile("Output.dat");

	/*
	* Alter the initial code in the Project application so that the array is now filled 
	* from a file called “Input.dat”
	*/
	while (inputFile >> line)
	{
		collection.push_back(line);

		cout << "Added " << line << " to collection from file." << endl;
	}

	do
	{
		cout << "\n\n";
		cout << "====================[ Menu Section ]====================\n\n";
		cout << "   [0] => Display Collection                              \n";
		cout << "   [1] => Total Sum	                                   \n";
		cout << "   [2] => Average Sum		                           \n";
		cout << "   [3] => Largest Number				   \n";
		cout << "   [4] => Smallest Number		     	           \n";
		cout << "   [5] => Occurances of Number                            \n";
		cout << "   [6] => Collection Scale				   \n";
		cout << "   [7] => Collection Reversed			           \n";
		cout << "   [8] => Collection with Zero Base		           \n";
		cout << "   [9] => Exit						   \n";
		cout << "\n========================================================\n";

		cout << "[Input] Enter Menu selection : "; cin >> menuSelection;

		cout << endl << endl;

		// Rewrite last term’s project to now include the following functions: MENU
		MenuSwitch(menuSelection);

	} while (menuSelection < 9);

	/*
	 * Add suitable code to the Project application as in 2. so that the contents of the array 
	 * are written to a file called “Output.dat” before the application terminates
	 */
	if (writeFile == true) 
	{
		for (int i = 0; i < collection.size(); i++)
		{
			outputFile << collection[i] << endl;

			cout << "Value " << collection[i] << " has been written to file." << endl;
		}
	}

	return EXIT_SUCCESS;
}

/*
 * Menu : which will display the same options as before (ref. last term’s project spec.)
 */
void MenuSwitch(int selection)
{
	switch (selection)
	{
		/***************************************************************************
		* Display: Display the collection to the screen.
		***************************************************************************/
		case 0:

			cout << "[0] => Display the current collection to the screen." << endl << endl;

			DisplayCollectionToScreen();

			break;

		/***************************************************************************
		* Total: Calculates the total of all the values in the collection
		***************************************************************************/
		case 1:

			cout << "[1] => Returning the total of all values in collection." << endl << endl;

			cout << "Total: " << GetTotalValue() << endl;

			break;

		/***************************************************************************
		* Average: Calculates the average of all the values in the collection
		***************************************************************************/
		case 2:

			cout << "[2] => Returning the average sum of the values in collection." << endl << endl;

			cout << "Average: " << fixed << setprecision(2) << GetAverageValue() << endl;

			break;

		/***************************************************************************
		* Largest: outputs the largest value in the collection
		***********
		****************************************************************/
		case 3:

			cout << "[3] => Returning the largest number in the collection." << endl << endl;

			cout << "Greatest Value: " << GetLargestValue() << endl;

			break;

		/***************************************************************************
		* Smallest: outputs the smallest value in the collection
		***************************************************************************/
		case 4:

			cout << "[4] => Returning the smallest number in the collection." << endl << endl;

			cout << "Lowest Value: " << GetSmallestValue() << endl;

			break;


		/***************************************************************************
		* Occurrences of value: outputs the number of occurrences of a particular
		* value in the collection
		***************************************************************************/
		case 5:

			cout << "[5] => Returning occurance of value in the collection" << endl << endl;

			cout << "[Input] Enter number to count for occurences : "; cin >> input; cout << endl;

			cout << "The value " << input << " appears " << GetOccurrences(input) << " times in the collection" << endl;

			break;

		/***************************************************************************
		* Scale Up: Multiplies each value in the collection by the scale factor
		* entered
		***************************************************************************/
		case 6:

			cout << "[6] => Returning the collection scaled by number." << endl << endl;

			cout << "[Input] Enter number to scale collection against : "; cin >> input; cout << endl;

			ScaleValues(input);

			DisplayCollectionToScreen();

			break;


		/***************************************************************************
		* Reverse : which will re-arrange the contents of the collection so that
		* they are in reverse order
		***************************************************************************/
		case 7:

			cout << "[7] => Returning the collection in reverse." << endl << endl;

			ReverseDisplay();

			DisplayCollectionToScreen();

			break;

		/***************************************************************************
		* Zero Base : which will adjust all the values in the collection by the
		* same amount so that the smallest value will be zero
		***************************************************************************/
		case 8:

			cout << "[8] => Returning the collection with zero-base." << endl << endl;

			ZeroBase();

			DisplayCollectionToScreen();

			break;

		/***************************************************************************
		* Invalid : Allows user to break out of the menu and the exectution loop.
		***************************************************************************/
		default:

			cout << "[" << selection << "] => Exit option, Program will now exit !" << endl;

			break;
	}
}


/***************************************************************************
* Average: Calculates the average of all the values in the collection
* Calls a function to get the total Values.
***************************************************************************/ 
double GetAverageValue(void)
{
	return ((double) GetTotalValue() / collection.size());
}

/***************************************************************************
* Display: Display the collection to the screen.
***************************************************************************/
void DisplayCollectionToScreen(void)
{
	for (int i = 0; i < collection.size(); i++)
	{
		cout << "Collection[" << i << "] : " << collection[i] << endl;
	}
}

/***************************************************************************
* Zero Base : which will adjust all the values in the collection by the
* same amount so that the smallest value will be zero
***************************************************************************/
void ZeroBase(void)
{
	// storing the first value from array to compare.
	auto smallestNumber = GetSmallestValue();

	// iterate the array, subtract the smallest value.
	for (int i = 0; i < collection.size(); i++)
	{
		collection[i] = collection[i] - smallestNumber;
	}

	// we want to write changed values to file.
	writeFile = true;
}

/***************************************************************************
* Reverse : which will re-arrange the contents of the collection so that
* they are in reverse order
***************************************************************************/
void ReverseDisplay(void)
{
	vector<int> reversed;

	// easier referencing.
	const int size = (int)collection.size() - 1;

	// store the collection into an array in reversed order.
	for (int i = size; i >= 0; i--)
	{
		reversed.push_back(collection[i]);
	}

	// store the reversed array into the collection.
	for (int i = 0; i < reversed.size(); i++)
	{
		collection[i] = reversed[i];
	}

	// we want to write changed values to file.
	writeFile = true;
}

/***************************************************************************
* Scale Up: Multiplies each value in the collection by the scale factor
* entered
***************************************************************************/
void ScaleValues(int multiplier)
{
	for (int i = 0; i < collection.size(); i++)
	{
		collection[i] = collection[i] * multiplier;
	}

	// we want to write changed values to file.
	writeFile = true;
}

/***************************************************************************
* Total: Calculates the total of all the values in the collection
***************************************************************************/
int GetTotalValue(void)
{
	int total = 0;

	for (int i = 0; i < collection.size(); i++)
	{
		total += collection[i];
	}

	return total;
}

/***************************************************************************
* Largest: outputs the largest value in the collection
***************************************************************************/
int GetLargestValue(void)
{
	int largest = 0;

	for (int i = 0; i < collection.size(); i++)
	{
		if (collection[i] > largest)
		{
			largest = collection[i];
		}
	}

	return largest;
}

/***************************************************************************
* Smallest: outputs the smallest value in the collection
***************************************************************************/
int GetSmallestValue(void)
{
	int smallest = collection[0];

	for (int i = 0; i < collection.size(); i++)
	{
		if (collection[i] < smallest)
		{
			smallest = collection[i];
		}
	}

	return smallest;
}

/***************************************************************************
* Occurrences of value: outputs the number of occurrences of a particular
* value in the collection
***************************************************************************/
int GetOccurrences(int value)
{
	int occurences = 0;

	for (int i = 0; i < collection.size(); i++)
	{
		if (collection[i] == value)
		{
			occurences++;
		}
	}

	return occurences;
}
