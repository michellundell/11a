# michellundell/11a C/C++

## Agenda

1. Self assessment
2. C++ repetition linked list, std::list
3. C++ std::stack
4. C++ std::vector
5. Repetition of getopt()
6. Repetition of pointers
7. Assignment "Lotto"

## 1. Self assessment
- to big assignments
- to difficult assignments

got it.

## 2. C++ repetition linked list, std::list

You are familiar with linked lists in C ,-)
```
/* example linked list */

typedef struct node {
	/* some data */
	Node *next;
} Node;

int main(int argc, char **argv)
{
	Node *lista = NULL;
	// lista = NULL;

	Node *node0 = malloc(sizeof(Node));
	node0->next = lista;
	lista = node0;
	// lista = node0,NULL

	Node *node1 = malloc(sizeof(Node));
	node1->next = lista;
	lista = node1;
	// lista = node1,node0,NULL

	Node *node2 = malloc(sizeof(Node));
	node2->next = lista;
	lista = node2;
	// lista = node2,node1,node0,NULL

	Node *node3 = malloc(sizeof(Node));
	node3->next = lista;
	lista = node3;
	// lista = node3,node2,node1,node0,NULL

	return 0;
}
```

U are also familiar with the C++ std::list
```
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <list>
using namespace std;

class myClass {
	int x;
public:
	myClass(int x) { this->x = x; }
	int getValue() { return(x); }
};
  

/*
** std::list.sort needs a "compare" function to work with custom objects
** is a less than b? 
*/

bool compareMyClass(myClass *a, myClass *b) { return( a->getValue() < b->getValue() ); }

/*
** function for printing the elements in a list
*/

void showlist(list<myClass *> g)
{
    list<myClass *>::iterator it;

    for (it = g.begin(); it != g.end(); ++it) {
        cout << "  " << (*mcp)->getValue();
    }
    cout << '\n';
}
  
int main(int argc, char **argv)
{
    list<myClass *> alist;
  
    alist.insert( alist.begin(), new myClass(rand()%100) );
    alist.insert( alist.begin(), new myClass(rand()%100) );
    alist.insert( alist.begin(), new myClass(rand()%100) );

    showlist(alist);
  
    return 0;
}
```

## 3. C++ std::stack

Now its time to know std::stack !!

```
#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char **argv) 
{

        stack<int> st;

        cout << "push(10)" << endl;
        st.push(10);
        // stack = 10

        cout << "push(20)" << endl;
        st.push(20);
        // stack = 10,20

        cout << "push(30)" << endl;
        st.push(30);
        // stack = 10,20,30

        cout << "push(40)" << endl;
        st.push(40);
        // stack = 10,20,30,40

        cout << "top= " << st.top() << endl;

        if(!st.empty()) { st.pop(); cout << "pop() top= " << to_string(st.top()) << endl; }
        if(!st.empty()) { st.pop(); cout << "pop() top=" << to_string(st.top()) << endl; }
        if(!st.empty()) { st.pop(); cout << "pop() top=" << to_string(st.top()) << endl; }
        if(!st.empty()) { st.pop(); cout << "pop() top=" << to_string(st.top()) << endl; }

        return 0;
}
```


## 4. std::vector example

Parsing token separated strings into a std::vector

```  
#include <iostream>
#include <iterator>
#include <sstream>
#include <vector>
using namespace std;

class IntegerVector {
        std::vector<int> container;

        // parse a csv string into a vector
        vector<int> &str2vector(string str)
        {
                vector<int> *ret = new vector<int>;
                stringstream sstr( str );
                while( sstr.good() )
                {
                        string substr;
                        getline( sstr , substr, ',');
                        ret->insert(ret->end(), stoi( substr ) );
                }
                return(*ret);
        }
public:
        IntegerVector() {
                this->container = this->str2vector("");
        }
        IntegerVector(string str) {
                this->container = this->str2vector( str );
        }
        string info() {
                string ret = "";
                for (int i=0; i < container.size(); i++)
                {
                        // vector has the operator [] implemented
                         ret += "[" + to_string( container[i] ) + "]";
                }
                return ret;
        }
};

int main(int argc, char **argv)
{
        IntegerVector some_numbers_1("1,2,3,4");
        IntegerVector some_numbers_2("10,20,30,40");
        IntegerVector *some_numbers_3 = new IntegerVector("110,120,130,140");

        cout << some_numbers_1.info() << endl << endl;
        cout << some_numbers_2.info() << endl << endl;
        cout << some_numbers_3->info() << endl << endl;

   return 0;
}
```  

## 5. Repetition of getopt()

```
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/* program -v -o output-file */

int main(int argc, char *argv[]) {
   int option;
   int debug = 0;
   char filename[255];

   // Parse command line flags

   while( ( option = getopt(argc, argv, "vo:")) != -1) {
      switch(option){
         case 'v':
		debug++;
		fprintf(stdout,"debug level set to %d\n",debug);
	 break;
         case 'o':
		strncpy(filename, optarg,sizeof(filename));
		fprintf(stdout,"output file is %s\n",filename);
         break;
      }
   }
   return 0;
}
```
## 6. Repetition pointers
```
#include <stdio.h>

int main(int argc, char **argv)
{
	int a = 42;

	fprintf(stdout,"int a = 42; // deklaration av a som en integer med värdet 42\n");
	fprintf(stdout,"värdet av a är %d\n",a);
	fprintf(stdout,"a finns på stack-minnesadressen %p\n\n",&a);

	int *ap;

	fprintf(stdout,"int *ap; // en oinitierad pekare till integer\n");
	fprintf(stdout,"ap pekar på minnesadressen %p (kan vara vad som helst här) \n",ap);
	fprintf(stdout,"värdet av minnesadresssen ap pekar på är %d (*ap, kan vara vad som helst här) \n",*ap);
	fprintf(stdout,"ap variabeln finns på stack-minnesadressen %p (&ap)\n\n",&ap);

	ap = &a;
	fprintf(stdout,"ap = &a; // ap pekar på adressen till a\n");
	fprintf(stdout,"ap pekar på minnesadressen %p (ap, adressen till a) \n",ap);
	fprintf(stdout,"värdet av det som ligger i minnet ap pekar på är %d (*ap)\n",*ap);
	fprintf(stdout,"ap kommer alltid att finnas på stack-minnesadressen %p (&ap) \n",&ap);

	return 0;
}
```
# output from above ...
```
int a = 42; // deklaration av a som en integer med värdet 42
värdet av a är 42
a finns på stack-minnesadressen 0x7ff7b364d63c

int *ap; // en oinitierad pekare till integer
ap pekar på minnesadressen 0x7ff7b364d650 (kan vara vad som helst här) 
värdet av minnesadresssen ap pekar på är -1285236896 (*ap, kan vara vad som helst här) 
ap variabeln finns på stack-minnesadressen 0x7ff7b364d630 (&ap)

ap = &a; // ap pekar på adressen till a
ap pekar på minnesadressen 0x7ff7b364d63c (ap, adressen till a) 
värdet av det som ligger i minnet ap pekar på är 42 (*ap)
ap finns på stack-minnesadressen 0x7ff7b364d630 (&ap) 
```

## 7. Assignment "Lotto"

Lotto is a game. 35 numbered balls are tubmled in a sphere until 11 balls exited the sphere.

The first 7 numbers are the primary numbers, the 4 last balls are the extra numbers.

The game is to (buy) guess 7 numbers that will be drawn in the process.

For example if 5 or your numbers are among the primary numbers, you have 5 correct numbers.

For example if 5 or your numbers are among the primary numbers, and one is in the extra numbers, you have 5 correct numbers + one extra.

- 7 correct numbers. The chans is 1 in 6724520  to win.
- 6 correct numbers and 1 extra. The chans is 1 in 240161  to win.
- 6 correct numbers. The chans is 1 in 40027  to win.
- 5 correct numbers. The chans is 1 in 847  to win.
- 4 correct numbers. The chans is 1 in 59 to win.

## Assignment, create a program in C++ that corrects your coupon.
```
lotto -c correct-lotto-numbers/extra-numbers -l my-lotto-numbers

    -c means the correct lotto is provided as an argument of comma separated numbers. 
       example: -c 32,12,1,15,21,19,3/16,8,4,22

    -l my-lotto-numbers, means the users lotto provided as an argument of comma separated numbers. 
       example: -l 32,12,1,15,21,19,3
```

Example of running the program yields:

```  
$./lotto -c 1,2,3,4,5,6,7/11,12,13,14 -l 1,5,8,12,23,33,34

1,2,3,4,5,6,7/14,13,12,11 ? 1,5,8,12,23,33,34 => 2+1 correct numbers


$./lotto -c 1,2,3,4,5,6,7/11,12,13,14 -l 1,2,3,4,5,6,7

1,2,3,4,5,6,7/14,13,12,11 ? 1,2,3,4,5,6,7 => 7+0 correct numbers


$./lotto -c 1,2,3,4,5,6,7/11,12,13,14 -l 1,2,3,4,5,6,13

1,2,3,4,5,6,7/14,13,12,11 ? 1,2,3,4,5,6,13 => 6+1 correct numbers

```  


