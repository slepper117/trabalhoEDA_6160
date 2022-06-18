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
#include <stdbool.h>
#include "Machines.h"

#pragma region Opera��o
/**
 * Estrutura de uma Opera��o.
 */
typedef struct Operation {
	int cod;
}Operation;

/**
 * Cria uma nova Opera��o.
 */
Operation* NewOperation(int codOp);
#pragma endregion Opera��o

#pragma region Lista de Opera��es
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
 * Insere uma Opera��o.
 */
ListOperations* InsertListOperations(ListOperations* lo, Operation* o);

/**
 * Procura uma Opera��o na Lista.
 */
ListOperations* SearchOperation(ListOperations* lo, int codOp);

/**
 * Fun��o para editar o tempo de execu��o de uma maquina numa opera��o.
 */
ListOperations* EditOperation(ListOperations* lo, int codOp, int codMachine, int execTime);

/**
 * Apaga uma Opera��o e as M�quinas dela.
 */
ListOperations* DeleteOperation(ListOperations* lo, int CodOp);

/**
 * Insere uma m�quina na Opera��o.
 */
ListOperations* InsertMachineIntoOperations(ListOperations* lo, Machine* m, int codOp);

/**
 * Mostra a Lista de Opera��es e as M�quinas de cada Opera��o.
 */
void ShowOperations(ListOperations* i);

/**
 * Mostra as M�quinas de uma opera��o especifica.
 */
void ShowMachinesInOperation(ListOperations* i, int codOp);

/**
 * Grava uma Lista de Opera��es e as M�quinas.
 */
bool SaveOperations(ListOperations* lo, char* filename);

/**
 * Fun��o para ler uma opera��o.
 */
ListOperations* ReadOperations(char* filename);

/**
 * Fun��o para verificar o tempo minimo para completar uma lista de opera��es.
 */
int SmOperation(ListOperations* lo);

/**
 * Fun��o para verificar o tempo m�ximo para completar uma lista de opera��es.
 */
int LgOperation(ListOperations* lo);

/**
 * Fun��o para verificar o tempo m�dio de execu��o de uma opera��o.
 */
int AvgOperation(ListOperations* lo, int codOp);
#pragma endregion Lista de Opera��es
