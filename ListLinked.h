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
			this->n = n;
			first = nullptr;
		}

		~ListLinked(){
			while(first->next != nullptr){
			int aux = first->next;
			delete[] first->next;
			aux++;
			first->next = aux;
			}
		}


		T operator[] (int pos){
			if (pos < 0 || pos >= n){
				throw  out_of_range("Posición fuera de rango.\n");
			}
			return pos;
		}

		

		friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
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

		
};


