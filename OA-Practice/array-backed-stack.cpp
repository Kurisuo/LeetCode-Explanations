#include <iostream> 

template <typename T>

//LIFO - Last in First Out 

class arrayStack { 

    public: 

        arrayStack() {
            capacity_ = 1 ;
            size_ = 0; 
            data_ = new T[capacity_];

        }

        ~arrayStack() {
            delete[] data_;
        }

        //push value
        void push(const T& val) { 
            //check if full
            if (size_ == capacity_){ 
                resize(capacity_ * 2);
            }

            //move cursor
            data_[size_++] = val;
        }
        
        
        void pop() {
            //check if empty 
            if (size_ == 0) {
                return;
            }

            --size_; 
        } 
        
        T& top() {
            return data_[size_ - 1];
        }

        const T& top() const {
            return data_[size_ - 1];
        }

        bool isEmpty() const {
            return size_ == 0;
        }

        bool isFull() const { 
            return size_ == capacity_;
        }

        std::size_t getSize() const {
            return size_;
        }

    private: 
        T* data_;
        std::size_t size_;
        std::size_t capacity_;

        void resize(std::size_t newCap) { 
            T* newData_ = new T[newCap];
            
            for (std::size_t x = 0; x < size_; x++){ 
                newData_[x] = data_[x];
            }

            delete[] data_;
            data_ = newData_;
            capacity_ = newCap;
        }

    };


int main(){ 
    arrayStack<int> stack;

    for (int i = 0; i < 50; i++) {
        stack.push(i);
    }

    std::cout << "size: " << stack.getSize() << "\n";        // expect 50
    std::cout << "top:  " << stack.top() << "\n";            // expect 49

    while (!stack.isEmpty()) {
        stack.pop();
    }
    std::cout << "size after pop all: " << stack.getSize() << "\n";  // expect 0

    return 0;
}