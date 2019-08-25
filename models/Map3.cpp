using namespace std;

class Map{
public:
    Map(int Rows, int Collums){

        int ships[10] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
        int occupied_m[120]; // Pior caso o numero de casas ocupadas é 120
        int occupied_n[120]; // Então podemos definir isso como tamanho maximo do vetor

        for (int k = 0; k < ships.size(); K++){

            char type;
            switch(ships[k]){ // Definir o tipo de barco a ser posicionado
                case 1:
                    type = 'S';
                    break;
                case 2:
                    type = 'C'
                    break;
                case 3;
                    type = 'D'
                    break;
                case 4:
                    type = 'B'
                    break;
            }

            /* Antes do posicionamento, deve haver uma checagem para saber se há posições que o vetor pode
            ocupar baseando-se no tipo de vetor detectado acima*/

            // Definir as cordenadas m e n dentro do espaço de busca para o tipo de barco determinado
            int m = rand() % (Rows - ships[k]);
            int n = rand() % (Collums - ships[k]);

            // Redefinir m e n para o caso das coordenadas escolhidas estiverem ocupadas
            for (int w = 0; w < occupied_m.size(); w++){
                if (m == occupied_m[w] && n == occupied_n[w]){
                    m = rand() % (Rows - ships[k])
                    n = rand() % (Collums - ships[k])
                }
            }

        }

    }        
}