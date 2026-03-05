#ifndef CP_TEST_H
#define CP_TEST_H

#include <string>

/**
 * @class Test
 * @brief 对 GCD 和 LCM 进行自动测试验证
 *
 * 每个测试用例包含：输入 a、输入 b、期望 GCD、期望 LCM。
 * 运行后输出每条用例的 PASS / FAIL，以及最终通过率汇总。
 */
class Test {
public:
    Test();

    // 运行全部测试用例，返回是否全部通过
    bool runAll();

private:
    int totalCases_;
    int passedCases_;

    // 单条测试：返回是否通过
    bool runCase(const std::string& label,
                 long long a, long long b,
                 long long expectedGcd, long long expectedLcm);

    // 测试异常是否正确抛出
    bool runExceptionCase(const std::string& label,
                          long long a, long long b);

    void printSummary() const;
};

#endif // CP_TEST_H