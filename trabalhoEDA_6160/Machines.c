/*****************************************************************//**
 * \file   Machines.c
 * \brief  Ficheiro com a Fun��es refrentes �s Maquinas
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/

#pragma warning(disable : 4996)
#include "Machines.h"

/**
 * Fun��o para criar uma M�quina.
 * 
 * \param codMachine C�digo de M�quina
 * \param exeTime Tempo de Execu��o
 * \return 
 */
Machine* NewMachine(int codMachine, int exeTime) {
	Machine* create = (Machine*)malloc(sizeof(Machine));
	if (create) {
		create->cod = codMachine;
		create->exeTime = exeTime;
		return create;
	}
	return NULL;
};

/**
 * Fun��o para procurar uma m�quina dentro de uma Lista de N�quinas.
 *
 * \param lm Lista de M�quinas
 * \param codMachine C�digo da M�quina
 * \return
 */
ListMachines* SearchMachine(ListMachines* lm, int codMachine) {
	ListMachines* aux = lm;
	while (aux) {
		if (aux->machine.cod == codMachine) return aux;
		aux = aux->next;
	}
	return NULL;
}

/**
 * Fun��o para editar uma m�quina dentro de uma Lista de M�quinas.
 *
 * \param i Lista de M�quinas
 * \param codMachine C�digo da M�quina
 * \param exeTime Tempo de Execu��o da M�quina
 * \return
 */
ListMachines* EditMachine(ListMachines* lm, int codMachine, int exeTime) {
	if (lm == NULL) return NULL;

	ListMachines* aux = SearchMachine(lm, codMachine);

	if (aux) {
		aux->machine.exeTime = exeTime;
		return aux;
	}

	return NULL;
}

/**
 * Fun��o para criar uma Lista de M�quinas.
 * 
 * \param m M�quina a inserir
 * \return 
 */
ListMachines* NewNodeListMachines(Machine* m) {
	ListMachines* create = (ListMachines*)malloc(sizeof(ListMachines));
	if (create) {
		create->machine.cod = m->cod;
		create->machine.exeTime = m->cod;
		create->next = NULL;
		return create;
	}
	return NULL;
}

/**
 * Fun��o para inserir uma m�quina na Lista.
 * 
 * \param lm Lista de M�quinas 
 * \param m M�quina a inserir
 * \return 
 */
ListMachines* InsertMachineList(ListMachines* lm, Machine* m) {
	if (m == NULL) return lm;
	ListMachines* create = NewNodeListMachines(m);
	if (lm == NULL) lm = create;
	else {
		create->next = lm;
		lm = create;
	}
	return lm;
}

/**
 * Fun��o para apagar todas as M�quinas.
 * 
 * \param i Lista de M�quinas
 * \return 
 */
ListMachines* DeleteMachines(ListMachines* lm) {
	while (lm != NULL)
	{
		ListMachines* aux = lm;
		aux = aux->next;
		free(aux);
	}
	return NULL;
}

/**
 * Fun��o para listar as M�quinas dentro de uma lista.
 *
 * \param lm Lista de M�quinas
 */
void ShowMachines(ListMachines* lm) {
	ListMachines* aux = lm;
	while (aux) {
		printf("Codigo: %d - Tempo de Execu��o: %d\n", aux->machine.cod, aux->machine.exeTime);
	}
}

/**
 * Fun��o para determinar a m�quina com a opera��o menor.
 * 
 * \param lm Lista de M�quinas
 * \return 
 */
int SmMachines(ListMachines* lm) {
	ListMachines* aux = lm;
	int sm = 0;

	while (aux) {
		if (sm < aux->machine.exeTime) sm = aux->machine.exeTime;
		aux = aux->next; //// Perguntar ao Prof se � necess�rio
	}

	return sm;
}

/**
 * Fun��o para determinar a m�quina com a opera��o maior.
 * 
 * \param lm Lista de M�quinas
 * \return 
 */
int LgMachines(ListMachines* lm) {
	ListMachines* aux = lm;
	int lg = 0;

	while (aux) {
		if (lg < aux->machine.exeTime) lg = aux->machine.exeTime;
		aux = aux->next; //// Perguntar ao Prof se � necess�rio
	}

	return lg;
}