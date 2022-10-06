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
if(empty()){ //case 1: list is empty
Item* back = new Item();
tail_ = back; 
head_ = back;
tail_->first = 0;
tail_->last = 1;
tail_->val[tail_->first] = val; 
}
else if(tail_->last != ARRSIZE){ //case 2: room at back
  tail_->val[tail_->last] = val;
  ++tail_->last;
}
else if(tail_->last == ARRSIZE){ //case 3: no room at back, make new Item
  Item* back = new Item();
  tail_->next = back;
  back->prev = tail_;
  tail_ = back;
  tail_->first = 0;
  tail_->last = 1; 
  tail_->val[tail_->first] = val;
}
++size_; //increase size
}

void ULListStr::pop_back(){
if(empty()){//case 1: if called on empty list
    return;
}
else if(head_ == tail_ && tail_->last - tail_->first == 1){//case 2: if there is only one node with one element
  head_ = nullptr;
  delete tail_;
  tail_ = nullptr;
}
else if(tail_->last - tail_->first == 1){//case 3: if popping back removes a node
Item* temp = new Item();
temp = tail_;
tail_ = tail_->prev;
tail_->next = nullptr;
delete temp;
}
else{ //case 4: if popping back just removes a number from array, just move tail pointer
--tail_->last;
}
--size_; //decrease size
}

void ULListStr::push_front(const std::string& val){
if(empty()){//case 1: list is empty
Item* front = new Item();
head_ = front; 
tail_ = front;
head_->first = ARRSIZE-1;
head_->last = ARRSIZE; 
head_->val[head_->first] = val;
}
else if(head_->first != 0){//case 2: there is room at front
  --head_->first;
  head_->val[head_->first] = val;
}
else if(head_->first == 0){//case 3: there is no room at front, make new node
  Item* front = new Item();
  front->next = head_;
  head_->prev = front;
  head_ = front;
  head_->first = ARRSIZE-1;
  head_->last = ARRSIZE; 
  head_->val[head_->first] = val;
}
++size_; //increment size
}

void ULListStr::pop_front(){
if(empty()){//case 1: if pop_front is called on empty list
  return; 
}
else if(head_->first == ARRSIZE-1 && head_->last == ARRSIZE){ //case 2: delete node
Item* temp = new Item();
temp = head_;
head_ = head_->next;
delete temp;
}
else{ //case 3: move first pointer
++head_->first;
}
--size_; //decrement size
}

std::string const & ULListStr::back() const{
return tail_->val[tail_->last-1]; //return the last value in array in tail Item
}

std::string const & ULListStr::front() const{
return head_->val[head_->first]; //return the first value in array in head Item
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

std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(empty()) return nullptr;
  Item* temp = head_;
  unsigned int counter = loc;
while(counter >= (temp->last - temp->first)){//keep moving to the next node until you reach the final node where the loc is
  counter -= (temp->last - temp->first);
  temp = temp->next;
  }
  return &(temp->val[temp->first + counter]); 
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
