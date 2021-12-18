//Analysis Type - Classification 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double kolloid_veri_klinik_4_MLP_10_7_2_input_hidden_weights[7][10]=
{
 {1.14689529809903e-001, 2.66023408593346e-001, 5.07353309283836e-002, 2.97813748663515e-001, 2.02828376325501e-001, 1.16973157755363e-001, 3.03494754544351e-001, 1.30740056663642e-001, 2.75646560631320e-002, 3.68520115676303e-001 },
 {5.86060374552391e-002, 3.09889985639145e-001, 1.58555194817707e-001, 2.09094179978371e-001, 3.56863280783847e-001, 5.83794307381301e-002, 4.73364061476464e-001, 2.54563262906803e-003, 8.60381646569635e-002, 3.62969138527612e-001 },
 {1.92179052058684e-001, 2.89679604491273e-001, 1.61317310076901e-001, 2.66692584420161e-001, 3.34830616599187e-001, 1.73198857055051e-001, 3.48296192061013e-001, 5.47951420516314e-002, 1.09162643304773e-001, 3.47417921440734e-001 },
 {1.12601129382030e-001, 2.88366561853268e-001, 6.10828694177046e-002, 2.60845405226591e-001, 9.20176214846395e-002, 2.44655724634071e-001, 1.65517947729686e-001, 2.36752815957573e-001, -4.41672336902089e-002, 3.71968341893009e-001 },
 {8.02025393739791e-002, 3.15806554013615e-001, 1.50939069284310e-001, 1.77745016117775e-001, 4.66023558962430e-001, -2.67192291833446e-002, 5.48083057947474e-001, -1.04663438116879e-001, 9.48763862475894e-002, 3.57098798145988e-001 },
 {-1.12761568584449e+000, 1.04163946498825e+000, 6.97805514141200e-001, -7.65065614765435e-001, 1.48814268211874e+000, -1.55863776968412e+000, 1.34668867625124e+000, -1.39779120994785e+000, 2.09266228554256e-001, -2.67206286658706e-001 },
 {4.22323887671431e-001, 1.21311498828848e-001, 3.77119216383919e-001, 2.18212702229182e-001, 3.24425230459438e-001, 1.85378705001027e-001, 3.88567822389012e-001, 1.45521696952794e-001, 2.55312505789036e-001, 2.07270705436477e-001 } 
};

double kolloid_veri_klinik_4_MLP_10_7_2_hidden_bias[7]={ 3.42989701849448e-001, 4.09065243285621e-001, 4.61617874500434e-001, 3.73270304771690e-001, 4.87138874311710e-001, -4.23516066362720e-002, 5.15209887304743e-001 };

double kolloid_veri_klinik_4_MLP_10_7_2_hidden_output_wts[2][7]=
{
 {3.36731054730820e-001, 1.04721633693779e-001, -2.13433479751627e-001, 4.97629900510900e-001, -1.25016740517120e-002, 1.14072470870409e+000, -1.11701173345086e+000 },
 {1.33260728597326e-001, 8.59717720456881e-002, 2.86782085333414e-001, 1.14084712553825e-001, 6.04783321156769e-002, -1.68042652278452e+000, 6.43098055356645e-001 }
};

double kolloid_veri_klinik_4_MLP_10_7_2_output_bias[2]={ -4.13390828956149e-001, -1.59462466731705e+000 };

double kolloid_veri_klinik_4_MLP_10_7_2_input[10];
double kolloid_veri_klinik_4_MLP_10_7_2_hidden[7];
double kolloid_veri_klinik_4_MLP_10_7_2_output[2];

double kolloid_veri_klinik_4_MLP_10_7_2_logistic(double x)
{
  if(x > 100.0) x = 1.0;
  else if (x < -100.0) x = 0.0;
  else x = 1.0/(1.0+exp(-x));
  return x;
}

void kolloid_veri_klinik_4_MLP_10_7_2_Normalise(double out[],long length)
{
  long i, j;
  double sum = 0.0;
  for(i=0; i<length; i++)
  {
   if(out[i]>100)
   {
    out[i] = 1.0;
    j = i;
    for(i=0; i<length; i++)
    {
     if(i!=j) out[i] = 0.0;
    }
    break;
   }
   else out[i] = exp(out[i]);
  }
  for(i=0; i<length; i++)
  {
   sum += out[i];
  }
  for(i=0; i<length; i++)
  {
   out[i] = out[i]/sum;
  }
}

void kolloid_veri_klinik_4_MLP_10_7_2_ComputeFeedForwardSignals(double* MAT_INOUT,double* V_IN,double* V_OUT, double* V_BIAS,int size1,int size2,int layer)
{
  int row,col;
  for(row=0;row < size2; row++) 
    {
      V_OUT[row]=0.0;
      for(col=0;col<size1;col++)V_OUT[row]+=(*(MAT_INOUT+(row*size1)+col)*V_IN[col]);
      V_OUT[row]+=V_BIAS[row];
      if(layer==0) V_OUT[row] = kolloid_veri_klinik_4_MLP_10_7_2_logistic(V_OUT[row]);
      if(layer==1) V_OUT[row] = exp(V_OUT[row]);
   }
}

void kolloid_veri_klinik_4_MLP_10_7_2_RunNeuralNet_Classification () 
{
  kolloid_veri_klinik_4_MLP_10_7_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_4_MLP_10_7_2_input_hidden_weights,kolloid_veri_klinik_4_MLP_10_7_2_input,kolloid_veri_klinik_4_MLP_10_7_2_hidden,kolloid_veri_klinik_4_MLP_10_7_2_hidden_bias,10, 7,0);
  kolloid_veri_klinik_4_MLP_10_7_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_4_MLP_10_7_2_hidden_output_wts,kolloid_veri_klinik_4_MLP_10_7_2_hidden,kolloid_veri_klinik_4_MLP_10_7_2_output,kolloid_veri_klinik_4_MLP_10_7_2_output_bias,7, 2,1);
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
	if(dummy==1)kolloid_veri_klinik_4_MLP_10_7_2_input[0]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[0]=0;
	if(dummy==2)kolloid_veri_klinik_4_MLP_10_7_2_input[1]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[1]=0;
	printf("\n%s\n","Categorical Input Name: Headache");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l2: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l2;
	if(dummy==1)kolloid_veri_klinik_4_MLP_10_7_2_input[2]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[2]=0;
	if(dummy==2)kolloid_veri_klinik_4_MLP_10_7_2_input[3]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[3]=0;
	printf("\n%s\n","Categorical Input Name: Axial Diameter >7mm");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l3: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l3;
	if(dummy==1)kolloid_veri_klinik_4_MLP_10_7_2_input[4]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[4]=0;
	if(dummy==2)kolloid_veri_klinik_4_MLP_10_7_2_input[5]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[5]=0;
	printf("\n%s\n","Categorical Input Name: FLAIR Hyperintensity");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l4: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l4;
	if(dummy==1)kolloid_veri_klinik_4_MLP_10_7_2_input[6]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[6]=0;
	if(dummy==2)kolloid_veri_klinik_4_MLP_10_7_2_input[7]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[7]=0;
	printf("\n%s\n","Categorical Input Name: Risk Zone");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l5: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l5;
	if(dummy==1)kolloid_veri_klinik_4_MLP_10_7_2_input[8]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[8]=0;
	if(dummy==2)kolloid_veri_klinik_4_MLP_10_7_2_input[9]=1;
	else kolloid_veri_klinik_4_MLP_10_7_2_input[9]=0;
	kolloid_veri_klinik_4_MLP_10_7_2_RunNeuralNet_Classification();
   //Normalise output if output activation is not Softmax;
 	kolloid_veri_klinik_4_MLP_10_7_2_Normalise(kolloid_veri_klinik_4_MLP_10_7_2_output,2);
	for(i=0;i<2;i++)
	{
      if(max<kolloid_veri_klinik_4_MLP_10_7_2_output[i])
      {
        max=kolloid_veri_klinik_4_MLP_10_7_2_output[i];
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

