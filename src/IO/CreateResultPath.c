#include"stdlib.h"
#include"stdio.h"
#include"unistd.h"
#include<sys/stat.h>
#include<sys/types.h>

#include"constants.h"
#include"IO.h"

int CREATE_RESULT_PATH(int IF_MKDIR)
{
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
		sprintf(str4, "%s", "GAUSS");
	else if (GLUON_KERNEL == _GLUON_KERNEL_MT_ && GLUON_UV_TAIL == _GLUON_UV_TAIL_NORMAL_)
		sprintf(str4, "%s", "MT");
	else if (GLUON_KERNEL == _GLUON_KERNEL_QC_ && GLUON_UV_TAIL == _GLUON_UV_TAIL_OFF_)
		sprintf(str4, "%s", "IC");
	else if (GLUON_KERNEL == _GLUON_KERNEL_QC_ && GLUON_UV_TAIL == _GLUON_UV_TAIL_NORMAL_)
		sprintf(str4, "%s", "QC");
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
		//	char str3[20];
		//	if(T_MU==0)
		//	{
		//		sprintf(str3,"%s","T0_MU0");
		//		Temperature=0;Mu=0;
		//	}
		//	else if(T_MU==1)
		//	{
		//		if(IFDFUNCT==0) sprintf(str3,"%s","T_MU");
		//		else if(IFDFUNCT==1) sprintf(str3,"%s","T_MU_DFUNCT");
		//		else if(IFDFUNCT==2) sprintf(str3,"%s","T_MU_DFUNCT2");
		//		else
		//		{
		//			printf("error IFDFUNCT %s %i  \n",__FILE__,__LINE__);
		//			exit(0);
		//		}
		//
		//
		//	}
		//	else if(T_MU==2)
		//	{
		//		sprintf(str3,"%s","T0_MU");
		//		Temperature=0;
		//	}
		//	strcat(RESULT_PATH,"/");
		//	strcat(RESULT_PATH,str3);
		//
		//	if(IF_MKDIR==1)
		//	{
		//		IF_EXIST = access(RESULT_PATH,00);
		//		if(IF_EXIST!=0)MAKE_PATH_SUCCESS = mkdir(RESULT_PATH,S_IRWXU);
		//		if(MAKE_PATH_SUCCESS ==0)printf("RESULT_PATH = %s\n",RESULT_PATH);
		//	}
		//
		//
		//	//路径第3层：顶点和胶子模型中的参数
		//	if(VERTEX<100)
		//	{
		//
		//		char str_ETA[50];
		//		sprintf(str_ETA,"ETA%06.3f",ETA);
		//
		//		char str_D[50];
		//		sprintf(str_D,"D%10.4e",GLUON_GAUSS_D);
		//
		//		char str_DL[50];
		//		sprintf(str_DL,"DL%10.4e",GLUON_D_LONG);
		//
		//		char str_DT[50];
		//		sprintf(str_DT,"DT%10.4e",GLUON_D_TRAN);
		//
		//		char str_omega[50];
		//		sprintf(str_omega,"omega%5.3f",GLUON_GAUSS_OMEGA);
		//
		//		char str_alpha[50];
		//		sprintf(str_alpha,"alpha%9.3e",ALPHA);
		//
		//		char str_alphaT[50];
		//		sprintf(str_alphaT,"alphaT%9.3e",ALPHA_T);
		//
		//		char str_mG[50];
		//		sprintf(str_mG,"mG%9.3e",GLUON_MASS);
		//
		//		char str_Lambda[50];
		//		sprintf(str_Lambda,"Lambda%10.4e",LambdaV_PV);
		//
		//		if(VERTEX==3 || VERTEX==4)
		//		{
		//			strcat(RESULT_PATH,"/");
		//			strcat(RESULT_PATH,str_ETA);
		//		}
		//
		//		if(GLUON_basic==10 || GLUON_basic==20)
		//		{
		//			if(GLUON_thermal==0)
		//			{
		//				if(VERTEX==3 ||VERTEX==4)
		//				{
		//					strcat(RESULT_PATH,"_");
		//					strcat(RESULT_PATH,str_D);
		//				}
		//				else
		//				{
		//					strcat(RESULT_PATH,"/");
		//					strcat(RESULT_PATH,str_D);
		//				}
		//			}
		//
		//			else if(GLUON_thermal==10)
		//			{
		//				if(VERTEX==3 || VERTEX==4) strcat(RESULT_PATH,"_");
		//				else strcat(RESULT_PATH,"/");
		//
		//				strcat(RESULT_PATH,str_DL);
		//				strcat(RESULT_PATH,"_");
		//				strcat(RESULT_PATH,str_DT);
		//
		//			}
		//
		//			if(GLUON_basic==10 || GLUON_basic==20)
		//			{
		//				strcat(RESULT_PATH,"_");
		//				strcat(RESULT_PATH,str_omega);
		//			}
		//
		//			if(GLUON_medium==10 || GLUON_medium==11)
		//			{
		//				strcat(RESULT_PATH,"_");
		//				strcat(RESULT_PATH,str_alpha);
		//			}
		//
		//			if(GLUON_medium==20)
		//			{
		//				strcat(RESULT_PATH,"_");
		//				strcat(RESULT_PATH,str_alphaT);
		//			}
		//
		//			char str_PoleHandle[50];
		//			sprintf(str_PoleHandle,"Pole%8.2e",POLE_HANDLE_PARA_S);
		//
		//			if(VERTEX==2 || VERTEX==3||VERTEX==4)
		//			{
		//				strcat(RESULT_PATH,"_");
		//				strcat(RESULT_PATH,str_PoleHandle);
		//
		//			}
		//		}
		//
		//		if(GLUON_basic==50)
		//		{
		//				if(VERTEX==3 ||VERTEX==4)
		//				{
		//					strcat(RESULT_PATH,"_");
		//					strcat(RESULT_PATH,str_mG);
		//					strcat(RESULT_PATH,"_");
		//					strcat(RESULT_PATH,str_Lambda);
		//				}
		//				else
		//				{
		//					strcat(RESULT_PATH,"/");
		//					strcat(RESULT_PATH,str_mG);
		//					strcat(RESULT_PATH,"_");
		//					strcat(RESULT_PATH,str_Lambda);
		//				}
		//
		//
		//
		//			if(GLUON_medium==10 || GLUON_medium==11)
		//			{
		//				strcat(RESULT_PATH,"_");
		//				strcat(RESULT_PATH,str_alpha);
		//			}
		//
		//			if(GLUON_medium==20)
		//			{
		//				strcat(RESULT_PATH,"_");
		//				strcat(RESULT_PATH,str_alphaT);
		//			}
		//
		//			char str_PoleHandle[50];
		//			sprintf(str_PoleHandle,"Pole%8.2e",POLE_HANDLE_PARA_S);
		//
		//			if(VERTEX==2 || VERTEX==3||VERTEX==4)
		//			{
		//				strcat(RESULT_PATH,"_");
		//				strcat(RESULT_PATH,str_PoleHandle);
		//
		//			}
		//		}
		//
		//
		//
		//		if(IF_MKDIR==1)
		//		{
		//			IF_EXIST = access(RESULT_PATH,00);
		//			if(IF_EXIST!=0)MAKE_PATH_SUCCESS = mkdir(RESULT_PATH,S_IRWXU);
		//			if(MAKE_PATH_SUCCESS ==0)printf("RESULT_PATH = %s\n",RESULT_PATH);
		//		}
		//	}
		//
		//
		//	//路径第4层：指定重整化点与夸克流质量
		//	char str_RENORM[200];
		//	if(ReScheme==1) sprintf(str_RENORM,"Re1_(Z2)%6.4f_(Z4)%6.4f",INIT_Z_2A,INIT_Z_4);
		//	else if(ReScheme==2)sprintf(str_RENORM,"Re2_RePoint%06.3f",RePoint);
		//	else if(ReScheme==3)sprintf(str_RENORM,"Re3_RePoint%06.3f",RePoint);
		//	else {printf("wrong ReScheme! %s %i\n",__FILE__,__LINE__);exit(0);}
		//
		//
		//	char str_mass[30];
		//	sprintf(str_mass,"Mass%10.4e",Mass);
		//
		//	if(GLUON_basic!=50)
		//	{
		//		strcat(RESULT_PATH,"/");
		//		strcat(RESULT_PATH,str_RENORM);
		//		strcat(RESULT_PATH,"_");
		//		strcat(RESULT_PATH,str_mass);
		//	}
		//	else if(GLUON_basic==50)
		//	{
		//		strcat(RESULT_PATH,"/");
		//		strcat(RESULT_PATH,str_mass);
		//
		//	}
		//
		//	if(IF_MKDIR==1)
		//	{
		//		IF_EXIST = access(RESULT_PATH,00);
		//		if(IF_EXIST!=0)MAKE_PATH_SUCCESS = mkdir(RESULT_PATH,S_IRWXU);
		//		if(MAKE_PATH_SUCCESS ==0)printf("RESULT_PATH = %s\n",RESULT_PATH);
		//	}
		//
		//
		//
		//	//路径第5层：指定温度与化学势
		//
		//	if(T_MU==0)
		//	{
		//		Temperature=0;
		//		Mu=0;
		//	}
		//	else if(T_MU ==1)
		//	{
		//		char str6[50];
		//		sprintf(str6,"/T%10.5e_Mu%10.5e",Temperature,Mu);
		//		strcat(RESULT_PATH,str6);
		//	}
		//	else if(T_MU==2)
		//	{
		//		char str6[50];
		//		Temperature=0;
		//		sprintf(str6,"/Mu%10.5e",Mu);
		//		strcat(RESULT_PATH,str6);
		//	}
		//	else
		//	{
		//		printf("wrong T_MU!");
		//		exit(0);
		//	}
		//
		//	if(IF_MKDIR==1)
		//	{
		//		IF_EXIST = access(RESULT_PATH,00);
		//		if(IF_EXIST!=0)MAKE_PATH_SUCCESS = mkdir(RESULT_PATH,S_IRWXU);
		//		if(MAKE_PATH_SUCCESS ==0)printf("RESULT_PATH = %s\n",RESULT_PATH);
		//	}
		//
		//	IF_EXIST = access(RESULT_PATH,00);
		//	if(IF_EXIST !=0)
		//	{
		//		printf("no such folder	%s\n",RESULT_PATH);
		//		return -1;
		//	}
		//	else
		//	{
		//		printf("RESULT_PATH=	%s\n",RESULT_PATH);
		//		return 1;
		//	}
		return 0;
}