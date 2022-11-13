# michellundell/11a C/C++

## Agenda

1. Self assessment
2. C++ stacks
3. Assignment "Lotto"

## 1. Self assessment
- to big assignments
- to difficult assignments

got it.

### 2. C++ stacks
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

	Node node1 = malloc(sizeof(Node));
	node1->next = lista;
	lista = node1;
	// lista = node1,node0,NULL

	Node node2 = malloc(sizeof(Node));
	node2->next = lista;
	lista = node2;
	// lista = node2,node1,node0,NULL

	Node node3 = malloc(sizeof(Node));
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

Now its time to know std::stack !!

```
#include <iostream>
#include <stack>
using namespace std;
int main() {

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

### 3. Assignment "Lotto"

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
