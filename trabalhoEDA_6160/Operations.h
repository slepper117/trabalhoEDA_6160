/*****************************************************************//**
 * \file   Operations.h
 * \brief  Ficheiro com as estruturas de dados relativas às Operações
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Machines.h"

#pragma region Operação
/**
 * Estrutura de uma Operação.
 */
typedef struct Operation {
	int cod;
}Operation;

/**
 * Função para criar uma Operação.
 */
Operation* NewOperation(int codOperation);

#pragma endregion Operação

#pragma region Lista Operação
/**
 * Lista de Operações.
 */
typedef struct ListOperations {
	struct Operation op;
	struct ListMachines* lm;
	struct ListOperations* next;
}ListOperations;

/**
 * Cria um Nodo na Lista de Operações.
 */
ListOperations* NewNodeListOperations(Operation* o);

/**
 * Insere Dados numa Operação.
 */
ListOperations* InsertListOperations(ListOperations* l, Operation* o);

/**
 * Procura uma Operação na Lista.
 */
ListOperations* SearchOperation(ListOperations* i, int codOp);

/**
 * Apaga uma Operação.
 */
ListOperations* DeleteOperation(ListOperations* i, int CodOp);

/**
 * Insere Máquina numa Operação.
 */
ListOperations* InsertMachineIntoOperations(ListOperations* lo, Machine* m, int codOp);

/**
 * Mostra as Lista de Operações e as Máquinas de cada Operação.
 */
void ShowOperations(ListOperations* o);

/**
 * Mostra as Máquinas de uma operação especifica.
 */
void ShowMachinesInOperation(ListOperations* i, int codOp)

#pragma endregion Lista Operação




