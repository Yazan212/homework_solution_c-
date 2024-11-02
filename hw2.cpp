

#include <iostream>
#include <string>

int main()
{
    int n;
    int arr[1000];

    std::cout << "Enter the value of n: ";
    std::cin >> n;
    // C(n, i) = C(n, i-1) * (n - i + 1)/ i
    arr[0] = 1;
    std::cout << "The output is: ";
    std::cout << arr[0] << " ";
    for (int i = 1; i <= n; ++i)
    {
        arr[i] = arr[i - 1] * (n - i + 1) / i;
        std::cout << arr[i] << " ";
    }
    return 0;
}