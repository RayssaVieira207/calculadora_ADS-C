#include <iostream>
#include <string>
#include <cmath>

using namespace std;

unsigned long long fatorial(int k)
{
    if (k < 0)
    {
        cout << "Não tem fatorial de negativo." << endl;
        return 0;
    }
    unsigned long long fat = 1;

    //REPETIÇÃO DETERMINADA PARA CALCULAR O FATORIAL
    for(int i = 1; i <= k; i++){
        fat *= i;
    }
    return fat;

}

int main()
{
    string name;
    double x, y, resultado;
    //float k;
    int n,fator;
    char option;

    cout << "Calculadora ADS" << endl;
    cout << "Informe o seu nome: ";
    getline(cin, name);

    //ABAIXO TEMOS O MENU DA APLICAÇÃO
    cout << " " << endl;
    cout << "Bem vindo: " << name << endl;
    cout << " ##### OPERACOES DISPONIVEIS #####" << endl;
    cout << " + (SOMA) " << endl;
    cout << " - (SUBTRACAO) " << endl;
    cout << " * (MULTIPLICACAO) " << endl;
    cout << " / (DIVISAO) " << endl;
    cout << " ^ (POTENCIA) " << endl;
    cout << " r (RAIZ QUADRADA) " << endl;
    cout << " ! (FATORIAL) " << endl;
    cout << "\n ----->Digite a sua escolha: ";
    cin >> option;

    if(option == 'r')
    {
        cout << "Digite o numero: ";
        cin >> x;
        if (x < 0)
        {
            cout << "Erro: seu abestado nao existe raiz de negativo..." << endl;
            return 1;
        }else
        {
            resultado =  sqrt(x);
            cout << "A raiz quadrada de " << x << " e: " << resultado << endl;
        }
    }else if (option == '!')
    {
        cout << "Digite o Numero do Fatorial: ";
        cin >> n;
        fator = fatorial(n);
        cout << "Fatorial eh: " << fator << endl;
        
    }else
    {
        switch(option)
        {
            case '+':
                cout << "Digite o primeiro numero: ";
                cin >> x;
    
                cout << "Digite o segundo numero: ";
                cin >> y;
                resultado = x + y;
                cout << "A soma dos numeros e: " << resultado << endl;
                break;
            case '-':
                cout << "Digite o primeiro numero: ";
                cin >> x;

                cout << "Digite o segundo numero: ";
                cin >> y;
                resultado = x - y;
                cout << "A subtracao dos numeros e: " << resultado << endl;
                break;
            case '*':
                cout << "Digite o primeiro numero: ";
                cin >> x;
    
                cout << "Digite o segundo numero: ";
                cin >> y;    
                resultado = x * y;
                cout << "A multiplicacao dos numeros e: " << resultado << endl;
                break;
            case '/':
                cout << "Digite o primeiro numero: ";
                cin >> x;

                cout << "Digite o segundo numero: ";
                cin >> y;
                
                if (y == 0)
                {
                    cout << "Erro: seu animal nao existe divisao por zero..." << endl;
                    return 1;
                }else
                {
                    resultado = x / y;
                    cout << "A Divisao dos numeros e: " << resultado << endl;
                }
                break;
            case '^':
                cout << "Digite o primeiro numero: ";
                cin >> x;
    
                cout << "Digite o segundo numero: ";
                cin >> y;    
                resultado = pow(x,y);
                cout << "A potencia de " << x << " elevado a " << y << " e: " << resultado << endl;
                break;
            default:
                cout << "Erro: voce digitou M..." << endl;
                return 1;    
        }
    }
    system("pause");
    return 0;
}

   