#include <iostream>




template <typename T>



class listStack { 

    public: 


        listStack() : head_(nullptr), size {0} {}

        ~listStack(){
        }

        //public API

        void push(T data){

            Node* newNode = new Node(data);

            if(head_ == nullptr){ 
                head_ = newNode;
                return;
            }

            newNode -> next = head_;
            head_ = newNode;            
        }

        void pop(){

            if(head_ == NULL){ 
                return;
            }


        }

        T& top(){}
        bool empty(){}
        std::size_t size() const;

    private: 

        struct Node {

            T data;
            Node* next;


            Node(T val)
        };

        Node* head_;
        std::size_t size_;
};


int main(){ 
    listStack<int>nums;

    for (int i = 0; i < 45; i++) { 
        nums.push(i);
    }
    nums.print();




}