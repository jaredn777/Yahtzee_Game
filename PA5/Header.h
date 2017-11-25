/*************************************************************************************************
* Programmer: Jared Nichols                                                                      *
* Class : CptS 121, Fall 2016; Lab Section 2 *
* Programming Assignment : Programming Assignment 5 : Yahtzee game                                   *
* Date : *
*                                                                                                *
* Description : This page Defines the functions of the program and includes serveral standard libraries
*                                                                      *
*                                                                                                *
*                                                                                                *
*                                                                                                *
*                                                                                                *
*/




#ifndef PA5_H
#define PLAY 1
#define RULES 2
#define EXIT 3
#define ROLL 1
#define YES 1
#define NO 2
#define FULLHOUSE 25
#define YAHTZEE 50
#define SmallStraight 30
#define LargeStraight 40
#define bonus 35
#define PLAYER1WINS 90
#define PLAYER2WINS 80
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> 

#endif
int PrintTitle(void);
void print_game_rules(void);
void roll_dice(int dice[], int size);
void roll_dice_hold(int dice[], int size, int chosenDies[], int size1);
void print_dice(int *dice_ptr, int size);
void count_dice(int dice[], int size, int dice_value_count[], int size_count);
int sum_num(int value, int n);
int sum_array(int dice[], int size1);
int fullhouse(int dice_value_count[], int size);
int smallstraight(int dice_value_count[], int size);
int largestraight(int dice_value_count[], int size);
int whosturnisitanyway(int round);

// and then he made fuctions for each players scorecard option and it was really fun, there was probably an easier way to do this but fuck it
void Scorecard(int ScoreUsedBefore[], int size, int ScoreUsedBefore2[],int size2);
int Scorecard1(int score_card_p1[], int size, int score_card_p2[], int size1, int round);
void player1Sums(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize);
void player2Sums(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize);
void player1case7(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize, int dice[], int Dsize);
void player2case7(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize, int dice[], int Dsize);
void player1case8(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize, int dice[], int Dsize);
void player2case8(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize, int dice[], int Dsize);
void player1FullHouse(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize);
void player2FullHouse(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize);
void player1SmallStraight(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize);
void player2SmallStraight(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize);
void player1LargeStraight(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dicevaluecount[], int DVCsize);
void player2LargeStraight(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize);
void player1YAHTZEE(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize);
void player2YAHTZEE(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dicevaluecount[], int DVCsize);
void player1Chance(int score_card_p1[], int size, int ScoreUsedBefore[], int sizeusedb4, int scorecard, int dice[], int Dsize);
void player2Chance(int score_card_p2[], int size, int ScoreUsedBefore2[], int sizeusedb42, int scorecard, int dice[], int Dsize);

