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




int bpb;
int nb;
int c,r;
int support,confidence;
///////////////////////////bits per band,no. of bands
bpb=4;
nb=6;
r=64;
c=64;
support=(int)((0.5)*(r*c));
confidence=60;
///////////////////////////
//printf("support-count=%d\n",support);
//printf("confidence=%d percent",confidence);
int i,j,k,count;
char data_formatted_dupli[c];
char data_formatted[r][c];


int azx=0;
azx=500;
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

	}

i++;
}//while

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


printf("\n\nRHS");
for(i=0;i<((int)(pow(2,k)) - 2) * (repeat);i++)
{
for(j=0;j<(k-1) && rhs[i][j]!=0;j++)
{
printf("%d(%d,%d) ",rhs[i][j],i,j);
}
printf("\n");
}

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
				fprintf(rule,"%c%c%c%c",function(number/100),function((number/10)%10),function(number%10),' ');
				}
			}
			fprintf(rule,"%c",'-');fprintf(rule,"%c",'-');fprintf(rule,"%c",' ');
			for(ln=0;ln<(k-1) && rhs[i][ln]!=0;ln++)
			{
				number=rhs[i][ln];
				if(number!=0)
				{
				fprintf(rule, "%c%c%c%c",function(number/100),function((number/10)%10),function(number%10),' ');
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



