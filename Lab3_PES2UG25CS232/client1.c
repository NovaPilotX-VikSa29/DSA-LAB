#include <stdio.h>
#include <string.h>
#include "stack.h"

int find_power(int num, int exp)
{
	int ans = 1;

	while(exp > 0)
	{
		ans = ans * num;
		exp--;
	}

	return ans;
}

int evaluate(char *expr)
{
	stack_t stack;
	int first, second;
	int number = 0;
	int readingNumber = 0;
	int pos = 0;

	init_stack(&stack);

	while(expr[pos] != '\0')
	{
		char symbol = expr[pos];

		if(symbol >= '0' && symbol <= '9')
		{
			number = number * 10 + (symbol - '0');
			readingNumber = 1;
		}
		else if(symbol == ' ' || symbol == '\t')
		{
			if(readingNumber)
			{
				push(&stack, number);
				number = 0;
				readingNumber = 0;
			}
		}
		else if(symbol == '+' || symbol == '-' || symbol == '*' ||
		        symbol == '/' || symbol == '^')
		{
			if(readingNumber)
			{
				push(&stack, number);
				number = 0;
				readingNumber = 0;
			}

			if(is_empty(&stack))
			{
				printf("Error: stack underflow\n");
				deinit_stack(&stack);
				return 0;
			}

			first = pop(&stack);

			if(is_empty(&stack))
			{
				printf("Error: stack underflow\n");
				deinit_stack(&stack);
				return 0;
			}

			second = pop(&stack);

			switch(symbol)
			{
				case '+':
					push(&stack, second + first);
					break;

				case '-':
					push(&stack, second - first);
					break;

				case '*':
					push(&stack, second * first);
					break;

				case '/':
					if(first == 0)
					{
						printf("Error: division by zero\n");
						deinit_stack(&stack);
						return 0;
					}

					push(&stack, second / first);
					break;

				case '^':
					if(first < 0)
					{
						printf("Error: invalid exponent\n");
						deinit_stack(&stack);
						return 0;
					}

					push(&stack, find_power(second, first));
					break;
			}
		}
		else if(symbol != '\n')
		{
			printf("Error: invalid token\n");
			deinit_stack(&stack);
			return 0;
		}

		pos++;
	}

	if(readingNumber)
	{
		push(&stack, number);
	}

	if(is_empty(&stack))
	{
		printf("Error: empty expression\n");
		deinit_stack(&stack);
		return 0;
	}

	number = pop(&stack);

	if(!is_empty(&stack))
	{
		printf("Error: too many operands\n");
		deinit_stack(&stack);
		return 0;
	}

	deinit_stack(&stack);
	return number;
}

int main()
{
	char expression[100];
    int f=1;

	while(f)
	{
		printf("postfix> ");

		if(fgets(expression, sizeof(expression), stdin) == NULL)
			break;

		expression[strcspn(expression, "\n")] = '\0';

		if(strcmp(expression, "exit") == 0 ||
		   strcmp(expression, "quit") == 0)
		{
			break;
		}

		printf("Result = %d\n", evaluate(expression));

        printf("Continue (n-0/s-1)> ");  scanf("%d",&f);
	}
 
	return 0;
}