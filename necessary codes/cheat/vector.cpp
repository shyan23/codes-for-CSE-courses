#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define ll long long



typedef struct vector
{
    int size;
    int* value;
    int ind;

    vector()
    {
        size = 5;
        ind = 0;
        value = (int*)calloc(size, sizeof(int));
        if(value == NULL)
        {
            printf("Memory not allocated.\n");
            exit(0);
        }
    }

    void resize(int new_size)
    {
        value = (int*)realloc(value, new_size * sizeof(int));
        if(value == NULL)
        {
            printf("Memory not allocated.\n");
            exit(0);
        }
        size = new_size;
    }

    int getValue(int pos)
    {
        if(pos>=ind)
        {
            printf("No ind exists.\n");
            exit(0);
        }
        else
        {
            return value[pos];
        }
    }

    void addValue(int num)
    {
        if(ind == size)
        {
            size *= 2;
            resize(size);
        }
        value[ind++]=num;
    }
    
    int arraySize()
    {
        return ind;
    }

    void erase()
    {
        free(value);
    }


} vector;


int main()
{
    vector a;
    int n;
    scanf("%d", &n);
    
    for(int i=0; i<n; i++)
    {
        int p;
        scanf("%d", &p);
        a.addValue(p);
    }

    a.addValue(11);
    a.addValue(12);
    a.addValue(13);

    a.addValue(14);
    a.addValue(15);
    a.addValue(16);
    
    a.addValue(17);
    a.addValue(18);
    a.addValue(19);
    
    // a.addValue(20);
    // a.addValue(21);
    // a.addValue(22);
    
    int sz=a.arraySize();

    for(int i=0; i<sz; i++)
    {
        int p=a.getValue(i);
        printf("%d ", p);
    }

    // int p=a.getValue(20);
    // printf("%d ", p);
    
    a.erase();

    return 0;
}
