//Analysis Type - Classification 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double koll_veri_rdmcs_1_MLP_5_10_2_input_hidden_weights[10][5]=
{
 {1.77805742284793e+000, 2.45705059539742e+000, 3.18831369403454e+000, -1.39713285545761e+000, 3.27526194476083e+000 },
 {-3.22326592818114e-001, 7.27474463986974e-001, 1.45089868036069e+000, -2.01762290893152e+000, 1.44635088900350e+000 },
 {4.69424252966670e-001, 2.30378389271980e-001, 2.27476529139484e-001, 1.64014579099533e-001, 2.46999462462081e-001 },
 {-6.29167475136413e-001, -1.08356838593673e+000, -1.54122697732704e+000, 1.15793389540786e+000, -1.56097857878604e+000 },
 {-2.41156334255324e-001, 5.49795258294283e-001, 6.52918087476616e-001, -6.69529035873578e-001, 6.11579429181301e-001 },
 {2.44957482560935e-001, -3.54675978745409e-001, -5.55695462065091e-001, 6.02474868405269e-001, -3.83283530638438e-001 },
 {2.14658227867672e-001, -1.06797088734815e+000, -2.19258197257832e+000, 2.71466413496671e+000, -2.15429294897843e+000 },
 {-8.01206679309941e-001, -3.34330451511327e+000, -6.02721657325697e+000, 6.33808436562433e+000, -6.08999062425564e+000 },
 {3.97257934978040e-001, 7.72402300336065e-001, 1.18658659314818e+000, -8.61368014301574e-001, 1.24829275281299e+000 },
 {-7.49046616863090e-001, -4.66606825851888e-001, -4.12509110043445e-001, -4.13380471798981e-001, -5.37539950478823e-001 } 
};

double koll_veri_rdmcs_1_MLP_5_10_2_hidden_bias[10]={ 1.25557019825635e+000, -1.50372841179329e+000, 3.86640795740269e-001, -1.09424723686037e-001, -6.41560592212408e-001, 5.89931454915567e-001, 1.76654701285065e+000, 2.77347620541525e+000, -3.48388105264071e-002, -1.18287048907798e+000 };

double koll_veri_rdmcs_1_MLP_5_10_2_hidden_output_wts[2][10]=
{
 {3.74752788332983e+000, -1.49280613661519e+000, 6.25361872426302e-001, -4.53352297605217e-001, -1.11410330741195e+000, 1.06605142101049e+000, 1.74757351409115e+000, 6.11394676115137e+000, 7.11485197988423e-002, -1.98383331267135e+000 },
 {-3.77748769286637e+000, 1.47525364261880e+000, -7.42778902370627e-001, 4.45280917035888e-001, 1.12993980582938e+000, -1.04794208800539e+000, -1.72660757048891e+000, -6.17971485354669e+000, -9.03389955384824e-002, 1.91154047713557e+000 }
};

double koll_veri_rdmcs_1_MLP_5_10_2_output_bias[2]={ 1.73371925531739e+000, -1.79651094773519e+000 };

double koll_veri_rdmcs_1_MLP_5_10_2_max_input[5]={ 9.82902376833000e-001, 9.83723603491000e-001, 9.91245083924000e-001, 5.63095238095000e-001, 5.34378624729000e+000 };

double koll_veri_rdmcs_1_MLP_5_10_2_min_input[5]={ 9.17333184459000e-001, 9.02165898618000e-001, 8.88272627308000e-001, 4.15156162035000e-001, 3.12581458369000e+000 };

double koll_veri_rdmcs_1_MLP_5_10_2_input[5];
double koll_veri_rdmcs_1_MLP_5_10_2_hidden[10];
double koll_veri_rdmcs_1_MLP_5_10_2_output[2];

double koll_veri_rdmcs_1_MLP_5_10_2_MeanInputs[5]={ 9.65504011660688e-001, 9.59320888990250e-001, 9.52057187498688e-001, 4.65133491343187e-001, 4.35509771332313e+000 };

void koll_veri_rdmcs_1_MLP_5_10_2_FindMax(double* vec, double* max, long* maxIndex,int len)
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

void koll_veri_rdmcs_1_MLP_5_10_2_ScaleInputs(double* input, double minimum, double maximum, int size)
{
 double delta;
 long i;
 for(i=0; i<size; i++)
 {
	delta = (maximum-minimum)/(koll_veri_rdmcs_1_MLP_5_10_2_max_input[i]-koll_veri_rdmcs_1_MLP_5_10_2_min_input[i]);
	input[i] = minimum - delta*koll_veri_rdmcs_1_MLP_5_10_2_min_input[i]+ delta*input[i];
 }
}

void koll_veri_rdmcs_1_MLP_5_10_2_softmax(double* vec,int len)
{

  long i, j;
  double sum=0.0;
  for(i=0; i<len; i++)
  {
    if(vec[i]>200)
    {
      double max;
      long maxIndex;
      koll_veri_rdmcs_1_MLP_5_10_2_FindMax(vec, &max, &maxIndex,len);
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

void koll_veri_rdmcs_1_MLP_5_10_2_ComputeFeedForwardSignals(double* MAT_INOUT,double* V_IN,double* V_OUT, double* V_BIAS,int size1,int size2,int layer)
{
  int row,col;
  for(row=0;row < size2; row++) 
    {
      V_OUT[row]=0.0;
      for(col=0;col<size1;col++)V_OUT[row]+=(*(MAT_INOUT+(row*size1)+col)*V_IN[col]);
      V_OUT[row]+=V_BIAS[row];
      if(layer==0) V_OUT[row] = tanh(V_OUT[row]);
   }
}

void koll_veri_rdmcs_1_MLP_5_10_2_RunNeuralNet_Classification () 
{
  koll_veri_rdmcs_1_MLP_5_10_2_ComputeFeedForwardSignals((double*)koll_veri_rdmcs_1_MLP_5_10_2_input_hidden_weights,koll_veri_rdmcs_1_MLP_5_10_2_input,koll_veri_rdmcs_1_MLP_5_10_2_hidden,koll_veri_rdmcs_1_MLP_5_10_2_hidden_bias,5, 10,0);
  koll_veri_rdmcs_1_MLP_5_10_2_ComputeFeedForwardSignals((double*)koll_veri_rdmcs_1_MLP_5_10_2_hidden_output_wts,koll_veri_rdmcs_1_MLP_5_10_2_hidden,koll_veri_rdmcs_1_MLP_5_10_2_output,koll_veri_rdmcs_1_MLP_5_10_2_output_bias,10, 2,1);
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
	scanf("%lg",&koll_veri_rdmcs_1_MLP_5_10_2_input[0]);
	printf("%s","Cont. Input-1(wavelet-LLLglrlmShortRunEmphasis): ");
	scanf("%lg",&koll_veri_rdmcs_1_MLP_5_10_2_input[1]);
	printf("%s","Cont. Input-2(wavelet-HLHglcmIdmn): ");
	scanf("%lg",&koll_veri_rdmcs_1_MLP_5_10_2_input[2]);
	printf("%s","Cont. Input-3(wavelet-HHLglcmInverseVariance): ");
	scanf("%lg",&koll_veri_rdmcs_1_MLP_5_10_2_input[3]);
	printf("%s","Cont. Input-4(wavelet-LHHgldmDependenceEntropy): ");
	scanf("%lg",&koll_veri_rdmcs_1_MLP_5_10_2_input[4]);
	for(cont_inps=0;cont_inps<5;cont_inps++)
	{
     //Substitution of missing continuous variables
     if(koll_veri_rdmcs_1_MLP_5_10_2_input[cont_inps] == -9999)
	  koll_veri_rdmcs_1_MLP_5_10_2_input[cont_inps]=koll_veri_rdmcs_1_MLP_5_10_2_MeanInputs[cont_inps];
	}
    koll_veri_rdmcs_1_MLP_5_10_2_ScaleInputs(koll_veri_rdmcs_1_MLP_5_10_2_input,0,1,5);
	koll_veri_rdmcs_1_MLP_5_10_2_RunNeuralNet_Classification();
   //Output Activation is Softmax;
	koll_veri_rdmcs_1_MLP_5_10_2_softmax(koll_veri_rdmcs_1_MLP_5_10_2_output, 2);
	for(i=0;i<2;i++)
	{
      if(max<koll_veri_rdmcs_1_MLP_5_10_2_output[i])
      {
        max=koll_veri_rdmcs_1_MLP_5_10_2_output[i];
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

