
#include "stdafx.h"
#include "Functions.h"

/***************************************************************************
* Display: Display the collection to the screen.
***************************************************************************/
void displayCollectionToScreen()
{
	for (int i = 0; i < collection_size; i++)
	{
		printf("Collection[%d] : %d \n", i, collection[i]);
	}
}

/***************************************************************************
* Total: Calculates the total of all the values in the collection
* By Stephen (I also made this website! ;P)
***************************************************************************/
int TotalValue(void)
{
	temp_integer = 0;

	for (int i = 0; i < collection_size; i++)
	{
		temp_integer += collection[i];
	}

	return temp_integer;
}

/***************************************************************************
* Average: Calculates the average of all the values in the collection
***************************************************************************/
double AverageValue(void)
{
	temp_integer = 0;

	for (int i = 0; i < collection_size; i++)
	{
		temp_integer += collection[i];
	}

	return ((double)temp_integer / collection_size);
}

/***************************************************************************
* Largest: outputs the largest value in the collection
***************************************************************************/
int LargestNumber(void)
{
	temp_integer = 0;

	for (int i = 0; i < collection_size; i++)
	{
		if (collection[i] > temp_integer)
		{
			temp_integer = collection[i];
		}
	}

	return temp_integer;
}

/***************************************************************************
* Smallest: outputs the smallest value in the collection
***************************************************************************/
int SmallestNumber(void)
{
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

	return temp_integer;
}

/***************************************************************************
* Occurrences of value: outputs the number of occurrences of a particular 
* value in the collection
***************************************************************************/
int findNumberOfOccurrences(int value)
{
	// reset values.
	temp_integer = 0;

	for (int i = 0; i < collection_size; i++)
	{
		if (collection[i] == value)
		{
			temp_integer++;
		}
	}

	return temp_integer;
}

/***************************************************************************
* Scale Up: Multiplies each value in the collection by the scale factor 
* entered
***************************************************************************/
void ScaleValues(int multiplier)
{
	for (int i = 0; i < collection_size; i++)
	{
		printf("Collection[%d] : %d x %d = %d \n", i, collection[i], input_integer, collection[i] * multiplier);

		collection[i] = collection[i] * multiplier;
	}
}

/***************************************************************************
* Reverse : which will re-arrange the contents of the collection so that 
* they are in reverse order
***************************************************************************/
void ReverseDisplay(void)
{
	for (int i = 0; i < collection_size; i++)
	{
		tempCollection[i] = collection[collection_size - i - 1];
	}

	for (int i = 0; i < collection_size; i++)
	{
		collection[i] = tempCollection[i];
	}
}

/***************************************************************************
* Zero Base : which will adjust all the values in the collection by the 
* same amount so that the smallest value will be zero
***************************************************************************/
void ZeroBase(void)
{
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
	}
}

/***************************************************************************
* Display: Display the collection to the screen.
***************************************************************************/
void displayCollectionToScreen()
{
	for (int i = 0; i < collection_size; i++)
	{
		printf("Collection[%d] : %d \n", i, collection[i]);
	}
}

/***************************************************************************
* Total: Calculates the total of all the values in the collection
* By Stephen (I also made this website! ;P)
***************************************************************************/
int TotalValue(void)
{
	temp_integer = 0;

	for (int i = 0; i < collection_size; i++)
	{
		temp_integer += collection[i];
	}

	return temp_integer;
}

/***************************************************************************
* Average: Calculates the average of all the values in the collection
***************************************************************************/
double AverageValue(void)
{
	temp_integer = 0;

	for (int i = 0; i < collection_size; i++)
	{
		temp_integer += collection[i];
	}

	return ((double)temp_integer / collection_size);
}

/***************************************************************************
* Largest: outputs the largest value in the collection
***************************************************************************/
int LargestNumber(void)
{
	temp_integer = 0;

	for (int i = 0; i < collection_size; i++)
	{
		if (collection[i] > temp_integer)
		{
			temp_integer = collection[i];
		}
	}

	return temp_integer;
}

/***************************************************************************
* Smallest: outputs the smallest value in the collection
***************************************************************************/
int SmallestNumber(void)
{
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

	return temp_integer;
}

/***************************************************************************
* Occurrences of value: outputs the number of occurrences of a particular
* value in the collection
***************************************************************************/
int findNumberOfOccurrences(int value)
{
	// reset values.
	temp_integer = 0;

	for (int i = 0; i < collection_size; i++)
	{
		if (collection[i] == value)
		{
			temp_integer++;
		}
	}

	return temp_integer;
}

/***************************************************************************
* Scale Up: Multiplies each value in the collection by the scale factor
* entered
***************************************************************************/
void ScaleValues(int multiplier)
{
	for (int i = 0; i < collection_size; i++)
	{
		printf("Collection[%d] : %d x %d = %d \n", i, collection[i], input_integer, collection[i] * multiplier);

		collection[i] = collection[i] * multiplier;
	}
}

/***************************************************************************
* Reverse : which will re-arrange the contents of the collection so that
* they are in reverse order
***************************************************************************/
void ReverseDisplay(void)
{
	for (int i = 0; i < collection_size; i++)
	{
		tempCollection[i] = collection[collection_size - i - 1];
	}

	for (int i = 0; i < collection_size; i++)
	{
		collection[i] = tempCollection[i];
	}
}

/***************************************************************************
* Zero Base : which will adjust all the values in the collection by the
* same amount so that the smallest value will be zero
***************************************************************************/
void ZeroBase(void)
{
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
	}
}