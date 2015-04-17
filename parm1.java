import java.io.*;
import java.awt.*;
import java.awt.image.BufferedImage;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

class parm1
{


static char function(int a)throws Exception
{
	int arr[]=new int[10];
	char arr2[]=new char[10];
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
	return '0';
	
}

static void func()throws Exception
{
int i,j;
BufferedImage image;
BufferedImage image2;

int width;
int height;

////////////////////////////////////////////////////////////////////////Game starts-->generating colors and writing it to a file rsi.txt

FileWriter  w=new FileWriter("dimensions.txt");
BufferedWriter br=new BufferedWriter(w);

File input = new File("geo1.jpg");
File input2 = new File("geo2.jpg");

image = ImageIO.read(input);
image2 = ImageIO.read(input2);

width = image.getWidth();
height = image.getHeight();
if(width>=1000)
{
w.write(function(width/1000));w.write( function((width/100)%10) );
w.write( function((width/10)%10) );w.write( function(width%10) );
w.write("\r\n");
w.write(function(height/1000));w.write( function((height/100)%10) );
w.write( function((height/10)%10) );w.write( function(height%10) );
}
else
{
if(width>99)
w.write(function(width/100));

w.write( function((width/10)%10) );
w.write( function(width%10) );
w.write("\r\n");

if(width>99)
w.write(function(height/100));

w.write( function((height/10)%10) );
w.write( function(height%10));
}
w.close();

FileWriter  w2=new FileWriter("parm_rsi.txt");
BufferedWriter br2=new BufferedWriter(w2);

int count = 0;
int r,g,b,k,l;
int r2,g2,b2;

int ra[]=new int[8];
int ga[]=new int[8];
int ba[]=new int[8];
int im2[]=new int[8];

int ct=0;
int avg=0;

//height=rows and width=cols
for(i=0; i<height; i++)
{
for(j=0; j<width; j++)         
{


for(k=0;k<8;k++)
ra[k]=ga[k]=ba[k]=im2[k]=0;

count++;
Color c = new Color(image.getRGB(j, i)); 
Color c2 = new Color(image2.getRGB(j, i));         
//System.out.println("pixel co-or. (R,G,B) " + count + "\t:\t" + c.getRed() +"," + c.getGreen() + "," + c.getBlue()+" \t;\t " + c2.getRed() +"," + c2.getGreen() + "," + c2.getBlue());    

r=c.getRed();
g=c.getGreen();
b=c.getBlue();
r2=c2.getRed();
g2=c2.getGreen();
b2=c2.getBlue();

avg=(int)((r2+g2+b2)/3);

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
while(avg!=0)
{
im2[ct]=avg%2;
avg=avg/2;
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

l=im2[k];
im2[k]=im2[7-k];
im2[7-k]=l;
}

for(l=0;l<4;l++)
{
if(ra[l]==1)
w2.write('1');
else
w2.write('0');
}
for(l=0;l<4;l++)
{
if(ga[l]==1)
w2.write('1');
else
w2.write('0');
}
for(l=0;l<4;l++)
{
if(ba[l]==1)
w2.write('1');
else
w2.write('0');
}
for(l=0;l<4;l++)
{
if(im2[l]==1)
w2.write('1');
else
w2.write('0');
}

          
}
w2.write("\r\n");
}      
////////////////////////////////////////////////////////////////////////
w2.close();         
}

public static void main(String args[]) throws Exception 
{
 func();

}
   
}
