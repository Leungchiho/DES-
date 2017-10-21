#include <string>
#include <iostream>
#include <bitset>
using namespace std;


int IP_table[] = {58, 50, 42, 34, 26, 18, 10, 2,
              60, 52, 44, 36, 28, 20, 12, 4,
              62, 54, 46, 38, 30, 22, 14, 6,
              64, 56, 48, 40, 32, 24, 16, 8,
              57, 49, 41, 33, 25, 17, 9,  1,
              59, 51, 43, 35, 27, 19, 11, 3,
              61, 53, 45, 37, 29, 21, 13, 5,
              63, 55, 47, 39, 31, 23, 15, 7
            };


int IP_table_1[] = {40, 8, 48, 16, 56, 24, 64, 32,
                39, 7, 47, 15, 55, 23, 63, 31,
                38, 6, 46, 14, 54, 22, 62, 30,
                37, 5, 45, 13, 53, 21, 61, 29,
                36, 4, 44, 12, 52, 20, 60, 28,
                35, 3, 43, 11, 51, 19, 59, 27,
                34, 2, 42, 10, 50, 18, 58, 26,
                33, 1, 41,  9, 49, 17, 57, 25
              };


int E[] = {32, 1,  2,  3,  4,  5,
             4,  5,  6,  7,  8,  9,
             8,  9,  10, 11, 12, 13,
             12, 13, 14, 15, 16, 17,
             16, 17, 18, 19, 20, 21,
             20, 21, 22, 23, 24, 25,
             24, 25, 26, 27, 28, 29,
             28, 29, 30, 31, 32,  1
            };


int PC_1[] = {57, 49, 41, 33, 25, 17, 9,
                1,  58, 50, 42, 34, 26, 18,
                10, 2,  59, 51, 43, 35, 27,
                19, 11, 3,  60, 52, 44, 36,
                63, 55, 47, 39, 31, 23, 15,
                7,  62, 54, 46, 38, 30, 22,
                14, 6,  61, 53, 45, 37, 29,
                21, 13, 5,  28, 20, 12, 4
               };


int PC_2[] = {14, 17, 11, 24, 1,  5,
                3,  28, 15,  6, 21, 10,
                23, 19, 12,  4, 26, 8,
                16, 7,  27, 20, 13, 2,
                41, 52, 31, 37, 47, 55,
                30, 40, 51, 45, 33, 48,
                44, 49, 39, 56, 34, 53,
                46, 42, 50, 36, 29, 32
              };


int S_BOX[8][4][16] = {
  {
    {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
    {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
    {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
    {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}
  },
  {
    {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
    {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
    {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
    {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}
  },
  {
    {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
    {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
    {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
    {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}
  },
  {
    {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
    {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
    {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
    {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14}
  },
  {
    {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
    {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
    {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
    {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}
  },
  {
    {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
    {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
    {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
    {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}
  },
  {
    {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
    {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
    {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
    {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}
  },
  {
    {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
    {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
    {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
    {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}
  }
};

// 在第0, 1, 8, 15轮左右部分左移1位，其他轮左移2位
int shift_left[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int P[] = {16,  7, 20, 21,
             29, 12, 28, 17,
             1, 15, 23, 26,
             5, 18, 31, 10,
             2,  8, 24, 14,
             32, 27,  3,  9,
             19, 13, 30,  6,
             22, 11,  4, 25
            };

bitset<64> IP(bitset<64> in) {
  bitset<64> out;
  for (int i = 0; i < 64; i++) {
    out[63 - i] = in[64 - IP_table[i]];
  }
  return out;
}

bitset<64> IP_1(bitset<64> in) {
  bitset<64> out;
  for (int i = 0; i < 64; i++) {
    out[63 - i] = in[64 - IP_table_1[i]];
  }
  return out;
}

//轮函数
bitset<32> feistel(bitset<32> R, bitset<48> ki) {
  bitset<48> E_out, temp;
  bitset<32> out(0x00000000);

  //E扩展
  for(int i = 0; i < 48; i++) {
    E_out[47 - i] = R[32 - E[i]];
  }

  //异或
  temp = E_out ^ ki;

  //把temp分成8组6位二进制数，通过S盒，转化为8组4位二进制数
  for(int i = 0; i < 48; i += 6) {
    //第1和6位
    int row = temp[47-i]<<1 + temp[47-i-5];
    //中间4位
    int col = (temp[47-i-1]<<3) + (temp[47-i-2]<<2) + (temp[47-i-3]<<1) + (temp[47-i-4]);
    bitset<4> a(S_BOX[i/6][row][col]);
    for (int j = 0; j < 4; j++) {
        out[j] = out[j] | a[j];
    }
    out <<= 4;
  }

  // P置换
  bitset<32> tmp = out;
  for(int i = 0; i < 32; i++) {
    out[31-i] = tmp[32-P[i]];
  }

  return out;
}


//16次迭代, 解密flag为0，加密flag为1
bitset<64> iteration_16(bitset<64> afterIP, bitset<48> *k, bool flag) {
  bitset<64> out;
  bitset<32> L, R, temp;

  //L0, R0
  for(int i = 0; i < 32; i++) {
    R[i] = afterIP[i];
    L[i] = afterIP[i + 32];
  }

  //迭代16次，区分加密和解密
  for(int i = 0; i < 16; i++) {
    temp = R;
    R = (flag == 1 ? L ^ feistel(R, k[i]) : L ^ feistel(R, k[15 - i]));
    L = temp;
  }

  //最后一次要把L、R交换再输出
  for(int i = 0; i < 32; i++) {
    out[i] = L[i];
    out[i + 32] = R[i];
  }

  return out;
}

void getKey(bitset<64> key64, bitset<48> *k) {
  bitset<56> key, temp;
  bitset<28> C, D;

  //PC_1置换
  for (int i = 0; i < 56; i++) {
    key[55 - i] = key64[64 - PC_1[i]];
  }

  //得到C0,D0
  for (int i = 0; i < 28; i++) {
    D[i] = key[i];
    C[i] = key[i + 28];
  }

  //得到16个48位子密钥
  for (int i = 0; i < 16; i++) {
    //16次循环移位
    for (int jjj = 0; jjj < shift_left[i]; jjj++) {
        if (1 == C[27]) {
          C <<= 1;
          C.set(0);
        } else {
          C <<= 1;
        }
        if (1 == D[27]) {
          D <<= 1;
          D.set(0);
        } else {
          D <<= 1;
        }
    }
    //拼成56位的temp
    for (int j = 0; j < 28; j++) {
      temp[j] = D[j];
      temp[j + 28] = C[j];
    }
     //压缩置换PC_2，输出48位子密钥
    for (int j = 0; j < 48; j++) {
      k[i][47 - j] = temp[56 - PC_2[j]];
    }
  }
}

bitset<64> encrypt(bitset<64> ClearText, bitset<48> *k) {
  bitset<64> ciphertext, IP_out, iteration_out;
  IP_out = IP(ClearText);
  iteration_out = iteration_16(IP_out, k, true);
  ciphertext = IP_1(iteration_out);
  return ciphertext;
}

bitset<64> decrypt(bitset<64> ciphertext, bitset<48> *k) {
  bitset<64> ClearText, IP_out, iteration_out;
  IP_out = IP(ciphertext);
  iteration_out = iteration_16(IP_out, k, false);
  ClearText = IP_1(iteration_out);
  return ClearText;
}

int main() {
  bitset<64> ClearText(0x000f), key(0x0001), ciphertext;
  bitset<48> k[16];
  getKey(key, k);
  ciphertext = encrypt(ClearText, k);
  cout << "明文：" << ClearText << endl;
  cout << "密钥：" << key << endl;
  cout << "密文：" <<ciphertext << endl;
  cout << "经恢复的明文如下：\n      " <<decrypt(ciphertext, k) << endl;
  return 0;
}
