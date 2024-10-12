#include <ostream>
using namespace std;

template <typename T>
class Node {
	public:
		T data;
		Node<T>* next;

		Node(T data, Node<T>*next=nullptr){
			this->data = data;
			this->next = next;

		}

		friend ostream& operator<<(ostream &out, const Node<T> &node){
			Node<T> aux = &node;
			while (aux != nullptr){
				out << aux->data;
				aux = aux->next;
				
				if(aux != nullptr){
					out << " ";
				}
			}
			return out;		
		
		}


};

