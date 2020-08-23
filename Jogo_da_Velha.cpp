#include <iostream>
#include <stdlib.h>
using namespace std;

/*
    programa jogo da velha prototipo
    Mateus da Silveira Batista - UFG
*/

typedef struct tabuleiro{
    char mat[3][3];
}tabuleiro;

void show(tabuleiro* x){
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            std::cout << " " << x->mat[i][j] << " ";
            if(j<2){
                std::cout << "|";
            }
        }
        if(i<2){
            std::cout << "\n--- --- ---\n";
        }
    }
    std::cout << std::endl;
}

void zera(tabuleiro* x){
    int i, j;

    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            x->mat[i][j] = ' ';
        }
    }

}

void chooses(){
    std::cout << std::endl;
    std::cout << " 1 | 2 | 3 \n";
    std::cout << "--- --- ---\n";
    std::cout << " 4 | 5 | 6 \n";
    std::cout << "--- --- ---\n";
    std::cout << " 7 | 8 | 9 \n";
    std::cout << std::endl;
}

int check_win(tabuleiro* x){
    int i;
    if(x->mat[0][0] == x->mat[1][1] && x->mat[1][1] == x->mat[2][2]){
        if(x->mat[0][0] != ' '){
            return(1);
        }
    }
    if(x->mat[0][2] == x->mat[1][1] && x->mat[1][1] == x->mat[2][0]){
        if(x->mat[0][2] != ' '){
            return(1);
        }
    }
    for(i=0; i<3; i++){
        if(x->mat[i][0] == x->mat[i][1] && x->mat[i][1] == x->mat[i][2]){
            if(x->mat[i][0] != ' '){
            return(1);
        }
        }
        if(x->mat[0][i] == x->mat[1][i] && x->mat[1][i] == x->mat[2][i]){
            if(x->mat[0][i] != ' '){
            return(1);
        }
        }
    }
    return(0);
}

int check_velha(tabuleiro* x){
    int i;
    int j;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(x->mat[i][j] != 'O' && x->mat[i][j] != 'X'){
                return(0);
            }
        }
    }
    return(1);
}

void place_x(tabuleiro* x, int num){
    while(num>9 || num <1){
        std::cout << "insira numero valido\n";
        std::cin >> num;
    }
        if(num == 1 && x->mat[0][0] == ' '){
            x->mat[0][0] = 'X';
        }
        else{
        if(num == 2 && x->mat[0][1] == ' '){
            x->mat[0][1] = 'X';
        }
        else{
        if(num == 3 && x->mat[0][2] == ' '){
            x->mat[0][2] = 'X';
        }
        else{
        if(num == 4 && x->mat[1][0] == ' '){
            x->mat[1][0] = 'X';
        }
        else{
        if(num == 5 && x->mat[1][1] == ' '){
            x->mat[1][1] = 'X';
        }
        else{
        if(num == 6 && x->mat[1][2] == ' '){
            x->mat[1][2] = 'X';
        }
        else{
        if(num == 7 && x->mat[2][0] == ' '){
            x->mat[2][0] = 'X';
        }
        else{
        if(num == 8 && x->mat[2][1] == ' '){
            x->mat[2][1] = 'X';
        }
        else{
        if(num == 9 && x->mat[2][2] == ' '){
            x->mat[2][2] = 'X';
        }
    else{
        std::cout << "Casa ja ocupada!!" << std::endl;
        std::cin >> num;
        place_x(x,num);
    }
        }
        }
        }
        }
        }
        }
        }
        }
}

void place_o(tabuleiro* x, int num){
    while(num>9 || num <1){
        std::cout << "insira numero valido\n";
        std::cin >> num;
    }
        if(num == 1 && x->mat[0][0] == ' '){
            x->mat[0][0] = 'O';
        }
        else{
        if(num == 2 && x->mat[0][1] == ' '){
            x->mat[0][1] = 'O';
        }
        else{
        if(num == 3 && x->mat[0][2] == ' '){
            x->mat[0][2] = 'O';
        }
        else{
        if(num == 4 && x->mat[1][0] == ' '){
            x->mat[1][0] = 'O';
        }
        else{
        if(num == 5 && x->mat[1][1] == ' '){
            x->mat[1][1] = 'O';
        }
        else{
        if(num == 6 && x->mat[1][2] == ' '){
            x->mat[1][2] = 'O';
        }
        else{
        if(num == 7 && x->mat[2][0] == ' '){
            x->mat[2][0] = 'O';
        }
        else{
        if(num == 8 && x->mat[2][1] == ' '){
            x->mat[2][1] = 'O';
        }
        else{
        if(num == 9 && x->mat[2][2] == ' '){
            x->mat[2][2] = 'O';
        }
        else{
            std::cout << "Casa ja ocupada!!" << std::endl;
            std::cin >> num;
            place_o(x,num);
        }
    }
    }
    }
    }
}
}
}
}
}

void play_x(tabuleiro* x){
    system("CLS");
    if(check_win(x) == 1 || check_velha(x) == 1){
        std::cout << "FIM DE JOGO!" << std::endl;
        show(x);
        return;
    }
    int number;

    show(x);
    std::cout << "jogador 1, escolha a posicao da peca com base no numero:" << std::endl;
    chooses();
    std::cin >> number;

    place_x(x,number);

    system("CLS");
    if(check_win(x) == 1 || check_velha(x) == 1){
        std::cout << "FIM DE JOGO!" << std::endl;
        show(x);
        return;
    }

    show(x);
    std::cout << "jogador 2, escolha a posicao da peca com base no numero:" << std::endl;
    chooses();
    std::cin >> number;
    place_o(x,number);

    play_x(x);
}

int main()
{
    tabuleiro A;
    zera(&A);
    cout << "---------JOGO DA VELHA---------" << endl;
    cout << "digite enter pra comecar" << endl;
    getchar();
    play_x(&A);
}
