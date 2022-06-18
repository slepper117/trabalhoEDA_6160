/*****************************************************************//**
 * \file   Jobs.c
 * \brief  Ficheiro com as Fun��es dos Jobs
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/

#pragma warning(disable : 4996)
#include "Jobs.h"
#include "Operations.h"

/**
 * Fun��o que cria um Job.
 * 
 * \param codJob C�digo do Job
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
 * \param j Job
 * \return 
 */
ListJobs* NewNodeListJobs(Job* j) {
	ListJobs* create = (ListJobs*)malloc(sizeof(ListJobs));
	create->job.cod = j->cod;
	create->lo = NULL;
	create->next = NULL;
	return create;
}

/**
 * Insere um Job na Lista de Jobs.
 * 
 * \param lj Lista de Jobs
 * \param j Job a inserir
 * \return 
 */
ListJobs* InsertListJobs(ListJobs* lj, Job* j) {
	if (j == NULL) return lj;
	ListJobs* create = NewNodeListJobs(j);
	if (lj == NULL) lj = create;
	else
	{
		create->next = lj;
		lj = create;
	}

	return lj;
}

/**
 * Procurar um Job numa Lista.
 * 
 * \param i Lista de Jobs
 * \param codJob C�digo do Job
 * \return 
 */
ListJobs* SearchJob(ListJobs* lj, int codJob) {
	ListJobs* aux = lj;
	while (aux)
	{
		if (aux->job.cod == codJob) return aux;
		aux = aux->next;
	}
	return NULL;
}

/**
 * Fun��o para editar o tempo de execu��o de uma maquina num Job.
 * 
 * \param lj Lista de Jobs
 * \param codJob C�digo do Job
 * \param codOp C�digo da Opera��o
 * \param codMachine C�digo da M�quina
 * \param execTime Tempo de Execu��o
 * \return 
 */
ListJobs* Editjob(ListJobs* lj, int codJob, int codOp, int codMachine, int execTime) {
	ListJobs* aux = lj;

	aux = SearchJob(lj, codJob);

	if (aux) {
		ListOperations* lo = aux->lo;
		lo = EditOperation(lo, codOp, codMachine, execTime);
		return aux;
	}

	return NULL;
}

/**
 * Inserir uma opera��o num Job.
 * 
 * \param lj Lista de Jobs
 * \param o Opera��o a inserir
 * \param codJob C�digo do Job
 * \return 
 */
ListJobs* InsertOperationIntoJob(ListJobs* lj, Operation* o, int codJob) {
	if (lj == NULL) return NULL;
	if (o == NULL) return lj;

	ListJobs* aux = SearchJob(lj, codJob);

	if (aux) {
		aux->lo = InsertListOperations(aux->lo, o);
		return lj;
	}

	return NULL;
}

/**
 * Mostra Opera��es num Job.
 * 
 * \param lj Lista de Jobs
 * \param codJob C�digo do Job
 */
void ShowOperationsInJob(ListJobs* lj, int codJob) {
	ListJobs* aux = lj;

	aux = SearchJob(lj, codJob);

	if (aux) {
		ListOperations* lo = aux->lo;
		printf("Job: %d\n", aux->job.cod);
		ShowOperations(lo);
	}
}

/**
 * Grava uma Lista de Jobs, as Opera��es e as M�quinas.
 *
 * \param lo Lista de Opera��es
 * \param filename Ficheiro para gravar
 * \return
 */
bool SaveJobs(ListJobs* lj, char* filename) {
	FILE* file;
	ListJobs* aux = lj;

	// Verfica se a Lista de existe
	if (lj == NULL) {
		fprintf(stderr, "\nLista n�o existe!!!\n");
		return false;
	}

	// Verifica se ficheiro existe
	if ((file = fopen(filename, "w")) == NULL) {
		fprintf(stderr, "\nFicheiro n�o existe!!!\n");
		return false;
	}

	//Header do csv
	fprintf(file,"codJob;codOp;codMaq;exeTime\n");
	// Percorre a Lista
	while (aux) {
		fprintf(file,"%d;%d;%d;%d\n", aux->job.cod, aux->lo->op.cod, aux->lo->lm->machine.cod);
		aux = aux->next;
	}

	fclose(file);
	return true;
}

/**
 * Fun��o para ler os Jobs, Opera��es e M�quinas.
 *
 * \param filename Ficheiro a ler.
 * \return
 */
ListJobs* ReadJobs(char* filename) {
	FILE* file;
	ListJobs* lj = NULL;
	Job j;
	Operation o;
	Machine m;
	char l[1024];

	// Verifica se ficheiro existe
	if ((file = fopen(filename, "w")) == NULL) {
		fprintf(stderr, "\nFicheiro n�o existe!!!\n");
		return NULL;
	}

	while (fgets(l, 1024, file) != NULL) {
		
		sscanf(l, "%d;%d;%d;%d", &j.cod, &o.cod, &m.cod, &m.exeTime);

		if (SearchJob(lj, j.cod) == NULL) {
			lj = InsertListJobs(lj, &j);
		}

		lj = InsertOperationIntoJob(lj, &o, j.cod);
		lj = InsertMachineIntoOperations(lj->lo, &m, o.cod);
	}

	fclose(file);
	return lj;
}