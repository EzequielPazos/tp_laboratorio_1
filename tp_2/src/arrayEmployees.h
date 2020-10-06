/*
 * arrayEmployees.h
 *
 *  Created on: 3 oct. 2020
 *      Author: Pazos Ezequiel
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

}typedef Employee;

#endif /* ARRAYEMPLOYEES_H_ */

/** \brief  To indicate that all position in the array are empty,
* 			this function put the flag (isEmpty) in TRUE in all
* 			position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order);

/** \brief print the content of employees array
*
* \param list Employee*
* \param len int
* \return int
*
*/
int printEmployees(Employee* list, int len);

/**
 * @brief shows a custom options menu on screen
 * @return int returns the selected option
 */
int showMenu();

/**
 * @brief finds the first empty position for an employee to be added
 * @param list Employee*
 * @param len int
 * @return int returns the index of the first empty slot in the employee array
 */
int findEmpty(Employee* list, int len);

/**
 * @brief modifies any data from an employee
 * @param list Employee*
 * @param len int
 * @return returns -1 if Error[Non-existent ID] or 0 if an employee was found
 */
int modifyEmployee(Employee* list, int len);

/**
 * @brief prints data from only one employee
 * @param anEmployee
 */
void printAnEmployee(Employee anEmployee);
