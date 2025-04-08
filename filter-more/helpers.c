#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0);
       
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
        }

    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++) 
        {
            // Swap left and right pixels
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumBlue = 0;
            int sumGreen = 0;
            int count = 0;
            int ni;
            int nj;

            //loops over all the neighboring pixels of pixel (i, j)
            for (int di = -1; di < 2; di++)
            {
                for (int dj = -1; dj < 2; dj++)
                {
                    ni = i + di;
                    nj = j + dj;

                    if( ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        sumRed += image[ni][nj].rgbtRed;
                        sumGreen += image[ni][nj].rgbtGreen;
                        sumBlue += image[ni][nj].rgbtBlue;
                        count ++;

                    }
                }
            }
            temp[i][j].rgbtRed = sumRed/count;
            temp[i][j].rgbtGreen = sumGreen/count;
            temp[i][j].rgbtBlue = sumBlue/count;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {   
            image[i][j] = temp[i][j];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    
    RGBTRIPLE temp[height][width];

    
    int Gx[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    int Gy[3][3] = {
        {-1, -2, -1},
        { 0,  0,  0},
        { 1,  2,  1}
    };

    // Iterate over each pixel
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Initialize Gx and Gy sums for each color channel
            int sumRedX = 0, sumRedY = 0;
            int sumGreenX = 0, sumGreenY = 0;
            int sumBlueX = 0, sumBlueY = 0;

            
            for (int di = -1; di <= 1; di++)
            {
                for (int dj = -1; dj <= 1; dj++)
                {
                    int ni = i + di;
                    int nj = j + dj;

                    // Check if the neighboring pixel is within bounds
                    if (ni >= 0 && ni < height && nj >= 0 && nj < width)
                    {
                        RGBTRIPLE pixel = image[ni][nj];

                        
                        sumRedX   += pixel.rgbtRed   * Gx[di + 1][dj + 1];
                        sumRedY   += pixel.rgbtRed   * Gy[di + 1][dj + 1];

                        sumGreenX += pixel.rgbtGreen * Gx[di + 1][dj + 1];
                        sumGreenY += pixel.rgbtGreen * Gy[di + 1][dj + 1];

                        sumBlueX  += pixel.rgbtBlue  * Gx[di + 1][dj + 1];
                        sumBlueY  += pixel.rgbtBlue  * Gy[di + 1][dj + 1];
                    }
                }
            }

            // Compute final gradient magnitude for each channel
            int finalRed   = round(sqrt(sumRedX * sumRedX + sumRedY * sumRedY));
            int finalGreen = round(sqrt(sumGreenX * sumGreenX + sumGreenY * sumGreenY));
            int finalBlue  = round(sqrt(sumBlueX * sumBlueX + sumBlueY * sumBlueY));

            // Cap values at 255
            temp[i][j].rgbtRed   = (finalRed > 255) ? 255 : finalRed;
            temp[i][j].rgbtGreen = (finalGreen > 255) ? 255 : finalGreen;
            temp[i][j].rgbtBlue  = (finalBlue > 255) ? 255 : finalBlue;
        }
    }

        // Copy results back to the original image
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                image[i][j] = temp[i][j];
            }
        }

    return;
}
