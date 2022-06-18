/*****************************************************************//**
 * \file   Machines.c
 * \brief  Ficheiro com a Funções refrentes às Maquinas
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/

#pragma warning(disable : 4996)
#include "Machines.h"

/**
 * Função para criar uma Máquina.
 * 
 * \param codMachine Código de Máquina
 * \param exeTime Tempo de Execução
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
 * Função para procurar uma máquina dentro de uma Lista de Náquinas.
 *
 * \param lm Lista de Máquinas
 * \param codMachine Código da Máquina
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
 * Função para editar uma máquina dentro de uma Lista de Máquinas.
 *
 * \param i Lista de Máquinas
 * \param codMachine Código da Máquina
 * \param exeTime Tempo de Execução da Máquina
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
 * Função para criar uma Lista de Máquinas.
 * 
 * \param m Máquina a inserir
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
 * Função para inserir uma máquina na Lista.
 * 
 * \param lm Lista de Máquinas 
 * \param m Máquina a inserir
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
 * Função para apagar todas as Máquinas.
 * 
 * \param i Lista de Máquinas
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
 * Função para listar as Máquinas dentro de uma lista.
 *
 * \param lm Lista de Máquinas
 */
void ShowMachines(ListMachines* lm) {
	ListMachines* aux = lm;
	while (aux) {
		printf("Codigo: %d - Tempo de Execução: %d\n", aux->machine.cod, aux->machine.exeTime);
	}
}

/**
 * Função para determinar a máquina com a operação menor.
 * 
 * \param lm Lista de Máquinas
 * \return 
 */
int SmMachines(ListMachines* lm) {
	ListMachines* aux = lm;
	int sm = 0;

	while (aux) {
		if (sm < aux->machine.exeTime) sm = aux->machine.exeTime;
		aux = aux->next; //// Perguntar ao Prof se é necessário
	}

	return sm;
}

/**
 * Função para determinar a máquina com a operação maior.
 * 
 * \param lm Lista de Máquinas
 * \return 
 */
int LgMachines(ListMachines* lm) {
	ListMachines* aux = lm;
	int lg = 0;

	while (aux) {
		if (lg < aux->machine.exeTime) lg = aux->machine.exeTime;
		aux = aux->next; //// Perguntar ao Prof se é necessário
	}

	return lg;
}