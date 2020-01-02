#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> whiteBoard =
    {"WBWBWBWB",
     "BWBWBWBW",
     "WBWBWBWB",
     "BWBWBWBW",
     "WBWBWBWB",
     "BWBWBWBW",
     "WBWBWBWB",
     "BWBWBWBW"};
vector<string> blackBoard =
    {"BWBWBWBW",
     "WBWBWBWB",
     "BWBWBWBW",
     "WBWBWBWB",
     "BWBWBWBW",
     "WBWBWBWB",
     "BWBWBWBW",
     "WBWBWBWB"};

int compareWhiteBoards(int i, int j, vector<string> chessBoard){
    int whiteMin = 0;
    for(int k = i; k < i + 8; k++){
        for(int l = j; l < j + 8; l++){
            if(chessBoard[k][l] != whiteBoard[k - i][l - j]){  
                whiteMin++;
            }
        }
    }
    return whiteMin;
}

int compareBlackBoards(int i, int j, vector<string> chessBoard){
    int blackMin = 0;
    for(int k = i; k < i + 8; k++){
        for(int l = j; l < j + 8; l++){
            if(chessBoard[k][l] != blackBoard[k - i][l - j]){
                blackMin++;
            }
        }
    }
    return blackMin;
}
int main(void){
	int height, width;
	cin>>height;
	cin>>width;
		
	vector<string> chessBoard;
    int result = 64;
    
	for(int i = 0; i < height; i++){
		string row;
		cin>>row;
		chessBoard.push_back(row);
	}
	
	for(int i = 0; i < height - 7; i++){
	    for(int j = 0; j < width - 7; j++){
	        result = min(result, min(compareWhiteBoards(i, j, chessBoard), compareBlackBoards(i, j, chessBoard)));
	    }
	}
    cout<<result<<endl;
    
	return 0;
}


