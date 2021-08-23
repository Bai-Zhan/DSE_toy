/***************************************************************
 * The DSE calculations may be conducted with different truncation, 
 * different temperature or chemical potential or different parameters.
 * 
 * We would like to store results from different conditions in different folder,
 * in order for easy search.
 * 
 * In this file, we provide a function which automatically generate the folder
 * in which our results will be stored. 
 * 
 * The corresponding path name will be stored in a global string variable, 'RESULT_PATH' (declared in '/src/constants.c').
 * 
 * The input IF_MKDIR determines whether to create the folder.
 * If IF_MKDIR == _CREATE_NONEXISTING_ON_, then the correponding folder will be created;
 * if IF_MKDIR ==_CREATE_NONEXISTING_OFF_, then the corresponding folder will not be created.
 **************************************************************/

#include"stdlib.h"
#include"stdio.h"
#include"unistd.h"
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

#include"constants.h"
#include"IO.h"



int CREATE_RESULT_PATH(int IF_MKDIR)
{
/***** If the folder './result' does not exist, create it. ***/
	int	IF_EXIST = access("./result",0);
	if(IF_EXIST !=0)mkdir("result",S_IRWXU);

	extern char * RESULT_PATH;
	extern int N_NAME;
	RESULT_PATH=(char *)malloc(N_NAME*sizeof(char));

/**** First layer of the folders: vertex and gluon model ***/
    extern int VERTEX;
	char str2[30];
	if(VERTEX==_VERTEX_RAINBOW_)sprintf(str2,"%s","RL");
	else if(VERTEX==_VERTEX_BC_)sprintf(str2,"%s","BC");
	else if(VERTEX==_VERTEX_CLR_)sprintf(str2,"%s","CLR");
	else{printf("wrong vertex! %s %i\n",__FILE__,__LINE__);exit(0);}

    extern int GLUON_KERNEL,GLUON_UV_TAIL;
	char str4[50];
	if (GLUON_KERNEL == _GLUON_KERNEL_MT_ && GLUON_UV_TAIL == _GLUON_UV_TAIL_OFF_)
		sprintf(str4, "%s", "GAUSS");  // Gauss gluon model is the Maris-Tandy model without the ultra-violet tail.
	else if (GLUON_KERNEL == _GLUON_KERNEL_MT_ && GLUON_UV_TAIL == _GLUON_UV_TAIL_NORMAL_)
		sprintf(str4, "%s", "MT");  // 'MT' is short for Maris-Tandy model
	else if (GLUON_KERNEL == _GLUON_KERNEL_QC_ && GLUON_UV_TAIL == _GLUON_UV_TAIL_OFF_)
		sprintf(str4, "%s", "IC");  // 'IC' is short for 'infrared constant'. This model is the same as Qin-Chang model except it does not have UV tail.
	else if (GLUON_KERNEL == _GLUON_KERNEL_QC_ && GLUON_UV_TAIL == _GLUON_UV_TAIL_NORMAL_)
		sprintf(str4, "%s", "QC"); // 'QC' is short for 'Qin-Chang' model.
	else
	{
		printf("wrong gluon model! %s %i\n",__FILE__,__LINE__);
		exit(0);
	}

	sprintf(RESULT_PATH,"result/%s_%s",str2,str4);
	int MAKE_PATH_SUCCESS = 0;
	if (IF_MKDIR == _CREATE_NONEXISTING_ON_)
	{
		IF_EXIST = access(RESULT_PATH, 0);
		if (IF_EXIST != 0)
			MAKE_PATH_SUCCESS = mkdir(RESULT_PATH, S_IRWXU);
	}
		
/**** 2nd layer of the folder: The medium condition ******/
	extern int MEDIUM;
	char str3[20];
	if(MEDIUM==_MEDIUM_T0MU0_)
		sprintf(str3, "%s", "T0_MU0");
	else if (MEDIUM == _MEDIUM_TMU_)
		sprintf(str3, "%s", "T_MU");
	else if(MEDIUM == _MEDIUM_T0MU_)
		sprintf(str3, "%s", "T0_MU");
	strcat(RESULT_PATH, "/");
	strcat(RESULT_PATH, str3);

	if (IF_MKDIR == _CREATE_NONEXISTING_ON_)
	{
		IF_EXIST = access(RESULT_PATH, 00);
		if (IF_EXIST != 0)
			MAKE_PATH_SUCCESS = mkdir(RESULT_PATH, S_IRWXU);
		if (MAKE_PATH_SUCCESS == 0)
			printf("RESULT_PATH = %s\n", RESULT_PATH);
	}

		
/***** 3rd layer of the folder:  parameters in the vertex and gluon model ****/


	extern double GLUON_D,GLUON_OMEGA;
	char str_D[50];
	sprintf(str_D, "D%10.4e", GLUON_D);

	char str_omega[50];
	sprintf(str_omega,"omega%5.3f",GLUON_OMEGA);
	
	
	extern int GLUON_KERNEL;
	if(GLUON_KERNEL==_GLUON_KERNEL_MT_ || GLUON_KERNEL==_GLUON_KERNEL_QC_)
	{
		strcat(RESULT_PATH, "/");
		strcat(RESULT_PATH, str_D);

		strcat(RESULT_PATH, "_");
		strcat(RESULT_PATH, str_omega);
	}
	else{printf("wront GLUON_KERNEL! %s %i\n",__FILE__,__LINE__);exit(0);}

	if (IF_MKDIR == _CREATE_NONEXISTING_ON_)
	{
		IF_EXIST = access(RESULT_PATH, 00);
		if (IF_EXIST != 0)
			MAKE_PATH_SUCCESS = mkdir(RESULT_PATH, S_IRWXU);
		if (MAKE_PATH_SUCCESS == 0)
			printf("RESULT_PATH = %s\n", RESULT_PATH);
	}
		
		
/***** 4th layer of the folder:  renormalization scheme, renornalization point and current quark mass****/

	extern int ReScheme;
	extern double RePoint,Z2,Z4;
	char str_RENORM[200];
	if(ReScheme==_RENORMALIZATION_OFF_) sprintf(str_RENORM,"Re0");
	else if(ReScheme==_RENORMALIZATION_CURRENT_MASS_INDEPENDENT_)
		sprintf(str_RENORM, "Re1_(Z2)%6.4f_(Z4)%6.4f",Z2,Z4);
	else if(ReScheme==_RENORMALIZATION_CURRENT_MASS_DEPENDENT_)
		sprintf(str_RENORM, "Re3_RePoint%06.3f", RePoint);
	else
	{
		printf("wrong ReScheme! %s %i\n", __FILE__, __LINE__);
		exit(0);
	}
	
	
	extern double Mass;
	char str_mass[30];
	sprintf(str_mass,"Mass%10.4e",Mass);

	strcat(RESULT_PATH, "/");
	strcat(RESULT_PATH, str_RENORM);
	strcat(RESULT_PATH, "_");
	strcat(RESULT_PATH, str_mass);

	if (IF_MKDIR == _CREATE_NONEXISTING_ON_)
	{
		IF_EXIST = access(RESULT_PATH, 00);
		if (IF_EXIST != 0)
			MAKE_PATH_SUCCESS = mkdir(RESULT_PATH, S_IRWXU);
		if (MAKE_PATH_SUCCESS == 0)
			printf("RESULT_PATH = %s\n", RESULT_PATH);
	}
	
	
	
/***** 5th layer of the folder:  temperature and chemical potential****/
	
	extern double Mu, Temperature;
	if (MEDIUM == _MEDIUM_TMU_)
	{
			char str6[50];
			sprintf(str6,"/T%10.5e_Mu%10.5e",Temperature,Mu);
			strcat(RESULT_PATH,str6);
	}
	else if (MEDIUM == _MEDIUM_T0MU_)
	{
		char str6[50];
		sprintf(str6, "/Mu%10.5e", Mu);
		strcat(RESULT_PATH, str6);
	}
	else if (MEDIUM == _MEDIUM_T0MU0_);
	else
	{
		printf("wrong T_MU!");
		exit(0);
	}

	if (IF_MKDIR == _CREATE_NONEXISTING_ON_)
	{
		IF_EXIST = access(RESULT_PATH, 00);
		if (IF_EXIST != 0)
			MAKE_PATH_SUCCESS = mkdir(RESULT_PATH, S_IRWXU);
		if (MAKE_PATH_SUCCESS == 0)
			printf("RESULT_PATH = %s\n", RESULT_PATH);
	}


/***** Check if the folder has been successfully created ***************/
	IF_EXIST = access(RESULT_PATH, 00);
	if (IF_EXIST != 0)
	{
		printf("no such folder	%s\n", RESULT_PATH);
		return -1;
	}
	else
	{
		printf("RESULT_PATH=	%s\n", RESULT_PATH);
		return MAKE_PATH_SUCCESS;
	}

	return MAKE_PATH_SUCCESS;
}