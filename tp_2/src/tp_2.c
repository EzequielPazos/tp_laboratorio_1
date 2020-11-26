/*
 ============================================================================
 Name        : tp_2.c
 Author      : Pazos Ezequiel
 Version     : 1.0.4
 Division    : 1°G
 Description : Trabajo practico 2 - Programacion/Laboratorio - ABM EMPLEADOS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arrayEmployees.h"

#define LEN 100

int main(void) {

	setbuf(stdout, NULL);

	int option;
	int optionInfo;
	int ans;
	int id = 1;
	int sector;
	int employeeQuantity;
	int employeesOverAverageSalary = 0;
	int index;
	int order;
	float salary;
	float averageSalaries;
	float totalSalaries = 0;
	char name[20];
	char lastName[20];


	char seguir = 's';
	char seguirInfo = 's';
	char confirm;
	Employee list[LEN];


	if(initEmployees(list , LEN)== 0)
	{
		printf("> Personas inicializadas con exito!\n\n");
	}else
	{
		printf("> Problemas al inicializar personas.\n\n");
	}

	do{

		option = showMenu();

		switch(option)
		{
			case 1:
				if(list !=NULL && LEN>0 && id>0)
				{
					system("cls");
					printf("*** ALTA DE EMPLEADOS ***\n\n");
					index = findEmpty(list, LEN);

					if(index == -1) //error del indice
					{
						printf("El sistema esta completo");
					}else
					{
						printf("Ingrese nombre: ");
						fflush(stdin);
						gets(name);

						printf("Ingrese apellido: ");
						fflush(stdin);
						gets(lastName);

						printf("Ingrese salario: ");
						scanf("%f", &salary);

						printf("Ingrese sector: ");
						scanf("%d", &sector);

						ans = addEmployee(list, LEN, id, name, lastName, salary, sector);

						if(ans == 0)
						{
							id++;
							printf("> El usuario se ha dado de alta con exito!\n\n");
						}else
						{
							printf("> Problema para realizar el alta.\n\n");
						}
						system("pause");
					}
				}
				break;
			case 2:
				ans = modifyEmployee(list, LEN);
				if(ans == -1)
				{
					printf("> Se ha producido un error en la modificion.\n\n");
				}
				break;
			case 3:
				ans = removeEmployee(list, LEN);
				if(ans == 0)
				{
					printf("> Baja exitosa!\n\n");
				}else
				{
					printf("> Se ha producido un error en la baja.\n\n");
				}
				break;
			case 4:
				do{
					system("cls");
					printf("==================== INFORMES ====================\n\n");
					printf("1 ---> Listado de los empleados\n");
					printf("2 ---> Salarios\n");
					printf("3 ---> Volver atras.\n\n");
					printf("Ingrese la opcion deseada: ");
					scanf("%d", &optionInfo);

					switch(optionInfo)
					{
						case 1:
							system("cls");
							printf("Desea listar los empleados en orden: \n\n");
							printf("0 ---> Descendente\n");
							printf("1 ---> Ascendente\n\n");
							printf("Ingrese el numero que corresponda: ");
							scanf("%d", &order);

							while(order !=0 && order !=1)
							{
								printf("Respuesta invalida. Ingrese nuevamente: ");
								scanf("%d", &order);
							}

							ans = sortEmployees(list, LEN, order);
							if(ans == -1)
							{
								printf("> El listado se ha ordenado con exito!\n\n");
							}

							ans = printEmployees(list, LEN);
							if(ans == 0)
							{
								printf("> El listado se ha mostrado con exito!\n\n");
							}else
							{
								printf("> Hubo un error intentando mostrar el listado.\n\n");
							}
							system("pause");
							break;
						case 2:
							for(int i=0;i<id;i++)
							{
								totalSalaries = totalSalaries + list[i].salary;
							}

							employeeQuantity = id - 1;

							averageSalaries = totalSalaries / employeeQuantity;

							for(int i=0;i<id;i++)
							{
								if(list[i].salary>averageSalaries)
								{
									employeesOverAverageSalary++;
								}
							}

							printf("            INFORME    SALARIOS          \n");
							printf("-----------------------------------------\n\n");
							printf("> Total salarios: %.2f\n", totalSalaries);
							printf("> Promedio salarios: %.2f\n", averageSalaries);
							printf("> Empleados con salario por encima del promedio: %d\n", employeesOverAverageSalary);

							totalSalaries = 0;
							employeesOverAverageSalary = 0;

							system("pause");
							break;
						case 3:
							seguirInfo = 'n';
							break;
						default:
							printf("\nLa opcion ingresada no existe!\n\n"); //validacion de las opciones disponibles
							system("pause");
							break;
					}
				}while(seguirInfo == 's');
				break;
			case 5:
				printf("\nConfirma que quiere salir? Ingrese s/n\n"); //confirmacion si quiere salir
				fflush(stdin);
				scanf("%c", &confirm);
				confirm = tolower(confirm);
				while(confirm !='s' && confirm !='n')
				{
					printf("Respuesta invalida. Ingrese s/n\n"); //validacion  de la confirmacion
					fflush(stdin);
					scanf("%c", &confirm);
					confirm = tolower(confirm);
				}
				if(confirm=='s')
				{
					seguir = 'n';
				}
				break;
			default:
				printf("\nLa opcion ingresada no existe!\n\n"); //validacion de las opciones disponibles
				system("pause");
				break;
		}

	}while(seguir == 's');

	return EXIT_SUCCESS;
}
