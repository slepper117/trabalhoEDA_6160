/*****************************************************************//**
 * \file   Machines.c
 * \brief  Ficheiro com a Fun��es refrentes �s Maquinas
 * 
 * \author renat
 * \date   April 2022
 *********************************************************************/

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
	create->cod = codMachine;
	create->exeTime = exeTime;
	return create;
};

/**
 * Fun��o para criar uma Lista de M�quinas.
 * 
 * \param m M�quina para receber 
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
 * Fun��o para inserir uma m�quina na Lista.
 * 
 * \param l Lista onde ir� 
 * \param m Recebe uma struct m�qina
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
 * Fun��o para apagar todas as M�quinas.
 * 
 * \param l Lista de M�quinas
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
 * Fun��o para mostrar a lista de M�quinas.
 *
 * \param l Recebe uma struct M�quina
 */
void ShowMachines(ListMachines* l) {
	ListMachines* lm = l;
	while (lm) {
		printf("Codigo: %d - Tempo de Execu��o: %d\n", lm->machines.cod, lm->machines.exeTime);
	}
}
