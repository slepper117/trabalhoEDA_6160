/*****************************************************************//**
 * \file   Jobs.h
 * \brief  Ficheiro com as Estruturas de dados dos Jobs
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Operations.h"

#pragma region Job
/**
 * Estrutura de um Job.
 */
typedef struct Job {
	int cod;
}Job;

/**
 * Fun��o que cria um Job.
 */
Job* NewJob(int codJob);
#pragma endregion Job

#pragma region Lista de Jobs
/**
 * Estrutura de uma Lista de Jobs.
 */
typedef struct ListJobs {
	struct Job job;
	struct ListOperations* lo;
	struct ListJobs* next;
}ListJobs;

/**
 * Cria um Nodo na Lista de Jobs.
 */
ListJobs* NewNodeListJobs(Job* j);

/**
 * Insere um Job na Lista de Jobs.
 */
ListJobs* InsertListJobs(ListJobs* lj, Job* j);

/**
 * Procurar um Job numa Lista.
 */
ListJobs* SearchJob(ListJobs* lj, int codJob);

/**
 * Fun��o para editar o tempo de execu��o de uma maquina num Job.
 */
ListJobs* Editjob(ListJobs* lj, int codJob, int codOp, int codMachine, int execTime);

/**
 * Inserir uma opera��o num Job.
 */
ListJobs* InsertOperationIntoJob(ListJobs* lj, Operation* o, int codJob);

/**
 * Mostra Opera��es num Job.
 */
void ShowOperationsInJob(ListJobs* lj, int codJob);

/**
 * Grava uma Lista de Jobs, as Opera��es e as M�quinas.
 */
bool SaveJobs(ListJobs* lj, char* filename);

/**
 * Fun��o para ler os Jobs, Opera��es e M�quinas.
 */
ListJobs* ReadJobs(char* filename);
#pragma endregion Lista de Jobs
