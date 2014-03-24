#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int row, col; /* These hold the size of the terminal window */
char *welcome(void);
int stage1_1(char *char_name);
void ending(int score);
void next(void);
void stage1_1a(void);

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
  score += stage1_1(char_name);

  ending(score);

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
    
int stage1_1(char *char_name) {
  int current_score = 0;
  char wake_up[] = "Wake up, ";
  char emotion_bad[] = "Oh no...";
  char in_bed[] = "You're in bed.";
  char in_bed_next[] = "Right next to you lies your cousin.";
  char cousin_ask[] = "What are you going to do on the bed ";
  char in_bed_erection[] = "You have the weirdest boner for her.";
  char in_bed_cousin_kawaii[] = "You are so kawaii, ";
  char in_bed_dick[] = "You can't control your penis for her anymore.";
  char choice0_0[] = "CHOICE:";
  char choice0_1[] = "A: Gather yourself and defeat your primal instincts.";
  char choice0_2[] = "B: Say \"My hips are moving on their own!\"";
  char choice_result[] = "Your choice didn't matter.";
  char awake1[] = "You are in a dream.";
  char awake2[] = "You quickly realize you don't have a cousin.";
  char awake3[] = "And that you are also not Japanese.";
  char awake4[] = "And, in fact, you are three-dimensional.";
  char awake5[] = "You wake up.";
  char awake6[] = "It's 2PM on a saturday.";
  char what_the_fuck_am_I_invoking[] = "\"What the fuck was I dreaming?\" you mutter to yourself as you turn on your battlestation.";
  char choice1_1[] = "A: Put some clothes on and clean up.";
  char choice1_2[] = "B: Do nothing.";
  char choice1;

  mvprintw(row / 2, ((col - strlen(char_name) - 5) / 2) , "\"%s!\"", char_name);
  next();

  mvprintw(row / 2, ((col - strlen(wake_up) - 7 - strlen(char_name))) / 2, "\"%s%s-chan\"", wake_up, char_name);
  next();

  mvprintw(row / 2, (col - strlen(emotion_bad)) / 2, "%s", emotion_bad);
  next();

  mvprintw(row / 2, (col - strlen(in_bed)) / 2, "%s", in_bed);
  next();

  mvprintw(row / 2, (col - strlen(in_bed_next)) / 2, "%s", in_bed_next);
  next();

  mvprintw(row / 2, (col - strlen(cousin_ask) - 8) / 2, "\"%s%s-chan?\"", cousin_ask, char_name);
  next();

  mvprintw(row / 2, (col - strlen(in_bed_erection)) / 2, "%s", in_bed_erection);
  next();

  mvprintw(row / 2, (col - strlen(in_bed_cousin_kawaii) - 8) / 2, "\"%s%s-chan~\"", in_bed_cousin_kawaii, char_name);
  next();

  mvprintw(row / 2, (col - strlen(in_bed_dick)) / 2, "%s", in_bed_dick);
  next();

  mvprintw(row / 2, (col - strlen(choice0_0)) / 2, "%s", choice0_0);
  attron(A_BOLD);
  mvprintw((row / 2) + 1, (col - strlen(choice0_1)) / 2, "%s", choice0_1);
  mvprintw((row / 2) + 2, (col - strlen(choice0_2)) / 2, "%s", choice0_2);
  attroff(A_BOLD);
  next();
  current_score++;

  mvprintw(row / 2, (col - strlen(choice_result)) / 2, "%s", choice_result);
  next();

  mvprintw(row / 2, (col - strlen(awake1)) / 2, "%s", awake1);
  next();

  mvprintw(row / 2, (col - strlen(awake2)) / 2, "%s", awake2);
  next();

  mvprintw(row / 2, (col - strlen(awake3)) / 2, "%s", awake3);
  next();

  mvprintw(row / 2, (col - strlen(awake4)) / 2, "%s", awake4);
  next();
  
  mvprintw(row / 2, (col - strlen(awake5)) / 2, "%s", awake5);
  next();
  
  mvprintw(row / 2, (col - strlen(awake6)) / 2, "%s", awake6);
  next();
  
  mvprintw(row / 2, (col - strlen(what_the_fuck_am_I_invoking)) / 2, "%s", what_the_fuck_am_I_invoking);
  next();

  mvprintw((row / 2) - 1, (col - strlen(choice0_0)) / 2, "%s", choice0_0);
  attron(A_BOLD);
  mvprintw(row / 2, (col - strlen(choice1_1)) / 2, "%s", choice1_1);
  mvprintw((row / 2) + 1, (col - strlen(choice1_2)) / 2, "%s", choice1_2);
  attroff(A_BOLD);
  choice1 = getch();

  if((choice1 == 'A') || (choice1 == 'a'))
    stage1_1a();
  else
    current_score++;

  return current_score;
}
void ending(int score) {
  char game_over[] = "Game over!";
  char final_score[] = "Final score: ";

  clear();
  mvprintw((row / 2) - 1, (col - strlen(game_over)) / 2 , "%s!", game_over);
  mvprintw(row / 2, (col - strlen(final_score) - 3) / 2, "%s%i", final_score, score);
  refresh();
  getch();
  endwin();
  exit(0);
}
void next(void) {
  refresh();
  getch();
  clear();
}
void stage1_1a(void) {
  char you_do_it[] = "You pick up some of your clothes, put them on and tidy up.";
  char before_pc[] = "Before you manage to get on the comuputer,";
  char bell_ring[] = "you hear a strange buzzing noise.";
  char the_secret[] = "It's your doorbell.";
  char stroke[] = "You get a stroke and die.";
  
  clear();
  mvprintw(row / 2, (col - strlen(you_do_it)) / 2, "%s", you_do_it);
  next();

  mvprintw((row / 2) - 1, (col - strlen(before_pc)) / 2, "%s", before_pc);
  mvprintw(row / 2, (col - strlen(bell_ring)) / 2, "%s", bell_ring);
  next();

  mvprintw(row / 2, (col - strlen(stroke)) / 2, "%s", stroke);
  next();
  int score = 0;
  ending(score);
}
