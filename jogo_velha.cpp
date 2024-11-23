#include <iostream>
using namespace std;

// Função para desenhar o tabuleiro
void drawBoard(char board[3][3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "--|---|--\n";
    }
    cout << "\n";
}

// Função para verificar se alguém venceu
char checkWinner(char board[3][3]) {
    // Verificar linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
            return board[0][i];
    }
    // Verificar diagonais
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
        return board[0][2];
    return ' '; // Sem vencedor
}

// Função principal
int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    char currentPlayer = 'X';
    int moves = 0;
    bool gameRunning = true;

    cout << "Bem-vindo ao Jogo da Velha!\n";
    drawBoard(board);

    while (gameRunning && moves < 9) {
        int row, col;

        // Solicitar jogada do jogador atual
        cout << "Jogador " << currentPlayer << ", insira a linha e a coluna (0-2) separadas por espaço: ";
        cin >> row >> col;

        // Verificar se a posição é válida
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = currentPlayer;
            moves++;
            drawBoard(board);

            // Verificar vencedor
            char winner = checkWinner(board);
            if (winner != ' ') {
                cout << "Parabéns! O jogador " << winner << " venceu!\n";
                gameRunning = false;
            }

            // Alternar jogador
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Jogada inválida. Tente novamente.\n";
        }
    }

    if (moves == 9 && gameRunning) {
        cout << "Empate! Nenhum vencedor.\n";
    }

    return 0;
}
