/*
 * @lc app=leetcode.cn id=299 lang=c
 *
 * [299] 猜数字游戏
 *
 * https://leetcode.cn/problems/bulls-and-cows/description/
 *
 * algorithms
 * Medium (57.29%)
 * Likes:    279
 * Dislikes: 0
 * Total Accepted:    79.5K
 * Total Submissions: 138.7K
 * Testcase Example:  '"1807"\n"7810"'
 *
 * 你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：
 * 
 * 写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，
 * 你就会给他一个包含下述信息的提示：
 * 
 * 
 * 猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
 * 有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，
 * 这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
 * 
 * 
 * 给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。
 * 
 * 提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。
 * 
 * 请注意秘密数字和朋友猜测的数字都可能含有重复数字。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：secret = "1807", guess = "7810"
 * 输出："1A3B"
 * 解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
 * "1807"
 * ⁠ |
 * "7810"
 * 
 * 示例 2：
 * 
 * 
 * 输入：secret = "1123", guess = "0111"
 * 输出："1A1B"
 * 解释：数字和位置都对（公牛）用 '|' 连接，数字猜对位置不对（奶牛）的采用斜体加粗标识。
 * "1123"        "1123"
 * ⁠ |      or     |
 * "0111"        "0111"
 * 注意，两个不匹配的 1 中，只有一个会算作奶牛（数字猜对位置不对）。通过重新排列非公牛数字，其中仅有一个 1 可以成为公牛数字。
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= secret.length, guess.length <= 1000
 * secret.length == guess.length
 * secret 和 guess 仅由数字组成
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>

// @lc code=start

#define MIN(a, b) ((a) > (b) ? (b) : (a))

/*
 * 公牛和奶牛的统计方式不一样
 *
 * 对于公牛
 * 如果 secret[i] == guess[i]，即公牛的数量加一
 *
 * 对于奶牛
 * 维护两个长度为 10 的数组，用来分别统计两个
 * 字符串中非公牛的数字的数量
 * 因为 guess 中多余的数字无法转化为奶牛，所以
 * 应该两个数组中每个数字的最小值加起来，就是
 * 奶牛的数量了
 *
 */
char * getHint(char *secret, char *guess)
{
        int bull = 0;
        int cow = 0;

        int secret_cnt[10] = {0};
        int guess_cnt[10] = {0};

        for (int i = 0; secret[i] != '\0'; i++) {
                if (secret[i] == guess[i]) {
                        bull++;
                        continue;
                }

                secret_cnt[secret[i] - '0']++;
                guess_cnt[guess[i] - '0']++;
        }

        for (int i = 0; i < 10; i++)
                cow += MIN(secret_cnt[i], guess_cnt[i]);

        // guess 和 secret 的长度为 1000，则公牛或者奶牛的
        // 数量最多不超过 1000
        char *result = malloc(sizeof(char) * 10);
        sprintf(result, "%dA%dB", bull, cow);

        return result;
}
// @lc code=end


