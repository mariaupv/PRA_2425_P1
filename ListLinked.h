#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

	private:
		Node<T>* first;
		int n;

	public:
		ListLinked(){
			n = 0;
			first = nullptr;
		}

		~ListLinked(){
			Node<T>* aux = first;
			while(aux != nullptr){
				Node<T>* next = aux->next;
				delete aux;
				aux = next;
			}
		}


		T operator[] (int pos){
			if (pos < 0 || pos >= n){
				throw  out_of_range("Posición fuera de rango.\n");
			}
			Node<T>* aux = first; // Puntero para recorrer la lista
        	for (int i = 0; i < pos; i++) {
           		aux = aux->next; // Avanzar al siguiente nodo
        	}
        return aux->data;
		}

		

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
			out << "List => [ ";
			if(list.n == 0){
				out << "]";
			}else{
				Node<T>* aux = list.first;
				while(aux != nullptr){
					out << "\n\t" << aux->data;
					aux = aux ->next;
					if(aux != nullptr){
						out << " ";
					}
				
				}
				out << "\n";
			}
			out << "]";
			return out;
		}

		void insert(int pos, T e)override {
			if(pos < 0 || pos > n){
                throw out_of_range("La posicion no es valida");
        	}
        	Node<T>* newNode = new Node<T> (e);
			if(pos == 0){
				newNode->next = first;
				first = newNode;
				
			}else{
				Node<T>* aux = first;
				for(int i = 0; i < pos-1; i++){
					aux = aux->next;
				}
				newNode->next = aux->next;
				aux->next = newNode;
									
			}
			n++;
		}

		void append(T e)override{
			insert(n,e);
		}
	
		void prepend(T e)override{
			insert(0,e);
		}

		T remove(int pos)override{
			if(pos < 0 || pos > n-1){
            	throw out_of_range("La posicion no es valida");
        	}

			
			T num;
			if(pos == 0){
				Node<T>* aux = first;
				first = first->next;
				num = aux->data; //Guarda el valor de pos en num
				delete aux;
				
			}else{
				Node<T>* prev = first;
				for(int i = 0; i < pos-1; i++){
					prev = prev->next;
				}
				Node<T>* aux = prev->next;
				prev->next = aux->next;
				num = aux->data;
				delete aux;
									
			}
			n--;
        	return num;
		}
	
		T get(int pos)override{
			Node<T>* aux = first;
			int i = 0;
			T valor;
			if(pos < 0 || pos >= n){
            	throw out_of_range("La posicion no es valida");
        	}
        	while(aux != nullptr && i < pos){
				aux = aux->next;
				i++;
			}
			valor = aux->data;
        	return valor;
		}

		int search(T e)override{
			int pos = 0;
			Node<T>* aux = first;
			while (aux != nullptr ){
            	if(aux->data==e){
                	return pos;
	        	}
				aux = aux->next;
            	pos++;
			 	
        	}
        	return -1;
		}

		bool empty()override{
			return n==0;
		}
		int size()override{
			return n;
		}
		
};


