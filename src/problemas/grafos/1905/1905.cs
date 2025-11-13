using System;
using System.Collections.Generic;
using System.Linq;

class URI
{
    static bool Chega(int[,] matriz, int x, int y)
    {
        if (matriz[x, y] == 1)
        {
            return false;
        }
        matriz[x, y] = 1;

        if (x == 5 && y == 5)
        {
            return true;
        }
        else
        {
            bool retorno = false;

            if (matriz[x - 1, y] == 0)
            {
                retorno = retorno || Chega(matriz, x - 1, y);
            }
            if (matriz[x + 1, y] == 0)
            {
                retorno = retorno || Chega(matriz, x + 1, y);
            }
            if (matriz[x, y - 1] == 0)
            {
                retorno = retorno || Chega(matriz, x, y - 1);
            }
            if (matriz[x, y + 1] == 0)
            {
                retorno = retorno || Chega(matriz, x, y + 1);
            }

            return retorno;
        }
    }

    static void Main(string[] args)
    {
        int T = int.Parse(Console.ReadLine().Trim());

        int[,] matriz = new int[7, 7];
        for (int i = 0; i < 7; ++i)
        {
            matriz[0, i] = 1;
            matriz[i, 0] = 1;
            matriz[6, i] = 1;
            matriz[i, 6] = 1;
        }

        string linha = Console.ReadLine().Trim();
        for (int k = 0; k < T; ++k)
        {
            while (linha.Length == 0)
            {
                linha = Console.ReadLine().Trim();
            }

            for (int i = 1; i < 6; ++i)
            {
                List<int> numeros = linha.Split(' ').Select(x => int.Parse(x)).ToList();
                for (int j = 1; j < 6; ++j)
                {
                    matriz[i, j] = numeros[j - 1];
                }
                linha = Console.ReadLine()?.Trim();
            }

            if (Chega(matriz, 1, 1))
            {
                Console.WriteLine("COPS");
            }
            else
            {
                Console.WriteLine("ROBBERS");
            }
        }
    }
}