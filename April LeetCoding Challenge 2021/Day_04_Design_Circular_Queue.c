typedef struct {
    int capacity;
    int arr[1000];
    int start;
    int end;
} MyCircularQueue;

bool myCircularQueueIsFull(MyCircularQueue*);
bool myCircularQueueIsEmpty(MyCircularQueue*);
    
MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    obj->capacity = k;
    obj->start = -1;
    obj->end = -1;
    return obj;
}

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
  if(myCircularQueueIsFull(obj))
     return false;
   if(myCircularQueueIsEmpty(obj)){
       obj->start = 0;
       obj->end = 0;
   }
   else
        obj->end = (obj->end + 1)%obj->capacity;
    obj->arr[obj->end] = value;
    
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj))
    return false;
  if(obj->start == obj->end){
      obj->start = -1;
      obj->end = -1;
  }
  else
    obj->start = (obj->start+1)%obj->capacity;
  return true;
}

int myCircularQueueFront(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj))
    return -1;
  return obj->arr[obj->start];
}

int myCircularQueueRear(MyCircularQueue* obj) {
  if(myCircularQueueIsEmpty(obj))
    return -1;
  return obj->arr[obj->end];
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
  if((obj->start == obj->end) && obj->start == -1)
        return true;
   return false;
}

bool myCircularQueueIsFull(MyCircularQueue* obj) {
  if((obj->end + 1)%obj->capacity == obj->start)
    return true;
  return false;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/
