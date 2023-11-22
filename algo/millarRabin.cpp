#include<iostream>
using namespace std;

bool miller(long long n){
	if(n <=1 || n % 2 == 0){
		if(n != 2){
			return false;
		}
	}
	if(n == 2 || n == 3){
		return true;
	}
	long long d = n-1;
    while(d % 2 == 0){
        d /= 2;
    }
	long long a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
	for(int i = 0; i < 12 && a[i] < n; ++i){
		long long temp = d;
        long long mod = binexp2(a[i], temp, n);
        if(mod == 1){
            continue;
 		}
        while(temp != n-1 && mod != n-1){
            mod = multiply(mod, mod, n);
            temp *= 2;
        	  
	    }
	    if(mod != n-1){
	    	return false;
	    }  
    }
    return true;
}

int main()
{
    
    return 0;
}