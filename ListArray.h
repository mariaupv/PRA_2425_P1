#include <ostream>
#include <iostream>
#include "List.h"

using namespace std;
template <typename T>
class ListArray : public List<T> {

	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE = 2;
		void resize(int new_size){
			T* array = new T[new_size];
			for(int i = 0; i < n; i++){
				array[i] = arr[i];
			}
			delete[] arr;
			arr = array;
			max = new_size;
		}

	public:
		ListArray(){
			arr = new T[MINSIZE];
			max = MINSIZE;
			n = 0;
		}			

		~ListArray(){
			delete[] arr;
		} 

		T get(int pos){
			try{
				if (pos < 0 || pos >= n ){
					throw out_of_range("Fuera de rango");
				}
				return arr[pos]; 
			}catch(const out_of_range& e){
				cout << "Error: " << e.what() << endl;
			}
			return T();

		}	
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			for(int i = 0; i < list.n; i++){
				out << list.arr[i] << endl;
			}
			return out;
		}

};
