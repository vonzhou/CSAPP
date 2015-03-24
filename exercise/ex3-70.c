/*
 * 3.70
 *
 * $ gcc -m64 -S ex3-70.c # 生成 64 位的汇编代码
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
 * 递归计算二叉树中所有节点中的最小值
 */
long traverse(tree_ptr tp)
{
        if (!tp)
                return -1;

        long v = tp->val;
        long vleft = traverse(tp->left);
        long vright = traverse(tp->right);

        if (vright > vleft)
                vright = vleft;
        if (v > vright)
                v = vright;

        return v;
}
