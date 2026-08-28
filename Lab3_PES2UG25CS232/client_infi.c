#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

int precedence(char op)
{
	if(op == '^')
		return 3;

	if(op == '*' || op == '/')
		return 2;

	if(op == '+' || op == '-')
		return 1;

	return 0;
}

int is_operator(char ch)
{
	if(ch == '+' || ch == '-' || ch == '*' ||
	   ch == '/' || ch == '^')
		return 1;

	return 0;
}

int is_left_associative(char ch)
{
	if(ch == '^')
		return 0;

	return 1;
}

void convert(char *infix, char *postfix)
{
	stack_t stack;
	int i = 0;
	int j = 0;
	char ch;
	char top;

	init_stack(&stack);

	while(infix[i] != '\0')
	{
		ch = infix[i];

		if(ch == ' ' || ch == '\t')
		{
			i++;
			continue;
		}

		/* Variable or identifier */
		if(isalpha(ch))
		{
			while(isalnum(infix[i]) || infix[i] == '_')
			{
				postfix[j] = infix[i];
				j++;
				i++;
			}

			postfix[j] = ' ';
			j++;
			continue;
		}

		/* Number */
		if(isdigit(ch))
		{
			while(isalnum(infix[i]) || infix[i] == '_')
			{
				postfix[j] = infix[i];
				j++;
				i++;
			}

			postfix[j] = ' ';
			j++;
			continue;
		}

		/* Opening bracket */
		if(ch == '(')
		{
			push(&stack, ch);
		}

		/* Closing bracket */
		else if(ch == ')')
		{
			while(!is_empty(&stack) && peek(&stack) != '(')
			{
				postfix[j] = pop(&stack);
				j++;
				postfix[j] = ' ';
				j++;
			}

			if(is_empty(&stack))
			{
				printf("Error: unmatched parenthesis\n");
				postfix[0] = '\0';
				deinit_stack(&stack);
				return;
			}

			pop(&stack);
		}

		/* Operator */
		else if(is_operator(ch))
		{
			while(!is_empty(&stack))
			{
				top = peek(&stack);

				if(top == '(')
					break;

				if(precedence(top) > precedence(ch))
				{
					postfix[j] = pop(&stack);
					j++;
					postfix[j] = ' ';
					j++;
				}
				else if(precedence(top) == precedence(ch) &&
				        is_left_associative(ch))
				{
					postfix[j] = pop(&stack);
					j++;
					postfix[j] = ' ';
					j++;
				}
				else
				{
					break;
				}
			}

			push(&stack, ch);
		}

		else
		{
			printf("Error: invalid token\n");
			postfix[0] = '\0';
			deinit_stack(&stack);
			return;
		}

		i++;
	}

	while(!is_empty(&stack))
	{
		top = pop(&stack);

		if(top == '(')
		{
			printf("Error: unmatched parenthesis\n");
			postfix[0] = '\0';
			deinit_stack(&stack);
			return;
		}

		postfix[j] = top;
		j++;
		postfix[j] = ' ';
		j++;
	}

	postfix[j] = '\0';

	deinit_stack(&stack);
}

int main()
{
	char infix[200];
	char postfix[400];
	int f = 1;

	while(f)
	{
		printf("infix> ");

		if(fgets(infix, sizeof(infix), stdin) == NULL)
			break;

		infix[strcspn(infix, "\n")] = '\0';

		if(strlen(infix) == 0)
		{
			printf("Error: empty expression\n");
		}
		else
		{
			convert(infix, postfix);

			if(strlen(postfix) != 0)
				printf("Postfix = %s\n", postfix);
		}

		printf("Continue (n-0/s-1)> ");
		scanf("%d", &f);

		/* Remove leftover newline from scanf */
		while(getchar() != '\n');
	}

	return 0;
}