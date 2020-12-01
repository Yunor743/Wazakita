/*
** EPITECH PROJECT, 2021
** Wazakita
** File description:
** Wazakita
*/

#include "main.hpp"

using namespace std;

const string P1("P1 missing or incorrect");
const string WRONG_NB_COL_LGN("Nb columns and/or nb lines incorrect");
const string MATRIX_SQUARE("Matrix is not square");
const string IRREGULAR_CONTENT("Matrix description with incorrect content");
const string DISCONNECTED_GRAPH("Matrix corresponds to a disconnected graph");

void coor(vector<vector<int>> Mat){
	for(size_t i(0); i < Mat.size(); ++i) { 
		cout << " " << endl;
		for (size_t j(0); j < Mat.size(); ++j){
	//cout << "M[" << i <<"," << j <<"] = " << Mat[i][j] << " ";
	cout << Mat[i][j] << " ";}
	}
}

bool verification(vector<vector<int>> A , int line){

    for (int i(0); i<line; i++){
        for(int j(0); j<line; j++){
            
            if (((A[i][j])!= 0) and ((A[i][j]) != 1 )){
                cout<< IRREGULAR_CONTENT<< endl;
                return 1;}
		}
	}
	cout<<"Matrix bouléen correcte"<< endl;
return 0;
}

bool verif_connexe(vector<vector<int>> A, int line){	//On part du principe que c'est tout à 0
	bool aUnUn = false;
	int nbLignes = A.size();
	bool estConnexe = true;								//Pour chaque colonne de la ligne line
	for (int i(0); i<nbLignes; i++){			        //Si il y a au moins un element a 1
		
		if(A[line][i]==1){
			aUnUn = true;			
		}
	}
	if(aUnUn == false){ //= ya que des 0 sur la ligne
		for (int j(0); j < nbLignes; j++){
				//Parcourt une colonne
			
			if(A[j][line] == 1){					//est ce que sur la colonne correspondante ya un 1 ?
				aUnUn = true;
			}
		}
			if(aUnUn == false){
				estConnexe = false;
			}
	}
	if(!estConnexe){
				//exit(0);
	return false;
	}
	else{
		if(line < nbLignes-1){
			line++;
			return verif_connexe(A, line);
		}
		else{
			return true;
		}
	}		
}

vector<vector<int>> Diagonale(vector<vector<int>>& A , int line){

	 for (int i(0); i<line; i++){
            if ((A[i][i])!= 0){
               A[i][i] = 0;
				}
            }
return A;
}

vector<vector<int>> trans_symetrique(vector<vector<int>>& A , int line){

	for (int i(0); i < line; i++){
		
	for (int j(0); j < line; j++){
		
		if ((A[i][j]) == (A[j][i])){} 
		else {
			if ((A[i][j]) == 1){
				A[j][i] = 1; 
				} 
				else {
					if((A[i][j]) == 0){ 
						A[j][i] = 0; } 
					}
				}
			}
		}
return A;
}

bool tache_trois(vector<vector<int>> A, int line){
	int nbLignes = A.size();
	int visited[nbLignes];
	for (int i(0); i<nbLignes; i++){
		for(int j(0); j<nbLignes; j++){					
			if(A[i][j]==1){								//prochaine ligne à vérifier -> valeur de j
				bool exists = find(begin(visited), end(visited), j); 		//!= end(visited);
				if(!exists){ 
					visited[j];
					cout<< j<<endl;
				}
				
				
				if(line < nbLignes-1){ 
				i=j;
				return verif_connexe(A, line);
				}
			}
		}
	}		
}

int main ()
{ 
	int line;	// nbr de ligne
	int col;	// nbr de colonne
	string x; //  P1

	do{
		cout << "Entrez la dimension de la Matrice:" << endl;
		cout << "Entrez P1/ Lignes/colonnes:" << endl;
		cin>> x;
		cin >> line;
		cin >> col;}
			while ((line <= 0) and (col <= 0));
			cout << "Entrez les composantes de la matrice :( " << line * col << " )"<< endl;
		vector<vector<int>> matAdj(line, vector<int>(col));
		for (auto& l : matAdj){
		for (auto& c : l){
		cin >> c;}
		}
		if ((x != "P1")){ 		// P1 ?
		cout << P1<< endl;
return 1;
}

		if (line == col){}			// matrice carrée ?
			else {
				cout << endl <<MATRIX_SQUARE << endl;
return 1;
}

verification(matAdj , line); // matrice booléenne ?

cout << "Modification en matrice diagonale :" << endl;
Diagonale(matAdj , line);
coor(matAdj);		//affiche nouvelle matrice diago
cout<< endl;

cout << "Modification en matrice symétrique :" << endl;
trans_symetrique(matAdj , line);	// affiche nouvelle symétrie
coor(matAdj);
cout<<endl;

cout << "Matrice connexe ?"<< endl; //matrice connexe ?
if (verif_connexe(matAdj, 0)){
	cout<<"la matrice est connexe";
}
else{
	cout<< DISCONNECTED_GRAPH;
	}
  return 0;
}
