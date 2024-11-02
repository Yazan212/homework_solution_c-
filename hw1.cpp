

#include <iostream>
#include <string>

int main()
{
    int number_of_strings;
    int k;
    std::string arr[1000];
    std::cout << "Enter total number of strings to process: ";
    std::cin >> number_of_strings;
    std::cout << "Enter " << number_of_strings << " strings:";
    for (int i = 0; i < number_of_strings; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Enter k: ";
    std::cin >> k;

    bool is_unique;
    int cnt = 0;
    for (int i = 0; i < number_of_strings; ++i)
    {
        // for each string arr[i], we compare it with each other string arr[i] where i != j

        is_unique = true;
        for (int j = 0; j < number_of_strings; ++j)
        {
            if (arr[i] == arr[j] && i != j)
            {
                // not unique
                is_unique = false;
                break;
            }
        }

        if (is_unique == true)
        {
            cnt++;
            if (cnt == k)
            {
                std::cout << "The " << k << "th unique string is: " << arr[i] << "\n";
                break;
            }
        }
    }

    if (cnt < k)
    { // no kth unique string in the array
        std::cout << "\n";
    }
    return 0;
}