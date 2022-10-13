/*
Projet: FlyOverBoxes
Author: MathiAs2Pique_
Creation date: 10/10/22
Last modification: 10/10/22
Role: Command
*/
#include "commandParsing.h"

// Get next word from user command
int getNextWord (char* userCommand, char* word)
{
    int index1;
    int index2;
    // We remove the white space before the word.
    index1 = 0;
    while (userCommand[index1] == ' '){
        index1++;
    }
    index2 = 0;
    while (userCommand[index1] != '\0'){
        if (userCommand[index1] == ' '){
            break;
        }
        else{
            word[index2] = userCommand[index1];
        }
        index1++;
        index2++;
    }
    word[index2] = '\0';
    return index1;
}

// Replace new line by end line
void replaceNewLineByEndLine (char* userCommand){
    int i;
    // Replace \n by \0.
    for (i = 0; i < strlen (userCommand); i++){
        if (userCommand[i] == '\n'){
            userCommand[i] = '\0';
        }
    }
}

// Parse user command
void parseUserCommand (char* userCommand, struct s_options* options){
    char word[MAX_STRING_SIZE];
    int nextWordPosition;
    int length;
    int value;
    // We parse the first word.
    replaceNewLineByEndLine (userCommand);
    length = getNextWord (userCommand, word);
    userCommand += length;
    // Case of an option.
    if (strcasecmp (word, "set") == 0){
        // we parse the option name.
        length = getNextWord (userCommand, word);
        userCommand += length;
        // Case of the difficulty option.
        if (strcasecmp (word, "difficulty") == 0){
            // We parse the option value.
            getNextWord (userCommand, word);
            value = atoi (word);
            if (value >=1 && value <= 3){
                options->difficulty = value;
            }
        }
        if(strcasecmp(word, "planetype") == 0){
            // We parse the option value.
            getNextWord (userCommand, word);
            value = atoi (word);
            if (value == 1 || value == 2){
                options->planeType = value;
            }
        }
        // Case of the powerup option.
        if (strcasecmp (word, "powerup") == 0){
            // We parse the option value.
            getNextWord (userCommand, word);
            if (strcasecmp (word, "yes") == 0)
            options->powerup = 1;
            if (strcasecmp (word, "no") == 0)
            options->powerup = 0;
        }
        if(strcasecmp(word, "colors") == 0){
            // We parse the option value.
            getNextWord (userCommand, word);
            if(strcasecmp(word, "yes") == 0){
                options->colors = 1;
            }
            else{
                options->colors = 0;
            }
        }

        // Case of the name option.
        if (strcasecmp (word, "name") == 0){
            // We parse the option value.
            getNextWord (userCommand, word);
            strcpy (options->name, word);
        }
    }
    // Case of run.
    if (strcasecmp (word, "run") == 0){
        options->run = 1;
    }
    
    if(strcasecmp(word, "quit") == 0){
        options->quit = 1;
    }
    
    // Case of help.
    if (strcasecmp (word, "help") == 0){
        options->help = !options->help;
    }
}