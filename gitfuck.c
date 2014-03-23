#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int row, col; /* These hold the size of the terminal window */
char *welcome();

int main() {
  char *char_name;
  char welc_msg[] = "Hello! Welcome to GitFuck!"; /* Initial welcome */
  char welc_continue[] = "Press any key to continue...";
  
  initscr();
  
  getmaxyx(stdscr,row,col);
  mvprintw(row / 2, (col - strlen(welc_msg))/2,"%s", welc_msg); /* Initial welcome to Git Fuck */
  mvprintw((row / 2) + 1, (col - strlen(welc_continue)) / 2, "%s", welc_continue);
  refresh();
  getch(); /* Wait for user input before continuing */

  char_name = welcome();
  while(char_name == "error") /* As long as welcome() returns errors, */
    char_name = welcome();    /* main() will loop welcome()           */

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
    
