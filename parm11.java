import java.io.*;
import java.awt.*;
import java.awt.image.BufferedImage;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

class parm11
{



static void func()throws Exception
{
int i,j;
BufferedImage image;
BufferedImage image2;

int width;
int height;

////////////////////////////////////////////////////////////////////////Game starts-->generating colors and writing it to a file rsi.txt

FileWriter  w=new FileWriter("parm_rsi.txt");
BufferedWriter br=new BufferedWriter(w);

File input = new File("geo1.jpg");
File input2 = new File("geo2.jpg");

image = ImageIO.read(input);
image2 = ImageIO.read(input2);

width = image.getWidth();
height = image.getHeight();
int count = 0;
int r,g,b,k,l;
int r2,g2,b2;

int ra[]=new int[8];
int ga[]=new int[8];
int ba[]=new int[8];
int ra2[]=new int[8];
int ga2[]=new int[8];
int ba2[]=new int[8];



int ct=0;


//height=rows and width=cols
for(i=0; i<height; i++)
{
for(j=0; j<width; j++)         
{

for(k=0;k<8;k++)
ra[k]=ga[k]=ba[k]=ra2[k]=ga2[k]=ba2[k]=0;

count++;
Color c = new Color(image.getRGB(j, i)); 
Color c2 = new Color(image2.getRGB(j, i));         

r=c.getRed();
g=c.getGreen();
b=c.getBlue();
r2=c2.getRed();
g2=c2.getGreen();
b2=c2.getBlue();

//avg=(int)((r2+g2+b2)/3);

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


while(r2!=0)
{
ra2[ct]=r2%2;
r2=r2/2;
ct++;
}




ct=0;

while(g2!=0)
{
ga2[ct]=g2%2;
g2=g2/2;
ct++;
}



ct=0;

while(b2!=0)
{
ba2[ct]=b2%2;
b2=b2/2;
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


/*
l=im2[k];
im2[k]=im2[7-k];
im2[7-k]=l;*/


l=ra2[k];
ra2[k]=ra2[7-k];
ra2[7-k]=l;

l=ga2[k];
ga2[k]=ga2[7-k];
ga2[7-k]=l;

l=ba2[k];
ba2[k]=ba2[7-k];
ba2[7-k]=l;




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



for(l=0;l<4;l++)
{
if(ra2[l]==1)
w.write('1');
else
w.write('0');
}



for(l=0;l<4;l++)
{
if(ga2[l]==1)
w.write('1');
else
w.write('0');
}



for(l=0;l<4;l++)
{
if(ba2[l]==1)
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

public static void main(String args[]) throws Exception 
{
 func();

}
   
}
