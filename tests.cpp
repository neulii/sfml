#include <iostream>

using namespace std;

int game();

int main() {
    
   
    
    //game();
    
    int n = 20;
    
    int *test;
    
    test = new int[n];
   
    for(int i = 0; i<n; i++){
        test[i] = i;
    }
    
    
    
    for(int i = 0; i<n; i++){
        std::cout << test[i] << std::endl;
        
    }
    
    std::cout << endl << endl;
    
    std::cout << *(test+1) << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    return EXIT_SUCCESS;
}
