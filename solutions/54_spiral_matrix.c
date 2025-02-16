int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* result = (int*)malloc(matrixSize * matrixColSize[0] * sizeof(int));
    *returnSize = 0;

    int n_lap = (matrixSize < matrixColSize[0]) ? matrixSize : matrixColSize[0];
    n_lap = (n_lap + 1) / 2;
    
    for (int lap = 0; lap < n_lap; lap++) {
        
        for (int j = lap; j < matrixColSize[lap] - lap; j++) {
            result[(*returnSize)++] = matrix[lap][j];
        }
    
        for (int i = lap + 1; i < matrixSize - lap; i++) {
            result[(*returnSize)++] = matrix[i][matrixColSize[lap] - lap - 1];
        }
        
        if (lap + 1 < matrixSize - lap) {
            for (int j = matrixColSize[lap] - lap - 2; j >= lap; j--) {
                result[(*returnSize)++] = matrix[matrixSize - lap - 1][j];
            }
        }
        
        if (lap <= matrixColSize[lap] - lap - 2) {
            for (int i = matrixSize - lap - 2; i >= lap + 1; i--) {
                result[(*returnSize)++] = matrix[i][lap];
            }
        }
    }

    return result;
}
