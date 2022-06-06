/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RoyRBTINSERTrules.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: areggie <areggie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:02:01 by areggie           #+#    #+#             */
/*   Updated: 2022/06/05 14:03:22 by areggie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	the insertion by Roy is another file"
	I watched the video of Roy about RBT INSERTION https://www.youtube.com/watch?v=UaLIHuR1t8Q
	after watching Rob's vidoes, it is kind of good time of repetition (the logics is the same)

	I also made  time code:
	Thank you, Mr.Tushar Roy! Clear explanation!
	I kind of double checked with you the rules I learned from Rob Edwards (he gave pseudocode here: https://www.youtube.com/watch?v=nMExd4DthdA), but Rob did not give deletion.:
	13:30 red aunt/uncle leads to ColorFlip (RBB in the triangle of grandparent) after insertion, 
	14:03 black aunt/uncle causes LR - Rotation
	14:52 LR-Rotation (first stage - L), dont change colors
	16:17 LR-Rotation (second stage - R: dragging to right),  ColorFlip (BRR) after rotation
	23:25 Example of a tree with pseudocode!!! Great.
	30:34 Time complexity analysis
	31:51 Code of RBT in Java (it is not easy to understand, need to spend time here)
	36:54 This code is more understandable

*/