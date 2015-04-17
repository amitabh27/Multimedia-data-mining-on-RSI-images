import java.awt.*;
import java.awt.image.BufferedImage;

import java.io.*;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

class parm6
{

static void func1()throws Exception 
{
BufferedImage  image,image2;
int width;
int height;

File input = new File("generated_image2.jpg");
image = ImageIO.read(input);
width = image.getWidth();
height = image.getHeight();
         
int i,j;  
int red,green,blue;   
for(i=0; i<height; i++)
{
for(j=0; j<width; j++)
{
            
Color c = new Color(image.getRGB(j, i));
red=(int)(c.getRed() * 0.299);
green=(int)(c.getGreen() * 0.587);
blue=(int)(c.getBlue() *0.114);
Color newColor = new Color(red+green+blue,red+green+blue,red+green+blue);
image.setRGB(j,i,newColor.getRGB());
}
}
File ouptut = new File("generated_image2.jpg");
ImageIO.write(image, "jpg", ouptut);

      
}


   
   public static void main(String args[]) throws Exception 
   {
     func1();
   }
}
