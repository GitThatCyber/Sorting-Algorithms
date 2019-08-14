/********************************************
*  Week 5 lesson:                           *
*   ArrayList class with search algorithms  *
*********************************************/

/*
 * Class implementing an array based list. Sequential search, sorted search, and
 * binary search algorithms are implemented also.
*/
class ArrayList
{
public:
	ArrayList (int);
	~ArrayList();
	bool  isEmpty();
	void  display();
	void  add(int);
	void  removeAt(int);
	void bubbleSort();
	void quicksort();
	int sequentialSearch(int);
	int sortedSearch(int);
	bool binarySearch(int);
	int elementPeek(int);
	int compare(int);
private:
	void quicksort(int, int);
	int findPivotLocation(int, int);
	int SIZE;		//size of the array that stores the list items
	int  *list;		//array to store the list items
	int  length;	//amount of elements in the list
};