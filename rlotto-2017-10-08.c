 /*rlotto.c | RLotto | gcc | v0.0.0.3
 * Console program for purpose of practising C
 * ----------------------------------------------------------------------------
 *
 * Objective:	Store and evaluate Lottery Tickets
 *
 * Author: 		Reinhard Rozumek
 * Email: 		reinhard@rozumek.de
 * Created: 	09/23/17
 * Last mod:	09/25/17
 *
 * ----------------------------------------------------------------------------
 * This file is part of RLotto.
 * 
 * c is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 * 
 * RLotto is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with Tyche I. If not, see <http://www.gnu.org/licenses/>.
 */
 
/* Header Section ************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include<dirent.h>


/* GLOBAL VARIABLES */
bool go_Exit = false;
char ticket_no[7];
 
/* FUNCTION DECLARATIONS */
int getche(void);
int terminateProgram(void);
int welcome(void); 													
int selectTicket(void);												
int addTicket(void);												
int evaluateTicket(void);												
int deleteTicket(void);											
int configureSettings(void);											
int terminateProgram(void);											
 
/* MAIN ---------------------------------------------------------------------*/
/* Function main just displays the main user menu and generates the main 
	program loop. Program can only be terminated by the option from the main 
	menu. All submenus are coded in other functions. 
*/
 
int main() {
	
	bool isFirstLoop = true;			        				// indicates first main prgramm loop
	int iConfirm;						        				// yes or no to confirm user input
	int iSelect;												// Selection from Main Menu
	
	welcome();													// Welcome Message
	
	/* Main Loop starts here */
	
	do {
		
		printf("\nMain Menu Options\n");
		printf("------------------------------------\n");
		printf("\t1 - Add new Lottery Ticket\n");
		printf("\t2 - Select Lottery Ticket\n");
		printf("\t3 - Evaluate Results\n");
		printf("\t4 - Delete Existing Ticket\n");
		printf("\t5 - RLotto settings\n");
		printf("\t6 - Terminate Program\n");
		
		do {
			
			printf("\nPlease select (1-6): ");
			iSelect =(getche());
			fflush(stdin);
         
         } while(iSelect < 49 || iSelect > 54);
		
		iSelect = iSelect - 48;
		
		switch(iSelect) {
			
			case 1: addTicket(); break;
			case 2: selectTicket(); break;
			case 3: evaluateTicket(); break;
			case 4: deleteTicket(); break;
			case 5: configureSettings(); break;
			case 6: terminateProgram(); exit;
					
		}
		
		} while(go_Exit == false);
	
}


/* WELCOME -----------------------------------------------------------------*/
/* Welcome message and check for default RLotto file to open.
*/
int welcome(void) {
	
	printf("\nRLOTTO v0.0.3\n\n");
}

/* ADD TICKET ---------------------------------------------------------------*/
 /* Creates new addressbook and stores it in patch of execuatble binary
 */
int addTicket(void) {
	
	printf("\n\nAdd new lottery ticket.\n");
}

/*	SELECT TICKET ****************************************************************
	Search path of execuatble binary for lottery tickets and displays a sub menu
	to select which ticket to open. 
	*****************************************************************************/

int selectTicket(void) {
	
	printf("\nTICKET SELECTION\n\n");
	
	// Find all files in path of binary executable file. Requires dirent.h
	
	int i = 0;
	int i_min = 1, i_max;
	int i_input = 0;
	DIR *d;
    struct dirent *dir;
	char fn_array[100] [12];								// Array filename with extension (str length + 1)
	
    // First run just to count number of tickets 
	d = opendir(".");
    if (d)
    {
		while ((dir = readdir(d)) != NULL)
        {
			char *fn = dir->d_name;							// fn: file name
			char * ext = strrchr(fn, '.');					// ext: file extension
			if(strcmp(ext, ".tck") == 0) 					// File extension for lottery tickets
			{
				i++;
			}
        }
		
        closedir(d);
		i_max = i;
    }
	
	// Second run to read ticket file names in array
	d = opendir(".");
	
    if (d)
	{	
		
		i = 0;												// Reset counter i
		while ((dir = readdir(d)) != NULL)
        {
			char *fn = dir->d_name;							// fn: file name
			char * ext = strrchr(fn, '.');					// ext: file extension
			if(strcmp(ext, ".tck") == 0) 					// File extension for lottery tickets
			{
				i++;
				strcpy(fn_array[i-1],fn);
				printf("%3i --> Ticket Number: %.*s File Name: %s\n", i, 7, fn + 0, fn_array[i-1]);
			}
        }
		
        closedir(d);
    }
	
	// i equals null --> no ticket found
	if(i == 0) 
	{
		 // no ticket found
		 printf("\nNo ticket found in selected directory.\n");
		 
	} 
	else
	{
		printf("\n%i ticket(s) found in selected directory.\n", i_max);
		do {
			printf("\nEnter number between %i and %i: ",i_min, i_max);
			scanf("%d", &i_input);
			if(i_input < 1 || i_input > i_max)
			if(i_input < 1 || i_input > i_max)
			{
				printf("\n \"%d\" is not between %i and %i !\n",i_input, i_min, i_max);
				printf("\n \"%d\" is not between %i and %i !\n",i_input, i_min, i_max);
			}
		}while(i_input < 1 || i_input > i_max);
			
		strncpy(ticket_no, fn_array[i_input - 1] + 0,7);
		ticket_no[7] = '\0';
		printf("\nTicket No %s has been selected.\n", ticket_no);
	}
}

/* EVALUATE TICKET ----------------------------------------------------------*/
/* Adds new contact to pre-selected address book.
*/
int evaluateTicket(void) {
	printf("\n\nEvaluate lottery results.\n");
	
}
 
/* DELETE TICKET ------------------------------------------------------------*/
/* Delete stored ticket in repository.
*/
int deleteTicket(void) {
	printf("\n\nDelete existing lottery ticket.\n");
}

/* CONFIGURE SETTINGS -------------------------------------------------------*/
/* Configure settings in INI file.
*/	
int configureSettings(void) {
	printf("\n\nConfigure Settings for RLotto.\n");
}

 /* TERMINATEPROGRAM --------------------------------------------------------*/
 /* terminateProgram displays a message for the program termination. Other
 	 functions like closing any open files, reset variables and write a history
 	 message to the ini file still needs to be defined.
 */

int terminateProgram(void) {
 	
 	printf("\n\nProgram terminated by user.\n");
 	go_Exit = true; // remove after Main Menu is completed
 	return 0;
}

