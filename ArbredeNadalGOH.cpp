#include <iostream>
#include <string>

using namespace std;

/// <summary>
/// Void per dibuixar un arbre piramidal sense adorns.
/// </summary>
/// <param name="level">Planta actual de l'arbre per l'alcada.</param>
/// <param name="height">Alcada total de l'arbre.</param>
/// <param name="c">Lletra o numero que s'utilitzarà per dibuixar el cos de l'arbre.</param>
void drawTree(int level, int height, char c) {
    if (level > 0)
        drawTree(level - 1, height, c);
    cout << string(height - level, ' ') << string((2 * level) + 1, c) << endl;
}

/// <summary>
/// Void que dibuixa els adorns a l'arbre.
/// </summary>
/// <param name="level">Planta actual de l'arbre per l'alcada.</param>
/// <param name="height">Alcada total de l'arbre.</param>
void drawAdorns(int level, int height) {
    char cTree2;
    int cos;

    for (int i = 0; i < (2 * level) + 1; i++) {
        cos = rand() % 10;
        if (cos >= 0 && cos <= 7) cTree2 = '*';// Aquesta part d'aqui posa els decorats entre el cos de l'arbre.
        else if (cos == 8) cTree2 = '+';
        else cTree2 = 'O';
        cout << cTree2;
    }
}

/// <summary>
/// Void que dibuixa el tronc de l'arbre.
/// </summary>
void drawTronc() {
    for (int j = 0; j < 4; j++) {
        cout << "   *************" << endl; // Posant un espai en blanc era la manera per fer que el tronc quedes centrat.
    }
}

/// <summary>
/// Void que dibuixa l'arbre amb tronc.
/// </summary>
/// <param name="level">Planta actual de l'arbre per l'alcada.</param>
/// <param name="height">Alcada total de l'arbre.</param>
/// <param name="cTree2">Lletra o numero que s'utilitzarà per dibuixar el cos de l'arbre.</param>
void drawTree2(int level, int height, char cTree2) {
    if (level > 0) {
        drawTree2(level - 1, height, cTree2);
    }
    cout << string(height - level, ' ');
    drawAdorns(level, height);
    cout << endl;
}

/// <summary>
/// Part principal del codi on l'usuari respon.
/// </summary>
/// <returns>Quan el codi acaba d'executar-se dona el resultat de 0 per acabar.</returns>
int main() {
    char cTree = '*';
    int iSize;
    char cTree2 = '*';

    cout << "**** Creador d'Arbres de Nadal, serveix per crear dos arbres de Nadal personalitzats al teu gust. ****" << endl;
    cout << "Introdueix el tamany que vols per els teus arbres:";
    cin >> iSize;
    cout << "Introdueix el caracter a utilitzar per crear els arbres:";
    cin >> cTree;
    drawTree(iSize, iSize, cTree);
    cout << "Ara dibuixarem el segon arbre:" << endl;
    drawTree2(iSize, iSize, cTree2);
    drawTronc();

    return 0;
}