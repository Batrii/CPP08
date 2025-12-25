#include "easyfind.hpp"
#include <vector>
#include <string>

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(arr, arr + 5);
    try {
        std::vector<int>::iterator it;
        it = easyfind(vec, 3);
        std::cout << "Found: " << *it << std::endl;

        it = easyfind(vec, 20);
        std::cout << "Found: " << *it << std::endl;
    }
    catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}