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

#include"functions.h"

/*void insert_data(int m[9][9]) {
   int i,j,n;
   
   //printf("\nA continuacion introduzca los data por filas en la matriz anadiendo un 0 \n(cero) en el lugar en el que corresponde un hueco:\n\n");
   printf("\nHereunder, type the numbers by rows in the matrix, adding 0(zero) when you\nwant to insert a hole:\n\n");
   for (i=0;i<9;i++)
      for (j=0;j<9;j++)
      {
         m[i][j]=-1;
         while(m[i][j]==-1)
         {
            scanf("%d",&n);
            if (n<0 || n>9)
               printf("\nEl valor no se pudo anadir, no pertenece a un sudoku");
            else
               m[i][j]=n;
         }
      }
            
}*/

void show_matrix(int m[9][9]) {
   int i, j, saltocolumna = 0, saltofila = 0;

   for (i = 0; i < 9; i++) {
      printf("\t\t\t");
      for (j = 0; j < 9; j++) {
         printf(" %d", m[i][j]);
         saltocolumna++;
         if (saltocolumna == 3) {
            printf("\t");
            saltocolumna = 0;
         }
      }
      printf("\n\n");
      saltofila++;
      if (saltofila == 3) {
         printf("\n");
         saltofila = 0;
      }
   }
}

void show_minimatrix(int m[3][3]) {
   int i, j;

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         printf("%d", m[i][j]);
      }
      printf("\n");
   }
}

void show_array(int v[2][9]) {
   int j;

   for (j = 0; j < 9; j++) {
      printf("%d", v[0][j]);
   }
   printf("\n");

}

void part_matrix(int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]) {
   int i, j;

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         m1[i][j] = g[i][j];
         m2[i][j] = g[i][j + 3];
         m3[i][j] = g[i][j + 6];
         m4[i][j] = g[i + 3][j];
         m5[i][j] = g[i + 3][j + 3];
         m6[i][j] = g[i + 3][j + 6];
         m7[i][j] = g[i + 6][j];
         m8[i][j] = g[i + 6][j + 3];
         m9[i][j] = g[i + 6][j + 6];
      }
   }
}

void count_elements(int g[9][9], int ve[2][9]) {
   int i, j, element = 1, counter = 0, idx = 0;

   while (element < 10) {
      for (i = 0; i < 9; i++) {
         for (j = 0; j < 9; j++) {
            if (g[i][j] == element) {
               counter++;
            }
         }
         ve[0][i] = i + 1;
      }
      if (counter == 9) {
         ve[1][idx] = 0;
      } else {
         ve[1][idx] = counter;
      }
      counter = 0;
      element++;
      idx++;
   }
}

int file(int g[9][9], char argv[1]) {
   FILE * text;
   int data = 1, i, j;

   if ((text = fopen(argv, "r")) == NULL) {
      return 0;
   } else {
      for (i = 0; i < 9; i++) {
         for (j = 0; j < 9; j++) {
            fscanf(text, "%d", & g[i][j]);
            if (g[i][j] > 9 || g[i][j] < 0) {
               data = 0;
            }
         }
      }
      fclose(text);
      if (data == 0) {
         return 2;
      } else {
         return 1;
      }
   }
}

int sort_array_desc(int ve[2][9], int n) {
   int elements=0, auxiliar[2][1], i = 0, distance = 0;

   if (n % 2 != 0) {
      distance = (n / 2) + 1;
   } else {
      distance = (n / 2);
   }

   while (distance >= 1) {
      for (i = 0; i < (n - distance); i++) {
         if (ve[1][i] < ve[1][i + distance]) {
            auxiliar[0][0] = ve[0][i + distance];
            auxiliar[1][0] = ve[1][i + distance];
            ve[0][i + distance] = ve[0][i];
            ve[1][i + distance] = ve[1][i];
            ve[0][i] = auxiliar[0][0];
            ve[1][i] = auxiliar[1][0];
         }
      }
      distance--;
   }
   for (i = 0; i < 9; i++) {
      if (ve[0][i] == 0) {
         elements++;
      }
   }
   return elements;
}

int sort_array_asc(int ve[2][9], int n) {
   int elements=0, auxiliar[2][1], i = 0, distance = 0;

   if (n % 2 != 0) {
      distance = (n / 2) + 1;
   } else {
      distance = (n / 2);
   }

   while (distance >= 1) {
      for (i = 0; i < (n - distance); i++) {
         if (ve[1][i] > ve[1][i + distance]) {
            auxiliar[0][0] = ve[0][i + distance];
            auxiliar[1][0] = ve[1][i + distance];
            ve[0][i + distance] = ve[0][i];
            ve[1][i + distance] = ve[1][i];
            ve[0][i] = auxiliar[0][0];
            ve[1][i] = auxiliar[1][0];
         }
      }
      distance--;
   }
   for (i = 0; i < 9; i++) {
      if (ve[0][i] == 0) {
         elements++;
      }
   }
   return elements;
}

int compair_minimatrix(int m1[3][3], int m2[3][3]) {
   int i, valid = 1, j;

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         if (m1[i][j] != m2[i][j]) {
            valid = 0;
         }
      }
   }
   if (valid == 1) {
      return 1; //same mini matrix
   } else {
      return 0; //different mini matrix
   }
}

int find_in_minimatrix(int element, int g[9][9], int m[3][3], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]) {
   int i, j, valid = 1, rlimsup, rliminf, climsup, climinf, found = 0;

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         if (m[i][j] == element) {
            valid = 0;
         }
      }
   }
   if (valid == 1) {
      if ((compair_minimatrix(m, m1)) == 1) {
         rlimsup = 2;
         rliminf = 0;
         climsup = 2;
         climinf = 0;
         found = assigner(element, g, m1, rlimsup, rliminf, climsup, climinf);
      }
      if (compair_minimatrix(m, m2) == 1) {
         rlimsup = 2;
         rliminf = 0;
         climsup = 5;
         climinf = 3;
         found = assigner(element, g, m2, rlimsup, rliminf, climsup, climinf);
      }
      if (compair_minimatrix(m, m3) == 1) {
         rlimsup = 2;
         rliminf = 0;
         climsup = 8;
         climinf = 6;
         found = assigner(element, g, m3, rlimsup, rliminf, climsup, climinf);
      }
      if (compair_minimatrix(m, m4) == 1) {
         rlimsup = 5;
         rliminf = 3;
         climsup = 2;
         climinf = 0;
         found = assigner(element, g, m4, rlimsup, rliminf, climsup, climinf);
      }
      if (compair_minimatrix(m, m5) == 1) {
         rlimsup = 5;
         rliminf = 3;
         climsup = 5;
         climinf = 3;
         found = assigner(element, g, m5, rlimsup, rliminf, climsup, climinf);
      }
      if (compair_minimatrix(m, m6) == 1) {
         rlimsup = 5;
         rliminf = 3;
         climsup = 8;
         climinf = 6;
         found = assigner(element, g, m6, rlimsup, rliminf, climsup, climinf);
      }
      if (compair_minimatrix(m, m7) == 1) {
         rlimsup = 8;
         rliminf = 6;
         climsup = 2;
         climinf = 0;
         found = assigner(element, g, m7, rlimsup, rliminf, climsup, climinf);
      }
      if (compair_minimatrix(m, m8) == 1) {
         rlimsup = 8;
         rliminf = 6;
         climsup = 5;
         climinf = 3;
         found = assigner(element, g, m8, rlimsup, rliminf, climsup, climinf);
      }
      if (compair_minimatrix(m, m9) == 1) {
         rlimsup = 8;
         rliminf = 6;
         climsup = 8;
         climinf = 6;
         found = assigner(element, g, m9, rlimsup, rliminf, climsup, climinf);
      }
      if(found != 1) {
         return 0;
      } else {
         return found;
      }
   } else {
      return valid;
   }
}

int assigner(int element, int g[9][9], int m[3][3], int rlimsup, int rliminf, int climsup, int climinf) {
   int exists, i, k, j, counter = 0;

   for (i = rliminf; i < rlimsup + 1; i++) {
      for (j = climinf; j < climsup + 1; j++) {
         if (g[i][j] == 0) //empty
         {
            exists = 0;
            for (k = 0; k < climinf; k++) {
               if (g[i][k] == element) {
                  exists++;
               }
            }
            for (k = climsup + 1; k < 9; k++) {
               if (g[i][k] == element) {
                  exists++;
               }
            }
            for (k = 0; k < rliminf; k++) {
               if (g[k][j] == element) {
                  exists++;
               }
            }
            for (k = rlimsup + 1; k < 9; k++) {
               if (g[k][j] == element) {
                  exists++;
               }
            }
            if (exists == 0) { //any match in rows and colums neither
               g[i][j] = element;
               m[i % 3][j % 3] = element;
               counter++; //element inserted
            }
         }
      }
   }
   //Looking for some posibilities to insert an element
   if (counter > 1) {
      for (i = rliminf; i < rlimsup + 1; i++) {
         for (j = climinf; j < climsup + 1; j++) {
            if (g[i][j] == element) {
               g[i][j] = 0;
               m[i % 3][j % 3] = 0;
            }
         }
      }
      return 2; //able to insert more than one time the same element -> it will not be inserted
   } else {
      return 1; //right number inserted
   }
}

int is_full_matrix(int g[9][9]) {
   int i, j, exit = 0;

   for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
         if (g[i][j] == 0) {
            exit = 1;
         }
      }
   }
   if (exit == 1) {
      return 0; //not full matrix
   } else {
      return 1; //full matrix
   }
}

int algorithm(int gprimitive[9][9], int g[9][9], int ve[2][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]) {
   int counter = 0, j, changes = 0, cycle_without_any_change = 0, els_added = 0, exit = 0, added = 0, recycle = 1, i = 0, element;

   //algorithm
   for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
         gprimitive[i][j] = g[i][j];
      }
   }
   part_matrix(g, m1, m2, m3, m4, m5, m6, m7, m8, m9);
   while (exit != 1) {
      exit = is_full_matrix(g);
      count_elements(g, ve);
      sort_array_desc(ve, 9);
      for (i = 0; i < 9; i++) {
         element = ve[0][i];
         recycle = 1;
         while (recycle != 0 && ve[1][i] != 0 && counter < 81) {
            els_added = +(added = find_in_minimatrix(element, g, m1, m1, m2, m3, m4, m5, m6, m7, m8, m9));
            els_added = +(added = find_in_minimatrix(element, g, m2, m1, m2, m3, m4, m5, m6, m7, m8, m9));
            els_added = +(added = find_in_minimatrix(element, g, m3, m1, m2, m3, m4, m5, m6, m7, m8, m9));
            els_added = +(added = find_in_minimatrix(element, g, m4, m1, m2, m3, m4, m5, m6, m7, m8, m9));
            els_added = +(added = find_in_minimatrix(element, g, m5, m1, m2, m3, m4, m5, m6, m7, m8, m9));
            els_added = +(added = find_in_minimatrix(element, g, m6, m1, m2, m3, m4, m5, m6, m7, m8, m9));
            els_added = +(added = find_in_minimatrix(element, g, m7, m1, m2, m3, m4, m5, m6, m7, m8, m9));
            els_added = +(added = find_in_minimatrix(element, g, m8, m1, m2, m3, m4, m5, m6, m7, m8, m9));
            els_added = +(added = find_in_minimatrix(element, g, m9, m1, m2, m3, m4, m5, m6, m7, m8, m9));

            //added would value 1 if it was possible to set the number as a solution; on the other hand, added will value 0, because there were more than one posibility for be inserted
            if (added < 1) { //element did not inserted-> not recycling this element
               recycle = 0;
            }
            counter++;

         }
         if (counter == 81) {
            exit = 1;
         }
      }
      if (els_added == 0) {
         cycle_without_any_change++;
      }
      if (els_added == 0 && cycle_without_any_change == 9) {
         exit = 1;
      }
   }
   for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
         if (g[i][j] != gprimitive[i][j]) {
            changes = 1;
         }
      }
   }
   return changes; //return 1 if matrix was changed, else return 0
}

void roll_left(int ve[2][9]) {
   int j, i, vt[2][9];

   for (i = 0; i < 2; i++) {
      for (j = 0; j < 9; j++) {
         vt[i][j] = ve[i][j];
      }
   }
   for (i = 0; i < 8; i++) {
      j = i + 1;
      ve[0][i] = vt[0][j];
      ve[1][i] = vt[1][j];
   }
   ve[0][8] = vt[0][0];
   ve[1][8] = vt[1][0];
}

int force(int element, int g[9][9], int rlimsup, int rliminf, int climsup, int climinf) {
   int i, j, k, exists, forced = 0;

   for (i = rliminf; i < rlimsup + 1; i++) {
      for (j = climinf; j < climsup + 1; j++) {
         if (g[i][j] == 0) //empty element
         {
            exists = 0;
            for (k = 0; k < climinf; k++) {
               if (g[i][k] == element) {
                  exists++;
               }
            }
            for (k = climsup + 1; k < 9; k++) {
               if (g[i][k] == element) {
                  exists++;
               }
            }
            for (k = 0; k < rliminf; k++) {
               if (g[k][j] == element) {
                  exists++;
               }
            }
            for (k = rlimsup + 1; k < 9; k++) {
               if (g[k][j] == element) {
                  exists++;
               }
            }
            if (exists == 0) { //any match in rows and colums neither
               g[i][j] = element;
               i = rlimsup + 1;
               j = climsup + 1;
               forced = 1; //one element was inserted
            }
         }
      }
   }
   return forced;

}

int count_zeros_g(int g[9][9]) {
   int i, j, zeros = 0;

   for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
         if (g[i][j] == 0) {
            zeros++;
         }
      }
   }
   return zeros; //number of zeros still in the matrix
}

int count_zeros_m(int m[3][3]) {
   int i, j, zeros = 0;

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         if (m[i][j] == 0) {
            zeros++;
         }
      }
   }
   return zeros; //number of zeros still in the mini matrix
}

void sort_by_elements(int nelements[2][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]) {
   //sort mini matrix switch the number of not null numbers inside
   int i, j = 1;

   nelements[1][0] = 9 - count_zeros_m(m1);
   nelements[1][1] = 9 - count_zeros_m(m2);
   nelements[1][2] = 9 - count_zeros_m(m3);
   nelements[1][3] = 9 - count_zeros_m(m4);
   nelements[1][4] = 9 - count_zeros_m(m5);
   nelements[1][5] = 9 - count_zeros_m(m6);
   nelements[1][6] = 9 - count_zeros_m(m7);
   nelements[1][7] = 9 - count_zeros_m(m8);
   nelements[1][8] = 9 - count_zeros_m(m9);
   for (i = 0; i < 9; i++) {
      if (nelements[1][i] == 9) {
         nelements[1][i] = 0;
      }
      nelements[0][i] = j;
      j++;
   }
   sort_array_desc(nelements, 9);
}

int count_els_without_be_assinged(int elements_nassigned[2][9], int g[9][9], int rlimsup, int rliminf, int climsup, int climinf) {
   int i, j, element;

   for (i = 0; i < 9; i++) {
      elements_nassigned[1][i] = 0;
   }

   for (i = rliminf; i < rlimsup + 1; i++) {
      for (j = climinf; j < climsup + 1; j++) {
         if (g[i][j] != 0)
            elements_nassigned[1][(g[i][j] - 1)] = 1;
      }
   }
   j = 1;
   for (i = 0; i < 9; i++) {
      elements_nassigned[0][i] = j;
      j++;
   }
   /*1 if element was found, else 0*/
   sort_array_desc(elements_nassigned, 9);
   element = 0;
   for (i = 0; i < 9; i++) {
      if (elements_nassigned[1][i] != 1) {
         element++;
      }
   }

   return element;
   /*return the number of elements wich can not be assigned*/
}

int * new_array(int els_without_be_assigned) {
   return ((int * ) malloc(els_without_be_assigned * sizeof(int)));
}

int calc_minimatrix(int x, int y) {
   int minimatrix = 0;

   if (x <= 8 && x >= 6) {
      if (y <= 8 && y >= 6)
         minimatrix = 9;
      else
      if (y <= 5 && y >= 3)
         minimatrix = 8;
      else
      if (y <= 2 && y >= 0)
         minimatrix = 7;
   } else
   if (x <= 5 && x >= 3) {
      if (y <= 8 && y >= 6)
         minimatrix = 6;
      else
      if (y <= 5 && y >= 3)
         minimatrix = 5;
      else
      if (y <= 2 && y >= 0)
         minimatrix = 4;
   } else
   if (y <= 8 && y >= 6)
      minimatrix = 3;
   else
   if (y <= 5 && y >= 3)
      minimatrix = 2;
   else
   if (y <= 2 && y >= 0)
      minimatrix = 1;

   return minimatrix;
}

int is_number_allow(int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3], int x, int y, int number) {
   int allow = 1, i, j, minimatrix;

   for (i = 0; i < 9 && allow != 0; i++) {
      if (g[x][i] == number) {
         allow = 0;
      }
   }

   for (i = 0; i < 9 && allow != 0; i++) {
      if (g[i][y] == number) {
         allow = 0;
      }
   }

   minimatrix = calc_minimatrix(x, y);
   
   switch (minimatrix) {
      case 1:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m1[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;

      case 2:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m2[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;

      case 3:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m3[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;

      case 4:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m4[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;

      case 5:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m5[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;

      case 6:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m6[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;

      case 7:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m7[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;

      case 8:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m8[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;

      case 9:
         for (i = 0; i < 3 && allow != 0; i++) {
            for (j = 0; j < 3 && allow != 0; j++) {
               if (m9[i][j] == number) {
                  allow = 0;
               }
            }
         }
         break;
   }

   return allow;
}

int super_force(int ve[2][9], int g[9][9], int gprimitive[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]) {

   int exit = 0;
   int gp[9][9];
   int p1, p2, p3, p4, p5, p6, p7, p8, p9, f, c, execution = 0;

   int a, b;

   for (a = 0; a < 9; a++) {
      for (b = 0; b < 9; b++) {
         gp[a][b] = g[a][b];
      }
   }


   part_matrix(g, m1, m2, m3, m4, m5, m6, m7, m8, m9);

   for (p1 = 0; p1 < 9 && exit != 1; p1++) {
      for (a = 0; a < 9 && exit != 1; a++) {
         for (b = 0; b < 9; b++) {
            g[a][b] = gp[a][b];
         }
      }
      for (p2 = 0; p2 < 9 && exit != 1; p2++) {
         for (p3 = 0; p3 < 9 && exit != 1; p3++) {
            for (p4 = 0; p4 < 9 && exit != 1; p4++) {
               for (p5 = 0; p5 < 9 && exit != 1; p5++) {
                  for (p6 = 0; p6 < 9 && exit != 1; p6++) {
                     for (p7 = 0; p7 < 9 && exit != 1; p7++) {
                        for (p8 = 0; p8 < 9 && exit != 1; p8++) {
                           for (p9 = 0; p9 < 9 && exit != 1; p9++) {
                              for (f = 0; f < 9 && exit != 1; f++) {
                                 for (c = 0; c < 9 && exit != 1; c++) {
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p1 + 1) != 0) {
                                       g[f][c] = p1 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p2 + 1) != 0) {
                                       g[f][c] = p2 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p3 + 1) != 0) {
                                       g[f][c] = p3 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p4 + 1) != 0) {
                                       g[f][c] = p4 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p5 + 1) != 0) {
                                       g[f][c] = p5 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p6 + 1) != 0) {
                                       g[f][c] = p6 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p7 + 1) != 0) {
                                       g[f][c] = p7 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p8 + 1) != 0) {
                                       g[f][c] = p8 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_number_allow(g, m1, m2, m3, m4, m5, m6, m7, m8, m9, f, c, p9 + 1) != 0) {
                                       g[f][c] = p9 + 1;
                                       algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                                    }
                                    if (is_full_matrix(g) != 0) {
                                       exit = 1;
                                    }
                                 }
                              }
                              if (exit != 1) {
                                 for (a = 0; a < 9; a++) {
                                    for (b = 0; b < 9; b++) {
                                       g[a][b] = gp[a][b];
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
                  if (exit != 1) {
                     algorithm(gprimitive, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9);
                     if (is_full_matrix(g) != 0) {
                        exit = 1;
                     }
                  }
                  switch (execution) {
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
                        execution = -1;
                        break;
                  }
                  execution++;
               }
            }
         }
      }
   }

   return exit;
}

void printarray(int arr[], int size) {
    int i;
    for (i=0; i<size; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int check_columns(int g[9][9], int* arr, int row_eval, int index) {
   int j, match = 1;

   for (j = 0; j < row_eval && match != 0; j++) {
      if (g[j][index] == arr[index]) {
         match = 0;
      }
   }
   for (j = row_eval+1; j < 9 && match != 0; j++) {
      if (g[j][index] == arr[index]) {
         match = 0;
      }
   }

   return match;
}

int check_minimatrix(int** g) {
   int e, k, j, match = 1;
   int m_el_acc[9][9];
   for (k = 0; k < 9; k++) {
      for (j = 0; j < 9; j++) {
         m_el_acc[k][j] = 0;
      }
   }
   for (e = 1; e < 10; e++) {
      for (k = 0; k < 3; k++) {
         for (j = 0; j < 3; j++) {
            if (g[k][j] == e) {
               m_el_acc[0][e-1]++;
            }
            if (g[k+3][j] == e) {
               m_el_acc[3][e-1]++;
            }
            if (g[k+6][j] == e) {
               m_el_acc[6][e-1]++;
            }

            if (g[k][j+3] == e) {
               m_el_acc[1][e-1]++;
            }
            if (g[k+3][j+3] == e) {
               m_el_acc[4][e-1]++;
            }
            if (g[k+6][j+3] == e) {
               m_el_acc[7][e-1]++;
            }

            if (g[k][j+6] == e) {
               m_el_acc[2][e-1]++;
            }
            if (g[k+3][j+6] == e) {
               m_el_acc[5][e-1]++;
            }
            if (g[k+6][j+6] == e) {
               m_el_acc[8][e-1]++;
            }
         }
      }
   }
   for (k = 0; k < 9 && match != 0; k++) {
      for (j = 0; j < 9 && match != 0; j++) {
         if (m_el_acc[k][j] > 1) {
            match = 0;
         }
      }
   }

   return match;
}

int check_starting_array(int idx, int *arr, int *match_arr) {
   if (match_arr[idx] <= 0) {
      return 1;
   }
   if (match_arr[idx] != 0 && match_arr[idx] != arr[idx]) {
      return 0;
   }
   return 1;
}

void permutation(int orig[9][9], int *arr, int *match_arr, int start, int end, int row_eval, struct candidate_solution** head, int* base_sol_number) {
   int i,j, match = 1;
   int g_part[9][9], m1[3][3], m2[3][3], m3[3][3], m4[3][3], m5[3][3], m6[3][3], m7[3][3], m8[3][3], m9[3][3];

   if (start==end) {
      for (i = 0; i < 9 && match != 0; i++) {
         match = check_columns(orig,arr,row_eval,i);
      }
      
      if (match != 0) {
         for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
               g_part[i][j] = orig[i][j];
            }
         }
         part_matrix(g_part,m1,m2,m3,m4,m5,m6,m7,m8,m9);
         for (i = 0; i < 9 && match != 0; i++) {
            if (match_arr[i] <= 0) {
               match = is_number_allow(g_part,m1,m2,m3,m4,m5,m6,m7,m8,m9,row_eval,i,arr[i]);
            }
         }
         if (match != 0) {
            if (row_eval < 9) {
               //printarray(arr, end+1);
               struct candidate_solution *node = (struct candidate_solution*)malloc(sizeof(struct candidate_solution));
               node->arr = (int*)malloc(9 * sizeof(int));
               node->next = NULL;

               for (j = 0; j < 9; j++) {
                  node->arr[j] = arr[j];
               }

               if (*head == NULL) {
                  *head = node;
               } else {
                  node->next = (*head)->next;
                  (*head)->next = node;
               }
               if (row_eval <= 0) {
                  (*base_sol_number)++;
               }
            }
         }
      } else {
         match = 0;
      }
      
      return;
   }

   for (i=start;i<=end;i++) {
      swap((arr+i), (arr+start));
      if (check_starting_array(start,arr,orig[row_eval]) != 0) {
         permutation(orig,arr,orig[row_eval], start+1, end, row_eval,&*head,base_sol_number);
      }
      swap((arr+i), (arr+start));
   }
}

int load_base_arr(int g[9][9], int row_eval, struct candidate_solution* base[9]) {
   int i,k;
   int *arr;
   int base_sol_number = 0;

   arr = new_array(9);
   for (k=0; k<9; k++) {
      row_eval = k;

      for (i = 0; i < 9; i++) {
         arr[i] = i+1;
      }

      base[k] = NULL;

      permutation(g,arr,g[row_eval],0, 9-1, row_eval,&base[k],&base_sol_number);
   }

   free(arr);

   return base_sol_number;
}

void copy_vector(int* dest, int* source, int size) {
   int i;

   for (i=0; i<size; i++) {
      dest[i] = source[i];
   }
}

int super_super_force(int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3], int g_primitiva[9][9]) {
   int i,j;
   int row_eval = 0;
   struct candidate_solution* base[9];
   int g_a[9][9];
   int base_sol_number, current_base_sol = 0;
   int g_part[9][9];
   struct candidate_solution *tmp0, *tmp1, *tmp2, *tmp3, *tmp4, *tmp5, *tmp6, *tmp7, *tmp8;
   int match = 1, solutions = 0;

   for (i = 0; i < 9; i++) {
      for (j = 0; j < 9; j++) {
         g_a[i][j] = g[i][j];
      }
   }

   base_sol_number = load_base_arr(g,row_eval,base);
   tmp0 = base[0];
   
   while(tmp0 != NULL) {
      copy_vector(g_a[0],tmp0->arr,9);
      tmp1 = base[1];
      while(tmp1 != NULL) {
         match = 1;
         for (i = 0; i < 9 && match != 0; i++) {
            match = check_columns(g_a,tmp1->arr,1,i);
         }
         if (match != 0) {
            copy_vector(g_a[1],tmp1->arr,9);
            tmp2 = base[2];
            while(tmp2 != NULL) {
               for (i = 0; i < 9 && match != 0; i++) {
                  match = check_columns(g_a,tmp2->arr,2,i);
               }
               if (match != 0) {
                  copy_vector(g_a[2],tmp2->arr,9);
                  tmp3 = base[3];
                  while(tmp3 != NULL) {
                     for (i = 0; i < 9 && match != 0; i++) {
                        match = check_columns(g_a,tmp3->arr,3,i);
                     }
                     if (match != 0) {
                        copy_vector(g_a[3],tmp3->arr,9);
                        tmp4 = base[4];
                        while(tmp4 != NULL) {
                           for (i = 0; i < 9 && match != 0; i++) {
                              match = check_columns(g_a,tmp4->arr,4,i);
                           }
                           if (match != 0) {
                              copy_vector(g_a[4],tmp4->arr,9);
                              tmp5 = base[5];
                              while(tmp5 != NULL) {
                                 for (i = 0; i < 9 && match != 0; i++) {
                                    match = check_columns(g_a,tmp5->arr,5,i);
                                 }
                                 if (match != 0) {
                                    copy_vector(g_a[5],tmp5->arr,9);
                                    tmp6 = base[6];
                                    while(tmp6 != NULL) {
                                       for (i = 0; i < 9 && match != 0; i++) {
                                          match = check_columns(g_a,tmp6->arr,6,i);
                                       }
                                       if (match != 0) {
                                          copy_vector(g_a[6],tmp6->arr,9);
                                          tmp7 = base[7];
                                          while(tmp7 != NULL) {
                                             for (i = 0; i < 9 && match != 0; i++) {
                                                match = check_columns(g_a,tmp7->arr,7,i);
                                             }
                                             if (match != 0) {
                                                copy_vector(g_a[7],tmp7->arr,9);
                                                tmp8 = base[8];
                                                while(tmp8 != NULL) {
                                                   for (i = 0; i < 9 && match != 0; i++) {
                                                      match = check_columns(g_a,tmp8->arr,8,i);
                                                   }
                                                   if (match != 0) {
                                                      copy_vector(g_a[8],tmp8->arr,9);
                                                      if (matrix_equal(g_a,g_primitiva) != 0) {
                                                         for (i = 0; i < 9; i++) {
                                                            for (j = 0; j < 9; j++) {
                                                               g_part[i][j] = g_a[i][j];
                                                            }
                                                         }
                                                         
                                                         part_matrix(g_part,m1,m2,m3,m4,m5,m6,m7,m8,m9);
                                                         if (check_matrix(g_part, m1, m2, m3, m4, m5, m6, m7, m8, m9) == 1) {
                                                            printf("\n\n¡Yes!, I've found a solution\n\n\n");
                                                            show_matrix(g_part);
                                                            printf("\n... still looking for more of that...\n\n");
                                                            solutions++;
                                                         }
                                                      }
                                                   }
                                                   for (i = 8; i < 9; i++) {
                                                      for (j = 0; j < 9; j++) {
                                                         g_a[i][j] = g[i][j];
                                                      }
                                                   }
                                                   tmp8 = tmp8->next;
                                                   match = 1;
                                                }
                                             }
                                             for (i = 7; i < 9; i++) {
                                                for (j = 0; j < 9; j++) {
                                                   g_a[i][j] = g[i][j];
                                                }
                                             }
                                             tmp7 = tmp7->next;
                                             tmp8 = base[8];
                                             match = 1;
                                          }
                                       }
                                       for (i = 6; i < 9; i++) {
                                          for (j = 0; j < 9; j++) {
                                             g_a[i][j] = g[i][j];
                                          }
                                       }
                                       tmp6 = tmp6->next;
                                       tmp7 = base[7];
                                       tmp8 = base[8];
                                       match = 1;
                                    }
                                 }
                                 for (i = 5; i < 9; i++) {
                                    for (j = 0; j < 9; j++) {
                                       g_a[i][j] = g[i][j];
                                    }
                                 }
                                 tmp5 = tmp5->next;
                                 tmp6 = base[6];
                                 tmp7 = base[7];
                                 tmp8 = base[8];
                                 match = 1;
                              }
                           }
                           for (i = 4; i < 9; i++) {
                              for (j = 0; j < 9; j++) {
                                 g_a[i][j] = g[i][j];
                              }
                           }
                           tmp4 = tmp4->next;
                           tmp5 = base[5];
                           tmp6 = base[6];
                           tmp7 = base[7];
                           tmp8 = base[8];
                           match = 1;
                        }
                     }
                     for (i = 3; i < 9; i++) {
                        for (j = 0; j < 9; j++) {
                           g_a[i][j] = g[i][j];
                        }
                     }
                     tmp3 = tmp3->next;
                     tmp4 = base[4];
                     tmp5 = base[5];
                     tmp6 = base[6];
                     tmp7 = base[7];
                     tmp8 = base[8];
                     match = 1;
                  }
               }
               for (i = 2; i < 9; i++) {
                  for (j = 0; j < 9; j++) {
                     g_a[i][j] = g[i][j];
                  }
               }
               tmp2 = tmp2->next;
               tmp3 = base[3];
               tmp4 = base[4];
               tmp5 = base[5];
               tmp6 = base[6];
               tmp7 = base[7];
               tmp8 = base[8];
               match = 1;
            }
         }
         for (i = 1; i < 9; i++) {
            for (j = 0; j < 9; j++) {
               g_a[i][j] = g[i][j];
            }
         }
         tmp1 = tmp1->next;
         tmp2 = base[2];
         tmp3 = base[3];
         tmp4 = base[4];
         tmp5 = base[5];
         tmp6 = base[6];
         tmp7 = base[7];
         tmp8 = base[8];
         match = 1;
      }
      tmp0 = tmp0->next;
      current_base_sol++;
      printf("Looking for solutions. PROGRESS: %d%%\r",(int)((current_base_sol/(float)base_sol_number)*100));
      tmp1 = base[1];
      tmp2 = base[2];
      tmp3 = base[3];
      tmp4 = base[4];
      tmp5 = base[5];
      tmp6 = base[6];
      tmp7 = base[7];
      tmp8 = base[8];
      match = 1;
   }

   printf("\r                                       \rFinished!");

   for (i = 0; i < 9; i++) {
      tmp0 = base[i];
      while(tmp0 != NULL){
         tmp1 = tmp0->next;
         free(tmp0);
         tmp0 = tmp1;
      }
   }

   return solutions;
}

int solver(int sorting, int p, int * d, int ve[2][9], int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]) {
   int cycles_without_any_change = 0, change = 1, previous_without_be_assigned=0, cycles = 0, exit = 0, gp[9][9], nelements[2][9], elements_nassigned[2][9], rlimsup, rliminf, climsup, climinf, els_without_be_assigned, *tryers, i, j;
  
   while (exit != 1) {
      for (i = 0; i < 9; i++) {
         for (j = 0; j < 9; j++) {
            gp[i][j] = g[i][j];
         }
      }

      sort_by_elements(nelements, m1, m2, m3, m4, m5, m6, m7, m8, m9);
      for (i = 0; i < ( * d); i++) {
         roll_left(nelements);
      }
      switch (nelements[0][0]) {
         case 1:
            rlimsup = 2;
            rliminf = 0;
            climsup = 2;
            climinf = 0;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;

         case 2:
            rlimsup = 2;
            rliminf = 0;
            climsup = 5;
            climinf = 3;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;

         case 3:
            rlimsup = 2;
            rliminf = 0;
            climsup = 8;
            climinf = 6;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;

         case 4:
            rlimsup = 5;
            rliminf = 3;
            climsup = 2;
            climinf = 0;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;

         case 5:
            rlimsup = 5;
            rliminf = 3;
            climsup = 5;
            climinf = 3;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;

         case 6:
            rlimsup = 5;
            rliminf = 3;
            climsup = 8;
            climinf = 6;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;

         case 7:
            rlimsup = 8;
            rliminf = 6;
            climsup = 2;
            climinf = 0;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;

         case 8:
            rlimsup = 8;
            rliminf = 6;
            climsup = 5;
            climinf = 3;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;

         case 9:
            rlimsup = 8;
            rliminf = 6;
            climsup = 8;
            climinf = 6;
            els_without_be_assigned = count_els_without_be_assinged(elements_nassigned, g, rlimsup, rliminf, climsup, climinf);
            break;
      }
      if (els_without_be_assigned == previous_without_be_assigned) {
         change = 0;
         cycles_without_any_change++;
         if (cycles_without_any_change == 9) {
            exit = 1;
         }
      } else {
         change = 1;
      }
      if (els_without_be_assigned > 0) {
         if (change == 1) {
            previous_without_be_assigned = els_without_be_assigned;
         }
         tryers = new_array(els_without_be_assigned);
         if (sorting == 1) {
            sort_array_asc(elements_nassigned, 9);
            for (i = 0; i < els_without_be_assigned; i++) {
               tryers[i] = elements_nassigned[0][i];
            }
         } else {
            for (i = 8; i >= (9 - els_without_be_assigned); i--) {
               tryers[(9 % i) - 1] = elements_nassigned[0][i];
            }
         }
         if (p <= els_without_be_assigned) {
            force(tryers[p], g, rlimsup, rliminf, climsup, climinf);
            part_matrix(g, m1, m2, m3, m4, m5, m6, m7, m8, m9);
            if (algorithm(gp, g, ve, m1, m2, m3, m4, m5, m6, m7, m8, m9) == 0) {
               part_matrix(g, m1, m2, m3, m4, m5, m6, m7, m8, m9);
               exit = 1;
            }
         }
         free(tryers);
         if (els_without_be_assigned == 1) {
            cycles++;
         }
         if (cycles == 9) {
            exit = 1;
         }
      } else {
         exit = 1;
      }
   }
   return is_full_matrix(g);
}

int check_el_in_minimatrix(int element, int m[3][3]) {
   int i, j, match = 0;

   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         if (m[i][j] == element) {
            match++;
         }
      }
   }
   if (match > 1) {
      return 1; //at least, one element repeated in one minimatrix
   } else {
      return 0; //any repeated element in one minimatrix
   }
}

int check_matrix(int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]) {
   int e, i, j = 1, exists = 0, g_matches = 0, min_matches = 0;

   for (e = 1; e < 10; e++) {
      for (i = 0; i < 9; i++) {
         for (j = 0; j < 9; j++) {
            if (g[i][j] == e) {
               exists++;
            }
         }
         if (exists > 1) {
            g_matches++;
         }
         exists = 0;
      }
      exists = 0;
   }
   
   for (e = 1; e < 10; e++) {
      for (i = 0; i < 9; i++) {
         for (j = 0; j < 9; j++) {
            if (g[j][i] == e) {
               exists++;
            }
         }
         if (exists > 1) {
            g_matches++;
         }
         exists = 0;
      }
      exists = 0;
   }
   
   for (e = 1; e < 10; e++) {
      min_matches += check_el_in_minimatrix(e, m1);
      min_matches += check_el_in_minimatrix(e, m2);
      min_matches += check_el_in_minimatrix(e, m3);
      min_matches += check_el_in_minimatrix(e, m4);
      min_matches += check_el_in_minimatrix(e, m5);
      min_matches += check_el_in_minimatrix(e, m6);
      min_matches += check_el_in_minimatrix(e, m7);
      min_matches += check_el_in_minimatrix(e, m8);
      min_matches += check_el_in_minimatrix(e, m9);
   }
   
   if (g_matches > 0 || min_matches > 0) {
      return 0;
   } else {
      return 1;
   }
}

int matrix_equal(int g[9][9], int h[9][9]) {
   int equal = 0, i, j;

   for (i=0; i<9; i++) {
      for (j=0; j<9; j++) {
         equal = equal || g[i][j] == h[i][j];
      }
   }

   return equal;
}