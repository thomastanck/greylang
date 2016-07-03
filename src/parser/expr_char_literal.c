#include "../parser.h"

#include <stdlib.h>

l_p_expr_char_literal* l_parse_expr_char_literal(l_scanner* stream)
{
	l_p_expr_char_literal* expr = malloc(sizeof(l_p_expr_char_literal));

	// char literal
	l_token c = l_scanner_expect(stream, TOKEN_CHAR_LITERAL, "char literal");
	expr->character = c.content[0];

	return expr;
}

void l_pretty_expr_char_literal(
		l_p_expr_char_literal* expr,
		int depth,
		FILE* file)
{
	char* tabs;
	P_TABS(depth, tabs);
	fprintf(file, "%s'%c'", tabs, expr->character);
}