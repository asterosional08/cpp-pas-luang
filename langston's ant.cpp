#include <iostream>
#include <vector>
using namespace std;

int main(){
    short M, N, steps, direction=0; cin >> M >> N >> steps;
    vector<vector<bool>> field(N, vector<bool>(M, true));
    
    short xnow=M/2, ynow=N/2;

    for(int i=0; i<steps; i++){

        if(xnow>M-1 || ynow >N-1 || ynow<0 || xnow<0) break;

        if(field[xnow][ynow]){
            field[xnow][ynow] = false;
            direction++;
            if(direction>3) direction = 0;
        }else{
            field[xnow][ynow] = true;
            direction--;
            if(direction<0) direction = 3;
        }

        if(direction == 0) ynow++;
            else if(direction == 1) xnow--;
            else if(direction == 2) ynow--;
            else if(direction == 3) xnow++;
    }

        for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(field[i][j]) cout << '.';
            else cout << '0';
        }
        cout << endl;
    }

}
