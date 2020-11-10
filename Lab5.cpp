//Jared Howie
//October 16 2018 


#include <iostream>		
#include <stdexcept>
#include <sstream>
#include "CartesianPoint.h"
#include <ctime>
#include <cmath>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>


int main() 
{
	map<string, CartesianPoint> pointMap; 
	map<string, CartesianPoint>::iterator mapIter; 
	string fileName ="PointData.dat";	//PointData.dat MockDataForTesting.txt
	ifstream inFile;
	char character;
	string key;
	string sPointX;
	string sPointY;
	string userKey;
	int x;
	int y;
	int numSpaces = 0;
	CartesianPoint point;
	CartesianPoint point1;
    CartesianPoint point2;
    bool done = false;
	bool found = false;
	double total;
	inFile.open(fileName.c_str());
	
	try
	{
		
	
	
		if(inFile.fail())
		{
			//If file fails to open throw an exception
			throw out_of_range("The file was NOT successfully opened.\nCheck that the file exists\n ");	
		}
		else
		{
		
				//check if the file is empty
				inFile.seekg(0,ios::end);
		    	size_t size = inFile.tellg();
		    	//if it is throw an exception
		    	if( size == 0)
		    	{
		        	throw out_of_range( "File is empty\n");
		    	}
		    	else
		    	{
		    		//go back to the beggining of the file
		    		inFile.seekg(0,ios::beg);
				
				do 
				{
					//grab the first character
					character = inFile.get();
				 	//check for the first space
					if(character == ' ' && numSpaces == 0)
					{
						numSpaces = 1;
						
					}
					//if there hasnt been a space yet, then we are  still getting the key
					else if(numSpaces == 0)
					{
						key += character;
					}
					//if there is one space we are getting the point
					 else if(numSpaces == 1)
					{
						//ignore the brackets, we just want the numbers
						if(character == '(')
						{
							do
							{
								character = inFile.get();
								//ignore commas
								if(character != ',')
								{
									//grab the x value
									sPointX += character;
								}
							}while (character != ',');
							
							do
							{
								character = inFile.get();
								if (character == ' ')
								{
									//grab the y value 
									character = inFile.get();
									sPointY += character;
									character = inFile.get();
										
								}
												
								if (character != ')' && character != ' ')
								{
									//grab the y value
									sPointY += character;
									character = inFile.get();
								}	
										
							
								
							}while (character != ')');
							numSpaces = 2;
						}
					}
						
					else 
					{
						
						//convert the x and y values from the file to integers
						x = stoi(sPointX);
						y = stoi(sPointY);
						//put the x and y values into a point
					    point.SetX(x);
						point.SetY(y);
					
						//put the point into the map at the key from the file
						pointMap[key] = point;
					
						//reset for the next line
						numSpaces = 0;
						key = "";
						sPointX = "";
				        sPointY = "";	
					}		
				}while(!inFile.eof());
			
			}
		}
		//we are done with the file, so we can close it
		inFile.close();
		
		//show the size of the map and its contents
		cout << "The map contains: "<< pointMap.size() << " elements"<<endl;
		cout <<"-----------------------------------"<<endl;
			mapIter = pointMap.begin();
			do
			{
				mapIter++;
			
				if(mapIter == pointMap.end())
				{
					
				}
				else
				{
					mapIter--;
					cout << "The Distance between " << mapIter->second;
					point1 = mapIter->second;
					mapIter++;
					cout << " and " << mapIter->second << " is: ";
					point2 = mapIter->second;
					cout << point1 - point2 << endl;
					//calculate the total distance as we go
					total += point1 - point2;
				}
			
			
			
		
				
			}while( mapIter != pointMap.end());
			//display the total distance
			cout << "Total distance: " << total<<endl;
			//pause and clear the console
			system("PAUSE");
		system("CLS");
		do  
		{
			//ask the user for a label
			cout << "Enter the label of the point you wish to go to (\"quit\" to end)";
			cin >> userKey;
			cout<<endl;
				mapIter = pointMap.begin();
			do
			{
				//if they entered quit, then we leave the loop
				if(userKey == "quit")
				{
					break;
				}
				else
				{
						//check if we have found the key they entered
						if(mapIter->first == userKey)
						{
							//show the user the distance from the first point to the point they entered and leave the loop
							cout << "The distance between " << pointMap.begin()->first <<" " << pointMap.begin()->second 
							 << " and " << mapIter->first << " " << mapIter->second << " is " << pointMap.begin()->second - mapIter->second<<endl; 
							 done = true;
							 break;
						}
						mapIter++;
						//if we have gone through the whole map and still havent found the key than it doesnt exist in the map
						if(mapIter == pointMap.end())
						{
							if(done != true)
							{
								cout << "There is no point labled " << userKey << " in the map."<<endl;
								
								done = true;
							}
							
						}
						else
						{
							done = false;	
						}
							
				
				}
			}while(done == false);
			cout << endl;
		}while(userKey != "quit");
	}
	//catch any exceptions thrown
	catch(const exception& ex)
	{
		cerr << endl << ex.what() << endl;
		
	}
	//END-OF-PROGRAM
	return 0;
}// end of main()
