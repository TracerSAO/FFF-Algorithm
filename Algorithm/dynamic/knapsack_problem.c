#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GOODSNUM 5
#define SIZENUM 4


/**
 * 测试用例 || PS：创建一个文件 "info.in" ，将以下数据存入，在通过 command 使用 xx.exe <info.in，就可以避免反复输入的尴尬🍺
 * a 3000 4
 * b 2000 3
 * c 1500 1
 * d 2000 1
*/
struct _nameNode {
    char value;
    struct nameNode * next;
};
typedef struct _nameNode nameNode;

struct _goodsNode {
    char name;
    int price;
    int size;
};
typedef struct _goodsNode goodsNode; 

struct _dataListNode {
    int price;
    nameNode * point;
};
typedef struct _dataListNode dataListNode;


nameNode * copy_nameNode(const nameNode * point);
void deBug_nameNodeList(const nameNode * nameList);
void deBug_dataListNode(const dataListNode (*dataList)[SIZENUM]);
void free_nameList(nameNode * list);
void free_nameNode(dataListNode (*dataList)[SIZENUM]);
int dynamic_KnapsackProblem(const goodsNode * goodsList, nameNode ** nameList);

int main()
{
    goodsNode goodsList[GOODSNUM];
    for (int i=0; i< GOODSNUM; i++) {
        scanf("%c %d %d", &(goodsList[i].name), &(goodsList[i].price), &(goodsList[i].size));
        getchar();      // 过滤 \n
    }

    for (int i=0; i< GOODSNUM; i++)
        printf("goodsList[%d]={ name:%c || price:%d || size:%d }\n", 
                i, goodsList[i].name, goodsList[i].price, goodsList[i].size);

    nameNode * nameList;
    int MAX = dynamic_KnapsackProblem(goodsList, &nameList);
    printf("The best answer:%d\n", MAX);

    deBug_nameNodeList(nameList);
    printf("\n");
    free_nameList(nameList);
    printf("Finally free() over...\n");

    return 0;
}

// 背包问题 - 动态规划解法
int dynamic_KnapsackProblem(const goodsNode * goodsList, nameNode ** nameList)       
{
    dataListNode dataList[2][SIZENUM];
    const int packSizeList[SIZENUM] = { 1, 2, 3, 4 };
    // 初始化二维数组
    // memset(dataList, 0, sizeof(dataList));
    for (int i=0; i<2; i++) {
        for (int j=0; j<SIZENUM; j++) {
            dataList[i][j].price = 0;
            dataList[i][j].point = NULL;
        }
    }

    // 使用 goodsList[0] 对象，对 dataList[0] 数组进行初始化
    for (int i=0; i<SIZENUM; i++) {
        if (packSizeList[i] < goodsList[0].size)
            continue;

        dataList[0][i].price = goodsList[0].price;
        nameNode * point = (nameNode*) malloc(sizeof(nameNode));    // 要记得及时 free() !!!
        point->value = goodsList[0].name;
        point->next = NULL;
        dataList[0][i].point = point;
    }

    deBug_dataListNode(dataList);

    // printf("sizeof(goodsList)=%ld  ||  sizeof(goodsNode)=%ld\n", sizeof(goodsList), sizeof(goodsNode));
    // printf("sizeof(goodsList) / sizeof(goodsNode)=%ld\n", sizeof(goodsList) / sizeof(goodsNode));
    // printf("sizeof(dataList[0]) / sizeof(dataListNode)=%ld\n\n", sizeof(dataList[0]) / sizeof(dataListNode));

    for (int goodsNumber=1; goodsNumber<GOODSNUM; goodsNumber++) {
        for (int packSize=0; packSize<SIZENUM; packSize++) {
            if (packSizeList[packSize] == goodsList[goodsNumber].size) {
                if (goodsList[goodsNumber].price > dataList[0][packSize].price) {
                    dataList[1][packSize].price = goodsList[goodsNumber].price;
                    // xxx
                    nameNode * point = (nameNode*) malloc(sizeof(nameNode));
                    point->value = goodsList[goodsNumber].name;
                    point->next = NULL;
                    dataList[1][packSize].point = point;
                }
                else  {     // < || =
                    dataList[1][packSize].price = dataList[0][packSize].price;
                    dataList[1][packSize].point = copy_nameNode(dataList[0][packSize].point);
                    // continue;
                }
            }
            else if (packSizeList[packSize] > goodsList[goodsNumber].size) {      // size: data... > goods...
                int _size = packSizeList[packSize] - goodsList[goodsNumber].size;       // 寻找帮手，看看它们合力是否可以战胜 dataList[0][packSize].price 
                // 检索帮手在 dataList[0] 数组中的位置，确定它的下标，方便召唤
                for (int i=0; i<SIZENUM; i++)
                    if (packSizeList[i] == _size) {
                        _size = i;
                        break;
                    }

                int sum = dataList[0][_size].price + goodsList[goodsNumber].price;
                if (sum > dataList[0][packSize].price) {
                    dataList[1][packSize].price = sum;
                    nameNode * xPoint = (nameNode*) malloc(sizeof(nameNode));
                    nameNode * yPoint = copy_nameNode(dataList[0][_size].point);
                    xPoint->value = goodsList[goodsNumber].name;
                    xPoint->next  = yPoint;
                    dataList[1][packSize].point = xPoint;
                }
                else {
                    dataList[1][packSize].price = dataList[0][packSize].price;
                    dataList[1][packSize].point = copy_nameNode(dataList[0][packSize].point);
                    // continue;
                }
            }
            else {  // (packSizeList[packSize] < goodsList[goodsNumber].size)
                dataList[1][packSize].price = dataList[0][packSize].price;
                dataList[1][packSize].point = copy_nameNode(dataList[0][packSize].point);
            }
        }

        deBug_dataListNode(dataList);
        free_nameNode(dataList);
        printf("No.%d free() Over...\n\n", goodsNumber);
    }

    (*nameList) = copy_nameNode(dataList[0][SIZENUM - 1].point);
    int temp = dataList[0][SIZENUM - 1].price;
    free_nameNode(dataList);

    return temp;
}

nameNode * copy_nameNode(const nameNode * point)
{
    nameNode * leftP, * rightP;
    nameNode *  x, * y;
    leftP = point;
    rightP = (nameNode*) malloc(sizeof(nameNode));
    rightP->next = NULL;
    y = rightP;

    while (1) {
        if (NULL == leftP)
            break;
        // 复刻 leftP 当前所指向节点的值
        x = (nameNode*) malloc(sizeof(nameNode));
        x->value = leftP->value;
        x->next = NULL;
        // 接收 x 中转指针指向的 "复刻节点"
        y->next = x;
        // ( y & leftP ) 指针移动，准备接收下一个复刻节点
        y = y->next;
        leftP = leftP->next;
    }

    y = rightP->next;
    free(rightP);   // 时刻小心内存泄漏！

    return y;
}

void deBug_nameNodeList(const nameNode * nameList)
{
    printf("- { ");
    nameNode * leftP, * rightP;
    leftP = rightP = nameList;
    while (1) {
        if (NULL == leftP)
            break;
        rightP = rightP->next;
        printf("%c ", leftP->value);
        // free(leftP);     // 想知道为什么这里使用了 free(leftP) 编译器也没有报错的原因吗？
                            // 看下面定义的的那个函数的参数的格式！！！
        leftP = rightP;
    }
    printf("}");
}

/**
 * 注意：这里的参数的格式！ 
 * constt dataListNode (*dataList)[SIZENUM]
 * 第一眼看上去，还挺像那回事儿——以为这是一个不被允许修改的变量，
 * 如果在函数中程序员定义了修改的操作，编译器便会报错，
 * 恩恩，这就是对这种 const 变量的一般认识
 * 
 * 下面，就要用这个例子来说明下，让我们以为 const 限定失效的操作
 * const dataListNode (*dataList)[SIZENUM]
 * 是一个 "指向 内部元素类型为const dataListNode，大小为 SIZENUM的数组的指针"
 * 简介：指针，指向一个数组（数组内部元素类型为 const dataListNode)
 * 
 * 恩恩，一切都是这么的美好，
 * 但是，dataListNode 是复合数据类型，内部含有指针，所以他可以指向其它内存空间、
 * 
 * 那么，我们刚才认为的 dataList 指针指向的内存空间无法修改是对的，
 * 但是，仅仅只是 dataList 指向的内存空间不可以修改，这个被指向的空间如果可以指向其它空间，
 * 那么，这个其它空间如果不是 const 类型（没被 const）修饰，那它就是可以修改的 ！！！
 * 
 * 以上，这些只想说明一点：const 只会修饰当前对象，无法作用到通过指针构建起关系的数据对象身上 
*/
void deBug_dataListNode(const dataListNode (*dataList)[SIZENUM])
{
    for (int row=0; row<2; row++) {
        printf("dataList[%d]: ", row);
        for (int packSize=0; packSize<SIZENUM; packSize++)
            printf("%4d ", dataList[row][packSize].price);
        printf("\t");
        for (int packSize=0; packSize<SIZENUM; packSize++) {
            deBug_nameNodeList(dataList[row][packSize].point);
            printf("  ");
        }
        printf("\n");
    }
    printf("\n");
}

// dataList 是指针，但是，是一个指向数组的指针，虽然说是指向一个多维数组，
// 但实际上，它还是一个只是指向一个一维数组的指针，
// 之所以可以在逻辑概念上可以指向多维数组，还是因为我们程序员的操控！
// 因为只要小心不越界，指针可以操控任意位置的内存空间 ！
// 最后：因为 dataList 本就是指向一维数组的指针，
// 所以 dataList + 1 = 当前地址 + sizeof(dataListNode) * SIZENUM !!!!
void free_nameNode(dataListNode (*dataList)[SIZENUM])   
{
    // dataList[1] 拷贝到 dataList[0] ，dataList[0] 删除
    for (int packSize=0; packSize<SIZENUM; packSize++) {
        // 第一步：释放 dataList[0] 中控制的手动申请的内存空间
        free_nameList(dataList[0][packSize].point);
        // 第二步：将 0 组的 price 全部赋值为 1 组的值
        //        将 1 组控制的手动申请的用于存储 goods name 的内存空间控制权，交给 0 组
        dataList[0][packSize] = dataList[1][packSize];
        // 第三步：初始化 1 数组
        dataList[1][packSize].price = 0;
        dataList[1][packSize].point = NULL;
    }
}

void free_nameList(nameNode * list)
{
    nameNode * leftP, * rightP;
    leftP = rightP = list;
    while (1) {
        if (NULL == leftP)
            break;
        rightP = rightP->next;
        free(leftP);
        leftP = rightP;
    }
}
