#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdint>
#include <vector>

// Binary compatability for MS VC++ 11.0 / _MSC_VER=1700
// Iterator from https://gist.github.com/zzjjzzgggg/a5ce54673443411548b995f12b21c556
namespace MSVCBinCompat {
	template <typename T>
	struct vector {
	private:
		T * _start;
		T* _end;
		T* _cap;

	public:
		static const int DEFAULT_CAPACITY = 0;
		typedef size_t size_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;

		// forward iterator
		class iterator {
		public:
			typedef iterator self_type;
			typedef int difference_type;
			typedef std::forward_iterator_tag iterator_category;

			iterator() {}
			iterator(pointer ptr) : _ptr(ptr) { }

			self_type operator=(const self_type& other) { _ptr = other._ptr; return *this; }
			self_type operator++() { _ptr++; return *this; } // ++i
			self_type operator++(int junk) { self_type i = *this; _ptr++; return i; } // i++
			self_type operator--() { _ptr--; return *this; }
			self_type operator--(int junk) { self_type i = *this; _ptr--; return i; }
			reference operator*() { return *_ptr; }
			pointer operator->() { return _ptr; }
			bool operator==(const self_type& rhs) const { return _ptr == rhs._ptr; }
			bool operator!=(const self_type& rhs) const { return _ptr != rhs._ptr; }

		private:
			pointer _ptr;
		};

		// const forward iterator
		class const_iterator {
		public:
			typedef const_iterator self_type;
			typedef int difference_type;
			typedef std::forward_iterator_tag iterator_category;

			const_iterator() {}
			const_iterator(pointer ptr) : _ptr(ptr) { }

			self_type operator++() { _ptr++; return *this; }
			self_type operator++(int junk) { self_type i = *this; _ptr++; return i; }
			self_type operator--() { _ptr--; return *this; }
			self_type operator--(int junk) { self_type i = *this; _ptr--; return i; }
			const value_type& operator*() { return *_ptr; }
			const value_type* operator->() { return _ptr; }
			bool operator==(const self_type& rhs) const { return _ptr == rhs._ptr; }
			bool operator!=(const self_type& rhs) const { return _ptr != rhs._ptr; }

		private:
			pointer _ptr;
		};

		/* Constructors & Destructors start*/
		vector() {
			auto mem = (pointer)operator new(0);
			_start = mem;
			_end = mem;
			_cap = mem;

			reserve(DEFAULT_CAPACITY);
		}

		~vector() {
			if (_start != nullptr) {
				operator delete(_start);
			}
		}

		/* Constructors & Destructors end*/

		/* Element access methods start*/
		reference at(size_type pos) {
			if (pos > size()) {
				throw std::out_of_range("index out of bounds");
			}
			return operator[](pos);
		}

		reference operator [](size_type pos) {
			return _start[pos];
		}

		reference front() {
			return *begin();
		}

		reference back() {
			auto tmp = end();
			tmp--;
			return *tmp;
		}

		/* Element access methods end*/

		/* Iterators methods start*/
		iterator begin() {
			return iterator(_start);
		}

		iterator end() {
			return iterator(_end);
		}

		const_iterator begin() const {
			return const_iterator(_start);
		}

		const_iterator end() const {
			return const_iterator(_end);
		}
		/* Iterators methods end*/

		/* Capacity methods start*/
		bool empty() const {
			return begin() == end();
		}

		size_type size() const {
			return _end - _start;
		}

		size_type max_size() const {
			// Silly, theoretical max container size.
			return UINTPTR_MAX / sizeof(T);
		}

		void reserve(size_type new_cap) {
			if (new_cap <= capacity()) {
				return;
			}

			if (new_cap > max_size()) {
				throw std::length_error("new_cap > max_size()");
			}

			auto old_size = size();
			pointer new_backing = (pointer)operator new(sizeof(T)*new_cap);
			std::memcpy((void*)new_backing, (void*)_start, old_size * sizeof(T));

			operator delete(_start);

			_start = new_backing;
			_end = new_backing + old_size;
			_cap = new_backing + new_cap;
		}

		size_type capacity() const {
			return _cap - _start;
		}
		/* Capacity methods end*/

		/* Modifer methods start*/
		void push_back(const T& value) {
			if (capacity() == 0) {
				reserve(1);
			}
			else if (size() == capacity()) {
				reserve(capacity() * 2);
			}
			_start[size()] = value;
			_end++;
		}

		void pop_back() {
			if (size() > 0) {
				back().~T();
				_end--;
			}
		}
		/* Modifer methods end*/
	};
};