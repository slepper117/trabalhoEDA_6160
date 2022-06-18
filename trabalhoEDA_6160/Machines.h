/*****************************************************************//**
 * \file   Machines.h
 * \brief  Estrutura de Dados referente �s M�quinas
 * 
 * \author renato
 * \date   April 2022
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#pragma region M�quina
/**
 * Estrutura da M�quina.
 */
typedef struct Machine {
	int cod;
	int exeTime;
}Machine;

/**
 * Fun��o para criar uma M�quina.
 */
Machine* NewMachine(int codMachine, int exeTime);
#pragma endregion M�quina

#pragma region Lista de M�quinas
/**
 * Estrutura da Lista de M�quinas.
 */
typedef struct ListMachines {
	struct Machine machine;
	struct ListMachines* next;
}ListMachines;

/**
 * Fun��o para procurar uma m�quina dentro de uma Lista de N�quinas.
 */
ListMachines* SearchMachine(ListMachines* lm, int codMachine);

/**
 * Fun��o para editar uma m�quina dentro de uma Lista de M�quinas.
 */
ListMachines* EditMachine(ListMachines* lm, int codMachine, int exeTime);

/**
 * Fun��o para criar uma Lista de M�quinas.
 */
ListMachines* NewNodeListMachines(Machine* m);

/**
 * Fun��o para inserir uma m�quina na Lista.
 */
ListMachines* InsertMachineList(ListMachines* lm, Machine* m);

/**
 * Fun��o para apagar todas as M�quinas.
 */
ListMachines* DeleteMachines(ListMachines* lm);

/**
 * Fun��o para listar as M�quinas dentro de uma lista.
 */
void ShowMachines(ListMachines* lm);

/**
 * Fun��o para determinar a m�quina com a opera��o menor.
 */
int SmMachines(ListMachines* lm);

/**
 * Fun��o para determinar a m�quina com a opera��o maior.
 */
int LgMachines(ListMachines* lm);

#pragma endregion Lista de M�quinas