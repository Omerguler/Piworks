#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
bool is_prime(int a){//Checks if a number is prime
	if(a==1||a==0) return false;//If number is 1 or 0 returns false since i can not calculater them
	for(int i=2;i*i<=a;i++){
		if(a%i==0) return false;//If number is divided by a number then return false
	}
	return true;
}
int total_sum(vector<int> &arr,int line,int index,int total,int &max)//Recursive function that loops through the array
{
	total+=arr[index];//Adds the index to the sum
	if((index+line)<arr.size()){//Checks if the next line exists
		if(!is_prime(arr[index+line]))//Checks if it is prime
			total_sum(arr,line+1,index+line,total,max);//If not prime it goes to the function again
	}
	else//If out of range looks if the max should be changed
		if(total>max) max=total;
	if((index+line+1)<arr.size()){//Checks if the next line exists
		if(!is_prime(arr[index+line+1]))//Checks if the next line exists
			total_sum(arr,line+1,index+line+1,total,max);//If not prime it goes to the function again
	}
	else//If out of range looks if the max should be changed
		if(total>max) max=total;
	return max;//Returns the max path value
}
int main(int argc,char **argv)
{
	ifstream File(argv[1]);//Opens the File
	int count=1,total=0;
	vector<int> layer;
	while(!File.eof()){//Fills the array till the file ends
		int temp;
		File>>temp;//Reads from the file
		layer.push_back(temp);//Pushes it into the vector
	}
	cout<<total_sum(layer,1,0,0,total);//Calls the function
}

