#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
 * Main method
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {

    /* Number of rows in the periodic table */
    const int ROWS = 18;
    /* Number of periods in the periodic table */
    const int PERIODS = 7;
    /* Number of elements in the periodic table */
    const int ELEMENTS = 118;

    /* Constant used to determine affirmative response */
    char YES[4] = "yes";
    /* Used temporarily store strings inputted by the user */
    char input[100];
    /* Element to begin printing at */
    int first_element = 1;
    /* Element to conclude printing at */
    int last_element = ELEMENTS;
    /* Whether to print the extra Lanthanum and Actinium groups */
    bool extra_groups = true;

    /* The symbol of the element currently being printed */
    char *element_symbol;
    /* The group number of the element currently bring printed */
    int element_group;

    /* The period currently bring printed */
    int current_period = 0;
    /* The previous group that was printed */
    int last_group = 0;
    /* The amount of padding to add between the last element and the current one */
    int padding = 0;

    /* Print the heading */
    printf("Periodic table Printer\n\n");

    /* Ask the user whether to print the extra groups; store the result */
    printf("Do you want to print the Lanthanum and Actinium groups? [Y/N] ");
    scanf("%s", input);

    /* Determine whether the user entered yes or no */
    if (! strcmp(input, YES)) {
        printf("...N assumed...\n");
        extra_groups = false;
    }

    /* Ask the user for the number of the first element to print */
    printf("Enter number of first element to print: ");
    scanf("%d", &first_element);

    /* Check the number is valid */
    if (first_element < 1 || first_element > ELEMENTS) {
        printf("...1 assumed...\n");
        first_element = 1;
    }

    /* Ask the user for the number of the second element to print */
    printf("Enter number of last element to print: ");
    scanf("%d", &last_element);

    /* Check the number is valid */
    if (last_element < 1 || last_element > ELEMENTS) {
        printf("...118 assumed...\n");
        last_element = ELEMENTS;
    }

    /* Loop through all the elements */
    for (int i = first_element - 1; i < last_element; i++) {

        /* Fetch the element symbol and group number from the table, converting the group to an integer */
        element_symbol = TABLE[i][0];
        element_group = atoi(TABLE[i][1]);

        /* Calculate and print the amount of required padding */
        padding = (element_group - last_group - 1);

        if (padding > 1) {
            for (int j = 0; j < padding; j++) {
                printf("    ", j);
            }
        }

        /* Only print the element if it is part of the main table */
        if (element_group > 0) {

            /* Print the element number */
            printf("%03d ", i + 1);


            /* Print a blank space to represent the Lanthanum and Actinium if appropriate */
            if (i == 55 || i == 87) {
                printf("    ");
            }

            /* If the end of a period is reached, begin the next one */
            if (element_group == 18) {
                printf("\n");
                current_period = 0;
            }

            /* Save the current group for comparison during next iteration */
            last_group = element_group;
        }
    }

    /* Print Lanthanum and Actinium groups */
    if (extra_groups) {
        printf("\n\n");
        current_period = 0;

        /* Loop through the elements */
        for (int i = first_element - 1; i < last_element; i++) {

            /* Fetch the element symbol and group number from the table, converting the group to an integer */
            element_symbol = TABLE[i][0];
            element_group = atoi(TABLE[i][1]);

            /* Only print elements from the Lanthanum and Actinium groups */
            if (element_group < 0) {
                printf("%03d ", i + 1);

                /* If the end of a period is reached, begin the next one */
                if (element_group == -18) {
                    printf("\n");
                    current_period = 0;
                }
            }
        }
    }
}
