//Analysis Type - Classification 
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>


double kolloid_veri_klinik_3_MLP_10_4_2_input_hidden_weights[4][10]=
{
 {8.21131410884811e-002, -1.13572321187139e-001, -8.49636619241239e-002, 2.78542199690863e-002, -4.07742360948342e-001, 2.69961761116310e-001, -5.43423377316706e-001, 3.95943181407724e-001, -1.46172806906887e-001, -9.01564405282165e-003 },
 {1.67043342700664e-003, -1.15123204537344e-001, -1.21713696244943e-001, -2.19559931099905e-002, -3.05005271612549e-001, 1.59815142849915e-001, -3.49719442494098e-001, 3.26874932494007e-001, -7.41398070666131e-002, -2.53081385626628e-002 },
 {5.60048694227951e-001, -7.38327699540407e-001, -2.84171657077058e-001, 9.10960310066798e-002, -8.50465365375726e-001, 7.06752207872555e-001, -9.85297830505450e-001, 8.52675130140368e-001, -2.66901779982625e-001, 1.29462968225037e-001 },
 {-1.40402744325474e-001, 1.03426188373251e-001, 7.50164411923047e-003, -3.95285216755771e-002, 7.20068988123254e-002, -1.00384718642664e-001, -2.34629057469898e-002, 7.34709828824676e-004, -2.68425733489532e-002, -2.84890773287990e-002 } 
};

double kolloid_veri_klinik_3_MLP_10_4_2_hidden_bias[4]={ -4.92187055227885e-002, -9.86930769050288e-002, -8.35104679921937e-002, -4.56112134295118e-003 };

double kolloid_veri_klinik_3_MLP_10_4_2_hidden_output_wts[2][4]=
{
 {3.72429457123102e-001, 4.28156566317888e-001, -8.44494782718549e-001, -5.30536547648322e-002 },
 {-2.55085226716248e-001, -4.03189132896248e-001, 5.51484308552269e-001, -5.38122473594836e-001 }
};

double kolloid_veri_klinik_3_MLP_10_4_2_output_bias[2]={ -1.10148113084281e-001, -4.72492929582713e-001 };

double kolloid_veri_klinik_3_MLP_10_4_2_input[10];
double kolloid_veri_klinik_3_MLP_10_4_2_hidden[4];
double kolloid_veri_klinik_3_MLP_10_4_2_output[2];

void kolloid_veri_klinik_3_MLP_10_4_2_Normalise(double out[],long length)
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

void kolloid_veri_klinik_3_MLP_10_4_2_ComputeFeedForwardSignals(double* MAT_INOUT,double* V_IN,double* V_OUT, double* V_BIAS,int size1,int size2,int layer)
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

void kolloid_veri_klinik_3_MLP_10_4_2_RunNeuralNet_Classification () 
{
  kolloid_veri_klinik_3_MLP_10_4_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_3_MLP_10_4_2_input_hidden_weights,kolloid_veri_klinik_3_MLP_10_4_2_input,kolloid_veri_klinik_3_MLP_10_4_2_hidden,kolloid_veri_klinik_3_MLP_10_4_2_hidden_bias,10, 4,0);
  kolloid_veri_klinik_3_MLP_10_4_2_ComputeFeedForwardSignals((double*)kolloid_veri_klinik_3_MLP_10_4_2_hidden_output_wts,kolloid_veri_klinik_3_MLP_10_4_2_hidden,kolloid_veri_klinik_3_MLP_10_4_2_output,kolloid_veri_klinik_3_MLP_10_4_2_output_bias,4, 2,1);
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
	if(dummy==1)kolloid_veri_klinik_3_MLP_10_4_2_input[0]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[0]=0;
	if(dummy==2)kolloid_veri_klinik_3_MLP_10_4_2_input[1]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[1]=0;
	printf("\n%s\n","Categorical Input Name: Headache");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l2: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l2;
	if(dummy==1)kolloid_veri_klinik_3_MLP_10_4_2_input[2]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[2]=0;
	if(dummy==2)kolloid_veri_klinik_3_MLP_10_4_2_input[3]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[3]=0;
	printf("\n%s\n","Categorical Input Name: Axial Diameter >7mm");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l3: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l3;
	if(dummy==1)kolloid_veri_klinik_3_MLP_10_4_2_input[4]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[4]=0;
	if(dummy==2)kolloid_veri_klinik_3_MLP_10_4_2_input[5]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[5]=0;
	printf("\n%s\n","Categorical Input Name: FLAIR Hyperintensity");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l4: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l4;
	if(dummy==1)kolloid_veri_klinik_3_MLP_10_4_2_input[6]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[6]=0;
	if(dummy==2)kolloid_veri_klinik_3_MLP_10_4_2_input[7]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[7]=0;
	printf("\n%s\n","Categorical Input Name: Risk Zone");
    printf("\n%s\n","Categories    NumericValues:");
	printf("%s\n","0           1");
	printf("%s\n","1           2");
l5: printf("%s","Enter a valid numeric value:");
    scanf("%f",&dummy);
    if(dummy!=1 && dummy!=2)goto l5;
	if(dummy==1)kolloid_veri_klinik_3_MLP_10_4_2_input[8]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[8]=0;
	if(dummy==2)kolloid_veri_klinik_3_MLP_10_4_2_input[9]=1;
	else kolloid_veri_klinik_3_MLP_10_4_2_input[9]=0;
	kolloid_veri_klinik_3_MLP_10_4_2_RunNeuralNet_Classification();
   //Normalise output if output activation is not Softmax;
 	kolloid_veri_klinik_3_MLP_10_4_2_Normalise(kolloid_veri_klinik_3_MLP_10_4_2_output,2);
	for(i=0;i<2;i++)
	{
      if(max<kolloid_veri_klinik_3_MLP_10_4_2_output[i])
      {
        max=kolloid_veri_klinik_3_MLP_10_4_2_output[i];
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

