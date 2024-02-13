#define _CRT_SECURE_NO_WARNINGS /* Disable security warnings in Microsoft Visual Studio */

#include <stdio.h> 
#include <math.h>

#define EQUILATERAL 'E'
#define SCALENE 'S'
#define ISOSCELES 'I'
#define INVALID 'N'

int getValidSide(int sideNumber);
char getTriangleType(int side1, int side2, int side3);
double getArea(int side1, int side2, int side3);

int main(void) {
	printf("Welcome User!\n\n");

	int side1, side2, side3;
	char repeat = 'Y';
	char triangleType;

	/* Main Loop */
	while (repeat == 'Y' || repeat == 'y') {
		/* Prompt the user for side lengths */
		side1 = getValidSide(1);
		side2 = getValidSide(2);
		side3 = getValidSide(3);

		/* Determine the triangle type */
		triangleType = getTriangleType(side1, side2, side3);

		/* Print the side lengths */
		printf("\nSide #1: %d\n", side1);
		printf("Side #2: %d\n", side2);
		printf("Side #3: %d\n", side3);

		/* If the three sides do not form a triangle, only print the side lengths */
		if (triangleType == 'N') {
			printf("ERROR: The side lengths do not form a valid triangle\n\n");
		}
		else {
			/* Otherwise, print the triangle type */
			printf("Triangle Type: ");
			switch (triangleType) {
			case EQUILATERAL:
				printf("Equilateral\n");
				break;
			case SCALENE:
				printf("Scalene\n");
				break;
			case ISOSCELES:
				printf("Isosceles\n");
				break;
			default:
				printf("\nERROR: Unable to determine triangle type\n\n");
			}

			/* ... and the Area, to 2 decimal places*/
			printf("Area: %.2f Square Units\n\n", getArea(side1, side2, side3));
		}

		/* Ask the user if they'd like to repeat the program */
		do {
			/* scanf("%d %d %d%*c", &side1, &side2, &side3); */
			printf("Would you like to run the program again?\nEnter 'Y' for Yes and 'N' for No: ");
			scanf(" %c", &repeat); /* The space before the c ensures any newline character is consumed before attempting to read the repeat character */

			if (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n') {
				printf("\nERROR: Invalid Selection\n\n");
			}
		} while (repeat != 'Y' && repeat != 'y' && repeat != 'N' && repeat != 'n');
		printf("\n");
	}

	printf("Terminating Program...\n");
	return 0;
}

/* Loops until the user enters a non-negative number */
int getValidSide(int sideNumber) {
	int validLength = 0;

	while (validLength <= 0) {
		printf("Enter Side #%d: ", sideNumber);
		scanf("%d", &validLength);

		if (validLength <= 0) {
			printf("\nERROR: Length Must Be Greater Than 0\n\n");
		}
	}
	return validLength;
}

/* Determines the type of triangle formed based on the three parameters passed in */
char getTriangleType(int side1, int side2, int side3) {
	char type = INVALID;
	/* First, check if the side lengths can form a valid triangle */
	if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
		/* Next, we check to see what type of triangle is formed */
		if (side1 == side2 && side2 == side3) {
			type = EQUILATERAL;
		}
		else if (side1 == side2 || side1 == side3 || side2 == side3) {
			type = ISOSCELES;
		}
		else {
			/* If it's not an Equilateral or Isosceles triangle, it must be a Scalene */
			type = SCALENE;
		}
	}
	return type;
}

/* Calculates the area of a triangle using the lengths of its three sides provided as input parameters. */
double getArea(int side1, int side2, int side3) {
	/* If this function is called using invalid side lengths, return 0 */
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		return 0;
	}

	double s = (side1 + side2 + side3) / 2.0;
	return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

/*
*	Test Cases
*
*	Case 1: User Inputs Negative Number for Side Length
*
*	```c
*	Enter Side #1: -2
*
*	ERROR: Length Must Be Greater Than 0
*	```
* 
* 
*	Case 2: User Inputs 0 for Side Length
* 
*	```c
*	Enter Side #1: 0
*
*	ERROR: Length Must Be Greater Than 0
*	```
*
* 
*	Case 3: Cannot Form Valid Triangle From User-Input Lengths
*
*	```c
*	Enter Side #1: 1
*	Enter Side #2: 2
*	Enter Side #3: 3
*
*	Side #1: 1
*	Side #2: 2
*	Side #3: 3
*	ERROR: The side lengths do not form a valid triangle
*	```
*
* 
*	Case 4: Valid Scalene
* 
*	```c
*	Enter Side #1: 3
*	Enter Side #2: 4
*	Enter Side #3: 5
*
*	Side #1: 3
*	Side #2: 4
*	Side #3: 5
*	Triangle Type: Scalene
*	Area: 6.00 Square Units
*	```
* 
* 
*	Case 5: Valid Isosceles
* 
*	```c
*	Enter Side #1: 5
*	Enter Side #2: 5
*	Enter Side #3: 7
*
*	Side #1: 5
*	Side #2: 5
*	Side #3: 7
*	Triangle Type: Isosceles
*	Area: 12.50 Square Units
*	```
* 
* 
*	Case 6: Valid Equilateral
* 
*	```c
*	Enter Side #1: 11
*	Enter Side #2: 11
*	Enter Side #3: 11
*
*	Side #1: 11
*	Side #2: 11
*	Side #3: 11
*	Triangle Type: Equilateral
*	Area: 52.39 Square Units
*	```
* 
* 
*	Case 7: Invalid User-Input for Repeating the Program
* 
*	```c
*	Would you like to run the program again?
*	Enter 'Y' for Yes and 'N' for No: a
*
*	ERROR: Invalid Selection
*
*	Would you like to run the program again?
*	Enter 'Y' for Yes and 'N' for No: Y
*	
*	Enter Side #1:
*	```
*
*
*	Case 8: Extremely Small and Large Side Lengths
* 
*	Enter Side #1: 1
*	Enter Side #2: 10000
*	Enter Side #3: 10000
*
*	Side #1: 1
*	Side #2: 10000
*	Side #3: 10000
*	Triangle Type: Isosceles
*	Area: 0.00 Square Units
*
*
*	Case 9: Repeating the Program With Different Inputs
*
*	```c
*	Enter Side #1: 3
*	Enter Side #2: 4
*	Enter Side #3: 5
*
*	Side #1: 3
*	Side #2: 4
*	Side #3: 5
*	Triangle Type: Scalene
*	Area: 6.00 Square Units
*	
*	Would you like to run the program again ?
*	Enter 'Y' for Yes and 'N' for No : Y
*
*	Enter Side #1: 2
*	Enter Side #2: 2
*	Enter Side #3: 2
*
*	Side #1: 2
*	Side #2: 2
*	Side #3: 2
*	Triangle Type: Equilateral
*	Area: 1.73 Square Units
* 
*	Would you like to run the program again ?
*	Enter 'Y' for Yes and 'N' for No:
*	```
*
*/

/*
Sample Output

Welcome User!

Enter Side #1: 1
Enter Side #2: 2
Enter Side #3: 3

Side #1: 1
Side #2: 2
Side #3: 3
ERROR: The side lengths do not form a valid triangle

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No: 2

ERROR: Invalid Selection

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No: y

Enter Side #1: 3
Enter Side #2: 4
Enter Side #3: 5

Side #1: 3
Side #2: 4
Side #3: 5
Triangle Type: Scalene
Area: 6.00 Square Units

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No: Y

Enter Side #1: 0

ERROR: Length Must Be Greater Than 0

Enter Side #1: -12

ERROR: Length Must Be Greater Than 0

Enter Side #1: 111111111
Enter Side #2: 222222222
Enter Side #3: 333333333

Side #1: 111111111
Side #2: 222222222
Side #3: 333333333
ERROR: The side lengths do not form a valid triangle

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No: y

Enter Side #1: 7
Enter Side #2: 8
Enter Side #3: 9

Side #1: 7
Side #2: 8
Side #3: 9
Triangle Type: Scalene
Area: 26.83 Square Units

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No: Y

Enter Side #1: 10
Enter Side #2: 10
Enter Side #3: 10

Side #1: 10
Side #2: 10
Side #3: 10
Triangle Type: Equilateral
Area: 43.30 Square Units

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No: 10

ERROR: Invalid Selection

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No:
ERROR: Invalid Selection

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No: Y

Enter Side #1: 10
Enter Side #2: 9
Enter Side #3: 10

Side #1: 10
Side #2: 9
Side #3: 10
Triangle Type: Isosceles
Area: 40.19 Square Units

Would you like to run the program again?
Enter 'Y' for Yes and 'N' for No: N

Terminating Program...

*/