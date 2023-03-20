#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// read file & store in array
// create adjacency LIST
// find max distance between 2 people
// find avg distance between 2 people?

struct chars{   //  20 char for each name
    char name[20];  // names, where each name
    char friends[12][20];   // points to an array of friends/known people
};  


void degOfSep(struct chars* data, int pos){
    int vert = 12;    // assuming max. 12 friends
    int visited[vert];    // to keep track if connection was visited
    for(int i=0; i<vert; i++){
        visited[i] = 0; // i.e. not visited
    }

    int q[vert];    // to actually keep connections' names
    int head, tail = 0; // empty

    visited[pos] = 1;   // visited
    tail++;
    q[tail] = pos;

    while(head!=tail){
        head++;
        pos = q[head];
        int adj = 0;
        while(adj<vert){
            for (int i=0; i<vert; i++){
                if (data[pos].friends[i] && visited[i]==0){
                    visited[adj] = 1;
                    tail++;
                    q[tail] = adj;
                }
            }
        }
    }
}

void getData(struct chars* data){
    int lineLen = 150;
    FILE    *textfile;
    char    line[lineLen];

    char* tokenPtr;
 
    textfile = fopen("projectDATA.txt", "r");
    int i = 0;
    while(fgets(line, lineLen, textfile)){
        tokenPtr = strtok(line, ",");   // thank you Deitel
        int j = 0;
        while(tokenPtr){
            if(j==0){
                strcpy(data[i].name,tokenPtr);
                // printf("%s: ", data[i].name);
            } else {
                strcpy(data[i].friends[j], tokenPtr);
                // printf("%s, ", data[i].friends[j]);
                tokenPtr = strtok(NULL, ",");
            } j++;
        } i++;
    }
    fclose(textfile);
}


void main(){
    struct chars data[61];
    getData(data);
    degOfSep(data, (int) data[0].name);

}