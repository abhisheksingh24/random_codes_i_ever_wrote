#include<stdio.h>
#include<math.h>

void print(int m[10][10], int n){
    int i,j;
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void matrix(int mat[10][10], int m2[10][10], int n, int i, int j){
    int x = 0, y = 0, a, b, flag;
    for(a = 0; a<n; a++, y=0){
        flag = 0;
        for(b = 0; b<n; b++){
            if(a!=i && b!=j)
                flag = 1;
                m2[x][y++] = mat[a][b];
        }
        x+=flag;
    }
    print(m2,n-1);
}

int determinant(int mat[10][10], int n){
    if(n==1) return(mat[0][0]);
    int i, j, det, m2[10][10], sum = 0;
    for(i = 0; i<n; i++){
            matrix(mat, m2, n, 0, i);
            det = determinant(m2, n-1);
            sum = sum + (mat[0][i] * pow(-1,(0+i)) * det);
    }
    return(sum);
}

int main(){
    int m[10][10], n, i, j;
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        for(j = 0; j<n; j++){
            scanf("%d", &m[i][j]);
        }
    }
    printf("%d\n", determinant(m, n));
}

