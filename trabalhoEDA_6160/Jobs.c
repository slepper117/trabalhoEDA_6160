/*****************************************************************//**
 * \file   Jobs.c
 * \brief  Ficheiro com as Funções dos Jobs
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/
#include "Operations.h"
#include "Jobs.h"

/**
 * Função que cria um Job.
 * 
 * \param codJob Código do Job
 * \return 
 */
Job* NewJob(int codJob) {
	Job* create = (Job*)malloc(sizeof(Job));
	create->cod = codJob;
	return create;
}

/**
 * Cria um Nodo na Lista de Jobs.
 * 
 * \param j Lista de Jobs
 * \return 
 */
ListJobs* NewNodeListJobs(Job* j) {
	ListJobs* create = (ListJobs*)malloc(sizeof(ListJobs));
	create->job.cod = j->cod;
	create->lj = NULL;
	create->next = NULL;
	return create;
}

/**
 * Insere dados num Nodo da Lista de Jobs.
 * 
 * \param l Lista de Jobs
 * \param j Job
 * \return 
 */
ListJobs* InsertListJobs(ListJobs* l, Job* j) {
	if (j == NULL) return l;
	ListJobs* create = NewNodeListJobs(j);
	if (l == NULL) l = create;
	else
	{
		create->next = l;
		l = create;
	}

	return l;
}

/**
 * Procurar um Job.
 * 
 * \param i Lista de Jobs
 * \param codLj Código do Job
 * \return 
 */
ListJobs* SearchJob(ListJobs* i, int codLj) {
	ListJobs* aux = i;
	while (aux)
	{
		if (aux->job.cod == codLj) return aux;
		aux = aux->next;
	}
	return NULL;
}

/**
 * Inserir uma operação num Job.
 * 
 * \param lj Lista de Jobs
 * \param o Operação a inserir
 * \param codJob Código do Job
 * \return 
 */
ListJobs* InsertOperationIntoJob(ListJobs* lj, Operation* o, int codJob) {
	if (lj == NULL) return NULL;
	if (o == NULL) return lj;

	ListJobs* aux = SearchJob(lj, codJob);

	if (aux) {
		aux->lj = InsertListOperations(aux->lj, o);
	}

	return lj;
}

/**
 * Mostra Operações num Job.
 * 
 * \param i Lista de Jobs
 * \param codJob Código do Job
 */
void ShowOperationsInJob(ListJobs* i, int codJob) {
	ListJobs* aux = i;

	ListJobs* aux = SearchJob(i, codJob);

	if (aux) {
		ListOperations* lo = aux->lj;
		printf("Job: %d\n", aux->job.cod);
		ShowOperations(lo);
	}
}