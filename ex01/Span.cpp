#include "Span.hpp"

Span::Span() : n(0), arr(NULL) {}
Span::Span(unsigned int n) : n(n) {
    arr = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &other) : n(other.n) {
    arr = new int[n];
    for (unsigned int i = 0; i < n; i++) {
        arr[i] = other.arr[i];
    }
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        delete[] arr;
        n = other.n;
        arr = new int[n];
        for (unsigned int i = 0; i < n; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

Span::~Span() {
    delete[] arr;
    std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number) {
    for (unsigned int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            arr[i] = number;
            return;
        }
    }
    throw std::runtime_error("Span is full");
}

int Span::shortestSpan(){
    unsigned int i = 0;
    unsigned int j;
    unsigned int minSpan = 0;
    while (i < n)
    {
        j = i + 1;
        while (j < n)
        {
            unsigned int span ;
            if (arr[i] > arr[j]){
                span = arr[i] - arr[j];
                if (minSpan == 0 || span < minSpan)
                    minSpan = span;
            }
            else{
                span = arr[j] - arr[i];
                if (minSpan == 0 || span < minSpan)
                    minSpan = span;
            }
            j++;
        }
        i++;
    }
    //check for exception
    if (minSpan == 0)
        throw std::runtime_error("No span found");
    return minSpan;
}

int Span::longestSpan(){
    unsigned int i = 0;
    unsigned int j;
    unsigned maxSpan = 0;
    while (i < n)
    {
        j = i + 1;
        while (j < n)
        {
            unsigned int span ;
            if (arr[i] > arr[j]){
                span = arr[i] -  arr[j];
                if (span > maxSpan)
                    maxSpan = span;
            }
            else{
                span = arr[j] - arr[i];
                if (span > maxSpan)
                    maxSpan = span;
            }
            j++;
        }
        i++;
    }
    //check for exception
    if (maxSpan == 0)
        throw std::runtime_error("No span found");
    return maxSpan;
}