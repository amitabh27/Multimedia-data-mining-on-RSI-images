#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
int bpb,nb;
int r,c;
////////////bits per band and number of bands
bpb=4;
nb=12;                                                                          //4;
r=64; c=64;
/////////////

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
FILE *fp17;
fp17=fopen("parm_rsi.txt","r");
FILE *fp18;
fp18=fopen("parm_rsi.txt","r");
FILE *fp19;
fp19=fopen("parm_rsi.txt","r");
FILE *fp20;
fp20=fopen("parm_rsi.txt","r");
FILE *fp21;
fp21=fopen("parm_rsi.txt","r");
FILE *fp22;
fp22=fopen("parm_rsi.txt","r");
FILE *fp23;
fp23=fopen("parm_rsi.txt","r");
FILE *fp24;
fp24=fopen("parm_rsi.txt","r");

FILE *fp91;
fp91=fopen("parm_rsi.txt","r");
FILE *fp92;
fp92=fopen("parm_rsi.txt","r");
FILE *fp93;
fp93=fopen("parm_rsi.txt","r");
FILE *fp94;
fp94=fopen("parm_rsi.txt","r");
FILE *fp95;
fp95=fopen("parm_rsi.txt","r");
FILE *fp96;
fp96=fopen("parm_rsi.txt","r");
FILE *fp97;
fp97=fopen("parm_rsi.txt","r");
FILE *fp98;
fp98=fopen("parm_rsi.txt","r");
FILE *fp99;
fp99=fopen("parm_rsi.txt","r");
FILE *fp910;
fp910=fopen("parm_rsi.txt","r");
FILE *fp911;
fp911=fopen("parm_rsi.txt","r");
FILE *fp912;
fp912=fopen("parm_rsi.txt","r");
FILE *fp913;
fp913=fopen("parm_rsi.txt","r");
FILE *fp914;
fp914=fopen("parm_rsi.txt","r");
FILE *fp915;
fp915=fopen("parm_rsi.txt","r");
FILE *fp916;
fp916=fopen("parm_rsi.txt","r");
FILE *fp917;
fp917=fopen("parm_rsi.txt","r");
FILE *fp918;
fp918=fopen("parm_rsi.txt","r");
FILE *fp919;
fp919=fopen("parm_rsi.txt","r");
FILE *fp920;
fp920=fopen("parm_rsi.txt","r");
FILE *fp921;
fp921=fopen("parm_rsi.txt","r");
FILE *fp922;
fp922=fopen("parm_rsi.txt","r");
FILE *fp923;
fp923=fopen("parm_rsi.txt","r");
FILE *fp924;
fp924=fopen("parm_rsi.txt","r");








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


FILE *w51;
w51=fopen("b5b1.txt","w");
FILE *w52;
w52=fopen("b5b2.txt","w");
FILE *w53;
w53=fopen("b5b3.txt","w");
FILE *w54;
w54=fopen("b5b4.txt","w");


FILE *w61;
w61=fopen("b6b1.txt","w");
FILE *w62;
w62=fopen("b6b2.txt","w");
FILE *w63;
w63=fopen("b6b3.txt","w");
FILE *w64;
w64=fopen("b6b4.txt","w");

FILE *w71;
w71=fopen("b7b1.txt","w");
FILE *w72;
w72=fopen("b7b2.txt","w");
FILE *w73;
w73=fopen("b7b3.txt","w");
FILE *w74;
w74=fopen("b7b4.txt","w");

FILE *w81;
w81=fopen("b8b1.txt","w");
FILE *w82;
w82=fopen("b8b2.txt","w");
FILE *w83;
w83=fopen("b8b3.txt","w");
FILE *w84;
w84=fopen("b8b4.txt","w");

FILE *w91;
w91=fopen("b9b1.txt","w");
FILE *w92;
w92=fopen("b9b2.txt","w");
FILE *w93;
w93=fopen("b9b3.txt","w");
FILE *w94;
w94=fopen("b9b4.txt","w");

FILE *w101;
w101=fopen("b10b1.txt","w");
FILE *w102;
w102=fopen("b10b2.txt","w");
FILE *w103;
w103=fopen("b10b3.txt","w");
FILE *w104;
w104=fopen("b10b4.txt","w");

FILE *w111;
w111=fopen("b11b1.txt","w");
FILE *w112;
w112=fopen("b11b2.txt","w");
FILE *w113;
w113=fopen("b11b3.txt","w");
FILE *w114;
w114=fopen("b11b4.txt","w");

FILE *w121;
w121=fopen("b12b1.txt","w");
FILE *w122;
w122=fopen("b12b2.txt","w");
FILE *w123;
w123=fopen("b12b3.txt","w");
FILE *w124;
w124=fopen("b12b4.txt","w");



int i,j,k;
char testing1[bpb*nb*c];char testing2[bpb*nb*c];char testing3[bpb*nb*c];char testing4[bpb*nb*c];
char testing5[bpb*nb*c];char testing6[bpb*nb*c];char testing7[bpb*nb*c];char testing8[bpb*nb*c];
char testing9[bpb*nb*c];char testing10[bpb*nb*c];char testing11[bpb*nb*c];char testing12[bpb*nb*c];
char testing13[bpb*nb*c];char testing14[bpb*nb*c];char testing15[bpb*nb*c];char testing16[bpb*nb*c];
char testing17[bpb*nb*c];char testing18[bpb*nb*c];char testing19[bpb*nb*c];char testing20[bpb*nb*c];
char testing21[bpb*nb*c];char testing22[bpb*nb*c];char testing23[bpb*nb*c];char testing24[bpb*nb*c];

char testing25[bpb*nb*c];char testing26[bpb*nb*c];char testing27[bpb*nb*c];char testing28[bpb*nb*c];
char testing29[bpb*nb*c];char testing30[bpb*nb*c];char testing31[bpb*nb*c];char testing32[bpb*nb*c];
char testing33[bpb*nb*c];char testing34[bpb*nb*c];char testing35[bpb*nb*c];char testing36[bpb*nb*c];
char testing37[bpb*nb*c];char testing38[bpb*nb*c];char testing39[bpb*nb*c];char testing40[bpb*nb*c];
char testing41[bpb*nb*c];char testing42[bpb*nb*c];char testing43[bpb*nb*c];char testing44[bpb*nb*c];
char testing45[bpb*nb*c];char testing46[bpb*nb*c];char testing47[bpb*nb*c];char testing48[bpb*nb*c];



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
		fgets(testing14,bpb*nb*c+1,(FILE*)fp14);
		fprintf(w42,"%c",'\n');
		}		
		break;
		//fclose(w42);

	case 15:for(k=0;k<r;k++)
		{
		fgets(testing15,bpb*nb*c+1,(FILE*)fp15);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w43,"%c",testing15[j]);
		fgets(testing15,bpb*nb*c+1,(FILE*)fp15);
		fprintf(w43,"%c",'\n');
		}		
		break;
		//fclose(w43);

	case 16:for(k=0;k<r;k++)
		{
		fgets(testing16,bpb*nb*c+1,(FILE*)fp16);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w44,"%c",testing16[j]);
		fgets(testing16,bpb*nb*c+1,(FILE*)fp16);
		fprintf(w44,"%c",'\n');
		}		
		break;



	case 17:for(k=0;k<r;k++)
		{
		fgets(testing17,bpb*nb*c+1,(FILE*)fp17);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w51,"%c",testing17[j]);
		fgets(testing17,bpb*nb*c+1,(FILE*)fp17);
		fprintf(w51,"%c",'\n');
		}		
		break;

	case 18:for(k=0;k<r;k++)
		{
		fgets(testing18,bpb*nb*c+1,(FILE*)fp18);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w52,"%c",testing18[j]);
		fgets(testing18,bpb*nb*c+1,(FILE*)fp18);
		fprintf(w52,"%c",'\n');
		}		
		break;


	case 19:for(k=0;k<r;k++)
		{
		fgets(testing19,bpb*nb*c+1,(FILE*)fp19);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w53,"%c",testing19[j]);
		fgets(testing19,bpb*nb*c+1,(FILE*)fp19);
		fprintf(w53,"%c",'\n');
		}		
		break;


	case 20:for(k=0;k<r;k++)
		{
		fgets(testing20,bpb*nb*c+1,(FILE*)fp20);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w54,"%c",testing20[j]);
		fgets(testing20,bpb*nb*c+1,(FILE*)fp20);
		fprintf(w54,"%c",'\n');
		}		
		break;


	case 21:for(k=0;k<r;k++)
		{
		fgets(testing21,bpb*nb*c+1,(FILE*)fp21);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w61,"%c",testing21[j]);
		fgets(testing21,bpb*nb*c+1,(FILE*)fp21);
		fprintf(w61,"%c",'\n');
		}		
		break;


	case 22:for(k=0;k<r;k++)
		{
		fgets(testing22,bpb*nb*c+1,(FILE*)fp22);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w62,"%c",testing22[j]);
		fgets(testing22,bpb*nb*c+1,(FILE*)fp22);
		fprintf(w62,"%c",'\n');
		}		
		break;


	case 23:for(k=0;k<r;k++)
		{
		fgets(testing23,bpb*nb*c+1,(FILE*)fp23);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w63,"%c",testing23[j]);
		fgets(testing23,bpb*nb*c+1,(FILE*)fp23);
		fprintf(w63,"%c",'\n');
		}		
		break;


	case 24:for(k=0;k<r;k++)
		{
		fgets(testing24,bpb*nb*c+1,(FILE*)fp24);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w64,"%c",testing24[j]);
		fgets(testing24,bpb*nb*c+1,(FILE*)fp24);
		fprintf(w64,"%c",'\n');
		}		
		break;

	case 25: for(k=0;k<r;k++)
		{
		fgets(testing25,bpb*nb*c+1,(FILE*)fp91);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			{fprintf(w71,"%c",testing25[j]);}
		fgets(testing25,bpb*nb*c+1,(FILE*)fp91);
		fprintf(w71,"%c",'\n');
		}
		break;
		//fclose(w11);
		
	case 26: for(k=0;k<r;k++)
		{
		fgets(testing26,bpb*nb*c+1,(FILE*)fp92);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w72,"%c",testing26[j]);
		fgets(testing26,bpb*nb*c+1,(FILE*)fp92);
		fprintf(w72,"%c",'\n');
		}
		break;		
		//fclose(w12);

	case 27: for(k=0;k<r;k++)
		{
		fgets(testing27,bpb*nb*c+1,(FILE*)fp93);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w73,"%c",testing27[j]);
		fgets(testing27,bpb*nb*c+1,(FILE*)fp93);
		fprintf(w73,"%c",'\n');
		}
		break;		
		//fclose(w13);

	case 28:
		for(k=0;k<r;k++)
		{
		fgets(testing28,bpb*nb*c+1,(FILE*)fp94);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w74,"%c",testing28[j]);
		fgets(testing28,bpb*nb*c+1,(FILE*)fp94);
		fprintf(w74,"%c",'\n');
		}	
		break;
		//fclose(w14);
	
	case 29: for(k=0;k<r;k++)
		{
		fgets(testing29,bpb*nb*c+1,(FILE*)fp95);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w81,"%c",testing29[j]);
		fgets(testing29,bpb*nb*c+1,(FILE*)fp95);
		fprintf(w81,"%c",'\n');
		}		
		break;
 		//fclose(w21);

	case 30: for(k=0;k<r;k++)
		{
		fgets(testing30,bpb*nb*c+1,(FILE*)fp96);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w82,"%c",testing30[j]);
		fgets(testing30,bpb*nb*c+1,(FILE*)fp96);
		fprintf(w82,"%c",'\n');
		}
		break;		
		//fclose(w22);

	case 31: for(k=0;k<r;k++)
		{
		fgets(testing31,bpb*nb*c+1,(FILE*)fp97);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w83,"%c",testing31[j]);
		fgets(testing31,bpb*nb*c+1,(FILE*)fp97);
		fprintf(w83,"%c",'\n');
		}	
		break;
		//fclose(w23);	
	
	case 32: for(k=0;k<r;k++)
		{
		fgets(testing32,bpb*nb*c+1,(FILE*)fp98);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w84,"%c",testing32[j]);
		fgets(testing32,bpb*nb*c+1,(FILE*)fp98);
		fprintf(w84,"%c",'\n');
		}
		break;
		//fclose(w24);		
	
	case 33: for(k=0;k<r;k++)
		{
		fgets(testing33,bpb*nb*c+1,(FILE*)fp99);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w91,"%c",testing33[j]);
		fgets(testing33,bpb*nb*c+1,(FILE*)fp99);
		fprintf(w91,"%c",'\n');
		}
		break;
		//fclose(w31);		
	
	case 34:for(k=0;k<r;k++)
		{
		fgets(testing34,bpb*nb*c+1,(FILE*)fp910);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w92,"%c",testing34[j]);
		fgets(testing34,bpb*nb*c+1,(FILE*)fp910);
		fprintf(w92,"%c",'\n');
		}		
		break;
		//fclose(w32);

	case 35:for(k=0;k<r;k++)
		{
		fgets(testing35,bpb*nb*c+1,(FILE*)fp911);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w93,"%c",testing35[j]);
		fgets(testing35,bpb*nb*c+1,(FILE*)fp911);
		fprintf(w93,"%c",'\n');
		}		
		break;
		//fclose(w33);

	case 36:for(k=0;k<r;k++)
		{
		fgets(testing36,bpb*nb*c+1,(FILE*)fp912);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w94,"%c",testing36[j]);
		fgets(testing36,bpb*nb*c+1,(FILE*)fp912);
		fprintf(w94,"%c",'\n');
		}		
		break;
		//fclose(w34);	

	case 37:for(k=0;k<r;k++)
		{
		fgets(testing37,bpb*nb*c+1,(FILE*)fp913);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w101,"%c",testing37[j]);
		fgets(testing37,bpb*nb*c+1,(FILE*)fp913);
		fprintf(w101,"%c",'\n');
		}		
		break;
		//fclose(w41);

	case 38:for(k=0;k<r;k++)
		{
		fgets(testing38,bpb*nb*c+1,(FILE*)fp914);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w102,"%c",testing38[j]);
		fgets(testing38,bpb*nb*c+1,(FILE*)fp914);
		fprintf(w102,"%c",'\n');
		}		
		break;
		//fclose(w42);

	case 39:for(k=0;k<r;k++)
		{
		fgets(testing39,bpb*nb*c+1,(FILE*)fp915);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w103,"%c",testing39[j]);
		fgets(testing39,bpb*nb*c+1,(FILE*)fp915);
		fprintf(w103,"%c",'\n');
		}		
		break;
		//fclose(w43);

	case 40:for(k=0;k<r;k++)
		{
		fgets(testing40,bpb*nb*c+1,(FILE*)fp916);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w104,"%c",testing40[j]);
		fgets(testing40,bpb*nb*c+1,(FILE*)fp916);
		fprintf(w104,"%c",'\n');
		}		
		break;



	case 41:for(k=0;k<r;k++)
		{
		fgets(testing41,bpb*nb*c+1,(FILE*)fp917);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w111,"%c",testing41[j]);
		fgets(testing41,bpb*nb*c+1,(FILE*)fp917);
		fprintf(w111,"%c",'\n');
		}		
		break;

	case 42:for(k=0;k<r;k++)
		{
		fgets(testing42,bpb*nb*c+1,(FILE*)fp918);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w112,"%c",testing42[j]);
		fgets(testing42,bpb*nb*c+1,(FILE*)fp918);
		fprintf(w112,"%c",'\n');
		}		
		break;


	case 43:for(k=0;k<r;k++)
		{
		fgets(testing43,bpb*nb*c+1,(FILE*)fp919);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w113,"%c",testing43[j]);
		fgets(testing43,bpb*nb*c+1,(FILE*)fp919);
		fprintf(w113,"%c",'\n');
		}		
		break;


	case 44:for(k=0;k<r;k++)
		{
		fgets(testing44,bpb*nb*c+1,(FILE*)fp920);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w114,"%c",testing44[j]);
		fgets(testing44,bpb*nb*c+1,(FILE*)fp920);
		fprintf(w114,"%c",'\n');
		}		
		break;


	case 45:for(k=0;k<r;k++)
		{
		fgets(testing45,bpb*nb*c+1,(FILE*)fp921);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w121,"%c",testing45[j]);
		fgets(testing45,bpb*nb*c+1,(FILE*)fp921);
		fprintf(w121,"%c",'\n');
		}		
		break;


	case 46:for(k=0;k<r;k++)
		{
		fgets(testing46,bpb*nb*c+1,(FILE*)fp922);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w122,"%c",testing46[j]);
		fgets(testing46,bpb*nb*c+1,(FILE*)fp922);
		fprintf(w122,"%c",'\n');
		}		
		break;


	case 47:for(k=0;k<r;k++)
		{
		fgets(testing47,bpb*nb*c+1,(FILE*)fp923);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w123,"%c",testing47[j]);
		fgets(testing47,bpb*nb*c+1,(FILE*)fp923);
		fprintf(w123,"%c",'\n');
		}		
		break;


	case 48:for(k=0;k<r;k++)
		{
		fgets(testing48,bpb*nb*c+1,(FILE*)fp924);
			for(j=i;j<(c*bpb*nb);j=j+(bpb*nb))
			fprintf(w124,"%c",testing48[j]);
		fgets(testing48,bpb*nb*c+1,(FILE*)fp924);
		fprintf(w124,"%c",'\n');
		}		
		break;








		//fclose(w44);
	}

}
}
