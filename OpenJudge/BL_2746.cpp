#include <iostream>

using namespace std;

// 定义链表节点的结构
struct SNode {
    int data;
    SNode *next;
};

void JosephusList(int n, int m);

int Solve(int n, int m, SNode *queen);

int main() {
    int n, m;
    cin >> n >> m;

    // 循环读取n, m，直到他们为0, 0
    while (n && m) {
        JosephusList(n, m);
        cin >> n >> m;
    }

    return 0;
}

void JosephusList(int n, int m) {
    // 1只猴子，直接输出
    if (n == 1) {
        cout << "1" << endl;
        return;
    }

    // 报数为1，输出最后一只猴
    if (m == 1) {
        cout << n << endl;
        return;
    }

    SNode *queen;
    queen = new SNode;
    queen->data = 1;  // 第一只猴子编号为1
    queen->next = nullptr;  // 下一只为空

    // 初始化循环链表
    SNode *p = queen, *q;

    for (int i = 2; i <= n; ++i) {
        q = new SNode;
        q->data = i;  // 设置当前节点的data为其位置数
        q->next = nullptr;  // 将当前节点的下一节点初始化为空，确保该节点为最后一个节点
        p->next = q;  // 将新节点链接到循环列表中，使其成为当前节点的下一节点
        p = q;  // 将当前节点指针移到新创建的节点，以便构建下一次循环的节点
    }
    p->next = queen;  // 将最后一个节点指向头节点，形成循环链表

    cout << Solve(n, m, queen) << endl;
}

int Solve(int n, int m, SNode *queen) {
    SNode *t = queen, *p = queen;  // 初始化为循环链表的头节点

    // 迭代处理约瑟夫环，直到仅剩一个节点
    for (int i = 1; i < n; ++i) {

        // 模拟报数，找到需要删除的节点
        for (int j = 1; j < m; ++j) {
            t = p;  // 保存当前节点的前一节点，方便删除时使用
            p = p->next;  // 移动p指针，模拟报数
        }

        t->next = p->next;  // 更新链表连接，跨过出列的猴子
        delete p;  // 删除出列猴子
        p = t->next;  // 移动p指针到下一节点，继续模拟报数
    }

    // 返回最后的猴子编号
    return p->data;
}