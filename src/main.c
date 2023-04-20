/*   GPL HEADER LICENCE

   This file is part of SUDOCU.

   SUDOCU is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   SUDOCU is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with SUDOCU.  If not, see <http://www.gnu.org/licenses/>.

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"functions.h"

int main(int argc, char * argv[]) {
   unsigned long int execution = 0;
   int gpreprimitive[9][9], sorting = 1, e_equal, sorting_change = 0, p = 0, d = 0, j, gprimitive[9][9], i, finnish = 0, g[9][9], ve[2][9], m1[3][3], m2[3][3], m3[3][3], m4[3][3], m5[3][3], m6[3][3], m7[3][3], m8[3][3], m9[3][3];
   char answer;
   int forced_solutions = 0;
   int is_solved = 0;

   if (argc == 2) {
      if (strcmp(argv[1], "-h") == 0) {
         printf("\nThis program only works with text files, for example:\n\nfile.txt\n\nContained in this file, must be the sudoku to be solved, in the following format:\n<this is an example>\n\n0\n0\n0\n6\n5\n7\n4\n0\n0\n\nwich would be the first unsolved sudoku's row.\n\nInformation must be introduced by rows, and number 0 will be a hole in that sudoku.\n\nData introduced must be a number between 0 and 9.\n");
         printf("\nRev. 0\n");
         printf("\nTHIS PROGRAM WAS MADE BY\n\nRafael Luque Tejada\n\nSecond year student of Technical Enginner in Computer Sciences, Systems, in University of Córdoba, Spain.\n\n11th January, 2008\n");
         printf("\nRev. 1\n");
         printf("\nTHIS PROGRAM WAS REVIEWED BY\n\nRafael Luque Tejada - Lukemaster\n\nTechnical Enginner in Computer Sciences, Systems,\n\n8th April, 2012\n");
         printf("\nRev. 2\n");
         printf("\nTHIS PROGRAM WAS REVIEWED BY\n\nRafael Luque Tejada - Lukemaster\n\nTechnical Enginner in Computer Sciences, Systems,\n\n20th April, 2023\n");
         printf("\nFor watching this information again, please execute 'sudocu -h'\n");
         printf("\nThis program is dedicated to every people who, with determination and perseverance, helped me to smooth out my rough edges and problems with C language.\n");
      }
      if ((file(g, argv[1])) == 1) {
         while (finnish != 1) {
            printf("\n\n\t\\\\\\\\ ****        WELCOME TO SUDOKU SOLVER          **** \\\\\\\\");
            printf("\n\n\t\\\\\\\\ ****               GPL LICENSE                **** \\\\\\\\");
            printf("\n\n\n\n\n\n");
            show_matrix(g);
            printf("\nIs the following sudoku which you want to be solved?\n");
            printf("\n[y/n]\n");
            scanf("%c", & answer);
            printf("\n");
            if (answer == 'n' || answer == 'N' || (answer != 'Y' && answer != 'y')) {
               printf("\n\n\n\n\n");
               printf("\t\\\\\\\\ **** THANK YOU FOR USING THIS PROGRAM **** \\\\\\\\\n");
               printf("\nFor getting more information, please execute 'sudocu -h'\n");
               return 0;
            }
            algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
            if (is_full_matrix(g) == 1) {
               finnish = 1;
            } else {
               sort_array_desc(ve, 9);
               printf("\n\nMaybe it is a multi solution sudoku. I'm goint to force it 'cleverly'...\n\n");
               while (finnish != 1) {
                  for (i = 0; i < 9; i++) {
                     for (j = 0; j < 9; j++) {
                        gpreprimitive[i][j] = gprimitive[i][j] = g[i][j];
                     }
                  }
                  if (d == 9) {
                     d = 0;
                     p++;
                  }
                  finnish = solver(sorting, p, &d, ve, g, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                  d++;
                  e_equal = 0;
                  for (i = 0; i < 9; i++) {
                     for (j = 0; j < 9; j++) {
                        if (g[i][j] == gprimitive[i][j]) {
                           e_equal++;
                        }
                     }
                  }
                  if (e_equal == 81) {
                     sorting_change++;
                  }
                  if (sorting_change == 9) {
                     if (sorting == 1) {
                        sorting = 2;
                     } else {
                        sorting = 1;
                     }
                     p = 0;
                     d = 0;
                  }
                  if (finnish != 1) {
                     for (i = 0; i < 9; i++) {
                        for (j = 0; j < 9; j++) {
                           g[i][j] = gpreprimitive[i][j];
                        }
                     }
                  }
                  execution++;
                  if (execution == 300 /*4294967295*/ ) { 
                     //THIS CONDITIONAL IS DUE TO PROBLEM PROPOSED COULD BE WRONG, 
                     //OR THERE WAS AN ERROR DURING PROGRAM EXECUTION, ENTERING IT IN A INFINITE LOOP
                     finnish = 1;
                     m1[0][0] = 1;
                     m1[0][1] = 1;
                  }
                  switch (execution % 4) {
                     default:
                        printf("\r|   ");
                        break;

                     case 1:
                        printf("\r/   ");
                        break;

                     case 2:
                        printf("\r-   ");
                        break;

                     case 3:
                        printf("\r\\   ");
                        break;
                  }
               }
               if (is_full_matrix(g) != 1) {
                  printf("\n\nIt is being a little bit difficult for me... I'll try to use brute force. Relax and be patient please...\n\n");
                  forced_solutions = super_super_force(gprimitive,m1,m2,m3,m4,m5,m6,m7,m8,m9,g);
               }
            }
         }
         is_solved = check_matrix(g, m1, m2, m3, m4, m5, m6, m7, m8, m9) && is_full_matrix(g);
         if (is_solved != 0 || forced_solutions != 0) {
            if (is_solved != 0) {
               printf("\n\n\n");
               show_matrix(g);
            }
            printf("\nforced_solutions %d\n",forced_solutions);
            if(forced_solutions <= 0) {
               answer = 'a';
               finnish = 0;
               printf("\nMaybe, there are more solutions for this sudoku; do you want I'll try to find more solutions for this?\n");
               printf("\n[y/n]\n");
               getchar();
               scanf("%c", & answer);
               if (answer == 'n' || answer == 'N' || (answer != 'Y' && answer != 'y')) {
                  finnish = 1;
               }
               if (finnish != 1) {
                  forced_solutions = super_super_force(gprimitive,m1,m2,m3,m4,m5,m6,m7,m8,m9,g);
               }
            }
            printf("\n\n\n\n\n");
            printf("\t\\\\\\\\ **** THANK YOU FOR USING THIS PROGRAM **** \\\\\\\\\n");
            printf("\nFor getting more information, please execute 'sudocu -h'\n");
         } else {
            printf("\n\nAn error happened. The sudoku is not well solved.\nIt could be by a wrong working, or maybe the problem proposed was not a real sudoku.\n");
         }
      }
      if ((file(g, argv[1])) == 0 && strcmp(argv[1], "-h") != 0) {
         printf("\n\aIt's impossible to open the file provided\n");
         printf("\nFor getting more information, please execute 'sudocu -h'\n");
      }
      if ((file(g, argv[1])) == 2) {
         printf("\nWrong data found\n");
         printf("\nFor getting more information, please execute 'sudocu -h'\n");
      }
   } else {
      printf("\a\nThe right form for using this program is passing source file by command line's parameter:\n\n\t<program name> <filename.extension>\n\nFor example: sudocu file.txt\n");
      printf("\nFor getting more information, please execute 'sudocu -h'\n");
   }

   return 0;
}
