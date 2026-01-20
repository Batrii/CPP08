#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span() : n(0), arr() {}

Span::Span(unsigned int n) : n(n) {
    std::cout << "Span constructor called" << std::endl;
}

Span::Span(const Span &other) : n(other.n) {
    arr.insert(arr.end(), other.arr.begin(), other.arr.end());
}

Span &Span::operator=(const Span &other) {
    if (this != &other) {
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
    std::size_t i = 0;
    int minSpan = INT_MAX;
    if (arr.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int> sortedarr = arr;
    std::sort(sortedarr.begin(), sortedarr.end());
    while (i < sortedarr.size() - 1)
    {
        int span = sortedarr[i + 1] - sortedarr[i];
        if (minSpan == INT_MAX || span < minSpan){
            minSpan = span;
        }
        i++;
    }
    return minSpan;
}

int Span::longestSpan(){

    if (arr.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");
    std::vector<int> sortedarr = arr;
    std::sort(sortedarr.begin(), sortedarr.end());
    return sortedarr[sortedarr.size() - 1] - sortedarr[0];
}


void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end){
    if (std::distance(begin, end) + arr.size() > n)
        throw std::runtime_error("Span is full");
    arr.insert(arr.end(), begin, end);
}