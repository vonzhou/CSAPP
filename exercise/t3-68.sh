#!/bin/sh

# 测试家庭作业 3.68
# mofaph@gmail.com

extern_file=ex3-68
test_file=t3-68
suffix=c

# 自动生成一个测试文件
cat <<EOF >${test_file}.${suffix}
/* NOTE!!! This is auto generate by a shell script */

extern int good_echo(void);

int main(void)
{
        int ret;
        ret = good_echo();
        return ret;
}
EOF

# 编译
cc ${test_file}.${suffix} ${extern_file}.${suffix} -o ${test_file}

# 产生数据以测试
printf "hel\n" | ./${test_file}         # 正常输入
printf "\0" | ./${test_file}            # 正常输入，但只有一个文件结束符
printf "Barcelona" | ./${test_file} # 非法输入

exit $?
