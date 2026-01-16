#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <exception>
#include <limits>
#include <vector>

class Span {
    private:
        unsigned int n;
        // int *arr;
        std::vector<int> arr;
    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();

        void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
};









#endif