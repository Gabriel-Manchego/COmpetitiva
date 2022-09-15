#include <iostream>
#include <queue>

using namespace std;


template <typename T>
struct nodo{
	T valor;
	nodo<T> *nodos[2];
	nodo<T>(T v){
		valor = v ; nodos[0] = nodos[1] = nullptr;
	}
	
};


template <class T>
class ArbolBinario{
	nodo<T>* root = nullptr;	
public:
	void Menu();
	bool Find(T bus, nodo<T>**& pos);
	bool Insert(T valor);
	
	void Niveles(nodo<T> *p);
	
	//~le();
};



template <class T>
bool ArbolBinario<T>::Find(T bus, nodo<T>**& pos){
	for (pos = &root; *pos && (*pos) -> valor != bus ; pos = &((*pos) -> nodos[bus > (*pos) -> valor]));
	return *pos != 0;
}

template <class T>
bool ArbolBinario<T>::Insert(T valor){
	nodo<T> **p;
	if(Find(valor,p))
		return 0;
	*p = new nodo<T>(valor);
	return 1;
}



template <class T>
void ArbolBinario<T>::Niveles(nodo<T> *n){
	static nodo<T> * const limitador=nullptr;
	if ( !n ) return;
	queue<nodo<T> *> A;
	A.push(root);
	A.push(limitador);
	while(true){
		
		nodo<T> *temp = A.front();
		A.pop();
		if(temp != limitador){
			cout<< temp->valor<< " ";
			if(temp->nodos[0] != nullptr){
				A.push(temp->nodos[0]);
			}
			if(temp->nodos[1] != nullptr){
				A.push(temp->nodos[1]);
			}
		}
		else{
			cout<<endl<<endl;
			if(A.empty()){
				break;
			}
			A.push(limitador);
		}
	}
}

template <class T>
void ArbolBinario<T>::Menu(){
	
		Niveles(root);
		
}


int main() {
	ArbolBinario<int> t;
	
	for (int i=1;i<=10000;i++)
		t.Insert(rand() % 10000 + 1); 
	
	t.Menu();
	return 0;
}
