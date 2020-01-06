#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std ;

template <class T>
T maxel(vector<vector<T>>& mat, int n, int m){
T max = mat[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j <m; j++)
            if (mat[i][j]>max)max=mat[i][j];
return max;
}


//ili ovako 
template<class T>
T maxEl(vector<vector<T>> matrica){
    vector<vector<T>>::iterator it = matrica.begin(); 
    vector<T> vrsta = *it;
    vector<T>:: iterator it2 = vrsta . begin ();
    T max = ∗it2;
    for(it = matrica.begin(); it != matrica.end(); it++){
        vector<T> vrsta = ∗it;
        for(it2 = vrsta.begin(); it2 != vrsta.end(); it2++){
}
return max;
if(max < ∗it2)
max = ∗it2;
    }
}
return max;


int main(){
vector<vector<int>> mat;
}
int dimn = 3, dimm = 2; vector<int> col1 , col2 , col3 ; col1 . push back (1);
col1 . push back (2);
col2 . push back (3);
col2 . push back (4);
col3 . push back (9);
col3 . push back (5);
mat.push back(col1); mat.push back(col2); mat.push back(col3);
cout << maxel(mat, dimn, dimm) << endl; system(”pause ”);
return 0;