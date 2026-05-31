

int add(int a, int b)
{
    int result = a + b;
    return result;
}

int multiply(int a, int b)
{
    int result = a * b;
    return result;
}

int main()
{
    int x = 10;
    int y = 20;

    int sum = add(x, y);

    int product = multiply(sum, 2);

    printf("Sum = %d\n", sum);
    printf("Product = %d\n", product);

    return 0;
}