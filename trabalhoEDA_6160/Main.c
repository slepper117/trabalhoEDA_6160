/*****************************************************************//**
 * \file   Main.c
 * \brief  Ficheiro Main onde o programa corre
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/

#pragma warning(disable : 4996)
#include "Machines.h"
#include "Operations.h"
#include "Jobs.h"

int main() {

	ListJobs* lj = NULL;
	ListOperations* lo1 = NULL;
	ListOperations* lo2 = NULL;
	ListOperations* lo3 = NULL;
	ListOperations* lo4 = NULL;

	// Criação de um Job
	Job* j1 = NewJob(1);
	lj = InsertListJobs(lj, j1);

	// Criação das Operações
	Operation* op1 = NewOperation(1);
	lj = InsertOperationIntoJob(lj, op1, 1);
	Operation* op2 = NewOperation(2);
	lj = InsertOperationIntoJob(lj, op2, 1);
	Operation* op3 = NewOperation(3);
	lj = InsertOperationIntoJob(lj, op3, 1);
	Operation* op4 = NewOperation(4);
	lj = InsertOperationIntoJob(lj, op4, 1);

	// Criação das Máquinas
	// Operação 1
	Machine* m1 = NewMachine(1, 4);
	lo1 = InsertMachineIntoOperations(lj->lo, m1, 1);
	Machine* m2 = NewMachine(3, 5);
	lo1 = InsertMachineIntoOperations(lj->lo, m2, 1);

	// Operação 2
	Machine* m3 = NewMachine(2, 4);
	lo2 = InsertMachineIntoOperations(lj->lo, m3, 2);
	Machine* m4 = NewMachine(4, 5);
	lo2 = InsertMachineIntoOperations(lj->lo, m4, 2);

	// Operação 3
	Machine* m5 = NewMachine(3, 5);
	lo3 = InsertMachineIntoOperations(lj->lo, m5, 3);
	Machine* m6 = NewMachine(5, 6);
	lo3 = InsertMachineIntoOperations(lj->lo, m6, 3);

	// Operação 4
	Machine* m7 = NewMachine(4, 5);
	lo4 = InsertMachineIntoOperations(lj->lo, m7, 4);
	Machine* m8 = NewMachine(5, 5);
	lo4 = InsertMachineIntoOperations(lj->lo, m8, 4);
	Machine* m9 = NewMachine(6, 4);
	lo4 = InsertMachineIntoOperations(lj->lo, m9, 4);
	Machine* m10 = NewMachine(7, 5);
	lo4 = InsertMachineIntoOperations(lj->lo, m10, 4);
	Machine* m11 = NewMachine(8, 9);
	lo4 = InsertMachineIntoOperations(lj->lo, m11, 4);

	SaveJobs(lj, "teste.csv");

	return 0;
}
