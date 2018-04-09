// Criado em				: 2018/04/06
// Ult. Atualização : 2018/04/09
// Autor			      : Marcio Anicete <marcioanicete@gmail.com>
// Notes      			: Calculo de uma integração numérica
// Compilação				: gcc integral.c -lm
// Execução					: ./a.out a b n

 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n, i;
	double area, a, b, *x, dz, *y,z;
	FILE *arquivo;
	arquivo = fopen("ponto.dat", "w");
	double g(double z)
	{
		return pow(sin(z),2);
	}
	if(argc != 4)
	{
			printf("\n Execute com %s a b n\n", argv[0]);
			exit(0); // a, b e n são os limites de integração;
	}
	a = atof(argv[1]);
	b = atof(argv[2]);
	n = atoi(argv[3]);
	dz = (b-a)/n;

	for(z= a; z<b; z+= dz)
	{
		fprintf(arquivo, "%e %e\n", z, g(z));
	}
	fclose(arquivo);
	arquivo = fopen("ponto.dat", "r");	
	y = (double *) calloc(n, sizeof(double));	
	x = (double *) calloc(n, sizeof(double));

	for(i= 0; i<=n; i++)
	{
		fscanf(arquivo," %lf %lf\n", &x[i], &y[i]);
	}
	fclose(arquivo);
	
	area= 0.0;
	for(i= 0; i<n-1; i++)
	{
		area+= (y[i+1]+y[i])*(x[i+1]-x[i])*0.5;
	}	
	printf("\n A integral é %e\n", area);


	free(x);
	free(y);
	return 0;
}


