//Analysis Type - Classification 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double kolloid_veri_klinik_5_MLP_10_3_2_input_hidden_weights[3][10]=
{
 {-8.18106094599900e-001, 3.95651580648526e-001, 2.16534604096464e-001, -4.81748009232517e-001, 8.89192834603459e-001, -1.25357286740257e+000, 1.08533773072079e+000, -1.43658046910222e+000, 2.24009987225804e-001, -5.95288176877307e-001 },
 {-1.90286550940333e+000, 1.94447456676305e+000, 8.20865045870850e-001, -7.69779686788753e-001, 3.67135196565673e+000, -3.44638376704240e+000, 4.32788260566420e+000, -4.31009233884975e+000, 8.59542530266218e-001, -7.44279202296108e-001 },
 {-1.28950829409484e+000, 1.10167221961261e+000, 6.48543057298539e-001, -8.00977421080536e-001, 2.30710800365360e+000, -2.51251376301024e+000, 2.88207348379048e+000, -3.04460396447367e+000, 5.65160568556518e-001, -6.95835524261805e-001 } 
};

double kolloid_veri_klinik_5_MLP_10_3_2_hidden_bias[3]={ -3.48775382308540e-001, 1.16133804652773e-001, -1.43048279874666e-001 };

double kolloid_veri_klinik_5_MLP_10_3_2_hidden_output_wts[2][3]=
{
 {6.61988127482399e-001, 1.33094660683736e+000, 5.07756365020894e-002 },
 {-7.10967751863740e-001, -1.22289721615893e+000, -4.65473509685443e-002 }
};

double kolloid_veri_klinik_5_MLP_10_3_2_output_bias[2]={ -2.35568711495063e-001, 1.77096759223730e-001 };

double kolloid_veri_klinik_5_MLP_10_3_2_input[10];
double kolloid_veri_klinik_5_MLP_10_3_2_hidden[3];
double kolloid_veri_klinik_5_MLP_10_3_2_output[2];

void kolloid_veri_klinik_5_MLP_10_3_2_FindMax(double* vec, double* max, long* maxIndex,int len)
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

void kolloid_veri_klinik_5_MLP_10_3_2_softmax(double* vec,int len)
{

  long i, j;
  double sum=0.0;
  for(i=0; i<len; i++)
  {
    if(vec[i]>200)
    {
      double max;
      long maxIndex;
      kolloid_veri_klinik_5_MLP_10_3_2_FindMax(vec, &max, &maxIndex,len);
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

void kolloid_veri_klinik_5_MLP_10_3_2_ComputeFeedForwardSignals(double* MAT_INOUT,double* V_IN,double* V_OUT, double* V_BIAS,int size1,int size2,int layer)
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

void kolloid_veri_klinik_5_MLP_10_3_2_RunNeuralNet_Classification () 
{
  kolloid_veri_klinik_5_MLP_10_3_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_5_MLP_10_3_2_input_hidden_weights,kolloid_veri_klinik_5_MLP_10_3_2_input,kolloid_veri_klinik_5_MLP_10_3_2_hidden,kolloid_veri_klinik_5_MLP_10_3_2_hidden_bias,10, 3,0);
  kolloid_veri_klinik_5_MLP_10_3_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_5_MLP_10_3_2_hidden_output_wts,kolloid_veri_klinik_5_MLP_10_3_2_hidden,kolloid_veri_klinik_5_MLP_10_3_2_output,kolloid_veri_klinik_5_MLP_10_3_2_output_bias,3, 2,1);
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
	if(dummy==1)kolloid_veri_klinik_5_MLP_10_3_2_input[0]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[0]=0;
	if(dummy==2)kolloid_veri_klinik_5_MLP_10_3_2_input[1]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[1]=0;
	printf("\n%s\n","Categorical Input Name: Headache");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l2: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l2;
	if(dummy==1)kolloid_veri_klinik_5_MLP_10_3_2_input[2]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[2]=0;
	if(dummy==2)kolloid_veri_klinik_5_MLP_10_3_2_input[3]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[3]=0;
	printf("\n%s\n","Categorical Input Name: Axial Diameter >7mm");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l3: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l3;
	if(dummy==1)kolloid_veri_klinik_5_MLP_10_3_2_input[4]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[4]=0;
	if(dummy==2)kolloid_veri_klinik_5_MLP_10_3_2_input[5]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[5]=0;
	printf("\n%s\n","Categorical Input Name: FLAIR Hyperintensity");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l4: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l4;
	if(dummy==1)kolloid_veri_klinik_5_MLP_10_3_2_input[6]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[6]=0;
	if(dummy==2)kolloid_veri_klinik_5_MLP_10_3_2_input[7]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[7]=0;
	printf("\n%s\n","Categorical Input Name: Risk Zone");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l5: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l5;
	if(dummy==1)kolloid_veri_klinik_5_MLP_10_3_2_input[8]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[8]=0;
	if(dummy==2)kolloid_veri_klinik_5_MLP_10_3_2_input[9]=1;
	else kolloid_veri_klinik_5_MLP_10_3_2_input[9]=0;
	kolloid_veri_klinik_5_MLP_10_3_2_RunNeuralNet_Classification();
   //Output Activation is Softmax;
	kolloid_veri_klinik_5_MLP_10_3_2_softmax(kolloid_veri_klinik_5_MLP_10_3_2_output, 2);
	for(i=0;i<2;i++)
	{
      if(max<kolloid_veri_klinik_5_MLP_10_3_2_output[i])
      {
        max=kolloid_veri_klinik_5_MLP_10_3_2_output[i];
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

