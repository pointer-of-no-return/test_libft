/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluque <lluque@student.42malaga.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 16:55:37 by lluque            #+#    #+#             */
/*   Updated: 2023/09/27 23:24:55 by lluque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../repo_github/libft.h"
#include "test_libft.h"
#define MAX_USR_INPUT_LINE_SIZE 100

void	*ft_print_memory(void *addr, unsigned int size);

void	ft_print_integer(void *integer)
{
	printf("\t\t\t\tEl entero es '%d'\n", *(int *)integer);
}

void	ft_lst_item_del(void *content)
{
	if (content == NULL)
		return ;
	free(content);
}

void	*ft_lst_item_cpy(void *content)
{
	void	*ret_val;

	if (content == NULL)
		return (NULL);
	ret_val = malloc(sizeof (content));
	*(int *)ret_val = *(int *)content;
	return (ret_val);
}

/*
void	*ft_add_thousand_to_integer(void *integer)
{
	*(int *)integer += 1000;
	return (
	//printf("\t\t\t\tEl entero es '%d'\n", *(int *)integer);
}
*/
char	ft_prueba(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
	return (' ');
}

void	ft_prueba2(unsigned int i, char *c)
{
	if (!(i % 2 == 0))
		*c = ' ';
}
/*
void	ft_printmem(void *ptr, size_t bytes)
{
	int	i;

	i = 0;
	while (i < bytes)
	{
		ft_putstr_fd(ft_itoa
	}
}
*/


int	main(int argc, char **argv)
{
	char	usr_input[MAX_USR_INPUT_LINE_SIZE];
	char	usr_input1[MAX_USR_INPUT_LINE_SIZE];
	char	usr_input2[MAX_USR_INPUT_LINE_SIZE];
	char	usr_input3[MAX_USR_INPUT_LINE_SIZE];
//	char	usr_input4[MAX_USR_INPUT_LINE_SIZE];


	printf("Introduzca el nombre de la funcion original a comparar con la version ft_\n");
	scanf("%s", usr_input);
	if(!ft_strncmp("isalpha", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		printf("\tProbando isalpha\n");
		return (0);
	}

	if(!ft_strncmp("memcpy", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		char	*lienzo_en_blanco;
		//char	*lienzo_en_negro;
						//    123456789012345678901234567890123456789
		char	texto[] = "Habia una vez un barquito chiquitito";
		char	texto2[] = "                                    ";

		printf("\tProbando memcpy\n");
		lienzo_en_blanco = ft_calloc(10, 16);
		ft_print_memory(lienzo_en_blanco, 10 * 16);	
		ft_memset(lienzo_en_blanco + 2 + 32, '@', 2);
		ft_memset(lienzo_en_blanco + 2 + 32 + 16, '@', 2);
		printf("\tPartiendo de esta area de memoria:\n");
		ft_print_memory(lienzo_en_blanco, 10 * 16);
		printf("\tEl memcpy produce:\n");
		ft_memcpy(lienzo_en_blanco + 10 + 96, lienzo_en_blanco + 2 + 32, 2);
		ft_memcpy(lienzo_en_blanco + 10 + 96 + 16, lienzo_en_blanco + 2 + 32 + 16, 2);
		ft_print_memory(lienzo_en_blanco, 10 * 16);
		
		printf("Ahora probando con un string\n");
		printf("\tEl origen:\n");
		ft_print_memory(texto - 32, 100);
		printf("\tEl destino:\n");
		ft_print_memory(texto2 - 32, 100);
		ft_memcpy(texto2 + 5, texto + 3, 15);
		printf("\tEl resultado:\n");
		ft_print_memory(texto2 - 32, 100);

		printf("Y con un substring del string original\n");
		printf("\tEl origen y destino (+5, 5 caracteres a copiar):\n");
		ft_print_memory(texto - 32, 100);
		ft_memcpy(texto + 5, texto, 5);
		printf("\tEl resultado:\n");
		ft_print_memory(texto - 32, 100);
		return (0);
	}


	if(!ft_strncmp("memmove", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
						//    123456789012345678901234567890123456789
		char	texto[] = "Habia una vez un barquito chiquitito";
		char	texto2[] = "Habia una vez un barquito chiquitito";
		char	texto3[] = "Habia una vez un barquito chiquitito";
		char	texto4[] = "Habia una vez un barquito chiquitito";

		printf("\tProbando memmove sin overlapping\n");
		printf("\tEl origen:\n");
		ft_print_memory(texto - 32, 100);
		ft_memmove(texto + 5, texto, 5);
		printf("\tEl resultado:\n");
		ft_print_memory(texto - 32, 100);

		printf("Probando memmove CON overlapping (destino antes de origen)\n");
		ft_print_memory(texto2 - 32, 100);
		ft_memmove(texto2, texto2 + 5, 10);
		printf("\tEl resultado:\n");
		ft_print_memory(texto2 - 32, 100);
	
		printf("Probando memmove CON overlapping (destino despues de origen)\n");
		ft_print_memory(texto3 - 32, 100);
		ft_memmove(texto3 + 5, texto3, 10);
		printf("\tEl resultado:\n");
		ft_print_memory(texto3 - 32, 100);

		printf("Probando memmove CON overlapping TOTAL\n");
		ft_print_memory(texto4 - 32, 100);
		ft_memmove(texto4, texto4, sizeof (texto4));
		printf("\tEl resultado:\n");
		ft_print_memory(texto4 - 32, 100);

		return (0);
	}

	if(!ft_strncmp("strlcpy", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		size_t	output;

		printf("\tProbando strlcpy\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tsize_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (un string o NULL)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		printf("\t\tIntroduzca el tercer argumento (un size_t)\n");
		scanf("%s", usr_input3);
		printf("\t\tRecibido '%s'\n", usr_input3);
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strlcpy(NULL, NULL, ft_atoi(usr_input3));
				printf("\t\tEl retorno es %zu y el string destino queda como '%s'\n", output, usr_input1);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strlcpy(NULL, usr_input2, ft_atoi(usr_input3));
				printf("\t\tEl retorno es %zu y el string destino queda como '%s'\n", output, usr_input1);
			}
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strlcpy(usr_input1, NULL, ft_atoi(usr_input3));
				printf("\t\tEl retorno es %zu y el string destino queda como '%s'\n", output, usr_input1);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strlcpy(usr_input1, usr_input2, ft_atoi(usr_input3));
				printf("\t\tEl retorno es %zu y el string destino queda como '%s'\n", output, usr_input1);
			}
		}
		return (0);
	}

	if(!ft_strncmp("strlcat", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		size_t	output;

		printf("\tProbando strlcat\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tsize_t  ft_strlcat(char *dst, const char *src, size_t dstsize);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (un string o NULL)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		printf("\t\tIntroduzca el tercer argumento (un size_t)\n");
		scanf("%s", usr_input3);
		printf("\t\tRecibido '%s'\n", usr_input3);
	

		char dest[30]; memset(dest, 0, 30);
		char * src = (char *)"AAAAAAAAA";
		int retorno;
		memset(dest, 'C', 5);
		retorno = ft_strlcat(dest, src, -1);
		printf("El destino queda '%s' y el retorno '%d'\n", dest, retorno);
	
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strlcat(NULL, NULL, ft_atoi(usr_input3));
				printf("\t\tEl retorno es %zu y el string destino queda como '%s'\n", output, usr_input1);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strlcat(NULL, usr_input2, ft_atoi(usr_input3));
				printf("\t\tEl retorno es %zu y el string destino queda como '%s'\n", output, usr_input1);
			}
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strlcat(usr_input1, NULL, ft_atoi(usr_input3));
				printf("\t\tEl retorno es %zu y el string destino queda como '%s'\n", output, usr_input1);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strlcat(usr_input1, usr_input2, ft_atoi(usr_input3));
				printf("\t\tEl retorno es %zu y el string destino queda como '%s'\n", output, usr_input1);
			}
		}
		return (0);
	}

	if(!ft_strncmp("strnstr", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		char	*output;

		printf("\tProbando strnstr\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tchar    *ft_strnstr(const char *haystack, const char *needle, size_t len);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (un string o NULL)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		printf("\t\tIntroduzca el tercer argumento (un size_t)\n");
		scanf("%s", usr_input3);
		printf("\t\tRecibido '%s'\n", usr_input3);
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strnstr(NULL, NULL, ft_atoi(usr_input3));
				printf("\t\tEl retorno es '%s'\n", output);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strnstr(NULL, usr_input2, ft_atoi(usr_input3));
				printf("\t\tEl retorno es '%s'\n", output);
			}
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strnstr(usr_input1, NULL, ft_atoi(usr_input3));
				printf("\t\tEl retorno es '%s'\n", output);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strnstr(usr_input1, usr_input2, ft_atoi(usr_input3));
				printf("\t\tEl retorno es '%s'\n", output);
				printf("\t\t\tEl retorno de la funcion original es '%s'\n", strnstr(usr_input1, usr_input2, ft_atoi(usr_input3)));
			}
		}
		return (0);
	}

	if(!ft_strncmp("strchr", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		char	*output;

		printf("\tProbando strchr\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tchar    *ft_strchr(const char *s, int c);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (caracter no numerico o un entero)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			if(ft_isdigit(usr_input2[0]))
			{
				printf("\t\tEl segundo argumento es un numero\n");
				output = ft_strchr(NULL, ft_atoi(usr_input2));
			}
			else
			{
				printf("\t\tEl segundo argumento es un caracter\n");
				output = ft_strchr(NULL, usr_input2[0]);
			}
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			if(ft_isdigit(usr_input2[0]))
			{
				printf("\t\tEl segundo argumento es un numero\n");
				output = ft_strchr(usr_input1, ft_atoi(usr_input2));
			}
			else
			{
				printf("\t\tEl segundo argumento es un caracter\n");
				output = ft_strchr(usr_input1, usr_input2[0]);
			}
		}
		printf("\tAhora se imprime el resultado: '%llu'\n", (unsigned long long)output);
		printf("\tQue seria el string: '%s'\n", output);
		return (0);
	}

	if(!ft_strncmp("strrchr", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		char	*output;

		printf("\tProbando strrchr\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tchar    *ft_strrchr(const char *s, int c);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (caracter no numerico o un entero)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			if(ft_isdigit(usr_input2[0]))
			{
				printf("\t\tEl segundo argumento es un numero\n");
				output = ft_strrchr(NULL, ft_atoi(usr_input2));
			}
			else
			{
				printf("\t\tEl segundo argumento es un caracter\n");
				output = ft_strrchr(NULL, usr_input2[0]);
			}
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			if(ft_isdigit(usr_input2[0]))
			{
				printf("\t\tEl segundo argumento es un numero\n");
				output = ft_strrchr(usr_input1, ft_atoi(usr_input2));
			}
			else
			{
				printf("\t\tEl segundo argumento es un caracter\n");
				output = ft_strrchr(usr_input1, usr_input2[0]);
			}
		}
		printf("\tAhora se imprime el resultado: '%llu'\n", (unsigned long long)output);
		printf("\tQue seria el string: '%s'\n", output);
		return (0);
	}

	if(!ft_strncmp("substr", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		char	*output;

		printf("\tProbando substr\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tchar *ft_substr(char const *s, unsigned int start, size_t len);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (un unsigned int)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		printf("\t\tIntroduzca el tercer argumento (un size_t)\n");
		scanf("%s", usr_input3);
		printf("\t\tRecibido '%s'\n", usr_input3);
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			output = ft_substr(NULL, ft_atoi(usr_input2), ft_atoi(usr_input3));
			printf("\tResulta el string: '%s'\n", output);
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			output = ft_substr(usr_input1, ft_atoi(usr_input2), ft_atoi(usr_input3));
			printf("\tResulta el string: '%s'\n", output);
			printf("\tCuyo strlen es: '%zu'\n", ft_strlen(output));
		}
		return (0);
	}

	if(!ft_strncmp("strjoin", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		char	*output;

		printf("\tProbando strjoin\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tchar *ft_strjoin(char const *s1, char const *s2);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (un string o NULL)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strjoin(NULL, NULL);
				printf("\t\tEl retorno es '%s'\n", output);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strjoin(NULL, usr_input2);
				printf("\t\tEl retorno es '%s'\n", output);
			}
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strjoin(usr_input1, NULL);
				printf("\t\tEl retorno es '%s'\n", output);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strjoin(usr_input1, usr_input2);
				printf("\t\tEl retorno es '%s'\n", output);
			}
		}
		return (0);
	}

	if(!ft_strncmp("strtrim", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		char	*output;

		printf("\tProbando strtrim\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tchar *ft_strtrim(char const *s1, char const *set);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (un string o NULL)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strtrim(NULL, NULL);
				printf("\t\tEl retorno es '%s'\n", output);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strtrim(NULL, usr_input2);
				printf("\t\tEl retorno es '%s'\n", output);
			}
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			if(!ft_strncmp("NULL", usr_input2, MAX_USR_INPUT_LINE_SIZE))
			{
				printf("\t\tEl segundo argumento es un NULL\n");
				output = ft_strtrim(usr_input1, NULL);
				printf("\t\tEl retorno es '%s'\n", output);
			}
			else
			{
				printf("\t\tEl segundo argumento es un string\n");
				output = ft_strtrim(usr_input1, usr_input2);
				printf("\t\tEl retorno es '%s'\n", output);
			}
		}
		return (0);
	}







	if(!ft_strncmp("split", usr_input, MAX_USR_INPUT_LINE_SIZE))
	{
		char	**output;

		printf("\tProbando split\n");
		printf("\t\tPrototipo:\n");
		printf("\t\tchar    **ft_split(char const *s, char c);\n");
		printf("\t\tIntroduzca el primer argumento (un string o NULL)\n");
		scanf("%s", usr_input1);
		printf("\t\tRecibido '%s'\n", usr_input1);
		printf("\t\tIntroduzca el segundo argumento (caracter no numerico o un entero)\n");
		scanf("%s", usr_input2);
		printf("\t\tRecibido '%s'\n", usr_input2);
		if(!ft_strncmp("NULL", usr_input1, MAX_USR_INPUT_LINE_SIZE))
		{
			printf("\t\tEl primer argumento es un NULL\n");
			if(ft_isdigit(usr_input2[0]))
			{
				printf("\t\tEl segundo argumento es un numero\n");
				output = ft_split(NULL, ft_atoi(usr_input2));
			}
			else
			{
				printf("\t\tEl segundo argumento es un caracter\n");
				output = ft_split(NULL, usr_input2[0]);
			}
		}
		else
		{
			printf("\t\tEl primer argumento es un string\n");
			if(ft_isdigit(usr_input2[0]))
			{
				printf("\t\tEl segundo argumento es un numero\n");
				output = ft_split(usr_input1, ft_atoi(usr_input2));
			}
			else
			{
				printf("\t\tEl segundo argumento es un caracter\n");
				output = ft_split(usr_input1, usr_input2[0]);
			}
		}
		int	i;
		i = 0;
		printf("\tAhora se imprime el resultado\n");
		while (output[i] != NULL)
		{
			ft_putendl_fd(output[i], 1);
			i++;
		}
		return (0);
	}
	printf("Prueba no implementada por los momentos\n");
	return (0);
























	if (argc != 4)
	{
		printf("Error en cantidad de parametros, debe ser:\n");
		printf("\t... %% tester un_caracter un_string un_entero\n");
		return (1);
	}
	printf("\n");

	ft_test_isalpha(argv[1][0]);
	ft_test_isalpha(-352);
	ft_test_isalpha(0);

	ft_test_isdigit(argv[1][0]);
	ft_test_isdigit(-352);
	ft_test_isdigit(0);

	ft_test_isalnum(argv[1][0]);
	ft_test_isalnum(-352);
	ft_test_isalnum(0);

	ft_test_isascii(argv[1][0]);
	ft_test_isascii(-352);
	ft_test_isascii(0);

	ft_test_isprint(argv[1][0]);
	ft_test_isprint(-352);
	ft_test_isprint(0);

	ft_test_atoi(argv[3]);
	//ft_test_atoi(NULL);					// Ambas versiones dan seg fault
	ft_test_atoi("");
	ft_test_atoi("  	23fsdf sdfsdf");
	ft_test_atoi("12345678901234567890");	///Discrepancia detectada
	ft_test_atoi("-12345678901234567890");

	ft_test_strlen(argv[2]);
	//ft_test_strlen(NULL);					// Ambas versiones dan seg fault
	ft_test_strlen("");						

	char original[] = "Hola! esto es una prueba para ver el contenido de memoria. Esto es una tabulacion '\t' y esto una nueva linea '\n'";

	char    ft[] = "Hola! esto es una prueba para ver el contenido de memoria. Esto es una tabulacion '\t' y esto una nueva linea '\n'";
	ft_test_memset(original + 15, ft + 15, '@', 5);	
	ft_test_memset(original + 25, ft + 25, '@', 0);
	//ft_test_memset(NULL, NULL, '@', 10);	// Ambas versiones dan seg fault


	char original_b[] = "Hola! esto es una prueba para ver el contenido de memoria. Esto es una tabulacion '\t' y esto una nueva linea '\n'";

	char    ft_b[] = "Hola! esto es una prueba para ver el contenido de memoria. Esto es una tabulacion '\t' y esto una nueva linea '\n'";
	ft_test_bzero(original_b + 1, ft_b + 1, 5);
	ft_test_bzero(original_b + 17, ft_b + 17, 5);
	//ft_test_bzero(NULL, NULL, 5);	// Ambas versiones dan seg fault

	printf("\n\nAhora se probara el calloc:\n");
	
	char	*lienzo_en_blanco;
	char	*lienzo_en_negro;

	lienzo_en_blanco = ft_calloc(10, 16);	// Ambas versiones dan un puntero válido con 0,0 x,0 0,y (por malloc
										// La calloc original reserva e inicializa en bloques de 16 siempre
										// (no hay que replicar ese comportamiento)
	printf("El sizeof de char es '%lu'\n", sizeof (char));
	printf("El sizeof de short es '%lu'\n", sizeof (short));
	printf("El sizeof de int es '%lu'\n", sizeof (int));
	printf("El sizeof de long es '%lu'\n", sizeof (long));
	printf("El sizeof de long long es '%lu'\n", sizeof (long long));
	printf("El sizeof de float es '%lu'\n", sizeof (float));
	printf("El sizeof de double es '%lu'\n", sizeof (double));
	printf("El sizeof de la variable es '%lu'\n", sizeof (*lienzo_en_blanco));
	printf("Imprimiendo lienzo original (dir: '%#lx')\n", (long unsigned)lienzo_en_blanco);
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	
	printf("\n\nAhora se probara el memset:\n");

	lienzo_en_negro = malloc(10 * 16 * sizeof (char));
	ft_memset(lienzo_en_negro, 64, 10 * 16);
	printf("Imprimiendo lienzo en negro (dir: '%#lx')\n", (long unsigned)lienzo_en_negro);
	ft_print_memory(lienzo_en_negro, 10 * 16);
	
	//ft_memset(lienzo_en_negro + 2, 0, 14);
	//ft_memset(lienzo_en_negro + 2 + 16, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 32, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 48, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 64, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 64 + 16, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 64 + 32, 0, 12);
	ft_memset(lienzo_en_negro + 2 + 64 + 48, 0, 12);
	//ft_memset(lienzo_en_negro + 2 + 64 + 64, 0, 12);
	printf("Cuadrado blanco en lienzo negro (dir: '%#lx')\n", (long unsigned)lienzo_en_negro);
	ft_print_memory(lienzo_en_negro, 10 * 16);
	
	printf("Memset con casos raros\n");
	//ft_memset(lienzo_en_blanco + 17, '*', 1);
	//ft_memset(lienzo_en_blanco + 17, '*', 0);
	printf("\tCaso 1:\n");
	ft_memset(lienzo_en_blanco + 17, '*', (0));		// Ambas bien, no hacen nada con len=0
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	printf("\tCaso 2:\n");
	ft_memset(lienzo_en_blanco + 17, -64, 5);
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	ft_memset(lienzo_en_blanco + 17, 0, 5);
	printf("\tCaso 3:\n");
	memset(lienzo_en_blanco + 17, -64, 5);			// Valores negativos interpretados idénticamente
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	printf("\tCaso 4:\n");
	//memset(NULL, '*', 5);
	//ft_memset(NULL, '*', 5);						// Ambas versiones explotan con NULL
	ft_print_memory(lienzo_en_blanco, 10 * 16);
	


	return (0);
	char    *block_calloc1;
	char    *block_calloc2;
	char    *block_calloc3;

	block_calloc2 = ft_calloc(30, 0);
	block_calloc1 = ft_calloc(30, 0);
	printf("Imprimiendo block_calloc1 (dir: '%#lx')\n", (long unsigned)block_calloc1);
	ft_print_memory(block_calloc1, 30);
	block_calloc2 = malloc(30 * sizeof (char));
	ft_memset(block_calloc2, 64, 30);
	block_calloc3 = calloc(30, 1);
	printf("Imprimiendo block_calloc3 (dir: '%#lx')\n", (long unsigned)block_calloc3);
	ft_print_memory(block_calloc3, 30);
	printf("\n");

	return (0);
	int	itoa_nbr;
	itoa_nbr = 2147483647;
	printf("El entero '%d' con ft_itoa se convierte en '%s'\n", itoa_nbr, ft_itoa(itoa_nbr));
	itoa_nbr = 0;
	printf("El entero '%d' con ft_itoa se convierte en '%s'\n", itoa_nbr, ft_itoa(itoa_nbr));
	itoa_nbr = -2147483648;
	printf("El entero '%d' con ft_itoa se convierte en '%s'\n", itoa_nbr, ft_itoa(itoa_nbr));
	itoa_nbr = ft_atoi(argv[3]);
	printf("El string '%s' que pasado por ft_atoi se vuelve '%d' con ft_itoa se convierte en '%s'\n", argv[3], itoa_nbr, ft_itoa(itoa_nbr));
	printf("\n");
	
	printf("Ahora se probara el bonus\n");
	int	*lst_contenido;
	t_list	*lst_item;
	t_list	*lst_first_item;
	int	lst_i;
	int	lst_contenido_temp;

	lst_contenido = malloc(1 * sizeof (int));
	*lst_contenido = 69;
	lst_item = ft_lstnew(lst_contenido);
	lst_first_item = lst_item;
	printf("\tCreado el primer nodo '%lu' con contenido '%d'\n", (unsigned long)lst_first_item, *(int *)lst_first_item->content);
	printf("\tLa lista tiene ahora '%d' elementos\n", ft_lstsize(lst_first_item));
	lst_i = 1;
	while (lst_i < 10)
	{
		lst_contenido_temp = *lst_contenido;
		lst_contenido = malloc(1 * sizeof(int));
		*lst_contenido = lst_contenido_temp + 10;
		lst_item = ft_lstnew(lst_contenido);
		printf("\tCreado el nodo '%lu' con contenido '%d'\n", (unsigned long)lst_item, *(int *)lst_item->content);
		ft_lstadd_back(&lst_first_item, lst_item);
		printf("\t\tAgregado  el nodo '%lu' al FINAL de la  lista '%lu'\n", (unsigned long)lst_item, (unsigned long)lst_first_item);
		printf("\tLa lista tiene ahora '%d' elementos\n", ft_lstsize(lst_first_item));
		lst_i++;
	}

	printf("\tAhora se añadirán elementos al inicio de la lista\n");
	*lst_contenido = 59;
	lst_i = 1;
	while (lst_i < 10)
	{
		lst_contenido_temp = *lst_contenido;
		lst_contenido = malloc(1 * sizeof(int));
		*lst_contenido = lst_contenido_temp - 10;
		lst_item = ft_lstnew(lst_contenido);
		printf("\tCreado el nodo '%lu' con contenido '%d'\n", (unsigned long)lst_item, *(int *)lst_item->content);
		ft_lstadd_front(&lst_first_item, lst_item);
		printf("\t\tAgregado el nodo '%lu' al COMIENZO de la lista '%lu'\n", (unsigned long)lst_item, (unsigned long)lst_first_item);
		printf("\tLa lista tiene ahora '%d' elementos\n", ft_lstsize(lst_first_item));
		lst_i++;
	}
	printf("Ahora se iterara por todos los elementos imprimiendo el contenido\n");
	ft_lstiter(lst_first_item, ft_print_integer);
	
	printf("Ahora se creara una copia de la lista\n");
	t_list	*new_list;

	new_list = ft_lstmap(lst_first_item, ft_lst_item_cpy, ft_lst_item_del);
	
	printf("Este es el contenido de la lista original\n");
	ft_lstiter(lst_first_item, ft_print_integer);
	
	printf("Este es el contenido de la nueva lista\n");
	ft_lstiter(new_list, ft_print_integer);

	printf("Ahora se borrara la nueva lista completamente\n");
	ft_lstclear(&new_list, ft_lst_item_del);

	return (0);
}
