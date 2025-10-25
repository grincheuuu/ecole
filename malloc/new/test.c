#include <unistd.h>
#include <string.h>

static int	ft_limit(int n, int fd)
{
	write (fd, "-", 1);
	write (fd, "2", 1);
	n = 147483648;
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		div;
	int		mod;

	c = 0;
	if (n == -2147483648)
		n = ft_limit(n, fd);
	if (n < 0)
	{
		n *= -1;
		write (fd, "-", 1);
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 0 && n <= 9)
	{
		c = '0' + n;
		write (fd, &c, 1);
	}
	else
	{
		div = n / 10;
		mod = n % 10;
		ft_putnbr_fd(div, fd);
		ft_putnbr_fd(mod, fd);
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	l;

	l = ft_strlen(s);
	write (fd, s, l);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
		i++;
	dest = malloc((i + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (s[j] != '\0')
	{
		dest[j] = s[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int main(void)
{
    char    *str;
    char    larg[100];
	char	**tab;
	char	**tab2;
	char    *str2;
	char	*str3;
	char	c;

/*    for (int i = 0; i < 99; i++)
        larg[i] = 'q';
    larg[99] = '\0';
	tab = malloc(201 * sizeof(char *));
	if (tab == NULL)
		return 1;
    for (int j = 0; j < 200; j++)
        tab[j] = ft_strdup(larg);
	tab[200] = NULL;
	for (int j = 0; tab[j] != NULL; j++)
	{
		free(tab[j]);
		write(1,"\n\n\n", 1);
	}
	free(tab);
	char	*ko[41];
	for (int i = 0; i < 40; i++)
		ko[i] = strdup("kokokokoffffffffffffffggggggggggggggggko");
	ko[40] = NULL;
	for (int i = 0; ko[i] != NULL; i++)
		free(ko[i]);
	free(ko);*/
//	str  = ft_strdup("hello word");
//	free(str);
//	str = NULL;
	str2 = malloc(3101);
	for (int i = 0; i < 3100; i++)
        str2[i] = 'q';
	str2[3100] = '\0';
	char **bb2;
	bb2 = malloc((11) * sizeof(char *));
	if (bb2 == NULL)
	{
		write(1, "error\n", 6);
		return 1;
	}
	for (int k = 0; k < 10; k++)
		bb2[k] = ft_strdup(str2);
	bb2[10] = NULL;
	for (int k = 0; bb2[k] != NULL; k++)
		free(bb2[k]);
//	free(bb2);
//	free(str2);
/*	str3 = malloc(150001);
	for (int i = 0; i < 150000; i++)
        str3[i] = 'q';
	str3[150000] = '\0';
	char **bb3;
	bb3 = malloc((11) * sizeof(char *));
	if (bb3 == NULL)
	{
		write(1, "error\n", 6);
		return 1;
	}
	for (int k = 0; k < 10; k++)
	{
		write(1, "\n", 1);
		ft_putnbr_fd(k, 1);
		write(1, "\n", 1);
		bb3[k] = ft_strdup(str3);
	}
	bb3[10] = NULL;*/
//	for (int k = 0; bb3[k] != NULL; k++)
//		free(bb3[k]);
//	free(bb3);
//	free(str3);
//	malloc(1);
//	free(bb2);
/*	char	*a1 = ft_strdup("hello");
	char	*a2 = ft_strdup("hello word");
	char	*a3 = ft_strdup("jjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj");
	realloc(a1, 100);
	realloc(a2, 200);
	realloc(a3, 400);*/
//	free(str2);
/*	char *zo;
	zo = ft_strdup(str2);
	realloc(zo, 100000);
	malloc(300000);
	malloc(300000);
	malloc(300000);
	malloc(300000);
	malloc(140000);
	malloc(240000);
	malloc(340000);
	malloc(40000);
	malloc(40000);
	malloc(30000);
	tab2 = malloc((11) * sizeof(char *));
	if (tab2 == NULL)
		write(1, "error\n", 6);
	for (int k = 0; k < 10; k++)
		tab2[k] = ft_strdup("hello word");
	tab2[10] = NULL;
	for (int k = 0; tab2[k] != NULL; k++)
		free(tab2[k]);
	free(tab2);
	malloc(1);
	realloc(tab2, 1400);
	malloc(1000);
	malloc(1900);*/
//	malloc(1);
    return 0;
}
/*
t_block *create_block_page(size_t page_size, size_t *in_stock)
{
    void *mem = mmap(NULL, page_size, PROT_READ | PROT_WRITE,
                     MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mem == MAP_FAILED)
    {
        ft_putstr_fd("mmap failed: ", 2);
        ft_putstr_fd(strerror(errno), 2);
        ft_putstr_fd("\n", 2);
        return NULL;
    }

    t_block *head = (t_block *)mem;
    head->size = page_size - sizeof(t_block); // payload available in this first block
    head->occupe = 0;
    head->debut_page = 1;
    head->next = NULL;

    if (in_stock)
        *in_stock += head->size;

    return head;
}*/

/*
 * allocate at the start of the free block `block`.
 * len_zone is total requested (header + payload), aligned.
 * returns pointer to payload (i.e. (char*)allocated + sizeof(t_block))
 */
/*
void *ft_first_allocate_block(t_block *block, size_t len_zone, size_t *in_stock)
{
    if (block == NULL) return NULL;

    size_t want_payload = len_zone - sizeof(t_block);

    if (block->size < want_payload)
        return NULL;

    size_t remaining_payload = block->size - want_payload;

    // if after allocating we can create a remaining free block (enough room for header+min payload),
    // we split; else allocate the whole block.
    if (remaining_payload >= (ssize_t) (sizeof(t_block) + 16))
    {
        // reuse current header 'block' as allocated block
        t_block *allocated = block;
        // compute address of remaining free block header
        t_block *remain = (t_block *)((char *)allocated + sizeof(t_block) + want_payload);
        // initialize remaining free block
        remain->size = remaining_payload - sizeof(t_block); // payload remaining
        remain->occupe = 0;
        remain->debut_page = 0;
        remain->next = allocated->next;

        // set allocated metadata
        allocated->size = want_payload; // payload
        allocated->occupe = 1;
        allocated->debut_page = allocated->debut_page; // keep debut flag on allocated if it was start
        allocated->next = remain;

        if (in_stock)
            *in_stock -= (want_payload + sizeof(t_block));

        return (void *)((char *)allocated + sizeof(t_block));
    }
    else
    {
        // not enough space to split: allocate whole block
        block->occupe = 1;
        // we consider no remain block: next stays as-is.
        if (in_stock)
            *in_stock -= block->size;
        return (void *)((char *)block + sizeof(t_block));
    }
}*/

/* Example split for arbitrary free block: carve len_zone from beginning of free block */
/*
void *ft_split_block(t_block *free_block, size_t len_zone, size_t *in_stock)
{
    if (free_block == NULL) return NULL;
    size_t want_payload = len_zone - sizeof(t_block);

    if (free_block->size < want_payload) return NULL;

    size_t remaining_payload = free_block->size - want_payload;

    if (remaining_payload >= (ssize_t)(sizeof(t_block) + 16))
    {
        // allocate at start of free_block, create remain after it
        t_block *allocated = free_block;
        t_block *remain = (t_block *)((char *)allocated + sizeof(t_block) + want_payload);

        remain->size = remaining_payload - sizeof(t_block);
        remain->occupe = 0;
        remain->debut_page = 0;
        remain->next = allocated->next;

        allocated->size = want_payload;
        allocated->occupe = 1;
        allocated->next = remain;

        if (in_stock)
            *in_stock -= (want_payload + sizeof(t_block));
        return (void *)((char *)allocated + sizeof(t_block));
    }
    else
    {
        // allocate whole free_block
        free_block->occupe = 1;
        if (in_stock)
            *in_stock -= free_block->size;
        return (void *)((char *)free_block + sizeof(t_block));
    }
}*/
