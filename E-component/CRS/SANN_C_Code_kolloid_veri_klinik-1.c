//Analysis Type - Classification 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double kolloid_veri_klinik_1_MLP_10_4_2_input_hidden_weights[4][10]=
{
 {1.07433800300129e-001, 3.18483545244704e-001, -1.45269277521561e-001, 4.09020132584573e-001, 8.05953217398377e-001, -5.36185921102755e-001, 2.94296409156726e-001, 1.61977625341851e-002, -1.70222682358933e-001, 5.10303723328286e-001 },
 {1.33931636580611e+000, -1.82802194149514e+000, -1.47726802811570e+000, 1.01257178839428e+000, -1.52023701068436e+000, 1.06228529464892e+000, -1.81460429007353e+000, 1.39365319610693e+000, -3.43129107260065e-001, -1.21093878525478e-001 },
 {-8.23340178522301e-001, 4.98806227064101e-001, 9.68586665238394e-001, -1.26313862090248e+000, -1.65612207561113e+000, 1.28446170997128e+000, -3.27903957623678e-001, -1.01333075322518e-001, -3.05670515989657e-001, -1.06402652956981e-002 },
 {7.51987638933179e-002, 6.40487909233388e-002, -1.63240203778058e+000, 1.75195023728531e+000, 2.59043977372637e-001, -8.50833370073016e-002, -1.13510426678054e-001, 1.89565126794307e-001, 1.31998918729965e-001, -1.27496631361122e-002 } 
};

double kolloid_veri_klinik_1_MLP_10_4_2_hidden_bias[4]={ 3.70888351981491e-001, -5.20565292882532e-001, -2.76363836046244e-001, 1.18862940978934e-001 };

double kolloid_veri_klinik_1_MLP_10_4_2_hidden_output_wts[2][4]=
{
 {-2.95647000683798e-002, -3.73888457015238e-001, -2.50682589754742e-001, 1.75577761786997e-002 },
 {-5.86705342636422e-001, 2.80130112512318e+000, 4.24789828335545e-001, -3.92788627915180e-001 }
};

double kolloid_veri_klinik_1_MLP_10_4_2_output_bias[2]={ 2.91968602664345e-001, -3.96993333954112e+000 };

double kolloid_veri_klinik_1_MLP_10_4_2_input[10];
double kolloid_veri_klinik_1_MLP_10_4_2_hidden[4];
double kolloid_veri_klinik_1_MLP_10_4_2_output[2];

void kolloid_veri_klinik_1_MLP_10_4_2_Normalise(double out[],long length)
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

void kolloid_veri_klinik_1_MLP_10_4_2_ComputeFeedForwardSignals(double* MAT_INOUT,double* V_IN,double* V_OUT, double* V_BIAS,int size1,int size2,int layer)
{
  int row,col;
  for(row=0;row < size2; row++) 
    {
      V_OUT[row]=0.0;
      for(col=0;col<size1;col++)V_OUT[row]+=(*(MAT_INOUT+(row*size1)+col)*V_IN[col]);
      V_OUT[row]+=V_BIAS[row];
      if(layer==0) V_OUT[row] = exp(V_OUT[row]);
      if(layer==1) V_OUT[row] = exp(V_OUT[row]);
   }
}

void kolloid_veri_klinik_1_MLP_10_4_2_RunNeuralNet_Classification () 
{
  kolloid_veri_klinik_1_MLP_10_4_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_1_MLP_10_4_2_input_hidden_weights,kolloid_veri_klinik_1_MLP_10_4_2_input,kolloid_veri_klinik_1_MLP_10_4_2_hidden,kolloid_veri_klinik_1_MLP_10_4_2_hidden_bias,10, 4,0);
  kolloid_veri_klinik_1_MLP_10_4_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_1_MLP_10_4_2_hidden_output_wts,kolloid_veri_klinik_1_MLP_10_4_2_hidden,kolloid_veri_klinik_1_MLP_10_4_2_output,kolloid_veri_klinik_1_MLP_10_4_2_output_bias,4, 2,1);
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
	if(dummy==1)kolloid_veri_klinik_1_MLP_10_4_2_input[0]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[0]=0;
	if(dummy==2)kolloid_veri_klinik_1_MLP_10_4_2_input[1]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[1]=0;
	printf("\n%s\n","Categorical Input Name: Headache");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l2: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l2;
	if(dummy==1)kolloid_veri_klinik_1_MLP_10_4_2_input[2]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[2]=0;
	if(dummy==2)kolloid_veri_klinik_1_MLP_10_4_2_input[3]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[3]=0;
	printf("\n%s\n","Categorical Input Name: Axial Diameter >7mm");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l3: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l3;
	if(dummy==1)kolloid_veri_klinik_1_MLP_10_4_2_input[4]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[4]=0;
	if(dummy==2)kolloid_veri_klinik_1_MLP_10_4_2_input[5]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[5]=0;
	printf("\n%s\n","Categorical Input Name: FLAIR Hyperintensity");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l4: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l4;
	if(dummy==1)kolloid_veri_klinik_1_MLP_10_4_2_input[6]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[6]=0;
	if(dummy==2)kolloid_veri_klinik_1_MLP_10_4_2_input[7]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[7]=0;
	printf("\n%s\n","Categorical Input Name: Risk Zone");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l5: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l5;
	if(dummy==1)kolloid_veri_klinik_1_MLP_10_4_2_input[8]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[8]=0;
	if(dummy==2)kolloid_veri_klinik_1_MLP_10_4_2_input[9]=1;
	else kolloid_veri_klinik_1_MLP_10_4_2_input[9]=0;
	kolloid_veri_klinik_1_MLP_10_4_2_RunNeuralNet_Classification();
   //Normalise output if output activation is not Softmax;
 	kolloid_veri_klinik_1_MLP_10_4_2_Normalise(kolloid_veri_klinik_1_MLP_10_4_2_output,2);
	for(i=0;i<2;i++)
	{
      if(max<kolloid_veri_klinik_1_MLP_10_4_2_output[i])
      {
        max=kolloid_veri_klinik_1_MLP_10_4_2_output[i];
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

