/*
 * funcionesCalculadora.c
 *
 *  Created on: 12 sep. 2020
 *      Author: Pazos Ezequiel
 */

float sumar(float a, float b)
{
	return(a + b);
}

float restar(float a, float b)
{
	return(a - b);
}

float dividir(float a, float b)
{
	return (a / b);
}

float multiplicar(float a, float b)
{
	return(a * b);
}

int factorear(int a)
{
	int factorial;

    if(a < 0)
    {
    	return -1;
    }
    else
    {
    	if(a == 1 || a == 0)
		{
			factorial = 1;
		}
		else
		{
			factorial = a * factorear(a - 1);
		}
    }

    return factorial;
}

