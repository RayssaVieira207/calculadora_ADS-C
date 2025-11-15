#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>


using namespace std;

// Função para calcular o fatorial
unsigned long long factorial(int n) {
    if (n < 0) {
        cerr << "Erro: Fatorial nao definido para numeros negativos." << endl;
        exit(1); // Termina o programa indicando um erro
    }

    unsigned long long fat = 1;
    for (int i = 1; i <= n; ++i) {
        fat *= i;
    }
    return fat;
}

// Função para formatar o número com separadores de milhar no formato brasileiro.
string formatar_numero_pt_br(unsigned long long numero) {
    string numero_str = to_string(numero);
    string resultado = "";
    int contador = 0;

    for (int i = numero_str.length() - 1; i >= 0; i--) {
        resultado = numero_str[i] + resultado;
        contador++;

        if (contador == 3 && i != 0) {
            resultado = "." + resultado;
            contador = 0;
        }
    }

    return resultado;
}

int main() { 
    string name;
    double x, y, resultado;
    int n;
    char operacao;

    cout << "Calculadora ADS!" << endl;
    cout << "Digite seu nome: ";
    getline(cin, name);

    cout << "\n### OPERACOES DISPONIVEIS ###\n";
    cout << "SOMA (+)\n";
    cout << "SUBTRACAO (-)\n";
    cout << "MULTIPLICACAO (*)\n";
    cout << "DIVICAO (/)\n";
    cout << "POTENCIACAO (^)\n";
    cout << "RAIZ QUADRADA (r)\n";
    cout << "FATORIAL (!)\n";
    cout << "\n--> DIGITE SUA ESCOLHA: ";
    cin >> operacao;
    cout << endl;

    if (operacao == 'r') {
        // RAIZ QUADRADA
        cout << "Digite um numero: ";
        cin >> x;
        cout << endl;

        if (x < 0) {
            cout << "Erro: Nao existe raiz quadrada de numero negativo." << endl;
            return 1;
        } else {
            resultado = sqrt(x);
            cout << "A Raiz Quadrada de " << x << " e: " << resultado << endl;
        }

    } else if (operacao == '!') {

        // FATORIAL
        cout << "Digite um numero inteiro (nao negativo): ";
        cin >> n;
        unsigned long long fat = factorial(n);
        cout << "Fatorial de " << n << " e: " << formatar_numero_pt_br(fat) << endl;   
    
    } else if (operacao == '+' || operacao == '-' || operacao == '*' || operacao == '/' || operacao == '^') {
        // OPERACOES BINÁRIAS
        cout << "Digite o primeiro numero: ";
        cin >> x;
        cout << "Digite o segundo numero: ";
        cin >> y;
        cout << endl;

        switch(operacao) {
            case '+':
                resultado = x + y;
                cout << "A Soma dos numeros " << x << " e " << y << " e: " << resultado << endl;
                break;

            case '-':
                resultado = x - y;
                cout << "A Subtracao dos numeros " << x << " e " << y << " e: " << resultado << endl;
                break;

            case '*':
                resultado = x * y;
                cout << "A Multiplicacao dos numeros " << x << " e " << y << " e: " << resultado << endl;
                break;

            case '/':
                if (y == 0) {
                    cout << "Erro: Nao existe divisao por zero!" << endl;
                    return 1;
                } else {
                    resultado = x / y;
                    cout << "A Divisao dos numeros " << x << " e " << y << " e: " << resultado << endl;
                }
                break;

            case '^':
                resultado = pow(x, y);
                cout << x << " elevado a " << y << " e: " << resultado << endl;
                break;
        }

    } else {
        cout << "ERRO: Voce digitou uma operacao invalida!" << endl;
        return 1;
    }

    cout << "\nObrigado por usar a Calculadora ADS, " << name << "!" << endl;
    system("pause");
    return 0;
}
