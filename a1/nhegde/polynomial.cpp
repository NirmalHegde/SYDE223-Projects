#include "polynomial.h"
#include <iostream>
using namespace std;

Polynomial::Polynomial(int A[], int size) {
    size_ = size;
    for (int i = 0; i < size_; i++) {
        coefficients.insert_back(A[i]);
    }
}

Polynomial* Polynomial::add(Polynomial* rhs) {
    int maxSize;
    if (rhs->size_ >= size_) {
        maxSize = rhs->size_;
    } else {
        maxSize = size_;
    }

    int* results = new int(maxSize);

    for (int i = 0; i < maxSize; i++) {
        int  right = (rhs->size_ - 1 >= i) ? rhs->coefficients.select(i) : 0;
        int  left = (size_ - 1 >= i) ? coefficients.select(i) : 0;
        results[i] = left + right;
    }

    Polynomial* returnPoly = new Polynomial(results, maxSize);
    return returnPoly;
}

Polynomial* Polynomial::sub(Polynomial* rhs) {
    int maxSize;
    if (rhs->size_ >= size_) {
        maxSize = rhs->size_;
    } else {
        maxSize = size_;
    }

    int* results = new int(maxSize);

    for (int i = 0; i < maxSize; i++) {
        int  right = (rhs->size_ - 1 >= i) ? rhs->coefficients.select(i) : 0;
        int  left = (size_ - 1 >= i) ? coefficients.select(i) : 0;
        results[i] = left - right;
    }

    Polynomial* returnPoly = new Polynomial(results, maxSize);
    return returnPoly;
}

Polynomial* Polynomial::mul(Polynomial* rhs) {
    const int MUL_SIZE = size_ + rhs->size_ - 1;
    int* results = new int(MUL_SIZE);

    for (int i = 0; i < MUL_SIZE; i++) {
        results[i] = 0;
    }

    for (int i = 0; i < size_; i++) {
        for (int j = 0; j < rhs->size_; j++) {
            results[i + j] += coefficients.select(i) * rhs->coefficients.select(j);
        }
    }

    Polynomial* returnPoly = new Polynomial(results, size_ + rhs->size_ - 1);
    return returnPoly;
}

void Polynomial::print() {
    int current;
    int counter = 0;
    int output = false;

    for (int i = size_ - 1; i >= 0; i--) {
        current = coefficients.select(i);
        if (current > 0) {
            cout << current << "x^" << i;
            counter = i - 1;
            output = true;
            break;
        } else if (current < 0) {
            cout << "(" << current << ")x^" << i;
            counter = i - 1;
            output = true;
            break;
        }
    }

    for (int j = counter; j >= 0; j--) {
        current = coefficients.select(j);
        if (current > 0) {
            cout << " + " << current << "x^" << j;
            output = true;
        } else if (current < 0) {
            cout << " + " << "(" << current << ")x^" << j;
            output = true;
        }
    }

    if (!output) {
        cout << "empty";
    }
    cout << endl;
}
