#include <bits/stdc++.h>
using namespace std;

struct matrix {
    int value[5][5];

    void input()
    {
        for(int i = 0 ; i < 5;i++)
        {
            for(int j = 0 ; j < 5 ;j++)
            {
                scanf("%d",&value[i][j]);
            }
        }
    }

    void rotate_anticlockwise() {
        for (int i = 0; i < 5; i++) {
            for (int j = i + 1; j < 5; j++) {
                swap(value[i][j], value[j][i]);
            }
        }
    }

    void rotate_clockwise() 
    {

        rotate_anticlockwise();
        for (int i = 0; i < 5; i++) 
        {
            int start = 0; int end = 4;
            while(start <= end)
            {
                int temp = value[i][start];
                value[i][start] = value[i][end];
                value[i][end] = temp;
                start++;
                end--;
            }
        }
    }

    void print_diagonal()
    {
        for(int i = 0 ; i < 5;i++)
        {
            for(int j = 0 ; j < 5 ;j++)
            {
                if(i == j) printf("%d ",value[i][j]);
            }
            
        }
        cout << "\n";
    }
    void multiply(matrix matrixB)
    {
        matrix temp;
        for(int i = 0 ; i < 5;i++)
        {
            for(int j = 0 ; j < 5;j++)
            {
                temp.value[i][j] = 0;
                for(int k = 0 ; k < 5;k++)
                {
                    temp.value[i][j] += value[i][k] * matrixB.value[k][j]; 
                }
            }
        }

        for(int i = 0 ; i < 5;i++)
        {
            for(int j = 0 ;j < 5;j++)
            {
                value[i][j] = temp.value[i][j];
            }
        }
    }
    void print_marix()
    {
        for(int i = 0 ; i < 5;i++)
        {
            for(int j = 0 ; j < 5;j++)
            {
                printf("%d ",value[i][j]);
            }
            printf("\n");
        }
        
    }
};

int main() 
{
    matrix A;
    matrix B;
    A.input();
    B.input();
    A.multiply(B);
    A.print_marix();

    
    
}
