#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

/* Table containing all elements in atomic order, with their row numbers */
char *TABLE[118][2] = {
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
 * Prompt the user to enter a number
 * @param prompt text to display as prompt
 * @param min minimum valid value
 * @param max maximum valid value
 * @param fallback value to use if entered value is invalid
 * @return validated input
 */
int prompt_number(char *prompt, int min, int max, int fallback) {
    /* Temporary variable to store user input */
    int input;

    /* Display prompt and retrieve input */
    printf(prompt);
    scanf("%d", &input);

    /* Check the number is valid */
    if (input < min || input > max) {
        printf("...%d assumed...\n", fallback);
        input = fallback;
    }

    return input;
}

/**
 * Prompt the user to answer a binary question
 * @param prompt text to display as a prompt
 * @return validated input
 */
bool prompt_bool(char *prompt) {
    char input[100];       // used temporarily store strings inputted by the user
    bool result = true;    // actual boolean result
    const char *YES = "Y"; // constant used to determine affirmative response
    const char *NO = "N";  // constant used to determine negative response

    /* Display prompt and retrieve input */
    printf(prompt);
    scanf("%s", input);

    /* Convert input to uppercase */
    for (int i = 0; input[i]; i++) {
        input[i] = (char) toupper(input[i]);
    }

    /* Determine whether the user entered yes or no */
    if (0 == strcmp(input, YES)) {
        result = true;
    } else if (0 == strcmp(input, NO)) {
        result = false;
    } else {
        printf("...N assumed...\n");
        result = false;
    }

    return result;
}

/**
 * Main method
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    const int GROUPS = 18;       // number of groups in the periodic table
    const int PERIODS = 7;       // number of periods in the periodic table
    const int ELEMENTS = 118;    // number of elements in the periodic table

    int first_element = 1;       // element to begin printing at
    int last_element = ELEMENTS; // element to conclude printing at
    bool extra_groups = true;    // whether to print the extra Lanthanum and Actinium groups

	int element;                 // the atomic number of the element currently being printed
    char *element_symbol;        // the symbol of the element currently being printed
    int element_group;           // the group number of the element currently bring printed

	int period = 1;             // the period currently bring printed
	int group = 1;              // the group currently bring printed

    /* Print the heading */
    printf("Periodic Table Printer\n\n");

    /* Ask the user whether to print the extra groups; store the result */
    extra_groups = prompt_bool("Do you want to print the Lanthanum and Actinium groups? [Y/N] ");

    /* Prompt the user to enter the first and last elements to print */
    first_element = prompt_number("Enter number of first element to print: ", 1, ELEMENTS, 1);
    last_element = prompt_number("Enter number of last element to print: ", 1, ELEMENTS, ELEMENTS);

    /* Loop through all the elements */
	element = first_element;

	for (period = 1; period <= PERIODS && element <= last_element; period++) {
		for (group = 1; group <= GROUPS && element <= last_element; group++) {

			/* Fetch the element symbol and group number from the table, converting the group to an integer */
			element_symbol = TABLE[element - 1][0];
			element_group = atoi(TABLE[element - 1][1]);

			/* If this cell holds an element ... */
			if (group == element_group) {

				/* Only print the element if it is part of the main table */
				if (element_group > 0) {
					/* Print the element */
					printf("%03d %-3s ", element, element_symbol);
				}

				/* Move onto the next element, skipping over the Lanthanum and Actinium elements */
				if (element == 56) {
					element = 72;
				} else if (element == 88) {
					element = 104;
				} else {
					element++;
				}

			} else {
				/* Print an empty cell in the absence of an element */
				printf("%3s %3s ", "", "");
			}
		}

		printf("\n");
	}

    /* Print Lanthanum and Actinium groups */
    if (extra_groups) {
        printf("\n\n");

		/* Print Lanthanum row */
		for (element = 57; element <= 71 && element <= last_element; element++) {

			/* Print the element if it is to be included */
			if (element >= first_element && element <= last_element) {
				/* Fetch the element symbol and group number from the table, converting the group to an integer */
				element_symbol = TABLE[element - 1][0];
				element_group = atoi(TABLE[element - 1][1]);

				/* Print the element */
				printf("%03d %-3s ", element, element_symbol);
			} else {
				/* Print an empty cell in the absence of an element */
				printf("%3s %3s ", "", "");

			}
		}

		printf("\n");

		/* Print Actinium row */
		for (element = 89; element <= 103 && element <= last_element; element++) {

			/* Print the element if it is to be included */
			if (element >= first_element && element <= last_element) {
				/* Fetch the element symbol and group number from the table, converting the group to an integer */
				element_symbol = TABLE[element - 1][0];
				element_group = atoi(TABLE[element - 1][1]);

				/* Print the element */
				printf("%03d %-3s ", element, element_symbol);
			} else {
				/* Print an empty cell in the absence of an element */
				printf("%3s %3s ", "", "");

			}
		}
    }
}
