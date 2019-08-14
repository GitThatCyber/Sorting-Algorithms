/********************************************
*   ArrayList class with search algorithms  *
*   Quicksort                               *
*********************************************/

#include <iostream>
#include "ArrayList.h"
#include <time.h>
#include <chrono>

using namespace std;

/*
* Program to test the ArrayList class.
*/
int main()
{
	srand((unsigned)time(0));
	int arraySize = 5;
	double sProcessTime[arraySize], bProcessTime[arraySize], seqProcessTime, sortedProcessTime;
	int x, randNum, arrayIndex = 0, temp = 0;
	bool found;

	//list creation
	ArrayList list1(arraySize);
	ArrayList list2(arraySize);
	ArrayList list3(arraySize);
	ArrayList list4(arraySize);

	for (int i = 0; i<arraySize; i++)
	{
		list1.add(rand()%2);
		list2.add(rand()%2);
	}

	for (int j = 0; j<arraySize; j++)
	{
		list3.add(list1.elementPeek(j));
		list4.add(list2.elementPeek(j));
	}

	//printing the list
	cout << "List of numbers in list1:" << endl <<"\t";
	list1.display();
	//printing the list
	cout << "List of numbers in list2:" << endl <<"\t";
	list2.display();

	//searching with sequential search
	//cout << endl << "(Sequential Search) Enter a number: ";
	//cin >> x;	

	auto startSeq = chrono::steady_clock::now();
	for(int k = arraySize - 1; k >= 0; k--)
	{
		temp = list1.sequentialSearch(list2.elementPeek(k));
		if(temp != 0)
		{
			list1.removeAt(temp - 1);
		}
		temp = 0;
	}
	auto endSeq = chrono::steady_clock::now();
	chrono::duration<double> timeElapsedS = chrono::duration_cast<chrono::duration<double> >(endSeq - startSeq);
	seqProcessTime = timeElapsedS.count();

	if(list1.isEmpty())
		cout << "(-:Both unsorted lists match:-)" << endl <<"\t";		
	else
		cout << ")-:Both unsorted lists do not match:-(" << endl << "\t";
	cout << "Unsorted Process Time: " << seqProcessTime << endl;
		

	//Sorting the list
	list3.quicksort();
	list4.quicksort();
	//printing the list
	cout << "List of numbers in list3:" << endl <<"\t";
	list3.display();
	//printing the list
	cout << "List of numbers in list4:" << endl <<"\t";
	list4.display();

	auto startSort = chrono::steady_clock::now();
	while(arrayIndex != arraySize)
	{
		if(list3.compare(arrayIndex) == list4.compare(arrayIndex))
			found = true;
		else
		{
			found = false;
			break;
		}
		arrayIndex++;	
	}
	auto endSort = chrono::steady_clock::now();
	chrono::duration<double> timeElapsedB = chrono::duration_cast<chrono::duration<double> >(endSort - startSort);
	sortedProcessTime = timeElapsedB.count();

	if(found == true)
		cout << "(-:Both sorted lists match:-)" << endl << "\t";
	else
		cout << ")-:Both sorted lists do not match:-(" << endl << "\t";
	cout << "Sorted Process Time: " << sortedProcessTime << endl;

	return 0;
}
