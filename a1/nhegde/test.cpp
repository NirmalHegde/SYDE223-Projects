/****************************************************
You can use this file to test if your code is working
properly by designing your own test case and test code.
****************************************************/

#include <iostream>
#include "sequential-list.h"
#include "doubly-linked-list.h"
#include "polynomial.h"
using namespace std;

class SequentialListTest {
public:
    string test1() {
        SequentialList sequentialList1(5);

        bool size = sequentialList1.size() == 0;
        bool capacity = sequentialList1.capacity() == 5;
        bool empty = sequentialList1.empty();
        bool full = sequentialList1.full() == false;

        if (size && capacity && empty && full) {
            return "PASS";
        } else {
            return "FAIL";
        }
    };

    string test2() {
        SequentialList sequentialList2(5);

        bool selectNull = sequentialList2.select(5) == 0;
        sequentialList2.insert_front(5);
        bool selectHasValue = sequentialList2.select(5) == 5;
        bool searchNotPresent = sequentialList2.search(3) == 1;
        bool searchPresent = sequentialList2.search(5) == 0;

        if (selectNull && selectHasValue && searchNotPresent && searchPresent) {
            return "PASS";
        } else {
            return "FAIL";
        }
    };

    string test3() {
        SequentialList sequentialList3(5);

        sequentialList3.insert_front(1);
        sequentialList3.insert_back(5);
        sequentialList3.insert(2, 1);
        sequentialList3.insert(6, 5);
        bool size = sequentialList3.size() == 3;

        if (size) {
            return "PASS";
        } else {
            return "FAIL";
        }
    };

    string test4() {
        SequentialList sequentialList4(5);

        sequentialList4.insert_front(5);
        sequentialList4.insert_front(4);
        sequentialList4.insert_front(3);
        sequentialList4.insert_front(2);
        sequentialList4.insert_front(1);

        sequentialList4.remove_back();
        sequentialList4.remove(4);
        sequentialList4.remove_back();
        sequentialList4.remove_front();
        sequentialList4.replace(0, 25);

        bool size = sequentialList4.size() == 2;
        bool front = sequentialList4.search(25) == 0;

        if (size && front) {
            return "PASS";
        } else {
            return "FAIL";
        }
    };
};

class DoublyLinkedListTest {
public:
    string test1() {
        DoublyLinkedList doublyLinkedList1;

        bool size = doublyLinkedList1.size() == 0;
        bool capacity = doublyLinkedList1.capacity() == 65536;
        bool empty = doublyLinkedList1.empty();
        bool full = doublyLinkedList1.full() == false;

        if (size && capacity && empty && full) {
            return "PASS";
        } else {
            return "FAIL";
        }
    };

    string test2() {
        DoublyLinkedList doublyLinkedList2;

        bool selectNull = doublyLinkedList2.select(5) == 0;
        doublyLinkedList2.insert_front(5);
        bool selectHasValue = doublyLinkedList2.select(5) == 5;
        bool searchNotPresent = doublyLinkedList2.search(3) == 1;
        bool searchPresent = doublyLinkedList2.search(5) == 0;

        if (selectNull && selectHasValue && searchNotPresent && searchPresent) {
            return "PASS";
        } else {
            return "FAIL";
        }
    };

    string test3() {
        DoublyLinkedList doublyLinkedList3;

        doublyLinkedList3.insert_front(1);
        doublyLinkedList3.insert_back(5);
        doublyLinkedList3.insert(2, 1);
        doublyLinkedList3.insert(6, 5);
        bool size = doublyLinkedList3.size() == 3;

        if (size) {
            return "PASS";
        } else {
            return "FAIL";
        }
    };

    string test4() {
        DoublyLinkedList doublyLinkedList4;

        doublyLinkedList4.insert_front(5);
        doublyLinkedList4.insert_front(4);
        doublyLinkedList4.insert_front(3);
        doublyLinkedList4.insert_front(2);
        doublyLinkedList4.insert_front(1);

        doublyLinkedList4.remove(4);
        doublyLinkedList4.remove_back();
        doublyLinkedList4.remove_front();
        doublyLinkedList4.replace(0, 25);

        bool size = doublyLinkedList4.size() == 2;
        bool front = doublyLinkedList4.search(25) == 0;

        if (size && front) {
            return "PASS";
        } else {
            return "FAIL";
        }
    };
};

class PolynomialTest {
public:
    void test1() {
        int poly1[2] = {5,1};
        int poly2[2] = {2,5};

        Polynomial polynomial1(poly1, 2);
        Polynomial* polynomial2 =  new Polynomial(poly2, 2);
        Polynomial* newPoly = polynomial1.add(polynomial2);
        newPoly->print();
    };

    void test2() {
        int poly1[2] = {5,1};
        int poly2[2] = {2,5};

        Polynomial polynomial1(poly1, 2);
        Polynomial* polynomial2 =  new Polynomial(poly2, 2);
        Polynomial* newPoly = polynomial1.sub(polynomial2);
        newPoly->print();
    };

    void test3() {
        int poly1[2] = {5,1};
        int poly2[2] = {2,5};

        Polynomial polynomial1(poly1, 2);
        Polynomial* polynomial2 =  new Polynomial(poly2, 2);
        Polynomial* newPoly = polynomial1.mul(polynomial2);
        newPoly->print();
    };

    void test4() {
        int poly1[2] = {1,0};
        int poly2[2] = {1,0};

        Polynomial polynomial1(poly1, 2);
        Polynomial* polynomial2 =  new Polynomial(poly2, 2);
        Polynomial* newPoly = polynomial1.sub(polynomial2);
        newPoly->print();
    };
};

void sequentialListTest() {
    SequentialListTest sequentialListTest;
    cout << "*** Testing for Sequential List ***" << endl;
    cout << "1: Size, Capacity, Empty, Full = " << sequentialListTest.test1() << endl;
    cout << "2: Select, Search = " << sequentialListTest.test2() << endl;
    cout << "3: insert, insert_front, insert_back = " << sequentialListTest.test3() << endl;
    cout << "4: remove, remove_front, remove_back, replace = " << sequentialListTest.test4() << "\n\n" << endl;
}

void doublyLinkedListTest() {
    DoublyLinkedListTest doublyLinkedListTest;
    cout << "*** Testing for Doubly Linked List ***" << endl;
    cout << "1: Size, Capacity, Empty, Full = " << doublyLinkedListTest.test1() << endl;
    cout << "2: Select, Search = " << doublyLinkedListTest.test2() << endl;
    cout << "3: insert, insert_front, insert_back = " << doublyLinkedListTest.test3() << endl;
    cout << "4: remove, remove_front, remove_back, replace = " << doublyLinkedListTest.test4() << "\n\n" << endl;
}

void polynomialTest() {
    PolynomialTest polynoialTest;
    cout << "*** Testing for Polynomial ***" << endl;

    cout << "1. Adding 1x + 5 with 5x + 2 (expecting 6x + 7): ";
    polynoialTest.test1();
    cout << endl;

    cout << "2. Subtracting 1x + 5 with 5x + 2 (expecting -4x + 3): ";
    polynoialTest.test2();
    cout << endl;

    cout << "3. Multiplying 1x + 5 with 5x + 2 (expecting 5x^2 + 27x + 10): ";
    polynoialTest.test3();
    cout << endl;

    cout << "4. Empty output: ";
    polynoialTest.test4();
    cout << endl;
}

int main() {
    sequentialListTest();
    doublyLinkedListTest();
    polynomialTest();
}