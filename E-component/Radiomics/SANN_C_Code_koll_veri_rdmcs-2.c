//Analysis Type - Classification 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double koll_veri_rdmcs_2_RBF_5_5_2_input_hidden_weights[30] =
{
1.00000000000000e+000, 6.21109829658412e-001, 6.08900425662540e-001, 2.25212640401291e-001, 
6.18672318591654e-001, 8.02799130539128e-001, 8.79449706949089e-001, 7.24497337557041e-001, 
3.59919290407119e-001, 9.31766449516150e-001, 7.08978847990714e-001, 7.45997035592673e-001, 
8.60405462738406e-001, 3.44414097383812e-001, 6.01232012444002e-001, 7.69659637595463e-001, 
7.71186649758484e-001, 5.45849136974619e-001, 1.00000000000000e+000, 0.00000000000000e+000, 
8.33969126691322e-001, 9.65809145079032e-001, 1.00000000000000e+000, 0.00000000000000e+000, 
1.00000000000000e+000, 4.21969264784404e-001, 3.93161931653146e-001, 3.93161931653146e-001, 
9.45798691827938e-001, 4.67470802560119e-001 };

double koll_veri_rdmcs_2_RBF_5_5_2_hidden_output_wts[2][5]=
{
 {-9.13111605080916e-001, 7.67972124554104e-001, -5.77897352022644e+000, 1.13740146683261e+003, -6.12610259142939e+000 },
 {8.81264704051597e-001, -9.81939121652244e-001, 5.93391674705231e+000, -1.13726943525880e+003, 6.02748777197617e+000 }
};

double koll_veri_rdmcs_2_RBF_5_5_2_output_bias[2]={ -2.18168239238418e+000, 2.07366817240448e+000 };

double koll_veri_rdmcs_2_RBF_5_5_2_radial_centers[5][5]=
{
 {1.00000000000000e+000, 6.21109829658412e-001, 6.08900425662540e-001, 2.25212640401291e-001, 6.18672318591654e-001 },
 {8.02799130539128e-001, 8.79449706949089e-001, 7.24497337557041e-001, 3.59919290407119e-001, 9.31766449516150e-001 },
 {7.08978847990714e-001, 7.45997035592673e-001, 8.60405462738406e-001, 3.44414097383812e-001, 6.01232012444002e-001 },
 {7.69659637595463e-001, 7.71186649758484e-001, 5.45849136974619e-001, 1.00000000000000e+000, 0.00000000000000e+000 },
 {8.33969126691322e-001, 9.65809145079032e-001, 1.00000000000000e+000, 0.00000000000000e+000, 1.00000000000000e+000 } 
};

double koll_veri_rdmcs_2_RBF_5_5_2_Vector_SigmasInv2[5]={ -2.80807282081504e+000, -3.23464842566483e+000, -3.23464842566483e+000, -5.58949518480876e-001, -2.28802635599840e+000 };

double koll_veri_rdmcs_2_RBF_5_5_2_normalizer[5]={ -2.80578666707890e-001, 7.29758947177110e-002, 7.29758947177110e-002, -4.31606500646539e+000, -7.92600732919679e-001 };

double koll_veri_rdmcs_2_RBF_5_5_2_NormSqd(double* data,long length,int centerid)
{
  double sum = 0.0;
  long i;
	for(i=0; i<length; i++) {sum += (*(data+(centerid*length)+i)) * (*(data+(centerid*length)+i));}
  return sum;
}

void koll_veri_rdmcs_2_RBF_5_5_2_ComputeActivations(double* in,double* hid)
{
  double diff2;
  long i,j;
 	for(i=0; i<5; i++)
  {
    diff2=0.0;
    for(j=0;j<5; j++)
       diff2+=(koll_veri_rdmcs_2_RBF_5_5_2_radial_centers[i][j]-in[j])*(koll_veri_rdmcs_2_RBF_5_5_2_radial_centers[i][j]-in[j]);
    hid[i] = exp(koll_veri_rdmcs_2_RBF_5_5_2_normalizer[i] + diff2*koll_veri_rdmcs_2_RBF_5_5_2_Vector_SigmasInv2[i]);
  }
}

double koll_veri_rdmcs_2_RBF_5_5_2_max_input[5]={ 9.82902376833000e-001, 9.83723603491000e-001, 9.91245083924000e-001, 5.63095238095000e-001, 5.34378624729000e+000 };

double koll_veri_rdmcs_2_RBF_5_5_2_min_input[5]={ 9.17333184459000e-001, 9.02165898618000e-001, 8.88272627308000e-001, 4.15156162035000e-001, 3.12581458369000e+000 };

double koll_veri_rdmcs_2_RBF_5_5_2_input[5];
double koll_veri_rdmcs_2_RBF_5_5_2_hidden[5];
double koll_veri_rdmcs_2_RBF_5_5_2_output[2];

double koll_veri_rdmcs_2_RBF_5_5_2_MeanInputs[5]={ 9.65504011660688e-001, 9.59320888990250e-001, 9.52057187498688e-001, 4.65133491343187e-001, 4.35509771332313e+000 };

void koll_veri_rdmcs_2_RBF_5_5_2_FindMax(double* vec, double* max, long* maxIndex,int len)
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

void koll_veri_rdmcs_2_RBF_5_5_2_ScaleInputs(double* input, double minimum, double maximum, int size)
{
 double delta;
 long i;
 for(i=0; i<size; i++)
 {
	delta = (maximum-minimum)/(koll_veri_rdmcs_2_RBF_5_5_2_max_input[i]-koll_veri_rdmcs_2_RBF_5_5_2_min_input[i]);
	input[i] = minimum - delta*koll_veri_rdmcs_2_RBF_5_5_2_min_input[i]+ delta*input[i];
 }
}

void koll_veri_rdmcs_2_RBF_5_5_2_softmax(double* vec,int len)
{

  long i, j;
  double sum=0.0;
  for(i=0; i<len; i++)
  {
    if(vec[i]>200)
    {
      double max;
      long maxIndex;
      koll_veri_rdmcs_2_RBF_5_5_2_FindMax(vec, &max, &maxIndex,len);
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

void koll_veri_rdmcs_2_RBF_5_5_2_ComputeFeedForwardSignals(double* MAT_INOUT,double* V_IN,double* V_OUT, double* V_BIAS,int size1,int size2,int layer)
{
  int row,col;
  for(row=0;row < size2; row++) 
    {
      V_OUT[row]=0.0;
      for(col=0;col<size1;col++)V_OUT[row]+=(*(MAT_INOUT+(row*size1)+col)*V_IN[col]);
      V_OUT[row]+=V_BIAS[row];
   }
}

void koll_veri_rdmcs_2_RBF_5_5_2_RunNeuralNet_Classification () 
{
  koll_veri_rdmcs_2_RBF_5_5_2_ComputeActivations(koll_veri_rdmcs_2_RBF_5_5_2_input,koll_veri_rdmcs_2_RBF_5_5_2_hidden);
  koll_veri_rdmcs_2_RBF_5_5_2_ComputeFeedForwardSignals((double*)koll_veri_rdmcs_2_RBF_5_5_2_hidden_output_wts,koll_veri_rdmcs_2_RBF_5_5_2_hidden,koll_veri_rdmcs_2_RBF_5_5_2_output,koll_veri_rdmcs_2_RBF_5_5_2_output_bias,5, 2,1);
}

int main()
{
  int cont_inps;
  int index;
  int i=0;
  int keyin=1;
  double max;
  while(1)
  {
	max=3.e-300;
	printf("\n%s\n","Enter values for Continuous inputs (To skip a continuous input please enter -9999)");
	printf("%s","Cont. Input-0(wavelet-LHHglcmIdmn): ");
	scanf("%lg",&koll_veri_rdmcs_2_RBF_5_5_2_input[0]);
	printf("%s","Cont. Input-1(wavelet-LLLglrlmShortRunEmphasis): ");
	scanf("%lg",&koll_veri_rdmcs_2_RBF_5_5_2_input[1]);
	printf("%s","Cont. Input-2(wavelet-HLHglcmIdmn): ");
	scanf("%lg",&koll_veri_rdmcs_2_RBF_5_5_2_input[2]);
	printf("%s","Cont. Input-3(wavelet-HHLglcmInverseVariance): ");
	scanf("%lg",&koll_veri_rdmcs_2_RBF_5_5_2_input[3]);
	printf("%s","Cont. Input-4(wavelet-LHHgldmDependenceEntropy): ");
	scanf("%lg",&koll_veri_rdmcs_2_RBF_5_5_2_input[4]);
	for(cont_inps=0;cont_inps<5;cont_inps++)
	{
     //Substitution of missing continuous variables
     if(koll_veri_rdmcs_2_RBF_5_5_2_input[cont_inps] == -9999)
	  koll_veri_rdmcs_2_RBF_5_5_2_input[cont_inps]=koll_veri_rdmcs_2_RBF_5_5_2_MeanInputs[cont_inps];
	}
    koll_veri_rdmcs_2_RBF_5_5_2_ScaleInputs(koll_veri_rdmcs_2_RBF_5_5_2_input,0,1,5);
	koll_veri_rdmcs_2_RBF_5_5_2_RunNeuralNet_Classification();
   //Output Activation is Softmax;
	koll_veri_rdmcs_2_RBF_5_5_2_softmax(koll_veri_rdmcs_2_RBF_5_5_2_output, 2);
	for(i=0;i<2;i++)
	{
      if(max<koll_veri_rdmcs_2_RBF_5_5_2_output[i])
      {
        max=koll_veri_rdmcs_2_RBF_5_5_2_output[i];
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

