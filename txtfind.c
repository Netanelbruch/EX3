#include <stdio.h>
#include <string.h>


#define LINE 256
#define WORD 30 


 

// the function return number of char not includ '\n'!!!
int getLine(char s[]){

    int count = 0;
    

    for (int i = 0; i < LINE; i++)
    {
        scanf("%c" , &(*(s+i)));
        count = i;
        if (*(s+i) == '\n' || *(s+i) == '\0' )
        {
            break;
        }
    }
    
    return count;

}

int getword(char w[])
{
	int count = 0;
	
	for (int i = 0; i < WORD; i++)
	{
		if (*(w+i) == '\n' || *(w + i) == '\t' || *(w + i) == ' ' || *(w + i) == '\0')
			break;

		count++;
	}

	return count;
}


int substring( char * str1, char * str2){
    if (strlen(str1) > strlen(str2)){
        if(strstr(str1, str2) != NULL){
            return 1;
        }
        
    }
    else
    {
        return 0;
    }
    

}

int similar (char *s, char *t, int n){
    int one = strlen(s);
    int tow = strlen(t);
    int sizOfRm = n;


//  comper lengthe.
    if (one == tow)
   {    
        //comper if the s = t.
        if (strcmp(s,t) == 0){
            return 1;
        }
        else 
        {
            return 0;
        }
   }

//  if length(s) - lengthe(t) != n return fals
    if(one-tow != sizOfRm){
        return 0;
    }


    char new[strlen(t)];
    int index = 0;
    for (int i = 0; i < one; i++)
    {

        if (t[index] == s[i])
        {
            new[index] = s[i];
            index ++;
            
        }
        
    }

    if (strcmp(new,t)==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    

}

void print_lines(char* str)
{
	char line[LINE] = {0};

	while (getLine(line) != 0)
	{
		if (substring(line, str) != 0)
			printf("%s\n", line);
	}
}

// Prints all the words that are similar to the word
void print_similar_words(char* str)
{
	char word[WORD] = {0};

	while (getword(word) != 0)
	{
		if (similar(word, str, 1) || similar(word, str, 0))
		{
			printf("%s\n", word);
		}
	}

}




int main()
{
	char word[WORD];
	char choose;

	getword(word);
	scanf(" %c\n", &choose);

	if (choose == 'a')
	{
		print_lines(word);
	}

	else if (choose == 'b')
	{
		print_similar_words(word);
	}

	return 0;
}


