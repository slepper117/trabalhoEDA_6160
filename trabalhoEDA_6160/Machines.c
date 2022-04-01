/*****************************************************************//**
 * \file   Machines.c
 * \brief  Ficheiro com a Funções refrentes às Maquinas
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/

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
	create->cod = codMachine;
	create->exeTime = exeTime;
	return create;
};

/**
 * Função para criar uma Lista de Máquinas.
 * 
 * \param m Máquina para receber 
 * \return 
 */
ListMachines* NewNodeListMachines(Machine* m) {
	ListMachines* create = (ListMachines*)malloc(sizeof(ListMachines));
	create->machines.cod = m->cod;
	create->machines.exeTime = m->cod;
	create->next = NULL;
	return create;
}

/**
 * Função para inserir uma máquina na Lista.
 * 
 * \param l Lista onde irá 
 * \param m Recebe uma struct máqina
 * \return 
 */
ListMachines* InsertMachineList(ListMachines* l, Machine* m) {
	if (m == NULL) return l;
	ListMachines* create = NewNodeListMachines(m);
	if (l == NULL) l = create;
	else {
		create->next = l;
		l = create;
	}
	return l;
}

/**
 * Função para apagar todas as Máquinas.
 * 
 * \param l Lista de Máquinas
 * \return 
 */
ListMachines* DeleteMachines(ListMachines* lm) {
	while (lm != NULL)
	{
		ListMachines* aux = lm;
		lm = lm->next;
		free(aux);
	}
	return NULL;
}

/**
 * Função para mostrar a lista de Máquinas.
 *
 * \param l Recebe uma struct Máquina
 */
void ShowMachines(ListMachines* l) {
	ListMachines* lm = l;
	while (lm) {
		printf("Codigo: %d - Tempo de Execução: %d\n", lm->machines.cod, lm->machines.exeTime);
	}
}
