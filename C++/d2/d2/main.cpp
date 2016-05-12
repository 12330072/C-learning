#include <iostream>
#include <cmath>

int det(int **m, int n);

int main() {
    int n;
    int **matrix;
    std::cin >> n;
    matrix = new int*[n];
    for (int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
        }
    }
    std::cout << det(matrix, n) << std::endl;
    for (int i = 0; i < n; i++) {
        delete []matrix[i];
    }
    delete []matrix;
}

int det(int **m, int n) {
    if (n > 2) {
        int sum = 0;
        int **tM;
        int i, j, col;
        tM = new int*[n - 1];
        for (i = 0; i < n - 1; i++) {
            tM[i] = new int[n - 1];
        }
        for (col = 0; col < n; col++) {
            for (i = 0; i < n - 1; i++) {
                for (j = 0; j < col; j++) {
                    tM[i][j] = m[i + 1][j];
                }
            }
            for (i = 0; i < n - 1; i++) {
                for (j = col + 1; j < n; j++) {
                    tM[i][j - 1] = m[i + 1][j];
                }
            }
            sum += pow(-1, col) * m[0][col] * det(tM, n - 1);
        }
        for (int i = 0; i < n - 1; i++) {
            delete []tM[i];
        }
        delete []tM;
        return sum;
    }
    else if (n == 2) {
        return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
    }
    else if (n == 1) {
        return m[0][0];
    }
    else
        return 0;
}
