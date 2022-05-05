#include "Lista.hpp"

void archive_reading(List *l) {
	string line;
	Item aux;

	ifstream file;
	file.open("10names.txt");
	if(file.is_open()) {
		while(!file.eof()) {
			getline(file, line);
			aux.val = line;
			list_insert(l, aux);
		}
		file.close();
	}
}

int main(){

	List l;
	Item aux;
	string line;

	create_empty_list(&l);
	archive_reading(&l);
	name_most_popsup(&l);
	cout << "\n\n\t- List before changes: " << endl << endl;
	list_print(&l);
	replacing_repeated_names(&l);
	cout << "\n\n\t- Lista after changes: " << endl << endl;
	list_print(&l);
	return 0;
}