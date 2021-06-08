#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;
            
            int red = round(0.393 * r + 0.769 * g + 0.189 * b);
            int green = round(0.349 * r + 0.686 * g + 0.168 * b);
            int blue = round(0.272 * r + 0.534 * g + 0.131 * b);
        
            if (red > 255){
                image[i][j].rgbtRed = 255;}
            else if (red < 0){
                image[i][j].rgbtRed = 0;}
            else{image[i][j].rgbtRed = red;}
            
            if (green > 255){
                image[i][j].rgbtGreen = 255;}
            else if (red < 0){
                image[i][j].rgbtGreen = 0;}
            else{image[i][j].rgbtGreen = green;}
        
            if (blue > 255){
                image[i][j].rgbtBlue = 255;}
            else if (red < 0){
                image[i][j].rgbtBlue = 0;}
            else{image[i][j].rgbtBlue = blue;}
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2; j++){
            RGBTRIPLE buffer = image[i][j];
            image[i][j] = image[i][width-1-j];
            image[i][width-1-j]=buffer;
        }
     }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width / 2; j++){
            
            RGBTRIPLE nullChecker[9] = {image[i-1][j-1],image[i-1][j],image[i-1][j+1],image[i][j-1],image[i][j],image[i][j+1],image[i+1][j-1],image[i+1][j],image[i+1][j+1]};
            float counter = 0;
            for(int k=0; k<9; k++){
                if((k = 0))
                {
                    continue;
                }
                else{counter++;}
            }
            
            int averageBlue = round((image[i-1][j-1].rgbtBlue + image[i-1][j].rgbtBlue + image[i-1][j+1].rgbtBlue + image[i][j-1].rgbtBlue + image[i][j].rgbtBlue + image[i][j+1].rgbtBlue + image[i+1][j-1].rgbtBlue + image[i+1][j].rgbtBlue + image[i+1][j+1].rgbtBlue) / counter);
            int averageGreen = round((image[i-1][j-1].rgbtGreen + image[i-1][j].rgbtGreen + image[i-1][j+1].rgbtGreen + image[i][j-1].rgbtGreen + image[i][j].rgbtGreen  + image[i][j+1].rgbtGreen  + image[i+1][j-1].rgbtGreen  + image[i+1][j].rgbtGreen  + image[i+1][j+1].rgbtGreen ) / counter);
            int averageRed = round((image[i-1][j-1].rgbtRed + image[i-1][j].rgbtRed + image[i-1][j+1].rgbtRed + image[i][j-1].rgbtRed + image[i][j].rgbtRed  + image[i][j+1].rgbtRed  + image[i+1][j-1].rgbtRed  + image[i+1][j].rgbtRed  + image[i+1][j+1].rgbtRed ) / counter);
            
            image[i][j].rgbtBlue = averageBlue;
            image[i][j].rgbtGreen = averageGreen;
            image[i][j].rgbtRed = averageRed;
        }
    }
    return;
}
