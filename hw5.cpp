#include <iostream>
#include <string>
#include <algorithm>

std::string addBinary(const std::string a, const std::string b)
{
    std::string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    // Loop until both strings are processed
    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry; // Start with the carry

        // Add the current bit of a
        if (i >= 0)
        {
            sum += a[i] - '0'; // Convert char to int
            i--;
        }

        // Add the current bit of b
        if (j >= 0)
        {
            sum += b[j] - '0'; // Convert char to int
            j--;
        }

        // Determine the result bit and the new carry
        result.push_back((sum % 2) + '0'); // Append the result bit
        carry = sum / 2;                   // Update carry for next iteration
    }

    // The result is in reverse order, so reverse it back
    std::reverse(result.begin(), result.end());
    return result;
}

int main()
{
    std::string binary1, binary2;

    // Input two binary numbers from the user
    std::cout << "Enter first binary number: ";
    std::cin >> binary1;
    std::cout << "Enter second binary number: ";
    std::cin >> binary2;

    // Call the addBinary function and display the result
    std::string sum = addBinary(binary1, binary2);
    std::cout << "Sum of " << binary1 << " and " << binary2 << " is: " << sum << std::endl;

    return 0;
}