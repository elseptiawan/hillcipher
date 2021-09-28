#include <iostream>
#define clear system("cls")
using namespace std;

int input_matriks(int ordo, int key[][3])
{
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            cout << "Key [" << i + 1 << "][" << j + 1 << "] :";
            cin >> key[i][j];
        }
    }
    return key[ordo][ordo];
}

void swap(int &var1, int &var2)
{
    int temp;
    temp = var1;
    var1 = var2;
    var2 = temp;
}

void enkripsi(int ordo, int key[][3], string plaintext)
{
    if (ordo == 2)
    {
        string ciphertext = "";
        bool huruf1, huruf2;
        int mp[2][1];
        int length = plaintext.length();
        if (length % 2 != 0)
        {
            plaintext += 'x';
        }
        for (int i = 0; i < length; i++)
        {
            if (i % 2 == 0)
            {
                if (plaintext[i] >= 97)
                {
                    mp[0][0] = plaintext[i] - 97;
                    huruf1 = true;
                }
                else
                {
                    mp[0][0] = plaintext[i] - 65;
                    huruf1 = false;
                }
            }
            else
            {
                if (plaintext[i] >= 97)
                {
                    mp[1][0] = plaintext[i] - 97;
                    huruf2 = true;
                }
                else
                {
                    mp[1][0] = plaintext[i] - 65;
                    huruf2 = false;
                }

                for (int j = 0; j < ordo; j++)
                {
                    // ciphertext+= char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0])) % 26);
                    if (j == 0)
                    {
                        if (huruf1 == true)
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0])) % 26) + 97;
                        }
                        else
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0])) % 26) + 65;
                        }
                    }
                    else
                    {
                        if (huruf2 == true)
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0])) % 26) + 97;
                        }
                        else
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0])) % 26) + 65;
                        }
                    }
                }
            }
        }
        cout << "Hasil Enkripsi (Ciphertext) = " << ciphertext << endl;
    }
    else if (ordo == 3)
    {
        string ciphertext = "";
        bool huruf1, huruf2, huruf3;
        int mp[3][1];
        int length = plaintext.length();
        if (length % 3 != 0)
        {
            plaintext += 'x';
        }
        for (int i = 0; i < length; i++)
        {
            if (i % 3 == 0)
            {
                if (plaintext[i] >= 97)
                {
                    mp[0][0] = plaintext[i] - 97;
                    huruf1 = true;
                }
                else
                {
                    mp[0][0] = plaintext[i] - 65;
                    huruf1 = false;
                }
            }
            else if (i % 3 == 1)
            {
                if (plaintext[i] >= 97)
                {
                    mp[1][0] = plaintext[i] - 97;
                    huruf2 = true;
                }
                else
                {
                    mp[1][0] = plaintext[i] - 65;
                    huruf2 = false;
                }
            }
            else
            {
                if (plaintext[i] >= 97)
                {
                    mp[2][0] = plaintext[i] - 97;
                    huruf3 = true;
                }
                else
                {
                    mp[2][0] = plaintext[i] - 65;
                    huruf3 = false;
                }
                for (int j = 0; j < ordo; j++)
                {
                    if (j == 0)
                    {
                        if (huruf1 == true)
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0]) + (key[j][2] * mp[2][0])) % 26) + 97;
                        }
                        else
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0]) + (key[j][2] * mp[2][0])) % 26) + 65;
                        }
                    }
                    else if (j == 1)
                    {
                        if (huruf2 == true)
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0]) + (key[j][2] * mp[2][0])) % 26) + 97;
                        }
                        else
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0]) + (key[j][2] * mp[2][0])) % 26) + 65;
                        }
                    }
                    else
                    {
                        if (huruf3 == true)
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0]) + (key[j][2] * mp[2][0])) % 26) + 97;
                        }
                        else
                        {
                            ciphertext += char(((key[j][0] * mp[0][0]) + (key[j][1] * mp[1][0]) + (key[j][2] * mp[2][0])) % 26) + 65;
                        }
                    }
                }
            }
        }
        cout << "Hasil Enkripsi (Ciphertext) = " << ciphertext << endl;
    }
    else
    {
        cout << "Hanya dapat mengenkripsi untuk matriks 2x2 dan 3x3";
    }
}

int cariDeterminan(int keyMatrix[][3], int n)
{
    int det1, det2, det3;
    int determinan;
    if (n == 2)
    {
        determinan = ((keyMatrix[0][0] * keyMatrix[1][1]) - (keyMatrix[1][0] * keyMatrix[0][1]));
        return determinan;
    }
    else if (n == 3)
    {
        det1 = (keyMatrix[1][1] * keyMatrix[2][2]) - (keyMatrix[2][1] * keyMatrix[1][2]);
        det2 = (keyMatrix[1][0] * keyMatrix[2][2]) - (keyMatrix[2][0] * keyMatrix[1][2]);
        det3 = (keyMatrix[1][0] * keyMatrix[2][1]) - (keyMatrix[2][0] * keyMatrix[1][1]);

        determinan = ((keyMatrix[0][0] * det1) - (keyMatrix[0][1] * det2) + (keyMatrix[0][2] * det3));
        return determinan;
    }
    return 0;
}

void inversMatriks2x2(int inversKey[][3], int key[][3])
{
    int determinan;
    determinan = cariDeterminan(key, 2);

    int adj[2][2];

    adj[0][0] = key[1][1];
    adj[0][1] = -(key[0][1]);
    adj[1][0] = -(key[1][0]);
    adj[1][1] = key[0][0];

    int mod_determinan;
    for (int i = 0; i < 26; i++)
    {
        int temp;
        temp = determinan * i;
        while (temp < 0)
        {
            temp += 26;
        }
        if (temp % 26 == 1)
        {
            mod_determinan = i;
            break;
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            inversKey[i][j] = (mod_determinan * (adj[i][j]));
            while (inversKey[i][j] < 0)
            {
                inversKey[i][j] += 26;
            }
            inversKey[i][j] = inversKey[i][j] % 26;
        }
    }
}

void inversMatriks3x3(int inversKey[][3], int key[][3])
{
    int determinan;
    determinan = cariDeterminan(key, 3);

    int mod_determinan;
    for (int i = 0; i < 26; i++)
    {
        int temp;
        temp = determinan * i;
        while (temp < 0)
        {
            temp += 26;
        }
        if (temp % 26 == 1)
        {
            mod_determinan = i;
            break;
        }
    }

    int each;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            each = ((key[(j + 1) % 3][(i + 1) % 3] * key[(j + 2) % 3][(i + 2) % 3]) - (key[(j + 1) % 3][(i + 2) % 3] * key[(j + 2) % 3][(i + 1) % 3]));

            while (each < 0)
            {
                each += 26;
            }

            inversKey[i][j] = (each * mod_determinan) % 26;
        }
    }
}

void cariKey(int ordo, string plaintext, string ciphertext, int key[][3])
{
    int x = 0;
    int plainMatriks[3][3];
    int cipherMatriks[3][3];
    for (int i = 0; i < ordo; i++)
    {
        for (int j = 0; j < ordo; j++)
        {
            plainMatriks[j][i] = plaintext[x] - 65;
            cipherMatriks[j][i] = ciphertext[x] - 65;
            x++;
        }
    }

    int inversPlainMatriks[3][3];

    if (ordo == 2)
    {
        inversMatriks2x2(inversPlainMatriks, plainMatriks);

        for (int i = 0; i < ordo; i++)
        {
            for (int j = 0; j < ordo; j++)
            {
                key[i][j] = (cipherMatriks[i][0] * inversPlainMatriks[0][j]) + (cipherMatriks[i][1] * inversPlainMatriks[1][j]);
                while (key[i][j] < 0)
                {
                    key[i][j] += 26;
                }
                key[i][j] = key[i][j] % 26;
                cout << key[i][j] << " ";
            }
            cout << endl;
        }
    }

    else
    {
        inversMatriks3x3(inversPlainMatriks, plainMatriks);

        for (int i = 0; i < ordo; i++)
        {
            for (int j = 0; j < ordo; j++)
            {
                key[i][j] = (cipherMatriks[i][0] * inversPlainMatriks[0][j]) + (cipherMatriks[i][1] * inversPlainMatriks[1][j]) + (cipherMatriks[i][2] * inversPlainMatriks[2][j]);
                while (key[i][j] < 0)
                {
                    key[i][j] += 26;
                }
                key[i][j] = key[i][j] % 26;
                cout << key[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    char loop;
    int menu;
    do
    {
        clear;
        cout << "=========|Program Hills Cipher|=========\n";
        cout << "1. Enkripsi" << endl;
        cout << "2. Dekripsi" << endl;
        cout << "3. Mencari Key" << endl;
        cout << "========================================\n";
        cout << "Pilih menu : ";
        cin >> menu;
        switch (menu)
        {
        case 1:
        {
            int ordo;
            string plaintext;
            cout << "Input ordo matriks (2x2 atau 3x3) = ";
            cin >> ordo;
            cout << "Input plaintext = ";
            getline(cin >> ws, plaintext);
            int key[3][3];
            input_matriks(ordo, key);
            enkripsi(ordo, key, plaintext);

            cout << "Apakah anda ingin mengulang? (y/n) -> ";
            cin >> loop;
            break;
        }
        case 2:
        {
            int ordo;
            string ciphertext;
            cout << "Input ordo matriks (2x2 atau 3x3) = ";
            cin >> ordo;
            cout << "Input Ciphertext = ";
            getline(cin >> ws, ciphertext);
            int key[3][3];
            input_matriks(ordo, key);
            int inversKey[3][3];
            if (ordo == 2)
            {
                inversMatriks2x2(inversKey, key);
            }
            else if (ordo == 3)
            {
                inversMatriks3x3(inversKey, key);
            }
            enkripsi(ordo, inversKey, ciphertext);

            cout << "Apakah anda ingin mengulang? (y/n) -> ";
            cin >> loop;
            break;
        }
        case 3:
        {
            int ordo;
            string ciphertext;
            string plaintext;
            cout << "Input ordo matriks (2x2 atau 3x3) = ";
            cin >> ordo;
            cout << "Input Plaintext = ";
            getline(cin >> ws, plaintext);
            cout << "Input Ciphertext = ";
            getline(cin >> ws, ciphertext);
            int key[3][3];
            cariKey(ordo, plaintext, ciphertext, key);

            cout << "Apakah anda ingin mengulang? (y/n) -> ";
            cin >> loop;
            break;
        }
        default:
            cout << "Menu tidak tersedia";
            break;
        }
    } while (loop == 'y' || loop == 'Y');
    return 0;
}