#ifndef RANDOM_H_
#define RANDOM_H_

#include <random>

template<typename F>
class UniformReal{
public:
    UniformReal(F, F, int);
    F operator () ();
private:
    std::uniform_real_distribution<F> dist_;
    std::mt19937 gen_;
};

template<typename F>
UniformReal<F>::UniformReal(F from, F to, int seed):dist_(from, to), gen_(seed){}

template<typename F>
F UniformReal<F>::operator () (){
    return dist_(gen_);
}

using UniformFloat = UniformReal<float>;

#endif // RANDOM_H_
