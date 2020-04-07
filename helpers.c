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
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copyarr[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copyarr[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumboxrgbtRed = 0, sumboxrgbtGreen = 0, sumboxrgbtBlue = 0;
            int sumcount = 0;
            int negrow = (i == 0) ? (0) : (i - 1);
            int posrow = (i == height - 1) ? (height - 1) : (i + 1);
            int negcol = (j == 0) ? (0) : (j - 1);
            int poscol = (j == width - 1) ? (width - 1) : (j + 1);
            for (int p = negrow; p <= posrow; p++)
            {
                for (int q = negcol; q <= poscol; q++)
                {
                    sumboxrgbtRed += copyarr[p][q].rgbtRed;
                    sumboxrgbtGreen += copyarr[p][q].rgbtGreen;
                    sumboxrgbtBlue += copyarr[p][q].rgbtBlue;
                    sumcount++;
                }
            }
            float redavg = roundf(sumboxrgbtRed / (float)sumcount);
            float greenavg = roundf(sumboxrgbtGreen / (float)sumcount);
            float blueavg = roundf(sumboxrgbtBlue / (float)sumcount);
            image[i][j].rgbtRed = redavg;
            image[i][j].rgbtGreen = greenavg;
            image[i][j].rgbtBlue = blueavg;
        }
    }
    return;
}
