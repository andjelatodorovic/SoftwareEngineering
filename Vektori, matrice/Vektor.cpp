//Napisati sablonsku funkciju za nalazenje maksimalnog elementa vektora
#include <stdlib .h> 
#include <iostream>
#include <vector>

using namespace std;

template <class T>
T minElement(vector<T>& v, int n){
T min = v[0];
for (int i = 0; i < v.size(); i++) 
if (v[i] < min) min = v[i];
return min;
}

T maxElement(vector<T>& v, int n){
T max = v[0];
for (int i = 0; i < v.size(); i++) 
if (v[i] > max) max = v[i];
return max;
}



template <class T>
T centarVektora(vector<T>& v, T d, int n){
double x = minElement(v,n) - d;
 
for (int i = 0; i < v.size(); i++)
{
  if ((v[i] - d) <= x) && (d + v[i]) >= x) ) {
    x = v[i] + d;
  }

return x;
}
return false;


int main(){
}
vector<int> a ; 
a.pushback(1);
a.pushback(7);
a.pushback(3);
a.pushback (4)
cout << centarVektora(a, 3, 5) << endl; 
system(”pause ”);
return 0;