
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

struct candidate_solution {
   struct candidate_solution *next;
   int row_eval;
   int* arr;
};

int algorithm(int gprimitive[9][9], int g[9][9], int ve[2][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]);
int assigner(int element, int g[9][9], int m[3][3], int rlimsup, int rliminf, int climsup, int climinf);
int calc_minimatrix(int x, int y);
int check_columns(int g[9][9], int* arr, int row_eval, int index);
int check_el_in_minimatrix(int element, int m[3][3]);
int check_matrix(int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]);
int check_minimatrix(int** g);
int check_starting_array(int idx, int *arr, int *match);
int compair_minimatrix(int m1[3][3], int m2[3][3]);
void count_elements(int g[9][9], int ve[2][9]);
int count_els_without_be_assinged(int elements_nassigned[2][9], int g[9][9], int rlimsup, int rliminf, int climsup, int climinf);
int count_zeros_g(int m[9][9]);
int count_zeros_m(int m[3][3]);
void copy_vector(int* dest, int* source, int size);
int file(int g[9][9],char argv[1]);
int find_in_minimatrix(int element, int g[9][9], int m[3][3], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]);
int force(int element, int g[9][9], int rlimsup, int rliminf, int climsup, int climinf);
//void insert_data(int m[9][9]);
int is_full_matrix(int g[9][9]);
int is_number_allow(int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3], int x, int y, int number);
int load_base_arr(int g[9][9], int row_eval, struct candidate_solution* base[9]);
int* new_array(int els_without_be_assigned);
int matrix_equal(int g[9][9], int h[9][9]);
void part_matrix(int m[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]);
void permutation(int g[9][9], int *arr, int *match_arr, int start, int end, int row_eval, struct candidate_solution** head, int* base_sol_number);
void printarray(int arr[], int size);
void roll_left(int ve[2][9]);
void show_array(int v[2][9]);
void show_matrix(int m[9][9]);
void show_minimatrix(int m[3][3]);
int solver(int sorting, int p, int * d, int ve[2][9], int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]);
int sort_array_desc(int ve[2][9], int n);
int sort_array_asc(int ve[2][9], int n);
void sort_by_elements(int nelements[2][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]);
int super_force(int ve[2][9], int g[9][9], int gprimitive[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3]);
int super_super_force(int g[9][9], int m1[3][3], int m2[3][3], int m3[3][3], int m4[3][3], int m5[3][3], int m6[3][3], int m7[3][3], int m8[3][3], int m9[3][3], int g_primitiva[9][9]);
void swap(int *a, int *b);
