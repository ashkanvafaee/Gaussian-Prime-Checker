/********************************************************************
Name:Vafaee, Ashkan				
UT EID:av28837		
Section:16320	
EE312-Assignment 3 

main.c 
Used to test Modes 1, 2, 3 of assignment-3.c
********************************************************************/
#include <stdio.h>

/********************************************************************
********************************************************************/
void isGaussianPrime(int a, int b, int print);
void PrintGaussianPrime(int m);
void PlotGaussianPrime(int m);

/********************************************************************
        Declarations for test functions
********************************************************************/
void TestPart1();
void TestPart2();
void TestPart3();

/********************************************************************
        Main Program
********************************************************************/
int main(void) {
        TestPart1();
        TestPart2();
        TestPart3();
	  getchar();
	  return 0;
}

/********************************************************************
        Main test function for operation mode #1 (isGaussianPrime).
********************************************************************/
void TestPart1(){
		int print = 1;
        int a;
        int b;
        printf("***** Test part #1 is started ***** \n");
        /* TEST #1: (-1 + 4i) is a Gaussian prime*/
        a = -1;
        b = 4;
        isGaussianPrime(a, b, print);
        /* TEST #2: (2 + 5i) is a Gaussian prime*/
        a = 2;
        b = 5;
        isGaussianPrime(a, b, print);
        /* TEST #3: (1 + -3i) is NOT a Gaussian prime*/
        a = 1;
        b = -3;
        isGaussianPrime(a, b, print);
        /* TEST #4: (2 + 0i) is NOT a Gaussian prime*/
        a = 0;
        b = -1;
        isGaussianPrime(a, b, print);
		/* TEST #5: (4 + 2i) is NOT a Gaussian prime*/
		a = -1;
		b = 1;
		isGaussianPrime(a, b, print);

		a = 1;
		b = 0;
		isGaussianPrime(a, b, print);

		a = -1;
		b = 0;
		isGaussianPrime(a, b, print);
        printf("***** Test part #1 is finished ***** \n\n");
}

/********************************************************************
        Main test function for operation mode #2 (PrintGaussianPrime).
********************************************************************/
void TestPart2(){
        int m;
        printf("***** Test part #2 is started ***** \n");
        /* TEST #1 */
        m = 4;
        PrintGaussianPrime(m);
        /* TEST #2 */
        m = 3;
        PrintGaussianPrime(m);
        printf("***** Test part #2 is finished ***** \n\n");
}

/********************************************************************
        Main test function for operation mode #3 (PlotGaussianPrime).
********************************************************************/
void TestPart3(){
        int m;
        printf("***** Test part #3 is started ***** \n");
        /* TEST #1 */
        m = 4;
        PlotGaussianPrime(m);
        /* TEST #2 */
        m = 3;
        PlotGaussianPrime(m);
        printf("***** Test part #3 is finished ***** \n\n");
}
