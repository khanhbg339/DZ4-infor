#include <stdio.h>

#include <malloc.h>

#include <stdlib.h>

#include <string.h>

#include <locale.h>

#include <conio.h>

void CountingSort(int* a, char* x, int n, int min, int max); 
int main() 
{  
    int n; // n - количество узлов
    printf("Please enter the number of vertices! "); // Добавление значения количества узлов
    scanf("%d", & n);
    char cur; // cur - текущий введенный символ                                    
    int k = 1, length = 0, dem = 0, min=0, max=0; // length - количество рёбер
    int ** e = (int ** ) malloc(n * sizeof(int * )); // выделение памяти для массива сохранения матрицы инцидентивности графа
    int *a = (int *)calloc(n, sizeof(int)); // выделение памяти для массива сохранения степени вершин графа
    //----------------------//
    //Ввод матрицы инцидентивности//
    //----------------------//
  for (int b = 0; b < n; b++) {
    e[b] = (int * ) malloc(sizeof(int));
  }
  cur = getchar(); // Переход на новую строку
  for (int i = 0; i < n; i++) {
    printf("%d :", i + 1);
    cur = getchar(); // Берём первый символ
    for (int j = 0; cur != '\n'; j++) {
      if ((cur == '1') || (cur == '0')) {
        e[i] = (int * ) realloc(e[i], sizeof(int) * k); // Выделение памяти на один больше символ
        e[i][k - 1] = cur - '0'; // Запись значения в массиве 
        k++;
      }
      cur = getchar(); // Получение нового значения
    }
    cur = '\0'; // Для перехода на новую строку         
    length = k - 1; // Определение длины строки
    k = 1;
  }
  printf("\n\n");
  //-----------------//
  //Обозначение узлов//
  //-----------------//
  char *x=(char*)calloc(n, sizeof(char));
  printf("\nEnter the names of the vertices: ");
  for (int i = 0; i < n; i++) {
    printf("\nx[%d]=", i + 1);
    x[i] = getche();
  }
  printf("\n\n");
  getchar();
  //-----------------------------//
  //Считание степени вершин графа//
  //-----------------------------//
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < length; j++)
    {
        dem = dem + e[i][j];
    }
    if(dem < min)
    {
        min = dem;
    }
    if(dem > max)
    {
        max = dem;
    }
    a[i]=dem;
    dem=0;
  }
  //----------------------------------//
  //Вызов функции сортировки подсчётом//
  //----------------------------------//
  printf("The vertices of the graph with odd degrees are arranged in descending order: \n");
  CountingSort(a, x, n, min, max);
 //------------------------------------//
  //Очистка памяти динамических массивов//
  //------------------------------------//
  for (int i = 0; i < n; i++) {
    free(e[i]);
  }
  free(e);
  free(a);
  free(x);
  return 0;
}
//----------------------------//
//Фукнция сортировки подсчётом//
//----------------------------//
void CountingSort(int* a, char* x, int n, int min, int max) 
{ 
    int d = 0, cs = max - min; 
    // массив сохранения количества присутствия элементов
    int count[cs + 1]; 
    // Передавать значение элементов массива на 0
    for(int i = 0; i <= cs; i++) 
        count[i] = 0;
    // Считать количество присутствия элементов в главном массиве и переписать в новый массив      
    for(int i = 0; i < n; i++) 
        count[a[i] - min]++;
    //Отображение на экране результатов вершин с нечётными степенями по убываню 
    for(int i=cs; i>=0; i--)
    {    if(count[i]>0)
        {
            for(int j=0; j < n; j++)
            {
                if((a[j]==i)&&(i%2))
                printf("%c", x[j]);
            }
        }
    }          
}