#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int n;
    for(int i=0 ; i<height ; ++i )
    {
      for(int j=0 ; j<width ; ++j )
      {
        n = round((image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue)/3.0);
        image[i][j].rgbtRed=n;
        image[i][j].rgbtGreen=n;
        image[i][j].rgbtBlue=n;
      }

    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int n;
    for(int i=0 ; i<height ; ++i )
    {
      for(int j=0 ; j<width ; ++j )
      {
    int originalRed=image[i][j].rgbtRed;
    int originalGreen=image[i][j].rgbtGreen;
    int originalBlue=image[i][j].rgbtBlue;
    n = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
    if (n>255)
      {
          n=255;
      }
      image[i][j].rgbtRed = n;
    n = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
    if (n>255)
      {
          n=255;
      }
      image[i][j].rgbtGreen = n;
      n= round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);
      if (n>255)
      {
          n=255;
      }
      image[i][j].rgbtBlue = n;
     }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE glass;
    for(int i=0 ; i<height ; ++i )
    {
      for(int j=0 ; j<width/2 ; ++j )
      {
       glass = image[i][j];
       image[i][j]=image[i][width-1-j];
       image[i][width-1-j] = glass ;
      }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int sumr,sumg, sumb;
    int neighbors;
    for(int i =0 ; i<height ; ++i)
    {
        for (int j =0 ; j<width ; ++j)
        {
          sumr=0;
          sumb=0;
          sumg=0;
          neighbors=0;
          for(int n = i-1 ; n<=i+1 ; ++n)
          {
            if (n<0 || n>height-1)
            {
                continue;
            }
            for(int k=j-1 ; k<=j+1 ; ++k)
            {
             if (k<0 || k>width-1)
            {
                continue;
            }
            sumr +=image[n][k].rgbtRed;
            sumg +=image[n][k].rgbtGreen;
            sumb +=image[n][k].rgbtBlue;
            neighbors +=1;
            }
          }
          temp[i][j].rgbtRed = round(sumr/(float)neighbors);
          temp[i][j].rgbtGreen = round(sumg/(float)neighbors);
          temp[i][j].rgbtBlue = round(sumb/(float)neighbors);
        }
    }
    for(int i=0 ; i<height ; ++i)
    {
        for (int j=0 ; j< width ; ++j)
        {
            image[i][j]=temp[i][j];
        }
    }
    return;
}
