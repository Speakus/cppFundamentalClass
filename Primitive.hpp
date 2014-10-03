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
    
#define OPERATOR_FUNC_ASSIGN(oper) \
    X& operator oper(const X& rhs) { value oper rhs.value; return *this; } \
    template <class TT> X& operator oper(const TT& rhs) { value oper rhs; return *this; }
    OPERATOR_FUNC_ASSIGN(+=);
    OPERATOR_FUNC_ASSIGN(-=);
    OPERATOR_FUNC_ASSIGN(*=);
    OPERATOR_FUNC_ASSIGN(/=);
    OPERATOR_FUNC_ASSIGN(%=);
    OPERATOR_FUNC_ASSIGN(&=);
    OPERATOR_FUNC_ASSIGN(|=);
    OPERATOR_FUNC_ASSIGN(^=);
    OPERATOR_FUNC_ASSIGN(<<=);
    OPERATOR_FUNC_ASSIGN(>>=);
#undef OPERATOR_FUNC_ASSIGN
    // compare
#define OPERATOR_FUNC_2ARG(resT, oper) \
    friend resT operator oper(const X& lhs, const X& rhs) { return lhs.value oper rhs.value; } \
    template <class TT> friend resT operator oper(const TT& lhs, const X& rhs) { return lhs oper rhs.value; } \
    template <class TT> friend resT operator oper(const X& lhs, const TT& rhs) { return lhs.value oper rhs; }
    OPERATOR_FUNC_2ARG(bool, ==);
    OPERATOR_FUNC_2ARG(bool, !=);
    OPERATOR_FUNC_2ARG(bool, >=);
    OPERATOR_FUNC_2ARG(bool, <=);
    OPERATOR_FUNC_2ARG(bool, > );
    OPERATOR_FUNC_2ARG(bool, < );
    // two elements to result operators
    OPERATOR_FUNC_2ARG(X, |);
    OPERATOR_FUNC_2ARG(X, &);
    OPERATOR_FUNC_2ARG(X, ^);
    OPERATOR_FUNC_2ARG(X, +);
    OPERATOR_FUNC_2ARG(X, -);
    OPERATOR_FUNC_2ARG(X, *);
    OPERATOR_FUNC_2ARG(X, /);
    OPERATOR_FUNC_2ARG(X, %);
    OPERATOR_FUNC_2ARG(X, <<);
    OPERATOR_FUNC_2ARG(X, >>);
#undef OPERATOR_FUNC_2ARG

    // prefix operators
#define PREFIX_OPERATOR(oper) X operator oper(void) const { return oper(value); }
    PREFIX_OPERATOR(+);
    PREFIX_OPERATOR(-);
    PREFIX_OPERATOR(!);
    PREFIX_OPERATOR(~);
#undef OPERATOR_FUNC_0ARG

    // postfix, prefix increment & descrement
    const X& operator++(void) { ++value; return *this; }
    const X& operator--(void) { --value; return *this; }
    X operator++(int) { return X(value++); }
    X operator--(int) { return X(value--); }
};
