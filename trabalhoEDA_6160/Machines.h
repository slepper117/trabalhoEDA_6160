/*****************************************************************//**
 * \file   Machines.h
 * \brief  Estrutura de Dados referente às Máquinas
 * 
 * \author renato
 * \date   April 2022
 *********************************************************************/
#pragma once

#include <stdio.h>
#include <stdlib.h>

/**
 * Estrutura da Máquina.
 */
typedef struct Machine {
	int cod;
	int exeTime;
}Machine;

/**
 * Função para criar uma Máquina.
 */
Machine* NewMachine(int codMachine, int exeTime);

/**
 * Estrutura da Lista de Máquinas.
 */
typedef struct ListMachines {
	struct Machine machines;
	struct ListMachines* next;
}ListMachines;

/**
 * Função para Criar um nodo na Lista.
 */
ListMachines* NewNodeListMachines(Machine* m);

/**
 * Função para Inserir uma Máquina na Lista.
 */
ListMachines* InsertMachineList(ListMachines* l, Machine* m);

/**
 * Função para Apagar as Máquinas.
 */
ListMachines* DeleteMachines(ListMachines* l);

/**
 * Função para Listar as Máquinas.
 */
void ShowMachines(ListMachines* l);




