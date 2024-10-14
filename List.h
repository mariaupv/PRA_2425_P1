#ifndef LIST_H
#define LIST_H

template <typename T>
class List{
	public:
		virtual void insert(int pos, T e) = 0 ; //inserta e en posición pos

		virtual void append(T e) = 0; //inserta e al final de la lista
		
		virtual void prepend(T e) = 0; //inserta e al principio de la lista

		virtual T remove (int pos) = 0; //delete y devuelve elem. situado en pos

		virtual T get(int pos) = 0; //devuelve elemento situado en pos

		virtual int search (T e) = 0; //devuelve pos cuando encuentra por primera vez e

		virtual bool empty() = 0; //indica si lista está vacía

		virtual int size() = 0; //devuelve num elementos lista
};

#endif
