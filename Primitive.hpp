// New BSD License
_Pragma("once");

#define OPERATOR_FUNC_2ARG(res, oper) \
    friend res operator oper(const X& lhs, const X&rhs) { return lhs.value oper rhs.value; } \
    template <class TT> friend res operator oper(const TT& lhs, const X&rhs) { return lhs oper rhs.value; } \
    template <class TT> friend res operator oper(const X& lhs, const TT&rhs) { return lhs.value oper rhs; }
#define OPERATOR_FUNC_ASSIGN(oper) \
    X& operator oper(const X& rhs) { value oper rhs.value; return *this; } \
    template <class TT> X& operator oper(const TT& rhs) { value oper rhs; return *this; }
#define OPERATOR_FUNC_0ARG(res, oper) \
    res operator oper(void) const { return oper(value); }

template <class T> class Primitive {
    typedef Primitive<T> X;
private:
    T value;
public:
    // conversion from T to X and vice versa
    Primitive(const T& rhs) : value(rhs) { }
    operator T () const { return value; }
    
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
    // compare
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

    // prefix operators
    OPERATOR_FUNC_0ARG(X, +);
    OPERATOR_FUNC_0ARG(X, -);
    OPERATOR_FUNC_0ARG(X, !);
    OPERATOR_FUNC_0ARG(X, ~);
    OPERATOR_FUNC_0ARG(X&, ++);
    OPERATOR_FUNC_0ARG(X&, --);

    // postfix increment & descrement
    X operator++(int) { return value++; }
    X operator--(int) { return value--; }
};

#undef OPERATOR_FUNC_0ARG
#undef OPERATOR_FUNC_2ARG
#undef OPERATOR_FUNC_ASSIGN
