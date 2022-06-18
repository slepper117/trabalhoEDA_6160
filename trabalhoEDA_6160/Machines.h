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
#include <stdbool.h>

#pragma region Máquina
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
#pragma endregion Máquina

#pragma region Lista de Máquinas
/**
 * Estrutura da Lista de Máquinas.
 */
typedef struct ListMachines {
	struct Machine machine;
	struct ListMachines* next;
}ListMachines;

/**
 * Função para procurar uma máquina dentro de uma Lista de Náquinas.
 */
ListMachines* SearchMachine(ListMachines* lm, int codMachine);

/**
 * Função para editar uma máquina dentro de uma Lista de Máquinas.
 */
ListMachines* EditMachine(ListMachines* lm, int codMachine, int exeTime);

/**
 * Função para criar uma Lista de Máquinas.
 */
ListMachines* NewNodeListMachines(Machine* m);

/**
 * Função para inserir uma máquina na Lista.
 */
ListMachines* InsertMachineList(ListMachines* lm, Machine* m);

/**
 * Função para apagar todas as Máquinas.
 */
ListMachines* DeleteMachines(ListMachines* lm);

/**
 * Função para listar as Máquinas dentro de uma lista.
 */
void ShowMachines(ListMachines* lm);

/**
 * Função para determinar a máquina com a operação menor.
 */
int SmMachines(ListMachines* lm);

/**
 * Função para determinar a máquina com a operação maior.
 */
int LgMachines(ListMachines* lm);

#pragma endregion Lista de Máquinas