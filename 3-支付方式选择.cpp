#include <iostream>
#include <string>
#include <cssert>
#include <algorithm>  //包含min/max找最大最小函数
using namespace std;

class Payment
{
protected:
    string username;

public:
    Payment(const string& name)
        :username(name){ }

<<<<<<< HEAD
    virtual bool pay(double amount) = 0;
=======
    virtual bool pay(double amount) = 0;    //bool函数的目的是判断支付是否成功，可以自行添加条件，做一些合法性检验之类的
>>>>>>> de4b07df7282cd9c9756ed79e3873a37d2bf6551
    virtual double getFee(double amount) = 0;

};

//微信支付类
class WeChatPay :public Payment
{
public:
    WeChatPay(const string& name)
        :Payment(name){ }
    double getFee(double amount) override
    {
        if (amount <= 1000)
            return 0;
        else
            return (amount * 0.001);
    }
    bool pay(double amount)
    {
        double fee = getFee(amount);
        double sum = amount + fee;
        cout << "微信支付：从账户[ " << username << " ]扣除[ " << sum << " ]" << endl;;
        return true;
    }
};

// 支付宝支付类
class AliPay : public Payment 
{
private:
    bool isNewUser;
    bool theFirst;    //标记是否为第一笔订单
public:
    AliPay(const string& name, bool newUser) 
        : Payment(name), isNewUser(newUser), theFirst(true) { } //这里的isNewUser函数接收主函数传的true

    double getFee(double amount) override 
    {
        if (isNewUser && theFirst) 
        {
            theFirst = false;
            return 0;
        }
        return amount * 0.0005;
    }
    bool pay(double amount) override 
    {
        double fee = getFee(amount);
        double total = amount + fee;
        cout << "支付宝支付：实际支付 [" << total << "]" << endl;
        return true;
    }
};

//银行卡支付类
class BankCardPay : public Payment 
{
private:
    int coupon;
public:
    BankCardPay(const string& name, int coup)
        : Payment(name), coupon(coup) { }
    double getFee(double amount) override
    {
        double fee = amount * 0.003;
        int discount = min(coupon, 10); // 最多抵扣10元
        return max(0.0, fee - discount);
    }
    bool pay(double amount) override
    {
        double fee = amount * 0.003;
        int discount = min(coupon, 10);
        double actualFee = max(0.0, fee - discount);
        double total = amount + actualFee;
        cout << "银行卡支付：扣除 [" << total << "]" << endl;
        return true;
    }
};



int main() 
{
    //初始化支付方式    
    Payment* payments[] = {

        new WeChatPay("wx_123456"),

        new AliPay("zfb_654321", true),          

        new BankCardPay("card_7890", 8)      
    };
    const int PAY_COUNT = sizeof(payments) / sizeof(payments[0]);

    // 模拟订单    
    double orders[] = { 500, 1500, 2000 };
    const int ORDER_COUNT = sizeof(orders) / sizeof(orders[0]);

    // 处理订单    
    for (int i = 0; i < ORDER_COUNT; i++)
    {
        cout << "\n=== 订单" << i + 1 << "（金额：" << orders[i] << "元）===" << endl;
        for (int j = 0; j < PAY_COUNT; ++j) {
            cout << "[" << j + 1 << "] ";
            payments[j]->pay(orders[i]);
        }

    }

    // 释放资源
    for (int i = 0; i < PAY_COUNT; i++) 
    {
        delete payments[i];
    }

    return 0;
}

