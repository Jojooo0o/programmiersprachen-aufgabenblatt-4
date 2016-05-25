#ifndef BUW_LIST_HPP
#define BUW_LIST_HPP

#include <cstddef>

// List.hpp
template < typename T >
	struct List ;

template < typename T >
	struct ListNode

{
	ListNode () : m_value (), m_prev ( nullptr ), m_next ( nullptr ) {}
	ListNode ( T const & v, ListNode * prev, ListNode * next ): m_value ( v ), m_prev ( prev ), m_next ( next )
	{}
	T m_value ;
	ListNode * m_prev ;
	ListNode * m_next ;
};

template < typename T >
	struct ListIterator

{
	friend class List <T >;
// not implemented yet
private :
	ListNode <T>* m_node = nullptr ;
};

template < typename T >
	struct ListConstIterator
{
	friend class List <T >;
public :
// not implemented yet
private :
	ListNode <T>* m_node = nullptr ;
};

template < typename T >
class List
{
public :

//A1
	List<T> (): m_size(0), m_first(nullptr), m_last(nullptr) {} 

	bool empty() const{
		return m_first == nullptr && m_last == nullptr;
	}

	std::size_t size() const{
		return m_size;
	}

//A2
	void push_front(const T& value){
		++m_size;
		if(empty()){
			m_first = new ListNode <T>(value, nullptr, nullptr);
			m_last = m_first;
		}else{
			m_first->m_prev = new ListNode <T>(value, nullptr, m_first);
			m_first = m_first->m_prev;
		}
	}

	void push_back(const T& value){
		++m_size;
		if(empty()){
			m_first = new ListNode <T>(value, nullptr, nullptr);
			m_last = m_first;
		}else{
			m_last->m_next = new ListNode <T>(value, m_last, nullptr);
			m_last = m_last->m_next;
		}
	}
	void pop_front(){
		if(size() == 1){
			delete m_first;
			m_first = nullptr;
			m_last = nullptr;
			--m_size;
		} else if(!empty()){
			m_first = m_first->m_next;
			delete m_first->m_prev;
			--m_size;
			}
		}
	void pop_back(){
		if(size() == 1){
			delete m_first;
			m_first = nullptr;
			m_last = nullptr;
			--m_size;
		} else if(!empty()){
			m_last = m_last->m_prev;
			delete m_last->m_next;
			--m_size;
			}
		}

	T& front() const {
		return m_first->m_value;
	}
	T& back() const{
		return m_last->m_value;
	}

//A3
	void clear(){
		while(!empty()){
			pop_front();
		}
	}
	//Destruktor
	~List () {
		clear();
	}

//typedef
	typedef T value_type ;
	typedef T * pointer ;
	typedef const T * const_pointer ;
	typedef T & reference ;
	typedef const T & const_reference ;
	typedef ListIterator <T > iterator ;
	typedef ListConstIterator <T > const_iterator ;
	friend class ListIterator <T >;
	friend class ListConstIterator <T >;// not implemented yet
private :
	std :: size_t m_size = 0;
	ListNode <T >* m_first = nullptr ;
	ListNode <T >* m_last = nullptr ;
};


#endif