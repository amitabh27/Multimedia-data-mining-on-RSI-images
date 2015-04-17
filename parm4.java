import java.io.*;
import java.awt.*;
import java.awt.image.BufferedImage;

import javax.imageio.ImageIO;
import javax.swing.JFrame;


class parm4
{

static int width,height;

public static void func()throws Exception
{
int i,j;
BufferedImage image;
BufferedImage image2;

//static int width;
//static int height;

////////////////////////////////////////////////////////////////////////Game starts-->generating colors and writing it to a file rsi.txt

FileWriter  w=new FileWriter("o1.txt");
BufferedWriter br=new BufferedWriter(w);

File input = new File("geo3.jpg");

image = ImageIO.read(input);

width = image.getWidth();
height = image.getHeight();
int count = 0;
int r,g,b,k,l;

int ra[]=new int[8];
int ga[]=new int[8];
int ba[]=new int[8];
//int im2[]=new int[8];

int ct=0;
int avg=0;

//height=rows and width=cols
for(i=0; i<height; i++)
{
for(j=0; j<width; j++)         
{


for(k=0;k<8;k++)
ra[k]=ga[k]=ba[k]=0;

count++;
Color c = new Color(image.getRGB(j, i)); 

r=c.getRed();
g=c.getGreen();
b=c.getBlue();

avg=(int)((r+g+b)/3);

while(r!=0)
{
ra[ct]=r%2;
r=r/2;
ct++;
}
ct=0;
while(g!=0)
{
ga[ct]=g%2;
g=g/2;
ct++;
}
ct=0;
while(b!=0)
{
ba[ct]=b%2;
b=b/2;
ct++;
}
ct=0;


for(k=0;k<4;k++)
{
l=ra[k];
ra[k]=ra[7-k];
ra[7-k]=l;

l=ga[k];
ga[k]=ga[7-k];
ga[7-k]=l;

l=ba[k];
ba[k]=ba[7-k];
ba[7-k]=l;

}

for(l=0;l<4;l++)
{
if(ra[l]==1)
w.write('1');
else
w.write('0');
}
for(l=0;l<4;l++)
{
if(ga[l]==1)
w.write('1');
else
w.write('0');
}
for(l=0;l<4;l++)
{
if(ba[l]==1)
w.write('1');
else
w.write('0');
}


          
}
w.write("\r\n");
}      
////////////////////////////////////////////////////////////////////////
w.close();         
}



 public static int countLines(String filename) throws IOException
 {
   LineNumberReader reader  = new LineNumberReader(new FileReader(filename));
   int cnt = 0;
   String lineRead = "";
   while ((lineRead = reader.readLine()) != null)
   {
   }
   cnt = reader.getLineNumber(); 
   reader.close();
   return cnt;
 }


 public static void main(String args[]) throws Exception
 {

  func();

  System.out.println("height "+height+" width "+width);

  int number=countLines("rules.txt")-1;
  System.out.println(number); 

  /*String inputrules[][]=new String[number][200];
  int i=0,j=0;
  for(i=0;i<number;i++)
  {
    for(j=0;j<200;j++)
    {
      inputrules[i][j]="*";
    }
  }*/

  //FileReader r=new FileReader("//home//mpiu//parmfiles//images//rules.txt");
  

  BufferedReader reader = new BufferedReader(new FileReader("rules.txt"));
  String line = reader.readLine();
  int kfrequent=Integer.parseInt(line);
  line = reader.readLine();
  int abc=0;
  int i=0,j=0;
   int rules_row=4000;
  String left[][]=new String[rules_row][100];
  String right[][]=new String[rules_row][100];

  while (line!=null)
   {
                // Print read line
      //System.out.println("line "+i+" :"+line);
      String s[]=line.split(" ");
      int len=s.length;
      int lab=0;
              
      int left_side=0,right_side=0;
      while(right_side!=2)
	{
	
	   j=0;
           while(left_side!=1)
            {
                    System.out.println(" "+s[lab]);

                    if(right_side==0)
	               left[i][j++]=s[lab];


                    if(right_side==1)
	               right[i][j++]=s[lab];



                     if(lab==len-1)
                     { 
                       left_side=1;
                     }
		     lab++;

                     if(right_side==0)
		     {
                       if(s[lab].equals("--"))
                       {   
                         left_side=1;
                       }
                     }
            }
  	   left_side=0;
           right_side++;
  	   lab++;
       } 
      line = reader.readLine();
      i++;
    }
   int no_of_rules=0;

//   int left_frequent[]=new int[]


   System.out.println("\nPrinting left side of rules");
   for(i=0;i<rules_row && left[i][0]!=null;i++)
   { 
     for(j=0;j<100 && left[i][j]!=null;j++)
     {
      //System.out.println(left[i][j]);
     }
     no_of_rules++;
   }
    
   int left_frequent[]=new int[no_of_rules];
   for(i=0;i<no_of_rules;i++)
   {
     left_frequent[i]=0;
     for(j=0;j<100;j++)
     {
         left_frequent[i]++;
         if(left[i][j+1]==null)
            j=100;
     }
    
   }


   System.out.println("\nPrinting right side of rules");
   for(i=0;i<no_of_rules;i++)//i<100 && right[i][0]!=null;i++)
   {
     for(j=0;j<100;j++)
     {
      System.out.println(right[i][j]);
      if(right[i][j+1]==null)
         j=100;
     }
   }

   int right_frequent[]=new int[no_of_rules];
   for(i=0;i<no_of_rules;i++)
   {
     right_frequent[i]=0;
     for(j=0;j<100;j++)
     {
         right_frequent[i]++;
         if(right[i][j+1]==null)
            j=100;
     }
    
   }



     String bline=new String();

     //System.out.println("\n"+bline+"\n");
     //System.out.println("length is : "+(bline.length()/12));


   int bnumber=countLines("o1.txt");
   System.out.println(bnumber); 

   int r=4,g=4,b=4;
   int rgb=r+g+b;
   int k=0;
   int size=width*rgb;

   int outimg[][]=new int[height][size];
   /*for(i=0;i<height;i++)
     for(j=0;j<size;j++)
        outimg[i][j]=0;*/
  //logic modified..............................................................
  String outimg_gen_dup[]=new String[width*3*4];
  BufferedReader reader12 = new BufferedReader(new FileReader("o1.txt"));
  String line12;
  char storing_row[]=new char[width*3*4];
  
  for(i=0;i<height;i++)
  {
  line12 = reader12.readLine();
  outimg_gen_dup[i]=line12;
  storing_row=outimg_gen_dup[i].toCharArray();
  	for(j=0;j<(width*3*4);j++)
	{
	if((int)(storing_row[j])==48)
	outimg[i][j]=0;
	else
	outimg[i][j]=1;
	}
  }




   int i1=0,j1=0,k1=0,i2=0;
   int inputmatch[]=new int[kfrequent];
   int pattern=0;

   //System.out.println("No of rules = "+no_of_rules);






   for(j1=0;j1<no_of_rules;j1++)
   {
     int leftcount=left_frequent[j1];
       for(i1=0;i1<leftcount;i1++)
           {
             inputmatch[i1]=Integer.parseInt(left[j1][i1]);
           }

        BufferedReader binary = new BufferedReader(new FileReader("o1.txt"));
          
     // inputmatch[i1]=left[j1][i1];
   
/*
	      int band=0,bit=0,value=0;
              band=inputmatch[i1]/100;
              bit= (inputmatch[i1]%100)/10
              value=inputmatch[i1]%10;
*/
      for(i=0;i<bnumber;i++)
      {

        bline=binary.readLine();
        //System.out.println("line read is "+i+" "+bline);
          
        for(j=0;j<bnumber;j++)
         { 
           String subline=new String();
           subline=bline.substring(j*rgb,(j*rgb)+rgb);
         
           String subline_half[]=new String[3];
           for(k=0;k<3;k++)
            {
              subline_half[k]=subline.substring(k*r,k*r+r);
            }
  
	   for(i2=0,pattern=0;i2<leftcount;i2++)
            {
	      int band=0,bit=0,value=0,subvalue=0;
              band=inputmatch[i2]/100;
              bit= (inputmatch[i2]%100)/10;
              value=inputmatch[i2]%10;
	
              switch(band)
               {
		 case 1:
			subvalue=Integer.parseInt(subline_half[band-1]);
 		        switch(bit)
			{
			  case 1:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 2:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 3:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 4:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;


			}// switch bit
		  break;

		case 2:
			subvalue=Integer.parseInt(subline_half[band-1]);
 		        switch(bit)
			{
			  case 1:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 2:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 3:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 4:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;


			}// switch bit

		  break;

		case 3:
			subvalue=Integer.parseInt(subline_half[band-1]);
 		        switch(bit)
			{
			  case 1:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 2:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 3:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;
			  case 4:
				if((subvalue/1000) ==  value)
                                 {
			            pattern=pattern+1;	    
                                 }
				else
				 {
				   i2=kfrequent;
				 }
                          break;


			}// switch bit

		  break;

		 default://for band 4,5,6 on lhs of a rule
			     pattern=pattern+1;
		  break;

    	      }//switch
            }   //for i2

	     if(pattern==leftcount)
	      {
                 int i3=0,j3=0,k3=0;
                 int rightcount=right_frequent[j1];
		int outputmatch[]=new int[rightcount];
                for(i3=0;i3<rightcount;i3++)
                 {
		   outputmatch[i3]=Integer.parseInt(right[j1][i3]);
		 }

               for(i3=0;i3<rightcount;i3++)
		{
     	          int band=0,bit=0,value=0;
                  band=outputmatch[i3]/100;
		  band=band-4;
                  bit= (outputmatch[i3]%100)/10;
                  value=outputmatch[i3]%10;
		  int subvalue=j*rgb;
                  
                  if(band<0) // for bands 1,2,3 on rhs of a rule
                  {}
                  else
		  {

		  switch(band)
                   {
			case 0:
				subvalue=subvalue+(band*4);
				switch(bit)
				{
				  case 1:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 2:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 3:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 4:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;

				}//switch bit for band 1
			break;
			case 1:
				subvalue=subvalue+(band*4);
				switch(bit)
				{
				  case 1:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 2:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 3:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 4:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;

				}// switch bit for band 2
			break;
			case 2:
				subvalue=subvalue+(band*4);
				switch(bit)
				{
				  case 1:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 2:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 3:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;
				  case 4:
					 subvalue=subvalue+bit-1;
					 outimg[i][subvalue]=value;
				  break;

				}//switch bit for band 3
			break;
		    }// switch band
		   }// else
		}// for i3
       
	      	
	      }// if

         
       }// for j
     }// for i
   j1++;
   }//for j1


  FileWriter  w1=new FileWriter("generatedrgb.txt");
  BufferedWriter br=new BufferedWriter(w1);

   for(i=0;i<height;i++)
   {
//     System.out.println("\n");
     for(j=0;j<size;j++)
      {
//	System.out.print(outimg[i][j]);
        if(outimg[i][j]==1)
         {
           w1.write('1');
	 }
        if(outimg[i][j]==0)
         {
           w1.write('0');
         } 
      }
     w1.write("\n");

   } 
  w1.close();


  int outimg_gen[][]=new int[height][width*3];

  int counting=0;

  size=width*3;  

  BufferedImage imagemin=new BufferedImage(width,height,BufferedImage.TYPE_INT_RGB);
  BufferedImage imagemax=new BufferedImage(width,height,BufferedImage.TYPE_INT_RGB);


  for(i=0;i<height;i++)
  {//System.out.println();
   counting=0;
   for(j=0;j<size;j++)
   {
   // outimg_gen[i][j]=0;
    int temporary=j;
    int rgb1[]={128,64,32,16};
    for(k=0;k<4;k++)
    {
     outimg_gen[i][j]=outimg_gen[i][j]+outimg[i][j*4+k]*rgb1[k];
    }
    
    int calci[]=new int[3];
    if(j%3==2) //blue
      {
      outimg_gen[i][j]=(int)(outimg_gen[i][j]*0.114);
        //calculate=0;
       for(k=2;k>=0;k--)
       {
         //calculate=calculate+outimg_gen[i][temporary];
         calci[k]=outimg_gen[i][temporary];
         temporary--;
       }
       int pixel=temporary/3;
       Color newColorMin=new Color(calci[0],calci[1],calci[2]);
       imagemin.setRGB(pixel,i,newColorMin.getRGB());
       
       Color newColorMax=new Color(calci[0]+15,calci[1]+15,calci[2]+15);
       imagemax.setRGB(pixel,i,newColorMax.getRGB());

      //Color newColor = new Color(calculate,calculate,calculate);
      // image.setRGB(pixel,i,newColor.getRGB());
      }
//    System.out.print(calculate);//(outimg_gen[i][j]);
   }
  }  
 File ouptutmin = new File("generated_image1.jpg");
 ImageIO.write(imagemin, "jpg", ouptutmin);

 File ouptutmax = new File("generated_image2.jpg");
 ImageIO.write(imagemax, "jpg", ouptutmax);





 } // main
}  // class

   
 



