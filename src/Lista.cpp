#include "Lista.hpp"

void create_empty_list(List *l){
	l->first = 0;
	l->last  = 0;
}

void list_insert(List *l, Item d) {
	if (l->last >= MAXTAM) {
		printf("LISTA CHEIA!\n");
	} else {
		l->vet[l->last] = d;
		l->last++;
	}
}

void list_print(List *l){
	for(int i=l->first; i<l->last; i++) {
		cout << l->vet[i].val << "\t" << endl; }
}

void name_most_popsup(List *l) {
	int biggest_cont = 0, dynamic_cont = 1;
	string name_most_popup, dynamic_name;

	dynamic_name = l -> vet[0].val;
	name_most_popup = l -> vet[0].val;

	for (int i = l -> first; i < l -> last; i++) {
		for (int j = (l -> first + 1); j < l -> last; j++) {
			if (l -> vet[i].val == l -> vet[j].val) {
				dynamic_cont++;
			}
		}

		if (dynamic_cont > biggest_cont) {
			biggest_cont = dynamic_cont;
			name_most_popup = l -> vet[i].val;
		}

		dynamic_cont = 0;
	}

	cout << "\n\n\t- The most seen name (" << biggest_cont << " times) is: " << name_most_popup << endl; 
}

void replacing_repeated_names(List *l) {
	Item aux;
	
	for (int i = l -> first; i < l -> last - 1; i++) {
		aux.val = l -> vet[i].val;
		//cout << "Name I = " << aux.val/*l -> vet[i].val*/ << endl << endl;
		for (int j = i + 1; j < (l -> last - 1); j++) {
			if (aux.val == l->vet[j].val) {
				//cout << "Repeated name: " << l -> vet[j].val;
				l -> vet[j].val = "\0";
			}
			//cout << "Name J = " << l -> vet[j].val << endl << endl;
		}
	}
}