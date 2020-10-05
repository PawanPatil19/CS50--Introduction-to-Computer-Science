#include "helpers.h"
#include <math.h>
#include <string.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
   for(int i=0; i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            image[i][j].rgbtRed=round(((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.000));
            image[i][j].rgbtBlue=image[i][j].rgbtRed;
            image[i][j].rgbtGreen=image[i][j].rgbtRed;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	 BYTE temp;
     for(int i=0; i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
          for(int a=j+1; a<width;a++)
            {
                temp=image[i][j].rgbtBlue;
                image[i][j].rgbtBlue=image[i][a].rgbtBlue;
                image[i][a].rgbtBlue=temp;

                temp=image[i][j].rgbtRed;
                image[i][j].rgbtRed=image[i][a].rgbtRed;
                image[i][a].rgbtRed=temp;


                temp=image[i][j].rgbtGreen;
                image[i][j].rgbtGreen=image[i][a].rgbtGreen;
                image[i][a].rgbtGreen=temp;
            }
        }

    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE imgCopy[height][width];
	float avgRed;
	float avgGreen;
	float avgBlue;

	//create a copy of original image to save original pixel values
	for (int row = 0; row < height; row++)
	{
		for (int w = 0; w < width; w++)
		{
			imgCopy[row][w].rgbtRed = image[row][w].rgbtRed;
			imgCopy[row][w].rgbtGreen = image[row][w].rgbtGreen;
			imgCopy[row][w].rgbtBlue = image[row][w].rgbtBlue;


		}
	}

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{


			//if the pixel is on the top left edge
			if (w == 0 && h == 0)
			{
				avgRed = (float)(imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 4;

				avgGreen = (float)(imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 4;

				avgBlue = (float)(imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 4;
				avgRed = round(avgRed);
				avgBlue = round(avgBlue);
				avgGreen = round(avgGreen);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}

			//if the pixel is on the lower left edge
			else if (w == 0 && h == (height - 1))
			{
				avgRed =(float)(imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed) / 4;

				avgGreen = (float)(imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen) / 4;

				avgBlue = (float)(imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue) / 4;
				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
                                image[h][w].rgbtBlue = avgBlue;
			}

			//if the pixel is on top Right
			else if (h == 0 && w == (width - 1))
			{
				avgRed = (float)(imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed)/ 4;

				avgGreen = (float)(imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen) / 4;

				avgBlue = (float)(imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue) / 4;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
                image[h][w].rgbtBlue = avgBlue;
			}

			//if the pixel is on lower right
			else if(h == (height - 1) && w == (width - 1))
			{
				avgRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed) / 4;

		 		avgBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue) / 4;

				avgGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen) / 4;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
                image[h][w].rgbtBlue = avgBlue;
			}
       //if the pixel is on left side

			else if (w == 0 && (h > 0 && h < height - 1))
			{
				avgRed = (float)(imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 6;

				avgGreen = (float)(imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 6;

				avgBlue = (float)(imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 6;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}
      //if the pixel is on right side
			else if (w == (width - 1) && (h > 0 && h < height - 1))
			{
				avgRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed) / 6;

				avgGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen) / 6;

				avgBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue) / 6;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
                image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}
       //if the pixel is on upper side
			else if (h == 0 && (w > 0 &&  w < width - 1))
			{
				avgRed = (float)(imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 6;

				avgGreen = (float)(imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 6;

				avgBlue = (float)(imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 6;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}
       //if the pixel is on lower side
			else if  (h == height - 1 && (w > 0 && w < width - 1))
			{
				avgRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed) / 6;

				avgGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen) / 6;
				avgBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue) / 6;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}
      //if the pixel is on the middle and can form a 3x3 grid
			else
			{
				avgRed = (float)(imgCopy[h-1][w-1].rgbtRed + imgCopy[h-1][w].rgbtRed + imgCopy[h-1][w+1].rgbtRed + imgCopy[h][w-1].rgbtRed + imgCopy[h][w].rgbtRed + imgCopy[h][w+1].rgbtRed + imgCopy[h+1][w-1].rgbtRed + imgCopy[h+1][w].rgbtRed + imgCopy[h+1][w+1].rgbtRed) / 9;
				avgGreen = (float)(imgCopy[h-1][w-1].rgbtGreen + imgCopy[h-1][w].rgbtGreen + imgCopy[h-1][w+1].rgbtGreen + imgCopy[h][w-1].rgbtGreen + imgCopy[h][w].rgbtGreen + imgCopy[h][w+1].rgbtGreen + imgCopy[h+1][w-1].rgbtGreen + imgCopy[h+1][w].rgbtGreen + imgCopy[h+1][w+1].rgbtGreen) / 9;

				avgBlue = (float)(imgCopy[h-1][w-1].rgbtBlue + imgCopy[h-1][w].rgbtBlue + imgCopy[h-1][w+1].rgbtBlue + imgCopy[h][w-1].rgbtBlue + imgCopy[h][w].rgbtBlue + imgCopy[h][w+1].rgbtBlue + imgCopy[h+1][w-1].rgbtBlue + imgCopy[h+1][w].rgbtBlue + imgCopy[h+1][w+1].rgbtBlue) / 9;

				avgRed = round(avgRed);
				avgGreen = round(avgGreen);
				avgBlue = round(avgBlue);

				image[h][w].rgbtRed = avgRed;
				image[h][w].rgbtGreen = avgGreen;
				image[h][w].rgbtBlue = avgBlue;
			}

		}
	}

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
	RGBTRIPLE imgCopy[height][width];
	memcpy(imgCopy,image,sizeof(RGBTRIPLE)*height*width);

	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			float avgRedx=0.0;
			float avgGreenx=0.0;
			float avgBluex=0.0;
			float avgRedy=0.0;
			float avgGreeny=0.0;
			float avgBluey=0.0;

			//if pixel is the the first pixel of the image
				if (w == 0 && h == 0)
			{
				avgRedx = imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*2 + imgCopy[h+1][w].rgbtRed*0 + imgCopy[h+1][w+1].rgbtRed*1;
				avgGreenx = imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*2 + imgCopy[h+1][w].rgbtGreen*0 + imgCopy[h+1][w+1].rgbtGreen*1;
				avgBluex = imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*2 + imgCopy[h+1][w].rgbtBlue*0 + imgCopy[h+1][w+1].rgbtBlue*1;

				avgRedy = imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*0 + imgCopy[h+1][w].rgbtRed*2 + imgCopy[h+1][w+1].rgbtRed*1;
				avgGreeny = imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*0 + imgCopy[h+1][w].rgbtGreen*2 + imgCopy[h+1][w+1].rgbtGreen*1;
				avgBluey = imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*0 + imgCopy[h+1][w].rgbtBlue*2 + imgCopy[h+1][w+1].rgbtBlue*1;


			}

			//if the pixel is on the lower left edge
			else if (w == 0 && h == (height - 1))
			{
				avgRedx =imgCopy[h-1][w].rgbtRed*0 + imgCopy[h-1][w+1].rgbtRed*1 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*2;
				avgGreenx =imgCopy[h-1][w].rgbtGreen*0 + imgCopy[h-1][w+1].rgbtGreen*1 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*2;
				avgBluex =imgCopy[h-1][w].rgbtBlue*0 + imgCopy[h-1][w+1].rgbtBlue*1 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*2;

				avgRedy =imgCopy[h-1][w].rgbtRed*-2 + imgCopy[h-1][w+1].rgbtRed*-1 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*0;
				avgGreeny =imgCopy[h-1][w].rgbtGreen*-2 + imgCopy[h-1][w+1].rgbtGreen*-1 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*0;
				avgBluey =imgCopy[h-1][w].rgbtBlue*-2 + imgCopy[h-1][w+1].rgbtBlue*-1 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*0;


			}

			//if the pixel is on top Right
			else if (h == 0 && w == (width - 1))
			{
				avgRedx = imgCopy[h][w-1].rgbtRed*-2 + imgCopy[h][w].rgbtRed*0 + imgCopy[h+1][w-1].rgbtRed*-1 + imgCopy[h+1][w].rgbtRed*0;
				avgGreenx = imgCopy[h][w-1].rgbtGreen*-2 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h+1][w-1].rgbtGreen*-1 + imgCopy[h+1][w].rgbtGreen*0;
				avgBluex = imgCopy[h][w-1].rgbtBlue*-2 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h+1][w-1].rgbtBlue*-1 + imgCopy[h+1][w].rgbtBlue*0;

				avgRedy = imgCopy[h][w-1].rgbtRed*0 + imgCopy[h][w].rgbtRed*0 + imgCopy[h+1][w-1].rgbtRed*1 + imgCopy[h+1][w].rgbtRed*2;
				avgGreeny = imgCopy[h][w-1].rgbtGreen*0 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h+1][w-1].rgbtGreen*1 + imgCopy[h+1][w].rgbtGreen*2;
				avgBluey = imgCopy[h][w-1].rgbtBlue*0 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h+1][w-1].rgbtBlue*1 + imgCopy[h+1][w].rgbtBlue*2;


			}

			//if the pixel is on lower right
			else if(h == (height - 1) && w == (width - 1))
			{
				avgRedx = imgCopy[h-1][w-1].rgbtRed*-1 + imgCopy[h-1][w].rgbtRed*0 + imgCopy[h][w-1].rgbtRed*-2 + imgCopy[h][w].rgbtRed*0;
		 		avgBluex = imgCopy[h-1][w-1].rgbtBlue*-1 + imgCopy[h-1][w].rgbtBlue*0 + imgCopy[h][w-1].rgbtBlue*-2 + imgCopy[h][w].rgbtBlue*0;
				avgGreenx = imgCopy[h-1][w-1].rgbtGreen*-1 + imgCopy[h-1][w].rgbtGreen*0 + imgCopy[h][w-1].rgbtGreen*-2 + imgCopy[h][w].rgbtGreen*0;

				avgRedy = imgCopy[h-1][w-1].rgbtRed*-1 + imgCopy[h-1][w].rgbtRed*-2 + imgCopy[h][w-1].rgbtRed*0 + imgCopy[h][w].rgbtRed*0;
		 		avgBluey = imgCopy[h-1][w-1].rgbtBlue*-1 + imgCopy[h-1][w].rgbtBlue*-2 + imgCopy[h][w-1].rgbtBlue*0 + imgCopy[h][w].rgbtBlue*0;
				avgGreeny = imgCopy[h-1][w-1].rgbtGreen*-1 + imgCopy[h-1][w].rgbtGreen*-2 + imgCopy[h][w-1].rgbtGreen*0 + imgCopy[h][w].rgbtGreen*0;


			}

       //if the pixel is on left side

			else if (w == 0 && (h > 0 && h < height - 1))
			{
				avgRedx = imgCopy[h-1][w].rgbtRed*0 + imgCopy[h-1][w+1].rgbtRed*1 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*2 + imgCopy[h+1][w].rgbtRed*0 + imgCopy[h+1][w+1].rgbtRed*1;
				avgGreenx = imgCopy[h-1][w].rgbtGreen*0 + imgCopy[h-1][w+1].rgbtGreen*1 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*2 + imgCopy[h+1][w].rgbtGreen*0 + imgCopy[h+1][w+1].rgbtGreen*1;
				avgBluex = imgCopy[h-1][w].rgbtBlue*0 + imgCopy[h-1][w+1].rgbtBlue*1 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*2 + imgCopy[h+1][w].rgbtBlue*0 + imgCopy[h+1][w+1].rgbtBlue*1;

				avgRedy = imgCopy[h-1][w].rgbtRed*-2 + imgCopy[h-1][w+1].rgbtRed*-1 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*0  + imgCopy[h+1][w].rgbtRed*2 + imgCopy[h+1][w+1].rgbtRed*1;
				avgGreeny = imgCopy[h-1][w].rgbtGreen*-2 + imgCopy[h-1][w+1].rgbtGreen*-1 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*0  + imgCopy[h+1][w].rgbtGreen*2 + imgCopy[h+1][w+1].rgbtGreen*1;
				avgBluey = imgCopy[h-1][w].rgbtBlue*-2 + imgCopy[h-1][w+1].rgbtBlue*-1 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*0  + imgCopy[h+1][w].rgbtBlue*2 + imgCopy[h+1][w+1].rgbtBlue*1;



			}
      //if the pixel is on right side
			else if (w == (width - 1) && (h > 0 && h < height - 1))
			{
				avgRedx = imgCopy[h-1][w-1].rgbtRed*-1 + imgCopy[h-1][w].rgbtRed*0 + imgCopy[h][w-1].rgbtRed*-2 + imgCopy[h][w].rgbtRed*0 + imgCopy[h+1][w-1].rgbtRed*-1 + imgCopy[h+1][w].rgbtRed*0;
				avgGreenx = imgCopy[h-1][w-1].rgbtGreen*-1 + imgCopy[h-1][w].rgbtGreen*0 + imgCopy[h][w-1].rgbtGreen*-2 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h+1][w-1].rgbtGreen*-1 + imgCopy[h+1][w].rgbtGreen*0;
				avgBluex =imgCopy[h-1][w-1].rgbtBlue*-1 + imgCopy[h-1][w].rgbtBlue*0 + imgCopy[h][w-1].rgbtBlue*-2 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h+1][w-1].rgbtBlue*-1 + imgCopy[h+1][w].rgbtBlue*0;

				avgRedy = imgCopy[h-1][w-1].rgbtRed*-1 + imgCopy[h-1][w].rgbtRed*-2 + imgCopy[h][w-1].rgbtRed*0 + imgCopy[h][w].rgbtRed*0 + imgCopy[h+1][w-1].rgbtRed*1 + imgCopy[h+1][w].rgbtRed*2;
				avgGreeny = imgCopy[h-1][w-1].rgbtGreen*-1 + imgCopy[h-1][w].rgbtGreen*-2 + imgCopy[h][w-1].rgbtGreen*0 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h+1][w-1].rgbtGreen*1 + imgCopy[h+1][w].rgbtGreen*2;
				avgBluey =imgCopy[h-1][w-1].rgbtBlue*-1 + imgCopy[h-1][w].rgbtBlue*-2 + imgCopy[h][w-1].rgbtBlue*0 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h+1][w-1].rgbtBlue*1 + imgCopy[h+1][w].rgbtBlue*2;

			}
       //if the pixel is on upper side
			else if (h == 0 && (w > 0 &&  w < width - 1))
			{
				avgRedx =imgCopy[h][w-1].rgbtRed*-2 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*2 + imgCopy[h+1][w-1].rgbtRed*-1 + imgCopy[h+1][w].rgbtRed*0 + imgCopy[h+1][w+1].rgbtRed*1;
				avgGreenx =imgCopy[h][w-1].rgbtGreen*-2 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*2 + imgCopy[h+1][w-1].rgbtGreen*-1 + imgCopy[h+1][w].rgbtGreen*0 + imgCopy[h+1][w+1].rgbtGreen*1;
				avgBluex =imgCopy[h][w-1].rgbtBlue*-2 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*2 + imgCopy[h+1][w-1].rgbtBlue*-1 + imgCopy[h+1][w].rgbtBlue*0 + imgCopy[h+1][w+1].rgbtBlue*1;

				avgRedy =imgCopy[h][w-1].rgbtRed*0 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*0 + imgCopy[h+1][w-1].rgbtRed*1 + imgCopy[h+1][w].rgbtRed*2 + imgCopy[h+1][w+1].rgbtRed*1;
				avgGreeny =imgCopy[h][w-1].rgbtGreen*0 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*0 + imgCopy[h+1][w-1].rgbtGreen*1 + imgCopy[h+1][w].rgbtGreen*2 + imgCopy[h+1][w+1].rgbtGreen*1;
				avgBluey =imgCopy[h][w-1].rgbtBlue*0 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*0 + imgCopy[h+1][w-1].rgbtBlue*1 + imgCopy[h+1][w].rgbtBlue*2 + imgCopy[h+1][w+1].rgbtBlue*1;


			}
       //if the pixel is on lower side
			else if  (h == height - 1 && (w > 0 && w < width - 1))
			{
				avgRedx = imgCopy[h-1][w-1].rgbtRed*-1 + imgCopy[h-1][w].rgbtRed*0 + imgCopy[h-1][w+1].rgbtRed*1 + imgCopy[h][w-1].rgbtRed*-2 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*2;
				avgGreenx = imgCopy[h-1][w-1].rgbtGreen*-1 + imgCopy[h-1][w].rgbtGreen*0 + imgCopy[h-1][w+1].rgbtGreen*1 + imgCopy[h][w-1].rgbtGreen*-2 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*2;
				avgBluex = imgCopy[h-1][w-1].rgbtBlue*-1 + imgCopy[h-1][w].rgbtBlue*0 + imgCopy[h-1][w+1].rgbtBlue*1 + imgCopy[h][w-1].rgbtBlue*-2 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*2;

				avgRedy = imgCopy[h-1][w-1].rgbtRed*-1 + imgCopy[h-1][w].rgbtRed*-2 + imgCopy[h-1][w+1].rgbtRed*-1 + imgCopy[h][w-1].rgbtRed*0 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*0;
				avgGreeny = imgCopy[h-1][w-1].rgbtGreen*-1 + imgCopy[h-1][w].rgbtGreen*-2 + imgCopy[h-1][w+1].rgbtGreen*-1 + imgCopy[h][w-1].rgbtGreen*0 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*0;
				avgBluey = imgCopy[h-1][w-1].rgbtBlue*-1 + imgCopy[h-1][w].rgbtBlue*-2 + imgCopy[h-1][w+1].rgbtBlue*-1 + imgCopy[h][w-1].rgbtBlue*0 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*0;


			}
      //if the pixel is on the middle and can form a 3x3 grid
			else
			{
				avgRedx = imgCopy[h-1][w-1].rgbtRed*-1 + imgCopy[h-1][w].rgbtRed*0 + imgCopy[h-1][w+1].rgbtRed*1 + imgCopy[h][w-1].rgbtRed*-2 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*2 + imgCopy[h+1][w-1].rgbtRed*-1 + imgCopy[h+1][w].rgbtRed*0 + imgCopy[h+1][w+1].rgbtRed*1;
				avgGreenx =imgCopy[h-1][w-1].rgbtGreen*-1 + imgCopy[h-1][w].rgbtGreen*0 + imgCopy[h-1][w+1].rgbtGreen*1 + imgCopy[h][w-1].rgbtGreen*-2 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*2 + imgCopy[h+1][w-1].rgbtGreen*-1 + imgCopy[h+1][w].rgbtGreen*0 + imgCopy[h+1][w+1].rgbtGreen*1;
				avgBluex = imgCopy[h-1][w-1].rgbtBlue*-1 + imgCopy[h-1][w].rgbtBlue*0 + imgCopy[h-1][w+1].rgbtBlue*1 + imgCopy[h][w-1].rgbtBlue*-2 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*2 + imgCopy[h+1][w-1].rgbtBlue*-1 + imgCopy[h+1][w].rgbtBlue*0 + imgCopy[h+1][w+1].rgbtBlue*1;

				avgRedy = imgCopy[h-1][w-1].rgbtRed*-1 + imgCopy[h-1][w].rgbtRed*-2 + imgCopy[h-1][w+1].rgbtRed*-1 + imgCopy[h][w-1].rgbtRed*0 + imgCopy[h][w].rgbtRed*0 + imgCopy[h][w+1].rgbtRed*0 + imgCopy[h+1][w-1].rgbtRed*1 + imgCopy[h+1][w].rgbtRed*2 + imgCopy[h+1][w+1].rgbtRed*1;
				avgGreeny =imgCopy[h-1][w-1].rgbtGreen*-1 + imgCopy[h-1][w].rgbtGreen*-2 + imgCopy[h-1][w+1].rgbtGreen*-1 + imgCopy[h][w-1].rgbtGreen*0 + imgCopy[h][w].rgbtGreen*0 + imgCopy[h][w+1].rgbtGreen*0 + imgCopy[h+1][w-1].rgbtGreen*1 + imgCopy[h+1][w].rgbtGreen*2 + imgCopy[h+1][w+1].rgbtGreen*1;
				avgBluey = imgCopy[h-1][w-1].rgbtBlue*-1 + imgCopy[h-1][w].rgbtBlue*-2 + imgCopy[h-1][w+1].rgbtBlue*-1 + imgCopy[h][w-1].rgbtBlue*0 + imgCopy[h][w].rgbtBlue*0 + imgCopy[h][w+1].rgbtBlue*0 + imgCopy[h+1][w-1].rgbtBlue*1 + imgCopy[h+1][w].rgbtBlue*2 + imgCopy[h+1][w+1].rgbtBlue*1;
			}

			double gxred=avgRedx;
			double gxblue=avgBluex;
			double gxgreen=avgGreenx;
			double gyred=avgRedy;
			double gyblue=avgBluey;
			double gygreen=avgGreeny;

			int red=0;
			int green=0;
			int blue=0;
			double x=2.0;
			if(round(sqrt(pow(gxred,x)+pow(gyred,x)))>255)
			{
				 red=255;
			}
			else
			{
		    	 red=round(sqrt(pow(gxred,x)+pow(gyred,x)));
			}

			if(round(sqrt(pow(gxblue,x)+pow(gyblue,x)))>255)
			{
				 blue=255;
			}
			else
			{
		    	 blue=round(sqrt(pow(gxblue,x)+pow(gyblue,x)));
			}

			if(round(sqrt(pow(gxgreen,x)+pow(gygreen,x)))>255)
			{
				 green=255;
			}
			else
			{
		    	 green=round(sqrt(pow(gxgreen,x)+pow(gygreen,x)));
			}

			image[h][w].rgbtRed=red;
			image[h][w].rgbtBlue=blue;
			image[h][w].rgbtGreen=green;


		}

	}

    return;
}
