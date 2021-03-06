#include "../parser.h"

#include <stdlib.h>

l_p_arg_definition* l_parse_arg_definition(l_scanner* stream)
{
	int namea = 4;
	l_p_arg_definition* list = malloc(sizeof(l_p_arg_definition));
	list->names = malloc(namea * sizeof(char*));
	list->namec = 0;

	// Empty argument definition
	l_token t = l_scanner_peek(stream);
	if (t.type == TOKEN_CLOSEPAREN)
		return list;

	while (1)
	{
		// name
		l_token name = l_scanner_expect(stream, TOKEN_NAME, "arg definition");
		list->namec += 1;
		if (namea < list->namec)
		{
			namea *= 2;
			list->names = realloc(list->names, namea * sizeof(char*));
		}
		list->names[list->namec - 1] = name.content;

		// , or )
		l_token next = l_scanner_peek(stream);
		if (next.type == TOKEN_COMMA)
		{
			l_scanner_skip(stream, TOKEN_COMMA, "arg definition");
		}
		else if (next.type == TOKEN_CLOSEPAREN)
		{
			break;
		}
		else
		{
			l_token_type expected[] = {
				TOKEN_COMMA,
				TOKEN_CLOSEPAREN
			};
			l_scanner_unexpecteda(expected, 2, next, "arg definition");
		}
	}

	return list;
}

void l_pretty_arg_definition(
		l_p_arg_definition* arg_definition,
		int depth,
		FILE* file)
{
	for (int i = 0; i < arg_definition->namec; ++i)
	{
		fprintf(file, "%s", arg_definition->names[i]);
		if (i + 1 < arg_definition->namec)
		{
			fprintf(file, ", ");
		}
	}
}
