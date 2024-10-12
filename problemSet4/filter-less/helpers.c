#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average =
                (float) (image[i][j].rgbtGreen + image[i][j].rgbtBlue + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtGreen = round(average);
            image[i][j].rgbtBlue = round(average);
            image[i][j].rgbtRed = round(average);
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
            float sepiaRed = round((image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) +
                                   (image[i][j].rgbtBlue * 0.189));
            float sepiaGreen =
                round((image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) +
                      (image[i][j].rgbtBlue * 0.168));
            float sepiaBlue =
                round((image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) +
                      (image[i][j].rgbtBlue * 0.131));

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        float w = width / 2;

        for (int j = 0; j < w; j++)
        {
            RGBTRIPLE temp[height][width];
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp[i][j];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j].rgbtBlue = image[i][j].rgbtBlue;
            copy[i][j].rgbtRed = image[i][j].rgbtRed;
            copy[i][j].rgbtGreen = image[i][j].rgbtGreen;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            int redAvg, blueAvg, greenAvg;
            redAvg = greenAvg = blueAvg = 0;

            for (int r = (i - 1); r <= (i + 1); r++)
            {
                for (int x = (j - 1); x <= (j + 1); x++)
                {
                    if ((r >= 0 && r <= (height - 1)) && (x >= 0 && x <= (width - 1)))
                    {
                        redAvg += copy[r][x].rgbtRed;
                        blueAvg += copy[r][x].rgbtBlue;
                        greenAvg += copy[r][x].rgbtGreen;
                        count++;
                    }
                }
            }
            image[i][j].rgbtBlue = (int) round((double) blueAvg / (double) count);
            image[i][j].rgbtGreen = (int) round((double) greenAvg / (double) count);
            image[i][j].rgbtRed = (int) round((double) redAvg / (double) count);
        }
    }
    return;
}
