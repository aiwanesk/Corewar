#include <stdlib.h>
#include <struct_lex.h>

static t_lex	*st_get(void)
{
	static t_lex		lex = {CMD, 0x00, 0, 0x00};

	return (&lex);
}

t_lex			*get_lex(void)
{
	t_lex		*lex;

	lex = st_get();
	return (lex->next);
}

void			new_lex(char *code, enum e_type type, int ligne)
{
	t_lex		*new;
	t_lex		*lex;

	lex = st_get();
	new = (t_lex *)malloc(sizeof(t_lex));
	new->ligne = ligne;
	new->type = type;
	new->code = code;
	new->next = 0x00;
	while (lex->next)
		lex = lex->next;
	lex->next = new;
}

void			free_lex(void)
{
	t_lex		*lex;
	t_lex		*temp;

	lex = get_lex();
	while (lex)
	{
		temp = lex;
		lex = lex->next;
		temp->code = 0x00;
		temp->next = 0x00;
		free(temp);
	}
}
