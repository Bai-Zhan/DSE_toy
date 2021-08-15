#include"constants.h"

int VERTEX=_VERTEX_RAINBOW_;
//1 bare vertex; 
//2 Ball-Chiu vertex; 
//3 CLR vertex, also known as DB vertex; 
//4 tau5 vertex

int MEDIUM=_MEDIUM_T0MU0_; 
// _MEDIUM_T0MU0_  : the gap equation will be solved in vacuum, with zero temperature and zero chemical potential.
// _MEDIUM_TMU_: the gap equation will be solved with finite temperature and finite chemical potential.
// _MEDIUM_T0MU_: the gap equation will be solved with zero temperature and finite chemical potential. 

int GLUON_KERNEL       = _GLUON_KERNEL_MT_;
int GLUON_UV_TAIL      = _GLUON_UV_TAIL_OFF_ ;

////
//
//int IFDFUNCT=0;
////0 耦合常数不依赖于温度
////1 耦合常数与温度的关系见陈晶毕业论文p80 (4.20)
////2 耦合常数见高飞论文：PHYSICAL REVIEW D 93, 094019 (2016)
//double TEMPERATURE_CRITICAL=0.15;
////赝相变温度，即调节耦合强度的临界温度，RL+QC:0.150GeV, RL+MT:0.1462GeV, BC1+QC:0.1602GeV, BC1+MT:0.1495GeV
//
//
//int N_PP=60;//The point number for the modulus of 4-momentum p
//int N_QQ=65;//The point number for the modulus of 4-momentum q
//int N_theta=30;//The angle between the 4-momentum p and q
//int Np_PSI=50;//The angle between 4-momentum p and \vec{p}
//int Nq_PSI=100;//The angle between 4-momentum q and \vec{q}, must be Nq_PSI=2*Np_PSI
//
//int N_PV=90;//有限温或有限密时，三动量模的取点数
//int N_P4=200;//零温有限密时，第四动量的取点数
//int N_IN=85;//有限温或有限密时，积分内三动量的取点数
//int N_QV=65;//与N_IN相同。不同的文件里可能会使用不同的变量名
//int N_Q4=280;
//int N_PHI=25;
//int N_OMEGA=60;//有限温时，Matsubara频率的取点数
//
//double GLUON_GAUSS_D=1.024; //GeV**2
//double GLUON_GAUSS_OMEGA=0.5;//GeV
//double GLUON_D_TRAN=1.024;
//double GLUON_D_LONG=1.024;
//double GLUON_MASS=0.05;
//
//double POLE_HANDLE_PARA_S=1e-5;
//// For some of the vertices, there will be a pole at p=q, and we need to exclude this pole from integral.
//// This parameter determines the range of the exclusion. The larger this parameter is, the larger neighbourhood of the pole will be excluded ( and the accuracy of the solution is worse).
//
//double LambdaR = 1e-2;//infrared cut-off
//double LambdaV=1e2;//ultra-violet cut-off
//double LambdaR_PV=1e-2;
//double LambdaV_PV=1e2;
//double LambdaR_P4=1e-3;
//double LambdaV_P4=1e3;
//
//int ReScheme=1;
//// 1 current quark mass independent scheme used by Chen Jing. A(\mu)=1, \frac{dB(p)}{dm_{f}}|_{p=\mu}=1, 
//// 2 current quark mass dependent scheme used by Tang Can.  S^{-1}(\mu)=i\slash{\mu}+m_{f}
////   Z1=Z2^2 for RL vertex, Z1=Z2 for TGL vertex.
//// 3 current quark mass dependent scheme used by Qin Si-Xue. S^{-1}(\mu)=i\slash{\mu}+m_{f}
////   Z1 is absorbed in the gluon model.
//
//double RePoint=19.0;//重整化点，取零为不重整
//
//double INIT_Z_2A=1.0,INIT_Z_2C=1.0,INIT_Z_4=1.0,INIT_Z_M;
//double Z2_d1m=0,ZM_d1m=0;
//double Z2_d2m=0,ZM_d2m=0;
////no renormalization
//
////double INIT_Z_2A=0.814823,INIT_Z_2C=0.814823,INIT_Z_4=0.351341;
////Chen Jing ReScheme,RePoint=2.0GeV,D=1.102736,omega=0.5, RL, QC gluon.
//
////double INIT_Z_2A=0.784821,INIT_Z_2C=0.784821,INIT_Z_4=0.319958;
////Chen Jing ReScheme,RePoint=2.0GeV,D=1.37842,omega=0.4, RL, QC gluon.
//
//
////求解未做重整化的DS方程时的假设的重整化常数
//double Z_2A0=1,Z_2C0=1,Z_2M0,Z_40=1;//重整化常数,Z_2M0代表裸质量与场强重整化常数的乘积
//double Z_2A0_cmplx=1,Z_2C0_cmplx=1,Z_2M0_cmplx=1,Z_40_cmplx=1;//重整化常数,计算复平面DS方程时使用
//
//double Mass=0.000;//流夸克质量
//double Mu;//化学势
//double Temperature;//温度
//
//double ETA=-0.65;//CLR顶点和tau5顶点的参数
//double ALPHA=0.4413;
//double ALPHA_T=0.0;
//double MU_C=0.3076;
//const double M_MUON=0.105;//If we don't want muon to exist, give it an extremely large mass
//double M_ELECTRON=0.511/1000.0;
//
//double ns=0.153*0.1973*0.1973*0.1973;
//double B_DS=0.0/0.0;//90.0/130798.0; //bag constant for quark phase. if B=0.0/0.0, we use a free B
//// By Chen Huan's Calculation, using RL and Gauss, mass=0, mu=0, B_DS=2*45 MeV fm^{-3}
//// RL Gauss,  mass0.005, mu=0.3521, B_DS=2*1.936366e-4 GeV^4 = 25.212 MeV fm^{-3}
//// RL Gaussbz, alpha2.209, mass0.005, mu=0.2895, B_DS=2*2.3779e-4 GeV^4 = 30.961 MeV fm^{-3}
//// RL Gaussch, alpha0.3771, mass0.005, mu=0.286, B_DS=2*2.1959e-4 GeV^4 = 28.591 MeV fm^{-3}
//double M_PION=0.14;
//
//
///****************  Constants for Relavitistic Mean Field(RMF) Theory (hadron phase) ***************/
//double xsL=0.7,xsS=0.7,xsX=0.7,xsD=1;
//double xoL=0.783,xoS=0.783,xoX=0.783,xoD=1.0;
//double xrL=0.783,xrS=0.783,xrX=0.783,xrD=1.0;
//double xdL=0.7,xdS=0.7,xdX=0.7,xdD=1.0;
//
//double mN=0.939;//mass for nucleon
//double mL=1116;//mass for Lambda hyperon
//double mS=1193;//mass for Sigma hyperon
//double mX=1318;//mass for Xi hyperon
//double mD=100;//1.232 for Delta resonance
//// If we don't want to include hyperon, give hyperon a large mass
//
//double Ms=0.55,Mo=0.783,Mr=0.763,Md=0.98;//mass for sigma,omega,rho and delta meson
//
//double a_s=1.365469,b_s=0.226061,c_s=0.409704,d_s=0.901995;
//double a_o=1.402488,b_o=0.172577,c_o=0.344293,d_o=0.983955;
//double a_r=1,b_r=0.515,   c_r=0, d_r=0;
//double a_d=0.01984, b_d=3.4732, c_d=-0.0908, d_d=-9.811;
//
//double GAMMAs0=10.72854,GAMMAo0=13.29015,GAMMAr0=7.32196,GAMMAd0=0;
///*********************************************************************/
//
//double GRAVITY_CONSTANT=2.62*1e-40/0.1973/0.1973;
//double M_SUN=1.116*1e57;//GeV
//
//char *RESULT_PATH;
//int N_NAME=500;
//
//
//void GENERATE_OUTPUT_PATH()
//{
//	printf("the function GENERATE_OUTPUT_PATH() has been removed.\nplease use CREATE_RESULT_PATH(1) instead.\n");
//	exit(0);
//}
//
//int CHECK_PATH()
//{
//	printf("the function CHECK_PATH() has been removed.\nplease use CREATE_RESULT_PATH(0) instead.\n");
//	exit(0);
//}
//
//int CREATE_RESULT_PATH(int IF_MKDIR)
//{
//	RESULT_PATH=(char *)malloc(N_NAME*sizeof(char));
//
//	int GLUON_basic, GLUON_thermal, GLUON_tail,GLUON_medium;
//	GLUON_basic=(int)(GLUONMODEL/1e6);
//	GLUON_thermal=(int)((GLUONMODEL-GLUON_basic*1e6)/1e4);
//	GLUON_tail=(int)((GLUONMODEL-GLUON_basic*1e6-GLUON_thermal*1e4)/1e2);
//	GLUON_medium=(int)((GLUONMODEL-GLUON_basic*1e6-GLUON_thermal*1e4-GLUON_tail*1e2));
//	//printf("%i\n",GLUON_basic);
//	//printf("%i\n",GLUON_thermal);
//	//printf("%i\n",GLUON_tail);
//	//printf("%i\n",GLUON_medium);
//	//getchar();
//
//
//	//路径第1层：指定顶点与胶子模型
//	char str1[5];
//	if(DS_BS_FD==1)sprintf(str1,"%s","DS");
//	else if(DS_BS_FD==2)sprintf(str1,"%s","BS");
//	else if(DS_BS_FD==3)sprintf(str1,"%s","FD");
//
//	char str2[30];
//	if(VERTEX==1)sprintf(str2,"%s","RL");
//	else if(VERTEX==2)sprintf(str2,"%s","BC");
//	else if(VERTEX==3)sprintf(str2,"%s","CLR");
//	else if(VERTEX==4)sprintf(str2,"%s","tau5");
//	else if(VERTEX==10)sprintf(str2,"%s","TGL");
//	else if(VERTEX==11)sprintf(str2,"%s","TGL1");
//	else if(VERTEX==15)sprintf(str2,"%s","TGL5");
//	else if(VERTEX==100)sprintf(str2,"%s","Munczek");
//
//	if(VERTEX<100)
//	{
//		char str4[50];
//		if(GLUONMODEL==10000000)sprintf(str4,"%s","GAUSS");
//		else if(GLUONMODEL==10000010)sprintf(str4,"%s","GAUSSch");
//		else if(GLUONMODEL==10000011)sprintf(str4,"%s","GAUSSbz");
//		else if(GLUONMODEL==10000020)sprintf(str4,"%s","GAUSSalphaT");
//		else if(GLUONMODEL==10100010)sprintf(str4,"%s","Gauss1alpha");
//		else if(GLUONMODEL==10001000)sprintf(str4,"%s","MT");
//		else if(GLUONMODEL==10001020)sprintf(str4,"%s","MTalphaT");
//		else if(GLUONMODEL==20000000)sprintf(str4,"%s","IC");
//		else if(GLUONMODEL==20000010)sprintf(str4,"%s","ICch");
//		else if(GLUONMODEL==20000011)sprintf(str4,"%s","ICbz");
//		else if(GLUONMODEL==10100000)sprintf(str4,"%s","GAUSS1");
//		else if(GLUONMODEL==20100000)sprintf(str4,"%s","IC1");
//		else if(GLUONMODEL==20101000)sprintf(str4,"%s","QC1");
//		else if(GLUONMODEL==20100010)sprintf(str4,"%s","IC1ch");
//		else if(GLUONMODEL==10101000)sprintf(str4,"%s","MT1");
//		else if(GLUONMODEL==20001000)sprintf(str4,"%s","QC");
//		else if(GLUONMODEL==20101000)sprintf(str4,"%s","QC1");
//		else if(GLUONMODEL==20101020)sprintf(str4,"%s","QC1alphaT");
//		else if(GLUONMODEL==20001020)sprintf(str4,"%s","QCalphaT");
//		else if(GLUONMODEL==30000000)sprintf(str4,"%s","Pepe");
//		else if(GLUONMODEL==30100000)sprintf(str4,"%s","Pepe1");
//		else if(GLUONMODEL==20001010)sprintf(str4,"%s","QCalpha");
//		else if(GLUONMODEL==40000000)sprintf(str4,"%s","TC");
//		else if(GLUONMODEL==50000000)sprintf(str4,"%s","CONTACT");
//		else if(GLUONMODEL==50000020)sprintf(str4,"%s","CONTACTalphaT");
//		else{printf("wrong GLUONMODEL! %s %i\n",__FILE__,__LINE__);exit(0);}
//
//		sprintf(RESULT_PATH,"result/%s_%s_%s",str1,str2,str4);
//	}
//	else sprintf(RESULT_PATH,"result/%s_%s",str1,str2);
//
//	int IF_EXIST=0,MAKE_PATH_SUCCESS=0;
//	if(IF_MKDIR==1)
//	{
//		IF_EXIST = access(RESULT_PATH,00);
//		if(IF_EXIST !=0)MAKE_PATH_SUCCESS=mkdir(RESULT_PATH,S_IRWXU); 
//	}
//
//	//路径第2层：指定计算的温度与密度
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
//}
//
//
//
//int line_number(char *name)
//{
//	FILE*input_hadron=fopen(name,"r");
//	if(input_hadron==NULL)
//	{
//		printf("no such file %s\n",name);
//		return -1;
//	}
//	char c;
//	int num_hadron=0;
//	c=fgetc(input_hadron);
//	while(c!=EOF)
//	{
//		if(c=='\n')num_hadron++;  //calculate line number of the file
//		c=fgetc(input_hadron);
//	}
//	fclose(input_hadron);
//	return num_hadron;
//}
	








