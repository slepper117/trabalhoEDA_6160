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

/**
 * Estrutura da Lista de M�quinas.
 */
typedef struct ListMachines {
	struct Machine machines;
	struct ListMachines* next;
}ListMachines;

/**
 * Fun��o para Criar um nodo na Lista.
 */
ListMachines* NewNodeListMachines(Machine* m);

/**
 * Fun��o para Inserir uma M�quina na Lista.
 */
ListMachines* InsertMachineList(ListMachines* l, Machine* m);

/**
 * Fun��o para Apagar as M�quinas.
 */
ListMachines* DeleteMachines(ListMachines* l);

/**
 * Fun��o para Listar as M�quinas.
 */
void ShowMachines(ListMachines* l);




