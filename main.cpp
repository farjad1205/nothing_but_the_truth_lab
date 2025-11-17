#include <iostream>
#include <vector>
using namespace std;

bool checkSorted(vector<int> vec)
{
    bool inc, dec;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        if (vec[i] > vec[i + 1])
        {
            dec = true;
        }
        else if (vec[i] < vec[i + 1])
        {
            inc = true;
        }

        if (inc && dec)
        {
            return false;
        }
    }
    return true;
}

bool targetSum(const vector<int> nums, const vector<int> indx, int target)
{
    int sum = 0;
    for (int i : indx)
    {
        try
        {
            sum += nums.at(i);
        }
        // out of bounds error continues after skipping error
        // so sum still totals but excluding error
        catch (const out_of_range e)
        {
            cout << "invalid index called" << endl;
        }
    }
    if (target == sum)
    {
        return true;
    }
    return false;
}

// helper function
bool prime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

bool checkPrimeFactorization(int number, const vector<int> &factors)
{
    if (number == 1)
    {
        return factors.empty();
    }

    if (number <= 0)
    { // Handles number < 1 case
        return false;
    }

    // Use standard 'int' for the product
    int product = 1;

    for (int factor : factors)
    {

        if (factor <= 1)
            return false;

        if (!prime(factor))
        {
            return false;
        }

        if (product > number / factor)
        {
        }

        product *= factor;
    }

    return product == number;
}

int main()
{
    cout << "1 = true, 0 = false" << endl;
    vector<int> ascend = {1, 2, 3, 4};
    vector<int> descend = {4, 3, 2, 1};
    vector<int> mix = {1, 2, 3, 6, 5, 4};

    cout << checkSorted(ascend);
    cout << checkSorted(descend);
    cout << checkSorted(mix) << endl;

    vector<int> nums1 = {10, 20, 30, 40, 50};
    vector<int> indx1 = {0, 2, 4};
    int target1 = 90;
    cout << targetSum(nums1, indx1, target1) << endl;

    vector<int> nums2 = {5, 10, 15};
    vector<int> indx2 = {0, 0, 0};
    int target2 = 15;
    cout << targetSum(nums2, indx2, target2) << endl;

    vector<int> nums3 = {1, 2, 3};
    vector<int> indx3 = {0, 1, 2, 3};
    int target3 = 6;
    cout << targetSum(nums3, indx3, target3) << endl;

    cout << checkPrimeFactorization(60, {2, 2, 3, 5}) << endl;
    cout << checkPrimeFactorization(60, {6, 10}) << endl;
    cout << checkPrimeFactorization(60, {2, 2, 3, 5, 2}) << endl;
    cout << checkPrimeFactorization(12, {1, 2, 2, 3}) << endl;
    cout << checkPrimeFactorization(7, {7}) << endl;
    cout << checkPrimeFactorization(1, {}) << endl;

    return 0;
}