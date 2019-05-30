#include <iostream>

/**
 * What is the meaning of const in a definition like this?
 */
class foobar
{
  public:
    operator int () const; /* the `this` pointer will become a pointer to a const object. */
    /**
     * So, the first method is called when the object is const,
     * and the second method is called when the object is not!
     */
    const char* foo() const;
    const char* foo(); // Whats the difference between these 2?
};

class MyClass {
  public:
    /* This is an error:
     *   `MyClass(): counter=0 {};`
     * the actual use of there oneline constructors has parantheses, 
     * basically defines a function to initialize the member var
     * (without explicit use of assignment).
     */
    MyClass(): counter(0) {};

    void foo() const {
      counter++;
      std::cout << "foo const " << counter << std::endl;
    }

    void bar() {
      counter++;
      std::cout << "bar, not const " << counter << std::endl;
    }

    void foobar() {
      counter++;
      std::cout << "foobar, not const " << counter << std::endl;
    }

    void foobar() const {
      counter++;
      std::cout << "foobar const " << counter << std::endl;
    }

  private:
    /* NOTE: mutable used here so that const pointer/reference to object can still modify */
    mutable int counter;
};

int main(){
  /**
   * If these both work then whats the point of any of this?
   * auto keyword was tricking me.  Don't use auto unless you already know the type.
   */
  /* `MyClass* mc = new MyClass();` is dynamic, returns a pointer, and then you use the `->`
   * `MyClass mc;` is static?? and then you use the `mc.<method_name>` syntax.
   * Does `MyClass mc; call the constructor?? */
  MyClass mc;
  std::cout << "Non-const calls: " << std::endl;
  for(int i=0; i<2; i++){
    mc.foo(); // Non-const instantiations.
    mc.bar(); // bar is const, can still use.
    mc.foobar(); // Non-const version overrides.
  }
  /* `const MyClass& mc2 = *mc;` Here the second star is required when mc was initialized dynamically.
   * Otherwise, if it is static, then we can get a reference to it without using the star... */
  const MyClass& mc2 = mc;
  std::cout << "\nConst calls: " << std::endl;
  for(int i=0; i<2; i++){
    mc2.foo();
    /* mc2.bar();
     * This line would produce an error, since the function was not marked const. */
    mc2.foobar();
  }

}
