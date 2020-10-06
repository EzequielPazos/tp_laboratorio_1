/*
 * arrayEmployees.c
 *
 *  Created on: 3 oct. 2020
 *      Author: Pazos Ezequiel
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int showMenu()
{
	int option;
	system("cls");

	printf("==================== ABM EMPLEADOS ====================\n\n");
	printf("1 ---> Altas\n");
	printf("2 ---> Modificar\n");
	printf("3 ---> Baja\n");
	printf("4 ---> Informar\n");
	printf("5 ---> Salir\n\n");
	printf("Ingrese la opcion deseada: ");

	return option;
}

int initEmployees(Employee* list, int len)
{
	int error = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
		error = 0;
	}

	return error;
}

int findEmpty(Employee* list, int len)
{
	int index = -1;

	for(int i=0;i<len;i++)
	{
		if(list[i].isEmpty == 1)
		{
			index = i;
			break;
		}
	}

	return index;
}

int addEmployee(Employee* list, int len, int id, char name[],char
lastName[],float salary,int sector)
{
	int error = -1; //falla
	int index;
	Employee newEmployee;

	if(list !=NULL && len>0 && id>0)
	{
		system("cls");
		printf("*** ALTA DE EMPLEADOS ***");
		index = findEmpty(list, len);

		if(index == -1) //error del indice
		{
			printf("El sistema esta completo");
		}else
		{
			newEmployee.id = id;
			newEmployee.isEmpty = 0;
			printf("Ingrese nombre: "); //FALTA VALIDAR INGRESO DE DATOS
			fflush(stdin);
			gets(newEmployee.name);

			printf("Ingrese apellido: ");
			fflush(stdin);
			gets(newEmployee.lastName);

			printf("Ingrese salario: ");
			scanf("%f", &newEmployee.salary);

			printf("Ingrese sector: ");
			scanf("%d", &newEmployee.sector);

			printf("Usted ha sido ingresado al sistema con exito!");

			error = 0;
		}
	}

	return error;
}

int findEmployeeById(Employee* list, int len,int id)
{
	int index = -1;

	for(int i=0;i<len;i++)
	{
		if(list[i].id == id)
		{
			index = i;
			break;
		}
	}

	return index;
}

void printAnEmployee(Employee anEmployee)
{
	printf("  %d  %s  %s  %.2f  %02d\n", anEmployee.id, anEmployee.name, anEmployee.lastName, anEmployee.salary, anEmployee.sector);
}

int printEmployees(Employee* list, int len)
{
	int error = -1;
	int flag = 0;

	system("cls");

	if(list !=NULL && len>0)
	{
		printf("  ID  Nombre  Apellido  Salario  Sector\n");
		printf("-----------------------------------------\n");

		for(int i=0; i<len; i++)
		{
			if(list[i].isEmpty == 0)
			{
				printAnEmployee(list[i]);
				flag = 1;
			}
		}
		if(flag == 0)
		{
			printf("  No hay empleados en la lista!");
		}
		printf("\n\n");

		error = 0;
	}

	return error;
}

int removeEmployee(Employee* list, int len)
{
	int error = -1;
	int id;
	int index;
	char confirm;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("*** BAJA DE EMPLEADOS ***\n\n");
		printEmployees(list, len);
		printf("Ingrese el ID: ");
		scanf("%d", &id);

		index = findEmployeeById(list, len, id);

		if(index == -1)
		{
			printf("No existe ninguna persona con esa ID!\n\n");
		}else
		{
			printAnEmployee(list[index]);
			printf("Confirma el borrado? Ingrese s/n\n");
			fflush(stdin);
			scanf("%c", &confirm);
			while(confirm !='s' && confirm !='n')
			{
				printf("La respuesta ingresada no es valida. Ingrese s/n\n");
				fflush(stdin);
				scanf("%c", &confirm);
			}

			if(confirm =='s')
			{
				list[index].isEmpty = 1;
				error = 0;
			}
		}
	}
	return error;
}

int modifyEmployee(Employee* list, int len)
{
	int error = -1;
	int id;
	int index;
	int option;
	char seguir;

	if(list != NULL && len > 0)
	{
		system("cls");
		printf("   *** MODIFICAR EMPLEADO ***   \n\n");
		printEmployees(list, len);
		printf("Ingrese el ID: ");
		scanf("%d", &id);

		index = findEmployeeById(list, len, id);

		if(index == -1)
		{
			printf("No existe una persona con ese legajo!\n\n");
		}else
		{
			printAnEmployee(list[index]);

			do{
				printf("Que desea modificar?\n\n");
				printf("1 ---> Nombre\n");
				printf("2 ---> Apellido\n");
				printf("3 ---> Salario\n");
				printf("4 ---> Sector\n");
				printf("5 ---> Volver atras\n");
				scanf("%d", &option);

				switch(option)
				{
					case 1:
						printf("Ingrese el nombre deseado: ");
						fflush(stdin);
						gets(list[index].name);
						printf("\n\nEl cambio de nombre ha sido realizado con exito!");
						system("pause");
						break;
					case 2:
						printf("Ingrese el apellido deseado: ");
						fflush(stdin);
						gets(list[index].lastName);
						printf("\n\nEl cambio de apellido ha sido realizado con exito!");
						system("pause");
						break;
					case 3:
						printf("Ingrese el salario deseado: ");
						scanf("%f", &list[index].salary);
						printf("\n\nEl cambio de salario ha sido realizado con exito!");
						system("pause");
						break;
					case 4:
						printf("Ingrese el sector deseado: ");
						scanf("%d", &list[index].sector);
						printf("\n\nEl cambio de sector ha sido realizado con exito!");
						system("pause");
						break;
					case 5:
						seguir = 'n';
						break;
					default:
						printf("\nLa opcion ingresada no existe!\n\n"); //validacion de las opciones disponibles
						system("pause");
						break;
				}
				error = 0;
			}while(seguir == 's');
		}
	}
	return error;
}

int sortEmployees(Employee* list, int len, int order)
{
	int error = -1;
	int auxInt;
	float auxFloat;
	char auxEmployee[51];

	if(list != NULL && len > 0 && order >= 0 && order <= 1)
	{
		for(int i=0; i<len-1; i++)
		{
			for(int j=i+1; j<len; j++)
			{
				if(list[i].sector > list[j].sector && order)
				{
					strcpy(auxEmployee, list[i].lastName);
					strcpy(list[i].lastName, list[j].lastName);
					strcpy(list[j].lastName, auxEmployee);

					strcpy(auxEmployee, list[i].name);
					strcpy(list[i].name, list[j].name);
					strcpy(list[j].name, auxEmployee);

					auxInt = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxInt;

					auxFloat = list[i].salary;
					list[i].salary = list[j].salary;
					list[j].salary = auxFloat;

					auxInt = list[i].sector;
					list[i].sector = list[j].sector;
					list[j].sector = auxInt;
				}
				else if(list[i].sector < list[j].sector && !order)
				{
					strcpy(auxEmployee, list[i].lastName);
					strcpy(list[i].lastName, list[j].lastName);
					strcpy(list[j].lastName, auxEmployee);

					strcpy(auxEmployee, list[i].name);
					strcpy(list[i].name, list[j].name);
					strcpy(list[j].name, auxEmployee);

					auxInt = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxInt;

					auxFloat = list[i].salary;
					list[i].salary = list[j].salary;
					list[j].salary = auxFloat;

					auxInt = list[i].sector;
					list[i].sector = list[j].sector;
					list[j].sector = auxInt;
				}else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName)>0 && order)
				{
					strcpy(auxEmployee, list[i].lastName);
					strcpy(list[i].lastName, list[j].lastName);
					strcpy(list[j].lastName, auxEmployee);

					strcpy(auxEmployee, list[i].name);
					strcpy(list[i].name, list[j].name);
					strcpy(list[j].name, auxEmployee);

					auxInt = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxInt;

					auxFloat = list[i].salary;
					list[i].salary = list[j].salary;
					list[j].salary = auxFloat;

					auxInt = list[i].sector;
					list[i].sector = list[j].sector;
					list[j].sector = auxInt;
				}else if(list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName)>0 && !order)
				{
					strcpy(auxEmployee, list[i].lastName);
					strcpy(list[i].lastName, list[j].lastName);
					strcpy(list[j].lastName, auxEmployee);

					strcpy(auxEmployee, list[i].name);
					strcpy(list[i].name, list[j].name);
					strcpy(list[j].name, auxEmployee);

					auxInt = list[i].id;
					list[i].id = list[j].id;
					list[j].id = auxInt;

					auxFloat = list[i].salary;
					list[i].salary = list[j].salary;
					list[j].salary = auxFloat;

					auxInt = list[i].sector;
					list[i].sector = list[j].sector;
					list[j].sector = auxInt;
				}
			}
		}
		error = 0;
	}
	return error;
}
