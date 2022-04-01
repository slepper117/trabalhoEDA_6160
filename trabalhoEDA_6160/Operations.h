/*****************************************************************//**
 * \file   Operations.h
 * \brief  Ficheiro com as estruturas de dados relativas �s Opera��es
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Machines.h"

#pragma region Opera��o
/**
 * Estrutura de uma Opera��o.
 */
typedef struct Operation {
	int cod;
}Operation;

/**
 * Fun��o para criar uma Opera��o.
 */
Operation* NewOperation(int codOperation);

#pragma endregion Opera��o

#pragma region Lista Opera��o
/**
 * Lista de Opera��es.
 */
typedef struct ListOperations {
	struct Operation op;
	struct ListMachines* lm;
	struct ListOperations* next;
}ListOperations;

/**
 * Cria um Nodo na Lista de Opera��es.
 */
ListOperations* NewNodeListOperations(Operation* o);

/**
 * Insere Dados numa Opera��o.
 */
ListOperations* InsertListOperations(ListOperations* l, Operation* o);

/**
 * Procura uma Opera��o na Lista.
 */
ListOperations* SearchOperation(ListOperations* i, int codOp);

/**
 * Apaga uma Opera��o.
 */
ListOperations* DeleteOperation(ListOperations* i, int CodOp);

/**
 * Insere M�quina numa Opera��o.
 */
ListOperations* InsertMachineIntoOperations(ListOperations* lo, Machine* m, int codOp);

/**
 * Mostra as Lista de Opera��es e as M�quinas de cada Opera��o.
 */
void ShowOperations(ListOperations* o);

/**
 * Mostra as M�quinas de uma opera��o especifica.
 */
void ShowMachinesInOperation(ListOperations* i, int codOp)

#pragma endregion Lista Opera��o




