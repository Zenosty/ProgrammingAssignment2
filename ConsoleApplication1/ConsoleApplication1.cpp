// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

/*
 * Entry point of the application
 */
int main()
{

	// initlize variables.
	int menu_selection, input_integer, temp_integer;

	// store the size of the collection for dynamic changes.
	const int collection_size = 3;

	// initilize a collection for an array.
	int collection[collection_size];

	// used to order a collection before assigning back.
	int tempCollection[collection_size];

	/*
	 * Take input from the user for the array collection.
	 */
	for (int i = 0; i < collection_size; i++)
	{
		printf("Enter collection value [%d/%d] :", i + 1, collection_size);  cin >> collection[i];
	}

	do
	{
		printf("\n\n");
		printf("====================[ Menu Section ]====================\n\n");
		printf("   [0] => Display Collection                              \n");
		printf("   [1] => Total Sum	                                      \n");
		printf("   [2] => Average Sum		                              \n");
		printf("   [3] => Largest Number				                  \n");
		printf("   [4] => Smallest Number		     	                  \n");
		printf("   [5] => Occurances of Number                            \n");
		printf("   [6] => Collection Scale				                  \n");
		printf("   [7] => Collection Reversed			                  \n");
		printf("   [8] => Collection with Zero Base		                  \n");
		printf("\n========================================================\n");

		cout << "[Input] Enter Menu selection : "; cin >> menu_selection;

		cout << endl << endl;

		switch (menu_selection)
		{
			/***************************************************************************
			* Display: Display the collection to the screen.
			***************************************************************************/
			case 0:
				cout << "[0] => Display the current collection to the screen." << endl << endl;

				for (int i = 0; i < collection_size; i++)
				{
					printf("Collection[%d] : %d \n", i, collection[i]);
				}
				
				break;

			/***************************************************************************
			* Total: Calculates the total of all the values in the collection
			***************************************************************************/
			case 1:
				cout << "[1] => Returning the total of all values in collection." << endl << endl;
					
				temp_integer = 0;

				for (int i = 0; i < collection_size; i++)
				{
					temp_integer += collection[i];
				}

				printf("Total: %d\n", temp_integer);

				break;

			/***************************************************************************
			* Average: Calculates the average of all the values in the collection
			***************************************************************************/
			case 2:
				cout << "[2] => Returning the average sum of the values in collection." << endl << endl;

				temp_integer = 0;

				for (int i = 0; i < collection_size; i++)
				{
					temp_integer += collection[i];
				}

				printf("Average: %.2f\n", ((double) temp_integer / collection_size));

				break;

			/***************************************************************************
			* Largest: outputs the largest value in the collection
			***************************************************************************/
			case 3:
				cout << "[3] => Returning the largest number in the collection." << endl << endl;
				
				// reset values.
				temp_integer = 0;

				for (int i = 0; i < collection_size; i++)
				{
					if (collection[i] > temp_integer)
					{
						temp_integer = collection[i];
					}
				}

				printf("Greatest Value: %d\n", temp_integer);

				break;

			/***************************************************************************
			* Smallest: outputs the smallest value in the collection
			***************************************************************************/
			case 4:
				cout << "[4] => Returning the smallest number in the collection." << endl << endl;

				// use the first value in the 
				// array as a starting point..
				temp_integer = collection[0];

				for (int i = 0; i < collection_size; i++)
				{
					if (collection[i] < temp_integer)
					{
						temp_integer = collection[i];
					}
				}

				printf("Lowest Value: %d\n", temp_integer);

				break;


			/***************************************************************************
			* Occurrences of value: outputs the number of occurrences of a particular value in the collection
			***************************************************************************/
			case 5:
				cout << "[5] => Returning occurance of value in the collection" << endl << endl;

				cout << "[Input] Enter number to count for occurences : "; cin >> input_integer; cout << endl;

				// reset values.
				temp_integer = 0;

				for (int i = 0; i < collection_size; i++)
				{
					if (collection[i] == input_integer)
					{
						temp_integer++;
					}
				}

				printf("The value %d appears %d times in the collection\n", input_integer, temp_integer);

				break;

			/***************************************************************************
			* Scale Up: Multiplies each value in the collection by the scale factor entered
			***************************************************************************/
			case 6:
				cout << "[6] => Returning the collection scaled by number." << endl << endl;

				cout << "[Input] Enter number to scale collection against : "; cin >> input_integer; cout << endl;

				for (int i = 0; i < collection_size; i++)
				{
					printf("Collection[%d] : %d x %d = %d \n", i, collection[i], input_integer, collection[i] * input_integer);

					collection[i] = collection[i] * input_integer;
				}

				break;

			/***************************************************************************
			* Reverse : which will re-arrange the contents of the collection so that they are in reverse order
			***************************************************************************/
			case 7:
				cout << "[7] => Returning the collection in reverse." << endl << endl;

				for (int i = 0; i < collection_size; i++)
				{
					tempCollection[i] = collection[collection_size - i - 1];
				}

				for (int i = 0; i < collection_size; i++)
				{
					collection[i] = tempCollection[i];

					printf("Collection[%d] : %d\n", i, collection[i]);
				}

				break;

			/***************************************************************************
			* Zero Base : which will adjust all the values in the collection by the same amount so that the smallest value will be zero
			***************************************************************************/
			case 8:
				cout << "[8] => Returning the collection with zero-base." << endl << endl;

				// storing the first value from array to compare.
				temp_integer = collection[0];

				// iterate the array, find the smallest value.
				for (int i = 0; i < collection_size; i++)
				{
					if (collection[i] < temp_integer)
					{
						temp_integer = collection[i];
					}
				}

				// iterate the array, subtract the smallest value.
				for (int i = 0; i < collection_size; i++)
				{
					collection[i] = collection[i] - temp_integer;

					printf("Collection[%d] : %d\n", i, collection[i]);
				}

				break;

			/***************************************************************************
			* Invalid : Allows user to break out of the menu and the exectution loop.
			***************************************************************************/
			default:
				printf("[%d] => Invalid option, breaking loop and execution. \n", menu_selection);
				break;
		}

	} while (menu_selection < 9);

    return 0;
}

