#include <bits/stdc++.h>

using namespace std;
const int N = 510;
const int M = 100010;

int n1; //左边有n1个点，右边有n2个点
int m;      //共有m条边
int h[N], e[M], ne[M], idx; //链式前向星

int match[N];   //右边点对应的左边哪个点
bool st[N];     //是不是已经匹配过
int res;        //记录结果数值，成功匹配的对数

//链式前向星建图
void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

/**
 * 功能：为每个男生找妹子
 * @param x
 * @return
 */
bool find(int x) {
    //枚举每一个看上的集合
    for (int i = h[x]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) { //如果没有考虑过
            //设置已处理过
            st[j] = true;
            //下面是经典的内容
            //j是当前相中的女生
            //match[j] == 0:如果j没有匹配过男生
            //find(match[j]):如果j的男朋友match[j]可以找其它女生
            if (match[j] == 0 || find(match[j])) {
                //设置女生j的男朋友是x,x逆袭成功！
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    //优化输入
    ios::sync_with_stdio(false);
    cin >> n1 >> m;
    //初始化邻接表
    memset(h, -1, sizeof h);
    //读入m条边建图
    while (m--) {
        int a, b;
        cin >> a >> b;
        //存的是左边指向右边,因为在代码中只找左边进行梳理，不会去遍历右边，所以只存一边
        //不必保存右边结点指向左边结点的边
        add(a, b);
    }
    //枚举左侧的每个点
    for (int i = 1; i <= n1; i++) {
        //表示后来的更牛，它看上的妹子，就会让其它人让出来，都是没有人选择过的状态！
        //就是本轮状态标识的作用，而不是全局状态标识
        memset(st, false, sizeof st);
        //如果有一个男生成功找到一个妹子，那么个数加1
        if (find(i)) res++;
    }
    //输出结果
    printf("%d\n", res);
    return 0;
}