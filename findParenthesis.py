


def p(n):
    if n == 1 or n == 2:
        return 1
    
    total = 0
    
    for i in range(1,n):
        total += p(i) * p(n-i)
        
    return total

print(p(10))


def m(a, b):
    # Get the dimensions of the matrices
    p = len(a)        # Number of rows of matrix a
    q = len(a[0])     # Number of columns of matrix a (also the number of rows of b)
    r = len(b[0])     # Number of columns of matrix b
    
    # Initialize the result matrix c with zeros
    c = [[0] * r for _ in range(p)]
    
    # Matrix multiplication logic
    for i in range(p):        # Iterate over rows of matrix a
        for j in range(r):    # Iterate over columns of matrix b
            for k in range(q):  # Iterate over the columns of a and rows of b
                c[i][j] += a[i][k] * b[k][j]
    
    return c

# Example matrices for testing
a = [
    [1, 2],
    [3, 4]
]

b = [
    [5, 6],
    [7, 8]
]

result = m(a, b)
print(result)
