#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main(){
    /*
    input nya diawali dengan integer N buat ukuran MATRIKS PERSEGI, jadi ukurannya N*N;
    lalu diikuti dengan input float N*N kali, yaitu elemen elemennya.
    contoh:
        3           <--- matriks 3x3
        1 0 0       <--- isi elemennya
        0 1 0       
        0 0 1
    */
    int orde; cin >> orde;
    vector<vector<float>> matriks(orde, vector<float>(orde));
    vector<vector<float>> identitas(orde, vector<float>(orde));
    vector<float> memo; vector<int> urut(orde);

    for(int i=0; i<orde; i++) for(int j=0; j<orde; j++) if(i==j) identitas[i][j] = 1;

    cout << fixed << setprecision(2);

    for(int i=0; i<orde; i++) for(int j=0; j<orde; j++) cin >> matriks[i][j];

    //uncomment bawah klau mau lihat [A|I]
    /*for(int i=0; i<orde; i++){
        for(int j=0; j<orde; j++) cout << matriks[i][j] << " ";
        cout << '|';
        for(int j=0; j<orde; j++) cout << identitas[i][j] << " ";
        cout << endl;
    }*/

    for(int i=0; i<orde; i++){
        bool barisnol=true;
        for(int j=0; j<orde; j++){
            if(matriks[i][j] != 0){
                barisnol = false;
                memo.push_back(matriks[i][j]);
                urut[j] =i;
                for(int k=0; k<orde; k++){
                    if(k==i || matriks[k][j] == 0) continue;
                    float pengali = matriks[k][j]/matriks[i][j];
                    for(int l=0; l<orde; l++) matriks[k][l] -= matriks[i][l]*pengali;
                    for(int l=0; l<orde; l++) identitas[k][l] -= identitas[i][l]*pengali;
                }
                break;
            }
        }
        if(barisnol){
            cout << "Matriks tidak ada invers!" << endl; return 0;
        }
    }

    for(int i=0; i<orde; i++){
        for(int j=0; j<orde; j++) matriks[i][j] /=memo[i];
        for(int j=0; j<orde; j++) identitas[i][j] /=memo[i];
    }


    //uncomment bawah klau mau lihat [I|A^(-1)]

    /*for(int i=0; i<orde; i++){
        for(int j=0; j<orde; j++) cout << matriks[urut[i]][j] << " ";
        cout << '|';
        for(int j=0; j<orde; j++) cout << identitas[urut[i]][j] << " ";
        cout << endl;
    }*/

    for(int i=0; i<orde; i++){
        for(int j=0; j<orde; j++) cout << identitas[urut[i]][j] << " ";
        cout << endl;
    }

    return 0;
}

