/*****************************************************************//**
 * \file   Operations.c
 * \brief  Ficheiro com as fun��es relativas �s Opera��es
 * 
 * \author renato
 * \date   April 2022
 *********************************************************************/

#pragma warning(disable : 4996)
#include "Operations.h"
#include "Machines.h"

/**
 * Cria uma nova Opera��o.
 * 
 * \param codOp C�digo da Opera��o
 * \return
 */
Operation* NewOperation(int codOp) {
	Operation* create = (Operation*)malloc(sizeof(Operation));
	create->cod = codOp;
	return create;
}

/**
 * Cria um Nodo na Lista de Opera��es.
 * 
 * \param o Opera��o a inserir
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
 * Insere uma Opera��o.
 * 
 * \param lo Lista de Dados onde inserir
 * \param o Opera��o a Inserir
 * \return 
 */
ListOperations* InsertListOperations(ListOperations* lo, Operation* o) {
	if (o == NULL) return lo;
	ListOperations* create = NewNodeListOperations(o);
	if (lo == NULL) lo = create;
	else {
		create->next = lo;
		lo = create;
	}
	return lo;
}

/**
 * Procura uma Opera��o na Lista.
 * 
 * \param i Lista de Opera��es
 * \param codOp C�digo da Lista de Opera��es
 * \return 
 */
ListOperations* SearchOperation(ListOperations* lo, int codOp) {
	ListOperations* aux = lo;
	while (aux)
	{
		if (aux->op.cod == codOp) return aux;
		aux = aux->next;
	}
	return NULL;
}

/**
 * Fun��o para editar o tempo de execu��o de uma maquina numa opera��o.
 * 
 * \param lo Lista de Opera��es
 * \param codOp C�digo da Opera��o
 * \param codMachine C�digo da M�quina
 * \param execTime Tempo de Execu��o
 * \return 
 */
ListOperations* EditOperation(ListOperations* lo, int codOp, int codMachine, int execTime) { 
	ListOperations* aux = lo;

	aux = SearchOperation(lo, codOp);

	if (aux) {
		ListMachines* lm = aux->lm;
		lm = EditMachine(lm, codMachine, execTime);
		return aux;
	}

	return NULL;
}

/**
 * Apaga uma Opera��o e as M�quinas dela.
 * 
 * \param lo Lista de Opera��es
 * \param CodOp C�digo da Opera��o
 * \return 
 */
ListOperations* DeleteOperation(ListOperations* lo, int CodOp) {
	if (lo == NULL) return NULL;

	ListOperations* aux = SearchOperation(lo, CodOp);

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
 * Mostra a Lista de Opera��es e as M�quinas de cada Opera��o.
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

	aux = SearchOperation(i, codOp);

	if (aux) {
		ListMachines* lm = aux->lm;
		printf("Operation: %d\n", aux->op.cod);
		ShowMachines(lm);
	}
}

/**
 * Grava uma Lista de Opera��es e as M�quinas.
 * 
 * \param lo Lista de Opera��es
 * \param filename Ficheiro para gravar
 * \return
 */
bool SaveOperations(ListOperations* lo, char* filename) {
	FILE* file;
	ListOperations* aux = lo;

	// Verfica se a Lista de existe
	if (lo == NULL) {
		fprintf(stderr, "\nLista n�o existe!!!\n");
		return false;
	}

	// Verifica se ficheiro existe
	if ((file = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "\nFicheiro n�o existe!!!\n");
		return false;
	}

	// Percorre a Lista
	while (aux) {
		fwrite(aux->lm, sizeof(aux->lm), 1, file);
		aux = aux->next;
	}

	fclose(file);
	return true;
}

/**
 * Fun��o para ler uma opera��o.
 * 
 * \param filename Ficheiro a ler.
 * \return
 */
ListOperations* ReadOperations(char* filename) {
	FILE* file;
	ListOperations* lo = NULL;
	Operation o;
	Machine m;
	char l[1024];

	// Verifica se ficheiro existe
	if ((file = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "\nFicheiro n�o existe!!!\n");
		return NULL;
	}

	while (fgets(l, 1024, file) != NULL) {
		scanf(l, "%d;%d;%d", &o.cod, &m.cod, &m.exeTime);

		if (SearchOperation(lo, o.cod) == NULL) {
			lo = InsertListOperations(lo, &o);
		}

		lo = InsertMachineIntoOperations(lo, &m, o.cod);
	}

	fclose(file);
	return lo;
}

/**
 * Fun��o para verificar o tempo minimo para completar uma lista de opera��es.
 * 
 * \param lo Lista de Opera��es
 * \return 
 */
int SmOperation(ListOperations* lo) {
	ListOperations* aux = lo;
	int sm = 0;

	while (aux) {
		ListMachines* lm = aux->lm;
		sm += SmMachines(lm);
		aux = aux->next;
	}

	return sm;
}

/**
 * Fun��o para verificar o tempo m�ximo para completar uma lista de opera��es.
 * 
 * \param lo
 * \return 
 */
int LgOperation(ListOperations* lo) {
	ListOperations* aux = lo;
	int lg = 0;

	while (aux) {
		ListMachines* lm = aux->lm;
		lg += LgMachines(lm);
		aux = aux->next;
	}

	return lg;
}

/**
 * Fun��o para verificar o tempo m�dio de execu��o de uma opera��o.
 * 
 * \param lo
 * \param codOp
 * \return 
 */
int AvgOperation(ListOperations* lo, int codOp) {
	int sum = 0;
	int tot = 0;
	ListOperations* aux = lo;
	
	aux = SearchOperation(lo, codOp);

	if (aux) {
		ListMachines* lm = aux->lm;
		while (lm != NULL) {
			tot++;
			sum += lm->machine.exeTime;
			lm = lm->next;
		}
	}

	return sum / tot;
}