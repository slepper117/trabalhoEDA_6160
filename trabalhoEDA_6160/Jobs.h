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

#pragma region Job
/**
 * Estrutura de um Job.
 */
typedef struct Job {
	int cod;
}Job;

/**
 * Função que cria um Job.
 */
Job* NewJob(int codJob);
#pragma endregion Job

#pragma region Lista Jobs
/**
 * Estrutura de uma Lista de Jobs.
 */
typedef struct ListJobs {
	struct Job job;
	struct ListJobs* lj;
	struct ListJobs* next;
}ListJobs;

/**
 * Cria um Nodo na Lista de Jobs.
 */
ListJobs* NewNodeListJobs(Job* j);

/**
 * Insere dados num Nodo da Lista de Jobs.
 */
ListJobs* InsertListJobs(ListJobs* l, Job* j);

/**
 * Procurar um Job.
 */
ListJobs* SearchJob(ListJobs* i, int codLj);

/**
 * Inserir uma operação num Job.
 */
ListJobs* InsertOperationIntoJob(ListJobs* lj, Operation* o, int codOp);

/**
 * Mostra Operações num Job.
 */
void ShowOperationsInJob(ListJobs* i, int codOp);

#pragma endregion Lista Jobs



