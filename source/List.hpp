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
	struct ListConstIterator
{
	friend class List <T >;
public :
// not implemented yet
private :
	ListNode <T>* m_node = nullptr ;
};
//A4
template <typename T>
struct ListIterator
{
	typedef ListIterator<T>Self;

	typedef T value_type;
	typedef T* pointer;
	typedef T& reference;
	typedef ptrdiff_t difference_type;
	typedef std::forward_iterator_tag iterator_category;

	friend class List<T>;

	ListIterator() : m_node(nullptr){}
	ListIterator(ListNode<T>* n) : m_node(n){}
	reference operator*() const {
		return m_node->m_value;
	}
	pointer operator->() const {
		return *m_node;
	}
	ListNode<T>* get_node () const {return m_node;} //get m_node


	Self& operator ++() {
		*this = next(); //setze iterator auf naechstes element
		return *this;
		}

	Self& operator++(int counter) {
		while(counter != 0){
			*this = next();
			counter--;
		}
		return *this;
	}
	bool operator==(const Self& x) const {
		return (m_node == x.m_node);
	}
	bool operator!=(const Self& x) const {
		return (m_node != x.m_node);
	}
	Self next() const
	{
		if (m_node)
			return ListIterator(m_node->m_next);
		else
			return ListIterator(nullptr);
	}
private:
	ListNode<T>* m_node = nullptr;
};

template < typename T >
class List
{
public :

//typedef
	typedef T value_type ;
	typedef T * pointer ;
	typedef const T * const_pointer ;
	typedef T & reference ;
	typedef const T & const_reference ;
	typedef ListIterator <T> iterator ;
	typedef ListConstIterator <T > const_iterator ;
	friend class ListIterator <T >;
	friend class ListConstIterator <T >;// not implemented yet

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

	T const& front() const {
		return m_first->m_value;
	}
	T const& back() const{
		return m_last->m_value;
	}

	T& front(){
		return m_first->m_value;
	}
	T& back(){
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

//A5
	iterator begin() const{ //Begin von der List
		return ListIterator<T>(m_first);
	}

	iterator end() const{ //Versuch 1
		return ListIterator<T> ();
	}

//A7
	List<T> (List<T> const& list): m_size(0), m_first(nullptr), m_last(nullptr) {
		for(iterator it = list.begin(); it != list.end(); ++it){
			push_back(*it);
		}
	}

//A8
	void insert(iterator const& it, T const& value){
		ListNode<T>* node = new ListNode<T>(value, nullptr, nullptr);
		ListNode<T>* prev = it.get_node()->m_prev;
		ListNode<T>* next = it.get_node();
		node->m_prev = prev;
		prev->m_next = node;
		node->m_next = next;
		next->m_prev = node;
	}

//A9
	void reverse() {
		auto help2 = m_first;
		m_first = m_last;
		m_last = help2;
		for(auto it = begin(); it != end(); ++it){
			auto node = it.get_node();
			auto help = node->m_prev;
			node->m_prev = node->m_next;
			node->m_next = help;
		}
		
	}

//A12
	List<T> (List<T>&& rhs) : m_size(rhs.m_size), m_first(rhs.m_first), m_last(rhs.m_last){
		rhs.m_size = 0;
		rhs.m_first = nullptr;
		rhs.m_last = nullptr;
	}

	List<T>& operator = (List<T>&& list){
		std::swap(m_size, list.m_size);
		std::swap(m_first, list.m_first);
		std::swap(m_last, list.m_last);
	}


private :
	std :: size_t m_size = 0;
	ListNode <T >* m_first = nullptr ;
	ListNode <T >* m_last = nullptr ;
};

//A6
	template<typename T>
	bool operator== (List<T> const& xs, List<T> const& ys){
	ListIterator<T> yit = ys.begin(); //VIterator zum durchgehen beider Listen
	bool same = true;
	for(ListIterator<T> xit = xs.begin(); xit != xs.end(); ++xit){//Listendurchgang für liste xs
		if(*xit != *yit){//Vergleich der Listen
			same = false;
		}
		++yit;
	}
	return same;
	};

	template<typename T>
	bool operator!= (List<T> const& xs, List<T> const& ys){
	ListIterator<T> yit = ys.begin(); //VIterator zum durchgehen beider Listen
	bool same = false;
	for(ListIterator<T> xit = xs.begin(); xit != xs.end(); ++xit){//Listendurchgang für liste xs
		if(*xit != *yit){//Vergleich der Listen
			same = true;
		}
		++yit;
	}
	return same;
	};

	template<typename T>
	List<T> reverse(List<T> const& list){
		List<T> list2;
		for(auto it = list.begin(); it != list.end(); ++it){
			list2.push_front(*it);
		}
		return list2;
	}

#endif