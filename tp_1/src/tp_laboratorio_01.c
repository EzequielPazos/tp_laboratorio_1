/*
 ============================================================================
 Name        : tp_laboratorio_01.c
 Author      : Pazos Ezequiel
 Version     : 1.0.0
 Copyright   : Your copyright notice
 Description : Trabajo practico 1 de Laboratorio
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "funcionesCalculadora.h"

int main()
{
	setbuf(stdout, NULL);

	int opcion;
	float operandoUno = 0;
	float operandoDos = 0;
	float resultadoSuma;
	float resultadoResta;
	float resultadoDivision;
	float resultadoMultiplicacion;
	float resultadoFactorialUno;
	float resultadoFactorialDos;
	int flagOperandoUno = 0;
	int flagOperandoDos = 0;
	int flagCalculos = 0;
	char seguir = 's';
	char confirma;

	do
	{
		system("cls");

		printf("==================== CALCULADORA ====================\n\n"); //menu de opciones

		if(flagOperandoUno == 1)
		{
			printf("1 ---> Ingresar el 1er operando: A = (%.2f)\n", operandoUno);
		}else
		{
			printf("1 ---> Ingresar el 1er operando: A = (X)\n");
		}

		if(flagOperandoDos == 1)
		{
			printf("2 ---> Ingresar el 2do operando: B = (%.2f)\n", operandoDos);
		}else
		{
			printf("2 ---> Ingresar el 2do operando: B = (Y)\n");
		}

		printf("3 ---> Calcular todas las operaciones.\n");
		printf("4 ---> Informar resultados.\n");
		printf("5 ---> Salir.\n\n");
		printf("Ingrese la opcion deseada: ");
		scanf("%d", &opcion);

		switch(opcion) //opciones
		{
			case 1:
				printf("\n ---> Ingrese el 1er operando: "); //Ingreso del 1er operando
				scanf("%f", &operandoUno);
				flagOperandoUno = 1; //flag para saber si ya ingreso el primer operando
				break;
			case 2:
				printf("\n ---> Ingrese el 2do operando: "); //Ingreso del 2do operando
				scanf("%f", &operandoDos);
				flagOperandoDos = 1; //flag para saber si ya ingreso el segundo operando
				break;
			case 3:
				if(flagOperandoUno == 1 && flagOperandoDos == 1) //realizacion de calculos
				{
					resultadoSuma = sumar(operandoUno, operandoDos);
					resultadoResta = restar(operandoUno, operandoDos);
					if(operandoDos !=0)
					{
						resultadoDivision = dividir(operandoUno, operandoDos); //validacion division
					}
					resultadoMultiplicacion = multiplicar(operandoUno, operandoDos);
					resultadoFactorialUno = factorear(operandoUno);
					resultadoFactorialDos = factorear(operandoDos);
					flagCalculos = 1;
					printf("\n «Las operaciones fueron realizadas con exito!»\n\n");
					system("pause");
				}else
				{
					printf("\n ---> Primero debe ingresar los operandos!\n\n"); //validacion del ingreso de operandos
					system("pause");
				}
				break;
			case 4:
				if(!flagOperandoUno || !flagOperandoDos)
				{
					printf("\n ---> Primero debe ingresar los operandos!\n\n"); //validacion del ingreso de operandos
					system("pause");
				}else
				{
					if(!flagCalculos)
					{
						printf("\n ---> Primero debe realizar los calculos!\n\n"); //validacion de la realizacion de calculos
						system("pause");
					}else
					{
						printf("\n«El resultado de %.2f + %.2f es: %.2f»\n", operandoUno, operandoDos, resultadoSuma); //mostrar resultados
						printf("«El resultado de %.2f - %.2f es: %.2f»\n", operandoUno, operandoDos, resultadoResta);
						if(operandoDos == 0) //validacion division
						{
							printf("«Error: No se puede dividir por 0!»\n");
						}else
						{
							printf("«El resultado de %.2f / %.2f es: %.2f»\n", operandoUno, operandoDos, resultadoDivision);
						}

						printf("«El resultado de %.2f * %.2f es: %.2f»\n", operandoUno, operandoDos, resultadoMultiplicacion);
						if(resultadoFactorialUno == -1) //validacion factorial
						{
							printf("«Error: No se puede factorear el 1er operando.»\n");
						}else
						{
							if(resultadoFactorialDos == -1) //validacion factorial
							{
								printf("«Error: No se puede factorear el 2do operando.»\n");
							}else
							{
								printf("«El factorial de %.2f es: %.2f y El factorial de %.2f es: %.2f»\n", operandoUno, resultadoFactorialUno, operandoDos, resultadoFactorialDos);
							}
						}
						system("pause");
					}
				}
				break;
			case 5:
				printf("\n«Confirma que quiere salir? Ingrese s/n»\n"); //confirmacion si quiere salir
				fflush(stdin);
				scanf("%c", &confirma);
				confirma = tolower(confirma);
				while(confirma !='s' && confirma !='n')
				{
					printf("«Respuesta invalida. Ingrese s/n»\n"); //validacion  de la confirmacion
					fflush(stdin);
					scanf("%c", &confirma);
					confirma = tolower(confirma);
				}
				if(confirma=='s')
				{
					seguir = 'n';
				}
				break;
			default:
				printf("La opcion ingresada no existe!»"); //validacion de las opciones disponibles
		}

	}while(seguir == 's');

	return EXIT_SUCCESS;
}
