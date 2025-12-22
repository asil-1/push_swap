/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truck_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldepenne <ldepenne@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 20:41:20 by ldepenne          #+#    #+#             */
/*   Updated: 2025/12/22 21:19:01 by ldepenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*calcul du cout pour passer mon chiffre target en haut de la stack*/
int	move_to_the_top(int nb, t_list **stack)
{
	/*
	* def l'index
	* compter le nb de mouv (r ou rr selon l'index)
	* qu'il faut que mon target atteigne le sommet
	*/
}

/*init du top of cost pour chaque nb
* chaque nb dans la pile b
* les targets des nb
*	essayer de ne les compter qu'une fois s'ils se repetent
* quand on cree la node, init le total cost et le top of cost a la position de la node dans la stack
*/
void	init_cost(t_list **stack_a, t_list **stack_b)
{
	t_list	*b;

	b = *stack_b;
	while (b) /*quand la fonciton sera faite, doit pouvoir attribuer le top_of_cost de chaue node dans b*/ /*PS ne pas oublier d'init lors de la creation de la node*/
	{
		b->top_of_cost = move_to_the_top(b->content, stack_b);
		b = b->next;
	}
	/*
	* idealement, j'aurais pre defini mes targets
	* chauqe node peut contenir son target
	* hypothese :
	* parcour tous les targets
		ou alors
			je me les initioalisent pas des le debut et je calul le cout que pour ceux qui n'ont pas ete initalise
			ca m'evite de calculer deux fois le meme
			ca veut aussi dire qu'avamt de refaire la boucle ils doivent tous etre remis a null
	*/
}
