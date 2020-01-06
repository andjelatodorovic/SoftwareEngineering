//Napisati sablonsku funkciju za nalazenje maksimalnog elementa vektora
#include <stdlib .h> 
#include <iostream>
#include <vector>

using namespace std;

template <class T>
T maxel(vector<T>& v, int n){
T max = v[0];
for (int i = 0; i < v.size(); i++) 
if (v[i]>max)max=v[i];
return max;
}
int main(){
}
vector<int> a ; a.push back(1); a.push back(2); a.push back(3);
cout << maxel(a, 3) << endl; system(”pause ”);
return 0;