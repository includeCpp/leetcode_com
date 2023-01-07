#include<iostream>
#include<vector>
#include<string>
#include<set>

void get_info(std::vector<std::vector<int>>& integer, std::vector<std::vector<std::string>>& string, std::size_t i, std::size_t j){
	string[i][j] = "";
	//TODO fix(+=):
	if(integer[i][j] >= integer[i - 1][j]){
		if(string[i - 1][j] == "x"){
			get_info(integer, string, i - 1, j);
		}
		string[i][j] += string[i - 1][j];
	}
	if(integer[i][j] >= integer[i][j + 1]){
		if(string[i][j + 1] == "x"){
			get_info(integer, string, i, j + 1);
		}
		string[i][j] += string[i][j + 1];
	}
	if(integer[i][j] >= integer[i + 1][j]){
		if(string[i + 1][j] == "x"){
			get_info(integer, string, i + 1, j);
		}
		string[i][j] += string[i + 1][j];
	}
	if(integer[i][j] >= integer[i][j - 1]){
		if(string[i][j - 1] == "x"){
			get_info(integer, string, i, j - 1);
		}
		string[i][j] += string[i][j - 1];
	}
}
		
void search_algth(std::vector<std::vector<int>>& integer, std::vector<std::vector<std::string>>& string){
	for(std::size_t i = 1; i < integer.size() - 1; i++){
		for(std::size_t j = 1; j < integer[i].size() - 1; j++){
			get_info(integer, string, i, j);
		}
	}
}

std::vector<std::vector<std::string>> fill_func(std::vector<std::vector<int>>& integer, std::vector<std::vector<std::string>>& str, std::size_t n, std::size_t m){

	/*for(std::size_t i = 0; i < str.size(); i++){
		for(std::size_t j = 0; j < str[i].size(); j++){
			str[i][j].push_back(' ');
		}
	}*/

	//filling up str
	for(std::size_t i = 0; i < str.size(); i++){
		for(std::size_t j = 0; j < str[i].size(); j++){
			if(i == 0 || j == 0 || i == str.size() - 1 || j == str[i].size() - 1){
				if(i == 0 || j == 0){
					str[i][j] += "P";
					if((i == 0 && j == str[i].size() - 1) || (i == str.size() - 1 && j == 0)){
						str[i][j] += "A";
					}
				}
				else if(i == str.size() - 1 || j == str[i].size() - 1){
					str[i][j] += "A";
				} 
			} else{
				str[i][j] += "x";
			}
		}
	}
	return str;
}

void fix_value(std::vector<std::vector<std::string>>& string){
	for(int i = 0; i < string.size(); i++){
		for(int j = 0; j < string[i].size(); j++){
			if((i == 0 && j == string[i].size() - 1) || (i == string[i].size() - 1 && j == 0)) continue;
			else{
				if((std::find(string[i][j].begin(), string[i][j].end(), 'P') != string[i][j].end()) && (std::find(string[i][j].begin(), string[i][j].end(), 'A') != string[i][j].end())){
					string[i][j] = "PA";
				}
				else if((std::find(string[i][j].begin(), string[i][j].end(), 'A') != string[i][j].end()) && (std::find(string[i][j].begin(), string[i][j].end(), 'P') == string[i][j].end())){
					string[i][j] = "A";
				}
				else if((std::find(string[i][j].begin(), string[i][j].end(), 'A') == string[i][j].end()) && (std::find(string[i][j].begin(), string[i][j].end(), 'P') != string[i][j].end())){
					string[i][j] = "P";
				}
				else if((std::find(string[i][j].begin(), string[i][j].end(), 'A') == string[i][j].end()) && (std::find(string[i][j].begin(), string[i][j].end(), 'P') == string[i][j].end())){
					string[i][j] = "C";
				}
			}
		}
	}
}

void fix_borders(std::vector<std::vector<int>>& v_main, std::vector<std::vector<std::string>>& string){
	//up
	for(std::size_t i = 0; i < 1; i++){
		for(std::size_t j = 1; j < v_main[i].size() - 1; j++){
			if(v_main[i][j] >= v_main[i + 1][j]){
				string[i][j] += string[i + 1][j];
			}
		}
	}
	//down
	for(std::size_t i = v_main.size() - 2; i < v_main.size() - 1; i++){
		for(std::size_t j = 1; j < v_main[i].size() - 1; j++){
			if(v_main[i][j] <= v_main[i + 1][j]){
				string[i + 1][j] += string[i][j];
			}
		}
	}
	//left side
	for(std::size_t i = 0; i < v_main.size() - 1; i++){
		for(std::size_t j = 0; j < 1; j++){
			if(v_main[i][j] >= v_main[i][j + 1]){
				string[i][j] += string[i][j + 1];
			}
		}
	}
	//right side
	for(std::size_t i = 0; i < v_main.size() - 1; i++){
		for(std::size_t j = v_main[i].size() - 2; j < v_main[i].size() - 1; j++){
			if(v_main[i][j] >= v_main[i][j + 1]){
				string[i][j + 1] += string[i][j];
			}
		}
	}
	//corners
	//top left corner
	for(std::size_t i = 0; i < 1; i++){
		for(std::size_t j = 0; j < 1; j++){
			if(v_main[i][j] >= v_main[i][j + 1]){
				string[i][j] += string[i][j + 1];
			} else {
				string[i][j + 1] += string[i][j];
			}
			if(v_main[i][j] > v_main[i + 1][j]){
				string[i][j] += string[i + 1][j];
			} else {
				string[i + 1][j] += string[i][j];
			}
		}
	}
	//top right corner
	for(std::size_t i = 0; i < 1; i++){
		for(std::size_t j = v_main[i].size() - 1; j == v_main[i].size() - 1; j++){
			if(v_main[i][j] <= v_main[i][j - 1]){
				string[i][j - 1] += string[i][j];
			}
			if(v_main[i][j] <= v_main[i + 1][j]){
				string[i + 1][j] += string[i][j];
			}
		}
	}
	//bottom left corner
	for(std::size_t i = v_main.size() - 1; i == v_main.size() - 1; i++){
		for(std::size_t j = 0; j < 1; j++){
			if(v_main[i - 1][j] >= v_main[i][j]){
				string[i - 1][j] += string[i][j];
			}
			if(v_main[i][j + 1] >= v_main[i][j]){
				string[i][j + 1] += string[i][j];
			}
		}
	}
	//bottom right corner
	for(std::size_t i = v_main.size() - 1; i == v_main.size() - 1; i++){
		for(std::size_t j = v_main[i].size() - 1; j == v_main[i].size() - 1; j++){
			if(v_main[i][j] >= v_main[i][j - 1]){
				string[i][j] += string[i][j - 1];
			} else {
				string[i][j - 1] += string[i][j];
			}
			if(v_main[i][j] >= v_main[i - 1][j]){
				string[i][j] += string[i - 1][j];
			} else {
				string[i - 1][j] += string[i][j];
			}

		}
	}

}



int main(){
	int n = 5;
	int m = n;

	std::vector<std::vector<std::string>> str = {{"P", "P", "P", "P", "PA"}, {"P", "x", "x", "x", "A"}, {"P", "x", "x", "x", "A"}, {"P", "x", "x", "x", "A"}, {"PA", "A", "A", "A", "A"}};
	std::vector<std::vector<int>> main_vec = {{1, 2, 2, 3, 5}, {3, 2, 8, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};

	//fill_func(main_vec, str, n, m);

	for(int i = 0; i < str.size(); i++){
		for(size_t j = 0; j < str[i].size(); j++){
			std::cout << str[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	for(int i = 0; i < main_vec.size(); i++){
		for(size_t j = 0; j < main_vec[i].size(); j++){
				std::cout << main_vec[i][j] << "  ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	search_algth(main_vec, str);
	fix_borders(main_vec, str);
	fix_value(str);

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	for(int i = 0; i < str.size(); i++){
		for(size_t j = 0; j < str[i].size(); j++){
			std::cout << str[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}