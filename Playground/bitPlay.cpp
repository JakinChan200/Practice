#include <bits/stdc++.h>

using namespace std;

typedef uint64_t board_t;
typedef uint16_t row_t;

static const board_t ROW_MASK = 0xFFFFULL;
static const board_t COL_MASK = 0x000F000F000F000FULL;

static inline void printBoard(board_t board){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            uint8_t power = board & 0xf;
            printf("%6u", (power == 0) ? 0 : 1 << power);
            board >>= 4;
        }
        printf("\n");
    }
    printf("\n");
}

static int count_empty(board_t x){
    if(x == 0){
        return 16;
    }

    //https://stackoverflow.com/questions/38225571/count-number-of-zero-nibbles-in-an-unsigned-64-bit-integer
    x |= (x >> 1);
    x |= (x >> 2);
    x = ~x & 0x1111111111111111ULL;

    x += x >> 32;
    x += x >> 16;
    x += x >>  8;
    x += x >>  4; 
    return x & 0xf;
}

static inline board_t unpack_col(row_t row) {
    board_t tmp = row;
    return (tmp | (tmp << 12ULL) | (tmp << 24ULL) | (tmp << 36ULL)) & COL_MASK;
}

int main(int argc, char** argv){
    board_t board = 0x123456789ABCDEFULL;
    printBoard(board);
    printBoard(unpack_col(board & 0xFFFFULL));

    // cout << "answer: " << countEmpty(board);
}