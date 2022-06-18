/*****************************************************************//**
 * \file   Operations.c
 * \brief  Ficheiro com as funções relativas às Operações
 * 
 * \author renato
 * \date   April 2022
 *********************************************************************/

#pragma warning(disable : 4996)
#include "Operations.h"
#include "Machines.h"

/**
 * Cria uma nova Operação.
 * 
 * \param codOp Código da Operação
 * \return
 */
Operation* NewOperation(int codOp) {
	Operation* create = (Operation*)malloc(sizeof(Operation));
	create->cod = codOp;
	return create;
}

/**
 * Cria um Nodo na Lista de Operações.
 * 
 * \param o Operação a inserir
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
 * Insere uma Operação.
 * 
 * \param lo Lista de Dados onde inserir
 * \param o Operação a Inserir
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
 * Procura uma Operação na Lista.
 * 
 * \param i Lista de Operações
 * \param codOp Código da Lista de Operações
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
 * Função para editar o tempo de execução de uma maquina numa operação.
 * 
 * \param lo Lista de Operações
 * \param codOp Código da Operação
 * \param codMachine Código da Máquina
 * \param execTime Tempo de Execução
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
 * Apaga uma Operação e as Máquinas dela.
 * 
 * \param lo Lista de Operações
 * \param CodOp Código da Operação
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
 * Mostra a Lista de Operações e as Máquinas de cada Operação.
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

	aux = SearchOperation(i, codOp);

	if (aux) {
		ListMachines* lm = aux->lm;
		printf("Operation: %d\n", aux->op.cod);
		ShowMachines(lm);
	}
}

/**
 * Grava uma Lista de Operações e as Máquinas.
 * 
 * \param lo Lista de Operações
 * \param filename Ficheiro para gravar
 * \return
 */
bool SaveOperations(ListOperations* lo, char* filename) {
	FILE* file;
	ListOperations* aux = lo;

	// Verfica se a Lista de existe
	if (lo == NULL) {
		fprintf(stderr, "\nLista não existe!!!\n");
		return false;
	}

	// Verifica se ficheiro existe
	if ((file = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "\nFicheiro não existe!!!\n");
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
 * Função para ler uma operação.
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
		fprintf(stderr, "\nFicheiro não existe!!!\n");
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
 * Função para verificar o tempo minimo para completar uma lista de operações.
 * 
 * \param lo Lista de Operações
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
 * Função para verificar o tempo máximo para completar uma lista de operações.
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
 * Função para verificar o tempo médio de execução de uma operação.
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