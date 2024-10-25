#include <iostream>
#include <algorithm>
using namespace std;

void findW(float ishw[8][4], float shw[4], float routeRate[8][4], float fin[4]){
float itemW [8] = {0,0,0,0};

for (int i = 0; i<4; i++){
    for (int j= 0; j<8; j++){
        itemW[j]+=ishw[j][i]*shw[i]/100;
    }
 }


 for (int i = 0; i<4; i++){
    for (int j= 0; j<8; j++){
        fin[i]+=routeRate[j][i]*itemW[j]/100.0;
    }
 }
}
void printArr (float arr[4]){
    for (int i =0; i<4; i++){
            cout << arr[i] << " ";
    }

    cout << endl;
}
void printArr (int arr[4]){
    for (int i =0; i<4; i++){
            cout << arr[i]<< " ";
    }
    cout << endl;
}
void transformArray(float input[4], int output[4]) {
    // Create a temporary array to store indices
    int indices[4] = {0, 1, 2, 3};

    // Sort indices based on the values in the input array
    sort(indices, indices + 4, [&input](int a, int b) {
        return input[a] < input[b];
    });

    // Fill the output array with order values
    for (int i = 0; i < 4; ++i) {
        output[indices[i]] = i + 1;
    }
}


bool compareArrays(int arr1[4], int arr2[4]) {
    for (int i = 0; i < 4; ++i) {
        if (arr1[i] != arr2[i]) {
            return false; // Return false if any element is different
        }
    }
    return true; // Return true if all elements are equal
}

int main() {
    float x = -15;
    int amount;
    float ishw [8][4] {
        {20, 20, 0, 0},
        {10, 15, 5, 5},
        {15, 0, 0, 0},
        {5, 10, 60, 10},
        {10, 20, 10, 10},
        {20, 0, 5, 50},
        {10, 25, 10, 20},
        {10, 10, 10, 5}
    };
    float shw [4] =  {60, 30, 5, 5};

    float routeRate[8][4] = {
        {5, 8, 4, 3},        // From {5, 0.9, 8, 1.44, 4, 0.72, 3, 0.54}
        {10, 8.1, 9.4, 2},   // From {10, 1.1, 8.1, 0.891, 9.4, 1.034, 2, 0.22}
        {10, 7.4, 8.5, 2},   // From {10, 0.9, 7.4, 0.666, 8.5, 0.765, 2, 0.18}
        {5, 3, 8, 4},        // From {5, 0.475, 3, 0.285, 8, 0.76, 4, 0.38}
        {9, 8.2, 5, 5.7},    // From {9, 1.17, 8.2, 1.066, 5, 0.65, 5.7, 0.741}
        {5, 8, 2, 7},        // From {5, 0.7375, 8, 1.18, 2, 0.295, 7, 1.0325}
        {4, 2, 7, 8},
        {7,5,8,7}
                 // From {4, 0.6, 2, 0.3, 7, 1.05, 8, 1.2}
    };
    float ogW [4] = {0,0,0,0};
    int ogO [4] = {0,0,0,0};
    float W [4] = {0,0,0,0};
    int O [4] = {0,0,0,0};

findW(ishw, shw, routeRate, ogW);
    printArr(ogW);
    transformArray(ogW,ogO);
    printArr(ogO);

for (int j=15; j>=x;x+=0.5){
        amount =0;
    for (int i =0; i<4; i++){
        for (int j= 0; j<8; j++){

            //routeRate[j][i]+=x;
            ishw[j][i]+=x;

            findW(ishw, shw, routeRate,W);
            transformArray(W,O);
            if (!compareArrays(ogO,O)){
                amount++;
            }

            //routeRate[j][i]-=x;
            ishw[j][i]-=x;

            W[0]=W[1]=W[2]=W[3]=0;
        }

    }
    cout << x << " " << amount << endl;
}

  return 0;
}
