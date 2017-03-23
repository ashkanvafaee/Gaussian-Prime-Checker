/********************************************************************
	Name:Vafaee, Ashkan				
	UT EID:av28837		
	Section:16320	
	EE312-Assignment 3 
	
********************************************************************/
Checks whether a Gaussian integer is a Gaussian prime or not.
/********************************************************************
	isGaussianPrime:

		Inputs: 	(int a) and (int b) to create z = a + bi
					int print: a flag indicating whether this function
					should print to stdout or not.

		Flow:		Take a Gaussian integer z as an argument, and 
				determine if it’s a Gaussian prime. If it is not a 
				Gaussian prime, factor it into Gaussian primes. 
				If print=1, write the result to stdout.

		Output: 	Check the lab document for output format
				
		Returns: This function should return 1 if the input is a Gaussian prime,
				and 0 otherwise.
				
		SAMPLE INPUT: -1 3
			       1 4
		SAMPLE OUTPUT:
		-1 + 3i is not a Gaussian prime. Factorization = (1+2i)(1+i)
		1 + 4i is a Gaussian prime.		
				

*********************************************************************/
#include <stdio.h>
int max, A, B, C, D;
int flag = 0;

int isGaussianPrime(int a, int b, int print) {
	flag = 0;



	if ((a == 0 && b==1) || (a==0 && b==-1) || (a==1 && b==0) || (a==-1 && b==0)){
		if (print == 1) {
			printf("%d + %di is not a Gaussian prime.\n", a, b);
		}
			return(0);
	}






	if (b == 0) {				//imaginary part 0

		flag = 1;				

		if (a < 0) {
			A = a*-1;
		}
		else {
			A = a;
		}

		if (isPrime(A)) {
			if (print == 1) {
				printf("%d + %di is a Gaussian prime.\n", a, b);
			}
			return(1);
		}
	}

	if (a == 0) {					//real part 0

		flag = 1;				

		if (b < 0) {
			B = b*-1;
		}
		else {
			B = b;
		}

		if (isPrime(B)) {
			if (print == 1) {
				printf("%d + %di is a Gaussian prime.\n", a, b);
			}
			return(1);
		}

	}

	if (isPrime((a*a) + (b*b))==1 || ((a*a)+(b*b)==2)){
		if (print == 1) {
			printf("%d + %di is a Gaussian prime.\n", a, b);
		}
		return(1);
		
	}




	max = (a*a) + (b*b);


	// Brute force method to check if input is a Gaussian prime.
	for (A=-1*max; A <= max; A++) {
		for (B=-1*max; B <= max; B++) {
			for (C=-1*max; C <= max; C++) {
				for (D=-1*max; D <= max; D++) {
					if ((a == ((A*C) - (B*D)) && b == ((A*D) + (B*C))) && ((((A==0 && (B!=1 && B!=-1)) || ((A!=1 && A!=-1) && B==0)) && (((C==0 && (D!=1 && D!=-1)) || ((C!=1 && C!=-1) && D==0)))) || (A != 0 && B != 0 && C != 0 && D != 0))) {		//&& (A!=0 && B!=0 && C!=0 && D!=0)
						if (print == 1) {
							printf("%d + %di is not a Gaussian prime. Factorization = (%d + %di)(%d + %di)\n", a, b, A, B, C, D);
						}
						return(0);
					}
				}
			}
		}

	}

	return(0);

	
}

/*********************************************************************
	PrintGaussianPrime:

		Inputs: 	(int m) where m is magnitude

		Flow:		Take a magnitude M and compute all Gaussian primes 
				a + bi such that 0 <= a <= M and 0<= b <= M. 
				Write the primes to stdout.

		Output: 	Check the lab document for output format

********************************************************************/
void PrintGaussianPrime(int m){

	printf("Primes with real and imaginary parts having magnitude less than or equal to %d = ", m);
	if (m > 0) {

		printf("{");

		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= m; j++) {
				if (isGaussianPrime(i, j, 0)) {
					printf("%d + %di, ", i, j);
				}
			}
		}
 		printf("\b\b}\n");
	}

	if (m <= 0) {
		printf("{}\n");
	}

}

/********************************************************************
	PlotGaussianPrime:

		Inputs: 	(int m) where m is magnitude

		Flow:		Take a magnitude M and draw a plot showing all the 
				Gaussian primes that are computed as in Part 2. 
				The plot should be in the form of text that you 
				print to stdout.

		Output: 	Check the lab document for output format


********************************************************************/
void PlotGaussianPrime(int m){
	printf("For M = %d;\n", m);

	if (m >= 0) {

		for (int i = m; i >= 0; i--) {				//i=a
			printf("%d ", i);
			for (int j = 0; j <= m; j++) {			//j=b
				if (isGaussianPrime(i, j, 0)) {
					printf("X");
				}
				else {
					printf("0");
				}
			}
			printf("\n");
		}

		printf("  ");

		for (int i = 0; i <= m; i++) {
			printf("%d", i);
		}

		printf("\n\n");
	}
	
	/****************************************************************
		
	isPrime:
	
		Prints the result of PlotGaussianPrime in an M x M grid
		
		SAMPLE OUTPUT:
		
		For M = 4;
		4 0X000
		3 X0X00
		2 0X0X0
		1 0XX0X
		0 000X0
		  01234
		  
		
		For z = a + bi, y-axis represents b values, and x-axis represents 
		a values.
	****************************************************************/
}



int isPrime(int n) {
	int c = 2;

	if (n < 3) {
		return(0);
	}


	for (c = 2; c <= n - 1; c++) {
		if (n%c == 0)
		{
			return(0);
		}
	}
	if (c == n && flag == 1) {
		for (int j = 3; j <= n; j = j + 4) {
			if (j == n) {
				return(1);
			}
		}
	}

	if (c == n && flag == 0) {
		return(1);
	}
		
		
		
		return(0);				//prime




	}
