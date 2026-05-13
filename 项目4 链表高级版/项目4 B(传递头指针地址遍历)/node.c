#include "node.h"

/* 向链表尾部添加新节点
 * 参数：
 *   Phead - 指向头节点指针的指针（可以修改头节点）
 *   number - 要添加的数值
 */
void add(Node **Phead, int number)
{
    // 为新节点分配内存
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = number;  // 设置新节点的值
    p->next = NULL;     // 新节点是最后一个节点，next设为NULL
    
    Node *last = *Phead;  // 从头节点开始查找尾节点
    
    if (last == NULL)  // 如果链表为空
    {
        *Phead = p;  // 新节点成为头节点
    }
    else
    {
        // 遍历到链表末尾
        while (last->next)
        {
            last = last->next;
        }
        last->next = p;  // 将新节点连接到链表尾部
    }
}

/* 显示链表中所有节点的值
 * 参数：
 *   head - 链表头节点指针
 */
void show(Node *head)
{
    Node *p;  // 用于遍历链表的指针
    printf("现在的链表为:\n");
    
    // 遍历链表并打印每个节点的值
    for (p = head; p; p = p->next)
    {
        printf("%d ", p->value);
    }
    printf("\n");
}

/* 在链表中搜索指定值
 * 参数：
 *   head - 链表头节点指针
 *   num - 要搜索的数值
 * 返回值：
 *   找到返回1，未找到返回0
 */
int search(Node *head, int num)
{
    Node *p;           // 遍历指针
    int cnt = 0;       // 记录节点位置
    int isfound = 0;   // 是否找到的标志
    
    // 遍历链表查找目标值
    for (p = head; p; p = p->next)
    {
        cnt++;  // 位置计数
        
        if (p->value == num)  // 找到目标值
        {
            printf("找到了,是链表中的第%d个数\n", cnt);
            isfound = 1;  // 设置找到标志
            break;        // 找到后退出循环
        }
    }
    
    if (!isfound)  // 如果未找到
    {
        printf("没找到\n");
    }
    
    return isfound;  // 返回查找结果
}

/* 删除链表中第一个包含指定值的节点
 * 参数：
 *   Phead - 指向头节点指针的指针
 *   num - 要删除的数值
 */
void Delete(Node **Phead, int num)
{
    Node *p, *q = NULL;  // p:当前节点, q:前一个节点
    
    // 遍历链表查找要删除的节点
    for (p = *Phead; p; q = p, p = p->next)
    {
        if (p->value == num)  // 找到要删除的节点
        {
            if (q == NULL)  // 要删除的是头节点
            {
                *Phead = p->next;  // 更新头节点
            }
            else  // 要删除的是中间或尾部节点
            {
                q->next = p->next;  // 前一个节点跳过当前节点
            }
            
            free(p);  // 释放被删除节点的内存
            break;    // 只删除第一个匹配的节点
        }
    }
}

/* 在指定位置插入新节点
 * 参数：
 *   Phead - 指向头节点指针的指针
 *   num - 要插入的数值
 *   index - 插入位置（从1开始计数）
 */
void inserted(Node **Phead, int num, int index)
{
    //位置有效性检查
    if (index < 1) {
        printf("插入位置无效（必须≥1）\n");
        return;
    }
    
    // 创建新节点
    Node *p = (Node *)malloc(sizeof(Node));
    p->value = num;
    p->next = NULL;
    
    // 在头部插入（位置1）
    if (index == 1) {
        p->next = *Phead;  // 新节点指向原头节点
        *Phead = p;        // 更新头节点为新节点
        printf("已插入\n");
        return;  // 重要：插入完成后直接返回
    }
    
    // 在其他位置插入
    int pos = 1;            // 当前位置计数器
    Node *q1 = NULL;        // 前一个节点
    Node *q2 = *Phead;      // 当前节点
    
    // 遍历到插入位置的前一个节点
    while (q2 != NULL && pos < index) {
        q1 = q2;            // 保存前一个节点
        q2 = q2->next;      // 移动到下一个节点
        pos++;              // 位置计数
    }
    
    // 检查插入位置是否超出链表长度
    if (pos < index) {
        printf("插入位置超出链表长度\n");
        free(p);  // 释放已分配但未使用的新节点内存
        return;
    }
    
    // 执行插入操作
    q1->next = p;  // 前一个节点指向新节点
    p->next = q2;  // 新节点指向原来的当前节点
    printf("已插入\n");
}

/* 反转链表
 * 参数：
 *   Phead - 指向头节点指针的指针
 */
void reverse(Node **Phead)
{
    if (*Phead == NULL)  // 空链表直接返回
    {
        return;
    }
    
    Node *pre = NULL;    // 前一个节点（初始为NULL）
    Node *curr = *Phead; // 当前节点（从头节点开始）
    Node *next = NULL;   // 下一个节点
    
    // 遍历链表，逐个反转节点间的指针方向
    while (curr) {
        next = curr->next;  // 保存下一个节点
        curr->next = pre;   // 当前节点指向前一个节点（反转）
        pre = curr;         // 前一个节点移动到当前位置
        curr = next;        // 当前节点移动到下一个位置
    }
    
    *Phead = pre;  // 更新头节点为原链表的最后一个节点
}

/* 计算链表的长度
 * 参数：
 *   head - 链表头节点指针
 * 返回值：
 *   链表的节点个数
 */
int length(Node *head)
{
    int cnt = 0;  // 节点计数器
    Node *p;      // 遍历指针
    
    // 遍历链表并计数
    for (p = head; p; p = p->next) {
        cnt++;
    }
    
    return cnt;  // 返回节点总数
}

/* 释放链表所有节点的内存
 * 参数：
 *   Phead - 指向头节点指针的指针
 */
void Free(Node **Phead)
{
    Node *p;  // 用于遍历和临时存储节点指针
    
    // 遍历链表，逐个释放节点内存
    while (*Phead) {
        p = *Phead;           // 保存当前节点
        *Phead = (*Phead)->next;  // 头指针指向下一个节点
        free(p);              // 释放当前节点
    }
}
