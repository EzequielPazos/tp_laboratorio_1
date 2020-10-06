/*
 ============================================================================
 Name        : tp_2.c
 Author      : Pazos Ezequiel
 Version     : 1.0.3
 Division    : 1°G
 Description : Trabajo practico 2 - Programacion/Laboratorio - ABM EMPLEADOS
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 1000

int main(void) {

	setbuf(stdout, NULL);

	int option;
	int optionInfo;
	int nextId = 1;
	int ans;
	int id;
	int employeeQuantity;
	int employeesOverAverageSalary = 0;
	float averageSalaries;
	float totalSalaries = 0;
	char name[LEN];
	char lastName[LEN];
	char salary;
	char sector;
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
		scanf("%d", &option);

		switch(option)
		{
			case 1:
				ans = addEmployee(list, LEN, id, name, lastName, salary, sector);
				if(ans == 0)
				{
					nextId++;
					printf("> Alta exitosa!\n\n");
				}else
				{
					printf("> Problema para realizar el alta.\n\n");
				}

				break;
			case 2:

				break;
			case 3:
				ans = removeEmployee(list, LEN);
				if(ans == 0)
				{
					printf("> Baja exitosa!\n\n");
				}else
				{
					printf("> Se ha producido un error en la baja.");
				}
				break;
			case 4:
				do{

					printf("==================== INFORMES ====================\n\n");
					printf("1 ---> Listado de los empleados\n");
					printf("2 ---> Salarios\n");
					printf("3 ---> Volver atras.\n\n");
					printf("Ingrese la opcion deseada: ");
					scanf("%d", &optionInfo);

					switch(optionInfo)
					{
						case 1:
							ans = printEmployees(list, LEN);
							if(ans == 0)
							{
								printf("> El listado se ha mostrado con exito!");
							}else
							{
								printf("> Hubo un error intentando mostrar el listado.");
							}
							break;
						case 2:
							printf("            INFORME    SALARIOS          \n");
							printf("-----------------------------------------\n\n");
							printf("> Total salarios: %.2f\n", totalSalaries);
							printf("> Promedio salarios: %.2f\n", averageSalaries);
							printf("> Empleados con salario por encima del promedio: %d\n", employeesOverAverageSalary);
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

		for(int i=1;i<nextId;i++)
		{
			totalSalaries = totalSalaries + list[i].salary;
		}

		employeeQuantity = nextId - 1;

		averageSalaries = totalSalaries / employeeQuantity;

		for(int i=1;i<nextId;i++)
		{
			if(list[i].salary>averageSalaries)
			{
				employeesOverAverageSalary++;
			}
		}

	}while(seguir == 's');

	return EXIT_SUCCESS;
}
