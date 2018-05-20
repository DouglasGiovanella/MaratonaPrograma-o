#include <iostream>
#include <map>

using namespace std;

int main(int argc, char** argv) {
	int time1=0, time2=0,teste, saldo1=0, saldo2=0, golfora1=0, golfora2=0, ponto1=0, ponto2=0;
	char x;
	cin >> teste;
	
	for(int i=0;i<teste;i++){
		for(int j=0;j<2;j++){
			cin >> time1 >> x >> time2;
			if(j == 0 ){
				if(time1 > time2){
					ponto1+= 3;
				}else{
					if(time1 < time2){
						ponto2+= 3;	
					}else{
						ponto1 = 1;
						ponto2 = 1;
					}
				}
				saldo1 = time1 - time2;
				saldo2 = time2 - time1;
				golfora2 = time2;
			}else{
				if(time1 > time2){
					ponto2+= 3;
				}else{
					if(time1 < time2){
						ponto1+= 3;	
					}else{
						ponto1 += 1;
						ponto2 += 1;
					}
				}
				saldo1 += time2 - time1;
				saldo2 += time1 - time2;
				golfora1 = time2;
			}
		}
		if(ponto1 > ponto2){
				cout << "Time 1" << "\n";
		}else{
			if(ponto1 < ponto2){
				cout << "Time 2" << "\n";
			}
		}
		if(ponto1 == ponto2){
			if(saldo1 > saldo2){
				cout << "Time 1" << "\n";
			}else{
				if(saldo1 < saldo2){
				cout << "Time 2" << "\n";
				}else{
					if(golfora1 > golfora2){
						cout << "Time 1" << "\n";
					}else{
						if(golfora1 < golfora2){
							cout << "Time 2" << "\n";	
						}else{
							cout << "Penaltis" << "\n";
						}
					}
				}
			}
		}
		ponto1 = 0;
		ponto2= 0;
		saldo1 =0;
		saldo2 =0;
			
	}
	return 0;
}