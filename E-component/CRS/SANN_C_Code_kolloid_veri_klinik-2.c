//Analysis Type - Classification 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double kolloid_veri_klinik_2_MLP_10_11_2_input_hidden_weights[11][10]=
{
 {-2.15137184483512e-001, 2.52335154540859e-001, 1.69683256665947e-001, -1.56136464768158e-001, 6.33201408851523e-001, -6.22707264774897e-001, 7.70718463731924e-001, -7.36628919416066e-001, 1.60877226451442e-001, -8.77621513154054e-002 },
 {-5.60939987114457e-001, 5.45241174239411e-001, 3.79369422705488e-001, -3.46167995590339e-001, 1.12434761778688e+000, -1.16250708800584e+000, 1.38328856016998e+000, -1.37145639944713e+000, 3.12567268504997e-001, -3.04089559140938e-001 },
 {-1.35062615411212e-001, 1.87209204950212e-001, 6.07730472003699e-002, -5.82305510081685e-002, 2.61769159699522e-001, -3.22197569521334e-001, 3.77096269249858e-001, -4.19800065752866e-001, 9.46566367784993e-002, -1.24448043389799e-001 },
 {-5.41205068512589e-001, 5.26595848327200e-001, 1.97565356483005e-001, -2.30406285147383e-001, 1.00451253240314e+000, -9.80777272275335e-001, 1.24563915467424e+000, -1.24765001908700e+000, 2.35603495397360e-001, -3.03237264911551e-001 },
 {-4.95270265658663e-001, 4.96491842286963e-001, 1.75921396841135e-001, -1.95416679782268e-001, 8.30248012595449e-001, -9.25103427446577e-001, 1.06995197492833e+000, -1.20329039387088e+000, 1.74987389618352e-001, -2.12940497759123e-001 },
 {-7.52174480655158e-001, 7.92205620051262e-001, 3.72096677028137e-001, -3.33149267699128e-001, 1.30098892160442e+000, -1.24983892651342e+000, 1.57892635872998e+000, -1.58637490881664e+000, 3.26730946417877e-001, -3.23424618229450e-001 },
 {-2.87085547850268e-001, 2.77045584586484e-001, 1.57380268215375e-001, -1.49890865473681e-001, 7.17444927614211e-001, -6.56280689447773e-001, 8.87709783146524e-001, -8.58644885811201e-001, 1.22966496660281e-001, -1.56509321784544e-001 },
 {-3.42435748318403e-001, 3.44359348132247e-001, 2.45810158035842e-001, -1.89274119154101e-001, 8.08502824485696e-001, -7.72870696062708e-001, 9.41655950349086e-001, -9.75401570843376e-001, 2.27842116086940e-001, -2.03118215911793e-001 },
 {-6.47861569539402e-001, 5.31016951665915e-001, 3.05579567624626e-001, -2.92581269063381e-001, 1.29172728493053e+000, -1.42781664089784e+000, 1.67552105701273e+000, -1.71540440323481e+000, 3.15513637085110e-001, -4.11515317869487e-001 },
 {-4.90967382976052e-001, 4.81389811302231e-001, 1.87765670182295e-001, -2.02363078926206e-001, 8.43310468519326e-001, -8.62531601306803e-001, 1.05146039323739e+000, -1.16296213745361e+000, 2.00912596325039e-001, -2.74866545888338e-001 },
 {-5.73375583062076e-001, 5.27665348545221e-001, 2.27968727382434e-001, -2.84652024776189e-001, 9.14816473017353e-001, -9.75767935001558e-001, 1.19842214480518e+000, -1.26822460744127e+000, 2.57156056410352e-001, -3.25009862266205e-001 } 
};

double kolloid_veri_klinik_2_MLP_10_11_2_hidden_bias[11]={ 5.48268795846525e-002, -4.64502996331671e-002, -7.05973574736672e-003, -4.37580453703768e-002, -3.34017288055120e-002, 5.94240716879769e-002, 2.79569587281593e-002, -2.51876291334398e-002, -7.61728161381649e-002, -6.38276379618340e-002, -6.45015877979928e-002 };

double kolloid_veri_klinik_2_MLP_10_11_2_hidden_output_wts[2][11]=
{
 {-9.55634174971853e-001, 6.07487263481195e-001, -1.74829293849766e-001, 4.93640388713023e-001, 3.81450222782634e-001, 1.29346268122963e+000, -1.12641319716186e+000, -2.98077549225732e-001, -6.04826222075640e-001, 5.22490385510887e-001, 9.67361449222184e-001 },
 {9.07595466495616e-001, -5.48962864349384e-001, 2.18851638189017e-001, -4.61964626707391e-001, -3.72374880966618e-001, -1.23904199114568e+000, 1.05942293137699e+000, 3.12890497563548e-001, 6.25430557888954e-001, -5.17553602989208e-001, -9.75316354110616e-001 }
};

double kolloid_veri_klinik_2_MLP_10_11_2_output_bias[2]={ 2.69131891695582e-001, -2.56581014997201e-001 };

double kolloid_veri_klinik_2_MLP_10_11_2_input[10];
double kolloid_veri_klinik_2_MLP_10_11_2_hidden[11];
double kolloid_veri_klinik_2_MLP_10_11_2_output[2];

void kolloid_veri_klinik_2_MLP_10_11_2_FindMax(double* vec, double* max, long* maxIndex,int len)
{
  long i;
  *max = vec[0];
  *maxIndex = 0;
  for(i=1; i<len; i++)
  {
    if(vec[i]>*max)
    {
      *max = vec[i];
      *maxIndex = i;
    }
  }
}

void kolloid_veri_klinik_2_MLP_10_11_2_softmax(double* vec,int len)
{

  long i, j;
  double sum=0.0;
  for(i=0; i<len; i++)
  {
    if(vec[i]>200)
    {
      double max;
      long maxIndex;
      kolloid_veri_klinik_2_MLP_10_11_2_FindMax(vec, &max, &maxIndex,len);
      for(j=0; j<len; j++)
      {        if(j==maxIndex) vec[j] = 1.0;
        else vec[j] = 0.0;
      }
      return;
    }
    else
    {
      vec[i] = exp(vec[i]);
    }
    sum += vec[i];
  }
  if(sum==0)
  {
   long a = 1;
  }
  if(sum!=0.0)
  {
    for(i=0; i<len; i++) vec[i] = vec[i]/sum;
  }
  else for(i=0; i<len; i++) vec[i] = 1.0/(double)len;
}

void kolloid_veri_klinik_2_MLP_10_11_2_ComputeFeedForwardSignals(double* MAT_INOUT,double* V_IN,double* V_OUT, double* V_BIAS,int size1,int size2,int layer)
{
  int row,col;
  for(row=0;row < size2; row++) 
    {
      V_OUT[row]=0.0;
      for(col=0;col<size1;col++)V_OUT[row]+=(*(MAT_INOUT+(row*size1)+col)*V_IN[col]);
      V_OUT[row]+=V_BIAS[row];
      if(layer==0) V_OUT[row] = exp(V_OUT[row]);
   }
}

void kolloid_veri_klinik_2_MLP_10_11_2_RunNeuralNet_Classification () 
{
  kolloid_veri_klinik_2_MLP_10_11_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_2_MLP_10_11_2_input_hidden_weights,kolloid_veri_klinik_2_MLP_10_11_2_input,kolloid_veri_klinik_2_MLP_10_11_2_hidden,kolloid_veri_klinik_2_MLP_10_11_2_hidden_bias,10, 11,0);
  kolloid_veri_klinik_2_MLP_10_11_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_2_MLP_10_11_2_hidden_output_wts,kolloid_veri_klinik_2_MLP_10_11_2_hidden,kolloid_veri_klinik_2_MLP_10_11_2_output,kolloid_veri_klinik_2_MLP_10_11_2_output_bias,11, 2,1);
}

int main()
{
  float dummy;
  int index;
  int i=0;
  int keyin=1;
  double max;
  while(1)
  {
	max=3.e-300;
	printf("%s","Enter a value for Categorical inputs");
	printf("\n%s\n","Categorical Input Name: Age <65");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l1: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l1;
	if(dummy==1)kolloid_veri_klinik_2_MLP_10_11_2_input[0]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[0]=0;
	if(dummy==2)kolloid_veri_klinik_2_MLP_10_11_2_input[1]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[1]=0;
	printf("\n%s\n","Categorical Input Name: Headache");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l2: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l2;
	if(dummy==1)kolloid_veri_klinik_2_MLP_10_11_2_input[2]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[2]=0;
	if(dummy==2)kolloid_veri_klinik_2_MLP_10_11_2_input[3]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[3]=0;
	printf("\n%s\n","Categorical Input Name: Axial Diameter >7mm");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l3: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l3;
	if(dummy==1)kolloid_veri_klinik_2_MLP_10_11_2_input[4]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[4]=0;
	if(dummy==2)kolloid_veri_klinik_2_MLP_10_11_2_input[5]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[5]=0;
	printf("\n%s\n","Categorical Input Name: FLAIR Hyperintensity");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l4: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l4;
	if(dummy==1)kolloid_veri_klinik_2_MLP_10_11_2_input[6]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[6]=0;
	if(dummy==2)kolloid_veri_klinik_2_MLP_10_11_2_input[7]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[7]=0;
	printf("\n%s\n","Categorical Input Name: Risk Zone");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l5: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l5;
	if(dummy==1)kolloid_veri_klinik_2_MLP_10_11_2_input[8]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[8]=0;
	if(dummy==2)kolloid_veri_klinik_2_MLP_10_11_2_input[9]=1;
	else kolloid_veri_klinik_2_MLP_10_11_2_input[9]=0;
	kolloid_veri_klinik_2_MLP_10_11_2_RunNeuralNet_Classification();
   //Output Activation is Softmax;
	kolloid_veri_klinik_2_MLP_10_11_2_softmax(kolloid_veri_klinik_2_MLP_10_11_2_output, 2);
	for(i=0;i<2;i++)
	{
      if(max<kolloid_veri_klinik_2_MLP_10_11_2_output[i])
      {
        max=kolloid_veri_klinik_2_MLP_10_11_2_output[i];
        index=i+1;
      }
	}
	printf("\n%s","Predicted category = ");

    switch(index)
    {
        case 1: printf("%s\n","0"); break;
        case 2: printf("%s\n","1"); break;
        default: break;
    }
    printf("\n%s%.14f","Confidence level = ",max);
	printf("\n\n%s\n","Press any key to make another prediction or enter 0 to quit the program.");
	keyin=getch();
	if(keyin==48)break;
  }
	return 0;
}

