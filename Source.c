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
	while (repeat == 'Y') {
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
			printf("Would you like to run the program again?\nEnter 'Y' for Yes and 'N' for No: ");
			scanf(" %c", &repeat); /* The space before the c ensures any newline character is consumed before attempting to read the repeat character */

			if (repeat != 'Y' && repeat != 'N') {
				printf("\nERROR: Invalid Selection\n\n");
			}
		} while (repeat != 'Y' && repeat != 'N');
		printf("\n");
	}

	printf("Terminating Program...\n");
	return 0;
}

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

/*
This function takes in three side lengths and determines the type of triangle formed
E = Equilateral, S = Scalene, I = Isosceles, and N = None (or invalid)
*/
char getTriangleType(int side1, int side2, int side3) {
	char type = INVALID;
	/* First, check if the side lengths can form a valid triangle */
	if (side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
		/* Next, we check to see what type of triangle is formed */
		if (side1 == side2 && side2 == side3) {
			type = EQUILATERAL;
		}
		else if (side1 != side2 && side1 != side3 && side2 != side3) {
			type = SCALENE;
		}
		else {
			/* If it's not an equilateral triangle, and not a scalene triangle, it must be an isosceles triangle */
			type = ISOSCELES;
		}
	}
	return type;
}

/* This function calculates the area of a triangle using the lengths of its three sides provided as input parameters. */
double getArea(int side1, int side2, int side3) {
	/* If this function is called using invalid side lengths, it simply returns 0*/
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		return 0;
	}

	double s = (side1 + side2 + side3) / 2.0;
	return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

/*
*	Test Cases
*
*	Case 1: User Inputs 0 / Negative Number for Side Length
*
*	```cpp
*	Enter Side #1: -2
*
*	ERROR: Length Must Be Greater Than 0
*	```
*
*	Case 2: Cannot Form Valid Triangle From User-Input Lengths
*
*	```cpp
*	Enter Side #1: 1
*	Enter Side #2: 2
*	Enter Side #3: 3
*
*	Side #1: 1
*	Side #2: 2
*	Side #3: 3
*	ERROR: The side lengths do not form a valid triangle
*
*	Would you like to run the program again?
*	Enter 'Y' for Yes and 'N' for No:
*	```
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*
*/