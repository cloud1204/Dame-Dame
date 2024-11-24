# ダメダメ!

This problem is used in IONC 2023 Day3 practice contest.

## Problem Statement

已知小春的「糟糕字眼筆記本」包含了 $m$ 個長度為 $3$ 的糟糕字串 $s_1,s_2,s_3,...,s_n$。在和她透過訊息聊天的過程中，你必須非常小心的斟酌字句，否則假如你發出來的訊息中的**子序列**包含至少一個糟糕字串，就會被她封鎖! 舉例來說，假如其中一個糟糕字串是 $abc$ ，那不只是 $dabce$ ，連 $adbec$ 這樣的訊息小春都會覺得很糟糕，於是把你封鎖。

現在，你突然很好奇假如亂敲鍵盤一通就送出訊息，被小春封鎖的機率是多少。為了方便計算，你假設你敲出來的字串長度為 $n$，由前 $n$個小寫字母組成，而且每個字母都恰好出現一次。請計算 $n!$ 種可能性中有多少種字串會讓你被小春封鎖。

請注意，基於一些精神錯亂的理由，小春的「糟糕字眼筆記本」**可能會包含重複的字串**。


## Input Format

* line $1$: $\ \ n\ \ m$
* line $1+i$ ($1 \le i \le m$): $\ \ s_i$

## Output Format

* line $1$: $\ \ ans$

## Constraints

- $3 \le n \le 20$。
- $1 \le m \le 10000$。
- $|s_i|=3$。
- $s_i$ 只包含前 $n$ 個小寫英文字母，並保證每個字串中的 $3$ 個字母相異。


## Example

### Example Input 1

```
4 3
abc
bcd
acd
```

該範例輸入符合全部子任務的限制。

### Example Output 1

```
9
```
以下為所有會害你被封鎖的字串：
$abcd$
$abdc$
$acbd$
$acdb$
$adbc$
$bacd$
$bcad$
$bcda$
$dabc$
