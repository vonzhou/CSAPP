/*
 * 3.69
 *
 * $ cc -m64 -S ex3-69.c # 使用 -m64 生成 64 位代码
 *
 * mofaph@gmail.com
 */

typedef struct ELE *tree_ptr;

struct ELE {
        tree_ptr left;
        tree_ptr right;
        long val;
};

/*
 * 这个函数用于找到二叉树的左子树的第一个叶子节点的 val
 *
 *                      o
 *                    /   \
 *                   o     o
 *                  / \   / \
 *                 o   o o   o
 *                 ^
 *                 |
 *            找到这个节点的值
 */
long trace(tree_ptr tp)
{
        long node = 0;

        while (tp) {
                node = tp->val;
                tp = tp->left;
        }

        return node;
}
