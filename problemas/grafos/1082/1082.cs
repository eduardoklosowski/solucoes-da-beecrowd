using System;
using System.Collections.Generic;
using System.Linq;

class URI
{
    static void DFS(ref List<int> visitado, ref List<List<int>> grafo, int componente, int u)
    {
        visitado[u] = componente;

        for (int i = 0; i < grafo[u].Count; ++i)
        {
            int v = grafo[u][i];

            if (visitado[v] == 0)
            {
                DFS(ref visitado, ref grafo, componente, v);
            }
        }
    }

    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        for (int k = 1; k <= N; ++k)
        {
            List<int> VE = Console.ReadLine().Trim().Split(' ').Select(x => int.Parse(x)).ToList();
            int V = VE[0];
            int E = VE[1];

            List<int> visitado = new List<int>();
            List<List<int>> grafo = new List<List<int>>();
            for (int i = 0; i < V; ++i)
            {
                visitado.Add(0);
                grafo.Add(new List<int>());
            }

            for (int i = 0; i < E; ++i)
            {
                List<char> uv = Console.ReadLine().Trim().Split(' ').Select(x => char.Parse(x)).ToList();
                int u = uv[0];
                int v = uv[1];

                grafo[u - 'a'].Add(v - 'a');
                grafo[v - 'a'].Add(u - 'a');
            }

            Console.WriteLine($"Case #{k}:");
            int componentes = 0;
            for (int u = 0; u < V; ++u)
            {
                if (visitado[u] == 0)
                {
                    componentes += 1;
                    DFS(ref visitado, ref grafo, componentes, u);

                    List<char> vertices = new List<char>();
                    for (int i = 0; i < V; ++i)
                    {
                        if (visitado[i] == componentes)
                        {
                            vertices.Add((char)(i + 'a'));
                        }
                    }

                    vertices.Sort();

                    Console.WriteLine($"{string.Join(",", vertices)},");
                }
            }
            Console.WriteLine($"{componentes} connected components");
            Console.WriteLine("");
        }
    }
}