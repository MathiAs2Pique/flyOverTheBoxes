/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: image
*/
#include "image.h"

// Get the mirror of the character
char mirrorChar(char c){
    char mirror;
    if(c == '('){
        mirror = ')';
    }
    else if(c == ')'){
        mirror = '(';
    }
    else if(c == '['){
        mirror = ']';
    }
    else if(c == ']'){
        mirror = '[';
    }
    else if(c == '{'){
        mirror = '}';
    }
    else if(c == '}'){
        mirror = '{';
    }
    else if(c == '<'){
        mirror = '>';
    }
    else if(c == '>'){
        mirror = '<';
    }
    else if(c == '/'){
        mirror = '\\';
    }
    else if(c == '\\'){
        mirror = '/';
    }
    else if(c == ' '){
        mirror = ' ';
    }
    else{
        mirror = c;
    }

    return mirror;
}

// Flip the image
void flipImage(struct s_image *image){
    // 2H POUR CETTE FONCTION
    int i, j;
    char temp;

    // Create a temporary image (Malloc the 1st dimmension)
    char **temp_data = malloc(image->height * sizeof(char*));

    // For each line
    for(i = 0; i < image->height; i++){
        // Malloc the temp data (2nd dimmension)
        temp_data[i] = malloc(image->width * sizeof(char));
        // For each character
        for(j = 0; j < image->width; j++){
            // Get the character
            temp = image->data[i][j];
            // Then store the mirror in the other side, in the temp data.
            temp_data[i][image->width - j -1] = mirrorChar(temp);
        }
    }

    // Copy the temp data to the image data
    for(i = 0; i < image->height; i++){
        for(j = 0; j < image->width; j++){
            image->data[i][j] = temp_data[i][j];
        }
        // Free the temp data (2nd dimmension)
        free(temp_data[i]);
    }
    // Free the temp data (1st dimmension)
    free(temp_data);
}

// Draw image
void drawXYImage(struct s_image image, int x, int y, int empty){
    int i, j;

    // For each line
    for(i = 0; i < image.height; i++){
        // For each char 
        for(j = 0; j < image.width; j++){
            // If empty, set it to blank.
            if(empty){
                drawXYText(" ", x + j, y + i);
            }
            else{
                // if not empty, draw the char.
                drawXYText(&image.data[i][j], x + j, y + i);
            }
        }
    }
}

struct s_image readImage (char* filename)
{

    // Fonction copiée collée du test semaine6/7 :)
    FILE* file;
    struct s_image image;
    int x;
    int y;

    // We open the file.
    file = fopen (filename, "r");
    if (file == NULL)
    {
        printf ("Impossible d'ouvrir le fichier : %s\n", filename);
        exit (EXIT_FAILURE);
    }

    // We read the flie.
    fscanf (file, "%d %d\n", &image.width, &image.height);
    image.data = (char**)malloc (image.height*sizeof (char*));
    for (y = 0; y < image.height; y++)
    {
        image.data[y] = (char*)malloc (image.width*sizeof (char));
        for (x = 0; x < image.width; x++)
        {
            fscanf (file, "%c", &image.data[y][x]);
            if (image.data[y][x] == '@')
                image.data[y][x] = ' ';
        }
        fscanf (file, "\n");
    }

    // We close the file.
    fclose (file);

    return image;
}

void deleteImage(struct s_image* image){
    // Free the image data.
    // Free 2nd dimmensions
    int i;
    for (i=0; image->height < i; i++){
        free(image->data[i]);
    }
    // Free 1st dimmension
    free(image->data);
}
