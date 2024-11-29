/* Name                    ID NO
   Letera Tujo                  0677/15
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Function prototypes
void buble(string A[], int n);
void insertionsort(string A[], int n);
void selectionSort(string A[], int n);
void sequentialSearching(string A[], int n);
void binarySearch(string A[], int n);

int main()
{
  char repeat; // To check if the user wants to repeat the program

  do
  {
    int n, option;
    string A[100];

    cout << "\n\n\t\t\t--Welcome To The Best Sorting and Searching System--\n"
         << endl;
    cout << "\t Enter the number of elements in the array: ";
    cin >> n;
    cin.ignore(); // To ignore leftover newline character

    cout << "\t Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
      getline(cin, A[i]);
    }

    do
    {
      cout << "\n \t Choose a sorting/searching method by entering the corresponding number:\n";
      cout << "\n\t\t\t\t MENU " << endl;
      cout << "\n\t\t 1: Bubble sort" << endl;
      cout << "\t\t 2: Selection sort" << endl;
      cout << "\t\t 3: Insertion sort" << endl;
      cout << "\t\t 4: Sequential search" << endl;
      cout << "\t\t 5: Binary search (data must be sorted)" << endl;
      cin >> option;

      switch (option)
      {
      case 1:
        cout << "\n\t WELCOME TO BUBBLE SORT" << endl;
        buble(A, n);
        break;
      case 2:
        cout << "\n\t WELCOME TO SELECTION SORT" << endl;
        selectionSort(A, n);
        break;
      case 3:
        cout << "\n\t WELCOME TO INSERTION SORT" << endl;
        insertionsort(A, n);
        break;
      case 4:
        cout << "\n\t WELCOME TO SEQUENTIAL SEARCH" << endl;
        sequentialSearching(A, n);
        break;
      case 5:
        cout << "\n\t WELCOME TO BINARY SEARCH" << endl;
        binarySearch(A, n);
        break;
      default:
        cout << "\n\t Invalid option!" << endl;
      }

      cout << "\n\t Do you want to search or sort the program again? (Enter S or s to close, or any other key to continue): ";
      cin >> repeat;
      cin.ignore(); // Handle newline character

    } while (repeat != 'S' && repeat != 's');

    cout << "\n\t Do you want to restart the program? (Enter Y or y to restart, or any other key to quit): ";
    cin >> repeat;
    cin.ignore(); // Handle newline character

  } while (repeat == 'y' || repeat == 'Y');

  cout << "\n\n############ Thank you! I HOPE YOU HAD A GOOD TIME WITH THE SYSTEM ###########" << endl;
  return 0;
}

// Function definitions

void buble(string A[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    for (int j = 0; j < n - i - 1; j++)
    {
      if (A[j] > A[j + 1])
      {
        swap(A[j], A[j + 1]);
      }
    }
  }
  cout << "\n\t Sorted strings:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << endl;
  }
}

void insertionsort(string A[], int n)
{
  for (int i = 1; i < n; i++)
  {
    string key = A[i];
    int j = i - 1;
    while (j >= 0 && A[j] > key)
    {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = key;
  }
  cout << "\n\t Sorted strings:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << endl;
  }
}

void selectionSort(string A[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int minIndex = i;
    for (int j = i + 1; j < n; j++)
    {
      if (A[j] < A[minIndex])
      {
        minIndex = j;
      }
    }
    if (minIndex != i)
    {
      swap(A[i], A[minIndex]);
    }
  }
  cout << "\n\t Sorted strings:" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << A[i] << endl;
  }
}

void sequentialSearching(string A[], int n)
{
  string data;
  cout << "\n\t Enter the data to search: ";
  cin.ignore();
  getline(cin, data);

  int loc = -1;
  for (int i = 0; i < n; i++)
  {
    if (A[i] == data)
    {
      loc = i;
      break;
    }
  }

  if (loc != -1)
  {
    cout << "\n\t Data found at index: " << loc << endl;
  }
  else
  {
    cout << "\n\t Data not found!" << endl;
  }
}

void binarySearch(string A[], int n)
{
  sort(A, A + n); // Ensure the array is sorted before binary search

  string data;
  cout << "\n\t Enter the data to search: ";
  cin.ignore();
  getline(cin, data);

  int lb = 0, ub = n - 1, loc = -1;
  while (lb <= ub)
  {
    int mid = (lb + ub) / 2;
    if (A[mid] == data)
    {
      loc = mid;
      break;
    }
    else if (data < A[mid])
    {
      ub = mid - 1;
    }
    else
    {
      lb = mid + 1;
    }
  }

  if (loc != -1)
  {
    cout << "\n\t Data found at index: " << loc << endl;
  }
  else
  {
    cout << "\n\t Data not found!" << endl;
  }
}
