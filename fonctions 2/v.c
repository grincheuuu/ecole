Pour generer automatiquement votre libft.h:
cat libft.h.template.begin > libft.h
grep -Eh '.*	ft_.*\(.*\)' *.c | sed 's/$/;/' >> libft.h
cat libft.h.template.end >> libft.h
Et mettez votre header +
#ifndef LIBFT_H
# define LIBFT_H
dans libft.h.template.begin
et #endif dans libft.h.template.end
