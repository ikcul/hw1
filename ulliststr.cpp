#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val){
  if (empty()){
    head_ = new Item();
    tail_ = head_;
    tail_->next = nullptr;
    head_->first = 0;
    head_->last = 1;
    head_->val[0] = val;
  }else if (tail_->last < ARRSIZE){
    tail_->val[tail_->last] = val;
    tail_->last++;
  }else{
    Item* newNode = new Item();
    tail_->next = newNode;
    newNode->prev = tail_;
    tail_ = newNode;
    tail_->first = 0;
    tail_->last = 1;
    tail_->val[0] = val;
  }
  size_++;
}

void ULListStr::pop_back(){
  if (empty()){
    return;
  }else{
    size_--;
    tail_->last--;
    if (tail_->first == tail_->last){
      if (tail_ == head_){
        delete tail_;
        head_ = nullptr;
        tail_ = nullptr;
        return;
      }
      Item* temp = tail_;
      tail_ = tail_->prev;
      delete temp;
      tail_->next = nullptr;
    }
  }
}

void ULListStr::push_front(const std::string& val){
  if (empty()){
    head_ = new Item();
    tail_ = head_;
    tail_->next = nullptr;
    head_->first = 0;
    head_->last = 1;
    head_->val[0] = val;
  }else if(head_->first > 0){
    head_->first--;
    head_->val[head_->first] = val;
  }else {
    Item* temp = new Item();
    temp->first = ARRSIZE-1;
    temp->last = ARRSIZE;
    temp->val[ARRSIZE-1] = val;
    temp->next = head_;
    temp->prev = nullptr;
    head_->prev = temp;
    head_ = temp;
  }
  size_++;
}

void ULListStr::pop_front(){
  if (empty()){
    return;
  }
  else{
    size_--;
    head_->first++;
    if (head_->first == head_->last){
      if (tail_ == head_){
        delete head_;
        head_ = nullptr;
        tail_ = nullptr;
        return;
      }
      Item* temp = head_;
      head_ = head_->next;
      delete temp;
      head_->prev = nullptr;
    }
  }
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last - 1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if (empty() || loc >= size_){
    return nullptr;
  }else {
    Item* temp = head_;
    size_t count = 0;
    while(temp != nullptr){
      for (size_t i = temp->first; i < temp->last; i++){
        if (count == loc){
          return &temp->val[i];
        }
        count++;
      }
      temp = temp->next;
    }
    return nullptr;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
