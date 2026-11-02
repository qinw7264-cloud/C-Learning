#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int average = round((r + g + b) / 3.0);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int newRed = round(0.393 * r + 0.769 * g + 0.189 * b);
            if (newRed > 255)
            {
                newRed = 255;
            }
            int newGreen = round(0.349 * r + 0.686 * g + 0.168 * b);
            if (newGreen > 255)
            {
                newGreen = 255;
            }
            int newBlue = round(0.272 * r + 0.534 * g + 0.131 * b);
            if (newBlue > 255)
            {
                newBlue = 255;
            }
            image[i][j].rgbtRed = newRed;
            image[i][j].rgbtGreen = newGreen;
            image[i][j].rgbtBlue = newBlue;

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
    RGBTRIPLE blurred[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int count = 0;
            for (int row = i - 1; row <= i + 1; row++)
            {
                for (int col = j - 1; col <= j + 1; col++)
                {
        
                    
                    if (row >= 0 && row < height && col >= 0 && col < width)
                    {  
                        sumRed += image[row][col].rgbtRed;
                        sumGreen += image[row][col].rgbtGreen;
                        sumBlue += image[row][col].rgbtBlue;
                        count ++;
                    }
        
        
                }
            }
            int averageRed = round((double) sumRed / count);
            int averageGreen = round((double) sumGreen / count);
            int averageBlue = round((double) sumBlue / count);
            blurred[i][j].rgbtRed = averageRed;
            blurred[i][j].rgbtGreen = averageGreen;
            blurred[i][j].rgbtBlue = averageBlue;

        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurred[i][j];
        }
    }
    return;
}
