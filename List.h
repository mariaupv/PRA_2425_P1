#ifndef LIST_H
#define LIST_H

template <typename T>
class List{
	public:
		void insert(int pos, T e); //inserta e en posición pos

		void append(T e); //inserta e al final de la lista
		
		void prepend(T e); //inserta e al principio de la lista

		T remove (int pos); //delete y devuelve elem. situado en pos

		T get(int pos); //devuelve elemento situado en pos

		int search (T e); //devuelve pos encuentra primera vez e

		bool empty(); //indica si lista está vacía

		int size(); //devuelve num elementos lista
};

#endif
