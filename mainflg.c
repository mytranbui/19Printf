/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainflg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbui <mbui@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 08:37:27 by mbui              #+#    #+#             */
/*   Updated: 2020/09/21 11:02:08 by mbui             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *format, ...);

int	main(void)
{
	int		i = 42;

	ft_printf("%hhLilol", i);
	ft_printf("\n");
	ft_printf("%+- # 0i", i);
	ft_printf("\n");
	ft_printf("%53.0i", i);
	ft_printf("\n");
	ft_printf("%+i", i);
	ft_printf("\n");
	ft_printf("% - 4520-+li", i);
	ft_printf("\n");
	ft_printf("%35.0 i", i);
	ft_printf("\n");
	ft_printf("%0 #-++hhLi", i);
	ft_printf("\n");
	ft_printf("%-43.53i", i);
	ft_printf("\n");
//	ft_printf("%hlhlli", i);
	ft_printf("\n");

	ft_printf("%+- # 0 hhllLi", i);
	ft_printf("\n");
	ft_printf("%L53.0i", i);
	ft_printf("\n");
//	ft_printf("%lL+i", i);
	ft_printf("\n");
//	ft_printf("% - l4520-l+", i);
	ft_printf("\n");
	ft_printf("%L35. i", i);
	ft_printf("\n");
	ft_printf("%0 #-++hhLi", i);
	ft_printf("\n");
	ft_printf("%-+43.53+i", i);
	//ft_printf("\n");
	//ft_printf("%7452hi", i);
	return (0);
}
