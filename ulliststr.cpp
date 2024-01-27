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
  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_back(const std::string& val) {
    if (tail_ == NULL || tail_->last == ARRSIZE) { // if tail isnt null or if
      Item* temp = new Item;

      if (head_ == NULL) { // if list is empty , point to new node
        head_ = temp;
      }
      
      else {
        tail_->next = temp; // if not link, new node to tail and and the new node to the prev
        temp->prev = tail_;
      }

      tail_ = temp; // update tail to new node
    }

    tail_->val[tail_->last] = val; // add value of array into current tail node
    tail_->last++; // increment index of new element
    size_++; // increment size of list
    
  } 


  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back() {
    if (size_ == 0) { // check if list is empty
      return;
    }

    tail_->last--; // decrement the index of last element
    size_--; // decrement size

    if (tail_->last == tail_->first) { // check if tail node is empty

      Item* temp = tail_; // temp pointer
      tail_ = tail_->prev; // update tail pointer
      delete temp;

      if (tail_ != NULL) { // if theres still a tail node, update its pointer
        tail_->next = NULL;
      } 

      else {
        head_ = NULL;
      }

    }
  }


  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
  void ULListStr::push_front(const std::string& val) {
    if (head_ == NULL || head_->first == 0) {
      
      Item* temp = new Item; // create a new item
      
      if (head_ != NULL) {
        head_->prev = temp; // if list isnt empty, link new item with head
        temp->next = head_;
      }
     
      head_ = temp; // make new item head of hte list
      head_->first = ARRSIZE; // make first and last ARRSIZE as well be adding to front
      head_->last = ARRSIZE;
      
      if (tail_ == NULL) { // if list is empty, set tail to new item
        tail_ = temp;
     }

    }
    
    head_->first--; // decrement the first index
    head_->val[head_->first] = val; // assign the new value
    size_++; // increment list size
  }


  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front() {
    if (size_ == 0) { // check if list is empty
      return;
    }
    head_->first++; // increment first index in head to "pop"
    size_--; // decrement size of list

    if (head_->first == head_->last) {
      Item* temp = new Item; //temp pointer
      temp = head_;
      head_ = head_->next; // move head to next pointer in list
      delete temp;

      if (head_ != NULL) { // check if list isn't empty
        head_->prev = NULL;
      } 
      else {
        tail_ = NULL; // if empty set tail to null as well 
      }
    }
  }

  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::back() const {
    return tail_->val[tail_->last - 1]; 
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  std::string const & ULListStr::front() const {
    return head_->val[head_->first];
  }

  
  /** 
   * Returns a pointer to the item at index, loc,
   *  if loc is valid and NULL otherwise
   *   - MUST RUN in O(n) 
   */
  std::string* ULListStr::getValAtLoc(size_t loc) const {
    if (loc >= size_) {
        return nullptr;
    }

    for (Item* temp = head_; temp != nullptr; temp = temp->next) { // iterate over each item
        size_t segmentSize = temp->last - temp->first; // calculate size of the current segment
        if (loc < segmentSize) { // check if loc is in segment
            return &temp->val[temp->first + loc]; // return the location
        }
        loc -= segmentSize; // decrement loc by size of segment
    }
    return nullptr;
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
