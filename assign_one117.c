#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef char *string;

const string TABLE[118][2]={{"H","1"},{"He","18"},{"Li","1"},{"Be","2"},{"B","13"},{"C","14"},{"N","15"},{"O","16"},{"F","17"},{"Ne","18"},
{"Na","1"},{"Mg","2"},{"Al","13"},{"Si","14"},{"P","15"},{"S","16"},{"Cl","17"},{"Ar","18"},{"K","1"},{"Ca","2"},
{"Sc","3"},{"Ti","4"},{"V","5"},{"Cr","6"},{"Mn","7"},{"Fe","8"},{"Co","9"},{"Ni","10"},{"Cu","11"},{"Zn","12"},
{"Ga","13"},{"Ge","14"},{"As","15"},{"Se","16"},{"Br","17"},{"Kr","18"},{"Rb","1"},{"Sr","2"},{"Y","3"},{"Zr","4"},
{"Nb","5"},{"Mo","6"},{"Tc","7"},{"Ru","8"},{"Rh","9"},{"Pd","10"},{"Ag","11"},{"Cd","12"},{"In","13"},{"Sn","14"},
{"Sb","15"},{"Te","16"},{"I","17"},{"Xe","18"},{"Cs","1"},{"Ba","2"},{"La","-11"},{"Ce","-12"},{"Pr","-13"},{"Nd","-14"},
{"Pm","-15"},{"Sm","-16"},{"Eu","-17"},{"Gd","-18"},{"Tb","-19"},{"Dy","-20"},{"Ho","-21"},{"Er","-22"},{"Tm","-23"},{"Yb","-24"},
{"Lu","-25"},{"Hf","4"},{"Ta","5"},{"W","6"},{"Re","7"},{"Os","8"},{"Ir","9"},{"Pt","10"},{"Au","11"},{"Hg","12"},
{"Tl","13"},{"Pb","14"},{"Bi","15"},{"Po","16"},{"At","17"},{"Rn","18"},{"Fr","1"},{"Ra","2"},{"Ac","-31"},{"Th","-32"},
{"Pa","-33"},{"U","-34"},{"Np","-35"},{"Pu","-36"},{"Am","-37"},{"Cm","-38"},{"Bk","-39"},{"Cf","-40"},{"Es","-41"},{"Fm","-42"},
{"Md","-43"},{"No","-44"},{"Lr","-45"},{"Rf","4"},{"Db","5"},{"Sg","6"},{"Bh","7"},{"Hs","8"},{"Mt","9"},{"Ds","10"},
{"Rg","11"},{"Cn","12"},{"Uut","13"},{"Fl","14"},{"Uup","15"},{"Lv","16"},{"Uus","17"},{"Uuo","18"}};



int main(int argc, char *argv[])
{

	const int ROWS = 18;
	const int PERIODS = 7;
	const int ELEMENTS = 118;

	const string YES = "yes";
	string input; // Used to temporarily store strings inputted by the user
	int first_element;	// Starting element to be printed.
	int last_element;	//Last element to be printed.
	bool extra_groups = true;
	string element_symbol;
	int element_group;

	int current_period = 0;

	printf("PERIDOC TABLE PRINTER\n\n");

	printf("Do you want to print the Lanthanum and Actinium groups?(yes/no) ");
	scanf("%s", &input);

	if(input != YES)
	{
		printf("...N assumed...\n");
		extra_groups = false;
	}

	printf("Enter number of first element to print: ");
	scanf("%d", &first_element);

	if(first_element < 1||first_element > ELEMENTS)
	{
		printf("...1 assumed...");
		first_element = 1;
	}

	printf("Enter number of second element to print: ");
	scanf("%d", &second_element);

	if(second_element < 1||second_element > ELEMENTS)
	{
		printf("...118 assumed...");
		second_element = ELEMENTS;
	}

	
	for (int i = first_element - 1; i < (last_element - 1); i++) {
		element_symbol = TABLE[i][0];
		element_group = atoi(TABLE[i][1]);

		if (element_group == 18) {
			printf("\n");
			current_period = 0;
		}
	}
}
