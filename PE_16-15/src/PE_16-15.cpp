//============================================================================
// Name        	: PE_16-15.cpp
// Author      	: Mike Mordec
//
//CSC 155-001	: Lab 09 - CSC 155 - CS Dept. Oakton Community College
//
// Date	       	: 12/06/2022
//
// Description : Write a version of the binary search algorithm that can be used to search a string vector object.
// Must use the selection sort algorithm you developed in Programming Exercise 16-12 to sort the vector.
// Also, write a program to test your algorithm.
//
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int binarySearch(vector<string> list, string searchItem);
void selectionSort(vector<string>& list);

int main()
{
    vector<string> nameList;
    string name;
    int index;

    cout << "Enter first names (zzz to end the input):" << endl;

    cin >> name;

    while (name != "zzz")
    {
        nameList.push_back(name);
        cin >> name;
    }

    cout << endl;

    selectionSort(nameList);

    cout << "Enter the name to be searched: ";
    cin >> name;
    cout << endl;

    index = binarySearch(nameList, name);

    if (index != -1)
        cout << name << " is found in the list." << endl;
    else
        cout << name << " is not in the list." << endl;

    return 0;
}

int binarySearch(vector<string> list, string searchItem)
{

    /*************************/
    /* Write your code here */
    /*************************/
    int start = 0, end = list.size() - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (list[mid] == searchItem)
        {
            return mid;
        }
        else if (list[mid] > searchItem)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
} //end binarySearch

void selectionSort(vector<string>& list)
{
    int temp_ind;
    int n = list.size();
    for (int i = 0; i < n - 1; i++)
    {

        temp_ind = i;
        for (int j = i + 1; j < n; j++)
        {
            if (list[j] < list[temp_ind])
            {
                temp_ind = j;
            }
        }
        string sudo = list[temp_ind];
        list[temp_ind] = list[i];
        list[i] = sudo;
    }
}
