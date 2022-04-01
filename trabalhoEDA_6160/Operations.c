/*****************************************************************//**
 * \file   Operations.c
 * \brief  Ficheiro com as funções relativas às Operações
 * 
 * \author renato
 * \date   April 2022
 *********************************************************************/

#include "Operations.h"
#include "Machines.h"

/**
 * Cria uma nova Operação.
 * 
 * \param cod Operation Código da Operação
 * \return Operação Criada
 */
Operation* NewOperation(int codOperation) {
	Operation* create = (Operation*)malloc(sizeof(Operation));
	create->cod = codOperation;
	return create;
}

/**
 * Cria um Nodo na Lista de Operações.
 * 
 * \param o Operação a receber
 * \return 
 */
ListOperations* NewNodeListOperations(Operation* o) {
	ListOperations* create = (ListOperations*)malloc(sizeof(ListOperations));
	create->op.cod = o->cod;
	create->lm = NULL;
	create->next = NULL;
	return create;
}

/**
 * Insere Dados numa Operação.
 * 
 * \param l Lista de Dados onde inserir
 * \param o Operação a Inserir
 * \return 
 */
ListOperations* InsertListOperations(ListOperations* l, Operation* o) {
	if (o == NULL) return l;
	ListOperations* create = NewNodeListOperations(o);
	if (l == NULL) l = create;
	else {
		create->next = l;
		l = create;
	}
	return l;
}

/**
 * Procura uma Operação na Lista.
 * 
 * \param i Lista de Operações
 * \param codOp Código da Lista de Operações
 * \return 
 */
ListOperations* SearchOperation(ListOperations* i, int codOp) {
	ListOperations* aux = i;
	while (aux)
	{
		if (aux->op.cod == codOp) return aux;
		aux = aux->next;
	}
	return NULL;
}

/**
 * Apaga uma Operação.
 * 
 * \param i Lista de Operações
 * \param CodOp Código da Lista de Operações
 * \return 
 */
ListOperations* DeleteOperation(ListOperations* i, int CodOp) {
	if (i == NULL) return NULL;

	ListOperations* aux = SearchOperation(i, CodOp);

	if (aux) {
		DeleteMachines(aux->lm);
		free(aux);
	}

	return NULL;
}

/**
 * Insere uma máquina na Operação.
 * 
 * \param lo Lista de Operações
 * \param m Máquina para inserir
 * \param codOp Código da Operação
 * \return 
 */
ListOperations* InsertMachineIntoOperations(ListOperations* lo, Machine* m, int codOp) {
	if (lo == NULL) return NULL;
	if (m == NULL) return lo;

	ListOperations* aux = SearchOperation(lo, codOp);

	if (aux) {
		aux->lm = InsertMachineList(aux->lm, m);
	}

	return lo;

}

/**
 * Mostra as Lista de Operações e as Máquinas de cada Operação.
 * 
 * \param i Lista de Operações
 */
void ShowOperations(ListOperations* i) {
	ListOperations* aux = i;
	while (aux) {
		printf("Operação: %d\n", aux->op.cod);
		ShowMachines(aux->lm);
		aux = aux->next;
	}
}

/**
 * Mostra as Máquinas de uma operação especifica.
 * 
 * \param i Lista de Operações
 * \param codOp Código da Lista de Operações
 */
void ShowMachinesInOperation(ListOperations* i, int codOp) {
	ListOperations* aux = i;

	ListOperations* aux = SearchOperation(i, codOp);

	if (aux) {
		ListMachines* lm = aux->lm;
		printf("Operation: %d\n", aux->op.cod);
		ShowMachines(lm);
	}
}