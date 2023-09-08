#include <iostream>
std::string sortString(std::string letters){
	int count[26] = {0};
	int maxCount = 0;
	for(char letter: letters){
		count [(int(letter))-97]++;
		if (count [(int(letter))-97] > maxCount){
			maxCount = count [(int(letter))-97];
		}
	}
	std::string retStr;

	for(int i = 0; i< maxCount; i++){
		for(int j = 0; j < 26; j++){
			if (count[j] > 0){
				count[j]--;
				retStr +=  char(97+j);
			}
		}

		for(int j = 25; j >= 0; j--){
			if (count[j] > 0 ){
				count[j]--;
				retStr +=  char(97+j);
			}
		}
	}
	return retStr;



}

int main(){
	std::string letters = "aaabbbccc";
	std::cout<< sortString(letters) ;
}