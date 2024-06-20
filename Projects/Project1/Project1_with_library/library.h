#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Enumerated type for the menu
typedef enum {
  Start_office_hours = 1,
  Serve = 2,
  Join = 3,
  Change_place = 4,
  Quit_Queue = 5,
  Stop = 6
} menu_t;
// Structure
typedef struct s_inf {
  char name[80];
  unsigned short ID;
  unsigned short time_mins;
  struct s_inf *next;
} s_info;
// Function prototypes
void menu(void);
void enqueue(s_info **front,s_info**rear,s_info*To_enqueue);
void dequeue(s_info **front,s_info**rear,char *To_serve);
void start_office_hours(FILE* infp, s_info** front, s_info** rear);
int Serve_student(s_info **front, s_info **rear, char *Currently_served);
void office_status(char *Student);
int display_waitlist(s_info *front);
int Change_place_students(s_info *front,unsigned short id1, unsigned short id2);
void finish_office_hours(s_info** front, s_info**rear);
int Quit(s_info**front, s_info**rear, unsigned short id);