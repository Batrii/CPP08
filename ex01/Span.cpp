#include "Span.hpp"

Span::Span() : n(0), arr() {}

Span::Span(unsigned int n) : n(n) {
    // arr.insert(arr.end(), n, 0);
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &other) : n(other.n) {
    arr.insert(arr.end(), other.arr.begin(), other.arr.end());
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
        // delete[] arr;
        // n = other.n;
        // arr = new int[n];
        // for (unsigned int i = 0; i < n; i++) {
        //     arr[i] = other.arr[i];
        // }
        this->n = other.n;
        this->arr.assign(other.arr.begin(), other.arr.end());
    }
    return *this;
}

Span::~Span() {
    // delete[] arr;
    std::cout << "Span destructor called" << std::endl;
}

void Span::addNumber(int number) {
    if (arr.size() >= n)
        throw std::runtime_error("Span is full");
    arr.push_back(number);
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


void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if (std::distance(begin, end) + arr.size() > n)
        throw std::runtime_error("Span is full");
    arr.insert(arr.end(), begin, end);
}