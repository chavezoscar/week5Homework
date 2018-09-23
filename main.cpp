#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void vectorMode(vector<int>& vectorForMode) {
    int mode = 0;
    int counter = 0;

    sort(vectorForMode.begin(), vectorForMode.end());

    for (int i = 0; i < vectorForMode.size(); i++) {
        int tempCounter = 0;

        for (int j = 0; j < vectorForMode.size(); j++) {
            if (vectorForMode[j] == vectorForMode[i]){ //IF CURRENT NUM IS EQUAL TO ANY SAME NUM IN ARRAY, INCREASE COUNTER
                tempCounter++;

            }
            if (tempCounter > counter) { 
                mode = vectorForMode[i];
            }
        }

    }
    cout << "\nVector mode: " << mode;
}






void vectorMean(vector<int>& vec){ //& pass by reference since we have to access variable directly
    //Initialize variables
    double temp = 0;
    double mean = 0;
    //BEGIN MEAN LOOP
    for (double i = 0; i < vec.size() ; ++i) {
        temp += vec[i];
        mean = temp / vec.size();
    }

    cout << "\nMean of vector contents: " << mean;

}

void vectorMedian(vector<int>& vecForMedian){ //have to pass by reference bcuz if not, original left unsorted
    double median = 0;

    cout << "Sorted Vector: ";

    //FUCKING A, THIS WORKS, DONT FUCK WITH IT
    sort(vecForMedian.begin(), vecForMedian.end());

    for (int i = 0; i < vecForMedian.size(); i++) {

        cout << vecForMedian[i] << ", ";

    }

    //THIS SORT FUNCTION DID NOT WORK
    /* for (int i = 0; i < vecForMode.size() ; i++) {
         for (int j = 1; j < vecForMode.size() - 1 ; j++) {
             if (vecForMode[j] < vecForMode[i]) {
                 swap = vecForMode[i];
                 vecForMode[i] = vecForMode[j];
                 vecForMode[j] = swap;
             }
             cout << vecForMode[i] << ", ";
         }

     }*/

    //FIND MEDIAN

    median = (vecForMedian[vecForMedian.size()/2] + vecForMedian[(vecForMedian.size() - 1)  / 2]) / 2.0;

    cout << "\nMedian of sorted vector: " << median;


}




int main() {

    //Initialize variables
    vector<int> tamalesEaten;
    string temp = "";
    int tamales = 0;
    //BEGIN INPUT LOOP
    do{
        //Prompt user
        cout << "Enter qty of tamales were eaten: " << endl;

        getline(cin, temp);
        tamales = stoi(temp);

        tamalesEaten.push_back(tamales);

        if (tamales == -1){
            tamalesEaten.pop_back(); //REMOVE value -1 FROM VECTOR -- EXITS
            break;
        }

    } while (tamales != -1);




    vectorMedian(tamalesEaten);
    vectorMean(tamalesEaten);
    vectorMode(tamalesEaten);





    return 0;
}