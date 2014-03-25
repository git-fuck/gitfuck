#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ncurses.h>

int row, col; /* These hold the size of the terminal window */
char *welcome(void); /* Welcomes the user to gitfuck and gets a name */
int stage1_1(char *char_name); /* Initial stage */
void ending(int score); /* Takes the score and ends everyone's life */
void next(void); /* Used to speed up writing for the programmer */
void stage1_1a(void);
void qtemarking(void); /* Warns user of the danger ahead */
void centermsg(char message[], int row_offset, int col_offset);

int main() {
  char *char_name;
  char welc_msg[] = "Hello! Welcome to GitFuck!"; /* Initial welcome */
  char welc_continue[] = "Press any key to continue...";
  int score;

  initscr();
  
  getmaxyx(stdscr,row,col);
  centermsg(welc_msg, 0, 0); /* Initial welcome to Git Fuck */
  centermsg(welc_continue, 1, 0);
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
    centermsg(bad_name, 0, 0);
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
  char choice_result[] = "Your choices don't matter.";
  char awake1[] = "You are in a dream.";
  char awake2[] = "You quickly realize you don't have a cousin.";
  char awake3[] = "And that you are also not Japanese.";
  char awake4[] = "In fact, you are three-dimensional.";
  char awake5[] = "You wake up.";
  char awake6[] = "It's 2PM on a saturday.";
  char what_the_fuck_am_I_invoking[] = "\"What the fuck was I dreaming?\" you mutter to yourself as you turn on your battlestation.";
  char choice1_1[] = "A: Put some clothes on and clean up.";
  char choice1_2[] = "B: Do nothing.";
  char choice1;
  char get_on_pc1[] = "You didn't even manage to put on underwear and your self-built \"battlestation\"";
  char get_on_pc2[] = "with an optimized kernel, bootloader and init daemon already booted up and restored";
  char get_on_pc3[] = "your last browser session and connected to your favorite IRC channels.";
  char start_work[] = "After you finished making a big mug of coffee, you can start to \"work\".";
  char work_however[] = "However, your \"work\" is nothing but browse your favorite imageboard.";
  char DESKTOP_THREAD[] = "The thread about posting screenshots of your desktop is still up.";
  char calm[] = "\"Ah.\"";
  char laugh1[] = "You remember how much fun you had laughing at other people's";
  char laugh2[] = "shitty desktops who used proprietary operating systems last night";
  char laugh3[] = "as you read the new things posted while you were asleep.";
  char THE_BUZZ_OF_STROKES[] = "You hear a loud buzz";
  char guess_what[] = "It's your doorbell, dimwit.";
  char how_sad[] = "You realize you do not remember the sound of";
  char how_bad[] = "your doorbell since nobody ever visits you.";
  char get_clothes[] = "You quickly stand up and search the ground for clothes";
  char cant_open[] = "You can't open the door while wearing just your underwear.";
  char cumming[] = "You yell \"I'm coming!\" as you walk downstairs.";
  char OOB[] = "Almost out of breath you open the door.";
  char gtk[] = "It's a cute Asian girl.";
  char package[] = "\"Hello! I have a package for you!\" She says while smiling.";
  char qte1;
  char qte1_1[] = "PRESS H TO NOT DIE!";
  char qte_death[] = "You died.";
  char survival[] = "\"Y-you too\" you reply without thinking.";

  mvprintw(row / 2, ((col - strlen(char_name) - 5) / 2) , "\"%s!\"", char_name);
  next();

  mvprintw(row / 2, ((col - strlen(wake_up) - 7 - strlen(char_name))) / 2, "\"%s%s-chan\"", wake_up, char_name);
  next();

  centermsg(emotion_bad, 0, 0);
  next();

  centermsg(in_bed, 0, 0);
  next();

  centermsg(in_bed_next, 0, 0);
  next();

  mvprintw(row / 2, (col - strlen(cousin_ask) - 8) / 2, "\"%s%s-chan?\"", cousin_ask, char_name);
  next();

  centermsg(in_bed_erection, 0, 0);
  next();

  mvprintw(row / 2, (col - strlen(in_bed_cousin_kawaii) - 8) / 2, "\"%s%s-chan~\"", in_bed_cousin_kawaii, char_name);
  next();

  centermsg(in_bed_dick, 0, 0);

  mvprintw((row / 2) - 1, (col - strlen(choice0_0)) / 2, "%s", choice0_0); /* Change to normal! */
  attron(A_BOLD);
  mvprintw(row / 2, (col - strlen(choice0_1)) / 2, "%s", choice0_1);
  mvprintw((row / 2) + 1, (col - strlen(choice0_2)) / 2, "%s", choice0_2);
  attroff(A_BOLD);
  next();
  current_score++;

  centermsg(choice_result, 0, 0);
  next();

  centermsg(awake1, 0, 0);
  next();

  centermsg(awake2, 0, 0);
  next();

  centermsg(awake3, 0, 0);
  next();

  centermsg(awake4, 0, 0);
  next();

  centermsg(awake5, 0, 0);
  next();

  centermsg(awake6, 0, 0);
  next();

  centermsg(what_the_fuck_am_I_invoking, 0, 0);
  next();

  mvprintw((row / 2) - 1, (col - strlen(choice0_0)) / 2, "%s", choice0_0); /* EROBE! */
  attron(A_BOLD);
  mvprintw(row / 2, (col - strlen(choice1_1)) / 2, "%s", choice1_1);
  mvprintw((row / 2) + 1, (col - strlen(choice1_2)) / 2, "%s", choice1_2);
  attroff(A_BOLD);
  choice1 = getch();

  if((choice1 == 'A') || (choice1 == 'a'))
    stage1_1a();
  else
    current_score++;

  centermsg(get_on_pc1, -1, 0);
  centermsg(get_on_pc2, 0, 0);
  centermsg(get_on_pc3, 1, 0);
  next();

  centermsg(start_work, 0, 0);
  next();

  centermsg(work_however, 0, 0);
  next();

  centermsg(calm, 0, 0);
  next();

  centermsg(DESKTOP_THREAD, 0 ,0);
  next();

  centermsg(laugh1, -1, 0);
  centermsg(laugh2, 0, 0);
  centermsg(laugh3, 1, 0);
  next(); 

  centermsg(THE_BUZZ_OF_STROKES, 0, 0);
  next();

  centermsg(guess_what, 0, 0);
  next();

  centermsg(how_sad, -1, 0);
  centermsg(how_bad, 0, 0);
  next();

  centermsg(get_clothes, -1, 0);
  centermsg(cant_open, 0, 0);
  next();

  centermsg(cumming, 0, 0);
  next();

  centermsg(OOB, 0, 0);
  next();
  
  centermsg(gtk, 0, 0);
  next();

  centermsg(package, 0, 0);
  next();

  qtemarking();
  attron(A_BOLD);
  centermsg(qte1_1, 0, 0);
  attroff(A_BOLD);
  timeout(1000); /* Waits 1s for the user before continuing */
  noecho();
  qte1 = getch();
  next();
  timeout(-1); /* Restores normal time */
  echo();

  if(qte1 == -1) {
    centermsg(qte_death, 0, 0);
    next();
    ending(0);
  }

  centermsg(survival, 0, 0);
  next();

  return current_score;
}
void ending(int score) {
  char game_over[] = "Game over!";
  char final_score[] = "Final score: ";

  clear();
  centermsg(game_over, -1, 0);
  mvprintw(row / 2, (col - strlen(final_score) - 3) / 2, "%s%i", final_score, score);
  refresh();
  getch();
  endwin(); /* This kills the ncurses */
  exit(0);
}
void stage1_1a(void) {
  char you_do_it[] = "You pick up some of your clothes, put them on and tidy up.";
  char before_pc[] = "Before you manage to get on the comuputer,";
  char bell_ring[] = "you hear a strange buzzing noise.";
  char the_secret[] = "It's your doorbell.";
  char stroke[] = "You get a stroke and die.";
  
  clear();
  centermsg(you_do_it, 0, 0);
  next();

  centermsg(before_pc, -1, 0);
  centermsg(bell_ring, 0, 0);
  next();

  centermsg(stroke, 0, 0);
  next();

  int score = 0;
  ending(score);
}
void qtemarking(void) {
  char qte[] =  "QUICK TIME EVENT!";
  attron(A_BOLD);
  mvprintw(0, 0, "%s", qte);
  mvprintw(0, col - strlen(qte), "%s", qte);
  mvprintw(row - 1, 0, "%s", qte);
  mvprintw(row - 1, col - strlen(qte), "%s", qte);
  attroff(A_BOLD);
}
void next(void) { 
  refresh();
  getch();
  clear();
}
void centermsg(char message[], int row_offset, int col_offset) {
  mvprintw((row / 2) + row_offset, (col - strlen(message) - col_offset) / 2, "%s", message);
}
