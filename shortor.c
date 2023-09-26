
# include <stdio.h>

/*
* C program that computes various bit and math functions through the use of
* addition, subtraction, and bitwise conjugation
* Maggie McComas
*/

/*
* Purpose: returns the negation of num
* Input: int num
* Output: int neg
*/
int neg (int num){

    return (0 - num);
}

/*
* Purpose: computes and returns the product of x and y by recursively adding x
* to itself y times
* Input: int x (positive), int y (positive) and x > y
* Output: int rmult
*/
int rmult (int x, int y){

    if (x < y)
    {
        return rmult(y, x);
    }
    else if (y != 0)
    {
        return (x + rmult(x, y - 1));
    }
    else
    {
        return 0;
    }
}

/*
* Purpose: returns the square of num
* Dependent: rmult(int x, int y), neg(int num)
* Input: int num
* Output: int ret
*/
int square (int num){

    if (num < 0){
        num = neg(num);
    }

    return rmult(num, num);
}

/*
* Purpose: computes and returns the factorial value of n through recursion
* Input: int n
* Output: int rfact
*/
int rfact (int n){
    
    if (n <=1 ){
        return 1;
    }
    return rmult(n, rfact(n-1));
}

/*
* Purpose: Contains while loop that loops through array and performs desired bit and
* math computations for all ints in array and prints out their answers in hex and decimal
* much like how Y86 assembly looks
* Dependent: neg(int num), square(int n), rfact(int n), setbit(int *x, int bit)
* Input: none
* Output: none
*/
int main(void)
{
    int arr[4] = {4, -9, 13, '\0'};
    int i = 0;
    int num = arr[i];
    int num2 = 0;
    int status;

    do
    {
        printf("           %10d    0x%08x\n", num, num);
        printf("           %10d    0x%08x\n", neg(num), neg(num));
        printf("           %10d    0x%08x\n", square(num), square(num));

        if (num < 0)
        {
            num2 = neg(num);
        }
        else
        {
            num2 = num;
        }

        printf("           %10d    0x%08x\n", rfact(num2), rfact(num2));

        status = 0;

        if (num & 1)
        {
            status = status + 1;
        }

        if (num < 0)
        {
            status = status + 2;
        }

        if (square(num) > 100)
        {
            status = status + 4;
        }

        status = status + 16;

        printf("                         0x%08x\n", status);

        printf("                         0x11111111\n");
        i++;
        num = arr[i];

    } while (num != '\0');
}