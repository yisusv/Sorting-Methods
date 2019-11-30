#include <iostream>   //Header files
#include <vector>
#include <random>
using namespace std;

int get_random_number();   //Generate random numbers
void fill_vector(vector<int> &v, int size);   //Fill the vector
void print_vector(vector<int> v);   //Print the vector
void merge(vector<int>, vector<int>, vector<int> &);   //Function to merge vectors L and R
void merge_sort(vector<int> &);   //Recursive function to sort an integer vector

int main()
{
  vector<int> v1;   //We create the vector that we are going to order...

  fill_vector(v1, 10);   //... we fill it

  cout << "-Disordered vector: " << endl;
  print_vector(v1);
	
  merge_sort(v1);

  cout << endl;
  cout << "-Ordered vector: " << endl;
	print_vector(v1);

  return 0;
}

int get_random_number()
{
  random_device dev;
  mt19937 gen(dev());
  uniform_int_distribution<> dist6(1, 1000);   //Generate random numbers between 1 and 1000
  return dist6(gen);
}

void fill_vector(vector<int> &v, int size)
{
  for(int i = 0; i < size; i++)
    v.push_back(get_random_number());
}

void print_vector(vector<int> v)
{
  for(auto i : v)
    cout << i << "   ";

  cout << endl;
}

void merge_sort(vector<int> &v)
{
  if(v.size() <= 1)   //If the vector is of size <= 1, it is because it is already ordered
    return;

  int half = v.size()/2;   //Vector half
  vector<int> left;   //sub left part of the vector
  vector<int> right;   //sub right part of the vector

  for(int i = 0; i < half; i++)   //Fill the vector left
    left.push_back(v[i]);
  for(int i = 0; i < (v.size()) - half; i++)   //Fill the vector right
    right.push_back(v[half + i]);

  merge_sort(left);   //Sorting the left sub vector
  merge_sort(right);   //Sorting the right sub vector
  merge(left, right, v);   //Merge Left and Right as sorted list
}

void merge(vector<int> left, vector<int> right, vector<int> &v)
{
  int nLeft = left.size();
  int nRight = right.size();
  int i = 0;   //i: to mark the index of merged sub-vector (v)
  int j = 0;   //j: to mark the index of left sub-vector (left)
  int k = 0;   //k: to mark the index of right subarray (right)

  while(j < nLeft and k < nRight)
  {
    if(left[j] < right[k])
    {
      v[i] = left[j];
      j++;
    }
    else
    {
      v[i] = right[k];
      k++;
		}
		i++;
  }
  while(j < nLeft)
  {
    v[i] = left[j];
    j++; i++;
	}
  while(k < nRight)
  {
    v[i] = right[k];
    k++; i++;
  }
}
