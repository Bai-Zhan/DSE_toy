#include"constants.h"

int VERTEX=_VERTEX_RAINBOW_;
//_VERTEX_RAINBOW_ bare vertex; 
//_VERTEX_BC_ Ball-Chiu vertex; 
//_VERTEX_CLR_ vertex, also known as DB vertex; 
//4 tau5 vertex

int MEDIUM=_MEDIUM_T0MU0_; 
// _MEDIUM_T0MU0_  : the gap equation will be solved in vacuum, with zero temperature and zero chemical potential.
// _MEDIUM_TMU_: the gap equation will be solved with finite temperature and finite chemical potential.
// _MEDIUM_T0MU_: the gap equation will be solved with zero temperature and finite chemical potential. 

int GLUON_KERNEL       = _GLUON_KERNEL_MT_;
int GLUON_UV_TAIL      = _GLUON_UV_TAIL_OFF_ ;

//
//int IFDFUNCT=0;
////0 耦合常数不依赖于温度
////1 耦合常数与温度的关系见陈晶毕业论文p80 (4.20)
////2 耦合常数见高飞论文：PHYSICAL REVIEW D 93, 094019 (2016)
//double TEMPERATURE_CRITICAL=0.15;
////赝相变温度，即调节耦合强度的临界温度，RL+QC:0.150GeV, RL+MT:0.1462GeV, BC1+QC:0.1602GeV, BC1+MT:0.1495GeV
//
//
int N_PP=60;//The point number for the modulus of 4-momentum p
int N_QQ=65;//The point number for the modulus of 4-momentum q
int N_theta=30;//The angle between the 4-momentum p and q


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

double GLUON_D    =1.024; // in the unit of GeV**2.  This is the parameter for the gluon model.
double GLUON_OMEGA=0.5;// in the unit of GeV.  This is the parameter for the gluon model.
//double GLUON_D_TRAN=1.024;
//double GLUON_D_LONG=1.024;
//double GLUON_MASS=0.05;
//
//double POLE_HANDLE_PARA_S=1e-5;
//// For some of the vertices, there will be a pole at p=q, and we need to exclude this pole from integral.
//// This parameter determines the range of the exclusion. The larger this parameter is, the larger neighbourhood of the pole will be excluded ( and the accuracy of the solution is worse).
//
double LambdaR = 1e-3;//infrared cut-off
double LambdaV=1e3;//ultra-violet cut-off

//double LambdaR_PV=1e-2;
//double LambdaV_PV=1e2;
//double LambdaR_P4=1e-3;
//double LambdaV_P4=1e3;
//
int ReScheme=_RENORMALIZATION_OFF_;
// 1 current quark mass independent scheme used by Chen Jing. A(\mu)=1, \frac{dB(p)}{dm_{f}}|_{p=\mu}=1, 
// 2 current quark mass dependent scheme used by Tang Can.  S^{-1}(\mu)=i\slash{\mu}+m_{f}
//   Z1=Z2^2 for RL vertex, Z1=Z2 for TGL vertex.
// 3 current quark mass dependent scheme used by Qin Si-Xue. S^{-1}(\mu)=i\slash{\mu}+m_{f}
//   Z1 is absorbed in the gluon model.
//
double RePoint=19.0;// Renormalization point. In the unit of GeV. 

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
//
//
//
char *RESULT_PATH;
int N_NAME=500;
//
//
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
	








