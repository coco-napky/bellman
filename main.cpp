#include "Test.h"
using namespace std;
#define INT_MAX numeric_limits<int>::max()

int* getShortestPath(int** graph, int size, int origin)
{
    bool change_flag;
    int* answer = new int[size];
    for(int i = 0; i < size; i++)
        answer[i] = INT_MAX;
    answer[origin] = 0;

    for (int k = 0; k < size - 1; k++) {
        change_flag = false;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if(graph[j][i] != -1) {
                    if (answer[j] != INT_MAX && answer[i] > answer[j] + graph[j][i]) {
                        answer[i] = answer[j] + graph[j][i];
                        change_flag = true;
                    }
                }
            }
        }
        if(!change_flag)
            break;
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if(graph[j][i] != -1){
                if (answer[i] > answer[j] + graph[j][i]) {
                    return NULL;
                }
            }
        }
    }

    return answer;
}

int main ()
{
    test();
    return 0;
}