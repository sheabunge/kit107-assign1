/*
 * assign_one117.c
 *
 * Written by Nathan Haig (390023) and Shea Bunge (407095)
 * Ratio of work completed by each author is 50:50
 *
 * Completed on 2017-03-29
 *
 * Prints an excerpt of the periodic table of elements.
 * Prompts the user to enter the range of elements to print, and whether to include the Lanthanum and Actinium groups.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ELEMENTS 118 // number of elements in the periodic table

const int LAST_ELEM = ELEMENTS; // number of the last element in the table
const int FIRST_ELEM = 1;       // number of the first element in the table

/* Table containing all elements in atomic order, with their row numbers */
char *TABLE[ELEMENTS][2] = {
        { "H", "1" }, { "He", "18" }, { "Li", "1" }, { "Be", "2" }, { "B", "13" }, { "C", "14" }, { "N", "15" }, { "O", "16" }, { "F", "17" }, { "Ne", "18" },
        { "Na", "1" }, { "Mg", "2" }, { "Al", "13" }, { "Si", "14" }, { "P", "15" }, { "S", "16" }, { "Cl", "17" }, { "Ar", "18" }, { "K", "1" }, { "Ca", "2" },
        { "Sc", "3" }, { "Ti", "4" }, { "V", "5" }, { "Cr", "6" }, { "Mn", "7" }, { "Fe", "8" }, { "Co", "9" }, { "Ni", "10" }, { "Cu", "11" }, { "Zn", "12" },
        { "Ga", "13" }, { "Ge", "14" }, { "As", "15" }, { "Se", "16" }, { "Br", "17" }, { "Kr", "18" }, { "Rb", "1" }, { "Sr", "2" }, { "Y", "3" }, { "Zr", "4" },
        { "Nb", "5" }, { "Mo", "6" }, { "Tc", "7" }, { "Ru", "8" }, { "Rh", "9" }, { "Pd", "10" }, { "Ag", "11" }, { "Cd", "12" }, { "In", "13" }, { "Sn", "14" },
        { "Sb", "15" }, { "Te", "16" }, { "I", "17" }, { "Xe", "18" }, { "Cs", "1" }, { "Ba", "2" }, { "La", "-11" }, { "Ce", "-12" }, { "Pr", "-13" }, { "Nd", "-14" },
        { "Pm", "-15" }, { "Sm", "-16" }, { "Eu", "-17" }, { "Gd", "-18" }, { "Tb", "-19" }, { "Dy", "-20" }, { "Ho", "-21" }, { "Er", "-22" }, { "Tm", "-23" }, { "Yb", "-24" },
        { "Lu", "-25" }, { "Hf", "4" }, { "Ta", "5" }, { "W", "6" }, { "Re", "7" }, { "Os", "8" }, { "Ir", "9" }, { "Pt", "10" }, { "Au", "11" }, { "Hg", "12" },
        { "Tl", "13" }, { "Pb", "14" }, { "Bi", "15" }, { "Po", "16" }, { "At", "17" }, { "Rn", "18" }, { "Fr", "1" }, { "Ra", "2" }, { "Ac", "-31" }, { "Th", "-32" },
        { "Pa", "-33" }, { "U", "-34" }, { "Np", "-35" }, { "Pu", "-36" }, { "Am", "-37" }, { "Cm", "-38" }, { "Bk", "-39" }, { "Cf", "-40" }, { "Es", "-41" }, { "Fm", "-42" },
        { "Md", "-43" }, { "No", "-44" }, { "Lr", "-45" }, { "Rf", "4" }, { "Db", "5" }, { "Sg", "6" }, { "Bh", "7" }, { "Hs", "8" }, { "Mt", "9" }, { "Ds", "10" },
        { "Rg", "11" }, { "Cn", "12" }, { "Uut", "13" }, { "Fl", "14" }, { "Uup", "15" }, { "Lv", "16" }, { "Uus", "17" }, { "Uuo", "18" }
};

/**
 * Retrieve a number from the user input
 * @param min minimum valid value
 * @param max maximum valid value
 * @param fallback value to use if entered value is invalid
 * @return validated input
 */
int input_number(int min, int max, int fallback)
{
	int input; // used to store the actual input from the user

	scanf("%d", &input);

	/* Ensure that the input is within the valid range */
	if (input < min || input > max)
	{
		/* If not, use the fallback value */
		printf("...%d assumed...\n", fallback);
		input = fallback;
	}

	return input;
}

/**
 * Retrieve the user input for use in other functions.
 * @param first_element pointer to variable used to store first element
 * @param last_element pointer to variable used to store last element
 * @param extra_groups pointer to variable used to determine whether to print the extra groups, if necessary
 */
void retrieve_input(int *first_element, int *last_element, bool *extra_groups)
{
	char YES = 'Y'; // constant used to represent affirmative answer
	char NO = 'N';  // constant used to represent negative answer
	char input[10]; // used to temporarily store strings retrieved from the user

	/* Retrieve a string value from the user */
	printf("Do you want to print the Lanthanum and Actinium groups? [Y/N] ");
	scanf("%s", input);

	/* Check if the user has answered a valid value, and set the extra_groups variable */
	if (toupper(input[0]) == YES)
	{
		*extra_groups = true;
	}
	else if (toupper(input[0]) == NO)
	{
		*extra_groups = false;
	}
	else
	{
		/* If the entered value is not valid, default to 'no' */
		printf("...N assumed...\n");
		*extra_groups = false;
	}

	/* Prompt the user for the element number to begin printing from
	 * If a value is entered that is not an element number, default to the first element number */
	printf("Enter number of first element to print: ");
	*first_element = input_number(FIRST_ELEM, LAST_ELEM, FIRST_ELEM);

	/* Prompt the user the element number to conclude printing at. If the entered number is not a valid element number
	 * or is not greater than the start value, default to the last element number */
	printf("Enter number of last element to print: ");
	*last_element = input_number(*first_element, LAST_ELEM, LAST_ELEM);
}

/**
 * Prints the Lanthanum and Actinium groups of the table.
 * @param first_element the first element to print.
 * @param last_element the last element to print.
 */
void print_extra_groups(int first_element, int last_element)
{
	char *element_symbol; // the symbol of the element currently being printed
	int element_group;    // the group number of the element currently bring printed

	/* Print extra padding to align with main table */
	printf("%7s %-3s %3s ", "", "*", "");

	/* Begin by looping through all elements again */
	for (int i = first_element - 1; i < last_element; i++)
	{
		/* Retrieve the element symbol and group from the table */
		element_symbol = TABLE[i][0];
		element_group = atoi(TABLE[i][1]);

		/* Only print the Lanthanum and Actinium elements; i.e. when the group number is negative */
		if (element_group < 0)
		{
			/* Print the element atomic number and symbol */
			printf("%03d %-3s ", i + 1, element_symbol);

			//* Once the Lanthanum group is printed, begin a new line for the Actinium group */
			if (element_group == -25)
			{
				printf("\n%7s %-3s %3s ", "", "**", "");
			}
		}
	}
}

/**
 * Print a formatted periodic table of elements
 * @param first_element number of the first element to print
 * @param last_element  number of the final element to print
 * @param extra_groups  whether to print the Lanthanum and Actinium groups
 */
void print_table(int first_element, int last_element, bool extra_groups)
{
	char *element_symbol; // the symbol of the element currently being printed
	int element_group;    // the group number of the element currently bring printed
	int last_group = 0;   // the group number of the previous element
	int padding = 0;      // the amount of padding to print before the current element

	/* Loop through every element in the defined range */
	for (int element = first_element; element <= last_element; element++)
	{
		/* Retrieve the element symbol and group from the table */
		element_symbol = TABLE[element - 1][0];
		element_group = atoi(TABLE[element - 1][1]);

		/* Calculate the amount of required padding between this group and the previous group */
		padding = (element_group - last_group - 1);

		if (padding > 1)
		{
			for (int j = 0; j < padding; j++)
			{
				/* Print an empty cell of padding */
				printf("%3s %3s ", "", "");
			}
		}

		/* Only print the element if it is not from the Lanthanum or Actinium groups */
		if (element_group > 0)
		{
			/* Print the element atomic number and symbol */
			printf("%03d %-3s ", element, element_symbol);

			if (element == 56)
			{
				/* Print the placeholder for the Lanthanum group in the appropriate position */
				printf("%-3s %3s ", "*", "");
			}
			else if (element == 88)
			{
				/* Print the placeholder for the Actinium group in the appropriate position */
				printf("%-3s %3s ", "**", "");
			}

			if (element_group == 18)
			{
				/* Move to a new line when the end of a period is reached */
				printf("\n");
			}

			last_group = element_group;
		}
	}

	/* Print the Lanthanum and Actinium groups if necessary */
	if (extra_groups)
	{
		printf("\n\n");
		print_extra_groups(first_element, last_element);
	}
}

/**
 * Main function to run the program.
 * @param argc number of arguments passed to the program
 * @param argv array of arguments passed to the program
 * @return returns 0 on successful completion
 */
int main(int argc, char *argv[])
{
	int first_element = FIRST_ELEM; // element to begin printing from
	int last_element = LAST_ELEM;   // element to conclude printing at
	bool extra_groups = true;       // whether to print the Lanthanum and Actinium groups

	/* Print the program header */
	printf("Periodic Table Printer\n\n");

	/* Retrieve the setting values from the user */
	retrieve_input(&first_element, &last_element, &extra_groups);

	/* Print the periodic table using the entered settings */
	print_table(first_element, last_element, extra_groups);

	return 0;
}
