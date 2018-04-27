
template <typename T>
class PIDController {
public:
  T p, i, d, processMax, sum, sumMax, lastError, errorAvg;
  PIDController(T p = 0, T i = 0, T d = 0, T processMax = 0.5, T lastError = 0, T sum = 0, T sumMax = 1) : p(p), i(i), d(d), processMax(processMax), lastError(lastError), sum(sum), sumMax(sumMax), errorAvg(lastError) {};
  T process(T error, T time = 1) {
    T r = p * error;
    errorAvg = errorAvg * 0.9f + error * 0.1f;
    r += d * (lastError - errorAvg) / time;
    lastError = errorAvg;
    sum += i * error * time;
    if (sum > sumMax) sum = sumMax;
    else if (sum < -sumMax) sum = -sumMax;
    r += sum;
    if (r > processMax) r = processMax;
    else if (r < -processMax) r = -processMax;
    return r;
  }
};