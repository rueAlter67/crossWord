#include <stdio.h>
#include <string.h>
#define ROW 20
#define COL 20

/* TODO (#1#): Create the following tasks:
               1. right-low diagonal
               2. left-upper diagonal
               3. right-upper diagonall
               4. what to do if word is  NOT 
                              ALGEBRA but ARBEGLA??? 
							  
*/


typedef char str20[21];

int
checkHorizontally(char TABLE[][COL], str20 word[], int index, int *foundRow, int*foundCol)
{
	int col,i,j,row = 0;
	int counter= sizeof(word+index);
	int found = 0;
	
	do{
		i=0;// restart the count to 0 of word
		col =0;
		counter = sizeof(word+index);

		while(counter>0 && col<COL)
		{
			if(TABLE[row][col] == word[index][i])
			{
				counter--;
				i++;
				col++;	
			}
			else
				col++;
		}
		
		row++;
		
	}while(row<ROW && counter > 0);
			
	if(counter ==0)
	{
		found = 1;
		*foundRow = row;//-sizeof(word+index);
		*foundCol = 1+col-sizeof(word+index);
		
	}
	
		
	return found;
}

int
checkVertically(char TABLE[][COL], str20 word[], int index, int *foundRow, int*foundCol)
{
	int row,i,j,col = 0;
	int counter=  sizeof(word+index);
	int found = 0;
	
	do{
		i=0;// restart the count to 0 of word
		row =0;
		counter =  sizeof(word+index);

		while(counter>0 && row<ROW)
		{
			if(TABLE[row][col] == word[index][i])
			{
				counter--;
				i++;
				row++;	
			}
			else
				row++;
		}
		
		col++;
		
	}while(col<COL && counter > 0);
			
	if(counter ==0)
	{
		found = 1;
		*foundRow = 1+row-sizeof(word+index);
		*foundCol = col;//-sizeof(word+index);
	}
	
	return found;
}

int
checkLeftLowerDiagonal(char TABLE[][COL], str20 word[], int index, int *foundRow, int*foundCol)
{
	int row=0,col=0;
	int rowD,colD; // for diagonal searches
	int counter=  counter= strlen(*(word+index));
	int found = 0; // by default
	int i=0;
	
	do{
		colD = col; rowD= row; 
		while(row <ROW && (colD< COL&& rowD<ROW) && counter >0) 
		{
			if(TABLE[rowD][colD] == word[index][i]) // searches diagonally
			{
				counter--;
				i++;
				rowD++; 
				colD++;	
			}
			else // quits the diagonal ++ move to the next row
			{
				counter= strlen(*(word+index));
				i=0;
				row++;
				rowD= row; 
				colD=col;
			}		
		}
		row=0;
		col++;
	
	}while(col<COL && counter>0);
			
	if(counter ==0)
	{
		found = 1;
		*foundRow = 1+rowD-sizeof(word+index);
		*foundCol = 1+colD-sizeof(word+index);
		
	}
	return found;
}


int
checkRightLowerDiagonal(char TABLE[][COL], str20 word[], int index, int *foundRow, int*foundCol)
{
	
	int row=0,col=0;
	int rowD,colD; // for diagonal searches
	int counter= strlen(*(word+index));
	int found = 0; // by default
	int i=0;

	do{
		
		colD = col; rowD= row; 
		
		while(col <COL && (colD< COL&& rowD<ROW) && counter >0) 
		{/*
			printf("\n%c%c",TABLE[rowD][colD], word[index][i]);
			printf("\ncounter= %d", counter);
			printf("row = %d, rowD = %d, col = %d, colD = %d", row,rowD,
																col,colD);*/
			if(TABLE[rowD][colD] == word[index][i])
			{
				counter--;
				i++;
				colD--;
				rowD++;	
			}	
			else
			{
				counter= strlen(*(word+index));
				i=0;
				col++;
				colD= col; 
				rowD=row;
			}
		}
		
		row++;
		col =0;

	}while(row<ROW && counter > 0);
			

	if(counter ==0)
	{
		found = 1;
		*foundRow = row;
		*foundCol = col+strlen(*(word+index))+1;
		
	}
	
	return found;
}


int
main()
{
	int i, foundRow, foundCol; 
	char TABLE[20][20] =
	{
		"MTSHAISQSRIXQLBIKYAY",
		"MYOHCPUCAYSWUARYRAPT",
		"EHRPQLKQIFOHWCSONCPI",
		"UENTOHQFSTSUXCEAAILL",
		"QDMAELHLGSSEQHLJHTII",
		"KIVQUMONZBMITYDEIEEB",
		"VWNPXCOGNMTHTTIAFMDA",
		"FBWPKLQNYAPITAHRWHMB",
		"SULUCLACOACANTTETTAO",
		"WCRZCTRXRGYIJYVSOITR",
		"QNSBEDWGENIDXZRLERHP",
		"JPWWABKOUUVROLLCBAYX",
		"XHGQPHMWTUBBTGSVCUCW",
		"NELKZESCINORTANIBMOC",
		"BKIBTALHFNQDTMTYIRDX",
		"VZYRCATEGORYTHEORYTF",
		"LFYCIGOLLACITAMEHTAM",
		"YRTEMOEGLAITNEREFFID",
		"FHLHXEPHGEOMETRYSOIU",
		"DIFFERENTIALEQUATION"
	};
	
	str20 wordSearch[20] = 
	{
		"CALCULUS", "TRIGONOMETRY",	"PROBABILITY","GRAPHTHEORY",
		"GEOMETRY","TOPOLOGY","APPLIEDMATH","ANALYTICGEOMETRY",
		"COMBINATRONICS","STATISTICS","ARITHMETIC","CATEGORYTHEORY",
		"SETTHEORY","DIFFERENTIALGEOMETRY","ANALYSIS","ALGEBRA",
		"GAMETHEORY","NUMBERTHEORY","DIFFERENTIALEQUATION","MATHEMATICALLOGIC",
	};
	

	for(i=0; i<20; i++)
	{
		if(checkHorizontally(TABLE, wordSearch, i, &foundRow, &foundCol))
			printf("\n%s can be found HORIZONTALLY on row-%d column-%d",wordSearch+i, foundRow, foundCol);
		else if(checkVertically(TABLE, wordSearch, i, &foundRow, &foundCol))
			printf("\n%s can be found VERTICALLY on row-%d column-%d",wordSearch+i, foundRow, foundCol);
		else if(checkLeftLowerDiagonal(TABLE, wordSearch, i, &foundRow, &foundCol))
			printf("\n%s can be found LEFT LOW diagonally on row-%d column-%d",wordSearch+i, foundRow, foundCol);
		else if(checkRightLowerDiagonal(TABLE, wordSearch, i, &foundRow, &foundCol))
			printf("\n%s can be found RIGHT LOW diagonally on row-%d column-%d",wordSearch+i, foundRow, foundCol);	
		else 
			printf("\n%s can't be found.",wordSearch+i);
		
		foundRow=0;
		foundCol=0;	
	}
	
	return 0;
}