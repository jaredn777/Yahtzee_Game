/*************************************************************************************************
* Programmer: Jared Nichols                                                                      *
* Class: CptS 121, Fall 2016; Lab Section 2                                                      *
* Programming Assignment: Programming Assignment 5: Yahtzee game                                   *
* Date:                                                                                          *
*                                                                                                *
* Description: This program runs a game of yahtzee for the user, keeping track of the score card and  *
* points earned by the user                                                                         *
*                                                                                                *
*                                                                                                *
*                                                                                                *
*                                                                                                *
*                                                                                                */





#include "header.h"

int main(void)
{
	//general main local variables 
	int choice = 0, roll_count = 0, scorecard = 0, rollagain = 0, totalturns = 0, round= 0, hold = 0, holddies = 0, mod=0, winner = 0;
	//arrays 
 int dice[5] = { 0 }, dice_value_count[7] = { 0 },  
		score_card_p1[14] = { 0 },
	    score_card_p2[14] = { 0 },
		score_used_before[14] = { 0 }, option = 0;	
      int  score_used_before2[14] = { 0 };
 // scorecard option local variables 


	choice = PrintTitle();
	srand((unsigned int)time(NULL));

	do
	{
		
		if (choice == RULES)
		{
			print_game_rules();
			system("cls");
			choice = PrintTitle();

		}


		if (choice == PLAY)
		{
			while (round <= 26)
			{
				mod = whosturnisitanyway(round);
				
				system("cls");
				if (mod == 0)
				{
					printf("Player 1's turn!\n\n\n");
				}
				else printf("playes 2's turn!\n\n\n");

				system("pause");
				    system("cls");
					printf("press enter to roll the dice!\n");
					system("pause");
					system("cls");
					roll_count += ROLL;
					printf("roll %d results!\n", roll_count);
					roll_dice(dice, 5);
					print_dice(dice, 5);
					system("pause");
					

					while (roll_count < 3)
					{
						printf("would you like to hold any of your dice? if you want to save all dice\nthen select no.\n1.Yes or 2.No\n");
						scanf("%d", &hold);
						//variables for parrallel array
						int chosenDies[5] = { 0 };
						while (hold!=YES && hold!=NO)
						{
							fseek(stdin, 0, SEEK_END);
							system("cls");
							printf("SORRY,THATS NOT CORRECT!\n");
							printf("try again\n");
							system("pause");
							system("cls");
							print_dice(dice, 5);
							printf("would you like to hold any of your dice? if you want to save all dice then select no.\n1.Yes or 2.No\n");
							scanf("%d", &hold);

						}
						if (hold == YES)
						{

							for (int i = 0; i < 5; i++)
							{
								printf("would you like to save die %d?\n1.Yes or 2.No\n", i + 1);
								scanf("%d", &holddies);
								while (holddies != YES && holddies != NO)
								{
									fseek(stdin, 0, SEEK_END);
									system("cls");
									printf("Please select the numeric value 1 or 2\n");
									printf("try again\n");
									system("pause");
									system("cls");
									print_dice(dice, 5);
									printf("would you like to save die %d?\n1.Yes or 2.No\n", i + 1);
									scanf("%d", &holddies);
								}
								if (holddies == YES)
								{
									chosenDies[i] = 1;

								}
								holddies = 0;
							}
							system("cls");
							printf("press enter to roll the dice!\n");
							system("pause");
							system("cls");
							roll_count += ROLL;
							printf("roll %d results!\n", roll_count);
							roll_dice_hold(dice, 5, chosenDies, 5);
							print_dice(dice, 5);
							system("pause");

						}
						else if (hold == NO)
						{
							printf("roll again?\n1.Yes or 2.No\n");
							scanf("%d", &rollagain);
							while (rollagain != YES && rollagain != NO)
							{
								fseek(stdin, 0, SEEK_END);
								system("cls");
								printf("user error checking isn't even on the rubric...\n");
								system("pause");
								system("cls");
								print_dice(dice, 5);
								printf("roll again?\n1.Yes or 2.No\n");
								scanf("%d", &rollagain);

							}
							if (rollagain == NO)
							{
								break;
							}
							system("cls");
							printf("press enter to roll the dice!\n");
							system("pause");
							system("cls");
							roll_count += ROLL;
							printf("roll %d results!\n", roll_count);
							roll_dice(dice, 5);
							print_dice(dice, 5);
							system("pause");
						}
						hold = 0;
					}

					//get scorecard option from user
					printf("Select an option from the score card and get points!\n");
					system("pause");
					system("cls");
					print_dice(dice, 5);
					Scorecard(score_used_before, 14, score_used_before2, 14);
					printf("please select an numerical option from the scorecard\n");
					scanf("%d", &scorecard);
					if (mod == 0)
					{
						while (score_used_before[scorecard] == 1)
						{
							system("cls");
							printf("You have already selected this option. there is literally a list of the options you picked presented for you.\n");
							printf("try again\n");
							system("pause");
							system("cls");
							print_dice(dice, 5);
							Scorecard(score_used_before, 14, score_used_before2, 14);
							printf("please select an numerical option from the scorecard\n");
							scanf("%d", &scorecard);
						}
					      while ((scorecard !=1) && (scorecard !=2) && (scorecard !=3) && (scorecard != 4) && (scorecard !=5) && (scorecard !=6) && (scorecard !=7) && (scorecard !=8) && (scorecard !=9) && (scorecard !=10) && (scorecard !=11) && (scorecard !=12) && (scorecard !=13))
						{
							fseek(stdin, 0, SEEK_END);
							system("cls");
							printf("Please select an actual option\n");
							printf("try again\n");
							system("pause");
							system("cls");
							scorecard = 0;
							print_dice(dice, 5);
							Scorecard(score_used_before, 14, score_used_before2, 14);
							printf("please select an numerical option from the scorecard\n");
							scanf("%d", &scorecard);
						}

					}
					else 
					{
						while (score_used_before2[scorecard]==1)
						{
						
							system("cls");
							printf("You have already selected this option. there is literally a list of the options you picked presented for you.\n");
							printf("try again\n");
							system("pause");
							system("cls");
							print_dice(dice, 5);
							Scorecard(score_used_before, 14, score_used_before2, 14);
							printf("please select an numerical option from the scorecard\n");
							scanf("%d", &scorecard);
						}//i never asked for this
						while ((scorecard != 1) && (scorecard != 2) && (scorecard != 3) && (scorecard != 4) && (scorecard != 5) && (scorecard != 6) && (scorecard != 7) && (scorecard != 8) && (scorecard != 9) && (scorecard != 10) && (scorecard != 11) && (scorecard != 12) && (scorecard != 13))
						{
							fseek(stdin, 0, SEEK_END);
							system("cls");
							printf("Please select an actual option\n");
							printf("try again\n");
							system("pause");
							system("cls");
							scorecard = 0;
							print_dice(dice, 5);
							Scorecard(score_used_before, 14, score_used_before2, 14);
							printf("please select an numerical option from the scorecard\n");
							scanf("%d", &scorecard);
						}

					}
					//add points to scorecard
					count_dice(dice, 5, dice_value_count, 7);
					// each of the posible options of the scorecard, a check of previous use comes first
					switch (scorecard)
					{
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:

						if (mod == 0)
						{
						player1Sums(score_card_p1, 14, score_used_before, 14, scorecard, dice_value_count, 7);

						}
						else
						{
						player2Sums(score_card_p2, 14, score_used_before2, 14, scorecard, dice_value_count, 7);
						}

						break;

					case 7:

						if (mod == 0)
						{
							player1case7(score_card_p1, 14, score_used_before, 14, scorecard, dice_value_count, 7, dice, 5);

						}
						else
						{
							player2case7(score_card_p2, 14, score_used_before2, 14, scorecard, dice_value_count, 7, dice, 5);
						}

						break;

					case 8:


						if (mod == 0)
						{
							player1case8(score_card_p1, 14, score_used_before, 14, scorecard, dice_value_count, 7, dice, 5);

						}
						else
						{
							player2case8(score_card_p2, 14, score_used_before2, 14, scorecard, dice_value_count, 7, dice, 5);
						}

						break;

					case 9:
						if (mod == 0)
						{
							player1FullHouse(score_card_p1, 14, score_used_before, 14, scorecard, dice_value_count, 7);
						}
						else
						{
							player2FullHouse(score_card_p2, 14, score_used_before2, 14, scorecard, dice_value_count, 7);
						}


						break;

					case 10:

						if (mod == 0)
						{
							player1SmallStraight(score_card_p1, 14, score_used_before, 14, scorecard, dice_value_count, 7);
						}
						else
						{
							player2SmallStraight(score_card_p2, 14, score_used_before2, 14, scorecard, dice_value_count, 7);
						}
						break;

					case 11:
						if (mod == 0)
						{
							player1LargeStraight(score_card_p1, 14, score_used_before, 14, scorecard, dice_value_count, 7);
						}
						else
						{
							player2LargeStraight(score_card_p2, 14, score_used_before2, 14, scorecard, dice_value_count, 7);
						}

						break;

					case 12:
						if (mod == 0)
						{
							player1YAHTZEE(score_card_p1, 14, score_used_before, 14, scorecard, dice_value_count, 7);
						}
						else
						{
							player2YAHTZEE(score_card_p1, 14, score_used_before2, 14, scorecard, dice_value_count, 7);
						}


						break;

					case 13:
						if (mod == 0)
						{
							player1Chance(score_card_p1, 14, score_used_before, 14, scorecard, dice_value_count, 7);
						}
						else
						{
							player2Chance(score_card_p1, 14, score_used_before2, 14, scorecard, dice_value_count, 7);
						}
						break;
						system("pause");
					}
					system("cls");
					roll_count = 0;
					for (int index = 0; index < 7; index++)
					{
						dice_value_count[index] = 0;
					}
					////computes the winner and prints the result then breaks from the loop and restarts
					winner = Scorecard1(score_card_p1, 14, score_card_p2, 14, round);
					if (winner == PLAYER1WINS) 
					{
						
						printf("PLAYER 1 WINS!");
						system("pause");
						system("cls");
						round = 0;
						break;
					
					}
					else if (winner == PLAYER2WINS)
					{
						
						printf("PLAYER 2 WINS!");
						system("pause");
						system("cls");
						round = 0;
						break;
						
					}
					else
					{
						round++;
					}

				}
				choice = PrintTitle();
		}
			
			

		if (choice == EXIT)
		{

			return 0;

		}
		else if (choice !=1 && choice !=2 && choice !=3)
		{
			fseek(stdin, 0, SEEK_END);
			system("cls");
			printf("the choices were 1, 2 and 3. what did you think was going to happen?\n");
			printf("try again\n");
			system("pause");
			system("cls");
	        choice = PrintTitle();


		}
		



		} 
		while (choice != EXIT);
	
}