//Analysis Type - Classification 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double koll_veri_rdmcs_5_RBF_5_6_2_input_hidden_weights[36] =
{
7.62265606504846e-001, 8.15199435142643e-001, 6.07713463565911e-001, 2.58151672486523e-001, 
6.13505207055433e-001, 9.15117722965780e-001, 3.45541986840898e-001, 7.32365288285081e-001, 
6.79906623380595e-002, 5.74270014763231e-001, 7.71821005684178e-001, 7.60059410125965e-001, 
7.06036446455947e-001, 1.77769387976533e-001, 6.46700136994482e-001, 0.00000000000000e+000, 
1.00000000000000e+000, 0.00000000000000e+000, 2.45313563904382e-001, 6.25095116575862e-001, 
8.02799130539128e-001, 8.79449706949089e-001, 7.24497337557041e-001, 3.59919290407119e-001, 
9.31766449516150e-001, 6.96071122314113e-001, 8.88854945536840e-001, 1.11816237053928e-001, 
6.77958570015149e-001, 6.01382817125365e-001, 1.42696713393876e-001, 4.58638575036902e-001, 
1.42696713393876e-001, 8.34934174517945e-001, 3.60549415733075e-001, 6.57347462732771e-001 
};

double koll_veri_rdmcs_5_RBF_5_6_2_hidden_output_wts[2][6]=
{
 {6.43569250085054e-003, 7.83634479241128e-001, -8.36681374867636e-003, 7.90247582935885e+000, -3.45781475578282e-001, 8.07040700958107e+000 },
 {-6.43569249229863e-003, -7.83634479008835e-001, 8.36681375138949e-003, -7.90247582931964e+000, 3.45781474064385e-001, -8.07040700947628e+000 }
};

double koll_veri_rdmcs_5_RBF_5_6_2_output_bias[2]={ 4.61514124540053e-001, 5.38485876413708e-001 };

double koll_veri_rdmcs_5_RBF_5_6_2_radial_centers[6][5]=
{
 {7.62265606504846e-001, 8.15199435142643e-001, 6.07713463565911e-001, 2.58151672486523e-001, 6.13505207055433e-001 },
 {9.15117722965780e-001, 3.45541986840898e-001, 7.32365288285081e-001, 6.79906623380595e-002, 5.74270014763231e-001 },
 {7.71821005684178e-001, 7.60059410125965e-001, 7.06036446455947e-001, 1.77769387976533e-001, 6.46700136994482e-001 },
 {0.00000000000000e+000, 1.00000000000000e+000, 0.00000000000000e+000, 2.45313563904382e-001, 6.25095116575862e-001 },
 {8.02799130539128e-001, 8.79449706949089e-001, 7.24497337557041e-001, 3.59919290407119e-001, 9.31766449516150e-001 },
 {6.96071122314113e-001, 8.88854945536840e-001, 1.11816237053928e-001, 6.77958570015149e-001, 6.01382817125365e-001 } 
};

double koll_veri_rdmcs_5_RBF_5_6_2_Vector_SigmasInv2[6]={ -2.45551201389024e+001, -2.37699815948681e+000, -2.45551201389024e+001, -7.17241697064165e-001, -3.84627570843312e+000, -1.15712432240289e+000 };

double koll_veri_rdmcs_5_RBF_5_6_2_normalizer[6]={ 5.14047626568818e+000, -6.97228679430672e-001, 5.14047626568818e+000, -3.69268071526574e+000, 5.05938614520348e-001, -2.49697997757718e+000 };

double koll_veri_rdmcs_5_RBF_5_6_2_NormSqd(double* data,long length,int centerid)
{
  double sum = 0.0;
  long i;
	for(i=0; i<length; i++) {sum += (*(data+(centerid*length)+i)) * (*(data+(centerid*length)+i));}
  return sum;
}

void koll_veri_rdmcs_5_RBF_5_6_2_ComputeActivations(double* in,double* hid)
{
  double diff2;
  long i,j;
 	for(i=0; i<6; i++)
  {
    diff2=0.0;
    for(j=0;j<5; j++)
       diff2+=(koll_veri_rdmcs_5_RBF_5_6_2_radial_centers[i][j]-in[j])*(koll_veri_rdmcs_5_RBF_5_6_2_radial_centers[i][j]-in[j]);
    hid[i] = exp(koll_veri_rdmcs_5_RBF_5_6_2_normalizer[i] + diff2*koll_veri_rdmcs_5_RBF_5_6_2_Vector_SigmasInv2[i]);
  }
}

double koll_veri_rdmcs_5_RBF_5_6_2_max_input[5]={ 9.82902376833000e-001, 9.83723603491000e-001, 9.91245083924000e-001, 5.63095238095000e-001, 5.34378624729000e+000 };

double koll_veri_rdmcs_5_RBF_5_6_2_min_input[5]={ 9.17333184459000e-001, 9.02165898618000e-001, 8.88272627308000e-001, 4.15156162035000e-001, 3.12581458369000e+000 };

double koll_veri_rdmcs_5_RBF_5_6_2_input[5];
double koll_veri_rdmcs_5_RBF_5_6_2_hidden[6];
double koll_veri_rdmcs_5_RBF_5_6_2_output[2];

double koll_veri_rdmcs_5_RBF_5_6_2_MeanInputs[5]={ 9.65504011660688e-001, 9.59320888990250e-001, 9.52057187498688e-001, 4.65133491343187e-001, 4.35509771332313e+000 };

void koll_veri_rdmcs_5_RBF_5_6_2_ScaleInputs(double* input, double minimum, double maximum, int size)
{
 double delta;
 long i;
 for(i=0; i<size; i++)
 {
	delta = (maximum-minimum)/(koll_veri_rdmcs_5_RBF_5_6_2_max_input[i]-koll_veri_rdmcs_5_RBF_5_6_2_min_input[i]);
	input[i] = minimum - delta*koll_veri_rdmcs_5_RBF_5_6_2_min_input[i]+ delta*input[i];
 }
}

void koll_veri_rdmcs_5_RBF_5_6_2_Normalise(double out[],long length)
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

void koll_veri_rdmcs_5_RBF_5_6_2_ComputeFeedForwardSignals(double* MAT_INOUT,double* V_IN,double* V_OUT, double* V_BIAS,int size1,int size2,int layer)
{
  int row,col;
  for(row=0;row < size2; row++) 
    {
      V_OUT[row]=0.0;
      for(col=0;col<size1;col++)V_OUT[row]+=(*(MAT_INOUT+(row*size1)+col)*V_IN[col]);
      V_OUT[row]+=V_BIAS[row];
   }
}

void koll_veri_rdmcs_5_RBF_5_6_2_RunNeuralNet_Classification () 
{
  koll_veri_rdmcs_5_RBF_5_6_2_ComputeActivations(koll_veri_rdmcs_5_RBF_5_6_2_input,koll_veri_rdmcs_5_RBF_5_6_2_hidden);
  koll_veri_rdmcs_5_RBF_5_6_2_ComputeFeedForwardSignals((double*)koll_veri_rdmcs_5_RBF_5_6_2_hidden_output_wts,koll_veri_rdmcs_5_RBF_5_6_2_hidden,koll_veri_rdmcs_5_RBF_5_6_2_output,koll_veri_rdmcs_5_RBF_5_6_2_output_bias,6, 2,1);
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
	scanf("%lg",&koll_veri_rdmcs_5_RBF_5_6_2_input[0]);
	printf("%s","Cont. Input-1(wavelet-LLLglrlmShortRunEmphasis): ");
	scanf("%lg",&koll_veri_rdmcs_5_RBF_5_6_2_input[1]);
	printf("%s","Cont. Input-2(wavelet-HLHglcmIdmn): ");
	scanf("%lg",&koll_veri_rdmcs_5_RBF_5_6_2_input[2]);
	printf("%s","Cont. Input-3(wavelet-HHLglcmInverseVariance): ");
	scanf("%lg",&koll_veri_rdmcs_5_RBF_5_6_2_input[3]);
	printf("%s","Cont. Input-4(wavelet-LHHgldmDependenceEntropy): ");
	scanf("%lg",&koll_veri_rdmcs_5_RBF_5_6_2_input[4]);
	for(cont_inps=0;cont_inps<5;cont_inps++)
	{
     //Substitution of missing continuous variables
     if(koll_veri_rdmcs_5_RBF_5_6_2_input[cont_inps] == -9999)
	  koll_veri_rdmcs_5_RBF_5_6_2_input[cont_inps]=koll_veri_rdmcs_5_RBF_5_6_2_MeanInputs[cont_inps];
	}
    koll_veri_rdmcs_5_RBF_5_6_2_ScaleInputs(koll_veri_rdmcs_5_RBF_5_6_2_input,0,1,5);
	koll_veri_rdmcs_5_RBF_5_6_2_RunNeuralNet_Classification();
   //Normalise output if output activation is not Softmax;
 	koll_veri_rdmcs_5_RBF_5_6_2_Normalise(koll_veri_rdmcs_5_RBF_5_6_2_output,2);
	for(i=0;i<2;i++)
	{
      if(max<koll_veri_rdmcs_5_RBF_5_6_2_output[i])
      {
        max=koll_veri_rdmcs_5_RBF_5_6_2_output[i];
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

