# Instruction 

 In this assignment, we will practice using Linear Search to solve a problem:

1. First, your program reads the titles of a collection of books from a data file and stores them in an array. 
This should be done using __a User defined function named "ReadData"__. This function should have 3 parameters:
* the input file stream,
* the array of book titles, and
* the number of books read from the file (think: should this parameter be passed by value? or by reference?)

2. Next, it sorts all the book titles into ascending order alphabetically
   
4.  Afterwards, the program goes into a query mode prompting the user to query whether a book is in the collection. If the book is in the collection, it display its location in the collection. If the book is not in the collection, inform the user about that. The query mode ends when the usr enters an empty string, i.e., simply press the "ENTER" key when prompted for book title.

*Notice*: The index of the first element in the array is 0. Yet, for the output, the value corresponding to the first book should be 1. Same goes for the location values returned in the query mode. 

Here is an example run of the program:
```
1 : A Bend in the Road
2 : A New Earth: Awakening to Your Life's Purpose
3 : A Spool of Blue Thread: A novel
4 : Cane River
5 : Drowning Ruth: A Novel
6 : I Know This Much Is True: A Novel
7 : Middlesex: A Novel
8 : Night (Night)
9 : Ruby
10 : Shantaram: A Novel
11 : She's Come Undone
12 : Take Me With You
13 : The Alchemist
14 : The Book of Awakening: Having the Life You Want by Being Present to the Life You Have
15 : The Gifts of Imperfection: Let Go of Who You Think You're Supposed to Be and Embrace Who You Are
16 : The Invention of Wings
17 : The Life We Bury
18 : The Nightingale
19 : The Pecan Man
20 : The Plum Tree
21 : The Secret Life of Bees
22 : The Untethered Soul: The Journey Beyond Yourself
23 : We Are Water: A Novel (P.S.)
24 : What I Know For Sure
25 : What She Left Behind
26 : When I Found You
27 : While I Was Gone
28 : Whistling Past the Graveyard
29 : Yellow Crocus

Enter the book title: Ruby
The book is at location 9

Enter the book title: The Plum Tree
The book is at location 20

Enter the book title: While I Was Gone
The book is at location 27

Enter the book title: Harry Potter
The book is not in the collection.

Enter the book title: The Dragon Maker
The book is not in the collection.

Enter the book title: Take Me With You
The book is at location 12

Enter the book title:

```

You may use the Linear Search code and the insertion sort code discussed in class:

```
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

void SelectionSort(string array[], int size) {
  int minIndex, minValue;
  
  // repeat pair-wise comparison across the elements n-1 times 
  for (int start = 0; start < (size – 1); start++) {
    // find the index of the element with the smallest value
    // in the remaining elements
    minIndex = start;
    minValue = array[start];

    for (int index = start + 1; index < size; index++) {
      if (arr[index] < minValue) {
        minValue = array[index];
        minIndex = index; 
      }
    }
    swap(array[minIndex], array[start]); 
  }
}
```