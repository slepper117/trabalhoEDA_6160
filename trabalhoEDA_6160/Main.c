/*****************************************************************//**
 * \file   Main.c
 * \brief  Ficheiro Main onde o programa corre
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/

#include "Machines.h"
#include "Operations.h"

int main() {

	Machine* m1 = NewMachine(3, 5);
	Machine* m2 = NewMachine(5, 6);
	ListMachines* lm = NULL;
	lm = InsertMachineList(lm, 1);
	
	Operation* op = NewOperation(1);

	return 0;
}