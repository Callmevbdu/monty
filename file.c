#include "monty.h"

/**
 * openFile - a function which opens a file.
 * @fileName: path/name of file.
 * Return: void.
*/

void openFile(char *fName)
{
    FILE *fDesc = fopen(fName, "r");

    if (fName == NULL || fDesc == NULL)
        error(2, fName);

    readFile(fDesc);
    fclose(fDesc);
}

/**
 * readFile - a function which reads a file.
 * @fDesc: file descriptor.
 * Return: void.
*/

void readFile(FILE *fDesc)
{
    int lineN, format = 0;
    char *buff = NULL;
    size_t length = 0;

    for (lineN = 1; getline(&buff, &length, fDesc) != -1; lineN++)
    {
        format = resolveLine(buff, lineN, format);
    }

    free(buff);
}

/**
 * resolveLine - a function that cuts the command into tokens.
 * @buff: reads line by line from a file.
 * @lineN: the line number.
 * @type: storage type (stack/queue).
 * Return: "0" if stack, "1" if queue.
*/

int resolveLine(char *buff, int lineN, int type)
{
    char *opCode, *idx;
	const char *dlm = "\n ";

	if (buff == NULL)
		error(4);

	opCode = strtok(buff, dlm);
	if (opCode == NULL)
		return (type);
	idx = strtok(NULL, dlm);

	if (strcmp(opCode, "stack") == 0)
		return (0);
	if (strcmp(opCode, "queue") == 0)
		return (1);

	functionFind(opCode, idx, lineN, type);
	return (type);
}

/**
 * functionFind - a function which finds the correct operation code.
 * @opCode: operation code.
 * @idx: argument of the opcode.
 * @type: storage type (stack/queue).
 * @lineN: the line number.
 * Return: void
 */

void functionFind(char *opCode, char *idx, int lineN, int type)
{
	int x;
	int flag;

	instruction_t functionList[] = {
		{"push", stackAdd},
		{"pall", stackPrint},
		{"pop", stackPopTop},
		{"pint", stackPrintTop},
		{"nop", nop},
		{"swap", nodeSwap},
		{"add", nodeAdd},
		{"sub", nodeSub},
		{"div", nodeDiv},
		{"mul", nodeMul},
		{"mod", nodeMod},
		{"pchar", printChar},
		{"pstr", printStr},
		{"rotl", rotateL},
		{"rotr", rotateR},
		{NULL, NULL}
	};

	if (opCode[0] == '#')
		return;

	for (flag = 1, x = 0; functionList[x].opcode != NULL; x++)
	{
		if (strcmp(opCode, functionList[x].opcode) == 0)
		{
			functionCall(functionList[x].f, opCode, idx, lineN, type);
			flag = 0;
		}
	}
	if (flag == 1)
		error(3, lineN, opCode);
}


/**
 * functionCall - a function that selects the required function.
 * @func: function to be called.
 * @opCode: operation code.
 * @idx: index input to operation.
 * @lineN: line numeber.
 * @type: storage type (stack/queue).
 */
void functionCall(op_func func, char *opCode, char *idx, int lineN, int type)
{
	stack_t *node;
	int flag;
	int i;

	flag = 1;
	if (strcmp(opCode, "push") == 0)
	{
		if (idx != NULL && idx[0] == '-')
		{
			idx = idx + 1;
			flag = -1;
		}
		if (idx == NULL)
			error(5, lineN);
		for (i = 0; idx[i] != '\0'; i++)
		{
			if (isdigit(idx[i]) == 0)
				error(5, lineN);
		}
		node = nodeCreate(atoi(idx) * flag);
		if (type == 0)
			func(&node, lineN);
		if (type == 1)
			queueAdd(&node, lineN);
	}
	else
		func(&first, lineN);
}
