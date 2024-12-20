#include <ostream>
#include <iostream>
#include <stdexcept>
#include <exception>
#include "List.h"

using namespace std;
template <typename T>
class ListArray : public List<T> {

	private:
		T* arr;
		int max; //longitud de vector (puede variar)
		int n; //num elementos del array
		static const int MINSIZE = 2;
		void resize(int new_size){
			if(new_size <= 0){
				throw invalid_argument("El tamaño del vector tiene que ser mayor que 0.\n");
			}
			if(new_size == max){
				return;
			}
			T* array = new T[new_size];
			for(int i = 0; i < max; i++){
				array[i] = arr[i];
			}
			delete[] arr;
			arr = array;
			max = new_size;

		}

	public:
		ListArray(){
			arr = new T[max];
			max = MINSIZE;
			n = 0;
		}			

		~ListArray(){
			delete[] arr;
		} 

		T operator[](int pos){
			if (pos < 0 || pos >= n){
				throw  out_of_range("Posición fuera de rango.\n");
			}
			return arr[pos];
		}

		friend ostream& operator<<(ostream &out, const ListArray<T> &list){
			out << "List => [ ";
			if(list.n == 0){
				out << "]";
			}else{
				for(int i = 0; i < list.n; i++){
					out << list.arr[i];
					if (i < list.n -1){
						out << "\n ";
					}
				}
				out << "\n]";
			}
			return out;
		}

		
		
		void insert(int pos, T e)override {
			if(pos < 0 || pos > n){
                throw out_of_range("La posicion no es valida");
        	}
        	if(n == max){
                resize(max == 0 ? 1 : 2*max);//si max 0, se cambia a 1
        	}
        	for(int i = n-1; i >= pos; i--){
                arr[i+1] = arr[i];
        	}
        	arr[pos]= e;
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
    		T x=arr[pos];
			for (int i = pos; i < n-1; i++){
				arr[i] = arr[i+1];
			}
			n--;
        	return x;
		}
	
		T get(int pos)override{
			if(pos < 0 || pos >= n){
            	throw out_of_range("La posicion no es valida");
        	}
        	T x=arr[pos];
        	return x;
		}
		int search(T e)override{
			int pos = 0;
			while (pos<=n){
            	if(arr[pos]==e){
                	return pos;
	        	}
            	else{
                	pos++;
			 	}
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
