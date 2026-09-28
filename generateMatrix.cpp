#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n = 8;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int value = 1;

    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;

    for (int k = 0; k <= (n - 1); k++)
    {
        for (int i = left; i <= right; i++)
        {
            matrix[top][i] = value;
            value++;
        }
        top++;
        
        for (int j = top; j <= bottom; j++)
        {
            matrix[j][right] = value;
            value++;
        }
        right--;

        for (int i = right; i >= left; i--)
        {
            matrix[bottom][i] = value;
            value++;
        }
        bottom--;

        for (int j = bottom; j >= top; j--)
        {
            matrix[j][left] = value;
            value++;
        }
        left++;

        
    }

    printf("The matrix is:\n");
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << '\n';
    }

    return 0;
}

