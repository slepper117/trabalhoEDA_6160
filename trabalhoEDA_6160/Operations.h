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
#include <stdbool.h>
#include "Machines.h"

#pragma region Operação
/**
 * Estrutura de uma Operação.
 */
typedef struct Operation {
	int cod;
}Operation;

/**
 * Cria uma nova Operação.
 */
Operation* NewOperation(int codOp);
#pragma endregion Operação

#pragma region Lista de Operações
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
 * Insere uma Operação.
 */
ListOperations* InsertListOperations(ListOperations* lo, Operation* o);

/**
 * Procura uma Operação na Lista.
 */
ListOperations* SearchOperation(ListOperations* lo, int codOp);

/**
 * Função para editar o tempo de execução de uma maquina numa operação.
 */
ListOperations* EditOperation(ListOperations* lo, int codOp, int codMachine, int execTime);

/**
 * Apaga uma Operação e as Máquinas dela.
 */
ListOperations* DeleteOperation(ListOperations* lo, int CodOp);

/**
 * Insere uma máquina na Operação.
 */
ListOperations* InsertMachineIntoOperations(ListOperations* lo, Machine* m, int codOp);

/**
 * Mostra a Lista de Operações e as Máquinas de cada Operação.
 */
void ShowOperations(ListOperations* i);

/**
 * Mostra as Máquinas de uma operação especifica.
 */
void ShowMachinesInOperation(ListOperations* i, int codOp);

/**
 * Grava uma Lista de Operações e as Máquinas.
 */
bool SaveOperations(ListOperations* lo, char* filename);

/**
 * Função para ler uma operação.
 */
ListOperations* ReadOperations(char* filename);

/**
 * Função para verificar o tempo minimo para completar uma lista de operações.
 */
int SmOperation(ListOperations* lo);

/**
 * Função para verificar o tempo máximo para completar uma lista de operações.
 */
int LgOperation(ListOperations* lo);

/**
 * Função para verificar o tempo médio de execução de uma operação.
 */
int AvgOperation(ListOperations* lo, int codOp);
#pragma endregion Lista de Operações
