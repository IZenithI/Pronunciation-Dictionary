/*
Brian Guo
March 25, 2018

Pronounciation Dictionary App.
*/

#include <fstream>
#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////
void splitOnSpace(string Word, string & before, string & after) //Splits "Word" after first space, i.e. AAAA BB CCC = AAAA; BB CCC
{
	before = ""; //Word
	after = ""; //Pronounciation
		
	int i = 0; //Begin at first letter of word, similar to arrays order i.e. [0,1,2...]
	while (i < Word.size() && not isspace(Word[i])) //While i < Word length and is not a space
	{
		before += Word[i]; //Add number or letter to "before" variable
			i++; //Move to next letter or number, continue while loop
	}
	i++; //Skip the space, move onto Pronounciation
	while (i < Word.size()) //while i < Word length
	{
		after += Word[i]; //Add each letter,number to "after" variable
		i++; //Move to next letter,number
	}
}

void splitpro1Space(string pronounce, string & P1, string & P2, string & P3, string & P4, string & P5, string & P6, string & P7) //Splits pronunciation into individual phonemes
{
    int i = 1; //Skip first space
    while(i < pronounce.size() && not isspace(pronounce[i])) //While i is less than length of pronounce, and is not a space
    {
        P1 += pronounce[i]; //Add individual string to P1
        i++; //Move to next string character
    }
    i++; //Skip space when space is encountered (when exit while loop)
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        P2 += pronounce[i];
        i++;
    }
    i++;
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        P3 += pronounce[i];
        i++;
    }
    i++;
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        P4 += pronounce[i];
        i++;
    }
    i++;
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        P5 += pronounce[i];
        i++;
    }
	i++;
	while(i < pronounce.size() && not isspace(pronounce[i]))
	{
		P6 += pronounce[i];
		i++;
	}
	i++;
	while(i < pronounce.size() && not isspace(pronounce[i]))
	{
		P7 += pronounce[i];
		i++;
	}
}

void splitpro2Space(string pronounce, string & Pho1, string & Pho2, string & Pho3, string & Pho4, string & Pho5, string & Pho6, string & Pho7) //Splits pronunciation2 into individual phonemes (description same as splitpro1Space)
{
    int i = 1;
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        Pho1 += pronounce[i];
        i++;
    }
    i++;
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        Pho2 += pronounce[i];
        i++;
    }
    i++;
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        Pho3 += pronounce[i];
        i++;
    }
    i++;
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        Pho4 += pronounce[i];
        i++;
    }
    i++;
    while(i < pronounce.size() && not isspace(pronounce[i]))
    {
        Pho5 += pronounce[i];
        i++;
    }
	i++;
	while(i < pronounce.size() && not isspace(pronounce[i]))
	{
		Pho6 += pronounce[i];
		i++;
	}
	i++;
	while(i < pronounce.size() && not isspace(pronounce[i]))
	{
		Pho7 += pronounce[i];
		i++;
	}
}

int countphonemes(string pronounce, int count) //Count amount of phonemes within a pronunciation
{
	count = 0;	//Set counter equal to 0
	int i = 0;
	while (i < pronounce.size()) //While less than length of pronounce
	{
		if(isspace(pronounce[i]))	//If space is encountered
		{
			count++;	//Increment counter by 1
		}
		i++;	//Move to next string character
	}
	return count;	//Return value of counter
}

bool ignorespecial(string Word)	//Looks for special characters in Word
{
	bool nospecial = true;
	for(int i = 0; i < Word.length(); i++)	//As long as i is less than Word length
	{
		if((int(Word[i]) == 46) || (int(Word[i] == 40)) || (int(Word[i]) == 41) || (int(Word[i]) == 42) || (int(Word[i] == 45)))	//If characters in Word are either, '.', '(', ')', '*', '-'
		{
			nospecial = false;	//Set nospecial to false
		}
		else	//If characters in Word is any other character
		{
			nospecial = true;	//Set nospecial to true
		}
	}
	return nospecial;	//Return nospecial bool value
}

bool searchphoneme(string pronounce, string phoneme) //Search for phoneme in a pronunciation
{
	int i, j;
	bool found = false;	//Declare bool as false
	for(i = 0; i < pronounce.length() && !found; i++)	//As long as i is less than length of pronounce and found is false
	{
		for(j = 0; j < phoneme.length(); j++)	//As long as j is less than length of phoneme
		{
			if(pronounce[i+j] != phoneme[j])	//If phoneme does not match, break and restart
			{
				break;
			}
		}
		if(j == phoneme.length())	//If phoneme found matches the entire phoneme by individual character
		{
			found = true;	//Declare found as true
		}
	}
	return found;	//Return found true/false
}

bool addphocompare(string pronounce1, string pronounce2) //Compare each phoneme for 'add' matches
{
	string P1, P2, P3, P4, P5, P6, P7, Pho1, Pho2, Pho3, Pho4, Pho5, Pho6, Pho7;	//Declare all phoneme variables
	int strike = 0;	//Declare strike count at 0
	bool found = false;
	splitpro1Space(pronounce1, P1, P2, P3, P4, P5, P6, P7);	//Refer to splitpro1Space function to separate phonemes in that pronunciation into P1, P2, P3, etc.
	splitpro2Space(pronounce2, Pho1, Pho2, Pho3, Pho4, Pho5, Pho6, Pho7);	//Refer to function to separate phonemes in pronunciation2 into P1, P2, P3, etc.
	int count;
	string pho1array[7] = {P1, P2, P3, P4, P5, P6, P7};
	string pho2array[7] = {Pho1, Pho2, Pho3, Pho4, Pho5, Pho6, Pho7};
	int i = 0;
	while (i < countphonemes(pronounce2, count))
	{
		if(pho1array[i] != pho2array[i])
		{
			strike++;
			break;
		}
		i++;
	}
	while (i < countphonemes(pronounce1, count))
	{
		if(pho1array[i] != pho2array[i+1])
		{
			strike++;
		}
		i++;
	}
	if(strike == 1)	//If strike equals exactly 1
	{
		found = true;	//Set found to true
	}
	if(strike != 1)	//If strike does not equal 1
	{
		found = false;	//Set found to false
	}
	return found;	//Return true/false value of found
}

bool removephocompare(string pronounce1, string pronounce2)	//Compare each phoneme for 'remove' matches
{
	string P1, P2, P3, P4, P5, P6, P7, Pho1, Pho2, Pho3, Pho4, Pho5, Pho6, Pho7;	//Declare all phoneme variables
	int strike = 0;	//Declare strike count at 0
	bool found = false;
	splitpro1Space(pronounce1, P1, P2, P3, P4, P5, P6, P7);	//Refer to splitpro1Space function to separate phonemes in that pronunciation into P1, P2, P3, etc.
	splitpro2Space(pronounce2, Pho1, Pho2, Pho3, Pho4, Pho5, Pho6, Pho7);	//Refer to function to separate phonemes in pronunciation2 into P1, P2, P3, etc.
	int count;
	string pho1array[7] = {P1, P2, P3, P4, P5, P6, P7};	//Create arrays for phonemes1
	string pho2array[7] = {Pho1, Pho2, Pho3, Pho4, Pho5, Pho6, Pho7};	//Create arrays for phonemes2
	int i = 0;
	while (i < countphonemes(pronounce1, count))	//While i is less than number of phonemes
	{
		if(pho1array[i] != pho2array[i])	//If phoneme1 array value of i is not equal to phoneme2 array value of i
		{
			strike++;	//Increase strike value by 1
			break; 	//Break out of while loop if not equal
		}
		i++;
	}
	while (i < countphonemes(pronounce1, count))
	{
		if(pho1array[i+1] != pho2array[i])	//Skipping the value that did not match, compare again
		{
			strike++;
		}
		i++;
	}
	if(strike == 1)
	{
		found = true;
	}
	if(strike != 1)
	{
		found = false;
	}
	return found;
}

bool replacephocompare(string pronounce1, string pronounce2) //Compare each phoneme for 'replace' matches
{
	string P1, P2, P3, P4, P5, P6, P7, Pho1, Pho2, Pho3, Pho4, Pho5, Pho6, Pho7;	//Declare all phoneme variables
	int strike = 0;	//Declare strike count at 0
	bool found = false;
	splitpro1Space(pronounce1, P1, P2, P3, P4, P5, P6, P7);	//Refer to splitpro1Space function to separate phonemes in that pronunciation into P1, P2, P3, etc.
	splitpro2Space(pronounce2, Pho1, Pho2, Pho3, Pho4, Pho5, Pho6, Pho7);	//Refer to function to separate phonemes in pronunciation2 into P1, P2, P3, etc.
	
	if(P1 != Pho1)	//If first phoneme of pronunciation1 does not match first phoneme of pronunciation2
	{
		strike++;	//Increment strike count by 1
	}
	if(P2 != Pho2)	//If second phoneme of pronunciation1 does not match second phoneme of pronunciation2
	{
		strike++;	//Increment
	}
	if(P3 != Pho3)	//Etc
	{
		strike++;
	}
	if(P4 != Pho4)
	{
		strike++;
	}
	if(P5 != Pho5)
	{
		strike++;
	}
	if(P6 != Pho6)
	{
		strike++;
	}
	if(strike == 1)	//If strike equals exactly 1
	{
		found = true;	//Set found to true
	}
	if(strike != 1)	//If strike does not equal 1
	{
		found = false;	//Set found to false
	}
	return found;	//Return found bool
}

bool replacecompare(string Pro1, string Pro2)	//Compare each individual character for matches
{
    int strike = 0;
    bool found = false;
    for(int i = 0; i < Pro1.length(); i++)	//As long as i is less than pronounce length
    {
        if(Pro1[i] != Pro2[i])	//For every character that does not match
        {
            strike++;	//Increase strike count by 1
        }
    }
    if(strike == 1)	//If exactly 1
    {
        found = true;	//Set as true
    }
	if(strike != 1)	//If not 1
	{
		found = false;	//Set as false
	}
    return found;	//Return found bool
}
//////////////////////////////PRINT//////////////////////////////////////

void printpronunciation(string W)	//Function to print pronunciation
{
	string line; 			//Variable for each line in the file
	string Word; 			//Variable for word before first space in line
	string Pronunciation;	//Variable for pronunciation after first space of the line
	
	ifstream istr;			//Declare stream variable
	bool found = false; 
	istr.open("PronunciationDictionary.txt");	//Open Dictionary File
	
	
	while (!found && !(istr.eof())) //If word not found and not at end of file
	{
		getline(istr, line); //Reads each line of the file
		splitOnSpace(line, Word, Pronunciation); //Refers to funtion, separates the line
		if (Word == W) //If inputted word matches the word before the first space
		{
			cout << "Pronunciation\t:";
			cout << Pronunciation << endl; //Print pronunciation as given in dictionary
			found = true; //Indicate word found;
			cout << " \n";
		}
	}
	if (found == false)
	{
		cout << endl;
		cout << "Not found" << endl;
	}
}

void printidentical(string W)	//Function to print identical words
{
	string line; 			//Variable for each line in the file
	string Word; 			//Variable for word before first space in line
	string Word2;			//Second Word variable
	string Pronunciation;	//Variable for pronunciation after first space of the line
	string Pronunciation2; //Second Pronunciation variable
	
	ifstream istr;			//Declare stream variable
	
	istr.open("PronunciationDictionary.txt");	//Open Dictionary File
	
	while (!(istr.eof())) //If word not found and not at end of file
	{
		getline(istr, line); //Reads each line of the file
		splitOnSpace(line, Word, Pronunciation); //Refers to funtion, separates the line
		if (Word == W) //If inputted word matches the word before the first space
		{
			
			cout << "Identical\t: ";
			istr.seekg(0); //Begin from beginning of file
			while(!(istr.eof()))
			{
				
				getline(istr, line);
				splitOnSpace(line, Word2, Pronunciation2);
				
				if ((Pronunciation == Pronunciation2) && (Word2 != Word)) //If Word2 doesnt match original word and pronunciation equals
				{
						cout << Word2 << " ";
				}
			}
			cout << endl;
		}
	}
}

void printaddphoneme(string W)	//Function to print phonemes with extra an extra phoneme
{
	string line; 			//Variable for each line in the file
	string Word; 			//Variable for word before first space in line
	string Word2;			//Second Word variable
	string Pronunciation;	//Variable for pronunciation after first space of the line
	string Pronunciation2; //Second Pronunciation variable
	int phonemes;
	int phonemes2;
	
	ifstream istr;			//Declare stream variable
	
	istr.open("PronunciationDictionary.txt");	//Open Dictionary File
	
	
	while (!(istr.eof())) //If word not found and not at end of file
	{
		getline(istr, line); //Reads each line of the file
		splitOnSpace(line, Word, Pronunciation); //Refers to funtion, separates the line
		
		if (Word == W) //If inputted word matches the word before the first space
		{
			
			cout << "Add phoneme\t: ";
			istr.seekg(0);	//Restart file from beginning
			while(!(istr.eof()))	//While not at end of file
			{
				getline(istr, line);	//Get line
				splitOnSpace(line, Word2, Pronunciation2);	//Refer to SplitOnSpace function
				
				if(countphonemes(Pronunciation2, phonemes2) == countphonemes(Pronunciation, phonemes) + 1)	//If amount of Pronunciation2 is 1 more than Pronunciation1
				{
					if(addphocompare(Pronunciation, Pronunciation2) == true)	//Refer to searchphoneme function
					{
						if(ignorespecial(Word2) == true)
						{
							cout << Word2 << " ";
						}
					}
				}
			}
			cout << endl;
		}
	}
}

void printremovephoneme(string W)	//Function to print phonemes with one less phoneme
{
	string line; 			//Variable for each line in the file
	string Word; 			//Variable for word before first space in line
	string Word2;			//Second Word variable
	string Pronunciation;	//Variable for pronunciation after first space of the line
	string Pronunciation2; //Second Pronunciation variable
	int phonemes;
	int phonemes2;
	
	ifstream istr;			//Declare stream variable
	
	istr.open("PronunciationDictionary.txt");	//Open Dictionary File
	
	
	while (!(istr.eof())) //If word not found and not at end of file
	{
		getline(istr, line); //Reads each line of the file
		splitOnSpace(line, Word, Pronunciation); //Refers to funtion, separates the line
		
		if (Word == W) //If inputted word matches the word before the first space
		{
			
			cout << "Remove phoneme\t: ";
			istr.seekg(0);
			while(!(istr.eof()))
			{
				getline(istr, line);
				splitOnSpace(line, Word2, Pronunciation2);
				
				if(countphonemes(Pronunciation2, phonemes2) == countphonemes(Pronunciation, phonemes) - 1)
				{
					if(removephocompare(Pronunciation, Pronunciation2) == true)
					{
						if(ignorespecial(Word2) == true)
						{
							cout << Word2 << " ";
						}
					}
				}
			}
			cout << endl;
		}
	}
}

void printreplacephoneme(string W)	//Function to print phonemes with a replaced phoneme
{
	string line; 			//Variable for each line in the file
	string Word; 			//Variable for word before first space in line
	string Word2;			//Second Word variable
	string Pronunciation;	//Variable for pronunciation after first space of the line
	string Pronunciation2; //Second Pronunciation variable
	int phonemes;
	int phonemes2;
	
	ifstream istr;			//Declare stream variable
	
	istr.open("PronunciationDictionary.txt");	//Open Dictionary File
	
	
	while (!(istr.eof())) //If word not found and not at end of file
	{
		getline(istr, line); //Reads each line of the file
		splitOnSpace(line, Word, Pronunciation); //Refers to funtion, separates the line
		
		if (Word == W) //If inputted word matches the word before the first space
		{
			
			cout << "Replace phoneme\t: ";
			istr.seekg(0);	//Start from beginning of file
			while(!(istr.eof()))	//While not at the end of file
			{
				getline(istr, line);	//Get each individual line
				splitOnSpace(line, Word2, Pronunciation2);	//Refer to SplitOnSpace function
				
				if(countphonemes(Pronunciation2, phonemes2) == countphonemes(Pronunciation, phonemes))	//If amount of phonemes of Pronunciation2 are exactly the same as Pronunciation1
				{
					if(replacephocompare(Pronunciation, Pronunciation2))	//Refer to replaephocompare function
					{
						if(ignorespecial(Word2))
						{
							cout << Word2 << " ";
						}
					}
				}
			}
			cout << endl;
		}
	}
}

	
///////////////////////////MAIN///////////////////////////////////
int main()
{
	bool specialfound = false;
	string W;
	cout << "Insert Word>";
	cin >> W; //Asks for Word;
	
	for(int i = 0; i < W.length(); i++)
	{
		if((W[i] >= 'a') && (W[i] <= 'z'))
		{
			W[i] = (char)((int)W[i] - 32);
		}
		if(!(((int(W[i]) >= 65) && (int(W[i]) <= 90)) || ((int(W[i]) >= 97) && (int(W[i]) <= 122)) || (int(W[i]) == 39)))	//If W is not a letter or apostrophe
		{
			specialfound = true;
		}
	}
	if(specialfound == false)	//If specialfound is false
	{
		printpronunciation(W);	//Refer to funtion to print pronounciation of inputted word
		printidentical(W);		//Refer to function to print identical pronounciation of inputted word
		printaddphoneme(W);		//Refer to function to print phonemes with and additional phoneme
		printremovephoneme(W);	//Refer to function to print phonemes with a removed phoneme
		printreplacephoneme(W);	//Refers to function to print phonemes with a replaced phoneme
	}
	else if(specialfound == true)	//If specialfound is true
	{
		cout << endl;
		cout << "Not found\n";
	}

}