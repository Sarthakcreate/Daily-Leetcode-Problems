class Solution {
public:
    int numSpecial(std::vector<std::vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int count = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    int rowSum = 0;
                    int colSum = 0;
                    // Check row sum
                    for (int k = 0; k < cols; ++k) {
                        rowSum += mat[i][k];
                    }
                    // Check column sum
                    for (int k = 0; k < rows; ++k) {
                        colSum += mat[k][j];
                    }
                    // If both row and column sums are 1, the element is special
                    if (rowSum == 1 && colSum == 1) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};
