#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int* x1=0;
int* x2=0;
int* y11=0;
int* y2=0;
int* remaining=0;
int* current_box=0;
int* pure_nodes_level=0;
int* ptree=0;
int* dsent=0;

int countone(int a,int b,int c,int d,int r,int col,char data_formatted[r][col],int find);
char function(int a);
int pure(int a,int b,int c,int d,int r,int col,char data_formatted[r][col]);
void printCombination(int arr[], int n, int r);
void combinationUtil(int arr[], int data[], int start, int end, int index, int r);
//int ptree_compute(int row1,int col1,char used_data[row1][col1]);
int determine(int bpb,int nb,int r,int c,int k,int support,int choice);
int possible(int count,int arr1[count],int arr2[count],int grouping_similar,int k);
int prune(int count,int k,int t1[count],int t2[count]);

void main()
{

int cr123=0;

FILE *rule;
rule=fopen("rules.txt","w");

FILE *fp1;
fp1=fopen("b1b1.txt","r");
FILE *fp2;
fp2=fopen("b1b2.txt","r");
FILE *fp3;
fp3=fopen("b1b3.txt","r");
FILE *fp4;
fp4=fopen("b1b4.txt","r");
FILE *fp5;
fp5=fopen("b2b1.txt","r");
FILE *fp6;
fp6=fopen("b2b2.txt","r");
FILE *fp7;
fp7=fopen("b2b3.txt","r");
FILE *fp8;
fp8=fopen("b2b4.txt","r");
FILE *fp9;
fp9=fopen("b3b1.txt","r");
FILE *fp10;
fp10=fopen("b3b2.txt","r");
FILE *fp11;
fp11=fopen("b3b3.txt","r");
FILE *fp12;
fp12=fopen("b3b4.txt","r");
FILE *fp13;
fp13=fopen("b4b1.txt","r");
FILE *fp14;
fp14=fopen("b4b2.txt","r");
FILE *fp15;
fp15=fopen("b4b3.txt","r");
FILE *fp16;
fp16=fopen("b4b4.txt","r");
FILE *fp17;
fp17=fopen("b5b1.txt","r");
FILE *fp18;
fp18=fopen("b5b2.txt","r");
FILE *fp19;
fp19=fopen("b5b3.txt","r");
FILE *fp20;
fp20=fopen("b5b4.txt","r");
FILE *fp21;
fp21=fopen("b6b1.txt","r");
FILE *fp22;
fp22=fopen("b6b2.txt","r");
FILE *fp23;
fp23=fopen("b6b3.txt","r");
FILE *fp24;
fp24=fopen("b6b4.txt","r");

FILE *fp25;
fp25=fopen("b7b1.txt","r");
FILE *fp26;
fp26=fopen("b7b2.txt","r");
FILE *fp27;
fp27=fopen("b7b3.txt","r");
FILE *fp28;
fp28=fopen("b7b4.txt","r");
FILE *fp29;
fp29=fopen("b8b1.txt","r");
FILE *fp30;
fp30=fopen("b8b2.txt","r");
FILE *fp31;
fp31=fopen("b8b3.txt","r");
FILE *fp32;
fp32=fopen("b8b4.txt","r");
FILE *fp33;
fp33=fopen("b9b1.txt","r");
FILE *fp34;
fp34=fopen("b9b2.txt","r");
FILE *fp35;
fp35=fopen("b9b3.txt","r");
FILE *fp36;
fp36=fopen("b9b4.txt","r");
FILE *fp37;
fp37=fopen("b10b1.txt","r");
FILE *fp38;
fp38=fopen("b10b2.txt","r");
FILE *fp39;
fp39=fopen("b10b3.txt","r");
FILE *fp40;
fp40=fopen("b10b4.txt","r");
FILE *fp41;
fp41=fopen("b11b1.txt","r");
FILE *fp42;
fp42=fopen("b11b2.txt","r");
FILE *fp43;
fp43=fopen("b11b3.txt","r");
FILE *fp44;
fp44=fopen("b11b4.txt","r");
FILE *fp45;
fp45=fopen("b12b1.txt","r");
FILE *fp46;
fp46=fopen("b12b2.txt","r");
FILE *fp47;
fp47=fopen("b12b3.txt","r");
FILE *fp48;
fp48=fopen("b12b4.txt","r");




int bpb;
int nb;
int c,r;
int support,confidence;
///////////////////////////bits per band,no. of bands
bpb=4;
nb=12;
r=64;
c=64;
support=(int)((0.6)*(r*c));
confidence=60;
///////////////////////////
//printf("support-count=%d\n",support);
//printf("confidence=%d percent",confidence);
int i,j,k,count;
char data_formatted_dupli[c];
char data_formatted[r][c];


int azx=0;
azx=4000;
int temp_row[azx][bpb*nb*2];
int tr=0,tc=0,trc=0;

struct frequent
{
int row[azx][bpb*nb*2];
};
struct frequent fq[1];

struct kfrequent
{
int krow[azx][bpb*nb*2];
};
struct kfrequent kfq[1];


for(i=0;i<azx;i++)
for(j=0;j<(bpb*nb*2);j++)
{
fq[0].row[i][j]=0;
kfq[0].krow[i][j]=0;
temp_row[i][j]=0;
}

//-------------------------------------------------------------generating 1-frequent itemset-------------------------------------------------
//reading one complete bSQ
k=1;
dsent=malloc(sizeof(int) * (bpb*nb*2));
i=0;
j=0;
count=0;
int uniq[bpb*nb*2];
for(i=0;i<(bpb*nb*2);i++)
uniq[i]=0;
i=0;

while(i<(bpb*nb))
{
	switch(i)
	{

	case 0:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp1);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)  >= support)
		{
		uniq[count]=111;
		fq[0].row[count][0]=111;
		count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0) >= support)
		{
		uniq[count]=110;
		fq[0].row[count][0]=110;
		count++;
		}
		break;

	case 1:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp2);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=121;
		fq[0].row[count][0]=121;
		count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=120;
		fq[0].row[count][0]=120;
		count++;
		}
		break;

	case 2:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp3);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=131;
		fq[0].row[count][0]=131;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=130;
		fq[0].row[count][0]=130;count++;
		}
		break;

	case 3:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp4);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=141;
		fq[0].row[count][0]=141;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=140;
		fq[0].row[count][0]=140;count++;
		}
		break;

	case 4:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp5);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=211;
		fq[0].row[count][0]=211;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=210;
		fq[0].row[count][0]=210;count++;
		}
		break;

	case 5:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp6);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=221;
		fq[0].row[count][0]=221;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=220;
		fq[0].row[count][0]=220;count++;
		}
		break;

	case 6:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp7);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=231;
		fq[0].row[count][0]=231;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=230;
		fq[0].row[count][0]=230;count++;
		}
		break;
	case 7:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp8);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1) >= support)
		{
		uniq[count]=241;
		fq[0].row[count][0]=241;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0) >= support)
		{
		uniq[count]=240;
		fq[0].row[count][0]=240;count++;
		}
		break;

	case 8:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp9);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=311;
		fq[0].row[count][0]=311;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=310;
		fq[0].row[count][0]=310;count++;
		}
		break;
	case 9:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp10);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=321;
		fq[0].row[count][0]=321;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=320;
		fq[0].row[count][0]=320;count++;
		}
		break;

	case 10:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp11);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=331;
		fq[0].row[count][0]=331;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=330;
		fq[0].row[count][0]=330;count++;
		}
		break;

	case 11:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp12);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=341;
		fq[0].row[count][0]=341;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=340;
		fq[0].row[count][0]=340;count++;
		}
		break;

	case 12:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp13);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=411;
		fq[0].row[count][0]=411;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=410;
		fq[0].row[count][0]=410;count++;
		}
		break;

	case 13:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp14);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=421;
		fq[0].row[count][0]=421;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=420;
		fq[0].row[count][0]=420;count++;
		}
		break;

	case 14:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp15);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=431;
		fq[0].row[count][0]=431;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=430;
		fq[0].row[count][0]=430;count++;
		}
		break;

	case 15:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp16);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=441;
		fq[0].row[count][0]=441;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=440;
		fq[0].row[count][0]=440;count++;
		}
		break;
	case 16:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp17);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=511;
		fq[0].row[count][0]=511;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=510;
		fq[0].row[count][0]=510;count++;
		}
		break;
	case 17:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp18);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=521;
		fq[0].row[count][0]=521;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=520;
		fq[0].row[count][0]=520;count++;
		}
		break;
	case 18:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp19);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=531;
		fq[0].row[count][0]=531;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=530;
		fq[0].row[count][0]=530;count++;
		}
		break;
	case 19:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp20);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=541;
		fq[0].row[count][0]=541;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=540;
		fq[0].row[count][0]=540;count++;
		}
		break;
	case 20:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp21);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=611;
		fq[0].row[count][0]=611;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=610;
		fq[0].row[count][0]=610;count++;
		}
		break;
	case 21:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp22);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=621;
		fq[0].row[count][0]=621;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=620;
		fq[0].row[count][0]=620;count++;
		}
		break;
	case 22:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp23);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=631;
		fq[0].row[count][0]=631;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=630;
		fq[0].row[count][0]=630;count++;
		}
		break;
	case 23:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp24);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=641;
		fq[0].row[count][0]=641;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=640;
		fq[0].row[count][0]=640;count++;
		}
		break;

	case 24:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp25);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=711;
		fq[0].row[count][0]=711;
		count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=710;
		fq[0].row[count][0]=710;
		count++;
		}
		break;

	case 25:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp26);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=721;
		fq[0].row[count][0]=721;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=720;
		fq[0].row[count][0]=720;count++;
		}
		break;

	case 26:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp27);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=731;
		fq[0].row[count][0]=731;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=730;
		fq[0].row[count][0]=730;count++;
		}
		break;

	case 27:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp28);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=741;
		fq[0].row[count][0]=741;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=740;
		fq[0].row[count][0]=740;count++;
		}
		break;

	case 28:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp29);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=811;
		fq[0].row[count][0]=811;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=810;
		fq[0].row[count][0]=810;count++;
		}
		break;

	case 29:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp30);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=821;
		fq[0].row[count][0]=821;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=820;
		fq[0].row[count][0]=820;count++;
		}
		break;
	case 30:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp31);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1) >= support)
		{
		uniq[count]=831;
		fq[0].row[count][0]=831;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0) >= support)
		{
		uniq[count]=830;
		fq[0].row[count][0]=830;count++;
		}
		break;

	case 31:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp32);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=841;
		fq[0].row[count][0]=841;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=840;
		fq[0].row[count][0]=840;count++;
		}
		break;
	case 32:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp33);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=911;
		fq[0].row[count][0]=911;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=910;
		fq[0].row[count][0]=910;count++;
		}
		break;

	case 33:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp34);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=921;
		fq[0].row[count][0]=921;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=920;
		fq[0].row[count][0]=920;count++;
		}
		break;

	case 34:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp35);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=931;
		fq[0].row[count][0]=931;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=930;
		fq[0].row[count][0]=930;count++;
		}
		break;

	case 35:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp36);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=941;
		fq[0].row[count][0]=941;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=940;
		fq[0].row[count][0]=940;count++;
		}
		break;

	case 36:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp37);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1011;
		fq[0].row[count][0]=1011;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1010;
		fq[0].row[count][0]=1010;count++;
		}
		break;

	case 37:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp38);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1021;
		fq[0].row[count][0]=1021;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1020;
		fq[0].row[count][0]=1020;count++;
		}
		break;

	case 38:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp39);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1031;
		fq[0].row[count][0]=1031;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1030;
		fq[0].row[count][0]=1030;count++;
		}
		break;
	case 39:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp40);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1041;
		fq[0].row[count][0]=1041;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1040;
		fq[0].row[count][0]=1040;count++;
		}
		break;
	case 40:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp41);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1111;
		fq[0].row[count][0]=1111;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1110;
		fq[0].row[count][0]=1110;count++;
		}
		break;
	case 41:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp42);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1121;
		fq[0].row[count][0]=1121;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1120;
		fq[0].row[count][0]=1120;count++;
		}
		break;
	case 42:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp43);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1131;
		fq[0].row[count][0]=1131;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1130;
		fq[0].row[count][0]=1130;count++;
		}
		break;
	case 43:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp44);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1141;
		fq[0].row[count][0]=1141;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1140;
		fq[0].row[count][0]=1140;count++;
		}
		break;
	case 44:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp45);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1211;
		fq[0].row[count][0]=1211;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1210;
		fq[0].row[count][0]=1210;count++;
		}
		break;
	case 45:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp46);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1221;
		fq[0].row[count][0]=1221;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1220;
		fq[0].row[count][0]=1220;count++;
		}
		break;
	case 46:for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp47);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)>=support)
		{
		uniq[count]=1231;
		fq[0].row[count][0]=1231;count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0)>=support)
		{
		uniq[count]=1230;
		fq[0].row[count][0]=1230;count++;
		}
		break;
	case 47:	for(k=0;k<r;k++)
		{
		fgets(data_formatted_dupli,bpb*nb*c+2,(FILE*)fp48);
			for(j=0;j<c;j++)
			data_formatted[k][j]=data_formatted_dupli[j];
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,1)  >= support)
		{
		uniq[count]=1241;
		fq[0].row[count][0]=1241;
		count++;
		}
		if(countone(0,r-1,0,c-1,r,c,data_formatted,0) >= support)
		{
		uniq[count]=1240;
		fq[0].row[count][0]=1240;
		count++;
		}
		break;


	}

i++;
}//while

fclose(fp48);fclose(fp47);fclose(fp46);fclose(fp45);fclose(fp44);fclose(fp43);fclose(fp42);fclose(fp41);fclose(fp40);fclose(fp39);
fclose(fp38);fclose(fp37);fclose(fp36);fclose(fp35);fclose(fp34);fclose(fp33);fclose(fp32);fclose(fp31);fclose(fp30);fclose(fp29);
fclose(fp28);fclose(fp27);fclose(fp26);fclose(fp25);fclose(fp24);fclose(fp23);fclose(fp22);fclose(fp21);fclose(fp20);fclose(fp19);
fclose(fp18);fclose(fp17);fclose(fp16);fclose(fp15);fclose(fp14);fclose(fp13);fclose(fp12);fclose(fp11);fclose(fp10);fclose(fp9);
fclose(fp8);fclose(fp7);fclose(fp6);fclose(fp5);fclose(fp4);fclose(fp3);fclose(fp2);fclose(fp1);
k=1;
//printing stuff
printf("\n1-Frequent Itemsets:\n");
for(i=0;i<azx && fq[0].row[i][0]!=0;i++)
printf("%d\n",fq[0].row[i][0]);
int a,b;
int rno=0;
for(i=0;i<(bpb*nb*2);i++)
dsent[i]=0;

int x=0,y=0,xy=0,z=0;
int arr1[bpb*nb*2];
int arr2[bpb*nb*2];

for(i=0;i<(bpb*nb*2);i++)
arr1[i]=arr2[i]=0;

int game_ends=0;
int zero_not_found=0;
int grouping_similar=0;
int f=0;
int d=0;
int r123=0;
int twodone=1;
//------------------------------------------------Generating k-frequent itemset-----------------------------------
while(game_ends==0)
{
zero_not_found=0;

//calulating the k of n-C-k;k=zero_not_found
for(i=0;i<1;i++)
{
for(j=0;j<(bpb*nb*2);j++)
{
if(fq[0].row[i][j]==0)
break;

zero_not_found++;
}}


grouping_similar=zero_not_found-1;
//calculating 2-frequent itemsets.
if(grouping_similar==0 && twodone==1)
{

//all possible combinations generated,counts are determined,pruning is done.
	for(i=0;i<(azx-1);i++)
	{
		for(j=i+1;j<azx;j++)
		{
		a=fq[0].row[i][0];
		b=fq[0].row[j][0];
		//printf("%d %d-->",i,j);
			if(a!=0 && b!=0)
			{
			dsent[0]=a;
			dsent[1]=b;
				if(determine(bpb,nb,r,c,k,support,0)==1)
				{
				kfq[0].krow[rno][0]=a;
				kfq[0].krow[rno][1]=b;
				rno++;
				}
			}
		}	
	}


k=2;
//printing 2-frequent itemsets
f=0;
printf("\n2-Frequent Itemsets:\n");
for(i=0;i<azx;i++)
{
	for(j=0;j<(bpb*nb*2) && kfq[0].krow[i][j]!=0;j++)
	{
	f=1;
	printf("%d ",kfq[0].krow[i][j]);
	}
	if(f==1)
	printf("\n");
f=0;
}
//exchange of contents of structures.
tr=tc=0;
for(i=0;i<azx;i++)
for(j=0;j<(bpb*nb*2);j++)
{
fq[0].row[i][j]=kfq[0].krow[i][j];
	if(kfq[0].krow[i][j]!=0)
	{
	temp_row[tr][tc]=kfq[0].krow[i][j];
	//printf("%d(%d,%d) ",temp_row[tr][tc],tr,tc);
	tc++;
	trc=1;
	}
	if(trc==1 && kfq[0].krow[i][j]==0)
	{
	//printf("\n");
	tr++;
	trc=0;
	break;
	}

}
//printf("\n\n");
//Kfq copied into fq and Kfq is initialised with 0.
for(i=0;i<azx;i++)
for(j=0;j<bpb*nb*2;j++)
kfq[0].krow[i][j]=0;

twodone=0;
}

//////////////////////////////////////////////////////////////////////////////
//calculating n-frequent itemsets.

 if(grouping_similar>=1)
 {
  k++;
  r123=0;
  for(i=0;i<(azx-1);i++)
  {

	for(y=0;y<(bpb*nb*2) && fq[0].row[i][y]!=0;y++)
	arr1[y]=fq[0].row[i][y];

	for(j=i+1;j<azx;j++)
	{
		for(x=0;x<(bpb*nb*2) && fq[0].row[j][x]!=0;x++)
		arr2[x]=fq[0].row[j][x];

		xy=possible(bpb*nb*2,arr1,arr2,grouping_similar,k);
		if(xy==1)
		{	
			d=determine(bpb,nb,64,64,k,support,0);
			if(d==1)
			{	
				for(z=0;z<(bpb*nb*2) && dsent[z]!=0;z++)
				kfq[0].krow[r123][z]=dsent[z];
				r123++;
				d=0;				
			}
		xy=0;
		}
	for(c=0;c<(bpb*nb*2);c++)
	arr2[c]=0;
		
	}

   for(c=0;c<(bpb*nb*2);c++)
     arr1[c]=0;

if(i==(azx-2))
r123--;
}

//pruning 

 int t1[bpb*nb*2];				
 int t2[bpb*nb*2];
 int dec=0;
				
 for(i=0;i<(bpb*nb*2);i++)
 t1[i]=t2[i]=0;

 for(i=0;i<(azx-1);i++)
 {

	for(y=0;y<(bpb*nb*2) && kfq[0].krow[i][y]!=0;y++)
	t1[y]=kfq[0].krow[i][y];

		for(j=i+1;j<azx;j++)
		{

		for(x=0;x<(bpb*nb*2) && kfq[0].krow[j][x]!=0;x++)
		t2[x]=kfq[0].krow[j][x];


		       if(t1[0]!=0 && t2[0]!=0)					
		       dec=prune(bpb*nb*2,k,t1,t2);

			if(dec==1)
		    	{
			for(x=0;x<(bpb*nb*2);x++)
			kfq[0].krow[j][x]=0;
			r123--;
			}
	
		dec=0;
		for(x=0;x<(bpb*nb*2);x++)
		t2[x]=0;
		}

				
 for(x=0;x<(bpb*nb*2);x++)
 t1[x]=0;

 }
 //pruning closed





 ///////////////////////////////////////////////////////////////////////////
 //print stuff for k-frequent itemset.
 printf("%d-frequent itemset :\n",k);
 f=0;
 for(i=0;i<azx;i++)
 {
  for(j=0;j<(bpb*nb*2) && kfq[0].krow[i][j]!=0;j++)
  {
   f=1;
   printf("%d ",kfq[0].krow[i][j]);
  }
  if(f==1)
  {
   printf("\n");
   f=0;
  }
 }

//exchange of contents of structures.
tr=tc=0,trc=0;
 for(i=0;i<azx;i++)
  for(j=0;j<(bpb*nb*2);j++)
  {

fq[0].row[i][j]=kfq[0].krow[i][j];


	if(kfq[0].krow[i][j]!=0)
	{
	temp_row[tr][tc]=kfq[0].krow[i][j];
	//printf("%d(%d,%d) ",temp_row[tr][tc],tr,tc);
	tc++;
	trc=1;
	}
	if(trc==1 && kfq[0].krow[i][j]==0)
	{
	tr++;
	trc=0;
	tc=0;
	break;
	}
  }
tr=tc=0;

//printf("\n\n");
//Kfq copied into fq and Kfq is initialised with 0.
 for(i=0;i<azx;i++)
 {
   for(j=0;j<(bpb*nb*2);j++)
   {
     kfq[0].krow[i][j]=0;
   }
 }
}



//checking whether the game needs to be ended now.

 if(fq[0].row[0][0]==0)
 {
  game_ends=1;
  printf("No more frequent itemsets to display.\n");
  break;
 }
 else
 {
 cr123=r123;
 }

}
//end of while generating itemsets.


//-------------------------------------------------Generation of Association rules-----------------------------------------------
//printf("\n Association rules: \n");
k=k-1;
//k=5;
int repeat=0;
j=0;

/*for(i=0;i<azx;i++)
{
if(temp_row[i][0]==0)
break;
repeat++;
}*/

//fprintf(rule,"%c",function(k));
//fprintf(rule,"%c",'\n');

repeat=cr123+1;
//printf("repeat=%d",repeat);



int lhs[ ((int)(pow(2,k)) - 2) * (repeat)][k-1];
int rhs[ ((int)(pow(2,k)) - 2) * (repeat)][k-1];
int lh=0,rh=0;

for(i=0;i<((int)(pow(2,k)) - 2) * (repeat);i++)
for(j=0;j<(k-1);j++)
lhs[i][j]=rhs[i][j]=0;

i=0;
int current_itemset[k];
int cn=1;
int s=0,t,rr=0;
int rwno=0;
int flags=0;

struct lhss
{
int lhs11[2000][k-1];
};
struct lhss lhs1[1];

struct lhsss
{
int lhs22[2000][k-1];
};
struct lhsss lhs2[1];


int arr11[k-1];
int arr22[k-1];
xy=0;

for(i=0;i<2000;i++)
for(j=0;j<(k-1);j++)
lhs1[0].lhs11[i][j]=lhs2[0].lhs22[i][j]=0;

int t11[k-1];
int t22[k-1];
int dec1=0;

for(i=0;i<(k-1);i++)
arr11[i]=arr22[i]=t11[i]=t22[i]=0;

int ttt=0;
rr=0;

for(i=0;i<(bpb*nb*2);i++)
dsent[i]=0;

while(ttt<repeat)
{
while(cn<=(k-1))
{
		for(j=0;j<k;j++)
		current_itemset[j]=temp_row[ttt][j];
		if(cn==1)	
		{
		
			for(j=0;j<k;j++)
			{
			lhs1[0].lhs11[lh][0]=current_itemset[j];
			lhs[lh][0]=current_itemset[j];
			//printf("-->%d",lhs1[0].lhs11[j][0]);
			lh++;
			}
		}
		if(cn==2)
		{
		rwno=0;
			for(i=0;i<(2000-1);i++)
			{
				for(j=i+1;j<2000;j++)
				{
					if(lhs1[0].lhs11[i][0]!=0 && lhs1[0].lhs11[j][0]!=0)
				{				
					lhs2[0].lhs22[rwno][0]=lhs1[0].lhs11[i][0];
					lhs2[0].lhs22[rwno][1]=lhs1[0].lhs11[j][0];
					//printf("--%d,%d",lhs2[0].lhs22[rwno][0],lhs2[0].lhs22[rwno][1]);
					rwno++;
					}
				}
			}
		}
		
		if(cn>2)
		{
		rwno=0;
			for(i=0;i<(2000-1);i++)
			{
		
				for(y=0;y<(k-1) && lhs1[0].lhs11[i][y]!=0;y++)
				arr11[y]=lhs1[0].lhs11[i][y];
					for(j=i+1;j<2000;j++)
					{
						for(x=0;x<(k-1) && lhs1[0].lhs11[j][x]!=0;x++)
						arr22[x]=lhs1[0].lhs11[j][x];
					xy=possible(cn,arr11,arr22,cn-2,cn);
					if(xy==1)
					{	
						for(z=0;z<(k-1) && dsent[z]!=0;z++)
						{
						lhs2[0].lhs22[rwno][z]=dsent[z];
						//printf("%d,",lhs2[0].lhs22[rwno][z]);
						}
					rwno++;		
					xy=0;		
					}

					for(c=0;c<(k-1);c++)
					arr22[c]=0;
					}
			for(c=0;c<(k-1);c++)
			arr11[c]=0;
			}		

		}


		//pruning of lhs2
		if(cn>2)
		{
		
				
		for(i=0;i<(k-1);i++)
		t11[i]=t22[i]=0;

		for(i=0;i<(2000-1);i++)
		{

			for(y=0;y<(k-1) && lhs2[0].lhs22[i][y]!=0;y++)
			t11[y]=lhs2[0].lhs22[i][y];

				for(j=i+1;j<2000;j++)
				{

					for(x=0;x<(k-1) && lhs2[0].lhs22[j][x]!=0;x++)
					t22[x]=lhs2[0].lhs22[j][x];


		       			if(t11[0]!=0 && t22[0]!=0)					
		       			dec1=prune(k-1,cn,t11,t22);

					if(dec1==1)
		    			{
					for(x=0;x<(k-1);x++)
					lhs2[0].lhs22[j][x]=0;
					}
	
					dec1=0;
				for(x=0;x<(k-1);x++)
				t22[x]=0;
				}

				
		for(x=0;x<(k-1);x++)
		t11[x]=0;

		}
	/*for(i=0;i<2000;i++)
	{
		for(j=0;j<(k-1) && lhs2[0].lhs22[i][j]!=0;j++)
		printf("%d,",lhs2[0].lhs22[i][j]);
	}*/
	//pruning closed
	}
		//copying lhs2 into lhs1
		if(cn>=2)
		{
		for(i=0;i<(2000);i++)
			{
				for(j=0;j<(k-1);j++)
				{
				lhs1[0].lhs11[i][j]=lhs2[0].lhs22[i][j];
				}
			}
		/*for(i=0;i<2000;i++)
		{
		for(j=0;j<(k-1) && lhs1[0].lhs11[i][j]!=0;j++)
		printf("%d,",lhs1[0].lhs11[i][j]);
		}
		*/
		}
		//copying lhs1 into lhs for 2 0r more combos

		if(cn>=2)
		{
		for(i=0;i<2000;i++)
			{
				for(j=0;j<(k-1) && lhs1[0].lhs11[i][j]!=0;j++)
				{
				lhs[lh][rr++]=lhs1[0].lhs11[i][j];
				flags=1;
				}
			rr=0;
			if(flags==1)
			{
			lh++;
			flags=0;
			}
			}
		}

	
		

		
cn++;
}

for(i=0;i<2000;i++)
for(j=0;j<(k-1);j++)
lhs1[0].lhs11[i][j]=lhs2[0].lhs22[i][j]=0;

for(i=0;i<(k-1);i++)
arr11[i]=arr22[i]=t11[i]=t22[i]=0;

for(i=0;i<(bpb*nb*2);i++)
dsent[i]=0;

cn=1;
ttt++;
}

printf("LHS\n");
for(i=0;i<((int)(pow(2,k)) - 2) * (repeat);i++)
{
for(j=0;j<(k-1);j++)
{
printf("%d(%d,%d) ",lhs[i][j],i,j);
}
printf("\n");
}
printf("\n\n");


rh=0;
rr=0;s=0;t=0;
int found=0;
int uniq_copy[k];
int terminator=0;
while(terminator<repeat)
{

for(j=0;j<k;j++)
current_itemset[j]=temp_row[terminator][j];

	for(i=((int)(pow(2,k)) - 2) * terminator;i<(	((int)(pow(2,k)) - 2)*terminator +  ((int)(pow(2,k)) - 2)	);i++)
	{
		for(t=0;t<k;t++)
		uniq_copy[t]=current_itemset[t];

		for(j=0;j<(k-1);j++)
		{		
			if(lhs[i][j]!=0)
			{
				for(t=0;t<k;t++)
				{
					if(uniq_copy[t]==lhs[i][j])
					uniq_copy[t]=0;
					
				}
								
			}
	
		}
		for(t=0;t<k;t++)
		if(uniq_copy[t]!=0)
		rhs[rh][rr++]=uniq_copy[t];
	rr=0;	
	rh++;
	}

rr=0;
terminator++;
}


/*printf("\n\nRHS");
for(i=0;i<((int)(pow(2,k)) - 2) * (repeat);i++)
{
for(j=0;j<(k-1) && rhs[i][j]!=0;j++)
{
printf("%d(%d,%d) ",rhs[i][j],i,j);
}
printf("\n");
}
*/
printf("\n\n");


i=0;
double whole=0;
double partial=0;
double output=0;
int number;

for(j=0;j<bpb*nb*2;j++)
dsent[j]=0;
int lm=0,ln=0;
t=0;

//printf("confidence=%d\n",confidence);
while(t<repeat)
{
if(t==0)
fprintf(rule,"%c%c%c",function(k/10),function(k%10),'\n');

	for(j=0;j<k;j++)
	if(temp_row[t][j]!=0)
	{
	dsent[j]=temp_row[t][j];
	//printf("%d ",dsent[j]);
	}
	//printf("\n");

	whole=determine(bpb,nb,r,c,k,support,1);

	//printf("whole=%lf\n",whole);
	for(i=((int)(pow(2,k)) - 2) * t;i<(	((int)(pow(2,k)) - 2)*t +  ((int)(pow(2,k)) - 2)	);i++)
	{
		//printf("i=%d\n",i);

		for(j=0;j<(bpb*nb*2);j++)
		dsent[j]=0;
		for(j=0;j<(k-1) && lhs[i][j]!=0;j++)
		{
		dsent[j]=lhs[i][j];
		//printf("%d ",dsent[j]);
		}
		//printf("\n");

		
		partial=determine(bpb,nb,r,c,k,support,1);
		//printf("partial=%lf\n",partial);

		output=(whole/partial)*100;
		//printf("confi=%d",confidence);
		//printf("output=%lf\n",output);
		if(output>=confidence)
		{
			for(lm=0;lm<(k-1);lm++)
			{	
				number=dsent[lm];
				if(number!=0)
				{
				if(number<1000)
				fprintf(rule,"%c%c%c%c",function(number/100),function((number/10)%10),function(number%10),' ');
				else
				fprintf(rule,"%c%c%c%c%c",function(number/1000),function((number/100)%10),function((number/10)%10),function 					(number%10),' ');
				}
			}
			fprintf(rule,"%c",'-');fprintf(rule,"%c",'-');fprintf(rule,"%c",' ');
			for(ln=0;ln<(k-1) && rhs[i][ln]!=0;ln++)
			{
				number=rhs[i][ln];
				if(number!=0)
				{
				if(number<1000)
				fprintf(rule,"%c%c%c%c",function(number/100),function((number/10)%10),function(number%10),' ');
				else
				fprintf(rule,"%c%c%c%c%c",function(number/1000),function((number/100)%10),function((number/10)%10),function 					(number%10),' ');
				}
			
			}
		fprintf(rule,"%c",'\n');
		}
	}

for(ln=0;ln<(bpb*nb*2);ln++)
dsent[ln]=0;
number=0;

t++;
}

}
//main closes

//function for anding p-trees
int determine(int bpb,int nb,int r,int c,int k,int support,int choice)
{
int arr[bpb*nb*2];

int i,j;
char data_formatted1[r][c];
char data_formatted2[r][c];
char data_formatted_dupli[c];

arr[0]=111;arr[1]=121;arr[2]=131;arr[3]=141;
arr[4]=211;arr[5]=221;arr[6]=231;arr[7]=241;
arr[8]=311;arr[9]=321;arr[10]=331;arr[11]=341;
arr[12]=411;arr[13]=421;arr[14]=431;arr[15]=441;
arr[16]=511;arr[17]=521;arr[18]=531;arr[19]=541;
arr[20]=611;arr[21]=621;arr[22]=631;arr[23]=641;

arr[24]=110;arr[25]=120;arr[26]=130;arr[27]=140;
arr[28]=210;arr[29]=220;arr[30]=230;arr[31]=240;
arr[32]=310;arr[33]=320;arr[34]=330;arr[35]=340;
arr[36]=410;arr[37]=420;arr[38]=430;arr[39]=440;
arr[40]=510;arr[41]=520;arr[42]=530;arr[43]=540;
arr[44]=610;arr[45]=620;arr[46]=630;arr[47]=640;

arr[48]=711;arr[49]=721;arr[50]=731;arr[51]=741;
arr[52]=811;arr[53]=821;arr[54]=831;arr[55]=841;
arr[56]=911;arr[57]=921;arr[58]=931;arr[59]=941;
arr[60]=1011;arr[61]=1021;arr[62]=1031;arr[63]=1041;
arr[64]=1111;arr[65]=1121;arr[66]=1131;arr[67]=1141;
arr[68]=1211;arr[69]=1221;arr[70]=1231;arr[71]=1241;

arr[72]=710;arr[72]=720;arr[74]=730;arr[75]=740;
arr[76]=810;arr[77]=820;arr[78]=830;arr[79]=840;
arr[80]=910;arr[81]=920;arr[82]=930;arr[83]=940;
arr[84]=1010;arr[85]=1020;arr[86]=1030;arr[87]=1040;
arr[88]=1110;arr[89]=1120;arr[90]=1130;arr[91]=1140;
arr[92]=1210;arr[93]=1220;arr[94]=1230;arr[95]=1240;

int arrp=0;
int pos=0;

int dumb=0;
int blah=0;

for(i=0;i<r;i++)
for(j=0;j<c;j++)
data_formatted2[i][j]='1';

int m=0,n=0;
	for(i=0;i<(bpb*nb*2);i++)
	{
		if(dsent[i]!=0)
		{
			for(arrp=0;arrp<(bpb*nb*2);arrp++)
			{
			if(arr[arrp]==dsent[i])
			{
			pos=arrp;
			break;
			}}
			
		switch(pos)
		{
		case 0:	if(blah==0)
			dumb=0;

			FILE *fp1;
			fp1=fopen("b1b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp1);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp1);
				}
			fclose(fp1);
			break;

		case 1: if(blah==0)
			dumb=0;
			FILE *fp2;
			fp2=fopen("b1b2.txt","r");		
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp2);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp2);
				}
				fclose(fp2);
			break;

  		case 2: if(blah==0)
			dumb=0;
			FILE *fp3;
			fp3=fopen("b1b3.txt","r");
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp3);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp3);
				}
			fclose(fp3);
			break;


			case 3:if(blah==0)
				dumb=0;
				FILE *fp4;
				fp4=fopen("b1b4.txt","r");	
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp4);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp4);
				}
				fclose(fp4);
			break;

		case 4: if(blah==0)
			dumb=0;
			FILE *fp5;
			fp5=fopen("b2b1.txt","r");	
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp5);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp5);				
				}
			fclose(fp5);
			break;

		case 5: if(blah==0)
			dumb=0;
			FILE *fp6;
			fp6=fopen("b2b2.txt","r");
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp6);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp6);
				}
			fclose(fp6);
			break;

		case 6: if(blah==0)
			dumb=0;
			FILE *fp7;
			fp7=fopen("b2b3.txt","r");	
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp7);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp7);
				}
			fclose(fp7);
			break;

		case 7: if(blah==0)
			dumb=0;
			FILE *fp8;
			fp8=fopen("b2b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8);
				}
			fclose(fp8);
			break;

		case 8: if(blah==0)
			dumb=0;
			FILE *fp9;
			fp9=fopen("b3b1.txt","r");
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp9);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp9);
				}
			fclose(fp9);
			break;

		case 9: if(blah==0)
			dumb=0;
			FILE *fp10;
			fp10=fopen("b3b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp10);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp10);
				}
			fclose(fp10);
			break;

  		case 10: if(blah==0)
			dumb=0;
			FILE *fp11;
			fp11=fopen("b3b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp11);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp11);
				}
			fclose(fp11);
			break;

		case 11: if(blah==0)
			dumb=0;
			FILE *fp12;
			fp12=fopen("b3b4.txt","r");
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp12);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp12);
				}
			fclose(fp12);
			break;

		case 12: if(blah==0)
			dumb=0;
			FILE *fp13;
			fp13=fopen("b4b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp13);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp13);
				}
			fclose(fp13);
			break;

		case 13: if(blah==0)
			dumb=0;
			FILE *fp14;
			fp14=fopen("b4b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp14);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp14);
				}
			fclose(fp14);
			break;

		case 14: if(blah==0)
			dumb=0;
			FILE *fp15;
			fp15=fopen("b4b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp15);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp15);
				}
			fclose(fp15);
			break;

		case 15: if(blah==0)
			dumb=0;
			FILE *fp16;
			fp16=fopen("b4b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp16);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp16);
				}
			fclose(fp16);
			break;

		case 16: if(blah==0)
			dumb=0;
			FILE *fp17;
			fp17=fopen("b5b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp17);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp17);
				}
			fclose(fp17);
			break;

		case 17: if(blah==0)
			dumb=0;
			FILE *fp18;
			fp18=fopen("b5b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp18);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp18);
				}
			fclose(fp18);
			break;

		case 18: if(blah==0)
			dumb=0;
			FILE *fp19;
			fp19=fopen("b5b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp19);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp19);
				}
			fclose(fp19);
			break;

		case 19: if(blah==0)
			dumb=0;
			FILE *fp20;
			fp20=fopen("b5b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp20);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp20);
				}
			fclose(fp20);
			break;

		case 20: if(blah==0)
			dumb=0;
			FILE *fp21;
			fp21=fopen("b6b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp21);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp21);
				}
			fclose(fp21);
			break;

		case 21: if(blah==0)
			dumb=0;
			FILE *fp22;
			fp22=fopen("b6b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp22);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp22);
				}
			fclose(fp22);
			break;

		case 22: if(blah==0)
			dumb=0;
			FILE *fp23;
			fp23=fopen("b6b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp23);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp23);
				}
			fclose(fp23);
			break;

		case 23: if(blah==0)
			dumb=0;
			FILE *fp24;
			fp24=fopen("b6b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp24);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp24);
				}
			fclose(fp24);
			break;


		case 24: if(blah==0)
			dumb=0;
			FILE *fp91;
			fp91=fopen("b1b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp91);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp91);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp91);
			break;

		case 25: if(blah==0)
			dumb=0;
			FILE *fp92;
			fp92=fopen("b1b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp92);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp92);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp92);
			break;

  		case 26: if(blah==0)
			dumb=0;
			FILE *fp93;
			fp93=fopen("b1b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp93);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp93);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp93);
			break;

		case 27: if(blah==0)
			dumb=0;
			FILE *fp94;
			fp94=fopen("b1b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp94);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp94);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp94);
			break;

		case 28: if(blah==0)
			dumb=0;
			FILE *fp95;
			fp95=fopen("b2b1.txt","r");	

			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp95);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp95);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp95);
			break;

		case 29: if(blah==0)
			dumb=0;
				FILE *fp96;
				fp96=fopen("b2b2.txt","r");	
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp96);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp96);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp96);
			break;

		case 30: if(blah==0)
			dumb=0;
			FILE *fp97;
			fp97=fopen("b2b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp97);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp97);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp97);
			break;

		case 31: if(blah==0)
			dumb=0;
			FILE *fp98;
			fp98=fopen("b2b4.txt","r");		
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp98);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp98);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
		fclose(fp98);
			break;

		case 32: if(blah==0)
			dumb=0;
			FILE *fp99;
			fp99=fopen("b3b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp99);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp99);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp99);
			break;

		case 33: if(blah==0)
			dumb=0;
				FILE *fp910;
				fp910=fopen("b3b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp910);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp910);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp910);
			break;

  		case 34: if(blah==0)
			dumb=0;
		FILE *fp911;
		fp911=fopen("b3b3.txt","r");	
		for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp911);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp911);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp911);
			break;

		case 35: if(blah==0)
			dumb=0;
			FILE *fp912;
			fp912=fopen("b3b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp912);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp912);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
		fclose(fp912);
			break;

		case 36: if(blah==0)
			dumb=0;
			FILE *fp913;
			fp913=fopen("b4b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp913);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp913);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
		fclose(fp913);
			break;

		case 37: if(blah==0)
			dumb=0;
			FILE *fp914;
			fp914=fopen("b4b2.txt","r");;	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp914);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp914);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp914);
			break;

		case 38: if(blah==0)
			dumb=0;
			FILE *fp915;
			fp915=fopen("b4b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp915);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp915);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp915);
			break;

		case 39: if(blah==0)
			dumb=0;
			FILE *fp916;
			fp916=fopen("b4b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp916);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp916);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp916);
			break;
			
		case 40: if(blah==0)
			dumb=0;
			FILE *fp917;
			fp917=fopen("b5b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp917);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp917);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp917);
			break;

		case 41: if(blah==0)
			dumb=0;
			FILE *fp918;
			fp918=fopen("b5b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp918);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp918);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp918);
			break;

		case 42: if(blah==0)
			dumb=0;
			FILE *fp919;
			fp919=fopen("b5b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp919);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp919);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp919);
			break;

		case 43: if(blah==0)
			dumb=0;
			FILE *fp920;
			fp920=fopen("b5b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp920);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp920);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp920);
			break;

		case 44: if(blah==0)
			dumb=0;
			FILE *fp921;
			fp921=fopen("b6b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp921);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp921);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp921);
			break;

		case 45: if(blah==0)
			dumb=0;
			FILE *fp922;
			fp922=fopen("b6b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp922);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp922);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp922);
			break;

		case 46: if(blah==0)
			dumb=0;
			FILE *fp923;
			fp923=fopen("b6b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp923);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp923);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp923);
			break;

		case 47: if(blah==0)
			dumb=0;
			FILE *fp924;
			fp924=fopen("b6b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp924);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp924);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp924);
			break;

		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		case 48:	if(blah==0)
			dumb=0;

			FILE *fp81;
			fp81=fopen("b7b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp81);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp81);
				}
			fclose(fp81);
			break;

		case 49: if(blah==0)
			dumb=0;
			FILE *fp82;
			fp82=fopen("b7b2.txt","r");		
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp82);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp82);
				}
				fclose(fp82);
			break;

  		case 50: if(blah==0)
			dumb=0;
			FILE *fp83;
			fp83=fopen("b7b3.txt","r");
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp83);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp83);
				}
			fclose(fp83);
			break;


			case 51:if(blah==0)
				dumb=0;
				FILE *fp84;
				fp84=fopen("b7b4.txt","r");	
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp84);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp84);
				}
				fclose(fp84);
			break;

		case 52: if(blah==0)
			dumb=0;
			FILE *fp85;
			fp85=fopen("b8b1.txt","r");	
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp85);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp85);				
				}
			fclose(fp85);
			break;

		case 53: if(blah==0)
			dumb=0;
			FILE *fp86;
			fp86=fopen("b8b2.txt","r");
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp86);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp86);
				}
			fclose(fp86);
			break;

		case 54: if(blah==0)
			dumb=0;
			FILE *fp87;
			fp87=fopen("b8b3.txt","r");	
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp87);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp87);
				}
			fclose(fp87);
			break;

		case 55: if(blah==0)
			dumb=0;
			FILE *fp88;
			fp88=fopen("b8b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp88);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp88);
				}
			fclose(fp88);
			break;

		case 56: if(blah==0)
			dumb=0;
			FILE *fp89;
			fp89=fopen("b9b1.txt","r");
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp89);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp89);
				}
			fclose(fp89);
			break;

		case 57: if(blah==0)
			dumb=0;
			FILE *fp810;
			fp810=fopen("b9b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp810);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp810);
				}
			fclose(fp810);
			break;

  		case 58: if(blah==0)
			dumb=0;
			FILE *fp811;
			fp811=fopen("b9b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp811);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp811);
				}
			fclose(fp811);
			break;

		case 59: if(blah==0)
			dumb=0;
			FILE *fp812;
			fp812=fopen("b9b4.txt","r");
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp812);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp812);
				}
			fclose(fp812);
			break;

		case 60: if(blah==0)
			dumb=0;
			FILE *fp813;
			fp813=fopen("b10b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp813);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp813);
				}
			fclose(fp813);
			break;

		case 61: if(blah==0)
			dumb=0;
			FILE *fp814;
			fp814=fopen("b10b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp814);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp814);
				}
			fclose(fp814);
			break;

		case 62: if(blah==0)
			dumb=0;
			FILE *fp815;
			fp815=fopen("b10b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp815);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp815);
				}
			fclose(fp815);
			break;

		case 63: if(blah==0)
			dumb=0;
			FILE *fp816;
			fp816=fopen("b10b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp816);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp816);
				}
			fclose(fp816);
			break;

		case 64: if(blah==0)
			dumb=0;
			FILE *fp817;
			fp817=fopen("b11b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp817);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp817);
				}
			fclose(fp817);
			break;

		case 65: if(blah==0)
			dumb=0;
			FILE *fp818;
			fp818=fopen("b11b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp818);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp818);
				}
			fclose(fp818);
			break;

		case 66: if(blah==0)
			dumb=0;
			FILE *fp819;
			fp819=fopen("b11b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp819);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp819);
				}
			fclose(fp819);
			break;

		case 67: if(blah==0)
			dumb=0;
			FILE *fp820;
			fp820=fopen("b11b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp820);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp820);
				}
			fclose(fp820);
			break;

		case 68: if(blah==0)
			dumb=0;
			FILE *fp821;
			fp821=fopen("b12b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp821);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp821);
				}
			fclose(fp821);
			break;

		case 69: if(blah==0)
			dumb=0;
			FILE *fp822;
			fp822=fopen("b11b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp822);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp822);
				}
			fclose(fp822);
			break;

		case 70: if(blah==0)
			dumb=0;
			FILE *fp823;
			fp823=fopen("b11b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp823);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp823);
				}
			fclose(fp823);
			break;

		case 71: if(blah==0)
			dumb=0;
			FILE *fp824;
			fp824=fopen("b11b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp824);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp824);
				}
			fclose(fp824);
			break;


		case 72: if(blah==0)
			dumb=0;
			FILE *fp891;
			fp891=fopen("b12b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp891);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp891);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp891);
			break;

		case 73: if(blah==0)
			dumb=0;
			FILE *fp892;
			fp892=fopen("b12b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp892);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp892);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp892);
			break;

  		case 74: if(blah==0)
			dumb=0;
			FILE *fp893;
			fp893=fopen("b12b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp893);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp893);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp893);
			break;

		case 75: if(blah==0)
			dumb=0;
			FILE *fp894;
			fp894=fopen("b12b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp894);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp894);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp894);
			break;

		case 76: if(blah==0)
			dumb=0;
			FILE *fp895;
			fp895=fopen("b7b1.txt","r");	

			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp895);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp895);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp895);
			break;

		case 77: if(blah==0)
			dumb=0;
				FILE *fp896;
				fp896=fopen("b8b2.txt","r");	
				for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp896);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp896);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp896);
			break;

		case 78: if(blah==0)
			dumb=0;
			FILE *fp897;
			fp897=fopen("b8b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp897);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp897);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp897);
			break;

		case 79: if(blah==0)
			dumb=0;
			FILE *fp898;
			fp898=fopen("b8b4.txt","r");		
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp898);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp898);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
		fclose(fp898);
			break;

		case 80: if(blah==0)
			dumb=0;
			FILE *fp899;
			fp899=fopen("b9b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp899);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp899);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp899);
			break;

		case 81: if(blah==0)
			dumb=0;
				FILE *fp8910;
				fp8910=fopen("b9b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8910);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8910);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8910);
			break;

  		case 82: if(blah==0)
			dumb=0;
		FILE *fp8911;
		fp8911=fopen("b9b3.txt","r");	
		for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8911);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8911);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8911);
			break;

		case 83: if(blah==0)
			dumb=0;
			FILE *fp8912;
			fp8912=fopen("b9b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8912);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8912);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
		fclose(fp8912);
			break;

		case 84: if(blah==0)
			dumb=0;
			FILE *fp8913;
			fp8913=fopen("b10b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8913);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8913);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
		fclose(fp8913);
			break;

		case 85: if(blah==0)
			dumb=0;
			FILE *fp8914;
			fp8914=fopen("b10b2.txt","r");;	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8914);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8914);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8914);
			break;

		case 86: if(blah==0)
			dumb=0;
			FILE *fp8915;
			fp8915=fopen("b10b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8915);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8915);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8915);
			break;

		case 87: if(blah==0)
			dumb=0;
			FILE *fp8916;
			fp8916=fopen("b10b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8916);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8916);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8916);
			break;
			
		case 88: if(blah==0)
			dumb=0;
			FILE *fp8917;
			fp8917=fopen("b11b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8917);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8917);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8917);
			break;

		case 89: if(blah==0)
			dumb=0;
			FILE *fp8918;
			fp8918=fopen("b11b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8918);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8918);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8918);
			break;

		case 90: if(blah==0)
			dumb=0;
			FILE *fp8919;
			fp8919=fopen("b11b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8919);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8919);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8919);
			break;

		case 91: if(blah==0)
			dumb=0;
			FILE *fp8920;
			fp8920=fopen("b11b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8920);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8920);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8920);
			break;

		case 92: if(blah==0)
			dumb=0;
			FILE *fp8921;
			fp8921=fopen("b12b1.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8921);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8921);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8921);
			break;

		case 93: if(blah==0)
			dumb=0;
			FILE *fp8922;
			fp8922=fopen("b12b2.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8922);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8922);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8922);
			break;

		case 94: if(blah==0)
			dumb=0;
			FILE *fp8923;
			fp8923=fopen("b12b3.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8923);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8923);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8923);
			break;

		case 95: if(blah==0)
			dumb=0;
			FILE *fp8924;
			fp8924=fopen("b12b4.txt","r");	
			for(k=0;k<r;k++)
				{
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8924);
				for(j=0;j<c;j++)
				data_formatted1[k][j]=data_formatted_dupli[j];
				fgets(data_formatted_dupli,bpb*nb*c+1,(FILE*)fp8924);
				}
			for(m=0;m<r;m++)
				{	for(n=0;n<c;n++)
					{
						if(data_formatted1[m][n]=='1')
						data_formatted1[m][n]='0';
						else
						data_formatted1[m][n]='1';
					}
				}
			fclose(fp8924);
			break;

		}
		//main switch	


		}//if
		else
		{
		break;
		}
	//actual anding of two ptrees
	for(m=0;m<r;m++)
	{
	for(n=0;n<c;n++)
	{
	data_formatted2[m][n]=data_formatted2[m][n] & data_formatted1[m][n];
	}}
	
	}//for loop



if( countone(0,r-1,0,c-1,r,c,data_formatted2,1)>= support)
{
//printf("True-->%d=\n",countone(0,r-1,0,c-1,r,c,data_formatted2,1));
if(choice==0)		
return 1;
else
return countone(0,r-1,0,c-1,r,c,data_formatted2,1);
}
else
{
//printf("False-->%d=\n",countone(0,r-1,0,c-1,r,c,data_formatted2,1));
if(choice==0)	
return 0;
else
return countone(0,r-1,0,c-1,r,c,data_formatted2,1);
}

}

//function for pruning
int prune(int count,int k,int t1[count],int t2[count])
{

int count123=k;

int i,j;

for(i=0;i<count;i++)
{

	for(j=0;j<count;j++)
	{
	if(t1[i]==t2[j] && t1[i]!=0 && t2[j]!=0)
	{
	count123--;
	//printf("%d   %d\n",t1[i],t2[j]);
	}
	}
}


if(count123==0)
{
return 1;
}
return 0;

}


//function for generating itemset
int possible(int count,int arr1[count],int arr2[count],int grouping_similar,int k)
{
int i,j;
int x,y,z;

for(i=0;i<count;i++)
dsent[i]=0;
int similar_count=k-2;

int a,b;

//finding the n(A intersection B) and if it matches the required value return 1.
for(i=0;i<(k-1) && arr1[i]!=0;i++)
{
a=arr1[i];
for(j=0;j<(k-1) && arr2[j]!=0;j++)
{
b=arr2[j];
if(a==b)
similar_count--;
}}

if(similar_count==0)
{

for(i=0;i<(k-1);i++)
dsent[i]=arr1[i];

int f=0;
for(j=0;j<(k-1);j++)
{
	for(i=0;i<(k-1);i++)
	if(arr2[j]==dsent[i])
	f=1;

	if(f==0)
	{
	dsent[i]=arr2[j];
	break;
	}
f=0;
}
//itemset has been generated and it is in dsent.
return 1;
}
//if closed

return 0;
}

/*
//function for creating p-tree
int ptree_compute(int row1,int col1,char data_formatted[row1][col1])
{
//////////////////bits per band,no of bands.
int bpb=4;
int nb=3;
int r=row1,c=col1;
//////////////////

ptree=malloc(sizeof(int) * 10000);
int pt=0;
int pu=3;
int rootcount=0;
current_box=malloc(sizeof(int) * 4);

int pure_nodes=0;
pure_nodes_level=malloc(sizeof(int) * 1000);
int pn1,pn2=4,pn3=0;

remaining=malloc(sizeof(int) * 1000);
int rem=0,r1=0,r2=0,r3=0,r4=0;

x1=malloc(sizeof(int) * 10000);
x2=malloc(sizeof(int) * 10000);
y11=malloc(sizeof(int) * 10000);
y2=malloc(sizeof(int) * 10000);
	x1[0]=0;
	x2[0]=r-1;
	y11[0]=0;
	y2[0]=c-1;
int xy=1;
int cxy=0;
int midx=0,midy=0;
int temp=0;
int i,j,k,l,m,n;

char test[c];
int col=0;

for(i=0;i<1000;i++)
{
remaining[i]=0;
pure_nodes_level[i]=0;
}

/////////////////////////////////////////////////////////////Game starts -->P-tree
rootcount=countone(0,r-1,0,c-1,r,c,data_formatted,1);
for(k=0;k<10000;k++)
ptree[k]=-1;

for(n=0;n<10000;n++)
x1[n]=x2[n]=y11[n]=y2[n]=rootcount+1;

x1[0]=0;
x2[0]=r-1;
y11[0]=0;
y2[0]=c-1;

while(cxy<xy)
{

current_box[0]=x1[cxy];
current_box[1]=x2[cxy];
current_box[2]=y11[cxy];
current_box[3]=y2[cxy];
x1[cxy]=x2[cxy]=y11[cxy]=y2[cxy]=0;
cxy++;


pu=pure(current_box[0],current_box[1],current_box[2],current_box[3],r,c,data_formatted);
if(pu==0 || pu==1)
{

if( (current_box[0]==current_box[1]) && (current_box[2]==current_box[3]))
ptree[pt]=pu;
else
{
	ptree[pt]=countone(current_box[0],current_box[1],current_box[2],current_box[3],r,c,data_formatted,1);
temp=pt;
i=1;
	for(k=0;r4==0;k++)
	{
	r1=(int)(pow(4,k));
	r2=(int)(pow(4,k+1));
		if(pt>=r1 && pt<=r2)
		{
				while(temp>0)
				{
				temp=temp-pow(4,i);
				i++;
				}
				pure_nodes_level[pure_nodes]=i-1;
				pn1=i-1;
				pure_nodes++;	
				
			
		r3=(pt-r1)*4 + (r1*4) + 1;
		break;
		}
	}

	for(k=0;pure_nodes_level[k]!=0;k++)
	{

		for(j=pure_nodes_level[k]+2;j<=pn1+1;j++)
		{
		pn2=pn2*4;
		pn3=1;
		}
		if(pn3==1)
		{
		r3=r3-pn2;
		pn2=4;
		pn3=0;	
		}
	}

	
	remaining[rem]=r3;
	rem++;
}

pt++;
}

else
{
midx=(int) ((current_box[0]+current_box[1])/2);
midy=(int) ((current_box[2]+current_box[3])/2);


x1[xy]=current_box[0];
x2[xy]=midx;
y11[xy]=current_box[2];
y2[xy]=midy;
xy++;
x1[xy]=current_box[0];
x2[xy]=midx;
y11[xy]=midy+1;
y2[xy]=current_box[3];
xy++;
x1[xy]=midx+1;
x2[xy]=current_box[1];
y11[xy]=midy+1;
y2[xy]=current_box[3];
xy++;
x1[xy]=midx+1;
x2[xy]=current_box[1];
y11[xy]=current_box[2];
y2[xy]=midy;
xy++;

ptree[pt]=countone(current_box[0],current_box[1],current_box[2],current_box[3],r,c,data_formatted,1);
pt++;

}

for(k=0;k<1000;k++)
{
	if(remaining[k]!=0)
		for(l=0;l<4;l++)
			ptree[remaining[k]+l]=rootcount+1;

}

for(k=0;k<1000;k++)
remaining[k]=0;
rem=0;

for(l=pt;r4==0;l++)
{
	if(ptree[l]==-1)
	break;
pt++;
}

}
//single p-tree's while



}
*/
//function for finding whether its pa pure quadrant;returns 0 or 1 or 2
int pure(int a,int b,int c,int d,int r,int col,char data_formatted[r][col])
{
int i,j,count1=0,count0=0;
int diff_ab=0;
int diff_cd=0;

diff_ab=b-a;
diff_cd=d-c;

if(diff_ab<0)
diff_ab=-diff_ab;
if(diff_cd<0)
diff_cd=-diff_cd;

diff_ab=diff_ab+1;
diff_cd=diff_cd+1;

for(i=a;i<=b;i++)
{
	for(j=c;j<=d;j++)
	{

	if(data_formatted[i][j]=='1')
	count1++;
	if(data_formatted[i][j]=='0')
	count0++;

	}
}



if(count1==(diff_ab*diff_cd))
return 1;
if(count0==(diff_ab*diff_cd))
return 0;

return 2;

}


//for finding number of 1s
int countone(int a,int b,int c,int d,int r,int col,char data_formatted[r][col],int find)
{
int i,j,k;
int count=0;
char ch;

if(find==1)
ch='1';
else
ch='0';

for(i=a;i<=b;i++)
{
	for(j=c;j<=d;j++)
	{
	if(data_formatted[i][j]==ch)
	{
	count++;
	}
	}
}

return count;
}

char function(int a)
{
int arr[10];
char arr2[10];
arr2[0]='0';arr2[1]='1';arr2[2]='2';arr2[3]='3';arr2[4]='4';arr2[5]='5';arr2[6]='6';arr2[7]='7';arr2[8]='8';arr2[9]='9';

int i;
char ch;
for(i=0;i<10;i++)
arr[i]=i;

for(i=0;i<10;i++)
{
	if(a==arr[i])
	return arr2[i];
}	
}



