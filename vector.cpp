#include <iostream>
#include <numeric>


class Vector {
    
  private:
  int* data;
  size_t size; // current number of elements in the vector
  size_t capacity; //curent number of memory locations reserved by the vector
  
  
  
  //change the capacity of the vector, not the size. 
  void resize(size_t newCapacity) {
      // create new pointer
      int* newData = new int[newCapacity];
      
      //copy elements to new data
      for (size_t i = 0;i < size; ++i) {
          newData[i] = data[i];
      }
      
      //delete old data
      delete[] data;
      data = newData;
      
      //update capacity variable
      capacity = newCapacity;
  }
  
  
  public:
  Vector(): data(nullptr), size(0), capacity(0) {}
  
  
  ~Vector() {
      delete [] data;
  }
  
  
  Vector(const Vector& other): data(nullptr), size(0), capacity(other.GetCapacity()) {
      data = new int[capacity];
      for (size_t i = 0;i < other.GetSize(); ++i) {
          Pushback(other[i]);
      }
  }
  
  
  void Clear() {
      size = 0;
  }
  
  Vector& operator=(const Vector& other) {
      delete[] data;
      capacity = other.GetCapacity();
      size = 0;
      
      data = new int[capacity];
      for (size_t i = 0;i < other.GetSize(); ++i) {
          Pushback(other[i]);
      }
      return *this;
  }
  
  size_t GetSize() const {
      return size;
  }
  void SetSize(size_t newSize) {
      size = newSize;
  }
  
  
  int GetCapacity() const {
      return capacity;
  }
  
  bool IsEmpty() const {
      return size == 0;
  }
  
  
  //Pushback function
  void Pushback(int number) {
      //check that there exist space to add
      if (size == capacity) {
          //it is common to resize the Vector to twice its capacity
          int newCapacity = capacity * 2;
          if (newCapacity == 0 ) {
              newCapacity = 1;
          }
          
          resize(newCapacity);
      }
      //add the number to the end of the vector 
      data[size] = number;
      size++;
  }
  
  
  //popback function
 void Popback() {
     if (IsEmpty()) {
         std::cout << " Vector is empty!";
     } else {
         size--;
     }
 }
 
 
 
 //Addition
 Vector operator+(const Vector& other) const {
     //both vectors should have the same size
     Vector temp;
     size_t newSize = std::min(size, other.GetSize());
     
     for (size_t i =0; i < newSize; ++i) {
         temp.Pushback(data[i] + other[i]);
     }
     return temp;
     
 }
 
 //Subtraction
  Vector operator-(const Vector& other) const {
     //both vectors should have the same size
     Vector temp;
     size_t newSize = std::min(size, other.GetSize());
     
     for (size_t i =0; i < newSize; ++i) {
         temp.Pushback(data[i] - other[i]);
     }
     return temp;
 }
 
 //Multiplication by int
 Vector operator*(const int value) {
    Vector temp;
     for (size_t i =0; i < size; ++i) {
         temp.Pushback(data[i] * value);
     }
     return temp;
 }
 
 //Multiplication scalar product
 int operator*(const Vector& other) const {
     //both vectors should have the same size
     if (other.GetSize() != size) {
         std::cout << " different sizes can't be multiplied";
         return -1;
     }
     size_t newSize = size;
     int sum = 0;
     for (size_t i =0; i < newSize; ++i) {
         sum += (data[i] * other[i]);
     }
     return sum;
 }
 
 
 //Compound sum operator
 Vector& operator+=(const Vector& other) {
     size_t newSize = std::min(size, other.GetSize());
     size = newSize;
     for (size_t i = 0;i < size; ++i) {
         data[i] += other[i];
     }
     
     return *this;
 }
 
 
  //Compound subtractc operator
 Vector& operator-=(const Vector& other) {
     size_t newSize = std::min(size, other.GetSize());
     size = newSize;
     for (size_t i = 0;i < size; ++i) {
         data[i] -= other[i];
     }
     
     return *this;
 }
 
 //Compound Multiplication by value
 Vector& operator*=(const int& value) {
    
     for (size_t i = 0;i < size; ++i) {
         data[i] *= value;
     }
     return *this;
 }
 
 
 
  
  
  //index operator
  const int& operator[](size_t index) const  {
      if (index >= size) {
          std::cout << "index out of range! ";
      }
      return data[index];
  }
  
  
  
  friend std::ostream& operator<<(std::ostream& os, const Vector& vector)  {
      os << "[";
      size_t i = 0;
      for (i = 0 ;i < vector.GetSize() - 1; ++i) {
          os << vector[i] << ", ";
      }
      os << vector[i] << "]";
      return os;
  }
  
  
  
  friend std::istream& operator>>(std::istream& is, Vector& vector) {
      // first you read the total number of elements n, then we expect n consecutive integers to fill the Vector
      vector.Clear();
      int nElements;
      int number;
      is >> nElements;
      for (int i = 0; i < nElements; ++i ) {
          is >> number;
          vector.Pushback(number);
      }
      return is;
  }
};



int main() {
    Vector vec;
    vec.Pushback(5);
    vec.Pushback(34);
    vec.Pushback(-12);
    std::cout << vec << "\n";
    vec.Popback();
    std::cout << vec << "\n";
    Vector v2(vec);
    std::cout << v2 << "\n";
    std::cout << vec + v2 << "\n";
    vec = v2;
    std::cout << vec << "\n";
    
    std::cout << vec*3 << "\n";
    
    std::cout << vec*v2 << "\n";
    
    Vector v4, v5;
    std::cin>>v4 >> v5;
    v4 += v5;
    v4 *= 10;
    std::cout << v4;
    
   
    return 0;
}