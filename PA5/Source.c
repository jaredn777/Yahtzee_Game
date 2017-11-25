/*************************************************************************************************
* Programmer: Jared Nichols                                                                      *
* Class: CptS 121, Fall 2016; Lab Section 2                                                      *
* Programming Assignment: Programming Assignment 5: Yahtzee game                                   *
* Date:                                                                                          *
*                                                                                                *
* Description: This page runs the functions of the program
*                                                                      *
*                                                                                                *
*                                                                                                *
*                                                                                                *
*                                                                                                *
*                                                                                                */


#include "header.h"


int PrintTitle(void)

{
	system("cls");
	printf(" /$$     /$$        /$$         /$$                        \n");
	printf("|  $$   /$$/       | $$        | $$           \n");
	printf(" \\  $$ /$$//$$$$$$ | $$$$$$$  /$$$$$$  /$$$$$$$$  /$$$$$$   /$$$$$$  \n");
	printf("  \\  $$$$/|____  $$| $$__  $$|_  $$_/ |____ /$$/ /$$__  $$ /$$__  $$    \n");
	printf("   \\  $$/  /$$$$$$$| $$  \\ $$  | $$      /$$$$/ | $$$$$$$$| $$$$$$$$  \n");
	printf("    | $$  /$$__  $$| $$  | $$  | $$ /$$ /$$__/  | $$_____/| $$_____/    \n");
	printf("    | $$ |  $$$$$$$| $$  | $$  |  $$$$//$$$$$$$$|  $$$$$$$|  $$$$$$$  \n");
	printf("    |__/  \\_______/|__/  |__/   \\___/ |________/ \\_______/ \\_______/   \n");
	printf("                                                       \n");
	printf("                ______     \n");
	printf("  .-------.    /\\     \\   \n");
	printf(" /   o   /|   /o \\  o  \\  \n");
	printf("/_______/o|  /   o\\_____\\ \n");
	printf("| o     | |  \\o   /o    / \n");
	printf("|   o   |o/   \\ o/  o  /  \n");
	printf("|     o |/     \\/____o/   \n");
	printf("'-------'\n\n\n");

	int choice;

	printf("1. Play\n");
	printf("2. View Rules\n");
	printf("3. Exit\n");
	scanf("%d", &choice);

	return choice;


}


void print_game_rules(void)
{
	system("cls");
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.");
	printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.");
	printf("The lower section contains a number of poker like combinations.");
	system("pause");



}
void roll_dice(int dice[], int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		dice[index] = rand() % 6 + 1;
	}
}
void roll_dice_hold(int dice[], int size, int chosenDies[], int size1)
{

	int i = 0;
	for (int index = 0; index < size; ++index, ++i)
	{
 		if (chosenDies[i] == 0)
		{
			dice[index] = rand() % 6 + 1;
			

		}
	}
}
void print_dice(int *dice_ptr, int size)
{
	int index = 0;

	for (index = 0; index < size; ++index)
	{
		printf("die %d: %d\n", index + 1, *(dice_ptr + index));
	}
}
void count_dice(int dice[], int size, int dice_value_count[], int size_count)
	{
		int index = 0, new_index = 0;

		while (index < size)
		{
			new_index = dice[index++];
			dice_value_count[new_index] += 1;
		}
	}

int sum_num(int value, int n)
{
	return value * n;
}




// just for you drew
void Scorecard(int ScoreUsedBefore[], int size, int ScoreUsedBefore2[], int size2)
{
	
	printf("        scorecard options!       \n\n");
	printf("a number '1' indicates the option has been used\n");
	printf("a number '0' indicates the option has not been used\n\n");

	printf(" 1. ACES: Count and add only aces.     PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[1], ScoreUsedBefore2[1]);
	printf(" 2. TWOS: Count and add only twos.     PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[2], ScoreUsedBefore2[2]);
	printf(" 3. THREES:Count and add only threes.  PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[3], ScoreUsedBefore2[3]);
	printf(" 4. FOURS:Count and add only four.     PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[4], ScoreUsedBefore2[4]);
	printf(" 5. FIVES:Count and add only fives.    PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[5], ScoreUsedBefore2[5]);
	printf(" 6. Sixes: Count and add only sixes.   PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[6], ScoreUsedBefore2[6]);
	printf(" 7. 3 of a Kind:add total of all die.  PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[7], ScoreUsedBefore2[7]);
	printf(" 8. 4 of a Kind:add total of all die.  PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[8], ScoreUsedBefore2[8]);
	printf(" 9. Full house: Score 25.              PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[9], ScoreUsedBefore2[9]);
	printf(" 10. Small Straight: sequence of 4.    PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[10], ScoreUsedBefore2[10]);
	printf(" 11. Large straight: sequence of 5.    PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[11], ScoreUsedBefore2[11]);
	printf(" 12. YAHTZEE: 5 of a kind.             PLAYER 1 used = %d PLAYER 2 used = %d\n", ScoreUsedBefore[12], ScoreUsedBefore2[12]);
	printf(" 13.Chance: score total of all die.    PLAYER 1 used = %d PLAYER 2 used = %d\n\n", ScoreUsedBefore[13], ScoreUsedBefore2[13]);
	


}

int Scorecard1(int score_card_p1[], int size, int score_card_p2[], int size1, int round)
{
	int Bonus = 0;
	int UpperScore = score_card_p1[1] + score_card_p1[2] + score_card_p1[3] + score_card_p1[4] + score_card_p1[5] + score_card_p1[6];
	int LowerScore = score_card_p1[7] + score_card_p1[8] + score_card_p1[9] + score_card_p1[10] + score_card_p1[11] + score_card_p1[12] + score_card_p1[13];
	int grandtotal = UpperScore + LowerScore;
	if (UpperScore >= 63)
	{
		Bonus = bonus;
		UpperScore += Bonus;
	}
	int Bonus2 = 0;
	int UpperScore2 = score_card_p2[1] + score_card_p2[2] + score_card_p2[3] + score_card_p2[4] + score_card_p2[5] + score_card_p2[6];
	int LowerScore2 = score_card_p2[7] + score_card_p2[8] + score_card_p2[9] + score_card_p2[10] + score_card_p2[11] + score_card_p2[12] + score_card_p2[13];
	int grandtotal2 = UpperScore2 + LowerScore2;
	if (UpperScore2 >= 63)
	{
		Bonus2 = bonus;
		UpperScore2 += Bonus2;
	}


	printf("your scores have been updated!");
	printf("                     YAHTZEE SCORE CARD\n");
	printf("_____________________________________________________________________________\n");                         
	printf("| UPPER SECTION |                   |  Player 1              Player 2        \n");
	printf("|_______________|___________________|________________________________________\n");
	printf("| 1. ACES: Count and add only aces  |   %d                         %d        \n", score_card_p1[1], score_card_p2[1]);
	printf("|___________________________________|________________________________________\n");
	printf("| 2.TWOS: Count and add only twos   |   %d                         %d        \n", score_card_p1[2], score_card_p2[2]);
	printf("|___________________________________|________________________________________\n");
	printf("| 3.THREES:Count and add only threes|   %d                         %d        \n", score_card_p1[3], score_card_p2[3]);
	printf("|___________________________________|________________________________________\n");
	printf("| 4.FOURS:Count and add only fours  |   %d                         %d        \n", score_card_p1[4], score_card_p2[4]);
	printf("|___________________________________|________________________________________\n");
	printf("| 5.FIVES:Count and add only fives  |   %d                         %d        \n", score_card_p1[5], score_card_p2[5]);
	printf("|___________________________________|________________________________________\n");
	printf("| 6.Sixes: Count and add only sixes |   %d                         %d        \n", score_card_p1[6], score_card_p2[6]);
	printf("|___________________________________|________________________________________\n");
	printf("| BONUS + 35: if score is 63 or over|   %d                         %d        \n", Bonus, Bonus2);
	printf("|___________________________________|________________________________________\n");
	printf("| Total Upper Score:                |   %d                         %d        \n", UpperScore, UpperScore2);
	printf("|___________________________________|________________________________________\n");
	printf("| LOWER SECTION                     |                                        \n");
	printf("|___________________________________|________________________________________\n");
	printf("| 7.3 of a Kind:add total of all die|   %d                         %d        \n", score_card_p1[7], score_card_p2[7]);
	printf("|___________________________________|________________________________________\n");
	printf("| 8.4 of a Kind:add total of all die|   %d                         %d        \n", score_card_p1[8], score_card_p2[8]);
	printf("|___________________________________|________________________________________\n");
	printf("| 9.Full house: Score 25            |   %d                         %d        \n", score_card_p1[9], score_card_p2[9]);
	printf("|___________________________________|________________________________________\n");
	printf("| 10.Small Straight: sequence of 4  |   %d                         %d        \n", score_card_p1[10], score_card_p2[10]);
	printf("|___________________________________|________________________________________\n");
	printf("| 11.Large straight: sequence of 5  |   %d                         %d        \n", score_card_p1[11], score_card_p2[11]);
	printf("|___________________________________|________________________________________\n");
	printf("| 12. YAHTZEE: 5 of a kind          |   %d                         %d        \n", score_card_p1[12], score_card_p2[12]);
	printf("|___________________________________|________________________________________\n");
	printf("| 13.Chance: score total of all die |   %d                         %d        \n", score_card_p1[13], score_card_p2[13]);
	printf("|___________________________________|________________________________________\n");
	printf("|Total Lower Score:                 |   %d                         %d        \n", LowerScore, LowerScore2);
	printf("|___________________________________|________________________________________\n");
	printf("| GRAND TOTAL:                      |   %d                         %d        \n", grandtotal, grandtotal2);
	printf("|___________________________________|________________________________________\n");

	system("pause");
	if (round == 26)
	{
		if (grandtotal >= grandtotal2)
		{
			//if there is a tie player 1 wins by default because everyone knows player 1 is better than player 2
			system("cls");
			printf("Player 1 ended the game with a score of %d\nplayer 2 ended the game with a score of %d\n", grandtotal, grandtotal2);
			return  PLAYER1WINS;

		}
		else
		{
		    system("cls");
			printf("Player 2 ended the game with a score of %d\nplayer 1 ended the game with a score of %d\n", grandtotal2, grandtotal);
			return PLAYER2WINS;
		}

	}
	return NULL;
}
//this function adds the values up of an array for chance, 3 and 4 of kind rolls
int sum_array(int dice[], int size1)
{
	int sum = 0;
	for (int index = 0; index < size1; index++)
	{
		sum += dice[index];

	}


		return sum;
}
// these three functions determine if the dice count of the roll is correct for the particular option the user selected
int fullhouse(int dicevaluecount[], int size)
{
	int three = 0;
	int two = 0;
	for (int i = 0; i < 7; i++)
	{
		if (dicevaluecount[i] == 3)
		{
			three = YES;
		}
		if (dicevaluecount[i] == 2)
		{
			two = YES;
		}
	
	}
	if ((three == YES) && (two == YES))
	{
		return YES;
	}
}
int smallstraight(int dicevaluecount[], int size)
{
	int number_of_dice = 0, result = 0;

	for (int index = 0; index < 7; index++)
	{
		if (dicevaluecount[index] > 0)
		{
			number_of_dice++;
		}
	}
	if (number_of_dice >= 4)
	{
		result = YES;
	}
	
	return result;
	
	
}
int largestraight(int dicevaluecount[], int size)
{
	int number_of_dice = 0, result = 0;

	for (int index = 0; index < 7; index++)
	{
		if (dicevaluecount[index] > 0)
		{
			number_of_dice++;
		}
	}
	if (number_of_dice == 5)
	{
		result = YES;
	}

	return result;
}
int whosturnisitanyway(int round)
{
	
		int mod = 0;
		mod = round % 2;
		return mod;
}
//these functions determine if the player recieves the correct amount of points for thier roll and adds the points to thier card after
void player1Sums(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize)
{


	system("cls");
	printf("Sum of %d's!\n", scorecard);
	system("pause");
	ScoreUsedBefore[scorecard] = 1;
	score_card_p1[scorecard] = sum_num(dicevaluecount[scorecard], scorecard);
}

void player2Sums(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize)
{

	system("cls");
	printf("Sum of %d's!\n", scorecard);
	system("pause");
	ScoreUsedBefore2[scorecard] = 1;
	score_card_p2[scorecard] = sum_num(dicevaluecount[scorecard], scorecard);

}
void player1case7(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize, int dice[], int Dsize)
{

	system("cls");
	for (int i = 0; i < 7; i++)
	{
		if (dicevaluecount[i] >= 3)
		{
			printf("You got a three of a kind!\n");
			system("pause");
			score_card_p1[scorecard] = sum_array(dice, 5);
			ScoreUsedBefore[scorecard] = 1;

		}
		else
			ScoreUsedBefore[scorecard] = 1;
	}
}
void player2case7(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize, int dice[], int Dsize)
{
	
	system("cls");
	for (int i = 0; i < 7; i++)
	{
		if (dicevaluecount[i] >= 3)
		{
			printf("You got a three of a kind!\n");
			system("pause");
			score_card_p2[scorecard] = sum_array(dice, 5);
			ScoreUsedBefore2[scorecard] = 1;

		}
		else
			ScoreUsedBefore2[scorecard] = 1;
	}
}

void player1case8(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize, int dice[], int Dsize)
{
	

	system("cls");
	for (int i = 0; i < 7; i++)
	{
		if (dicevaluecount[i] >= 4)
		{
			printf("You got a Four of a kind!\n");
			system("pause");
			score_card_p1[scorecard] = sum_array(dice, 5);
			ScoreUsedBefore[scorecard] = 1;

		}
		else
			ScoreUsedBefore[scorecard] = 1;

	}
}

void player2case8(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize, int dice[], int Dsize)
{
	

	system("cls");
	for (int i = 0; i < 7; i++)
	{
		if (dicevaluecount[i] >= 4)
		{
			printf("You got a Four of a kind!\n");
			system("pause");
			score_card_p2[scorecard] = sum_array(dice, 5);
			ScoreUsedBefore2[scorecard] = 1;
		}
		else
			ScoreUsedBefore2[scorecard] = 1;
	}
}
void player1FullHouse(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize)
{
	int is_fullhouse = 0;
	system("cls");
	is_fullhouse = fullhouse(dicevaluecount, 7);
	if (is_fullhouse == YES)
	{
		printf(" You got a Full House!\n");
		system("pause");

		score_card_p1[scorecard] = FULLHOUSE;
	}

	ScoreUsedBefore[scorecard] = 1;



}

void player2FullHouse(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize)
{
	int is_fullhouse = 0;
	system("cls");
	is_fullhouse = fullhouse(dicevaluecount, 7);
	if (is_fullhouse == YES)
	{
		printf(" You got a Full House!\n");
		system("pause");

		score_card_p2[scorecard] = FULLHOUSE;
	}

	ScoreUsedBefore2[scorecard] = 1;
	
}

void player1SmallStraight(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize)
{
	int is_smallstraight = 0;
	system("cls");
	is_smallstraight = smallstraight(dicevaluecount, 7);
	if (is_smallstraight == YES)
	{
		printf("You got a Small Straight!\n");
		system("pause");

		score_card_p1[scorecard] = SmallStraight;
	}
	ScoreUsedBefore[scorecard] = 1;
}
void player2SmallStraight(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize)
{
	int is_smallstraight = 0;
	system("cls");
	is_smallstraight = smallstraight(dicevaluecount, 7);
	if (is_smallstraight == YES)
	{
		printf("You got a Small Straight!\n");
		system("pause");

		score_card_p2[scorecard] = SmallStraight;
	}
	ScoreUsedBefore2[scorecard] = 1;
}
void player1LargeStraight(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize)
{
	int is_largestraight = 0;
	system("cls");
	is_largestraight = largestraight(dicevaluecount, 7);
	if (is_largestraight == YES)
	{
		printf("You got a Large Straight!\n");
		system("pause");

		score_card_p1[scorecard] = LargeStraight;
	}
	ScoreUsedBefore[scorecard] = 1;

}
void player2LargeStraight(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize)
{
	int is_largestraight = 0;
	system("cls");
	is_largestraight = largestraight(dicevaluecount, 7);
	if (is_largestraight == YES)
	{
		printf("You got a Large Straight!\n");
		system("pause");

		score_card_p2[scorecard] = LargeStraight;
	}
	ScoreUsedBefore2[scorecard] = 1;

}
void player1YAHTZEE(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize)
{
	
	system("cls");
	for (int i = 0; i < 7; i++)
	{
		if (dicevaluecount[i] == 5)
		{
			printf("You got a YAHTZEE!!!\n");
			system("pause");

			score_card_p1[scorecard] = YAHTZEE;
		}
		
	}

	




}

void player2YAHTZEE(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize)
{
	
	system("cls");
	for (int i = 0; i < 7; i++)
	{
		if (dicevaluecount[i] == 5)
		{
			printf("You got a YAHTZEE!!!\n");
			system("pause");

			score_card_p2[scorecard] = YAHTZEE;
		}
		

	}

}
void player1Chance(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dice[], int Dsize)
{
	
	score_card_p1[scorecard] = sum_array(dice, 5);
	ScoreUsedBefore[scorecard] = 1;


}

void player2Chance(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dice[], int Dsize)
{

	
	score_card_p2[scorecard] = sum_array(dice, 5);
	ScoreUsedBefore2[scorecard] = 1;


}











