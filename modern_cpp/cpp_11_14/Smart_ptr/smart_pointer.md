### Smart_pointer related
#### Reference CS106L course reader

#### Possible interface
```cpp
template <typename T>
class Smart_pointer
{
public:
    explicit Smart_pointer(T* memory);
    Smart_pointer(const Smart_pointer& other);
    Smart_pointer& operator=(const Smart_pointer& other);
    ~Smart_pointer();

    T& operator*() const;
    T* operator->() const;
};
```

1. Why ctor explicit?
```cpp
// Ctor is not explicit
void PrintString(const Smart_pointer<string>& ptr) {
    cout << *ptr << endl; 
}

string* ptr = new string("Y");
PrintString(ptr);
// Make a temporary with Smart_pointer<string> with ptr, when the function returns the dtor of Smart_pointer invokes.
delete ptr; 
// Delete ptr a second time
```
2. Why Intermediary?
    - Reference count is shared across all Smart_pointers object that pointer to a particular resource thus making any changes to the reference count by on Smart_pointer visible in all of the other Smart_pointers referencing the resource.
    - Why not make the refCount a static data member?
      - This would make the reference count visible across multiple Smart_pointers
    - In conclusion, to use Smart_pointer to manage multiple resources, each one needs to have its own refCount and changes to the refCount for a partiular resource will show up in the refCount for other resources