#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int function_dup(char arr[4]);

void main()
{
int bpb,nb;
int r,c;

int i,j,k;
FILE *fpd;
fpd=fopen("dimensions.txt","r");
////////////bits per band and number of bands
bpb=4;
nb=4;
r=64;
c=64;
///////////////////////////////////

FILE *fp1;
fp1=fopen("parm_rsi.txt","r");
FILE *fp2;
fp2=fopen("parm_rsi.txt","r");
FILE *fp3;
fp3=fopen("parm_rsi.txt","r");
FILE *fp4;
fp4=fopen("parm_rsi.txt","r");
FILE *fp5;
fp5=fopen("parm_rsi.txt","r");
FILE *fp6;
fp6=fopen("parm_rsi.txt","r");
FILE *fp7;
fp7=fopen("parm_rsi.txt","r");
FILE *fp8;
fp8=fopen("parm_rsi.txt","r");
FILE *fp9;
fp9=fopen("parm_rsi.txt","r");
FILE *fp10;
fp10=fopen("parm_rsi.txt","r");
FILE *fp11;
fp11=fopen("parm_rsi.txt","r");
FILE *fp12;
fp12=fopen("parm_rsi.txt","r");
FILE *fp13;
fp13=fopen("parm_rsi.txt","r");
FILE *fp14;
fp14=fopen("parm_rsi.txt","r");
FILE *fp15;
fp15=fopen("parm_rsi.txt","r");
FILE *fp16;
fp16=fopen("parm_rsi.txt","r");

FILE *w11;
w11=fopen("b1b1.txt","w");
FILE *w12;
w12=fopen("b1b2.txt","w");
FILE *w13;
w13=fopen("b1b3.txt","w");
FILE *w14;
w14=fopen("b1b4.txt","w");

FILE *w21;
w21=fopen("b2b1.txt","w");
FILE *w22;
w22=fopen("b2b2.txt","w");
FILE *w23;
w23=fopen("b2b3.txt","w");
FILE *w24;
w24=fopen("b2b4.txt","w");

FILE *w31;
w31=fopen("b3b1.txt","w");
FILE *w32;
w32=fopen("b3b2.txt","w");
FILE *w33;
w33=fopen("b3b3.txt","w");
FILE *w34;
w34=fopen("b3b4.txt","w");

FILE *w41;
w41=fopen("b4b1.txt","w");
FILE *w42;
w42=fopen("b4b2.txt","w");
FILE *w43;
w43=fopen("b4b3.txt","w");
FILE *w44;
w44=fopen("b4b4.txt","w");

char testing1[bpb*nb*c];char testing2[bpb*nb*c];char testing3[bpb*nb*c];char testing4[bpb*nb*c];
char testing5[bpb*nb*c];char testing6[bpb*nb*c];char testing7[bpb*nb*c];char testing8[bpb*nb*c];
char testing9[bpb*nb*c];char testing10[bpb*nb*c];char testing11[bpb*nb*c];char testing12[bpb*nb*c];
char testing13[bpb*nb*c];char testing14[bpb*nb*c];char testing15[bpb*nb*c];char testing16[bpb*nb*c];

for(i=0;i<nb*bpb;i++)
{
	switch(i+1)
	{

	case 1: for(k=0;k<r;k++)
		{
		fgets(testing1,bpb*nb*c+1,(FILE*)fp1);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			{fprintf(w11,"%c",testing1[j]);}
		fgets(testing1,bpb*nb*c+1,(FILE*)fp1);
		fprintf(w11,"%c",'\n');
		}
		break;
		//fclose(w11);
		
	case 2: for(k=0;k<r;k++)
		{
		fgets(testing2,bpb*nb*c+1,(FILE*)fp2);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w12,"%c",testing2[j]);
		fgets(testing2,bpb*nb*c+1,(FILE*)fp2);
		fprintf(w12,"%c",'\n');
		}
		break;		
		//fclose(w12);

	case 3: for(k=0;k<r;k++)
		{
		fgets(testing3,bpb*nb*c+1,(FILE*)fp3);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w13,"%c",testing3[j]);
		fgets(testing3,bpb*nb*c+1,(FILE*)fp3);
		fprintf(w13,"%c",'\n');
		}
		break;		
		//fclose(w13);

	case 4:
		for(k=0;k<r;k++)
		{
		fgets(testing4,bpb*nb*c+1,(FILE*)fp4);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w14,"%c",testing4[j]);
		fgets(testing4,bpb*nb*c+1,(FILE*)fp4);
		fprintf(w14,"%c",'\n');
		}	
		break;
		//fclose(w14);
	
	case 5: for(k=0;k<r;k++)
		{
		fgets(testing5,bpb*nb*c+1,(FILE*)fp5);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w21,"%c",testing5[j]);
		fgets(testing5,bpb*nb*c+1,(FILE*)fp5);
		fprintf(w21,"%c",'\n');
		}		
		break;
 		//fclose(w21);

	case 6: for(k=0;k<r;k++)
		{
		fgets(testing6,bpb*nb*c+1,(FILE*)fp6);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w22,"%c",testing6[j]);
		fgets(testing6,bpb*nb*c+1,(FILE*)fp6);
		fprintf(w22,"%c",'\n');
		}
		break;		
		//fclose(w22);

	case 7: for(k=0;k<r;k++)
		{
		fgets(testing7,bpb*nb*c+1,(FILE*)fp7);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w23,"%c",testing7[j]);
		fgets(testing7,bpb*nb*c+1,(FILE*)fp7);
		fprintf(w23,"%c",'\n');
		}	
		break;
		//fclose(w23);	
	
	case 8: for(k=0;k<r;k++)
		{
		fgets(testing8,bpb*nb*c+1,(FILE*)fp8);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w24,"%c",testing8[j]);
		fgets(testing8,bpb*nb*c+1,(FILE*)fp8);
		fprintf(w24,"%c",'\n');
		}
		break;
		//fclose(w24);		
	
	case 9: for(k=0;k<r;k++)
		{
		fgets(testing9,bpb*nb*c+1,(FILE*)fp9);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w31,"%c",testing9[j]);
		fgets(testing9,bpb*nb*c+1,(FILE*)fp9);
		fprintf(w31,"%c",'\n');
		}
		break;
		//fclose(w31);		
	
	case 10:for(k=0;k<r;k++)
		{
		fgets(testing10,bpb*nb*c+1,(FILE*)fp10);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w32,"%c",testing10[j]);
		fgets(testing10,bpb*nb*c+1,(FILE*)fp10);
		fprintf(w32,"%c",'\n');
		}		
		break;
		//fclose(w32);

	case 11:for(k=0;k<r;k++)
		{
		fgets(testing11,bpb*nb*c+1,(FILE*)fp11);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w33,"%c",testing11[j]);
		fgets(testing11,bpb*nb*c+1,(FILE*)fp11);
		fprintf(w33,"%c",'\n');
		}		
		break;
		//fclose(w33);

	case 12:for(k=0;k<r;k++)
		{
		fgets(testing12,bpb*nb*c+1,(FILE*)fp12);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w34,"%c",testing12[j]);
		fgets(testing12,bpb*nb*c+1,(FILE*)fp12);
		fprintf(w34,"%c",'\n');
		}		
		break;
		//fclose(w34);	

	case 13:for(k=0;k<r;k++)
		{
		fgets(testing13,bpb*nb*c+1,(FILE*)fp13);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w41,"%c",testing13[j]);
		fgets(testing13,bpb*nb*c+1,(FILE*)fp13);
		fprintf(w41,"%c",'\n');
		}		
		break;
		//fclose(w41);

	case 14:for(k=0;k<r;k++)
		{
		fgets(testing14,bpb*nb*c+1,(FILE*)fp14);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w42,"%c",testing14[j]);
		fgets(testing14,bpb*nb*c+1,(FILE*)fp12);
		fprintf(w42,"%c",'\n');
		}		
		break;
		//fclose(w42);

	case 15:for(k=0;k<r;k++)
		{
		fgets(testing15,bpb*nb*c+1,(FILE*)fp15);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w43,"%c",testing15[j]);
		fgets(testing15,bpb*nb*c+1,(FILE*)fp12);
		fprintf(w43,"%c",'\n');
		}		
		break;
		//fclose(w43);

	case 16:for(k=0;k<r;k++)
		{
		fgets(testing16,bpb*nb*c+1,(FILE*)fp16);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w44,"%c",testing16[j]);
		fgets(testing16,bpb*nb*c+1,(FILE*)fp12);
		fprintf(w44,"%c",'\n');
		}		
		break;
		//fclose(w44);
	}

}
}


int function_dup(char arr[4])
{
int i,j,k;
int counter=0;
char ch;


for(i=0;i<4;i++)
{
if(arr[i]=='\0')
break;
counter++;
}

int sum=0;
int arr3[10];
char arr2[10];
arr2[0]='0';arr2[1]='1';arr2[2]='2';arr2[3]='3';arr2[4]='4';arr2[5]='5';arr2[6]='6';arr2[7]='7';arr2[8]='8';arr2[9]='9';
for(i=0;i<10;i++)
arr3[i]=i;

for(i=0;i<counter;i++)
{
	for(j=0;j<10;j++)
		if(arr[i]==arr2[j])
		{
		k=arr3[j];
		break;
		}
sum=sum+(k*pow(10,counter-i-1));
}	

return sum;



}
