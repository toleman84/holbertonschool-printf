Readme File

Description
function that recreates the function of the library stdio.h printf

How it works: the function receives the arguments pased when the function is called and compares with an array of structures if the function find a sign of percentage, the structure contains functions that receives %d, %i, %c and %s and converts them like printf does.

If the function not receives a percentage sign, the function only print the string.

If the function find a percentage sign but the variable dosen´tmatch with a variable of the array the function goes to print the percentage and the variabe.

if the function receives a percentage sing and a variable incluided in the array but the argument passed to the variable is incompatible, the function returns error

Example

a simple example of how to print Hello World with _printf

	#include "main.h"

	**/_printf - Function that mimics the function defined by stdio.h printf.
	*@format: The arguments passed to the function.
	*Return: the count of byte that will be printed.

	int main(void)
	{
	_printf("Hello World");
	return(0);
	}	

Authors File
Andrés Maciel and Gustavo Ponce Marsiglia

