//This program will call a function to read a list of book titles from a data file. It will store these titles into an array, and then call a function to sort them into alphabetical order and display this. It will then let the user query a title to get the position of the title in the collection.
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

const int MAX_SIZE = 50; //max array size

// function definitions
void ReadData(ifstream& myIn, string book_titles[], int& titles_in_file);

void SelectionSort(string book_titles[], int size);

int LinearSearch(string book_titles[], int size, string toFind);


int main() {
  ifstream myIn;
  string book_titles[MAX_SIZE];
  int titles_in_file = 0; //variable for the number of book titles in the data file
  int size; //second variable equal to the size of the book_titles[] array
  string toFind = " "; //variable for user input in query mode of program
  int position1;
  assert(myIn);
  ReadData(myIn, book_titles,titles_in_file);
  

  size = titles_in_file;
  SelectionSort(book_titles, size);

  for (int i = 0; i < size; i++) {
    cout << (i+1) << " : " << book_titles[i] << endl;
  }

  //Query mode begins. prompts user for a book title, then enters while loop if the user enters a value, or exits program if they press enter without a value.
  cout << "Enter the book title: ";
  getline(cin, toFind);
  while (toFind.length() != 0) {

    //position1 stores the return value (array position) from linear search and if it is a valid position will print the position, else lets the user know it was not in the array
    position1 = LinearSearch(book_titles, size, toFind);
    if (position1 <= size && position1 != -1) {
      cout << "The book is at location: " << (position1 + 1) << endl;
    }
    else {
      cout << "The position could not be found in the collection." << endl;
    }
    
    cout << "Enter the book title: ";
    getline(cin, toFind);
  }
  
  return 0;
}

// ReadData function opens the data file and stores the book titles into the book_titles[] array. each entry increments the titles_in_file to capture the size of the array, then passes it back by reference
void ReadData(ifstream& myIn, string book_titles[], int& titles_in_file) {
  myIn.open("booktitles.dat");
  assert(myIn);
  
  while ( titles_in_file < MAX_SIZE && getline(myIn, book_titles[titles_in_file]) ) {
    titles_in_file++;
  }

  myIn.close();
}

//function to sort book_titles array
void SelectionSort(string book_titles[], int size) {
  int minIndex;
  string minValue;
  
  // repeat pair-wise comparison across the elements n-1 times 
  for (int start = 0; start < (size - 1); start++) {
    // find the index of the element with the smallest value
    // in the remaining elements
    minIndex = start;
    minValue = book_titles[start];

    for (int index = start + 1; index < size; index++) {
      if (book_titles[index] < minValue) {
        minValue = book_titles[index];
        minIndex = index; 
      }
    }
    swap(book_titles[minIndex], book_titles[start]); 
  }
}

//function to search for position of a title in the array
int LinearSearch(string names[], int size, string toFind)
{
   int position = -1;
   bool found=false;
   int index;

   index=0;
   while (!found && index < size)
   {
       if (names[index] == toFind)
       {
           found = true;
           position = index;
       }

       index++;
   }

   return position;
}