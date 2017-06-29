#include <stdlib.h>
	#include <stdio.h>
	#include <math.h>
	 	/* globals ... */
    #define HEADER "**********************************************************\n" \
               "             Metodo de iteracao de jacobi                     \n" \
	               "    para matrizes de diagonal principal dominante         \n" \
	               "**********************************************************\n"

	#define EPSILON 0.0000001
	#define MAX_PRINT_ITERS 333
	 
	int SHOW_ITERS = 0; /* defaults to NO ... */
	 
	/* input matrix elements */
	void getInput( int, double** mat );
	/* check if diagonally dominant */
	int checkIfDD( int, double** mat );
	/* calculate and display answers */
	void jacobiCalcDisplay( int, double** mat );
	 
	double dotProd( int num, double* v1, double* v2 );
	 
	void showXcheck( int num, double** mat, double* v1, double* v2 );
 
	int checkFlags( int num, int flags[] );
	 
/* free dynamic memory occupied by 2D square matrix */
	void freeMat( int num, double** sqMat );
 
	int more()/* defaults to yes ... */
	{
	    int c, reply ;
	    printf("\nDeseja fazer outra vez ... (s/n) ? ");
	    reply = c = getchar();
	    while( c!='\n' ) c=getchar(); /* flush stdin ... */
	    return !(reply=='n' || reply=='N');
	}

	int main()
	{
	    double **mat;
	    int dummy, num;
	 
	    do
	    {
	        puts( HEADER );
	         
	        printf( "mostre o resultado de cada iteracao 1=sim 0= nao ? " );
	        scanf("%d", &SHOW_ITERS);
	        dummy = SHOW_ITERS; /* get a backup copy ... */
	        while( dummy != '\n' ) dummy = getchar(); /* flush stdin ... */
	         
	        if( !(SHOW_ITERS=='1'||SHOW_ITERS=='y'||SHOW_ITERS=='Y') )
	        {
	            puts("Sim");
	            SHOW_ITERS =0;
	        }
	        else 
	 				puts("Nao");
	 
	        printf("\nResolver sistema linear ...\n");
	        printf("Digite o numero de icognitas a serem encontradas: ");
	        num = 0;
	        scanf("%d", &num); /* num of unknowns */
	        while( getchar() != '\n' ) ; /* flush stdin ... */
         
	        mat = NULL;
	        if( num>0 && (mat = (double**) malloc(num*sizeof(double*))) )
	        {
	            getInput(num, mat);
	            if( checkIfDD(num, mat) ) jacobiCalcDisplay(num,mat);
	            else freeMat(num, mat);
	        }
	        else
	        {
	            puts("Memoria excedida tente novamente.");
	            if( mat != NULL ) free( mat );
	        }
	    }while( more() );
	    return 0;
	}
	 
	 
	void getInput( int numUnKnowns, double** mat )
	{
	    int i, j;
	     
	    printf
	    (
	        "\nDigite os valores para as linhas e colunas especificadas a baixo ...\n"
	        "(A ultima coluna e o valor do lado esquerdo da equacao.)\n"
	    );
	    for( i = 0 ; i < numUnKnowns ; i++ )
	    {
	        mat[i] = (double*) malloc( (numUnKnowns+1)*sizeof(double) );
	        puts("");
	        for( j = 0 ; j < numUnKnowns+1 ; j++ )
	        {
	            printf("matriz[%d][%d] : ", i, j);
	            if( scanf("%lf", &mat[i][j]) != 1 )
	            {
	                --j;
	                puts("Erro tente novamente com um numero valido.");
	            }
	            while( getchar() != '\n' ) ; /* flush stdin ... */
	        }
	    }
	 
	    printf("\nA matriz digitada:\n\n");
	    for( i = 0 ; i < numUnKnowns ; i++ )
	    {
	        for( j = 0 ; j < numUnKnowns+1 ; j++ )
	            printf("%+9f ", mat[i][j]);
	             
	        puts("");
	    }
	 
	    printf("\nPressione Enter ");
	    getchar();
	}
	 
	/* Check if the matrix entered is strictly diagonally dominant */
	int checkIfDD( int numUnKnowns, double** mat )
	{
	    int   m, n, dd = 0;
	    double* chkdd;
	    double* sumdd = (double*) malloc( numUnKnowns*sizeof(double) );
	    chkdd = (double*) malloc( numUnKnowns*sizeof(double) );
	 
	    for( m = 0 ; m < numUnKnowns ; m++ )
	        chkdd[m] = sumdd[m] = 0; /* all set to zero ... */
	     
	    printf("\nChecando se a Matriz possui diagonal principal dominante...");
	 
	    for( m = 0 ; m < numUnKnowns ; m++ )
	    {
	        for( n = 0 ; n < numUnKnowns ; n++ )
	        {
	            sumdd[m] += fabs(mat[m][n] );
	        }
	        sumdd[m] -= fabs(mat[m][m]);
	        chkdd[m] = fabs(mat[m][m]);
	         
	        if(chkdd[m] > sumdd[m])
	        {
	            printf("\n%f > %f",chkdd[m],sumdd[m]);
	            dd++;
	        }
	        else
	            printf("\n%f !> %f",chkdd[m],sumdd[m]);
 
	    }
	    if(dd == numUnKnowns)
	    {
	        printf
	        (
	            "\nSim "
	            "\nA matriz possui diagonal principal dominante."
	            
	        );
	        getchar();
    }
	    else
	    {
	        printf
	        (
	            "\nNao"
	            "\nA matriz n possui diagonal principal dominante!"
	 
	 
	            
	        );
	        getchar();
	        free( sumdd );
	        free( chkdd );
	        return 0; /* false */
	    }
	     
	    free( sumdd );
	    free( chkdd );
	    return 1; /* true */
	}
 
	/* uses global SHOW_ITERS ... */
	void jacobiCalcDisplay( int numUnKnowns, double** mat )
	{
	    int* flag;
	    int i, j, counter = 0;
	    double* res;
	    double* var = (double*) malloc( numUnKnowns*sizeof(double) );
	    res = (double*) malloc( numUnKnowns*sizeof(double) );
	    flag = (int*) malloc( numUnKnowns*sizeof(int) );
	     
	    for(i = 0 ; i < numUnKnowns ; i++ )
	        var[i] = res[i] = flag[i] = 0;
	 
	    printf( "*********************\n");
	    printf( "Inicio do calculo    \n");
	    printf( "*********************\n");
	 
	    do
	    {
	        counter++;
	        /* for each iteration keep a copy of the old results ... */
	        for(i = 0 ; i < numUnKnowns ; i++ )
	        {
	            var[i] = res[i];
	        }
	 
	        if( SHOW_ITERS ) printf("\nNumero de iteracoes %d ...\n", counter);
	         
	        for(i = 0 ; i < numUnKnowns ; i++ ) /* calculation */
	        {
	            res[i] = mat[i][numUnKnowns];
	            for(j = 0 ; j < numUnKnowns ; j++ )
                res[i] = res[i] - mat[i][j]*var[j] ;
	                 
	            res[i] = res[i] + mat[i][i]*var[i] ;
	            res[i] = res[i] / mat[i][i] ;
	            if( SHOW_ITERS ) printf("%c = %f\n", 'a'+i, res[i]);
	            if( fabs(res[i] - var[i]) < EPSILON ) /* stop condition */
	                flag[i]++;
	 
	            if( counter==MAX_PRINT_ITERS) SHOW_ITERS = 0;
	        }
	    }while( !checkFlags( numUnKnowns, flag ) );
	 
	    printf( "\n********************************\n");
	    printf( "os resultados de %d Iteracoes     \n", counter);
	    printf( "********************************\n");
	 
	    
	     
	    
	    for( i = 0 ; i < numUnKnowns ; i++)
	    {
	        var[i] = dotProd( numUnKnowns, mat[i], res );
	        
    }
	    showXcheck( numUnKnowns, mat, res, var );
	 
	    
	 
	    printf("\nVetor solucao\n");
	    for( i = 0 ; i < numUnKnowns ; i++)
	    {
	        printf("%c = %+f\n", 'a'+i, res[i]);
	        free(mat[i]);
	    }
	    free( mat );
	    free( flag );
	    free( res );
	    free( var );
	}
	 
	int checkFlags( int num, int flags[] )
	{
	    int i;
	    for( i=0; i<num; ++ i)
	        if( flags[i] == 0 ) return 0;
	    return 1;
	}
	 
	double dotProd( int num, double* v1, double* v2 )
	{
	    int i;
	    double sum =0;
	    for( i=0; i<num; ++i ) sum += v1[i]*v2[i];
	    return sum;
	}
	 
	void showXcheck( int num, double** mat, double* v1, double* v2 )
	{
	    int i, j;
    
    for( i = 0 ; i < num ; i++)
    {
	        printf("|");
	        for( j =0 ; j < num ; j++ )
	            printf("%+9f ", mat[i][j] );
	        printf("| |%+9f| |%+9f|vs|%+9f|\n", v1[i], v2[i], mat[i][num]);
	    }
	}
	 
	 
	void freeMat( int num, double** sqMat )
	{
	    int i;
	    for( i=num-1; i>=0; --i )
	        free( sqMat[i] );
	    free( sqMat );
	}