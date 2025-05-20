#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Min_val 10
#define Max_val 99

//Reservo la memoria para matriz mxn de enteros
int **reservar(int filas, int columnas) {
	int **matriz = (int **)malloc(filas * sizeof(int *));
	for (int i = 0; i < filas; i++) {
		*(matriz + i) = (int *)malloc(columnas * sizeof(int)); 
	}
	return matriz;
}

//Llenar matriz con valores diferentes a cero de manera aleatoria
void matrizAleatoria(int **matriz, int filas, int columnas) {
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
	            *(*(matriz + i) + j) = (rand() % (Max_val - Min_val + 1)) + Min_val;

		}
	}
}

//Imprimir matriz aleatoria 
void imprimir(int **matriz, int filas, int columnas) {
	printf("Matriz (%dx%d):\n", filas, columnas);
	for (int i = 0; i < filas; i++) {
		for (int j = 0; j < columnas; j++) {
	            printf("%3d ", *(*(matriz + i) + j));
		}
		printf("\n");
	}
}

//Redimensionar la matriz a otro tamano y mantiendo valores 
int **ajustarTamano(int **original, int m, int n, int m2, int n2) {
	int **nueva = reservar(m2, n2);
	
	//Usar datos que ya existen
	for (int i = 0; i < m2 && i < m; i++) {
		for (int j = 0; j < n2 && j < n; j++) {
			*(*(nueva + i) + j) = *(*(original + i) + j);
		}
	}

	//Datos nuevos si aumenta el tamano
	for (int i = 0; i < m2; i++) {
		for (int j = 0; j < n2; j++) {
			if (i >= m || j >= n) {
				*(*(nueva + i) + j) = (rand() % (Max_val - Min_val + 1)) + Min_val;
			}
		}
	}

	//Libero memoria de matriz original
	for (int i = 0; i < m; i++) {
		free(*(original +i));
	}
	free(original);
	return nueva;
}

//Liberar memoria total
void liberar(int **matriz, int filas) {
	for (int i = 0; i < filas; i++) {
		free(*(matriz + i));
	}
	free(matriz);
}

int main() {
	int m, n, m2, n2;
	int **matriz;

	srand(time(NULL));

	printf("Tamano inicial de la matriz(mxn): ");
	scanf("%dx%d", &m, &n);

	matriz = reservar(m, n);
	matrizAleatoria(matriz, m, n);
	imprimir(matriz, m, n);

	printf("\n Tamano nuevo de la matriz(mxn): ");
	scanf("%dx%d", &m2, &n2);

	matriz = ajustarTamano(matriz, m, n, m2, n2);
	imprimir(matriz, m2, n2);

	liberar(matriz, m2);
	return 0;
}





	
