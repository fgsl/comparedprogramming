/**
 * C implementation of Eudoxo Algorithm for square root
 * @author Flávio Gomes da Silva Lisboa <flavio.lisboa@fgsl.eti.br>
 * Compiling with GCC: gcc eudoxo.c -o eudoxo -lm
 **/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

/**
 *  https://www.gnu.org/software/libc/manual/html_node/Elapsed-Time.html
 *  time_t tv_sec: This represents the number of whole seconds of elapsed time.
 *  this function returns time in microseconds
**/
long microtime(){
	struct timeval currentTime;
	gettimeofday(&currentTime, NULL);
	return currentTime.tv_sec * (int)1e6; //+ currentTime.tv_usec;
}


int main(int argc, char *argv[]){
	if (argc<3){
		printf("\nType: php eudoxo.php [number to extract root square] [number of iterations]\n");
		exit(0);
	}

	float p;
	int n;
       	sscanf(argv[1],"%f", &p); // square
	sscanf(argv[2],"%d", &n); // iterations

	long start = microtime();

	float x = ((1 + p)/2);

	printf("\n n=0; x=%f\n",x);

	for (int i=1;i<n;i++){
		x = (((p/x) + x)/2);
		printf("\n n=%d; x=%f; x^2=%f\n",i,x,(x*x));
	}	

	long elapsedtime = microtime() - start;

	printf("\nElapsed time: %ldms\n",elapsedtime*1000);

	double vlf = sqrt(p);

	printf("\nValue of language function: %f\n",vlf); 
}
