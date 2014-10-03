// New BSD License
_Pragma("once");

// you could use N from int (or enum) if you want stronger typing between different types
// example:
// typedef Primitive<double, 1> timeT;
// typedef Primitive<double, 2> volumeLevelT;
template <class T, int N = 0> class Primitive {
    typedef Primitive<T, N> X;
private:
    T value;
public:
    // conversion from T to X and vice versa
    Primitive(const T& rhs) : value(rhs) { }
    operator T () const { return value; }
    
#define ASSIGN_OPERATOR(oper) \
    X& operator oper(const X& rhs) { value oper rhs.value; return *this; } \
    template <class TT> X& operator oper(const TT& rhs) { value oper rhs; return *this; }
    ASSIGN_OPERATOR(+=);
    ASSIGN_OPERATOR(-=);
    ASSIGN_OPERATOR(*=);
    ASSIGN_OPERATOR(/=);
    ASSIGN_OPERATOR(%=);
    ASSIGN_OPERATOR(&=);
    ASSIGN_OPERATOR(|=);
    ASSIGN_OPERATOR(^=);
    ASSIGN_OPERATOR(<<=);
    ASSIGN_OPERATOR(>>=);
#undef ASSIGN_OPERATOR
    // compare
#define OPERATOR_WITH_2_OPERANDS(resT, oper) \
    friend resT operator oper(const X& lhs, const X& rhs) { return lhs.value oper rhs.value; } \
    template <class TT> friend resT operator oper(const TT& lhs, const X& rhs) { return lhs oper rhs.value; } \
    template <class TT> friend resT operator oper(const X& lhs, const TT& rhs) { return lhs.value oper rhs; }
    OPERATOR_WITH_2_OPERANDS(bool, ==);
    OPERATOR_WITH_2_OPERANDS(bool, !=);
    OPERATOR_WITH_2_OPERANDS(bool, >=);
    OPERATOR_WITH_2_OPERANDS(bool, <=);
    OPERATOR_WITH_2_OPERANDS(bool, > );
    OPERATOR_WITH_2_OPERANDS(bool, < );
    // two elements to result operators
    OPERATOR_WITH_2_OPERANDS(X, |);
    OPERATOR_WITH_2_OPERANDS(X, &);
    OPERATOR_WITH_2_OPERANDS(X, ^);
    OPERATOR_WITH_2_OPERANDS(X, +);
    OPERATOR_WITH_2_OPERANDS(X, -);
    OPERATOR_WITH_2_OPERANDS(X, *);
    OPERATOR_WITH_2_OPERANDS(X, /);
    OPERATOR_WITH_2_OPERANDS(X, %);
    OPERATOR_WITH_2_OPERANDS(X, <<);
    OPERATOR_WITH_2_OPERANDS(X, >>);
#undef OPERATOR_WITH_2_OPERANDS

    // prefix operators
#define PREFIX_OPERATOR(resT, oper) resT operator oper(void) const { return X(oper(value)); }
    PREFIX_OPERATOR(bool, !);
    PREFIX_OPERATOR(X, +);
    PREFIX_OPERATOR(X, -);
    PREFIX_OPERATOR(X, ~);
#undef PREFIX_OPERATOR

    // postfix, prefix increment & descrement
    const X& operator++(void) { ++value; return *this; }
    const X& operator--(void) { --value; return *this; }
    X operator++(int) { return X(value++); }
    X operator--(int) { return X(value--); }
};
