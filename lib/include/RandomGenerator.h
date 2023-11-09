#include <memory>
#include <random>

template<typename T, typename Distribution>
class RandomGenerator {
protected:
    std::unique_ptr<std::mt19937> p_gen_;
    std::unique_ptr<Distribution> p_dist_;

public:
    RandomGenerator(T min, T max) {
        std::random_device seed;
        p_gen_ = std::make_unique<std::mt19937>(seed());
        p_dist_ = std::make_unique<Distribution>(min, max);
    }

    T get() const {
        return (*p_dist_)(*p_gen_);
    }
};

class IntegerRandomGenerator : public RandomGenerator<int, std::uniform_int_distribution<>> {
public:
    using RandomGenerator::RandomGenerator;
};

class DoubleRandomGenerator : public RandomGenerator<double, std::uniform_real_distribution<>> {
public:
    using RandomGenerator::RandomGenerator;
};