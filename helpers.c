#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0;
            average = roundf(average);
            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = average;
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
            float newred = roundf((.393 * image[i][j].rgbtRed) + (.769 * image[i][j].rgbtGreen) + (.189 * image[i][j].rgbtBlue));
            float newgreen = roundf((.349 * image[i][j].rgbtRed) + (.686 * image[i][j].rgbtGreen) + (.168 * image[i][j].rgbtBlue));
            float newblue = roundf((.272 * image[i][j].rgbtRed) + (.534 * image[i][j].rgbtGreen) + (.131 * image[i][j].rgbtBlue));
            if (newred > 255)
            {
                newred = 255;
            }
            if (newgreen > 255)
            {
                newgreen = 255;
            }
            if (newblue > 255)
            {
                newblue = 255;
            }

            image[i][j].rgbtRed = newred;
            image[i][j].rgbtGreen = newgreen;
            image[i][j].rgbtBlue = newblue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width/2; j++)
        {
            image[i][j] = image[i][width - j - 1];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
