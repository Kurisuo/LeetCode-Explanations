#include <iostream>

template<typename T>

//implementing a array stack with dynamic sizing



class arrayStack {

    public:
        //constructor

        arrayStack() {
            size_ = 0;
            capacity_ = 1;
            arr_ = new T[capacity];
        }

        ~arrayStack() { 
            delete[] arr_;
        }

        //public API functions

        void push(const T& value){
            //check for full
            if (size_ == capacity_){
                resize(capacity_ * 2);
            }

            arr_[size++] = value;
        }

        void pop(){
            //check if empty
            if (size_ == 0) {
                return;
            }
            size--;
        }

        std::size_t getSize() const{
            return size_;
        }
        
        //mutable
        T& top(){
            if(size_ == 0) {return;}
            return arr_[size_ - 1];
        }

        //const
        const T& top() const {
            if(size_ == 0) {return;}
            return arr_[size_ - 1];
        }

    private: 
        T* arr;
        std::size_t size_;
        std::size_t capacity_;

        void resize(std::size_t newCapacity){
            T* newArr = new T[newCapacity];
            for(std::size_t x = 0; x < size_; x++){
                newArr[x] = arr_[x];
            }

            delete[] arr_;
            arr_ = newArr;
            capacity_ = newCapacity;
        }
};