/*****************************************************************//**
 * \file   Operations.c
 * \brief  Ficheiro com as fun��es relativas �s Opera��es
 * 
 * \author renato
 * \date   April 2022
 *********************************************************************/

#include "Operations.h"
#include "Machines.h"

/**
 * Cria uma nova Opera��o.
 * 
 * \param cod Operation C�digo da Opera��o
 * \return Opera��o Criada
 */
Operation* NewOperation(int codOperation) {
	Operation* create = (Operation*)malloc(sizeof(Operation));
	create->cod = codOperation;
	return create;
}

/**
 * Cria um Nodo na Lista de Opera��es.
 * 
 * \param o Opera��o a receber
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
 * Insere Dados numa Opera��o.
 * 
 * \param l Lista de Dados onde inserir
 * \param o Opera��o a Inserir
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
 * Procura uma Opera��o na Lista.
 * 
 * \param i Lista de Opera��es
 * \param codOp C�digo da Lista de Opera��es
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
 * Apaga uma Opera��o.
 * 
 * \param i Lista de Opera��es
 * \param CodOp C�digo da Lista de Opera��es
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
 * Insere uma m�quina na Opera��o.
 * 
 * \param lo Lista de Opera��es
 * \param m M�quina para inserir
 * \param codOp C�digo da Opera��o
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
 * Mostra as Lista de Opera��es e as M�quinas de cada Opera��o.
 * 
 * \param i Lista de Opera��es
 */
void ShowOperations(ListOperations* i) {
	ListOperations* aux = i;
	while (aux) {
		printf("Opera��o: %d\n", aux->op.cod);
		ShowMachines(aux->lm);
		aux = aux->next;
	}
}

/**
 * Mostra as M�quinas de uma opera��o especifica.
 * 
 * \param i Lista de Opera��es
 * \param codOp C�digo da Lista de Opera��es
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