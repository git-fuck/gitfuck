#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int row, col; /* These hold the size of the terminal window */
char *welcome(void);
int stage1_1(char *char_name, int current_score);

int main() {
  char *char_name;
  char welc_msg[] = "Hello! Welcome to GitFuck!"; /* Initial welcome */
  char welc_continue[] = "Press any key to continue...";
  int score;

  initscr();
  
  getmaxyx(stdscr,row,col);
  mvprintw(row / 2, (col - strlen(welc_msg))/2,"%s", welc_msg); /* Initial welcome to Git Fuck */
  mvprintw((row / 2) + 1, (col - strlen(welc_continue)) / 2, "%s", welc_continue);
  refresh();
  getch(); /* Wait for user input before continuing */

  char_name = welcome();
  while(char_name == "error") /* As long as welcome() returns errors, */
    char_name = welcome();    /* main() will loop welcome()           */

  score = 0;
  stage1_1(char_name, score);

  endwin();
  return 0;
}
char *welcome() {
  char *char_name; /* The name of the character */
  char name_confirm; /* Confirmation for the name [Y/N] */
  char *return_err = "error"; /* The return if name is invalid */
  int row, col, name_valid; /* Initial set for window sizes and name validity */
  char ask_name[] = "What's your name?"; /* These three are self explanitory */
  char ask_name_confirm[] = "Is your name";
  char bad_name[] = "Name is invalid."; 
  
  getmaxyx(stdscr,row,col);
  clear();

  mvprintw(row / 2, (col - strlen(ask_name)) / 2, "%s\n", ask_name);
  move((row / 2) + 1, (col - strlen(ask_name)) / 2);

  refresh();
  scanw("%s", char_name);
  clear();
  
  mvprintw(row / 2, ((col - strlen(ask_name_confirm)) / 2) - strlen (char_name + 1), "%s ", ask_name_confirm);
  printw("%s?", char_name);
  /* These last functions ask if the character's name is right */
  
  refresh();
  name_confirm = getch();
  clear();

  if((name_confirm == 'y') || (name_confirm == 'Y')) {
    name_valid = 1;
    clear();
    refresh();
  }
  else
    name_valid = 0;
  /* This if-block checks the answer and sets the validity */
  /* variable of the name accordingly with the choice.     */
  
  if(name_valid)      /* If the name is valid, welcome() */
    return char_name; /* hands it back to main(), if not */
  else {              /* then returns "error" to main()  */
    clear();
    mvprintw(row / 2, (col - strlen(bad_name)) / 2, "%s\n", bad_name);
    refresh();
    sleep(1);
    clear();
    return return_err;
  }
}
    
int stage1_1(char *char_name, int current_score) {
  char wake_up[] = "Wake up, ";
  char in_bed[] = "You're in bed.";
  char in_bed_next[] = "Right next to you lies your cousin.";
  char in_bed_erection[] = "You have the weirdest boner for her.";
  char in_bed_dick[] = "You can't control your penis for her anymore.";
  char choice0_0[] = "CHOICE:";
  char choice0_1[] = "A: Go in.";
  char choice0_2[] = "B: Yell \"Lewd!\"";
  char choice_result[] = "Your choice didn't matter.";
  char awake1[] = "You are in a dream.";
  char awake2[] = "You quickly realize you don't have a cousin.";
  char awake3[] = "And that you are also not Japanese.";
  char awake4[] = "And, in fact, you are three-dimensional.";

  mvprintw(row / 2, ((col - strlen(char_name) - 5) / 2) , "\"%s!\"", char_name);
  refresh();
  getch();
  clear();

  mvprintw(row / 2, ((col - strlen(wake_up) - 7 - strlen(char_name))) / 2, "\"%s%s-chan\"", wake_up, char_name);
  refresh();
  getch();
  clear();

  mvprintw(row / 2, (col - strlen(in_bed)) / 2, "%s", in_bed);
  refresh();
  getch();
  clear();

  mvprintw(row / 2, (col - strlen(in_bed_next)) / 2, "%s", in_bed_next);
  refresh();
  getch();
  clear();

  mvprintw(row / 2, (col - strlen(in_bed_erection)) / 2, "%s", in_bed_erection);
  refresh();
  getch();
  clear();

  mvprintw(row / 2, (col - strlen(in_bed_dick)) / 2, "%s", in_bed_dick);
  refresh();
  getch();
  clear();

  mvprintw(row / 2, (col - strlen(choice0_0)) / 2, "%s", choice0_0);
  attron(A_BOLD);
  mvprintw((row / 2) + 1, (col - strlen(choice0_1)) / 2, "%s", choice0_1);
  mvprintw((row / 2) + 2, (col - strlen(choice0_2)) / 2, "%s", choice0_2);
  attroff(A_BOLD);
  refresh();
  getch();
  clear();
  current_score++;

  mvprintw(row / 2, (col - strlen(choice_result)) / 2, "%s", choice_result);
  refresh();
  getch();
  clear();
    
  mvprintw(row / 2, (col - strlen(awake1)) / 2, "%s", awake1);
  refresh();
  getch();
  clear();
  
  mvprintw(row / 2, (col - strlen(awake2)) / 2, "%s", awake2);
  refresh();
  getch();
  clear();
  
  mvprintw(row / 2, (col - strlen(awake3)) / 2, "%s", awake3);
  refresh();
  getch();
  clear();

  mvprintw(row / 2, (col - strlen(awake4)) / 2, "%s", awake4);
  refresh();
  getch();
  clear();

  return current_score;
}
