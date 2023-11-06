//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {
        long long res = 1;
        // code here

        int zeroflag = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                zeroflag += 1;
                continue;
            }
            res *= nums[i];
        }

        vector<long long> ans(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0 && zeroflag == 1)
            {

                ans[i] = 0;
            }

            else if (nums[i] == 0 && zeroflag == 1)
            {
                ans[i] = res;
            }

            else if (zeroflag > 1)
            {
                ans[i] = 0;
            }

            else
            {
                ans[i] = res / nums[i];
            }
        }

        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

//{ Driver Code Starts
#include <iostream>
using namespace std;
#include <stdio.h>

int findEquilibrium(int[], int);

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << findEquilibrium(a, n) << endl;
    }
    // your code goes here
    return 0;
}
// } Driver Code Ends

/* You are required to complete this method*/
int findEquilibrium(int A[], int n)
{
    // Your code here
    int leftsum = A[0];
    int rightsum = A[n - 1];
    int left = 0;
    int right = n - 1;

    while (left < right)
    {

        if (leftsum == rightsum && left + 1 == right - 1)
        {
            break;
        }
        else if (leftsum < rightsum)
        {
            left++;
            leftsum += A[left];
        }
        else
        {
            right--;
            rightsum += A[right];
        }
    }

    if (left + 1 >= right)
    {
        return -1;
    }

    return left + 1;
}

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if there exists a triplet in the
    // array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {

        unordered_map<int, int> h;
        for (int i = 0; i < n; i++)
        {

            h[A[i]] = i;
        }

        for (int i = 0; i < n - 2; i++)
        {
            int sum = A[i];

            for (int j = i + 1; j < n - 1; j++)
            {

                if (h.count(X - sum - A[j]) && h[X - sum - A[j]] != i && h[X - sum - A[j]] != j)
                {

                    return true;
                }
            }
        }

        return false;
    }
};

//{ Driver Code Starts.

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, X;
        cin >> n >> X;
        int i, A[n];
        for (i = 0; i < n; i++)
            cin >> A[i];
        Solution ob;
        cout << ob.find3Numbers(A, n, X) << endl;
    }
}

// } Driver Code Ends